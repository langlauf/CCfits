
//	This is version 1.1 release dated May 2002

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	May 2002 Ben Dorman, L3-Com Analytics Corporation
//	e-mail: ccfits@legacy.gsfc.nasa.gov




#ifdef _MSC_VER
#include "MSconfig.h" // for truncation warning
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_STRSTREAM
#include <strstream>
using std::ostrstream;
#else
#include <sstream>
using std::ostringstream;
#endif


// Table
#include "Table.h"
// Column
#include "Column.h"



#include "FITS.h"
#include "ColumnData.h"
#include "ColumnVectorData.h"
#include <limits.h>
#include <float.h>


namespace CCfits {

  // Class CCfits::Column::RangeError 

  Column::RangeError::RangeError (const string& msg, bool silent)
  : FitsException("FitsError: Range error in operation ",silent)
  {
  if (!silent || FITS::verboseMode() ) std::cerr << msg << '\n';
  }


  // Class CCfits::Column::InvalidDataType 

  Column::InvalidDataType::InvalidDataType (const string& str, bool silent)
  : FitsException("FitsError: Incorrect data type: ",silent)
  {
  if (!silent || FITS::verboseMode() ) std::cerr << str << '\n';
  }


  // Class CCfits::Column::InvalidRowParameter 

  Column::InvalidRowParameter::InvalidRowParameter (const string& diag, bool silent)
  : FitsException("FitsError: row offset or length incompatible with column declaration ",silent)
  {
  if (!silent || FITS::verboseMode() ) std::cerr << diag << '\n';
  }


  // Class CCfits::Column::WrongColumnType 

  Column::WrongColumnType::WrongColumnType (const string& diag, bool silent)
  : FitsException("FitsError: Attempt to return scalar data from vector column, or vice versa - Column: ",silent)
  {
  if (!silent || FITS::verboseMode() ) std::cerr << diag << '\n';
  }


  // Class CCfits::Column::UnspecifiedLengths 

  Column::UnspecifiedLengths::UnspecifiedLengths (const string& diag, bool silent)
  : FitsException
        ("FitsError: Variable length column being written needs integer array of row lengths: Column ",silent)
                
  {
  if (!silent || FITS::verboseMode() ) std::cerr << diag << '\n';
  }


  // Class CCfits::Column::InvalidRowNumber 

  Column::InvalidRowNumber::InvalidRowNumber (const string& diag, bool silent)
  : FitsException("FitsError: Invalid Row Number - Column: ",silent)
  {
    if (!silent || FITS::verboseMode() ) std::cerr << diag << '\n';
  }


  // Class CCfits::Column::InsufficientElements 

  Column::InsufficientElements::InsufficientElements (const string& msg, bool silent)
     : FitsException("FitsError: not enough elements supplied for write operation ",silent)
  {
    if (!silent || FITS::verboseMode() ) std::cerr << msg << '\n';    
  }


  // Class CCfits::Column::NoNullValue 

  Column::NoNullValue::NoNullValue (const string& diag, bool silent)
    : FitsException("Fits Error: No null value specified for column: ",silent)
  {
     if (!silent || FITS::verboseMode() ) std::cerr << diag << '\n';    
  }


  // Class CCfits::Column::InvalidNumberOfRows 

  Column::InvalidNumberOfRows::InvalidNumberOfRows (size_t number, bool silent)
    : FitsException( "Fits Error: number of rows to write must be positive ",silent)
  {
     if (!silent || FITS::verboseMode() ) std::cerr << " specified: " << number  << '\n';    
  }


  // Class CCfits::Column 

  const string Column::s_TBCOL = "TBCOL";

  const string Column::s_TTYPE = "TTYPE";

  const string Column::s_TFORM = "TFORM";

  const string Column::s_TDISP = "TDISP";

  const string Column::s_TUNIT = "TUNIT";

  const string Column::s_TSCAL = "TSCAL";

  const string Column::s_TZERO = "TZERO";

  const string Column::s_TDIM = "TDIM";

  const string Column::s_TNULL = "TNULL";

  const string Column::s_TLMIN = "TLMIN";

  const string Column::s_TLMAX = "TLMAX";

  const string Column::s_TDMAX = "TDMAX";

  const string Column::s_TDMIN = "TDMIN";

  const short Column::LLIMITSHORT = SHRT_MIN;

  const long Column::LLIMITLONG = LONG_MIN;

  const unsigned short Column::LLIMITUSHORT = 0;

  const unsigned long Column::LLIMITULONG = 0;

  const unsigned char Column::LLIMITUCHAR = 0;

  const float Column::LLIMITFLOAT = FLT_MIN;

  const double Column::LLIMITDOUBLE = DBL_MIN;

  const short Column::ULIMITSHORT = SHRT_MAX;

  const long Column::ULIMITLONG = LONG_MAX;

  const unsigned short Column::ULIMITUSHORT = USHRT_MAX;

  const unsigned long Column::ULIMITULONG = ULONG_MAX;

  const unsigned char Column::ULIMITUCHAR = UCHAR_MAX;

  const float Column::ULIMITFLOAT = FLT_MAX;

  const double Column::ULIMITDOUBLE = DBL_MAX;

  const int Column::LLIMITINT = INT_MIN;

  const int Column::ULIMITINT = INT_MAX;

  const unsigned int Column::LLIMITUINT = 0;

  const unsigned int Column::ULIMITUINT = UINT_MAX;

  std::vector<std::string> Column::s_columnKeys;


  Column::Column(const Column &right)
      : m_index(right.m_index),
	m_isRead(right.m_isRead),
	m_width(right.m_width),
	m_repeat(right.m_repeat),
	m_varLength(right.m_varLength),
	m_scale(right.m_scale),
	m_zero(right.m_zero),
	m_display(right.m_display),
	m_dimen(right.m_dimen),
	m_type(right.m_type),
	m_name(right.m_name),
	m_unit(right.m_unit),
	m_format(right.m_format),
	m_comment(right.m_comment),
        m_parent(right.m_parent)
  {
  }

