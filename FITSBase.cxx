
//	This is version 1.2 release dated April 2003

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	April 2003 Ben Dorman, L3-Communications EER Systems Inc.
//	e-mail: ccfits@legacy.gsfc.nasa.gov




// PHDU
#include "PHDU.h"
// ExtHDU
#include "ExtHDU.h"
// FITSBase
#include "FITSBase.h"
// FITSUtil
#include "FITSUtil.h"





namespace CCfits {
  typedef  std::multimap<string,ExtHDU*> ExtMap;
  typedef  std::multimap<string,ExtHDU*>::iterator ExtMapIt;
  typedef  std::multimap<string,ExtHDU*>::const_iterator ExtMapConstIt;

  // Class CCfits::FITSBase 

  FITSBase::FITSBase(const FITSBase &right)
    : m_mode(right.m_mode), m_currentExtensionName(right.m_currentExtensionName),
       m_name(right.m_name), m_pHDU(0), 
       m_fptr(FITSUtil::copyFitsPtr(right.m_fptr)), m_extension()
      // copyFitsPtr throws bad_alloc if the allocation fails in copying.
      
  {
          
        if (right.m_pHDU)  m_pHDU = dynamic_cast< PHDU *> (right.m_pHDU->clone(this)); 
          
        ExtMapConstIt endList = right.m_extension.end();
        for (ExtMapConstIt hdu = right.m_extension.begin(); hdu != endList; hdu++)
        {              
                ExtHDU* copy = dynamic_cast<ExtHDU*>((*hdu).second->clone(this));
                ExtMap::value_type addHDUEntry((*hdu).first,copy);
                m_extension.insert(addHDUEntry);
        }
  }

  FITSBase::FITSBase (const string& fileName, RWmode rwmode)
    : m_mode(rwmode), m_currentExtensionName(""), m_name(fileName),
      m_pHDU(0), m_fptr(0), m_extension()
  {
  }


  FITSBase::~FITSBase()
  {
          
    destroyPrimary();
    
    destroyExtensions();
  }



  void FITSBase::destroyPrimary ()
  {
    delete m_pHDU;
    m_pHDU = 0;
  }

  void FITSBase::destroyExtensions ()
  {
        ExtMapIt endList = m_extension.end();
  
        for (ExtMapIt hdu = m_extension.begin();  hdu != endList; hdu++)
        {
                delete (*hdu).second;
        }
  
        m_extension.clear();
  }

  FITSBase* FITSBase::clone ()
  {
    return new FITSBase(*this);
  }

  // Additional Declarations

} // namespace CCfits

