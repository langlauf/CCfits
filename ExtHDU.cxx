//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%380397F2A068.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%380397F2A068.cm

//## begin module%380397F2A068.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%380397F2A068.cp

//## Module: ExtHDU%380397F2A068; Package body
//## Subsystem: CCfits::HDU%3826DF628F48
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/ExtHDU.cxx

//## begin module%380397F2A068.additionalIncludes preserve=no
//## end module%380397F2A068.additionalIncludes

//## begin module%380397F2A068.includes preserve=yes
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
#endif

//## end module%380397F2A068.includes

// Column
#include "Column.h"
// FITS
#include "FITS.h"
// FITSBase
#include "FITSBase.h"
// ExtHDU
#include "ExtHDU.h"
// FitsError
#include "FitsError.h"
// FITSUtil
#include "FITSUtil.h"


//## begin module%380397F2A068.declarations preserve=no
//## end module%380397F2A068.declarations

//## begin module%380397F2A068.additionalDeclarations preserve=yes
//## end module%380397F2A068.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  // Class CCfits::ExtHDU::WrongExtensionType 

  ExtHDU::WrongExtensionType::WrongExtensionType (const String& msg, bool silent)
    //## begin CCfits::ExtHDU::WrongExtensionType::WrongExtensionType%39E61D960161.hasinit preserve=yes
  : FitsException("Fits Error: wrong extension type: ",silent)
    //## end CCfits::ExtHDU::WrongExtensionType::WrongExtensionType%39E61D960161.hasinit
    //## begin CCfits::ExtHDU::WrongExtensionType::WrongExtensionType%39E61D960161.initialization preserve=yes
    //## end CCfits::ExtHDU::WrongExtensionType::WrongExtensionType%39E61D960161.initialization
  {
    //## begin CCfits::ExtHDU::WrongExtensionType::WrongExtensionType%39E61D960161.body preserve=yes
  std::cerr << msg << '\n'; 
    //## end CCfits::ExtHDU::WrongExtensionType::WrongExtensionType%39E61D960161.body
  }


  // Class CCfits::ExtHDU 

  //## begin CCfits::ExtHDU::missHDU%3AFC4D0D00E4.attr preserve=no  public: static String {V} "$HDU$"
  String ExtHDU::s_missHDU = "$HDU$";
  //## end CCfits::ExtHDU::missHDU%3AFC4D0D00E4.attr

  ExtHDU::ExtHDU(const ExtHDU &right)
    //## begin ExtHDU::ExtHDU%380481E172B0_copy.hasinit preserve=yes
      : HDU(right),
	m_pcount(right.m_pcount),
	m_gcount(right.m_gcount),
	m_version(right.m_version),
	m_xtension(right.m_xtension),
	m_name(right.m_name)
    //## end ExtHDU::ExtHDU%380481E172B0_copy.hasinit
    //## begin ExtHDU::ExtHDU%380481E172B0_copy.initialization preserve=yes
    //## end ExtHDU::ExtHDU%380481E172B0_copy.initialization
  {
    //## begin CCfits::ExtHDU::ExtHDU%380481E172B0_copy.body preserve=yes
    //## end CCfits::ExtHDU::ExtHDU%380481E172B0_copy.body
  }

  ExtHDU::ExtHDU (FITSBase* p, HduType xtype, const String &hduName, int version)
    //## begin CCfits::ExtHDU::ExtHDU%3846987DA210.hasinit preserve=yes
      : HDU(p),
	m_pcount(0),
	m_gcount(1),
        m_version(version),
        m_xtension(xtype),
        m_name(hduName)
    //## end CCfits::ExtHDU::ExtHDU%3846987DA210.hasinit
    //## begin CCfits::ExtHDU::ExtHDU%3846987DA210.initialization preserve=yes
    //## end CCfits::ExtHDU::ExtHDU%3846987DA210.initialization
  {
    //## begin CCfits::ExtHDU::ExtHDU%3846987DA210.body preserve=yes
  int status = 0;
  int htype = xtype;
  int number = -1;
    
  
  if ( hduName.substr(0,5) == s_missHDU ) 
  {
#ifdef SSTREAM_DEFECT
    std::istrstream fakeName( hduName.substr(5).c_str() );
#else
        std::istringstream fakeName(hduName.substr(5));
#endif
        fakeName  >> number;   
        if (fits_movabs_hdu(fitsPointer(),number+1,&htype,&status) != 0) throw FitsError(status);
  }
  else
  {
        // move to the appropriate HDU and throw if it doesn't exist.
        if (fits_movnam_hdu(fitsPointer(),htype,const_cast<char*>(hduName.c_str()),
                        version,&status)) 
        {
#ifdef SSTREAM_DEFECT
	        ostrstream msg;
#else
		std::ostringstream msg;
#endif
		msg << "Can't access  HDU named " << hduName << " in file " 
                          << fitsPointer()->Fptr->filename << '\n';
#ifdef SSTREAM_DEFECT
	        msg << std::ends;
#endif
                
		throw FITS::NoSuchHDU(msg.str());
	}
        fits_get_hdu_num(fitsPointer(),&number);
        // Retrieve the HDU number. checkXtension tests against this.
        index(number-1);
  }
        
  
  
  
  // check we got the right kind of extension, since otherwise
  // we cannot proceed. CheckXtension throws an exception if
  // not, which is caught by the concrete class ctors.
  checkXtension();
  
    //## end CCfits::ExtHDU::ExtHDU%3846987DA210.body
  }

  ExtHDU::ExtHDU (FITSBase* p, HduType xtype, const String &hduName, int bitpix, int naxis, const std::vector<long>& axes, int version)
    //## begin CCfits::ExtHDU::ExtHDU%3805D2960BC8.hasinit preserve=yes
      : HDU(p, bitpix, naxis, axes),
   	m_pcount(0),
	m_gcount(1),
        m_version(version),
	m_xtension(xtype), 
        m_name(hduName)
    //## end CCfits::ExtHDU::ExtHDU%3805D2960BC8.hasinit
    //## begin CCfits::ExtHDU::ExtHDU%3805D2960BC8.initialization preserve=yes
    //## end CCfits::ExtHDU::ExtHDU%3805D2960BC8.initialization
  {
    //## begin CCfits::ExtHDU::ExtHDU%3805D2960BC8.body preserve=yes
  // writing constructor. Extension must be supplied
  // since we must know what type of object to instantiate.
    //## end CCfits::ExtHDU::ExtHDU%3805D2960BC8.body
  }

  ExtHDU::ExtHDU (FITSBase* p, HduType xtype, int number)
    //## begin CCfits::ExtHDU::ExtHDU%395116540257.hasinit preserve=yes
      : HDU(p), 
        m_pcount(0),
        m_gcount(1),
        m_version(1),
        m_xtension(xtype),
        m_name("")
    //## end CCfits::ExtHDU::ExtHDU%395116540257.hasinit
    //## begin CCfits::ExtHDU::ExtHDU%395116540257.initialization preserve=yes
    //## end CCfits::ExtHDU::ExtHDU%395116540257.initialization
  {
    //## begin CCfits::ExtHDU::ExtHDU%395116540257.body preserve=yes
  // set current HDU number. This is required for makeThisCurrent.
  
  index(number+1);
  makeThisCurrent();
  // set name and version.
  readHduName(fitsPointer(),number,m_name,m_version);
  // finally, check we got the right type of extension and throw an
  // exception otherwise.
  checkXtension();
    //## end CCfits::ExtHDU::ExtHDU%395116540257.body
  }


  ExtHDU::~ExtHDU()
  {
    //## begin CCfits::ExtHDU::~ExtHDU%380481E172B0_dest.body preserve=yes
    //## end CCfits::ExtHDU::~ExtHDU%380481E172B0_dest.body
  }



  //## Other Operations (implementation)
  void ExtHDU::checkXtension ()
  {
    //## begin CCfits::ExtHDU::checkXtension%38D14FAB5EB8.body preserve=yes
  int   status=0;
  int hType = -1;
  
  if (fits_get_hdu_type(fitsPointer(),  &hType,  &status) ) throw FitsError(status);
  
  if (HduType(hType) != m_xtension) 
          throw HDU::InvalidExtensionType
            (" extension type mismatch between request and disk file ",true);
    //## end CCfits::ExtHDU::checkXtension%38D14FAB5EB8.body
  }

  void ExtHDU::readHduName (const fitsfile* fptr, int hduIndex, String& hduName, int& hduVersion)
  {
    //## begin CCfits::ExtHDU::readHduName%394E89D202AE.body preserve=yes
   
   // get the name of the extension. If there is neither a HDUNAME
   // or an EXTNAME, make a name key for the multimap from the HDU number.
    
   int   status=0;
   FITSUtil::auto_array_ptr<char> pHduCstr(new char[FLEN_KEYWORD]);
   char* hduCstr = pHduCstr.get();
   int htype = -1;
   
   String key = "EXTNAME";
   char* extnm = const_cast<char*>(key.c_str());
   
   // C requires fptr to be non-const, because the fitsfile pointer 
   // saves the file state.
   fitsfile* cfptr = const_cast<fitsfile*>(fptr);
   
   if (fits_movabs_hdu(cfptr,hduIndex+1,&htype,&status) != 0) throw FitsError(status);
   
   
   status = fits_read_key_str(cfptr,  extnm, hduCstr, NULL, &status);
   if (status != 0)
   {
      strcpy(hduCstr,"");
      status = 0;
      key = String("HDUNAME");
      extnm = const_cast<char*>(key.c_str());
      status = fits_read_key_str(cfptr,  extnm, hduCstr, NULL, &status);
   }


   
   if (strlen(hduCstr) > 0) 
   {
        hduName = String(hduCstr);
        long hduV = 1;
        hduVersion = hduV;
        // get the version number.
        key = String("EXTVER");
        char* extv = const_cast<char*>(key.c_str());
        status = fits_read_key_lng(cfptr, extv, &hduV, NULL, &status);
        if (status == 0) hduVersion = hduV;
   }
   else
   {
#ifdef SSTREAM_DEFECT
       std::ostrstream fakeKey;       
#else
       std::ostringstream fakeKey;       
#endif
       fakeKey << s_missHDU << hduIndex;
#ifdef SSTREAM_DEFECT
       msg << std::ends;
#endif
       
       hduName = fakeKey.str();
   }
   
    //## end CCfits::ExtHDU::readHduName%394E89D202AE.body
  }

  void ExtHDU::makeThisCurrent () const
  {
    //## begin CCfits::ExtHDU::makeThisCurrent%39CA57850315.body preserve=yes
  HDU::makeThisCurrent();
  String tname("");
  int tvers = 0;
  ExtHDU::readHduName(fitsPointer(),index(),tname,tvers);
  parent()->currentExtensionName() = tname;       
    //## end CCfits::ExtHDU::makeThisCurrent%39CA57850315.body
  }

  Column& ExtHDU::column (const String& colName) const
  {
    //## begin CCfits::ExtHDU::column%39E61E7901A6.body preserve=yes
  // if not overridden, throw an exception.
  // there might be a similar default implementation for function
  // that returns image data.
  throw WrongExtensionType(name());
    //## end CCfits::ExtHDU::column%39E61E7901A6.body
  }

  void ExtHDU::column (const String& colname, Column* value)
  {
    //## begin CCfits::ExtHDU::column%39E620F802DE.body preserve=yes
  throw WrongExtensionType(name());
    //## end CCfits::ExtHDU::column%39E620F802DE.body
  }

  Column& ExtHDU::column (int colIndex) const
  {
    //## begin CCfits::ExtHDU::column%39EDABAA0283.body preserve=yes
  throw WrongExtensionType(name());
    //## end CCfits::ExtHDU::column%39EDABAA0283.body
  }

  long ExtHDU::rows () const
  {
    //## begin CCfits::ExtHDU::rows%3B0034DC031E.body preserve=yes
    String msg(" rows function can only be called for Tables - HDU: ");
    msg += name();
    throw WrongExtensionType(msg);
    //## end CCfits::ExtHDU::rows%3B0034DC031E.body
  }

  void ExtHDU::checkExtensionType () const
  {
    // throw if not overridden.
    throw WrongExtensionType(name());

    //## begin CCfits::ExtHDU::checkExtensionType%3B045BEC0213.body preserve=yes
    //## end CCfits::ExtHDU::checkExtensionType%3B045BEC0213.body
  }

  void ExtHDU::addColumn (ValueType type, const String& columnName, long repeatWidth, const String& colUnit, long decimals, size_t columnNumber)
  {
    //## begin CCfits::ExtHDU::addColumn%3B0AB73900AB.body preserve=yes
    // overridden separately in AsciiTable and BinTable
    throw WrongExtensionType(name());

         
    //## end CCfits::ExtHDU::addColumn%3B0AB73900AB.body
  }

  void ExtHDU::deleteColumn (const String& columnName)
  {
    //## begin CCfits::ExtHDU::deleteColumn%3B0AB77801E0.body preserve=yes
    // overridden in Table.
    throw WrongExtensionType(name());

    //## end CCfits::ExtHDU::deleteColumn%3B0AB77801E0.body
  }

  int ExtHDU::getVersion ()
  {
    //## begin CCfits::ExtHDU::getVersion%3B38EDCD0324.body preserve=yes
    // the version keyword is not stored as a keyword object but
    // as a data attribute so we don't "addKeyword" but fits_read_key instead.
    static char EXTVER[] = {"EXTVER"};
    int status(0);
    long vers(1);
    fits_read_key_lng(fitsPointer(),EXTVER,&vers,0,&status);
    if (status == 0)
    {
        m_version = vers;
    }
    else
    {
        if (status == KEY_NO_EXIST) 
        {
                m_version = 1;
        }
        else throw FitsError(status);
        
    }
    return m_version;
    //## end CCfits::ExtHDU::getVersion%3B38EDCD0324.body
  }

  // Additional Declarations
    //## begin CCfits::ExtHDU%380481E172B0.declarations preserve=yes
    //## end CCfits::ExtHDU%380481E172B0.declarations

} // namespace CCfits

//## begin module%380397F2A068.epilog preserve=yes
//## end module%380397F2A068.epilog
