//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%38034DE30348.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%38034DE30348.cm

//## begin module%38034DE30348.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%38034DE30348.cp

//## Module: HDU%38034DE30348; Package body
//## Subsystem: CCfits::HDU%3826DF628F48
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/HDU.cxx

//## begin module%38034DE30348.additionalIncludes preserve=no
//## end module%38034DE30348.additionalIncludes

//## begin module%38034DE30348.includes preserve=yes

#ifdef _MSC_VER
#include "MSconfig.h" // for truncation warning
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef SSTREAM_DEFECT
#include <strstream>
#else
#include <sstream>
#endif

#include <memory>
//## end module%38034DE30348.includes

// FITS
#include "FITS.h"
// FITSBase
#include "FITSBase.h"
// HDU
#include "HDU.h"


//## begin module%38034DE30348.declarations preserve=no
//## end module%38034DE30348.declarations

//## begin module%38034DE30348.additionalDeclarations preserve=yes
#include "FITSUtil.h"
#include <functional>
//## end module%38034DE30348.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  // Class CCfits::HDU::InvalidImageDataType 

  HDU::InvalidImageDataType::InvalidImageDataType (const string& diag, bool silent)
    //## begin CCfits::HDU::InvalidImageDataType::InvalidImageDataType%39B54E68004D.hasinit preserve=yes
  : FitsException("Fits Error: Invalid Data Type for Image",silent)
    //## end CCfits::HDU::InvalidImageDataType::InvalidImageDataType%39B54E68004D.hasinit
    //## begin CCfits::HDU::InvalidImageDataType::InvalidImageDataType%39B54E68004D.initialization preserve=yes
    //## end CCfits::HDU::InvalidImageDataType::InvalidImageDataType%39B54E68004D.initialization
  {
    //## begin CCfits::HDU::InvalidImageDataType::InvalidImageDataType%39B54E68004D.body preserve=yes
  if (!silent) std::cerr << diag << '\n';
    //## end CCfits::HDU::InvalidImageDataType::InvalidImageDataType%39B54E68004D.body
  }


  // Class CCfits::HDU::InvalidExtensionType 

  HDU::InvalidExtensionType::InvalidExtensionType (const string& diag, bool silent)
    //## begin CCfits::HDU::InvalidExtensionType::InvalidExtensionType%39B54A7A008C.hasinit preserve=yes
  : FitsException
     ("Fits Error: Extension Type: ",
     silent)
    //## end CCfits::HDU::InvalidExtensionType::InvalidExtensionType%39B54A7A008C.hasinit
    //## begin CCfits::HDU::InvalidExtensionType::InvalidExtensionType%39B54A7A008C.initialization preserve=yes
    //## end CCfits::HDU::InvalidExtensionType::InvalidExtensionType%39B54A7A008C.initialization
  {
    //## begin CCfits::HDU::InvalidExtensionType::InvalidExtensionType%39B54A7A008C.body preserve=yes
        if (!silent) std::cerr << diag << '\n';
    //## end CCfits::HDU::InvalidExtensionType::InvalidExtensionType%39B54A7A008C.body
  }


  // Class CCfits::HDU::NoSuchKeyword 

  HDU::NoSuchKeyword::NoSuchKeyword (const string& diag, bool silent)
    //## begin CCfits::HDU::NoSuchKeyword::NoSuchKeyword%398862DD008E.hasinit preserve=yes
  : FitsException("Fits Error: Keyword not found: ",silent)
    //## end CCfits::HDU::NoSuchKeyword::NoSuchKeyword%398862DD008E.hasinit
    //## begin CCfits::HDU::NoSuchKeyword::NoSuchKeyword%398862DD008E.initialization preserve=yes
    //## end CCfits::HDU::NoSuchKeyword::NoSuchKeyword%398862DD008E.initialization
  {
    //## begin CCfits::HDU::NoSuchKeyword::NoSuchKeyword%398862DD008E.body preserve=yes
  if (!silent || FITS::verboseMode()) std::cerr << diag << '\n';
    //## end CCfits::HDU::NoSuchKeyword::NoSuchKeyword%398862DD008E.body
  }


  // Class CCfits::HDU::NoNullValue 

  HDU::NoNullValue::NoNullValue (const string& diag, bool silent)
    //## begin CCfits::HDU::NoNullValue::NoNullValue%3B0D581B039E.hasinit preserve=yes
    : FitsException("Fits Error: No Null Pixel Value specified for Image ",silent)
    //## end CCfits::HDU::NoNullValue::NoNullValue%3B0D581B039E.hasinit
    //## begin CCfits::HDU::NoNullValue::NoNullValue%3B0D581B039E.initialization preserve=yes
    //## end CCfits::HDU::NoNullValue::NoNullValue%3B0D581B039E.initialization
  {
    //## begin CCfits::HDU::NoNullValue::NoNullValue%3B0D581B039E.body preserve=yes
    if (!silent || FITS::verboseMode() ) std::cerr << diag << '\n';    
    //## end CCfits::HDU::NoNullValue::NoNullValue%3B0D581B039E.body
  }


  // Class CCfits::HDU 

  HDU::HDU(const HDU &right)
    //## begin HDU::HDU%38034D916A68_copy.hasinit preserve=yes
      : m_naxis(right.m_naxis),
        m_bitpix(right.m_bitpix),
        m_index(right.m_index),
        m_anynul(right.m_anynul),
        m_history(right.m_history),
        m_comment(right.m_comment),
        m_zero(right.m_zero),
        m_scale(right.m_scale),        
        m_keyWord(),
        m_parent(right.m_parent),
        m_naxes(right.m_naxes)
    //## end HDU::HDU%38034D916A68_copy.hasinit
    //## begin HDU::HDU%38034D916A68_copy.initialization preserve=yes
    //## end HDU::HDU%38034D916A68_copy.initialization
  {
    //## begin CCfits::HDU::HDU%38034D916A68_copy.body preserve=yes
   // ensure deep copy.
   copyKeys(right);
    //## end CCfits::HDU::HDU%38034D916A68_copy.body
  }

  HDU::HDU (FITSBase* p)
    //## begin CCfits::HDU::HDU%387F49C44258.hasinit preserve=yes
      : m_naxis(0),
        m_bitpix(8),
        m_index(0),
        m_anynul(false),
        m_history(""),
        m_comment(""),
        m_zero(0),
        m_scale(1.0),        
        m_keyWord(),
        m_parent(p),
        m_naxes()
    //## end CCfits::HDU::HDU%387F49C44258.hasinit
    //## begin CCfits::HDU::HDU%387F49C44258.initialization preserve=yes
    //## end CCfits::HDU::HDU%387F49C44258.initialization
  {
    //## begin CCfits::HDU::HDU%387F49C44258.body preserve=yes
   readHduInfo();  // read bitpix, naxis and naxes keywords 
   int hduIndex = 0;
   fits_get_hdu_num(fitsPointer(), &hduIndex);
   m_index = hduIndex - 1;
    //## end CCfits::HDU::HDU%387F49C44258.body
  }

  HDU::HDU (FITSBase* p, int bitpix, int naxis, const std::vector<long>& axes)
    //## begin CCfits::HDU::HDU%3803834F9260.hasinit preserve=yes
      : m_naxis(naxis),
        m_bitpix(bitpix),
        m_index(0),
        m_anynul(false),
        m_history(""),
        m_comment(""),
        m_zero(0),
        m_scale(1.0),        
        m_keyWord(),
        m_parent(p),
        m_naxes(axes)
    //## end CCfits::HDU::HDU%3803834F9260.hasinit
    //## begin CCfits::HDU::HDU%3803834F9260.initialization preserve=yes
    //## end CCfits::HDU::HDU%3803834F9260.initialization
  {
    //## begin CCfits::HDU::HDU%3803834F9260.body preserve=yes
    //## end CCfits::HDU::HDU%3803834F9260.body
  }


  HDU::~HDU()
  {
    //## begin CCfits::HDU::~HDU%38034D916A68_dest.body preserve=yes
  // garbage collection for heap allocated objects.
  clearKeys();
    //## end CCfits::HDU::~HDU%38034D916A68_dest.body
  }


  bool HDU::operator==(const HDU &right) const
  {
    //## begin CCfits::HDU::operator==%38034D916A68_eq.body preserve=yes
   return compare(right);
    //## end CCfits::HDU::operator==%38034D916A68_eq.body
  }

  bool HDU::operator!=(const HDU &right) const
  {
    //## begin CCfits::HDU::operator!=%38034D916A68_neq.body preserve=yes
  return !compare(right);
    //## end CCfits::HDU::operator!=%38034D916A68_neq.body
  }



  //## Other Operations (implementation)
  void HDU::clearKeys ()
  {
    //## begin CCfits::HDU::clearKeys%39522169007F.body preserve=yes
  for (std::map<String,Keyword*>::iterator key = m_keyWord.begin(); 
          key != m_keyWord.end(); ++key)
  {
        delete (*key).second;
  }
  
  m_keyWord.erase(m_keyWord.begin(),m_keyWord.end());
    //## end CCfits::HDU::clearKeys%39522169007F.body
  }

  void HDU::readHduInfo ()
  {
    //## begin CCfits::HDU::readHduInfo%388786291C20.body preserve=yes

  // Read BITPIX and NAXIS keywords 
  int status = 0;
  char* comment = 0;
  //string keyname("BITPIX");
  //
  //
  //if (fits_read_key_lng(fitsPointer(),const_cast<char*>(keyname.c_str()),&m_bitpix,comment,&status) )
  //    throw FitsError(status);
  
  String keyname = String("NAXIS");
    
  if (fits_read_key_lng(fitsPointer(),const_cast<char*>(keyname.c_str()),&m_naxis,comment,&status) )
      throw FitsError(status);
  
  // okay, we have the number of axes and therefore the number of values
  // NAXISn.
  
  
  FITSUtil::auto_array_ptr<long> axes(new long[m_naxis]);
  long* pAxes = axes.get();
  
  
  // create strings NAXIS1 - NAXISn, where n = NAXIS, and read keyword.
            
  for (int i=0; i <m_naxis; i++)
  {  
#ifdef SSTREAM_DEFECT
        std::ostrstream axisKey;
	axisKey << keyname << i+1 << std::ends;
        if (fits_read_key_lng(fitsPointer(),axisKey.str(),&pAxes[i],comment,&status) ) 
                throw FitsError(status);
#else
	std::ostringstream axisKey;
	axisKey << keyname << i+1;
        if (fits_read_key_lng(fitsPointer(),const_cast<char*>(axisKey.str().c_str()),
                                                                &pAxes[i],comment,&status) ) 
                throw FitsError(status);
#endif
  }

 
  std::copy(&pAxes[0],&pAxes[m_naxis], std::back_inserter(m_naxes));

    //## end CCfits::HDU::readHduInfo%388786291C20.body
  }

  Keyword& HDU::readKeyword (const String &keyname)
  {
    //## begin CCfits::HDU::readKeyword%38CE6054A2C0.body preserve=yes

  try       
  {
  	using std::pair;  
        Keyword* newKey(KeywordCreator::getKeyword(keyname,this));
        std::map<String,Keyword*>::value_type refToEntry(keyname,newKey);
        m_keyWord.insert(refToEntry);
  	return *(refToEntry.second);
  
  }
  catch (FitsError)
  {     
        throw NoSuchKeyword(keyname);
  }  
  
    //## end CCfits::HDU::readKeyword%38CE6054A2C0.body
  }

  void HDU::readKeywords (std::list<String>& keynames)
  {
    //## begin CCfits::HDU::readKeywords%38CE62D8D050.body preserve=yes
  // the scoop is: this and the previous function - which reads
  // a single key - are designed to be called by HDU and its subclasses
  // in constructors etc., and by the public member functions
  // addKey<T>, readKey<T> and readKeys<T>. These functions read keywords
  // and either return nothing or return Keyword references from which another
  // function call is necessary to retrieve the value. These are both things
  // that implementers need but are not necessary to provide for the user.
  std::list<String>::iterator ikey = keynames.begin();
  while ( ikey != keynames.end())
  {
     try
     {
        readKeyword(*ikey);
	++ikey;
     }
     catch (NoSuchKeyword)
     {
        ikey = keynames.erase(ikey);
     }
  }
  
  

    //## end CCfits::HDU::readKeywords%38CE62D8D050.body
  }

  Keyword* HDU::addKeyword (Keyword* newKey)
  {
    //## begin CCfits::HDU::addKeyword%397EFAA40263.body preserve=yes
  	using std::pair;
  	newKey->write();
        const String& keyname = newKey->name(); 
        std::map<String,Keyword*>::value_type refToEntry(keyname,newKey);
        m_keyWord.insert(refToEntry);
  	return refToEntry.second;
    //## end CCfits::HDU::addKeyword%397EFAA40263.body
  }

  bool HDU::compare (const HDU &right) const
  {
    //## begin CCfits::HDU::compare%380376C81C50.body preserve=yes
    if (fitsPointer() != right.fitsPointer()) return false;
    if (m_index != right.m_index) return false;
    return true;
    //## end CCfits::HDU::compare%380376C81C50.body
  }

  fitsfile* HDU::fitsPointer () const
  {
    //## begin CCfits::HDU::fitsPointer%3937DEB20035.body preserve=yes
    //## end CCfits::HDU::fitsPointer%3937DEB20035.body

    return m_parent->fptr();
  }

  void HDU::makeThisCurrent () const
  {
    //## begin CCfits::HDU::makeThisCurrent%393FEAFD009B.body preserve=yes
  int status = 0;
  int hduType = 0;
  // m_index contains the value of fptr->Fptr->curhdu. movabs_hdu moves to
  // 1 - this unless it's at the beginning, so it must be m_index+1 [Check!!!]
  if (fits_movabs_hdu(fitsPointer(),m_index+1, &hduType, &status) != 0) throw FitsError(status);
  m_parent->currentExtensionName()  = "";
    //## end CCfits::HDU::makeThisCurrent%393FEAFD009B.body
  }

  void HDU::copyKeys (const HDU& right)
  {
    //## begin CCfits::HDU::copyKeys%395221E50097.body preserve=yes
    // copy all keys that have already been read.
  for (std::map<String,Keyword*>::const_iterator key = right.m_keyWord.begin(); 
          key != right.m_keyWord.end(); key++)
  {
        m_keyWord[(*key).first] = ((*key).second)->clone();
  }
    //## end CCfits::HDU::copyKeys%395221E50097.body
  }

  String HDU::getNamedLines (const String& name)
  {
    //## begin CCfits::HDU::getNamedLines%39AFB2DD038E.body preserve=yes
  int fitsStatus = 0;
  int numKeys = 0;
  static char searchKey[FLEN_KEYWORD];

  makeThisCurrent();
        
  
  String content("");
  char* card = new char[81];
  FITSUtil::auto_array_ptr<char> pcard(card);
  int where = 1;
  int keylen = 0;

  fits_get_hdrpos(fitsPointer(),&numKeys,&where,&fitsStatus);
  if (fitsStatus != 0 ) throw FitsError(fitsStatus,false);

  // search through the header to get the first "name" keyword.
  while ( where < numKeys )
  {
        fits_read_record(fitsPointer(),++where,card,&fitsStatus);
	fits_get_keyname(card,searchKey,&keylen,&fitsStatus);
	// on FitsError, always print a message (!silent).
	if (fitsStatus != 0 ) throw FitsError(fitsStatus,false);
	// require exact match
        if (strcmp(name.c_str(),searchKey) == 0) 
        {
        	// this should work for standard compliant
        	// string implementation, where the length added
        	// to content is determined by traits::length()
                content += card + 8;
                content += "\n";  
        }
  }

  // print a message if there are no "name" type records.
  if (content.size() == 0) throw NoSuchKeyword(name);
  
  
  
          
  return content; 
    //## end CCfits::HDU::getNamedLines%39AFB2DD038E.body
  }

  const String& HDU::getHistory ()
  {
    //## begin CCfits::HDU::getHistory%39AFB37D01F3.body preserve=yes
  
  try
  {
          m_history = getNamedLines("HISTORY");
  }
  catch (HDU::NoSuchKeyword) {}
  catch (FitsError) {}
  catch (...) { throw; }
  return m_history;
    //## end CCfits::HDU::getHistory%39AFB37D01F3.body
  }

  const String& HDU::getComments ()
  {
    //## begin CCfits::HDU::getComments%39AFB38400DA.body preserve=yes
  try
  {
          m_comment = getNamedLines("COMMENT");
  }
  catch (HDU::NoSuchKeyword) {}
  catch (FitsError) {}
  catch (...) { throw; }
  return m_comment;
    //## end CCfits::HDU::getComments%39AFB38400DA.body
  }

  void HDU::writeHistory (const String& history)
  {
    //## begin CCfits::HDU::writeHistory%3B33A2C302AA.body preserve=yes
    int status(0);
    makeThisCurrent();
    if (fits_write_history(fitsPointer(),const_cast<char*>(history.c_str()),&status))
                throw FitsError(status);
    m_history = history;             
    //## end CCfits::HDU::writeHistory%3B33A2C302AA.body
  }

  void HDU::writeComment (const String& comment)
  {
    //## begin CCfits::HDU::writeComment%3B33A36D022C.body preserve=yes
    int status(0);
    makeThisCurrent();
    if (fits_write_comment(fitsPointer(),const_cast<char*>(comment.c_str()),&status))
                throw FitsError(status);

    m_comment = comment;             
    //## end CCfits::HDU::writeComment%3B33A36D022C.body
  }

  void HDU::writeDate ()
  {
    //## begin CCfits::HDU::writeDate%3B33A43F0164.body preserve=yes
    static const String DATE("DATE");
    int status(0);
    makeThisCurrent();
    if (fits_write_date(fitsPointer(),&status)) throw FitsError(status);
    FITSUtil::auto_array_ptr<char> pDate(new char[FLEN_KEYWORD]);
    FITSUtil::auto_array_ptr<char> pDateComment(new char[FLEN_COMMENT]);
    char* date = pDate.get();
    if (fits_read_key_str(fitsPointer(),
        const_cast<char*>(DATE.c_str()),date,pDateComment.get(),&status))   throw FitsError(status);
    NewKeyword<String> creator(this,pDate.release());
    Keyword* newKey = creator.MakeKeyword(DATE,String(pDateComment.release()));
    m_keyWord[DATE] = newKey;               

    
    //## end CCfits::HDU::writeDate%3B33A43F0164.body
  }

  FITSBase* HDU::parent () const
  {
    //## begin CCfits::HDU::parent%3B38956B00A3.body preserve=yes
    //## end CCfits::HDU::parent%3B38956B00A3.body

    return m_parent;
  }

  void HDU::readAllKeys ()
  {
    //## begin CCfits::HDU::readAllKeys%3B4B248200A1.body preserve=yes
    makeThisCurrent();
    int status(0);
    int n (0);
    int dum(0);
    if (fits_get_hdrpos(fitsPointer(),&n,&dum,&status)) throw FitsError(status);
    
    for (int j = 1; j <= n; ++j)
    {
            // get keywords by header position and store all the keys that
            // are neither metadata for columns nor history/comment cards.
            std::auto_ptr<Keyword> key(KeywordCreator::getKeyword(j,this));
            // comment/history cards have no value field and return 0 here.
            if (key.get() != 0)
            {
                int keyClass = fits_get_keyclass(const_cast<char*>(key->name().c_str()));
                if ( (keyClass == TYP_USER_KEY  ) ||
                        (keyClass == TYP_WCS_KEY   ) ||
                        (keyClass == TYP_CMPRS_KEY ) ||
                        (keyClass == TYP_CKSUM_KEY ) ||
                        (keyClass == TYP_REFSYS_KEY) )
                {
                        saveReadKeyword(key.get());
                }  
            }       
    }
                
    getHistory();
    getComments();
          
    //## end CCfits::HDU::readAllKeys%3B4B248200A1.body
  }

  void HDU::deleteKey (const String& doomed)
  {
    //## begin CCfits::HDU::deleteKey%3B66F7E501AF.body preserve=yes
    Keyword& k = keyWord(doomed); //throws no such keyword if there isn't.
    int status(0);
    if (fits_delete_key(fitsPointer(),const_cast<char*>(k.name().c_str()),&status)) throw FitsError(status);
    std::map<String,Keyword*>::iterator ki(m_keyWord.find(doomed));
    delete (*ki).second;
    m_keyWord.erase(ki);
    //## end CCfits::HDU::deleteKey%3B66F7E501AF.body
  }

  // Additional Declarations
    //## begin CCfits::HDU%38034D916A68.declarations preserve=yes
    Keyword& HDU::addKey(const string& name, const char* charString, const string& comment)
    {
        return addKey(name,String(charString),comment);      
    }
    //## end CCfits::HDU%38034D916A68.declarations
} // namespace CCfits

//## begin module%38034DE30348.epilog preserve=yes
//## end module%38034DE30348.epilog
