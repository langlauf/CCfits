
//	This is version 1.1.1 release dated Sept 2002

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	Sept 2002 Ben Dorman, L3-Communications
//	e-mail: ccfits@legacy.gsfc.nasa.gov



#ifdef _MSC_VER
#include "MSconfig.h" //for truncation warning
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_STRSTREAM
#include <strstream>
#else
#include <sstream>
#endif

#include <float.h>

// HDU
#include "HDU.h"
// PHDU
#include "PHDU.h"
// ExtHDU
#include "ExtHDU.h"
// FitsError
#include "FitsError.h"
// FITSBase
#include "FITSBase.h"
// ImageExt
#include "ImageExt.h"
// HDUCreator
#include "HDUCreator.h"
// PrimaryHDU
#include "PrimaryHDU.h"
// AsciiTable
#include "AsciiTable.h"
// BinTable
#include "BinTable.h"
// FITS
#include "FITS.h"





namespace CCfits {
  char BSCALE[7] = {"BSCALE"};
  char BZERO[6]  = {"BZERO"};

  // Class CCfits::HDUCreator 

  HDUCreator::HDUCreator (FITSBase* p)
  : m_hdu(0), m_parent(p) 
  {
  }


  HDUCreator::~HDUCreator()
  {
  }



  PHDU * HDUCreator::createImage (int bitpix, long naxis, const std::vector<long>& naxes)
  {
    return MakeImage(bitpix,naxis,naxes);
  }

  PHDU * HDUCreator::MakeImage (int bpix, int naxis, const std::vector<long>& naxes)
  {
    m_hdu = m_parent->pHDU();
    if (!m_hdu) 
    {
            switch (bpix)
            {
                case BYTE_IMG:
                        m_hdu = new PrimaryHDU<unsigned char>(m_parent,bpix,naxis,naxes);
                        break; 
                case SHORT_IMG:
                        m_hdu = new PrimaryHDU<short>(m_parent,bpix,naxis,naxes);
                        break; 
                case LONG_IMG:
                        m_hdu = new PrimaryHDU<long>(m_parent,bpix,naxis,naxes);
                        break; 
                case FLOAT_IMG:
                        m_hdu = new PrimaryHDU<float>(m_parent,bpix,naxis,naxes);
                        break; 
                case DOUBLE_IMG:
                        m_hdu = new PrimaryHDU<double>(m_parent,bpix,naxis,naxes);
                        break; 
                case USHORT_IMG:
                        m_hdu =  new PrimaryHDU<unsigned short>(m_parent,bpix,naxis,naxes);
                        m_hdu->bitpix(SHORT_IMG);
                        m_hdu->zero(USBASE);
                        break; 
                case ULONG_IMG:
                        m_hdu =  new PrimaryHDU<unsigned long>(m_parent,bpix,naxis,naxes);
                        m_hdu->bitpix(LONG_IMG);
                        m_hdu->zero(ULBASE);
                        break; 
                default:
                       throw HDU::InvalidImageDataType("FitsError: invalid data type for FITS I/O");
            } 
    }  
    return static_cast<PHDU*>(m_hdu);
  }

