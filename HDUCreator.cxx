
//	This is CCfits version 1.0-beta release August 2001

//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov



#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_STRSTREAM
#include <strstream>
#else
#include <sstream>
#endif


// ExtHDU
#include "ExtHDU.h"
// PHDU
#include "PHDU.h"
// HDU
#include "HDU.h"
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
// FitsError
#include "FitsError.h"
// FITSBase
#include "FITSBase.h"





namespace CCfits {

  // Class CCfits::HDUCreator 



  HDUCreator::HDUCreator (FITSBase* p)
  : m_hdu(0), m_parent(p) 
  {
  }


  HDUCreator::~HDUCreator()
  {
  }



  PHDU * HDUCreator::createImage (int bitpix, long naxis, const std::vector<long>& naxes) throw (FitsException&)
  {
    return MakeImage(bitpix,naxis,naxes);
  }

  PHDU * HDUCreator::MakeImage (int bpix, int naxis, const std::vector<long>& naxes) throw (FitsException&)
  {
          m_hdu = m_parent->pHDU();
          if (!m_hdu) 
          {
                  switch (bpix)
                  {
                      case BYTE_IMG:
                              return new PrimaryHDU<unsigned char>(m_parent,bpix,naxis,naxes);
                              break;   
                      case SHORT_IMG:
                              return new PrimaryHDU<short>(m_parent,bpix,naxis,naxes);
                              break;
                      case LONG_IMG:
                              return new PrimaryHDU<long>(m_parent,bpix,naxis,naxes);
                              break;
                      case FLOAT_IMG:
                              return new PrimaryHDU<float>(m_parent,bpix,naxis,naxes);
                              break;
                      case DOUBLE_IMG:
                              return new PrimaryHDU<double>(m_parent,bpix,naxis,naxes);
                              break;
                      case USHORT_IMG:
                              return  new PrimaryHDU<unsigned short>(m_parent,bpix,naxis,naxes);
                              break;
                      case ULONG_IMG:
                              return  new PrimaryHDU<unsigned long>(m_parent,bpix,naxis,naxes);
                              break;
                      default:
                              throw HDU::InvalidImageDataType("FitsError: invalid data type for FITS I/O");
                  } 
          }  
          else return static_cast<PHDU*>(m_hdu);   
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
    switch(xtype)
    {
    case ImageHdu:
            // ImageHDU types are templated
            switch (bpix)
            {
                    case BYTE_IMG:
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
                    case SHORT_IMG:
                            if (primary) 
                            {
                                    if (!m_hdu) m_hdu = 
                                          new PrimaryHDU<short>(m_parent,readDataFlag,keys);
                            }
                            else
                            {
                                    m_hdu = new ImageExt<short>
                                            (m_parent,hduName,readDataFlag,keys,version);   
                            }
			    break;
                    case LONG_IMG:
                            if (primary) 
                            {
                                    if (!m_hdu) m_hdu = 
                                          new PrimaryHDU<long>(m_parent,readDataFlag,keys);
                            }
                            else
                            {
                                    m_hdu = new ImageExt<long>
                                                (m_parent,hduName,readDataFlag,keys,version);   
                            }
                            break;
                    case FLOAT_IMG:
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
                    case DOUBLE_IMG:
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
                    case USHORT_IMG:
                            if (primary) 
                            {
                                    if (!m_hdu) m_hdu = 
                                          new PrimaryHDU<unsigned short>
                                                (m_parent,readDataFlag,keys);
                            }
                            else
                            {
                                    m_hdu = new ImageExt<unsigned short>
                                            (m_parent,hduName,readDataFlag,keys,version);   
                            }
                            break;
                    case ULONG_IMG:
                            if (primary) 
                            {
                                    if (!m_hdu) m_hdu = 
                                          new PrimaryHDU<unsigned long>
                                                (m_parent,readDataFlag,keys);
                            }
                            else
                            {
                                    m_hdu = new ImageExt<unsigned long>
                                            (m_parent,hduName,readDataFlag,keys,version);   
                            }
                            break;
                    default:
                            throw HDU::InvalidImageDataType("FitsError: invalid data type for FITS I/O");
			    break;
            }    
	    break;
    case AsciiTbl:
	    m_hdu = new AsciiTable(m_parent, hduName, readDataFlag, keys, version);
	    break;

    case BinaryTbl:
	    m_hdu = new BinTable(m_parent, hduName, readDataFlag, keys, version);
	    break;

    default:
                throw HDU::InvalidImageDataType("FitsError: invalid data type for FITS I/O");
                break;   
    }
    return m_hdu;
  }

  HDU* HDUCreator::MakeTable (const string &name, HduType xtype, int rows, const std::vector<ValueType>& colType, const std::vector<string>& colName, const std::vector<string>& colFmt, const std::vector<string>& colUnit, int version) throw (FitsException&)
  {
  switch (xtype)
  {
        case AsciiTbl:
                m_hdu = new AsciiTable(m_parent,name,rows,colType,colName,colFmt,colUnit,version); 
                break;
        case BinaryTbl:
                m_hdu = new BinTable(m_parent,name,rows,colType,colName,colFmt,colUnit,version);                 
                break;
        default:
                throw HDU::InvalidExtensionType("unexpected");
                break;   
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

  ExtHDU * HDUCreator::createImage (const string &name, int bitpix, long naxis, const std::vector<long>& naxes, int version) throw (FitsException&)
  {
        return MakeImage(name,bitpix,naxis,naxes,version);
  }

  ExtHDU * HDUCreator::MakeImage (const string &name, int bpix, long naxis, const std::vector<long>& naxes, int version) throw (FitsException&)
  {
  switch (bpix)
  {
      case BYTE_IMG:
                return new ImageExt<unsigned char>(m_parent,name,bpix,naxis,naxes,version);   
                break;   
      case SHORT_IMG:
                return new ImageExt<short>(m_parent,name,bpix,naxis,naxes,version);   
                break;
      case LONG_IMG:
                return new ImageExt<long>(m_parent,name,bpix,naxis,naxes,version);   
                break;
      case FLOAT_IMG:
                return new ImageExt<float>(m_parent,name,bpix,naxis,naxes,version);   
                break;
      case DOUBLE_IMG:
                return new ImageExt<double>(m_parent,name,bpix,naxis,naxes,version);   
                break;
      case USHORT_IMG:
                return new ImageExt<unsigned short>(m_parent,name,bpix,naxis,naxes,version);   
                break;
      case ULONG_IMG:
                return new ImageExt<unsigned long>(m_parent,name,bpix,naxis,naxes,version);   
                break;
      default:
              throw HDU::InvalidImageDataType("FitsError: invalid data type for FITS I/O");
  } 
  }

  // Additional Declarations

} // namespace CCfits