  Column::Column (int columnIndex, const string &columnName, ValueType type, const string &format, const string &unit, Table* p, int  rpt, long w, const string &comment)
  :m_index(columnIndex),
   m_isRead(false),
   m_width(w),
   m_repeat(rpt),
   m_varLength(type < 0),
   m_scale(1),
   m_zero(0),
   m_display(""),
   m_dimen(""),
   m_type(type),
   m_name(columnName),
   m_unit(unit),
   m_format(format),
   m_comment(comment),
   m_parent(p)
  {
    Column::loadColumnKeys();
    setDisplay();
    setDimen();
  }

  Column::Column (Table* p)
      : m_index(-1),
        m_isRead(false),
        m_width(1),
        m_repeat(1),
        m_varLength(false),
        m_scale(1),
        m_zero(0),
        m_display(""),
        m_dimen(""),
        m_type(Tnull),
        m_name(""),
        m_unit(""),
        m_format(""),
        m_comment(""),
        m_parent(p)
  {
  // default constructor.
    Column::loadColumnKeys();
  }


  Column::~Column()
  {
  }


  bool Column::operator==(const Column &right) const
  {
  return compare(right);
  }

  bool Column::operator!=(const Column &right) const
  {
  return !compare(right);
  }



  bool Column::compare (const Column &right) const
  {
        if (m_isRead != right.m_isRead) return false;
        if (m_repeat != right.m_repeat) return false;
        if (m_width != right.m_width) return false;
        if (m_varLength != right.m_varLength) return false;
        if (m_name != right.m_name) return false;
        if (m_format != right.m_format) return false;
        if (m_unit != right.m_unit) return false;
        if (m_comment != right.m_comment) return false;
        if (m_parent != right.m_parent) return false;  
        return true;
  }

  fitsfile* Column::fitsPointer ()
  {

    return m_parent->fitsPointer();
  }

  void Column::makeHDUCurrent ()
  {
    m_parent->makeThisCurrent();

  }

  int Column::rows () const
  {
  return m_parent->rows();   
  }

  void Column::setDisplay ()
  {
#ifdef HAVE_STRSTREAM
  ostrstream key;
#else
  std::ostringstream key;
#endif
  key << "TDISP" << index();
  int status = 0;
  FITSUtil::auto_array_ptr<char> dispValue (new char[FLEN_VALUE]);
#ifdef HAVE_STRSTREAM
  fits_read_key_str(fitsPointer(), key.str(), dispValue.get(),0,&status);
#else
  fits_read_key_str(fitsPointer(),const_cast<char*>(key.str().c_str()),dispValue.get(),0,&status);
#endif
  if (status == 0)
  {
        m_display = string(dispValue.get());
  }
  }

  std::ostream& Column::put (std::ostream& s) const
  {
  {
     s << "Column Name:"  << name() << " Number: " << index() <<  "   unit: " << unit() << "\n";
     s << "format: " << format() << " comment: " << comment() << "\n";
  }

    return s;
  }

  Table* Column::parent () const
  {

    return m_parent;
  }

  void Column::dimen (const string& value)
  {
  }

