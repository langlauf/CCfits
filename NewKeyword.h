//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3935715800D4.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%3935715800D4.cm

//## begin module%3935715800D4.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%3935715800D4.cp

//## Module: NewKeyword%3935715800D4; Package specification
//## Subsystem: CCfits::Keyword%3826DF71D818
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/NewKeyword.h

#ifndef NEWKEYWORD_H
#define NEWKEYWORD_H 1

//## begin module%3935715800D4.additionalIncludes preserve=no
//## end module%3935715800D4.additionalIncludes

// KeywordCreator
#include "KeywordCreator.h"
// KeyData
#include "KeyData.h"
// FITSUtil
#include "FITSUtil.h"
//## begin module%3935715800D4.includes preserve=yes
//## end module%3935715800D4.includes

//## begin module%3935715800D4.declarations preserve=no
//## end module%3935715800D4.declarations

//## begin module%3935715800D4.additionalDeclarations preserve=yes
//## end module%3935715800D4.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::NewKeyword%39355A710265.preface preserve=yes
  //## end CCfits::NewKeyword%39355A710265.preface

  //## Class: NewKeyword%39355A710265; Parameterized Class
  //## Category: CCfits::Keyword%393417BC003C
  //## Subsystem: CCfits::Keyword%3826DF71D818
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%39357009D260;protected:  { -> }
  //## Uses: <unnamed>%39357009D261;protected:  { -> }
  //## Uses: <unnamed>%3935730B01D0;KeyData { -> }

  template <typename T>
  class NewKeyword : public KeywordCreator  //## Inherits: <unnamed>%39355AA90209
  {
    //## begin CCfits::NewKeyword%39355A710265.initialDeclarations preserve=yes
    //## end CCfits::NewKeyword%39355A710265.initialDeclarations

    public:
      //## Constructors (specified)
        //## Operation: NewKeyword%39355AD40220; C++
        //	Parameterized Class NewKeyword
        NewKeyword (HDU* p, T value);

      //## Destructor (generated)
        virtual ~NewKeyword();


      //## Other Operations (specified)
        //## Operation: MakeKeyword%39355D860356; C++
        //	Additional Protected Declarations
        virtual Keyword* MakeKeyword (const String& keyName, const String& keyComment = String(""));

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: keyData%39355AB003D1
        const T keyData () const;
        void keyData (T value);

      // Additional Public Declarations
        //## begin CCfits::NewKeyword%39355A710265.public preserve=yes
        //## end CCfits::NewKeyword%39355A710265.public

    protected:
      // Additional Protected Declarations
        //## begin CCfits::NewKeyword%39355A710265.protected preserve=yes
        //## end CCfits::NewKeyword%39355A710265.protected

    private:
      //## Constructors (generated)
        NewKeyword();

        NewKeyword(const NewKeyword< T > &right);

      //## Assignment Operation (generated)
        NewKeyword< T > & operator=(const NewKeyword< T > &right);

      // Additional Private Declarations
        //## begin CCfits::NewKeyword%39355A710265.private preserve=yes
        //## end CCfits::NewKeyword%39355A710265.private

    private: //## implementation
      // Data Members for Class Attributes

        //## begin CCfits::NewKeyword::keyData%39355AB003D1.attr preserve=no  public: T {U} value
        T m_keyData;
        //## end CCfits::NewKeyword::keyData%39355AB003D1.attr

      // Additional Implementation Declarations
        //## begin CCfits::NewKeyword%39355A710265.implementation preserve=yes
        //## end CCfits::NewKeyword%39355A710265.implementation

  };

  //## begin CCfits::NewKeyword%39355A710265.postscript preserve=yes
  //## end CCfits::NewKeyword%39355A710265.postscript

  // Parameterized Class CCfits::NewKeyword 

  //## Get and Set Operations for Class Attributes (inline)

  template <typename T>
  inline const T NewKeyword<T>::keyData () const
  {
    //## begin CCfits::NewKeyword::keyData%39355AB003D1.get preserve=no
    return m_keyData;
    //## end CCfits::NewKeyword::keyData%39355AB003D1.get
  }

  template <typename T>
  inline void NewKeyword<T>::keyData (T value)
  {
    //## begin CCfits::NewKeyword::keyData%39355AB003D1.set preserve=no
    m_keyData = value;
    //## end CCfits::NewKeyword::keyData%39355AB003D1.set
  }

  // Parameterized Class CCfits::NewKeyword 

  template <typename T>
  NewKeyword<T>::NewKeyword (HDU* p, T value)
    //## begin CCfits::NewKeyword::NewKeyword%39355AD40220.hasinit preserve=yes
      : KeywordCreator(p), m_keyData(value)
    //## end CCfits::NewKeyword::NewKeyword%39355AD40220.hasinit
    //## begin CCfits::NewKeyword::NewKeyword%39355AD40220.initialization preserve=yes
    //## end CCfits::NewKeyword::NewKeyword%39355AD40220.initialization
  {
    //## begin CCfits::NewKeyword::NewKeyword%39355AD40220.body preserve=yes
    //## end CCfits::NewKeyword::NewKeyword%39355AD40220.body
  }


  template <typename T>
  NewKeyword<T>::~NewKeyword()
  {
    //## begin CCfits::NewKeyword::~NewKeyword%39355A710265_dest.body preserve=yes
    //## end CCfits::NewKeyword::~NewKeyword%39355A710265_dest.body
  }



  //## Other Operations (implementation)
  template <typename T>
  Keyword* NewKeyword<T>::MakeKeyword (const String& keyName, const String& keyComment)
  {
    //## begin CCfits::NewKeyword::MakeKeyword%39355D860356.body preserve=yes
  FITSUtil::MatchType<T> keyType;
  return new KeyData<T>(keyName,keyType(),m_keyData,forHDU(),keyComment);
    //## end CCfits::NewKeyword::MakeKeyword%39355D860356.body
  }

  // Additional Declarations
    //## begin CCfits::NewKeyword%39355A710265.declarations preserve=yes
    //## end CCfits::NewKeyword%39355A710265.declarations

} // namespace CCfits

//## begin module%3935715800D4.epilog preserve=yes
//## end module%3935715800D4.epilog


#endif
