
//	This is version 1.1 release dated May 2002

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	May 2002 Ben Dorman, L3-Com Analytics Corporation
//	e-mail: ccfits@legacy.gsfc.nasa.gov




// KeyData
#include "KeyData.h"

#include <complex>
#include <iomanip>


namespace CCfits
{   
#ifndef SPEC_TEMPLATE_IMP_DEFECT
#ifndef SPEC_TEMPLATE_DECL_DEFECT
        template<>
        void KeyData<string>::write() 
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
        ostream & KeyData<string>::put (ostream &s) const
        {
   		using std::setw;
   		s << "Keyword Name: " << setw(10) << name() << "  Value: " << setw(14) 
                  << keyval() << " Type: " << setw(20) << " string "  << " Comment: " << comment();
          return s;
        }
#endif
#endif

        template  <>
        void KeyData<string>::keyval(const string& newVal)
        {
                m_keyval = newVal;

        }

#ifndef SPEC_TEMPLATE_IMP_DEFECT
#ifndef SPEC_TEMPLATE_DECL_DEFECT
        template <>
        ostream & KeyData<std::complex<float> >::put (ostream &s) const
        {
   		using std::setw;
           	s << "Keyword Name: " << name() << " Value: " << m_keyval.real() << " +   i " 
             	  << m_keyval.imag() <<   " Type: " <<  setw(20) << " complex<float> " 
             	  << " Comment: " << comment()   << std::endl;
          return s;
        }
        
        template <>
        ostream & KeyData<std::complex<double> >::put (ostream &s) const
        {
   		using std::setw;
           	s << "Keyword Name: " << name() << " Value: " << m_keyval.real() << " +   i " 
             	  << m_keyval.imag() <<   " Type: " <<  setw(20) << " complex<double> " 
             	  << " Comment: " << comment()   << std::endl;

	          return s;
        }
#endif
#endif

#ifndef SPEC_TEMPLATE_DECL_DEFECT
        template  <>
        const string& KeyData<string>::keyval() const
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