  void Column::setLimits (ValueType type)
  {
    int status(0);
    static long*  pl  = new long[4];
    static unsigned long*  pul  = new unsigned long[4];
    static int*  pi  = new int[4];
    static unsigned int*  pui  = new unsigned int[4];
    static short*  ps  = new short[4];
    static unsigned short*  pus  = new unsigned short[4];
    static unsigned char* puc = new unsigned char[4];
    static float* pf = new float[4];
    static double* pd = new double[4];
    static std::complex<float> cf[4];
    static std::complex<double> cd[4];
#ifdef HAVE_STRSTREAM
    ostrstream slmin;
    ostrstream slmax;
    ostrstream sdmin;
    ostrstream sdmax;   
#else
    ostringstream slmin;
    ostringstream slmax;
    ostringstream sdmin;
    ostringstream sdmax;
#endif
    
    slmin << s_TLMIN << m_index;
    slmax << s_TLMAX << m_index;
    sdmin << s_TDMIN << m_index;
    sdmax << s_TDMAX << m_index;
    
#ifdef HAVE_STRSTREAM
    char* lmin(slmin.str());
    char* lmax(slmax.str());
    char* dmin(slmin.str());
    char* dmax(slmax.str());
#else
    char* lmin = const_cast<char*>(slmin.str().c_str());
    char* lmax = const_cast<char*>(slmax.str().c_str());
    char* dmin = const_cast<char*>(sdmin.str().c_str());
    char* dmax = const_cast<char*>(sdmax.str().c_str());
#endif

    size_t j = 0; // for MS VC++
    switch (type) 
    {
        case VTushort:
        case Tushort:
                fits_read_key_lng(fitsPointer(),lmin,pl,0,&status);
                if (status != 0) pl[0] = LLIMITUSHORT;
                fits_read_key_lng(fitsPointer(),lmax,pl+1,0,&status);
                if (status != 0) pl[1] = ULIMITUSHORT;
                fits_read_key_lng(fitsPointer(),dmin,pl+2,0,&status);
                if (status != 0) pl[2] = LLIMITUSHORT;
                fits_read_key_lng(fitsPointer(),dmax,pl+3,0,&status);
                if (status != 0) pl[3] = ULIMITUSHORT;
                for (j = 0; j < 4; ++j) pus[j] = pl[j];
                if (m_repeat == 1)
                {
                        ColumnData<unsigned short>& col = 
                                dynamic_cast<ColumnData<unsigned short>&>(*this);
                        col.setDataLimits(pus);                       
                }
                else
                {
                        ColumnVectorData<unsigned short>& col = 
                                dynamic_cast<ColumnVectorData<unsigned short>&>(*this);
                        col.setDataLimits(pus);                       
                }	
                break;
        case VTshort:
        case Tshort:
                fits_read_key_lng(fitsPointer(),lmin,pl,0,&status);
                if (status != 0) pl[0] = LLIMITSHORT;
                fits_read_key_lng(fitsPointer(),lmax,pl+1,0,&status);
                if (status != 0) pl[1] = ULIMITSHORT;
                fits_read_key_lng(fitsPointer(),dmin,pl+2,0,&status);
                if (status != 0) pl[2] = LLIMITSHORT;
                fits_read_key_lng(fitsPointer(),dmax,pl+3,0,&status);
                if (status != 0) pl[3] = ULIMITSHORT;
                for ( j = 0; j < 4; ++j) ps[j] = pl[j];                
                if (m_repeat == 1 && type > 0)
                {
                        ColumnData<short>& col = 
                                dynamic_cast<ColumnData<short>&>(*this);
                         col.setDataLimits(static_cast<short*>(ps));                       
                       
                }
                else
                {
                        ColumnVectorData<short>& col = 
                                dynamic_cast<ColumnVectorData<short>&>(*this);
                        col.setDataLimits(static_cast<short*>(ps));                       
                }	
                break;
        case VTbyte:
        case VTbit:
        case Tbit:
        case Tbyte:
                fits_read_key_lng(fitsPointer(),lmin,pl,0,&status);
                if (status != 0) pl[0] = LLIMITUCHAR;
                fits_read_key_lng(fitsPointer(),lmax,pl+1,0,&status);
                if (status != 0) pl[1] = ULIMITUCHAR;
                fits_read_key_lng(fitsPointer(),dmin,pl+2,0,&status);
                if (status != 0) pl[2] = LLIMITUCHAR;
                fits_read_key_lng(fitsPointer(),dmax,pl+3,0,&status);
                if (status != 0) pl[3] = ULIMITUCHAR;
                for ( j = 0; j < 4; ++j) puc[j] = pl[j];                
                if (m_repeat == 1 && type > 0)
                {
                        ColumnData<unsigned char>& col = 
                                dynamic_cast<ColumnData<unsigned char>&>(*this);                
                         col.setDataLimits(puc);                       
               }
                else
                {
                        ColumnVectorData<unsigned char>& col = 
                                dynamic_cast<ColumnVectorData<unsigned char>&>(*this);
                        col.setDataLimits(puc);                       
                }	
                break;
        case VTint:	                
        case Tint:
                fits_read_key_lng(fitsPointer(),lmin,pl,0,&status);
                if (status != 0) pl[0] = LLIMITINT;
                fits_read_key_lng(fitsPointer(),lmax,pl+1,0,&status);
                if (status != 0) pl[1] = ULIMITINT;
                fits_read_key_lng(fitsPointer(),dmin,pl+2,0,&status);
                if (status != 0) pl[2] = LLIMITINT;
                fits_read_key_lng(fitsPointer(),dmax,pl+3,0,&status);
                if (status != 0) pl[3] = ULIMITINT;
                for ( j = 0; j < 4; ++j) pi[j] = pl[j];                
                if (m_repeat == 1 && type > 0)
                {
                        ColumnData<int>& col = 
                                dynamic_cast<ColumnData<int>&>(*this);
                        
                         col.setDataLimits(pi);                       
               }
                else
                {
                        ColumnVectorData<int>& col = 
                                dynamic_cast<ColumnVectorData<int>&>(*this);
                          col.setDataLimits(pi);                       
              }	
                break;
        case VTuint:
        case Tuint:
                fits_read_key_lng(fitsPointer(),lmin,pl,0,&status);
                if (status != 0) pui[0] = LLIMITUINT;
                else pui[0] = pl[0]; 
                fits_read_key_lng(fitsPointer(),lmax,pl+1,0,&status);
                if (status != 0) pui[1] = ULIMITUINT;
                else pui[1] = pl[1]; 
                fits_read_key_lng(fitsPointer(),dmin,pl+2,0,&status);
                if (status != 0) pui[2] = LLIMITUINT;
                else pui[2] = pl[2]; 
                fits_read_key_lng(fitsPointer(),dmax,pl+3,0,&status);
                if (status != 0) pui[3] = ULIMITUINT;
                else pui[3] = pl[3]; 
                if (m_repeat == 1 && type > 0)
                {
                        ColumnData<unsigned int>& col = 
                                dynamic_cast<ColumnData<unsigned int>&>(*this);
                        
                         col.setDataLimits(pui);                       
               }
                else
                {
                        ColumnVectorData<unsigned int>& col = 
                                dynamic_cast<ColumnVectorData<unsigned int>&>(*this);
                          col.setDataLimits(pui);                       
              }	
                break;
        case VTlong:
        case Tlong:
                fits_read_key_lng(fitsPointer(),lmin,pl,0,&status);
                if (status != 0) pl[0] = LLIMITLONG;
                fits_read_key_lng(fitsPointer(),lmax,pl+1,0,&status);
                if (status != 0) pl[1] = ULIMITLONG;
                fits_read_key_lng(fitsPointer(),dmin,pl+2,0,&status);
                if (status != 0) pl[2] = LLIMITLONG;
                fits_read_key_lng(fitsPointer(),dmax,pl+3,0,&status);
                if (status != 0) pl[3] = ULIMITLONG;
                if (m_repeat == 1 && type > 0)
                {
                        ColumnData<long>& col = 
                                dynamic_cast<ColumnData<long>&>(*this);
                          col.setDataLimits(pl);                       
              }
                else
                {
                        ColumnVectorData<long>& col = 
                                dynamic_cast<ColumnVectorData<long>&>(*this);
                          col.setDataLimits(pl);                       
              }	
                break;
        case VTulong:          
        case Tulong:
                fits_read_key_lng(fitsPointer(),lmin,pl,0,&status);
                if (status != 0) pul[0] = LLIMITULONG;
                else pul[0] = pl[0];
                fits_read_key_lng(fitsPointer(),lmax,pl+1,0,&status);
                if (status != 0) pul[1] = ULIMITULONG;
                else pul[1] = pl[1];
                fits_read_key_lng(fitsPointer(),dmin,pl+2,0,&status);
                if (status != 0) pl[2] = LLIMITULONG;
                else pul[2] = pl[2];
                fits_read_key_lng(fitsPointer(),dmax,pl+3,0,&status);
                if (status != 0) pul[3] = ULIMITULONG;
                else pul[3] = pl[3];               
                if (m_repeat == 1 && type > 0)
                {
                        ColumnData<unsigned long>& col = 
                                dynamic_cast<ColumnData<unsigned long>&>(*this);
                           col.setDataLimits(pul);                       
             }
                else
                {
                        ColumnVectorData<unsigned long>& col = 
                                dynamic_cast<ColumnVectorData<unsigned long>&>(*this);
                         col.setDataLimits(pul);                       
               }	
                break;
        case VTfloat:
        case Tfloat:
                fits_read_key_flt(fitsPointer(),lmin,pf,0,&status);
                if (status != 0) pf[0] = LLIMITFLOAT;
                fits_read_key_flt(fitsPointer(),lmax,pf+1,0,&status);
                if (status != 0) pf[1] = ULIMITFLOAT;
                fits_read_key_flt(fitsPointer(),dmin,pf+2,0,&status);
                if (status != 0) pf[2] = LLIMITFLOAT;
                fits_read_key_flt(fitsPointer(),dmax,pf+3,0,&status);
                if (status != 0) pf[3] = ULIMITFLOAT;
                 
                if (m_repeat == 1 && type > 0)
                {
                        ColumnData<float>& col = 
                                dynamic_cast<ColumnData<float>&>(*this);
                        col.setDataLimits(pf);                       
                }
                else
                {
                        ColumnVectorData<float>& col = 
                                dynamic_cast<ColumnVectorData<float>&>(*this);
                        col.setDataLimits(pf);                       
                }	
                break;
        case VTdouble:
        case Tdouble:
                fits_read_key_dbl(fitsPointer(),lmin,pd,0,&status);
                if (status != 0) pd[0] = LLIMITDOUBLE;
                fits_read_key_dbl(fitsPointer(),lmax,pd+1,0,&status);
                if (status != 0) pd[1] = ULIMITDOUBLE;
                fits_read_key_dbl(fitsPointer(),dmin,pd+2,0,&status);
                if (status != 0) pd[2] = LLIMITDOUBLE;
                fits_read_key_dbl(fitsPointer(),dmax,pd+3,0,&status);
                if (status != 0) pd[3] = ULIMITDOUBLE;                 
                if (m_repeat == 1 && type > 0)
                {
                        ColumnData<double>& col = 
                                 dynamic_cast<ColumnData<double>&>(*this);
                        col.setDataLimits(pd);                       
                }
                else
                {
                        ColumnVectorData<double>& col = 
                                 dynamic_cast<ColumnVectorData<double>&>(*this);
                        col.setDataLimits(pd);                       
                }	
                break;
        case VTcomplex:
        case Tcomplex:
                fits_read_key_cmp(fitsPointer(),lmin,pf,0,&status);
                status != 0 ? cf[0] = std::complex<float>(pf[0],pf[1])
                            : cf[0] = std::complex<float>(-ULIMITFLOAT,-ULIMITFLOAT);
                fits_read_key_cmp(fitsPointer(),lmax,pf,0,&status);
                status != 0 ? cf[1] = std::complex<float>(pf[0],pf[1])
                            : cf[1] = std::complex<float>(ULIMITFLOAT,ULIMITFLOAT);
                fits_read_key_cmp(fitsPointer(),dmin,pf,0,&status);
                status != 0 ? cf[2] = std::complex<float>(pf[0],pf[1])
                            : cf[2] = std::complex<float>(-ULIMITFLOAT,ULIMITFLOAT);
                fits_read_key_cmp(fitsPointer(),dmax,pf,0,&status);
                status != 0 ? cf[3] = std::complex<float>(pf[0],pf[1])
                            : cf[3] = std::complex<float>(ULIMITFLOAT,ULIMITFLOAT);
                if (m_repeat == 1 && type > 0)
                {
                        ColumnData<complex<float> >& col = 
                                 dynamic_cast<ColumnData<complex<float> >&>(*this);
                        col.setDataLimits(cf);                       
                }
                else
                {
                        ColumnVectorData<complex<float> >& col = 
                                 dynamic_cast<ColumnVectorData<complex<float> >&>(*this);
                        col.setDataLimits(cf);                       
               }	
                break;
        case VTdblcomplex:
        case Tdblcomplex:
                fits_read_key_dblcmp(fitsPointer(),lmin,pd,0,&status);
                status != 0 ? cd[0] = std::complex<double>(pd[0],pd[1])
                            : cd[0] = std::complex<double>(-ULIMITDOUBLE,-ULIMITDOUBLE);
                fits_read_key_dblcmp(fitsPointer(),lmax,pd,0,&status);
                status != 0 ? cd[1] = std::complex<double>(pd[0],pd[1])
                            : cd[1] = std::complex<double>(ULIMITDOUBLE,ULIMITDOUBLE);
                fits_read_key_dblcmp(fitsPointer(),dmin,pd,0,&status);
                status != 0 ? cd[2] = std::complex<double>(pd[0],pd[1])
                            : cd[2] = std::complex<double>(-ULIMITDOUBLE,-ULIMITDOUBLE);
                fits_read_key_dblcmp(fitsPointer(),dmax,pd,0,&status);
                status != 0 ? cd[3] = std::complex<double>(pd[0],pd[1])
                            : cd[3] = std::complex<double>(ULIMITDOUBLE,ULIMITDOUBLE);
                if (m_repeat == 1 && type > 0)
                {
                        ColumnData<complex<double> >& col = 
                                        dynamic_cast<ColumnData<complex<double> >&>(*this);
                        col.setDataLimits(cd);                       
                }
                else
                {
                        ColumnVectorData<complex<double> >& col = 
                                 dynamic_cast<ColumnVectorData<complex<double> >&>(*this);
                        col.setDataLimits(cd);                       
               }	
                break;
        case Tstring:
        default:
                break;
    }                
                      
          
          
  }

