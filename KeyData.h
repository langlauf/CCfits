
//	This is CCfits version 1.0-beta

//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov


#ifndef KEYDATA_H
#define KEYDATA_H 1

#include "CCfits.h"


// Keyword
#include "Keyword.h"

#include <complex>
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

template<> void KeyData<string>::write();
template<> const string& KeyData<string>::keyval() const;
template<> void KeyData<string>::keyval(const string& );
template<> ostream& KeyData<string>::put(ostream& s) const;

template<> void KeyData<std::complex<float> >::write();
template<> ostream& KeyData<std::complex<float> >::put(ostream& s) const;
template<> const std::complex<float>&  KeyData<std::complex<float> >::keyval() const;
template<> void KeyData<std::complex<float> >::keyval(const std::complex<float>&  );


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
