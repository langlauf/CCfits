//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3A15B50B014F.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%3A15B50B014F.cm

//## begin module%3A15B50B014F.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%3A15B50B014F.cp

//## Module: FITSBase%3A15B50B014F; Package body
//## Subsystem: CCfits::FITS%393411910327
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/FITSBase.cxx

//## begin module%3A15B50B014F.additionalIncludes preserve=no
//## end module%3A15B50B014F.additionalIncludes

//## begin module%3A15B50B014F.includes preserve=yes
//## end module%3A15B50B014F.includes

// PHDU
#include "PHDU.h"
// ExtHDU
#include "ExtHDU.h"
// FITSBase
#include "FITSBase.h"
// FITSUtil
#include "FITSUtil.h"


//## begin module%3A15B50B014F.declarations preserve=no
//## end module%3A15B50B014F.declarations

//## begin module%3A15B50B014F.additionalDeclarations preserve=yes
//## end module%3A15B50B014F.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  typedef  std::multimap<string,ExtHDU*> ExtMap;
  typedef  std::multimap<string,ExtHDU*>::iterator ExtMapIt;
  typedef  std::multimap<string,ExtHDU*>::const_iterator ExtMapConstIt;
  //## end CCfits%37FE4140B6F8.initialDeclarations

  // Class CCfits::FITSBase 

  FITSBase::FITSBase(const FITSBase &right)
    //## begin FITSBase::FITSBase%3A15B16501F3_copy.hasinit preserve=yes
    : m_mode(right.m_mode), m_currentExtensionName(right.m_currentExtensionName),
       m_name(right.m_name), m_pHDU(0), 
       m_fptr(FITSUtil::copyFitsPtr(right.m_fptr)), m_extension()
      // copyFitsPtr throws bad_alloc if the allocation fails in copying.
      
    //## end FITSBase::FITSBase%3A15B16501F3_copy.hasinit
    //## begin FITSBase::FITSBase%3A15B16501F3_copy.initialization preserve=yes
    //## end FITSBase::FITSBase%3A15B16501F3_copy.initialization
  {
    //## begin CCfits::FITSBase::FITSBase%3A15B16501F3_copy.body preserve=yes
          
        if (right.m_pHDU)  m_pHDU = dynamic_cast< PHDU *> (right.m_pHDU->clone(this)); 
          
        ExtMapConstIt endList = right.m_extension.end();
        for (ExtMapConstIt hdu = right.m_extension.begin(); hdu != endList; hdu++)
        {              
                ExtHDU* copy = dynamic_cast<ExtHDU*>((*hdu).second->clone(this));
                ExtMap::value_type addHDUEntry((*hdu).first,copy);
                m_extension.insert(addHDUEntry);
        }
    //## end CCfits::FITSBase::FITSBase%3A15B16501F3_copy.body
  }

  FITSBase::FITSBase (const String& fileName, RWmode rwmode)
    //## begin CCfits::FITSBase::FITSBase%3A15B3620048.hasinit preserve=yes
    : m_mode(rwmode), m_currentExtensionName(""), m_name(fileName),
      m_pHDU(0), m_fptr(0), m_extension()
    //## end CCfits::FITSBase::FITSBase%3A15B3620048.hasinit
    //## begin CCfits::FITSBase::FITSBase%3A15B3620048.initialization preserve=yes
    //## end CCfits::FITSBase::FITSBase%3A15B3620048.initialization
  {
    //## begin CCfits::FITSBase::FITSBase%3A15B3620048.body preserve=yes
    //## end CCfits::FITSBase::FITSBase%3A15B3620048.body
  }


  FITSBase::~FITSBase()
  {
    //## begin CCfits::FITSBase::~FITSBase%3A15B16501F3_dest.body preserve=yes
          
    destroyPrimary();    
    destroyExtensions();
    
    int status=0;
    if (m_fptr)
    {
       fits_close_file(m_fptr, &status);
    }
    //## end CCfits::FITSBase::~FITSBase%3A15B16501F3_dest.body
  }



  //## Other Operations (implementation)
  void FITSBase::destroyPrimary ()
  {
    //## begin CCfits::FITSBase::destroyPrimary%3A15B3420057.body preserve=yes
    delete m_pHDU;
    m_pHDU = 0;
    //## end CCfits::FITSBase::destroyPrimary%3A15B3420057.body
  }

  void FITSBase::destroyExtensions ()
  {
    //## begin CCfits::FITSBase::destroyExtensions%3A15B34D01B0.body preserve=yes
        ExtMapIt endList = m_extension.end();
  
        for (ExtMapIt hdu = m_extension.begin();  hdu != endList; hdu++)
        {
                delete (*hdu).second;
        }
  
        m_extension.clear();
    //## end CCfits::FITSBase::destroyExtensions%3A15B34D01B0.body
  }

  FITSBase* FITSBase::clone ()
  {
    //## begin CCfits::FITSBase::clone%3A15B357024F.body preserve=yes
    return new FITSBase(*this);
    //## end CCfits::FITSBase::clone%3A15B357024F.body
  }

  // Additional Declarations
    //## begin CCfits::FITSBase%3A15B16501F3.declarations preserve=yes
    //## end CCfits::FITSBase%3A15B16501F3.declarations

} // namespace CCfits

//## begin module%3A15B50B014F.epilog preserve=yes
//## end module%3A15B50B014F.epilog