  void Column::loadColumnKeys ()
  {
    if (s_columnKeys.empty())
    {
        s_columnKeys.resize(13);
        s_columnKeys[0] = s_TBCOL;       
        s_columnKeys[1] = s_TTYPE;       
        s_columnKeys[2] = s_TFORM;       
        s_columnKeys[3] = s_TUNIT;       
        s_columnKeys[4] = s_TNULL;       
        s_columnKeys[5] = s_TDISP;       
        s_columnKeys[6] = s_TDIM;       
        s_columnKeys[7] = s_TSCAL;       
        s_columnKeys[8] = s_TZERO;       
        s_columnKeys[9] = s_TLMIN;       
        s_columnKeys[10] = s_TLMAX;       
        s_columnKeys[11] = s_TDMIN;       
        s_columnKeys[12] = s_TDMAX;       
    }      
  }

  void Column::name (const string& value)
  {
    m_name = value;

  }

  void Column::unit (const string& value)
  {
    m_unit = value;

  }

  void Column::format (const string& value)
  {
    m_format = value;

  }

  void Column::varLength (bool value)
  {
    m_varLength = value;
  }

  long Column::numberOfElements (long& first, long& last)
  {
    // user expects 1 based indexing. If 0 based indices are supplied,
    // add one to both ranges.
    if (first == 0)
    {
            first +=1;
            last = std::min(static_cast<long>(rows()),
				            static_cast<long>( last+1));       
    }

    last  = std::min(static_cast<long>(rows()),last);
    if (last < first ) throw RangeError(name());
    return last - first + 1;
  }

