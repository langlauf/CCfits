
//	This is version 1.1.1 release dated Sept 2002

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	Sept 2002 Ben Dorman, L3-Communications
//	e-mail: ccfits@legacy.gsfc.nasa.gov


#ifndef KEYWORDCREATOR_H
#define KEYWORDCREATOR_H 1

#include <iostream>

// KeyData
#include "KeyData.h"
// FitsError
#include "FitsError.h"

namespace CCfits {
  class HDU;

} // namespace CCfits





namespace CCfits {






  class KeywordCreator 
  {

    public:
        KeywordCreator (HDU* p);

        virtual ~KeywordCreator();


        virtual Keyword* MakeKeyword (const string& keyName, const string& comment = string("")) = 0;

        static Keyword* getKeyword (const string& keyName, HDU* p);

        //	Additional Public Declarations
        virtual void reset ();

        virtual Keyword* createKeyword (const string& keyName, const string& comment = string(""));

        //	This version of getKeyword is for reading a keyword
        //	in with a specified type.
        static Keyword* getKeyword (const string& keyName, ValueType keyType, HDU* p);

        static Keyword* getKeyword (int keyNumber, HDU* p);

      // Additional Public Declarations

    protected:

        HDU* forHDU ();

      // Additional Protected Declarations

    private:
        KeywordCreator(const KeywordCreator &right);

        KeywordCreator & operator=(const KeywordCreator &right);


        static Keyword* parseRecord (const string& name, const string& valueString, const string& comment, HDU* hdu);

      // Additional Private Declarations

    private: //## implementation
      // Data Members for Class Attributes

        Keyword *m_keyword;

      // Data Members for Associations

        HDU* m_forHDU;

      // Additional Implementation Declarations

  };


  // Class CCfits::KeywordCreator 


  inline void KeywordCreator::reset ()
  {
    m_keyword=0;


  }


  inline HDU* KeywordCreator::forHDU ()
  {
    return m_forHDU;
  }

} // namespace CCfits



#endif