  HDU * HDUCreator::Make (const string& hduName, bool readDataFlag, const std::vector<string> &keys, bool primary, int version)
  {
    static char bitkey[] = "BITPIX";
    long bpix = 0;
    int status = 0;
    if ( !primary && fits_movnam_hdu(m_parent->fptr(),-1, 
             const_cast<char*>(hduName.c_str()),version,&status) )
    {
#ifdef HAVE_STRSTREAM
        std::ostrstream msg;
#else
        std::ostringstream msg;
#endif
        msg << "Cannot access HDU name " << hduName ;
        if (version) msg << " version " << version;
	throw FITS::NoSuchHDU(msg.str());
    }
    int htype = -1;
    if ( fits_get_hdu_type(m_parent->fptr(),&htype,&status) )
							throw FitsError(status);

    HduType xtype = HduType(htype);
    
    if ( fits_read_key_lng(m_parent->fptr(),bitkey,&bpix,0,&status) ) throw FitsError(status);
    m_hdu = m_parent->pHDU();
    double unsignedZero(0);
    double scale(1);
    getScaling(bpix,unsignedZero,scale);
    switch(xtype)
    {
        case ImageHdu:
            // ImageHDU types are templated
            switch (bpix)
            {
                    case Ibyte:
                            if (primary) 
                            {
                                    if (!m_hdu) m_hdu = 
                                        new PrimaryHDU<unsigned char>(m_parent,readDataFlag,keys);
                            }
                            else
                            {
                                    m_hdu = new ImageExt<unsigned char>
                                                (m_parent,hduName,readDataFlag,keys,version);   
                            }
                            break;   
                    case Ishort:
                            if (primary) 
                            {
                                if (!m_hdu) 
                                {           
                                        if (unsignedZero == USBASE && scale == 1 )
                                        { 
                                                m_hdu =  new PrimaryHDU<unsigned short>
                                                                (m_parent,readDataFlag,keys);
                                        }
                                        else
                                        {
                                                m_hdu =  new PrimaryHDU<short>
                                                                (m_parent,readDataFlag,keys);     
                                        }
                                }
                            }
                            else
                            {
                                        if (unsignedZero == USBASE && scale == 1 )
                                        { 
                                                m_hdu =  new ImageExt<unsigned short>
                                                               (m_parent,hduName,readDataFlag,keys);
                                        }
                                        else
                                        {
                                                m_hdu =  new ImageExt<short>
                                                               (m_parent,hduName,readDataFlag,keys);     
                                        }
                            }
			    break;
                    case Ilong:
                            if (primary) 
                            {
                                if (!m_hdu) 
                                {           
                                        if (unsignedZero == ULBASE && scale == 1)
                                        { 
                                                m_hdu =  new PrimaryHDU<unsigned long>
                                                                (m_parent,readDataFlag,keys);
                                        }
                                        else
                                        {
                                                m_hdu =  new PrimaryHDU<long>
                                                                (m_parent,readDataFlag,keys);     
                                        }
                                }
                            }
                            else
                            {
                                        if (unsignedZero == ULBASE && scale == 1)
                                        { 
                                                m_hdu =  new ImageExt<unsigned long>
                                                               (m_parent,hduName,readDataFlag,keys);
                                        }
                                        else
                                        {
                                                m_hdu =  new ImageExt<long>
                                                               (m_parent,hduName,readDataFlag,keys);     
                                        }
                            }
                            break;
                    case Ifloat:
                            if (primary) 
                            {
                                    if (!m_hdu) m_hdu = 
                                          new PrimaryHDU<float>(m_parent,readDataFlag,keys);
                           }
                            else
                            {
                                    m_hdu = new ImageExt<float>
                                                (m_parent,hduName,readDataFlag,keys,version);   
                            }
                            break;
                    case Idouble:
                            if (primary) 
                            {
                                    if (!m_hdu) m_hdu = 
                                          new PrimaryHDU<double>(m_parent,readDataFlag,keys);
                            }
                            else
                            {
                                    m_hdu = new ImageExt<double>
                                            (m_parent,hduName,readDataFlag,keys,version);   
                            }
                            break;
// dummy code to avoid SEGV in Solaris. This is supposed to trick the 
// compiler into instantiating PrimaryHDU<int, unsigned int>, ImageExt<int, unsigned int>
// so that it doesn't throw a SEGV if the user tries to read integer data into an
// integer array. But Tint is not actually an acceptable value for bitpix.
                    case Tint:
                            if (primary) 
                            {
                                if (!m_hdu) 
                                {           
                                        if (unsignedZero == ULBASE && scale == 1)
                                        { 
                                                m_hdu =  new PrimaryHDU<unsigned int>
                                                                (m_parent,readDataFlag,keys);
                                        }
                                        else
                                        {
                                                m_hdu =  new PrimaryHDU<int>
                                                                (m_parent,readDataFlag,keys);     
                                        }
                                }
                            }
                            else
                            {
                                        if (unsignedZero == ULBASE && scale == 1)
                                        { 
                                                m_hdu =  new ImageExt<unsigned int>
                                                               (m_parent,hduName,readDataFlag,keys);
                                        }
                                        else
                                        {
                                                m_hdu =  new ImageExt<int>
                                                               (m_parent,hduName,readDataFlag,keys);     
                                        }
                            }
                    default:
                            throw HDU::InvalidImageDataType(" invalid data type for FITS Image I/O");
            }    
            m_hdu->zero(unsignedZero);
            m_hdu->scale(scale);
	    break;
    case AsciiTbl:
	    m_hdu = new AsciiTable(m_parent, hduName, readDataFlag, keys, version);
	    break;

    case BinaryTbl:
	    m_hdu = new BinTable(m_parent, hduName, readDataFlag, keys, version);
	    break;

    default:
                throw HDU::InvalidImageDataType("FitsError: invalid data type for FITS I/O");
    }
    return m_hdu;
  }