  // Additional Declarations
  void 
  Column::write(const std::vector<string>& indata, long firstRow)
  {
    try
    {
        ColumnData<string>& col = dynamic_cast<ColumnData<string>& >(*this);       
        col.writeData(indata,firstRow);

    }
    catch (std::bad_cast)
    {
        throw WrongColumnType(" downcasting string column ");       
    }
  }
 
    void 
    Column::write (const std::vector<std::complex<float> >& indata, long firstRow)
    {
            // we'll allow casting between float and double but that's
            // as far as it goes.
            firstRow = std::max(firstRow,static_cast<long>(1));
            if ( ColumnData<std::complex<float> >* col = 
                            dynamic_cast<ColumnData<std::complex<float> >*>(this) )
            {
                    col->writeData(indata,firstRow);
            }
            else
            {
                   if ( type() == Tcomplex) 
                   {
                           string msg("Incorrect call: writing to vector column ");
                           msg += name();
                           msg += " requires specification of # rows or vector lengths";
                           throw WrongColumnType(msg);
                   }
                   else
                   {
                           try
                           {
                                ColumnData<std::complex<double> >& col = 
                                    dynamic_cast<ColumnData<std::complex<double> >&>(*this);
                                std::vector<std::complex<double> > tmp(indata.size());
#ifdef TEMPLATE_AMBIG_DEFECT
                                FITSUtil::fillMSvdvf(tmp,indata,1,indata.size());
#else
                                FITSUtil::fill(tmp,indata,1,indata.size());
#endif
                                col.writeData(tmp,firstRow);
                           }
                           catch (std::bad_cast)
                           {
                                 std::string msg(" implicit conversion from complex to real data not allowed: Column ");
                                 msg += name();
                                    throw InvalidDataType(msg);
                           }
                   } 
            }
    }

    void Column::write (const std::vector<std::complex<double> >& indata, long firstRow)
    {
            firstRow = std::max(firstRow,static_cast<long>(1));
            if ( ColumnData<std::complex<double> >* col = 
                            dynamic_cast<ColumnData<std::complex<double> >*>(this))
            {
                    col->writeData(indata,firstRow);
            }
            else
            {
                   if ( type() == Tdblcomplex) 
                   {
                           string msg("Incorrect call: writing to vector column ");
                           msg += name();
                           msg += " requires specification of # rows or vector lengths";
                           throw WrongColumnType(msg);
                   }
                   else
                   {
                           try
                           {
                                ColumnData<std::complex<float> >& col = 
                                    dynamic_cast<ColumnData<std::complex<float> >&>(*this);
                                std::vector<std::complex<float> > __tmp(indata.size());

#ifdef TEMPLATE_AMBIG_DEFECT
                                FITSUtil::fillMSvfvd(__tmp,indata,1,indata.size());
#else
                                FITSUtil::fill(__tmp,indata,1,indata.size());
#endif
                                col.writeData(__tmp,firstRow);

                           }
                           catch (std::bad_cast)
                           {
                                 std::string msg(" implicit conversion from complex to real data not allowed: Column ");
                                 msg += name();
                                 throw InvalidDataType(msg);
                           }
                   } 
            }
     }

    void
    Column::write (const std::valarray<std::complex<float> >& indata, long firstRow)
    {
            std::vector<std::complex<float> > __tmp;            
            FITSUtil::fill(__tmp,indata);   
            write(__tmp,firstRow); 
    }

    void 
    Column::write (const std::valarray<std::complex<double> >& indata, long firstRow)
    {
            std::vector<std::complex<double> > __tmp;            
            FITSUtil::fill(__tmp,indata);   
            write(__tmp,firstRow); 
    }

    void 
    Column::read(std::vector<string>& vals, long first, long last)
    {
            try
            {
                ColumnData<string>& col = dynamic_cast<ColumnData<string>& >(*this);       
                col.readData(first,last-first+1);
#if TEMPLATE_AMBIG_DEFECT || TEMPLATE_AMBIG7_DEFECT
                FITSUtil::fillMSvsvs(vals,col.data(),first,last);   
#else
                FITSUtil::fill(vals,col.data(),first,last);               
#endif
			}
            catch (std::bad_cast)
            {
                throw WrongColumnType(" downcasting string column ");       
            }
    }
    
