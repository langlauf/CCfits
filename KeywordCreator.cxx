//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%38171AF72688.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%38171AF72688.cm

//## begin module%38171AF72688.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%38171AF72688.cp

//## Module: KeywordCreator%38171AF72688; Package body
//## Subsystem: CCfits::Keyword%3826DF71D818
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/KeywordCreator.cxx

//## begin module%38171AF72688.additionalIncludes preserve=no
//## end module%38171AF72688.additionalIncludes

//## begin module%38171AF72688.includes preserve=yes

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

//## end module%38171AF72688.includes

// HDU
#include "HDU.h"
// KeywordCreator
#include "KeywordCreator.h"
//## begin module%38171AF72688.declarations preserve=no
//## end module%38171AF72688.declarations

//## begin module%38171AF72688.additionalDeclarations preserve=yes
//#include "HDU.h"
using std::cout;
using std::endl;
//## end module%38171AF72688.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  // Class CCfits::KeywordCreator 

  KeywordCreator::KeywordCreator (HDU* p)
    //## begin CCfits::KeywordCreator::KeywordCreator%397F059803DA.hasinit preserve=yes
      : m_keyword(0), m_forHDU(p)
    //## end CCfits::KeywordCreator::KeywordCreator%397F059803DA.hasinit
    //## begin CCfits::KeywordCreator::KeywordCreator%397F059803DA.initialization preserve=yes
    //## end CCfits::KeywordCreator::KeywordCreator%397F059803DA.initialization
  {
    //## begin CCfits::KeywordCreator::KeywordCreator%397F059803DA.body preserve=yes
    //## end CCfits::KeywordCreator::KeywordCreator%397F059803DA.body
  }


  KeywordCreator::~KeywordCreator()
  {
    //## begin CCfits::KeywordCreator::~KeywordCreator%38171AE53AD8_dest.body preserve=yes
    //## end CCfits::KeywordCreator::~KeywordCreator%38171AE53AD8_dest.body
  }



  //## Other Operations (implementation)
  Keyword* KeywordCreator::getKeyword (const String& keyName, HDU* p)
  {
    //## begin CCfits::KeywordCreator::getKeyword%3935740F00A2.body preserve=yes
   int     status=0;
   FITSUtil::auto_array_ptr<char> pCard(new char[FLEN_CARD]);
   FITSUtil::auto_array_ptr<char> pV(new char[FLEN_VALUE]);
   FITSUtil::auto_array_ptr<char> pCom(new char[FLEN_COMMENT]);
   char* card = pCard.get();
   char* v = pV.get();
   char* com = pCom.get();

   if (fits_read_card(p->fitsPointer(), const_cast<char*>(keyName.c_str()), card,&status) ) 
           throw FitsError(status);

   if (fits_parse_value(card, v, com, &status))  
           throw FitsError(status);
   
   String valString(v);
   if (KeywordCreator::isContinued(valString))
   {
      bool restoreQuote = valString[0] == '\'';
      KeywordCreator::getLongValueString(p, keyName, valString);
      if (restoreQuote)
      {
         valString = '\'' + valString + '\'';
      }
   }
   
   return parseRecord(keyName,valString,String(com),p);

    //## end CCfits::KeywordCreator::getKeyword%3935740F00A2.body
  }

  Keyword* KeywordCreator::createKeyword (const String& keyName, const String& comment)
  {
    //## begin CCfits::KeywordCreator::createKeyword%39411F6D03D7.body preserve=yes
  if (m_keyword == 0) m_keyword = MakeKeyword(keyName,comment);
  return m_keyword;
    //## end CCfits::KeywordCreator::createKeyword%39411F6D03D7.body
  }

  Keyword* KeywordCreator::getKeyword (const String& keyName, ValueType keyType, HDU* p)
  {
    //## begin CCfits::KeywordCreator::getKeyword%39414CC202F1.body preserve=yes
   int status = 0;
   String val = "";
   bool bvalue = 0;
   float fvalue = 0;
   double dvalue = 0;
   std::complex<float> xvalue;
   std::complex<double> zvalue;
   int ivalue = 0;
   unsigned int uvalue = 0;
   short isvalue = 0;
   unsigned short usvalue = 0;
   long ilvalue = 0;
   unsigned long ulvalue = 0;
   unsigned char byteVal = 0;

   FITSUtil::auto_array_ptr<char> pCard(new char[FLEN_CARD]);
   FITSUtil::auto_array_ptr<char> pV(new char[FLEN_VALUE]);
   FITSUtil::auto_array_ptr<char> pCom(new char[FLEN_COMMENT]);
   char* card = pCard.get();
   char* v = pV.get();
   char* com = pCom.get();
   Keyword* readKey = 0;

   if (fits_read_card(p->fitsPointer(), const_cast<char*>(keyName.c_str()), card,&status) ) 
           throw FitsError(status);

   if (fits_parse_value(card, v, com, &status))  throw FitsError(status);

   
   String value(v);
   String comment(com);
 
   if (KeywordCreator::isContinued(value))
   {
      bool restoreQuote = value[0] == '\'';
      KeywordCreator::getLongValueString(p, keyName, value);
      if (restoreQuote)
      {
         value = '\'' + value + '\'';
      }
   }
 
#ifdef SSTREAM_DEFECT
   std::istrstream vstream( value.c_str() );
#else
   std::istringstream vstream(value);
#endif
   
   switch (keyType)
   {
        case Tstring: 
	        readKey = new KeyData<String>(keyName, Tstring, value, p, comment);
	        break;
        case Tlogical: 
                vstream >> bvalue;
	        readKey = new KeyData<bool>(keyName, Tlogical, bvalue, p, comment);
	        break;
        case Tbyte: 
                vstream >> byteVal;
	        readKey = new KeyData<unsigned char>(keyName, Tbyte, byteVal, p, comment);
	        break;
        case Tfloat: 
                vstream >> fvalue;
	        readKey = new KeyData<float>(keyName, Tfloat, fvalue, p, comment);
	        break;
        case Tdouble: 
                vstream >> dvalue;
	        readKey = new KeyData<double>(keyName, Tdouble, dvalue, p, comment);
	        break;
        case Tcomplex: 
                vstream >> xvalue;
	        readKey = new KeyData<std::complex<float> >(keyName, Tcomplex, xvalue, p, comment);
	        break;
        case Tdblcomplex: 
                vstream >> zvalue;
	        readKey = new KeyData<std::complex<double> >(keyName, Tdblcomplex, zvalue, p, comment);
	        break;
        case Tint: 
                vstream >> ivalue;
	        readKey = new KeyData<int>(keyName, Tint, ivalue, p, comment);
	        break;
        case Tuint: 
                vstream >> uvalue;
	        readKey = new KeyData<unsigned int>(keyName, Tuint, uvalue, p, comment);
	        break;
        case Tshort: 
                vstream >> isvalue;
	        readKey = new KeyData<short>(keyName, Tshort, isvalue, p, comment);
	        break;
        case Tushort: 
                vstream >> usvalue;
	        readKey = new KeyData<unsigned short>(keyName, Tushort, usvalue, p, comment);
	        break;
        case Tlong: 
                vstream >> ilvalue;
	        readKey = new KeyData<long>(keyName, Tlong, ilvalue, p, comment);
	        break;
        case Tulong: 
                vstream >> ulvalue;
	        readKey = new KeyData<unsigned long>(keyName, Tulong, ulvalue, p, comment);
	        break;
        default:
                std::cerr << "Unknown keyword type\n";
       
   }
   return readKey;
    //## end CCfits::KeywordCreator::getKeyword%39414CC202F1.body
  }

  Keyword* KeywordCreator::getKeyword (int keyNumber, HDU* p)
  {
    //## begin CCfits::KeywordCreator::getKeyword%3CCEA83501E1.body preserve=yes
    FITSUtil::auto_array_ptr<char> pValue(new char[FLEN_VALUE]);    
    FITSUtil::auto_array_ptr<char> pKey(new char[FLEN_KEYWORD]);
    FITSUtil::auto_array_ptr<char> pComment(new char[FLEN_COMMENT]);
    char* key = pKey.get();
    char* comment = pComment.get();
    char* value = pValue.get();
    int status(0);
    if (fits_read_keyn(p->fitsPointer(),keyNumber,key,value,comment,&status)) 
    {
            throw FitsError(status);    
    }
    String valString(value);
    if (KeywordCreator::isContinued(valString))
    {
       bool restoreQuote = valString[0] == '\'';
       KeywordCreator::getLongValueString(p, String(key), valString);
       if (restoreQuote)
       {
          valString = '\'' + valString + '\'';
       }
    }
    int keyClass (fits_get_keyclass(key));
    if ( keyClass == TYP_COMM_KEY || keyClass == TYP_CONT_KEY)
    {
        return 0;
    }
    else
    {
        return parseRecord(String(key),valString,String(comment),p);
    }
    //## end CCfits::KeywordCreator::getKeyword%3CCEA83501E1.body
  }

  Keyword* KeywordCreator::parseRecord (const String& name, const String& valueString, const String& comment, HDU* hdu)
  {
    //## begin CCfits::KeywordCreator::parseRecord%3CCEAA2A02E4.body preserve=yes

     char keyType('\0');
     String value ("");
     bool bvalue (0);
     float fvalue (0);
     int ivalue (0);
     std::complex<float> xvalue(0,0);
     int status (0);

     if ( valueString[0] == '\'')
     {
          value = valueString.substr(1,valueString.length()-2);
     }
     else
     {
         value = valueString;       
     }
#ifdef SSTREAM_DEFECT
     std::istrstream vstream( value.c_str() );
#else   
     std::istringstream vstream(value);
#endif

     if (fits_get_keytype(const_cast<char*>(valueString.c_str()), &keyType, &status))   
     {
             throw FitsError(status);
     }

     switch(keyType)
     {
        case 'L':
           value == "T" ? bvalue = true : bvalue = false;
	   return  new KeyData<bool>(name, Tlogical, bvalue, hdu, comment);
	   break;
        case 'F':
           vstream >> fvalue;
           return  new KeyData<float>(name, Tfloat, fvalue, hdu, comment);
	   break;
        case 'I':
        case 'T':
           vstream >> ivalue;
	   return  new KeyData<int>(name, Tint, ivalue, hdu, comment);
	   break;
        case 'X':
           vstream >> xvalue;
	   return new KeyData<std::complex<float> >(name, Tcomplex, xvalue, hdu, comment);
        case 'C':
        default:
	   return  new KeyData<String>(name, Tstring, 
                        value.substr(0,value.find_last_not_of(" ")+1),hdu, comment);                 
     }
    //## end CCfits::KeywordCreator::parseRecord%3CCEAA2A02E4.body
  }

  bool KeywordCreator::isContinued (const String& value)
  {
    //## begin CCfits::KeywordCreator::isContinued%3F61E20B039C.body preserve=yes
    // Check whether the last non-whitespace char in the value string
    // is an ampersand, which indicates the value string is to be
    // continued on the next line.
    bool status = false;
    String::size_type ampTest = value.find_last_not_of(String(" \n\t'"));
    if (ampTest != String::npos)
    {
       if (value[ampTest] == '&')
       {
          status = true;
       }
    }
    
    return status;
    //## end CCfits::KeywordCreator::isContinued%3F61E20B039C.body
  }

  void KeywordCreator::getLongValueString (HDU* p, const String& keyName, String& value)
  {
    //## begin CCfits::KeywordCreator::getLongValueString%3F61F20001A3.body preserve=yes
    char* lv = 0;
    int status = 0;
    // The following function actually allocates the memory for the
    // lv string - very unusual for cfitsio.
    if (fits_read_key_longstr(p->fitsPointer(), const_cast<char*>(keyName.c_str()), 
                &lv, 0, &status))
    {
       delete lv;
       throw FitsError(status);
    }
    value = String(lv);
    delete lv;
    //## end CCfits::KeywordCreator::getLongValueString%3F61F20001A3.body
  }

  // Additional Declarations
    //## begin CCfits::KeywordCreator%38171AE53AD8.declarations preserve=yes
    //## end CCfits::KeywordCreator%38171AE53AD8.declarations

} // namespace CCfits

//## begin module%38171AF72688.epilog preserve=yes
//## end module%38171AF72688.epilog
