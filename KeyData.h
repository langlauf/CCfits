
//	This is version 1.2 release dated April 2003

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	April 2003 Ben Dorman, L3-Communications EER Systems Inc.
//	e-mail: ccfits@legacy.gsfc.nasa.gov


#ifndef KEYDATA_H
#define KEYDATA_H 1

#ifdef _MSC_VER
#include "MSconfig.h"
#endif

#include "CCfits.h"

// Keyword
#include "Keyword.h"


#include <complex>
#include <iomanip>
#include "FitsError.h"
#include "FITSUtil.h"


namespace CCfits {

//class Keyword;




  template <typename T>
  class KeyData : public Keyword  //## Inherits: <unnamed>%381F43399D58
  {

    public:
        KeyData(const KeyData< T > &right);

        KeyData (const string &keyname, ValueType keytype, const T &value, HDU* p, 	// A pointer to the HDU containing the keyword. This is passed to the base class constructor.
        const string &comment = "");

        virtual ~KeyData();


        virtual KeyData <T>* clone () const;

        virtual void write ();


        const T& keyval () const;
        void keyval (const T& value);

      // Additional Public Declarations

    protected:

        virtual void copy (const Keyword& right);

        virtual bool compare (const Keyword &right) const;

        virtual ostream & put (ostream &s) const;

      // Additional Protected Declarations

    private:
      // Data Members for Class Attributes

        T m_keyval;

      // Additional Private Declarations

    private: //## implementation
      // Additional Implementation Declarations

  };

#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
        template<>
        inline void KeyData<string>::write() 
        {
           int status = 0;
           if (fits_update_key(fitsPointer(), Tstring, 
			           const_cast<char *>(name().c_str()),
			           const_cast<char*>(m_keyval.c_str()),
			           const_cast<char *>(comment().c_str()), 
			           &status)) throw FitsError(status);

        }
#else
template<> void KeyData<string>::write();
#endif

#ifdef SPEC_TEMPLATE_DECL_DEFECT
        template  <>
        inline const string& KeyData<string>::keyval() const
        {
                return m_keyval;

        }
#else
template<> const string& KeyData<string>::keyval() const;
#endif

#ifndef SPEC_TEMPLATE_DECL_DEFECT
template<> void KeyData<string>::keyval(const string& );
#endif

#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
        template <>
        inline ostream & KeyData<string>::put (ostream &s) const
        {
   		using std::setw;
   		s << "Keyword Name: " << setw(10) << name() << "  Value: " << setw(14) 
                  << keyval() << " Type: " << setw(20) << " string "  << " Comment: " << comment();
          return s;
        }

#else
template<> ostream& KeyData<string>::put(ostream& s) const;
#endif

#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
        template<>
        inline void KeyData<std::complex<float> >::write() 
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
#else
template<> void KeyData<std::complex<float> >::write();
#endif

#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
        template<>
        inline void KeyData<std::complex<double> >::write() 
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
#else
template<> void KeyData<std::complex<double> >::write();
#endif

#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
        template <>
        inline ostream & KeyData<std::complex<float> >::put (ostream &s) const
        {
   		using std::setw;
           	s << "Keyword Name: " << name() << " Value: " << m_keyval.real() << " +   i " 
             	  << m_keyval.imag() <<   " Type: " <<  setw(20) << " complex<float> " 
             	  << " Comment: " << comment()   << std::endl;
          return s;
        }
        
        template <>
        inline ostream & KeyData<std::complex<double> >::put (ostream &s) const
        {
   		using std::setw;
           	s << "Keyword Name: " << name() << " Value: " << m_keyval.real() << " +   i " 
             	  << m_keyval.imag() <<   " Type: " <<  setw(20) << " complex<double> " 
             	  << " Comment: " << comment()   << std::endl;

	          return s;
        }
#else
template<> ostream& KeyData<std::complex<float> >::put(ostream& s) const;
template<> ostream& KeyData<std::complex<double> >::put(ostream& s) const;
#endif

#ifdef SPEC_TEMPLATE_DECL_DEFECT
  template  <>
  inline const std::complex<float>& KeyData<std::complex<float> >::keyval() const
  {
    return m_keyval;

  }

  template  <>
  inline void KeyData<std::complex<float> >::keyval(const std::complex<float>&  newVal)
  {
    m_keyval = newVal;

  }

  template  <>
  inline const std::complex<double>& KeyData<std::complex<double> >::keyval() const
  {
    return m_keyval;

  }

  template  <>
  inline void KeyData<std::complex<double> >::keyval(const std::complex<double>&  newVal)
  {
    m_keyval = newVal;

  }

#else
template<> const std::complex<float>&  KeyData<std::complex<float> >::keyval() const;
template<> void KeyData<std::complex<float> >::keyval(const std::complex<float>&  );



template<> const std::complex<double>&  KeyData<std::complex<double> >::keyval() const;
template<> void KeyData<std::complex<double> >::keyval(const std::complex<double>&  );
#endif


  // Parameterized Class CCfits::KeyData 


  template <typename T>
  inline ostream & KeyData<T>::put (ostream &s) const
  {
   s << "Keyword Name: " << name() << "\t Value: " << keyval() << 
     "\t Type: " << keytype() << "\t Comment: " << comment();

  return s;
  }


  template <typename T>
  inline const T& KeyData<T>::keyval () const
  {
    return m_keyval;
  }

  template <typename T>
  inline void KeyData<T>::keyval (const T& value)
  {
    m_keyval = value;
  }

  // Parameterized Class CCfits::KeyData 

  template <typename T>
  KeyData<T>::KeyData(const KeyData<T> &right)
      :Keyword(right),
       m_keyval(right.m_keyval)
  {
  }

  template <typename T>
  KeyData<T>::KeyData (const string &keyname, ValueType keytype, const T &value, HDU* p, const string &comment)
       : Keyword(keyname, keytype, p, comment), 
         m_keyval(value)
  {
  }


  template <typename T>
  KeyData<T>::~KeyData()
  {
  }



  template <typename T>
  void KeyData<T>::copy (const Keyword& right)
  {
  Keyword::copy(right);
  const KeyData<T>& that = static_cast<const KeyData<T>&>(right);
  m_keyval = that.m_keyval;
  }

  template <typename T>
  bool KeyData<T>::compare (const Keyword &right) const
  {
  if ( !Keyword::compare(right) ) return false;
  const KeyData<T>& that = static_cast<const KeyData<T>&>(right);
  if (this->m_keyval != that.m_keyval) return false;
  return true;
  }

  template <typename T>
  KeyData <T>* KeyData<T>::clone () const
  {
  return new KeyData<T>(*this);
  }

  template <typename T>
  void KeyData<T>::write ()
  {
   int status = 0;
   FITSUtil::MatchType<T> keyType;
   if ( fits_update_key(fitsPointer(),keyType(), 
			   const_cast<char *>(name().c_str()),
			   &m_keyval,  // fits_write_key takes a void* here 
			   const_cast<char *>(comment().c_str()), 
			   &status) ) throw FitsError(status);
  }

  // Additional Declarations

} // namespace CCfits



#endif