    void 
    Column::read(std::vector< std::complex<float> >& vals , long first, long last)
    {
           if  (ColumnData< std::complex<float> >* col 
                           = dynamic_cast<ColumnData< std::complex<float> >*>(this))
           {
                   // fails if user requested outputType different from input type.


                   if (!isRead()) col->readColumnData(first,last - first + 1);
                   // scalar column with vector output can just be assigned.
#ifdef TEMPLATE_AMBIG_DEFECT
                   FITSUtil::fillMSvfvf(vals,col->data(),first,last);
#else
                   FITSUtil::fill(vals,col->data(),first,last);
#endif
           }
           else
           {
                  if ( type() == Tcomplex) 
                  {
                          string msg("Incorrect call: writing to vector column ");
                          msg += name();
                          msg += " requires specification of # rows or vector lengths";
                          throw WrongColumnType(msg);
                  }
                  else
                  {
                          try
                          {
                               ColumnData<std::complex<double> >& col = 
                                   dynamic_cast<ColumnData<std::complex<double> >&>(*this);
                               if (!isRead()) col.readColumnData(first,last - first + 1);
#ifdef TEMPLATE_AMBIG_DEFECT
                               FITSUtil::fillMSvfvd(vals,col.data(),first,last);
#else
                               FITSUtil::fill(vals,col.data(),first,last);
#endif
                          }
                          catch (std::bad_cast)
                          {
                                std::string msg(" implicit conversion from complex to real data not allowed: Column ");
                                msg += name();
                                throw InvalidDataType(msg);
                          }
                  } 
           }
    }
        
    void 
    Column::read(std::vector< std::complex<double> >&  vals, long first, long last)
    {
         if  (ColumnData<std::complex<double> >* col 
                         = dynamic_cast<ColumnData<std::complex<double> >*>(this))
         {
                 // fails if user requested outputType different from input type.


                 if (!isRead()) col->readColumnData(first,last - first + 1);
                 // scalar column with vector output can just be assigned.
#ifdef TEMPLATE_AMBIG_DEFECT
                 FITSUtil::fillMSvdvd(vals,col->data(),first,last);
#else
				 FITSUtil::fill(vals,col->data(),first,last);
#endif
         }
         else
         {
                if ( type() == Tdblcomplex) 
                {
                        string msg("Incorrect call: writing to vector column ");
                        msg += name();
                        msg += " requires specification of # rows or vector lengths";
                        throw WrongColumnType(msg);
                }
                else
                {
                        try
                        {
                             ColumnData<std::complex<float> >& col = 
                                 dynamic_cast<ColumnData<std::complex<float> >&>(*this);
                             if (!isRead()) col.readColumnData(first,last - first + 1);
#ifdef TEMPLATE_AMBIG_DEFECT
                             FITSUtil::fillMSvdvf(vals,col.data(),first,last);
#else
                             FITSUtil::fill(vals,col.data(),first,last);
#endif
                        }
                        catch (std::bad_cast)
                        {
                              std::string msg(" implicit conversion from complex to real data not allowed: Column ");
                              msg += name();
                              throw InvalidDataType(msg);
                        }
                } 
         }
            
    }
    
    void 
    Column::read(std::valarray<std::complex<float> >& vals, long row)
    {
          if ( ColumnVectorData<std::complex<float> >* col 
                          = dynamic_cast<ColumnVectorData<std::complex<float> >*>(this))
          {
                  // fails if user requested outputType different from input type.



                  // input and output are both valarrays. Since one should not
                  // be able to call a constructor for a non-numeric valarray type,
                  // there shouldn't be any InvalidType problems. However, there
                  // is still the vector/scalar possibility and the implicit
                  // conversion request to deal with.

                  if (!isRead()) col->readRow(row);
                  FITSUtil::fill(vals,col->data(row));
          }
          else
          {
                if ( type() == Tcomplex ) 
                { 
                        // in this case user tried to read vector row from scalar column.
                        // one could be charitable and return a valarray of size 1,
                        // but... I'm going to throw an exception suggesting the user
                        // might not have meant that.

                        throw Column::WrongColumnType(name());
                }
                else
                {
                       try
                       {
                            ColumnVectorData<std::complex<double> >& col 
                                 = dynamic_cast<ColumnVectorData<std::complex<double> >&>(*this);
                            if (!isRead()) col.readRow(row);                                  
                            FITSUtil::fill(vals,col.data(row));
                               
                       }
                       catch (std::bad_cast)
                       {
                              std::string 
                        msg(" implicit conversion from complex to real data not allowed: Column ");
                              msg += name();
                              throw InvalidDataType(msg);
                               
                       }    
                }

          }

    }
        
    void 
    Column::read(std::valarray<std::complex<double> >& vals, long row)
    {
          if ( ColumnVectorData<std::complex<double> >* col 
                          = dynamic_cast<ColumnVectorData<std::complex<double> >*>(this))
          {
                  // fails if user requested outputType different from input type.



                  // input and output are both valarrays. Since one should not
                  // be able to call a constructor for a non-numeric valarray type,
                  // there shouldn't be any InvalidType problems. However, there
                  // is still the vector/scalar possibility and the implicit
                  // conversion request to deal with.

                  if (!isRead()) col->readRow(row);
                  FITSUtil::fill(vals,col->data(row));
          }
          else
          {
                if ( type() == Tdblcomplex ) 
                { 
                        // in this case user tried to read vector row from scalar column.
                        // one could be charitable and return a valarray of size 1,
                        // but... I'm going to throw an exception suggesting the user
                        // might not have meant that.

                        throw Column::WrongColumnType(name());
                }
                else
                {
                       try
                       {
                            ColumnVectorData<std::complex<float> >& col 
                                 = dynamic_cast<ColumnVectorData<std::complex<float> >&>(*this);
                            if (!isRead()) col.readRow(row);                                  
                            FITSUtil::fill(vals,col.data(row));
                               
                       }
                       catch (std::bad_cast)
                       {
                              std::string 
                        msg(" implicit conversion from complex to real data not allowed: Column ");
                              msg += name();
                              throw InvalidDataType(msg);
                               
                       }    
                }
        }
    }
  
