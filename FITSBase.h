
//	This is CCfits version 1.0-beta

//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov


#ifndef FITSBASE_H
#define FITSBASE_H 1



// map
#include <map>
// fitsio
#include "fitsio.h"
// string
#include <string>
// CCfitsHeader
#include "CCfits.h"

namespace CCfits {
  class PHDU;
  class ExtHDU;

} // namespace CCfits


using std::string;


namespace CCfits {




  class FITSBase 
  {

    public:
        FITSBase(const FITSBase &right);

        FITSBase (const string& fileName, RWmode rwmode);

        ~FITSBase();


        void destroyPrimary ();

        void destroyExtensions ();

        FITSBase* clone ();


        RWmode mode ();

        std::string& currentExtensionName ();

        std::string& name ();

        PHDU*& pHDU ();

        fitsfile*& fptr ();

        std::multimap<string,ExtHDU*>& extension ();

      // Additional Public Declarations

    protected:
      // Additional Protected Declarations

    private:
        FITSBase & operator=(const FITSBase &right);

      // Additional Private Declarations

    private: //## implementation
      // Data Members for Associations

        RWmode m_mode;

        std::string m_currentExtensionName;

        std::string m_name;

        PHDU* m_pHDU;

        fitsfile* m_fptr;

        std::multimap<string,ExtHDU*> m_extension;

      // Additional Implementation Declarations

  };


  // Class CCfits::FITSBase 


  inline RWmode FITSBase::mode ()
  {
    return m_mode;
  }

  inline std::string& FITSBase::currentExtensionName ()
  {
    return m_currentExtensionName;
  }

  inline std::string& FITSBase::name ()
  {
    return m_name;
  }

  inline PHDU*& FITSBase::pHDU ()
  {
    return m_pHDU;
  }

  inline fitsfile*& FITSBase::fptr ()
  {
    return m_fptr;
  }

  inline std::multimap<string,ExtHDU*>& FITSBase::extension ()
  {
    return m_extension;
  }

} // namespace CCfits



#endif