  HDU* HDUCreator::MakeTable (const string &name, HduType xtype, int rows, const std::vector<string>& colName, const std::vector<string>& colFmt, const std::vector<string>& colUnit, int version)
  {
  switch (xtype)
  {
        case AsciiTbl:
                m_hdu = new AsciiTable(m_parent,name,rows,colName,colFmt,colUnit,version); 
                break;
        case BinaryTbl:
                m_hdu = new BinTable(m_parent,name,rows,colName,colFmt,colUnit,version);                 
                break;
        default:
                throw HDU::InvalidExtensionType("unexpected");
  }
  return m_hdu;
  }

  HDU * HDUCreator::Make (int index, bool readDataFlag, const std::vector<string> &keys)
  {
  bool primary = (index == 0);
  string hduName("");
  int version = 0;
  if (!primary) ExtHDU::readHduName(m_parent->fptr(),index,hduName,version );
  return Make(hduName,readDataFlag,keys,primary,version);
          
  }

  ExtHDU * HDUCreator::createImage (const string &name, int bitpix, long naxis, const std::vector<long>& naxes, int version)
  {
        return MakeImage(name,bitpix,naxis,naxes,version);
  }

  ExtHDU * HDUCreator::MakeImage (const string &name, int bpix, long naxis, const std::vector<long>& naxes, int version)
  {
  ExtHDU* newImage = 0;
  switch (bpix)
  {
      case BYTE_IMG:
                newImage =  new ImageExt<unsigned char>(m_parent,name,bpix,naxis,naxes,version);   
                break; 
      case SHORT_IMG:
                newImage =  new ImageExt<short>(m_parent,name,bpix,naxis,naxes,version);   
                break; 
      case LONG_IMG:
                newImage =  new ImageExt<long>(m_parent,name,bpix,naxis,naxes,version);   
                break; 
      case FLOAT_IMG:
                newImage =  new ImageExt<float>(m_parent,name,bpix,naxis,naxes,version);   
                break; 
      case DOUBLE_IMG:
                newImage =  new ImageExt<double>(m_parent,name,bpix,naxis,naxes,version);   
                break; 
      case USHORT_IMG:
                newImage =  
                        new ImageExt<unsigned short>(m_parent,name,bpix,naxis,naxes,version);
                newImage->bitpix(SHORT_IMG);
                newImage->zero(USBASE);
                break; 
      case ULONG_IMG:
                newImage =  
                        new ImageExt<unsigned long>(m_parent,name,bpix,naxis,naxes,version);  
                newImage->bitpix(LONG_IMG);
                newImage->zero(ULBASE); 
                break; 
      default:
              throw HDU::InvalidImageDataType("FitsError: invalid data type for FITS I/O");
  } 
  return newImage;
  }

  void HDUCreator::getScaling (long& type, double& zero, double& scale) const
  {
    float tmpScale(1.);
    float zval (0);
    int status (0);
    bool scalePresent = !fits_read_key_flt(m_parent->fptr(),BSCALE,&tmpScale,0,&status);
    // if there is no BSCALE key present or BSCALE == 1 ... 
    if (!scalePresent || scalePresent &&  tmpScale == 1)
    {
         if (scalePresent) scale = tmpScale;
         if ( !fits_read_key_flt(m_parent->fptr(),BZERO,&zval,0,&status))
         {
                 switch (type)
                 {
                         case SHORT_IMG:
                                 if (zval == USBASE)  zero = USBASE;  // 2^15
                                 break;
                         case LONG_IMG:
                                 if (zval == ULBASE)  zero = ULBASE;  // 2^31
                                 break;
                         default:
                                 break;
                 }        
         }       
    }
    else // scale present and tmpScale != 1.
    {
            switch (type)
            {
                case BYTE_IMG:
                case SHORT_IMG:
                        type = FLOAT_IMG;
                        break;
                case LONG_IMG:
                        type = DOUBLE_IMG;
                        break;   
                default:
                        break; // do nothing.    
            }
    }                
  }

  // Additional Declarations

} // namespace CCfits