  void 
  Column::readArrays(std::vector<std::valarray<std::complex<float> > >& vals, long first, long last)
  {
                // again, can only call this if the entire column has been read from disk.
                // user expects 1 based indexing. If 0 based indices are supplied,
                // add one to both ranges.
                long range = numberOfElements(first,last);

                vals.resize(range);


                if ( ColumnVectorData<std::complex<float> >* col 
                                = dynamic_cast<ColumnVectorData<std::complex<float> >*>(this))
                {
                        for (int j = 0; j < range; ++j) 
                        {
                                if (!isRead()) col->readRow(j + first);                             
                                FITSUtil::fill(vals[j],col->data(j+first));
                        }
                }
                else
                {
                        if ( type() == Tcomplex) 
                        { 
                                // in this case user tried to read vector data from scalar,
                                // (i.e. first argument was vector<valarray<S> >.
                                // since the cast won't fail on template parameter grounds.
                                throw Column::WrongColumnType(name());
                        }
                        // the InvalidDataType exception should not be possible.
                        try
                        {
                                 ColumnVectorData<std::complex<double> >& col 
                                         = dynamic_cast<ColumnVectorData<std::complex<double> >&>(*this);
                                 for (int j = 0; j < range; ++j) 
                                 {
                                     if (!isRead()) col.readRow(j + first); 
                                     FITSUtil::fill(vals[j],col.data(j+first));
                                 }

                        }
                        catch (std::bad_cast)
                        {
                                      std::string 
                                msg(" implicit conversion from complex to real data not allowed: Column ");
                                      msg += name();
                                      throw InvalidDataType(msg);

                        }
                        
                }
             
  }                
        
 void 
  Column::readArrays(std::vector<std::valarray<std::complex<double> > >& vals, long first, long last)
  {
                // again, can only call this if the entire column has been read from disk.
                // user expects 1 based indexing. If 0 based indices are supplied,
                // add one to both ranges.
                long range = numberOfElements(first,last);

                vals.resize(range);


                if ( ColumnVectorData<std::complex<double> >* col 
                                = dynamic_cast<ColumnVectorData<std::complex<double> >*>(this))
                {
                        for (int j = 0; j < range; ++j) 
                        {
                                if (!isRead()) col->readRow(j + first);                             
                                FITSUtil::fill(vals[j],col->data(j+first));
                        }
                }
                else
                {
                        if ( type() == Tdblcomplex) 
                        { 
                                // in this case user tried to read vector data from scalar,
                                // (i.e. first argument was vector<valarray<S> >.
                                // since the cast won't fail on template parameter grounds.
                                throw Column::WrongColumnType(name());
                        }
                        // the InvalidDataType exception should not be possible.
                        try
                        {
                                 ColumnVectorData<std::complex<float> >& col 
                                         = dynamic_cast<ColumnVectorData<std::complex<float> >&>(*this);
                                 for (int j = 0; j < range; ++j) 
                                 {
                                     if (!isRead()) col.readRow(j + first); 
                                     FITSUtil::fill(vals[j],col.data(j+first));
                                 }

                        }
                        catch (std::bad_cast)
                        {
                                      std::string 
                                msg(" implicit conversion from complex to real data not allowed: Column ");
                                      msg += name();
                                      throw InvalidDataType(msg);

                        }
                        
                }
             
  }                
    
