
//	This is CCfits version 1.0-beta release August 2001

//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov




// KeyData
#include "KeyData.h"

#include <complex>


namespace CCfits
{       
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
        //   int status = 0;
        //   fits_write_key(const_cast<fitsfile*>(parent()->fptr()), Tstring, 
        //			   const_cast<char *>(name().c_str()),
        //			 
        //			   const_cast<char *>(comment().c_str()), 
        //			   &status);

        }


        template <>
        ostream & KeyData<string>::put (ostream &s) const
        {
           s << "Keyword Name: " << name() << "\t Value: " << keyval() << 
             "\t Type: " << keytype() << "\t Comment: " << comment();

          return s;
        }

        template  <>
        void KeyData<string>::keyval(const string& newVal)
        {
                m_keyval = newVal;

        }


        template  <>
        const string& KeyData<string>::keyval() const
        {
                return m_keyval;

        }


        template  <>
        void KeyData<std::complex<float> >::keyval(const std::complex<float>&  newVal)
        {
                m_keyval = newVal;

        }

        template  <>
        const std::complex<float>& KeyData<std::complex<float> >::keyval() const
        {
                return m_keyval;

        }


        template <>
        ostream & KeyData<std::complex<float> >::put (ostream &s) const
        {
           s << "keyname: " << name() << " value: " << m_keyval << 
            " type: " << keytype() << std::endl;

          return s;
        }

} // namespace CCfits
