//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%38171AF918A8.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%38171AF918A8.cm

//## begin module%38171AF918A8.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%38171AF918A8.cp

//## Module: KeywordCreator%38171AF918A8; Package specification
//## Subsystem: CCfits::Keyword%3826DF71D818
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/KeywordCreator.h

#ifndef KEYWORDCREATOR_H
#define KEYWORDCREATOR_H 1

//## begin module%38171AF918A8.additionalIncludes preserve=no
//## end module%38171AF918A8.additionalIncludes

// KeyData
#include "KeyData.h"
// FitsError
#include "FitsError.h"

namespace CCfits {
  class HDU;

} // namespace CCfits

//## begin module%38171AF918A8.includes preserve=yes
//## end module%38171AF918A8.includes

//## begin module%38171AF918A8.declarations preserve=no
//## end module%38171AF918A8.declarations

//## begin module%38171AF918A8.additionalDeclarations preserve=yes
//## end module%38171AF918A8.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::KeywordCreator%38171AE53AD8.preface preserve=yes
  //## end CCfits::KeywordCreator%38171AE53AD8.preface

  //## Class: KeywordCreator%38171AE53AD8
  //## Category: CCfits::Keyword%393417BC003C
  //## Subsystem: CCfits::Keyword%3826DF71D818
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%393531CE011B;KeyData { -> }
  //## Uses: <unnamed>%39354DE7004E;friend  { -> }
  //## Uses: <unnamed>%393554E8032F; { -> }
  //## Uses: <unnamed>%39357008E6E1; { -> }

  class KeywordCreator 
  {
    //## begin CCfits::KeywordCreator%38171AE53AD8.initialDeclarations preserve=yes
    //## end CCfits::KeywordCreator%38171AE53AD8.initialDeclarations

    public:
      //## Constructors (specified)
        //## Operation: KeywordCreator%397F059803DA
        KeywordCreator (HDU* p);

      //## Destructor (generated)
        virtual ~KeywordCreator();


      //## Other Operations (specified)
        //## Operation: MakeKeyword%38171BCDFBE0; C++
        virtual Keyword* MakeKeyword (const String& keyName, const String& comment = String("")) = 0;

        //## Operation: getKeyword%3935740F00A2
        static Keyword* getKeyword (const String& keyName, HDU* p);

        //## Operation: reset%38171C090928; C++
        //	Additional Public Declarations
        virtual void reset ();

        //## Operation: createKeyword%39411F6D03D7; C++
        virtual Keyword* createKeyword (const String& keyName, const String& comment = String(""));

        //## Operation: getKeyword%39414CC202F1
        //	This version of getKeyword is for reading a keyword
        //	in with a specified type.
        static Keyword* getKeyword (const String& keyName, ValueType keyType, HDU* p);

        //## Operation: getKeyword%3CCEA83501E1
        static Keyword* getKeyword (int keyNumber, HDU* p);

      // Additional Public Declarations
        //## begin CCfits::KeywordCreator%38171AE53AD8.public preserve=yes
        //## end CCfits::KeywordCreator%38171AE53AD8.public

    protected:
      //## Get and Set Operations for Associations (generated)

        //## Association: CCfits::Keyword::<unnamed>%3A15604F02F1
        //## Role: KeywordCreator::forHDU%3A1560500244
        HDU* forHDU ();

      // Additional Protected Declarations
        //## begin CCfits::KeywordCreator%38171AE53AD8.protected preserve=yes
        //## end CCfits::KeywordCreator%38171AE53AD8.protected

    private:
      //## Constructors (generated)
        KeywordCreator(const KeywordCreator &right);

      //## Assignment Operation (generated)
        KeywordCreator & operator=(const KeywordCreator &right);


      //## Other Operations (specified)
        //## Operation: parseRecord%3CCEAA2A02E4
        static Keyword* parseRecord (const String& name, const String& valueString, const String& comment, HDU* hdu);

        //## Operation: isContinued%3F61E20B039C
        static bool isContinued (const String& value);

        //## Operation: getLongValueString%3F61F20001A3
        static void getLongValueString (HDU* p, const String& keyName, String& value);

      // Additional Private Declarations
        //## begin CCfits::KeywordCreator%38171AE53AD8.private preserve=yes
        //## end CCfits::KeywordCreator%38171AE53AD8.private

    private: //## implementation
      // Data Members for Class Attributes

        //## Attribute: keyword%38171BAE6770
        //## begin CCfits::KeywordCreator::keyword%38171BAE6770.attr preserve=no  protected: Keyword * {U} 0
        Keyword *m_keyword;
        //## end CCfits::KeywordCreator::keyword%38171BAE6770.attr

      // Data Members for Associations

        //## Association: CCfits::Keyword::<unnamed>%3A15604F02F1
        //## begin CCfits::KeywordCreator::forHDU%3A1560500244.role preserve=no  protected: CCfits::HDU { -> 1RFHgN}
        HDU* m_forHDU;
        //## end CCfits::KeywordCreator::forHDU%3A1560500244.role

      // Additional Implementation Declarations
        //## begin CCfits::KeywordCreator%38171AE53AD8.implementation preserve=yes
        //## end CCfits::KeywordCreator%38171AE53AD8.implementation

  };

  //## begin CCfits::KeywordCreator%38171AE53AD8.postscript preserve=yes
  //## end CCfits::KeywordCreator%38171AE53AD8.postscript

  // Class CCfits::KeywordCreator 


  //## Other Operations (inline)
  inline void KeywordCreator::reset ()
  {
    m_keyword=0;


    //## begin CCfits::KeywordCreator::reset%38171C090928.body preserve=yes
    //## end CCfits::KeywordCreator::reset%38171C090928.body
  }

  //## Get and Set Operations for Associations (inline)

  inline HDU* KeywordCreator::forHDU ()
  {
    //## begin CCfits::KeywordCreator::forHDU%3A1560500244.get preserve=no
    return m_forHDU;
    //## end CCfits::KeywordCreator::forHDU%3A1560500244.get
  }

} // namespace CCfits

//## begin module%38171AF918A8.epilog preserve=yes
//## end module%38171AF918A8.epilog


#endif