  void 
  Column::write (const std::valarray<std::complex<float> >& indata, long nRows, long firstRow)
  {
        if (nRows <= 0) throw InvalidNumberOfRows(nRows);
        firstRow = std::max(firstRow,static_cast<long>(1));
        if (ColumnVectorData<std::complex<float> >* col 
                        = dynamic_cast<ColumnVectorData<std::complex<float> >*>(this))
        {
                col->writeData(indata,nRows,firstRow);
        }
        else 
        {
                // alright, input data type has to be rewritten as output
                // data type.
                if ( type()  == Tcomplex ) 
                {
                        string 
                          msg("Incorrect call: writing to valarray data to scalar column: ");
                          msg += name();
                          msg += " does not require specification of number of rows";
                        throw WrongColumnType(msg);
                }
                else
                {
                        try
                        {
                                ColumnVectorData<std::complex<double> >& col 
                                        = dynamic_cast<ColumnVectorData<std::complex<double> >&>(*this);
                                std::valarray<std::complex<double> > __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,nRows,firstRow);                              
                        }
                        catch (std::bad_cast)
                        {
                                std::string msg(" implicit conversion from complex to real data not allowed: Column ");
                                msg += name();
                                throw InvalidDataType(msg);
                                
                        }
                }
        }
  }

  void 
  Column::write (const std::valarray<std::complex<double> >& indata, long nRows, long firstRow)
  {
        if (nRows <= 0) throw InvalidNumberOfRows(nRows);
        firstRow = std::max(firstRow,static_cast<long>(1));
        if (ColumnVectorData<std::complex<double> >* col 
                        = dynamic_cast<ColumnVectorData<std::complex<double> >*>(this))
        {
                col->writeData(indata,nRows,firstRow);
        }
        else 
        {
                // alright, input data type has to be rewritten as output
                // data type.
                if ( type()  == Tdblcomplex ) 
                {
                        string msg("Incorrect call: writing to valarray data to scalar column: ");
                        msg += name();
                        msg += " does not require specification of number of rows";
                        throw WrongColumnType(msg);
                }
                else
                {
                        try
                        {
                                ColumnVectorData<std::complex<float> >& col 
                                        = dynamic_cast<ColumnVectorData<std::complex<float> >&>(*this);
                                std::valarray<std::complex<float> > __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,nRows,firstRow);                              
                        }
                        catch (std::bad_cast)
                        {
                                std::string msg(" implicit conversion from complex to real data not allowed: Column ");
                                msg += name();
                                throw InvalidDataType(msg);
                                
                        }
                }
        }

  }
  
  void
  Column::write (const std::vector<std::complex<float> >& indata, long nRows, long firstRow)
  {
          std::valarray<std::complex<float> >  __tmp(indata.size());

#ifdef TEMPLATE_AMBIG_DEFECT
          FITSUtil::fillMSafvf(__tmp,indata,1,indata.size());
#else
          FITSUtil::fill(__tmp,indata,1,indata.size());
#endif
         write(__tmp,nRows,firstRow);
  }
  
  void 
  Column::write (const std::vector<std::complex<double> >& indata, long nRows, long firstRow)
  {
          std::valarray<std::complex<double> >  __tmp(indata.size());

#ifdef TEMPLATE_AMBIG_DEFECT
          FITSUtil::fillMSadvd(__tmp,indata,1,indata.size());
#else
		  FITSUtil::fill(__tmp,indata,1,indata.size());
#endif
          write(__tmp,nRows,firstRow);          
  }
  
  void 
  Column::write (const std::valarray<std::complex<float> >& indata,  
                        const std::vector<long>& vectorLengths, 
                        long firstRow)
  {
        using std::valarray;
        firstRow = std::max(firstRow,static_cast<long>(1));
        if (ColumnVectorData<std::complex<float> >* col 
                        = dynamic_cast<ColumnVectorData<std::complex<float> >*>(this))
        {
                col->writeData(indata,vectorLengths,firstRow);
        }
        else
        {
                if (  type() == Tcomplex ) 
                {
                        string msg("Incorrect call: scalar column ");
                        msg += name();
                        msg += " does not have vector lengths";
                        throw WrongColumnType(msg);
                }
                else
                {
                        try
                        {
                                ColumnVectorData<std::complex<double> >& col 
                                        = dynamic_cast<ColumnVectorData<std::complex<double> >&>(*this);                                        
                                valarray<std::complex<double> > __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,vectorLengths,firstRow);

                        }
                        catch (std::bad_cast)
                        {
                                std::string msg(" implicit conversion from complex to real data not allowed: Column ");
                                msg += name();
                                throw InvalidDataType(msg);
                        }       
                }               
        }  
  }    

  void 
  Column::write (const std::valarray<std::complex<double> >& indata,  
                        const std::vector<long>& vectorLengths, 
                        long firstRow)
  {
        using std::valarray;
        firstRow = std::max(firstRow,static_cast<long>(1));
        if (ColumnVectorData<std::complex<double> >* col 
                        = dynamic_cast<ColumnVectorData<std::complex<double> >*>(this))
        {
                col->writeData(indata,vectorLengths,firstRow);
        }
        else
        {
                if (  type() == Tdblcomplex ) 
                {
                        string msg("Incorrect call: scalar column ");
                        msg += name();
                        msg += " does not have vector lengths";
                        throw WrongColumnType(msg);
                }
                else
                {
                        try
                        {
                                ColumnVectorData<std::complex<float> >& col 
                                        = dynamic_cast<ColumnVectorData<std::complex<float> >&>(*this);                                        
                                valarray<std::complex<float> > __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,vectorLengths,firstRow);

                        }
                        catch (std::bad_cast)
                        {
                                std::string msg(" implicit conversion from complex to real data not allowed: Column ");
                                msg += name();
                                throw InvalidDataType(msg);
                        }       
                }               
        }            
  }      
  
  void 
  Column::write (const std::vector<std::complex<float> >& indata, 
                const std::vector<long>& vectorLengths, 
                long firstRow)
  {
          std::valarray<std::complex<float> >  __tmp(indata.size());
#ifdef TEMPLATE_AMBIG_DEFECT
          FITSUtil::fillMSafvf(__tmp,indata,1,indata.size());
#else
		  FITSUtil::fill(__tmp,indata,1,indata.size());
#endif
		  write(__tmp,vectorLengths,firstRow);
  }
  


  void 
  Column::write (const std::vector<std::complex<double> >& indata, 
                        const std::vector<long>& vectorLengths, 
                        long firstRow)
  {
          std::valarray<std::complex<double> >  __tmp(indata.size());
#ifdef TEMPLATE_AMBIG_DEFECT
          FITSUtil::fillMSadvd(__tmp,indata,1,indata.size());
#else
		  FITSUtil::fill(__tmp,indata,1,indata.size());
#endif
		  write(__tmp,vectorLengths,firstRow);        
  }

  
  
  void 
  Column::writeArrays (const std::vector<std::valarray<std::complex<float> > >& indata, 
                  long firstRow)
  {
        firstRow = std::max(firstRow,static_cast<long>(1));
        if (ColumnVectorData<std::complex<float> >* col 
                        = dynamic_cast<ColumnVectorData<std::complex<float> >*>(this))
        {
                 col->writeData(indata,firstRow);
        }
        else
        {
                if (  type() == Tcomplex ) 
                {
                        string msg("Incorrect call: writing vectors to scalar column ");
                        throw WrongColumnType(msg);
                }
                else
                {
                        size_t n(indata.size());     
                        try 
                        {                       
                            ColumnVectorData<std::complex<double> >& col 
                            = dynamic_cast<ColumnVectorData<std::complex<double> >&>(*this);
                            std::vector<std::valarray<std::complex<double> > > __tmp(n);
                            for (size_t i = 0; i < n; ++i)
                            {
                                    FITSUtil::fill(__tmp[i],indata[i]);
                            }
                            col.writeData(__tmp,firstRow);
                        }
                        catch (std::bad_cast)
                        {
                                std::string msg
                        (" implicit conversion from complex to real data not allowed: Column ");
                                msg += name();
                                throw InvalidDataType(msg);
                        }
                 }
        }
  }
                  
  void 
  Column::writeArrays (const std::vector<std::valarray<std::complex<double> > >& indata, long firstRow)
  {
        firstRow = std::max(firstRow,static_cast<long>(1));
        if (ColumnVectorData<std::complex<double> >* col 
                        = dynamic_cast<ColumnVectorData<std::complex<double> >*>(this))
        {
                 col->writeData(indata,firstRow);
        }
        else
        {
                if (  type() == Tcomplex ) 
                {
                        string msg("Incorrect call: writing vectors to scalar column ");
                        throw WrongColumnType(msg);
                }
                else
                {
                        size_t n(indata.size());     
                        try 
                        {                       
                            ColumnVectorData<std::complex<float> >& col 
                            = dynamic_cast<ColumnVectorData<std::complex<float> >&>(*this);
                            std::vector<std::valarray<std::complex<float> > > __tmp(n);
                            for (size_t i = 0; i < n; ++i)
                            {
                                    FITSUtil::fill(__tmp[i],indata[i]);
                            }
                            col.writeData(__tmp,firstRow);
                        }
                        catch (std::bad_cast)
                        {
                                std::string msg
                        (" implicit conversion from complex to real data not allowed: Column ");
                                msg += name();
                                throw InvalidDataType(msg);
                        }
                 }
        }
          
  }

} // namespace CCfits

