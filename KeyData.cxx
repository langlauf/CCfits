//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%38171603E2E8.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%38171603E2E8.cm

//## begin module%38171603E2E8.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%38171603E2E8.cp

//## Module: KeyData%38171603E2E8; Package body
//## Subsystem: CCfits::Keyword%3826DF71D818
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/KeyData.cxx

//## begin module%38171603E2E8.additionalIncludes preserve=no
//## end module%38171603E2E8.additionalIncludes

//## begin module%38171603E2E8.includes preserve=yes
//## end module%38171603E2E8.includes

// KeyData
#include "KeyData.h"
//## begin module%38171603E2E8.declarations preserve=no
//## end module%38171603E2E8.declarations

//## begin module%38171603E2E8.additionalDeclarations preserve=yes
#include <complex>
#include <iomanip>
//## end module%38171603E2E8.additionalDeclarations


//## begin module%38171603E2E8.epilog preserve=yes
namespace CCfits
{   
#ifndef SPEC_TEMPLATE_IMP_DEFECT
#ifndef SPEC_TEMPLATE_DECL_DEFECT
        template<>
        void KeyData<bool>::write() 
        {
           int status = 0;
           int value(0);
           if (m_keyval) value = 1; 
           if (fits_update_key(fitsPointer(), Tlogical, 
			           const_cast<char *>(name().c_str()),
			           &value,
			           const_cast<char *>(comment().c_str()), 
			           &status)) throw FitsError(status);

        }
                
        template<>
        void KeyData<String>::write() 
        {
           int status = 0;
           if (fits_update_key(fitsPointer(), Tstring, 
			           const_cast<char *>(name().c_str()),
			           const_cast<char*>(m_keyval.c_str()),
			           const_cast<char *>(comment().c_str()), 
			           &status)) throw FitsError(status);

        }

        template<>
        void KeyData<std::complex<float> >::write() 
        {
             int status = 0;
             FITSUtil::auto_array_ptr<float> keyVal( new float[2]);
             keyVal[0] = m_keyval.real(); 
             keyVal[1] = m_keyval.imag(); 
             if (fits_update_key(fitsPointer(), Tcomplex, 
        			   const_cast<char *>(name().c_str()),
        			   keyVal.get(),
         			   const_cast<char *>(comment().c_str()), 
        			   &status)) throw FitsError(status);

        }

        template<>
        void KeyData<std::complex<double> >::write() 
        {
             int status = 0;
             FITSUtil::auto_array_ptr<double> keyVal(new double[2]);
             keyVal[0] = m_keyval.real(); 
             keyVal[1] = m_keyval.imag(); 
             if (fits_update_key(fitsPointer(), Tdblcomplex, 
        			   const_cast<char *>(name().c_str()),
        			   keyVal.get(),
         			   const_cast<char *>(comment().c_str()), 
        			   &status)) throw FitsError(status);

        }


        template <>
        std::ostream & KeyData<String>::put (std::ostream &s) const
        {
   		using std::setw;
   		s << "Keyword Name: " << setw(10) << name() << "  Value: " << setw(14) 
                  << keyval() << " Type: " << setw(20) << " string "  << " Comment: " << comment();
          return s;
        }
#endif
#endif

        template  <>
        void KeyData<String>::keyval(const String& newVal)
        {
                m_keyval = newVal;

        }

#ifndef SPEC_TEMPLATE_IMP_DEFECT
#ifndef SPEC_TEMPLATE_DECL_DEFECT
        template <>
        std::ostream & KeyData<std::complex<float> >::put (std::ostream &s) const
        {
   		using std::setw;
           	s << "Keyword Name: " << name() << " Value: " << m_keyval.real() << " +   i " 
             	  << m_keyval.imag() <<   " Type: " <<  setw(20) << " complex<float> " 
             	  << " Comment: " << comment()   << std::endl;
          return s;
        }
        
        template <>
        std::ostream & KeyData<std::complex<double> >::put (std::ostream &s) const
        {
   		using std::setw;
           	s << "Keyword Name: " << name() << " Value: " << m_keyval.real() << " +   i " 
             	  << m_keyval.imag() <<   " Type: " <<  setw(20) << " complex<double> " 
             	  << " Comment: " << comment()   << std::endl;

	          return s;
        }
        
        template <>
        std::ostream & KeyData<bool>::put (std::ostream &s) const
        {
   		using std::setw;
   		s << "Keyword Name: " << setw(10) << name() 
                  << "  Value: " << std::boolalpha  << setw(8) << keyval() 
                  << "  Type: " << setw(20) << " logical "  << " Comment: " << comment();
                return s;
        }
        
        
#endif
#endif

#ifndef SPEC_TEMPLATE_DECL_DEFECT
        template  <>
        const String& KeyData<String>::keyval() const
        {
                return m_keyval;

        }
#endif

#ifndef SPEC_TEMPLATE_DECL_DEFECT
        template  <>
        void KeyData<std::complex<float> >::keyval(const std::complex<float>&  newVal)
        {
                m_keyval = newVal;

        }
        template  <>
        void KeyData<std::complex<double> >::keyval(const std::complex<double>&  newVal)
        {
                m_keyval = newVal;

        }

        template  <>
        const std::complex<float>& KeyData<std::complex<float> >::keyval() const
        {
                return m_keyval;

        }

        template  <>
        const std::complex<double>& KeyData<std::complex<double> >::keyval() const
        {
                return m_keyval;

        }

#endif


} // namespace CCfits
//## end module%38171603E2E8.epilog
