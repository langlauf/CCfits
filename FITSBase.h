//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3A15B50300A6.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%3A15B50300A6.cm

//## begin module%3A15B50300A6.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%3A15B50300A6.cp

//## Module: FITSBase%3A15B50300A6; Package specification
//## Subsystem: CCfits::FITS%393411910327
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/FITSBase.h

#ifndef FITSBASE_H
#define FITSBASE_H 1

//## begin module%3A15B50300A6.additionalIncludes preserve=no
//## end module%3A15B50300A6.additionalIncludes

// string
#include <string>
// map
#include <map>
// fitsio
#include "fitsio.h"
// CCfitsHeader
#include "CCfits.h"

namespace CCfits {
  class PHDU;
  class ExtHDU;

} // namespace CCfits

//## begin module%3A15B50300A6.includes preserve=yes
//## end module%3A15B50300A6.includes

//## begin module%3A15B50300A6.declarations preserve=no
//## end module%3A15B50300A6.declarations

//## begin module%3A15B50300A6.additionalDeclarations preserve=yes
using std::string;
//## end module%3A15B50300A6.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::FITSBase%3A15B16501F3.preface preserve=yes
  //## end CCfits::FITSBase%3A15B16501F3.preface

  //## Class: FITSBase%3A15B16501F3
  //## Category: CCfits::FITS%393416E90118
  //## Subsystem: CCfits::FITS%393411910327
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%3A19559002AC;std::multimap { -> }

  class FITSBase 
  {
    //## begin CCfits::FITSBase%3A15B16501F3.initialDeclarations preserve=yes
    //## end CCfits::FITSBase%3A15B16501F3.initialDeclarations

    public:
      //## Constructors (generated)
        FITSBase(const FITSBase &right);

      //## Constructors (specified)
        //## Operation: FITSBase%3A15B3620048
        FITSBase (const String& fileName, RWmode rwmode);

      //## Destructor (generated)
        ~FITSBase();


      //## Other Operations (specified)
        //## Operation: destroyPrimary%3A15B3420057
        void destroyPrimary ();

        //## Operation: destroyExtensions%3A15B34D01B0
        void destroyExtensions ();

        //## Operation: clone%3A15B357024F
        FITSBase* clone ();

      //## Get and Set Operations for Associations (generated)

        //## Association: CCfits::<unnamed>%39C631A203D5
        //## Role: FITSBase::mode%39C631A30280
        RWmode mode ();

        //## Association: CCfits::<unnamed>%39CA23DF0371
        //## Role: FITSBase::currentExtensionName%39CA23E10070
        std::string& currentExtensionName ();

        //## Association: CCfits::<unnamed>%3A15B1AA036B
        //## Role: FITSBase::name%3A15B1AA036D
        std::string& name ();

        //## Association: CCfits::<unnamed>%3A15B47F0262
        //## Role: FITSBase::pHDU%3A15B47F0264
        PHDU*& pHDU ();

        //## Association: CCfits::FITS::<unnamed>%4201231500FD
        //## Role: FITSBase::fptr %420123160117
        fitsfile*& fptr ();

        //## Association: CCfits::extension%3A193EA70004
        //## Role: FITSBase::extension%3A193EA8026C
        //## Qualifier: hduName%3A193EC300AE; string
        ExtMap& extension ();

      // Additional Public Declarations
        //## begin CCfits::FITSBase%3A15B16501F3.public preserve=yes
        //## end CCfits::FITSBase%3A15B16501F3.public

    protected:
      // Additional Protected Declarations
        //## begin CCfits::FITSBase%3A15B16501F3.protected preserve=yes
        //## end CCfits::FITSBase%3A15B16501F3.protected

    private:
      //## Assignment Operation (generated)
        FITSBase & operator=(const FITSBase &right);

      // Additional Private Declarations
        //## begin CCfits::FITSBase%3A15B16501F3.private preserve=yes
        //## end CCfits::FITSBase%3A15B16501F3.private

    private: //## implementation
      // Data Members for Associations

        //## Association: CCfits::<unnamed>%39C631A203D5
        //## begin CCfits::FITSBase::mode%39C631A30280.role preserve=no  public: CCfits::RWmode { -> 1VHgN}
        RWmode m_mode;
        //## end CCfits::FITSBase::mode%39C631A30280.role

        //## Association: CCfits::<unnamed>%39CA23DF0371
        //## begin CCfits::FITSBase::currentExtensionName%39CA23E10070.role preserve=no  public: std::string { -> 1VHgN}
        std::string m_currentExtensionName;
        //## end CCfits::FITSBase::currentExtensionName%39CA23E10070.role

        //## Association: CCfits::<unnamed>%3A15B1AA036B
        //## begin CCfits::FITSBase::name%3A15B1AA036D.role preserve=no  public: std::string { -> 1..1VHgN}
        std::string m_name;
        //## end CCfits::FITSBase::name%3A15B1AA036D.role

        //## Association: CCfits::<unnamed>%3A15B47F0262
        //## begin CCfits::FITSBase::pHDU%3A15B47F0264.role preserve=no  public: CCfits::PHDU {1..1 -> 1..1RFHgN}
        PHDU* m_pHDU;
        //## end CCfits::FITSBase::pHDU%3A15B47F0264.role

        //## Association: CCfits::FITS::<unnamed>%4201231500FD
        //## begin CCfits::FITSBase::fptr %420123160117.role preserve=no  public: fitsfile { -> 1RHgN}
        fitsfile* m_fptr;
        //## end CCfits::FITSBase::fptr %420123160117.role

        //## Association: CCfits::extension%3A193EA70004
        //## begin CCfits::FITSBase::extension%3A193EA8026C.role preserve=no  public: CCfits::ExtHDU { -> 1RFHgN}
        ExtMap m_extension;
        //## end CCfits::FITSBase::extension%3A193EA8026C.role

      // Additional Implementation Declarations
        //## begin CCfits::FITSBase%3A15B16501F3.implementation preserve=yes
        //## end CCfits::FITSBase%3A15B16501F3.implementation

  };

  //## begin CCfits::FITSBase%3A15B16501F3.postscript preserve=yes
  //## end CCfits::FITSBase%3A15B16501F3.postscript

  // Class CCfits::FITSBase 

  //## Get and Set Operations for Associations (inline)

  inline RWmode FITSBase::mode ()
  {
    //## begin CCfits::FITSBase::mode%39C631A30280.get preserve=no
    return m_mode;
    //## end CCfits::FITSBase::mode%39C631A30280.get
  }

  inline std::string& FITSBase::currentExtensionName ()
  {
    //## begin CCfits::FITSBase::currentExtensionName%39CA23E10070.get preserve=no
    return m_currentExtensionName;
    //## end CCfits::FITSBase::currentExtensionName%39CA23E10070.get
  }

  inline std::string& FITSBase::name ()
  {
    //## begin CCfits::FITSBase::name%3A15B1AA036D.get preserve=no
    return m_name;
    //## end CCfits::FITSBase::name%3A15B1AA036D.get
  }

  inline PHDU*& FITSBase::pHDU ()
  {
    //## begin CCfits::FITSBase::pHDU%3A15B47F0264.get preserve=no
    return m_pHDU;
    //## end CCfits::FITSBase::pHDU%3A15B47F0264.get
  }

  inline fitsfile*& FITSBase::fptr ()
  {
    //## begin CCfits::FITSBase::fptr%420123160117.get preserve=no
    return m_fptr;
    //## end CCfits::FITSBase::fptr%420123160117.get
  }

  inline ExtMap& FITSBase::extension ()
  {
    //## begin CCfits::FITSBase::extension%3A193EA8026C.get preserve=no
    return m_extension;
    //## end CCfits::FITSBase::extension%3A193EA8026C.get
  }

} // namespace CCfits

//## begin module%3A15B50300A6.epilog preserve=yes
//## end module%3A15B50300A6.epilog


#endif
