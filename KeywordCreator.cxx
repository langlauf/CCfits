
//	This is version 1.1.1 release dated Sept 2002

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	Sept 2002 Ben Dorman, L3-Communications
//	e-mail: ccfits@legacy.gsfc.nasa.gov



#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_STRSTREAM
#include <strstream>
#else
#include <sstream>
#endif


// HDU
#include "HDU.h"
// KeywordCreator
#include "KeywordCreator.h"

//#include "HDU.h"
using std::cout;
using std::endl;


namespace CCfits {

  // Class CCfits::KeywordCreator 

  KeywordCreator::KeywordCreator (HDU* p)
      : m_keyword(0), m_forHDU(p)
  {
  }


  KeywordCreator::~KeywordCreator()
  {
  }



  Keyword* KeywordCreator::getKeyword (const string& keyName, HDU* p)
  {
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
   
   return parseRecord(keyName,string(v),string(com),p);

  }

  Keyword* KeywordCreator::createKeyword (const string& keyName, const string& comment)
  {
  if (m_keyword == 0) m_keyword = MakeKeyword(keyName,comment);
  return m_keyword;
  }

  Keyword* KeywordCreator::getKeyword (const string& keyName, ValueType keyType, HDU* p)
  {
   int status = 0;
   string val = "";
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

   
   string value(pV.release());
   string comment(pCom.release());
 
#ifdef HAVE_STRSTREAM
   std::istrstream vstream( value.c_str() );
#else
   std::istringstream vstream(value);
#endif
   
   switch (keyType)
   {
        case Tstring: 
	        readKey = new KeyData<string>(keyName, Tstring, value, p, comment);
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
  }

  Keyword* KeywordCreator::getKeyword (int keyNumber, HDU* p)
  {
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
    int keyClass (fits_get_keyclass(key));
    if ( keyClass == TYP_COMM_KEY || keyClass == TYP_CONT_KEY)
    {
        return 0;
    }
    else
    {
        return parseRecord(string(key),string(value),string(comment),p);
    }
  }

  Keyword* KeywordCreator::parseRecord (const string& name, const string& valueString, const string& comment, HDU* hdu)
  {

     char keyType('\0');
     string value ("");
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
  #ifdef HAVE_STRSTREAM
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
	   return  new KeyData<string>(name, Tstring, 
                        value.substr(0,value.find_last_not_of(" ")+1),hdu, comment);                 
     }
  }

  // Additional Declarations

} // namespace CCfits

