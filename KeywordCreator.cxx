
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
   char    keyType;
   FITSUtil::auto_array_ptr<char> pCard(new char[FLEN_CARD]);
   FITSUtil::auto_array_ptr<char> pV(new char[FLEN_VALUE]);
   FITSUtil::auto_array_ptr<char> pCom(new char[FLEN_COMMENT]);
   char* card(pCard.get());
   char* v(pV.get());
   char* com(pCom.get());

   Keyword* readKey = 0;

   if (fits_read_card(p->fitsPointer(), const_cast<char*>(keyName.c_str()), card,&status) ) 
           throw FitsError(status);

   if (fits_parse_value(card, v, com, &status))  
           throw FitsError(status);

   if (fits_get_keytype(v, &keyType, &status))   throw FitsError(status);
   
   string value(v);
   string vv(v);
   if ( vv[0] == '\'')
   {
        value = vv.substr(1,vv.length()-2);
   }

   string comment(pCom.release());


#ifdef HAVE_STRSTREAM
   std::istrstream vstream( value.c_str() );
#else   
   std::istringstream vstream(value);
#endif

   value = "";
   bool bvalue = 0;
   float fvalue = 0;
   int ivalue = 0;
   std::complex<float> xvalue;
   
   switch(keyType)
   {
      case 'C':
         vstream >> value;
	 readKey = new KeyData<string>(keyName, Tstring, value, p, comment);
	 break;
      case 'L':
         vstream >> value;
         value == "T" ? bvalue = true : bvalue = false;
	 readKey = new KeyData<bool>(keyName, Tlogical, bvalue, p, comment);
	 break;
      case 'F':
         vstream >> fvalue;
         readKey = new KeyData<float>(keyName, Tfloat, fvalue, p, comment);
	 break;
      case 'I':
      case 'T':
         vstream >> ivalue;
	 readKey = new KeyData<int>(keyName, Tint, ivalue, p, comment);
	 break;
      case 'X':
         vstream >> xvalue;
	 readKey = new KeyData<std::complex<float> >(keyName, Tcomplex, xvalue, p, comment);
      default:
         // should throw here.
	 cout << "KeywordCreator::getKeyword: Unknown Type" << endl;
   }

   return readKey;

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
   char* card(pCard.get());
   char* v(pV.get());
   char* com(pCom.get());
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

  // Additional Declarations

} // namespace CCfits

