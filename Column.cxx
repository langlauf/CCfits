//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3804E902E258.cm preserve=no
//	This is version 1.2 release dated April 2003
//## end module%3804E902E258.cm

//## begin module%3804E902E258.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author:  Ben Dorman, L3-Communications EER Systems Inc.
//## end module%3804E902E258.cp

//## Module: Column%3804E902E258; Package body
//## Subsystem: CCfits::Column%3934116D0008
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/Column.cxx

//## begin module%3804E902E258.additionalIncludes preserve=no
//## end module%3804E902E258.additionalIncludes

//## begin module%3804E902E258.includes preserve=yes

#ifdef _MSC_VER
#include "MSconfig.h" // for truncation warning
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef SSTREAM_DEFECT
#include <strstream>
using std::ostrstream;
#else
#include <sstream>
using std::ostringstream;
#endif

//## end module%3804E902E258.includes

// Table
#include "Table.h"
// Column
#include "Column.h"


//## begin module%3804E902E258.declarations preserve=no
//## end module%3804E902E258.declarations

//## begin module%3804E902E258.additionalDeclarations preserve=yes
#include "FITS.h"
#include "fitsio2.h"
#include "ColumnData.h"
#include "ColumnVectorData.h"
#include <limits.h>
#include <float.h>
//## end module%3804E902E258.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  // Class CCfits::Column::RangeError 

  Column::RangeError::RangeError (const String& msg, bool silent)
    //## begin CCfits::Column::RangeError::RangeError%394651000189.hasinit preserve=yes
  : FitsException("FitsError: Range error in operation ",silent)
    //## end CCfits::Column::RangeError::RangeError%394651000189.hasinit
    //## begin CCfits::Column::RangeError::RangeError%394651000189.initialization preserve=yes
    //## end CCfits::Column::RangeError::RangeError%394651000189.initialization
  {
    //## begin CCfits::Column::RangeError::RangeError%394651000189.body preserve=yes
  if (!silent || FITS::verboseMode() ) std::cerr << msg << '\n';
    //## end CCfits::Column::RangeError::RangeError%394651000189.body
  }


  // Class CCfits::Column::InvalidDataType 

  Column::InvalidDataType::InvalidDataType (const String& str, bool silent)
    //## begin CCfits::Column::InvalidDataType::InvalidDataType%3947CF410349.hasinit preserve=yes
  : FitsException("FitsError: Incorrect data type: ",silent)
    //## end CCfits::Column::InvalidDataType::InvalidDataType%3947CF410349.hasinit
    //## begin CCfits::Column::InvalidDataType::InvalidDataType%3947CF410349.initialization preserve=yes
    //## end CCfits::Column::InvalidDataType::InvalidDataType%3947CF410349.initialization
  {
    //## begin CCfits::Column::InvalidDataType::InvalidDataType%3947CF410349.body preserve=yes
  if (!silent || FITS::verboseMode() ) std::cerr << str << '\n';
    //## end CCfits::Column::InvalidDataType::InvalidDataType%3947CF410349.body
  }


  // Class CCfits::Column::InvalidRowParameter 

  Column::InvalidRowParameter::InvalidRowParameter (const String& diag, bool silent)
    //## begin CCfits::Column::InvalidRowParameter::InvalidRowParameter%39B52EE000AF.hasinit preserve=yes
  : FitsException("FitsError: row offset or length incompatible with column declaration ",silent)
    //## end CCfits::Column::InvalidRowParameter::InvalidRowParameter%39B52EE000AF.hasinit
    //## begin CCfits::Column::InvalidRowParameter::InvalidRowParameter%39B52EE000AF.initialization preserve=yes
    //## end CCfits::Column::InvalidRowParameter::InvalidRowParameter%39B52EE000AF.initialization
  {
    //## begin CCfits::Column::InvalidRowParameter::InvalidRowParameter%39B52EE000AF.body preserve=yes
  if (!silent || FITS::verboseMode() ) std::cerr << diag << '\n';
    //## end CCfits::Column::InvalidRowParameter::InvalidRowParameter%39B52EE000AF.body
  }


  // Class CCfits::Column::WrongColumnType 

  Column::WrongColumnType::WrongColumnType (const String& diag, bool silent)
    //## begin CCfits::Column::WrongColumnType::WrongColumnType%39B5452302B7.hasinit preserve=yes
  : FitsException("FitsError: Attempt to return scalar data from vector column, or vice versa - Column: ",silent)
    //## end CCfits::Column::WrongColumnType::WrongColumnType%39B5452302B7.hasinit
    //## begin CCfits::Column::WrongColumnType::WrongColumnType%39B5452302B7.initialization preserve=yes
    //## end CCfits::Column::WrongColumnType::WrongColumnType%39B5452302B7.initialization
  {
    //## begin CCfits::Column::WrongColumnType::WrongColumnType%39B5452302B7.body preserve=yes
  if (!silent || FITS::verboseMode() ) std::cerr << diag << '\n';
    //## end CCfits::Column::WrongColumnType::WrongColumnType%39B5452302B7.body
  }


  // Class CCfits::Column::UnspecifiedLengths 

  Column::UnspecifiedLengths::UnspecifiedLengths (const String& diag, bool silent)
    //## begin CCfits::Column::UnspecifiedLengths::UnspecifiedLengths%3A018C550303.hasinit preserve=yes
  : FitsException
        ("FitsError: Variable length column being written needs integer array of row lengths: Column ",silent)
                
    //## end CCfits::Column::UnspecifiedLengths::UnspecifiedLengths%3A018C550303.hasinit
    //## begin CCfits::Column::UnspecifiedLengths::UnspecifiedLengths%3A018C550303.initialization preserve=yes
    //## end CCfits::Column::UnspecifiedLengths::UnspecifiedLengths%3A018C550303.initialization
  {
    //## begin CCfits::Column::UnspecifiedLengths::UnspecifiedLengths%3A018C550303.body preserve=yes
  if (!silent || FITS::verboseMode() ) std::cerr << diag << '\n';
    //## end CCfits::Column::UnspecifiedLengths::UnspecifiedLengths%3A018C550303.body
  }


  // Class CCfits::Column::InvalidRowNumber 

  Column::InvalidRowNumber::InvalidRowNumber (const String& diag, bool silent)
    //## begin CCfits::Column::InvalidRowNumber::InvalidRowNumber%3B0A83990352.hasinit preserve=yes
  : FitsException("FitsError: Invalid Row Number - Column: ",silent)
    //## end CCfits::Column::InvalidRowNumber::InvalidRowNumber%3B0A83990352.hasinit
    //## begin CCfits::Column::InvalidRowNumber::InvalidRowNumber%3B0A83990352.initialization preserve=yes
    //## end CCfits::Column::InvalidRowNumber::InvalidRowNumber%3B0A83990352.initialization
  {
    //## begin CCfits::Column::InvalidRowNumber::InvalidRowNumber%3B0A83990352.body preserve=yes
    if (!silent || FITS::verboseMode() ) std::cerr << diag << '\n';
    //## end CCfits::Column::InvalidRowNumber::InvalidRowNumber%3B0A83990352.body
  }


  // Class CCfits::Column::InsufficientElements 

  Column::InsufficientElements::InsufficientElements (const String& msg, bool silent)
    //## begin CCfits::Column::InsufficientElements::InsufficientElements%3B0BE63102DD.hasinit preserve=yes
     : FitsException("FitsError: not enough elements supplied for write operation ",silent)
    //## end CCfits::Column::InsufficientElements::InsufficientElements%3B0BE63102DD.hasinit
    //## begin CCfits::Column::InsufficientElements::InsufficientElements%3B0BE63102DD.initialization preserve=yes
    //## end CCfits::Column::InsufficientElements::InsufficientElements%3B0BE63102DD.initialization
  {
    //## begin CCfits::Column::InsufficientElements::InsufficientElements%3B0BE63102DD.body preserve=yes
    if (!silent || FITS::verboseMode() ) std::cerr << msg << '\n';    
    //## end CCfits::Column::InsufficientElements::InsufficientElements%3B0BE63102DD.body
  }


  // Class CCfits::Column::NoNullValue 

  Column::NoNullValue::NoNullValue (const String& diag, bool silent)
    //## begin CCfits::Column::NoNullValue::NoNullValue%3B0D58680222.hasinit preserve=yes
    : FitsException("Fits Error: No null value specified for column: ",silent)
    //## end CCfits::Column::NoNullValue::NoNullValue%3B0D58680222.hasinit
    //## begin CCfits::Column::NoNullValue::NoNullValue%3B0D58680222.initialization preserve=yes
    //## end CCfits::Column::NoNullValue::NoNullValue%3B0D58680222.initialization
  {
    //## begin CCfits::Column::NoNullValue::NoNullValue%3B0D58680222.body preserve=yes
     if (!silent || FITS::verboseMode() ) std::cerr << diag << '\n';    
    //## end CCfits::Column::NoNullValue::NoNullValue%3B0D58680222.body
  }


  // Class CCfits::Column::InvalidNumberOfRows 

  Column::InvalidNumberOfRows::InvalidNumberOfRows (size_t number, bool silent)
    //## begin CCfits::Column::InvalidNumberOfRows::InvalidNumberOfRows%3B20E7690328.hasinit preserve=yes
    : FitsException( "Fits Error: number of rows to write must be positive ",silent)
    //## end CCfits::Column::InvalidNumberOfRows::InvalidNumberOfRows%3B20E7690328.hasinit
    //## begin CCfits::Column::InvalidNumberOfRows::InvalidNumberOfRows%3B20E7690328.initialization preserve=yes
    //## end CCfits::Column::InvalidNumberOfRows::InvalidNumberOfRows%3B20E7690328.initialization
  {
    //## begin CCfits::Column::InvalidNumberOfRows::InvalidNumberOfRows%3B20E7690328.body preserve=yes
     if (!silent || FITS::verboseMode() ) std::cerr << " specified: " << number  << '\n';    
    //## end CCfits::Column::InvalidNumberOfRows::InvalidNumberOfRows%3B20E7690328.body
  }


  // Class CCfits::Column 

  //## begin CCfits::Column::TBCOL%3B41E45800B2.attr preserve=no  protected: static String {VC} "TBCOL"
  const String Column::s_TBCOL = "TBCOL";
  //## end CCfits::Column::TBCOL%3B41E45800B2.attr

  //## begin CCfits::Column::TTYPE%3B41E4B6013B.attr preserve=no  protected: static String {VC} "TTYPE"
  const String Column::s_TTYPE = "TTYPE";
  //## end CCfits::Column::TTYPE%3B41E4B6013B.attr

  //## begin CCfits::Column::TFORM%3B41E4C401F8.attr preserve=no  public: static const String {VC} "TFORM"
  const String Column::s_TFORM = "TFORM";
  //## end CCfits::Column::TFORM%3B41E4C401F8.attr

  //## begin CCfits::Column::TDISP%3B41E4D4025C.attr preserve=no  public: static String {VC} "TDISP"
  const String Column::s_TDISP = "TDISP";
  //## end CCfits::Column::TDISP%3B41E4D4025C.attr

  //## begin CCfits::Column::TUNIT%3B41E4EC0050.attr preserve=no  protected: static String {VC} "TUNIT"
  const String Column::s_TUNIT = "TUNIT";
  //## end CCfits::Column::TUNIT%3B41E4EC0050.attr

  //## begin CCfits::Column::TSCAL%3B41E4FE0096.attr preserve=no  public: static String {VC} "TSCAL"
  const String Column::s_TSCAL = "TSCAL";
  //## end CCfits::Column::TSCAL%3B41E4FE0096.attr

  //## begin CCfits::Column::TZERO%3B41E6730238.attr preserve=no  public: static String {VC} "TZERO"
  const String Column::s_TZERO = "TZERO";
  //## end CCfits::Column::TZERO%3B41E6730238.attr

  //## begin CCfits::Column::TDIM%3B41E793003F.attr preserve=no  public: static String {VC} "TDIM"
  const String Column::s_TDIM = "TDIM";
  //## end CCfits::Column::TDIM%3B41E793003F.attr

  //## begin CCfits::Column::TNULL%3B41E807029A.attr preserve=no  protected: static String {VC} "TNULL"
  const String Column::s_TNULL = "TNULL";
  //## end CCfits::Column::TNULL%3B41E807029A.attr

  //## begin CCfits::Column::TLMIN%3B41E8300368.attr preserve=no  protected: static String {VC} "TLMIN"
  const String Column::s_TLMIN = "TLMIN";
  //## end CCfits::Column::TLMIN%3B41E8300368.attr

  //## begin CCfits::Column::TLMAX%3B41E8330127.attr preserve=no  protected: static String {VC} "TLMAX"
  const String Column::s_TLMAX = "TLMAX";
  //## end CCfits::Column::TLMAX%3B41E8330127.attr

  //## begin CCfits::Column::TDMAX%3B41E86F00AF.attr preserve=no  protected: static String {VC} "TDMAX"
  const String Column::s_TDMAX = "TDMAX";
  //## end CCfits::Column::TDMAX%3B41E86F00AF.attr

  //## begin CCfits::Column::TDMIN%3B41E87301A5.attr preserve=no  protected: static String {VC} "TDMIN"
  const String Column::s_TDMIN = "TDMIN";
  //## end CCfits::Column::TDMIN%3B41E87301A5.attr

  //## begin CCfits::Column::LLIMITSHORT%3B41EF3800F8.attr preserve=no  private: static short {VC} SHRT_MIN
  const short Column::LLIMITSHORT = SHRT_MIN;
  //## end CCfits::Column::LLIMITSHORT%3B41EF3800F8.attr

  //## begin CCfits::Column::LLIMITLONG%3B41EF710302.attr preserve=no  private: static long {VC} LONG_MIN
  const long Column::LLIMITLONG = LONG_MIN;
  //## end CCfits::Column::LLIMITLONG%3B41EF710302.attr

  //## begin CCfits::Column::LLIMITUSHORT%3B41EF9D0367.attr preserve=no  private: static unsigned short {VC} 0
  const unsigned short Column::LLIMITUSHORT = 0;
  //## end CCfits::Column::LLIMITUSHORT%3B41EF9D0367.attr

  //## begin CCfits::Column::LLIMITULONG%3B41EFC40063.attr preserve=no  private: static unsigned long {VC} 0
  const unsigned long Column::LLIMITULONG = 0;
  //## end CCfits::Column::LLIMITULONG%3B41EFC40063.attr

  //## begin CCfits::Column::LLIMITUCHAR%3B41EFD50177.attr preserve=yes  private: static unsigned char {VC} 0
  const unsigned char Column::LLIMITUCHAR = 0;
  //## end CCfits::Column::LLIMITUCHAR%3B41EFD50177.attr

  //## begin CCfits::Column::LLIMITFLOAT%3B41EFEA021B.attr preserve=no  private: static float {VC} FLT_MIN
  const float Column::LLIMITFLOAT = FLT_MIN;
  //## end CCfits::Column::LLIMITFLOAT%3B41EFEA021B.attr

  //## begin CCfits::Column::LLIMITDOUBLE%3B41F003025F.attr preserve=no  private: static double {VC} DBL_MIN
  const double Column::LLIMITDOUBLE = DBL_MIN;
  //## end CCfits::Column::LLIMITDOUBLE%3B41F003025F.attr

  //## begin CCfits::Column::ULIMITSHORT%3B41F02201C1.attr preserve=no  private: static short {VC} SHRT_MAX
  const short Column::ULIMITSHORT = SHRT_MAX;
  //## end CCfits::Column::ULIMITSHORT%3B41F02201C1.attr

  //## begin CCfits::Column::ULIMITLONG%3B41F0270291.attr preserve=no  private: static long {VC} LONG_MAX
  const long Column::ULIMITLONG = LONG_MAX;
  //## end CCfits::Column::ULIMITLONG%3B41F0270291.attr

  //## begin CCfits::Column::ULIMITUSHORT%3B41F02B032A.attr preserve=no  private: static unsigned short {VC} USHRT_MAX
  const unsigned short Column::ULIMITUSHORT = USHRT_MAX;
  //## end CCfits::Column::ULIMITUSHORT%3B41F02B032A.attr

  //## begin CCfits::Column::ULIMITULONG%3B41F02F0325.attr preserve=no  private: static unsigned long {VC} ULONG_MAX
  const unsigned long Column::ULIMITULONG = ULONG_MAX;
  //## end CCfits::Column::ULIMITULONG%3B41F02F0325.attr

  //## begin CCfits::Column::ULIMITUCHAR%3B41F03701B2.attr preserve=no  private: static unsigned char {VC} UCHAR_MAX
  const unsigned char Column::ULIMITUCHAR = UCHAR_MAX;
  //## end CCfits::Column::ULIMITUCHAR%3B41F03701B2.attr

  //## begin CCfits::Column::ULIMITFLOAT%3B41F03B00F1.attr preserve=no  private: static float {VC} FLT_MAX
  const float Column::ULIMITFLOAT = FLT_MAX;
  //## end CCfits::Column::ULIMITFLOAT%3B41F03B00F1.attr

  //## begin CCfits::Column::ULIMITDOUBLE%3B41F03F0040.attr preserve=no  private: static double {VC} DBL_MAX
  const double Column::ULIMITDOUBLE = DBL_MAX;
  //## end CCfits::Column::ULIMITDOUBLE%3B41F03F0040.attr

  //## begin CCfits::Column::LLIMITINT%3B41F0A5018E.attr preserve=no  private: static int {VC} INT_MIN
  const int Column::LLIMITINT = INT_MIN;
  //## end CCfits::Column::LLIMITINT%3B41F0A5018E.attr

  //## begin CCfits::Column::ULIMITINT%3B41F0A80334.attr preserve=no  private: static int {VC} INT_MAX
  const int Column::ULIMITINT = INT_MAX;
  //## end CCfits::Column::ULIMITINT%3B41F0A80334.attr

  //## begin CCfits::Column::LLIMITUINT%3B41F0AC022F.attr preserve=no  private: static unsigned int {VC} 0
  const unsigned int Column::LLIMITUINT = 0;
  //## end CCfits::Column::LLIMITUINT%3B41F0AC022F.attr

  //## begin CCfits::Column::ULIMITUINT%3B41F0AF028A.attr preserve=no  private: static unsigned int {VC} UINT_MAX
  const unsigned int Column::ULIMITUINT = UINT_MAX;
  //## end CCfits::Column::ULIMITUINT%3B41F0AF028A.attr

  //## begin CCfits::Column::LLIMITLONGLONG%4134E15F012E.attr preserve=no  private: static LONGLONG {VC} LONGLONG_MIN
  const LONGLONG Column::LLIMITLONGLONG = LONGLONG_MIN;
  //## end CCfits::Column::LLIMITLONGLONG%4134E15F012E.attr

  //## begin CCfits::Column::ULIMITLONGLONG%4134E1D10336.attr preserve=no  private: static LONGLONG {VC} LONGLONG_MAX
  const LONGLONG Column::ULIMITLONGLONG = LONGLONG_MAX;
  //## end CCfits::Column::ULIMITLONGLONG%4134E1D10336.attr

  //## begin CCfits::Column::columnKeys%3B41E8CD029C.role preserve=no  protected: static CCfits::String {1 -> 1..nVHgN}
  std::vector<String> Column::s_columnKeys;
  //## end CCfits::Column::columnKeys%3B41E8CD029C.role


  Column::Column(const Column &right)
    //## begin Column::Column%3804E8D06FF8_copy.hasinit preserve=yes
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
        m_parent(right.m_parent),
	m_comment(right.m_comment),
	m_format(right.m_format),
	m_unit(right.m_unit),
	m_name(right.m_name)
    //## end Column::Column%3804E8D06FF8_copy.hasinit
    //## begin Column::Column%3804E8D06FF8_copy.initialization preserve=yes
    //## end Column::Column%3804E8D06FF8_copy.initialization
  {
    //## begin CCfits::Column::Column%3804E8D06FF8_copy.body preserve=yes
    //## end CCfits::Column::Column%3804E8D06FF8_copy.body
  }

  Column::Column (int columnIndex, const String &columnName, ValueType type, const String &format, const String &unit, Table* p, int rpt, long w, const String &comment)
    //## begin CCfits::Column::Column%385E7153FA28.hasinit preserve=yes
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
   m_parent(p),
   m_comment(comment),
   m_format(format),
   m_unit(unit),
   m_name(columnName)
    //## end CCfits::Column::Column%385E7153FA28.hasinit
    //## begin CCfits::Column::Column%385E7153FA28.initialization preserve=yes
    //## end CCfits::Column::Column%385E7153FA28.initialization
  {
    //## begin CCfits::Column::Column%385E7153FA28.body preserve=yes
    Column::loadColumnKeys();
    setDisplay();
    setDimen();
    //## end CCfits::Column::Column%385E7153FA28.body
  }

  Column::Column (Table* p)
    //## begin CCfits::Column::Column%3937C21F0138.hasinit preserve=yes
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
        m_parent(p),
        m_comment(""),
        m_format(""),
        m_unit(""),
        m_name("")
    //## end CCfits::Column::Column%3937C21F0138.hasinit
    //## begin CCfits::Column::Column%3937C21F0138.initialization preserve=yes
    //## end CCfits::Column::Column%3937C21F0138.initialization
  {
    //## begin CCfits::Column::Column%3937C21F0138.body preserve=yes
  // default constructor.
    Column::loadColumnKeys();
    //## end CCfits::Column::Column%3937C21F0138.body
  }


  Column::~Column()
  {
    //## begin CCfits::Column::~Column%3804E8D06FF8_dest.body preserve=yes
    //## end CCfits::Column::~Column%3804E8D06FF8_dest.body
  }


  bool Column::operator==(const Column &right) const
  {
    //## begin CCfits::Column::operator==%3804E8D06FF8_eq.body preserve=yes
  return compare(right);
    //## end CCfits::Column::operator==%3804E8D06FF8_eq.body
  }

  bool Column::operator!=(const Column &right) const
  {
    //## begin CCfits::Column::operator!=%3804E8D06FF8_neq.body preserve=yes
  return !compare(right);
    //## end CCfits::Column::operator!=%3804E8D06FF8_neq.body
  }



  //## Other Operations (implementation)
  bool Column::compare (const Column &right) const
  {
    //## begin CCfits::Column::compare%3832D29BD548.body preserve=yes
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
    //## end CCfits::Column::compare%3832D29BD548.body
  }

  fitsfile* Column::fitsPointer ()
  {
    //## begin CCfits::Column::fitsPointer%3937DCD0038C.body preserve=yes
    //## end CCfits::Column::fitsPointer%3937DCD0038C.body

    return m_parent->fitsPointer();
  }

  void Column::makeHDUCurrent ()
  {
    m_parent->makeThisCurrent();

    //## begin CCfits::Column::makeHDUCurrent%393FE92F029F.body preserve=yes
    //## end CCfits::Column::makeHDUCurrent%393FE92F029F.body
  }

  int Column::rows () const
  {
    //## begin CCfits::Column::rows%39465C400353.body preserve=yes
  return m_parent->rows();   
    //## end CCfits::Column::rows%39465C400353.body
  }

  void Column::setDisplay ()
  {
    //## begin CCfits::Column::setDisplay%3948FF000114.body preserve=yes
#ifdef SSTREAM_DEFECT
  ostrstream key;
#else
  std::ostringstream key;
#endif
  key << "TDISP" << index();
  int status = 0;
  FITSUtil::auto_array_ptr<char> dispValue (new char[FLEN_VALUE]);
#ifdef SSTREAM_DEFECT
  key << std::ends;
  fits_read_key_str(fitsPointer(), key.str(), dispValue.get(),0,&status);
#else
  fits_read_key_str(fitsPointer(),const_cast<char*>(key.str().c_str()),dispValue.get(),0,&status);
#endif
  if (status == 0)
  {
        m_display = String(dispValue.get());
  }
    //## end CCfits::Column::setDisplay%3948FF000114.body
  }

  std::ostream& Column::put (std::ostream& s) const
  {
    //## begin CCfits::Column::put%39513C7401F6.body preserve=yes
  {
     s << "Column Name:"  << name() << " Number: " << index() <<  "   unit: " << unit() << "\n";
     s << "format: " << format() << " comment: " << comment() << "\n";
  }
    //## end CCfits::Column::put%39513C7401F6.body

    return s;
  }

  Table* Column::parent () const
  {
    //## begin CCfits::Column::parent%3B0154C00364.body preserve=yes
    //## end CCfits::Column::parent%3B0154C00364.body

    return m_parent;
  }

  void Column::setLimits (ValueType type)
  {
    //## begin CCfits::Column::setLimits%3B41E12B010C.body preserve=yes
    int status(0);
    static long*  pl  = new long[4];
    static LONGLONG* pll = new LONGLONG[4];
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
#ifdef SSTREAM_DEFECT
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
    
#ifdef SSTREAM_DEFECT
    slmin << std::ends;
    slmax << std::ends;
    sdmin << std::ends;
    sdmax << std::ends;
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
        case VTlonglong:
        case Tlonglong:
                // NOTE: cfitsio cannot currently read kewyords
                // of type long long.
                fits_read_key_lng(fitsPointer(),lmin,pl,0,&status);
                pll[0] = status ? LLIMITLONGLONG : pl[0];
                fits_read_key_lng(fitsPointer(),lmax,pl+1,0,&status);
                pll[1] = status ? ULIMITLONGLONG : pl[1];
                fits_read_key_lng(fitsPointer(),dmin,pl+2,0,&status);
                pll[2] = status ? LLIMITLONGLONG : pl[2];
                fits_read_key_lng(fitsPointer(),dmax,pl+3,0,&status);
                pll[3] = status ? ULIMITLONGLONG : pl[3];
                if (m_repeat == 1 && type > 0)
                {
                        ColumnData<LONGLONG>& col = 
                                dynamic_cast<ColumnData<LONGLONG>&>(*this);
                          col.setDataLimits(pll);                       
                }
                else
                {
                        ColumnVectorData<LONGLONG>& col = 
                                dynamic_cast<ColumnVectorData<LONGLONG>&>(*this);
                          col.setDataLimits(pll);                       
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
                      
          
          
    //## end CCfits::Column::setLimits%3B41E12B010C.body
  }

  void Column::loadColumnKeys ()
  {
    //## begin CCfits::Column::loadColumnKeys%3B41EB140398.body preserve=yes
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
    //## end CCfits::Column::loadColumnKeys%3B41EB140398.body
  }

  void Column::name (const String& value)
  {
    m_name = value;

    //## begin CCfits::Column::name%3B545ED20305.body preserve=yes
    //## end CCfits::Column::name%3B545ED20305.body
  }

  void Column::unit (const String& value)
  {
    m_unit = value;

    //## begin CCfits::Column::unit%3B545F61014D.body preserve=yes
    //## end CCfits::Column::unit%3B545F61014D.body
  }

  void Column::format (const String& value)
  {
    m_format = value;

    //## begin CCfits::Column::format%3B545FC8006E.body preserve=yes
    //## end CCfits::Column::format%3B545FC8006E.body
  }

  void Column::varLength (bool value)
  {
    //## begin CCfits::Column::varLength%3B7188120167.body preserve=yes
    m_varLength = value;
    //## end CCfits::Column::varLength%3B7188120167.body
  }

  long Column::numberOfElements (long& first, long& last)
  {
    //## begin CCfits::Column::numberOfElements%3CDFCA860268.body preserve=yes
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
    //## end CCfits::Column::numberOfElements%3CDFCA860268.body
  }

  // Additional Declarations
    //## begin CCfits::Column%3804E8D06FF8.declarations preserve=yes
  void 
  Column::write(const std::vector<String>& indata, long firstRow)
  {
    try
    {
        ColumnData<String>& col = dynamic_cast<ColumnData<String>& >(*this);       
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
                           String msg("Incorrect call: writing to vector column ");
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
                                 String msg(" implicit conversion from complex to real data not allowed: Column ");
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
                           String msg("Incorrect call: writing to vector column ");
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
                                 String msg(" implicit conversion from complex to real data not allowed: Column ");
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
    Column::read(std::vector<String>& vals, long first, long last)
    {
            try
            {
                ColumnData<String>& col = dynamic_cast<ColumnData<String>& >(*this);       
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
                          String msg("Incorrect call: writing to vector column ");
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
                                String msg(" implicit conversion from complex to real data not allowed: Column ");
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
                        String msg("Incorrect call: writing to vector column ");
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
                              String msg(" implicit conversion from complex to real data not allowed: Column ");
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
                              String 
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
                              String 
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
                                      String 
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
                                      String 
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
                        String 
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
                                String msg(" implicit conversion from complex to real data not allowed: Column ");
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
                        String msg("Incorrect call: writing to valarray data to scalar column: ");
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
                                String msg(" implicit conversion from complex to real data not allowed: Column ");
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
                        String msg("Incorrect call: scalar column ");
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
                                String msg(" implicit conversion from complex to real data not allowed: Column ");
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
                        String msg("Incorrect call: scalar column ");
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
                                String msg(" implicit conversion from complex to real data not allowed: Column ");
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
                        String msg("Incorrect call: writing vectors to scalar column ");
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
                                String msg
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
                        String msg("Incorrect call: writing vectors to scalar column ");
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
                                String msg
                        (" implicit conversion from complex to real data not allowed: Column ");
                                msg += name();
                                throw InvalidDataType(msg);
                        }
                 }
        }
          
  }

    //## end CCfits::Column%3804E8D06FF8.declarations
} // namespace CCfits

//## begin module%3804E902E258.epilog preserve=yes
//## end module%3804E902E258.epilog
