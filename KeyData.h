//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3817161C9470.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%3817161C9470.cm

//## begin module%3817161C9470.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%3817161C9470.cp

//## Module: KeyData%3817161C9470; Package specification
//## Subsystem: CCfits::Keyword%3826DF71D818
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/KeyData.h

#ifndef KEYDATA_H
#define KEYDATA_H 1

//## begin module%3817161C9470.additionalIncludes preserve=yes
#ifdef _MSC_VER
#include "MSconfig.h"
#endif

#include "CCfits.h"
//## end module%3817161C9470.additionalIncludes

// Keyword
#include "Keyword.h"
//## begin module%3817161C9470.includes preserve=yes
//## end module%3817161C9470.includes

//## begin module%3817161C9470.declarations preserve=no
//## end module%3817161C9470.declarations

//## begin module%3817161C9470.additionalDeclarations preserve=yes
#include <complex>
#include <iomanip>
#include "FitsError.h"
#include "FITSUtil.h"
//## end module%3817161C9470.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::KeyData%381716BBD3F8.preface preserve=yes
//class Keyword;
  //## end CCfits::KeyData%381716BBD3F8.preface

  //## Class: KeyData%381716BBD3F8; Parameterized Class
  //## Category: CCfits::Keyword%393417BC003C
  //## Subsystem: CCfits::Keyword%3826DF71D818
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n
  //## Space Complexity: T



  template <typename T>
  class KeyData : public Keyword  //## Inherits: <unnamed>%381F43399D58
  {
    //## begin CCfits::KeyData%381716BBD3F8.initialDeclarations preserve=yes
    //## end CCfits::KeyData%381716BBD3F8.initialDeclarations

    public:
      //## Constructors (generated)
        KeyData(const KeyData< T > &right);

      //## Constructors (specified)
        //## Operation: KeyData%38CA72D03278
        KeyData (const String &keyname, ValueType keytype, const T &value, HDU* p, 	// A pointer to the HDU containing the keyword. This is passed to the base class constructor.
        const String &comment = "");

      //## Destructor (generated)
        virtual ~KeyData();


      //## Other Operations (specified)
        //## Operation: clone%3821D3010D70
        virtual KeyData <T>* clone () const;

        //## Operation: write%39357BA80119
        virtual void write ();

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: keyval%3817192022F0
        const T& keyval () const;
        void keyval (const T& value);

      // Additional Public Declarations
        //## begin CCfits::KeyData%381716BBD3F8.public preserve=yes
        //## end CCfits::KeyData%381716BBD3F8.public

    protected:

      //## Other Operations (specified)
        //## Operation: copy%387CD1CF3FF8
        virtual void copy (const Keyword& right);

        //## Operation: compare%38171A5FAF98
        virtual bool compare (const Keyword &right) const;

        //## Operation: put%38D10D920120
        virtual std::ostream & put (std::ostream &s) const;

      // Additional Protected Declarations
        //## begin CCfits::KeyData%381716BBD3F8.protected preserve=yes
        //## end CCfits::KeyData%381716BBD3F8.protected

    private:
      // Data Members for Class Attributes

        //## begin CCfits::KeyData::keyval%3817192022F0.attr preserve=no  public: T {U} 
        T m_keyval;
        //## end CCfits::KeyData::keyval%3817192022F0.attr

      // Additional Private Declarations
        //## begin CCfits::KeyData%381716BBD3F8.private preserve=yes
        //## end CCfits::KeyData%381716BBD3F8.private

    private: //## implementation
      // Additional Implementation Declarations
        //## begin CCfits::KeyData%381716BBD3F8.implementation preserve=yes
        //## end CCfits::KeyData%381716BBD3F8.implementation

  };

  //## begin CCfits::KeyData%381716BBD3F8.postscript preserve=yes
#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
        template<>
        inline void KeyData<String>::write() 
        {
           int status = 0;
           if (fits_update_key(fitsPointer(), Tstring, 
			           const_cast<char *>(name().c_str()),
			           const_cast<char*>(m_keyval.c_str()),
			           const_cast<char *>(comment().c_str()), 
			           &status)) throw FitsError(status);

        }
#else
template<> void KeyData<String>::write();
#endif

#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
        template<>
        inline void KeyData<bool>::write() 
        {
           int status = 0;
           int value(0);
           if (m_keyval) value=1; 
           if (fits_update_key(fitsPointer(), Tlogical, 
			           const_cast<char *>(name().c_str()),
			           &value,
			           const_cast<char *>(comment().c_str()), 
			           &status)) throw FitsError(status);

        }
#else
template<> void KeyData<bool>::write();
#endif

#ifdef SPEC_TEMPLATE_DECL_DEFECT
        template  <>
        inline const String& KeyData<String>::keyval() const
        {
                return m_keyval;

        }
#else
template<> const String& KeyData<String>::keyval() const;
#endif

#ifndef SPEC_TEMPLATE_DECL_DEFECT
template<> void KeyData<String>::keyval(const String& );
#endif

#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
        template <>
        inline std::ostream & KeyData<String>::put (std::ostream &s) const
        {
   		using std::setw;
   		s << "Keyword Name: " << setw(10) << name() << "  Value: " << setw(14) 
                  << keyval() << " Type: " << setw(20) << " string "  << " Comment: " << comment();
          return s;
        }

#else
template<> std::ostream& KeyData<String>::put(std::ostream& s) const;
#endif


#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
        template <>
        inline std::ostream & KeyData<bool>::put (std::ostream &s) const
        {
   		using std::setw;
   		s << "Keyword Name: " << setw(10) << name() 
                  << "  Value: " << std::boolalpha  << setw(8) << keyval() 
                  << "  Type: " << setw(20) << " logical "  << " Comment: " << comment();
          return s;
        }

#else
template<> std::ostream& KeyData<bool>::put(std::ostream& s) const;
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
        inline std::ostream & KeyData<std::complex<float> >::put (std::ostream &s) const
        {
   		using std::setw;
           	s << "Keyword Name: " << name() << " Value: " << m_keyval.real() << " +   i " 
             	  << m_keyval.imag() <<   " Type: " <<  setw(20) << " complex<float> " 
             	  << " Comment: " << comment()   << std::endl;
          return s;
        }
        
        template <>
        inline std::ostream & KeyData<std::complex<double> >::put (std::ostream &s) const
        {
   		using std::setw;
           	s << "Keyword Name: " << name() << " Value: " << m_keyval.real() << " +   i " 
             	  << m_keyval.imag() <<   " Type: " <<  setw(20) << " complex<double> " 
             	  << " Comment: " << comment()   << std::endl;

	          return s;
        }
#else
template<> std::ostream& KeyData<std::complex<float> >::put(std::ostream& s) const;
template<> std::ostream& KeyData<std::complex<double> >::put(std::ostream& s) const;
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

  //## end CCfits::KeyData%381716BBD3F8.postscript

  // Parameterized Class CCfits::KeyData 


  //## Other Operations (inline)
  template <typename T>
  inline std::ostream & KeyData<T>::put (std::ostream &s) const
  {
    //## begin CCfits::KeyData::put%38D10D920120.body preserve=yes
   s << "Keyword Name: " << name() << "\t Value: " << keyval() << 
     "\t Type: " << keytype() << "\t Comment: " << comment();

  return s;
    //## end CCfits::KeyData::put%38D10D920120.body
  }

  //## Get and Set Operations for Class Attributes (inline)

  template <typename T>
  inline const T& KeyData<T>::keyval () const
  {
    //## begin CCfits::KeyData::keyval%3817192022F0.get preserve=no
    return m_keyval;
    //## end CCfits::KeyData::keyval%3817192022F0.get
  }

  template <typename T>
  inline void KeyData<T>::keyval (const T& value)
  {
    //## begin CCfits::KeyData::keyval%3817192022F0.set preserve=no
    m_keyval = value;
    //## end CCfits::KeyData::keyval%3817192022F0.set
  }

  // Parameterized Class CCfits::KeyData 

  template <typename T>
  KeyData<T>::KeyData(const KeyData<T> &right)
    //## begin KeyData::KeyData%381716BBD3F8_copy.hasinit preserve=no
    //## end KeyData::KeyData%381716BBD3F8_copy.hasinit
    //## begin KeyData::KeyData%381716BBD3F8_copy.initialization preserve=yes
      :Keyword(right),
       m_keyval(right.m_keyval)
    //## end KeyData::KeyData%381716BBD3F8_copy.initialization
  {
    //## begin CCfits::KeyData::KeyData%381716BBD3F8_copy.body preserve=yes
    //## end CCfits::KeyData::KeyData%381716BBD3F8_copy.body
  }

  template <typename T>
  KeyData<T>::KeyData (const String &keyname, ValueType keytype, const T &value, HDU* p, const String &comment)
    //## begin CCfits::KeyData::KeyData%38CA72D03278.hasinit preserve=no
    //## end CCfits::KeyData::KeyData%38CA72D03278.hasinit
    //## begin CCfits::KeyData::KeyData%38CA72D03278.initialization preserve=yes
       : Keyword(keyname, keytype, p, comment), 
         m_keyval(value)
    //## end CCfits::KeyData::KeyData%38CA72D03278.initialization
  {
    //## begin CCfits::KeyData::KeyData%38CA72D03278.body preserve=yes
    //## end CCfits::KeyData::KeyData%38CA72D03278.body
  }


  template <typename T>
  KeyData<T>::~KeyData()
  {
    //## begin CCfits::KeyData::~KeyData%381716BBD3F8_dest.body preserve=yes
    //## end CCfits::KeyData::~KeyData%381716BBD3F8_dest.body
  }



  //## Other Operations (implementation)
  template <typename T>
  void KeyData<T>::copy (const Keyword& right)
  {
    //## begin CCfits::KeyData::copy%387CD1CF3FF8.body preserve=yes
  Keyword::copy(right);
  const KeyData<T>& that = static_cast<const KeyData<T>&>(right);
  m_keyval = that.m_keyval;
    //## end CCfits::KeyData::copy%387CD1CF3FF8.body
  }

  template <typename T>
  bool KeyData<T>::compare (const Keyword &right) const
  {
    //## begin CCfits::KeyData::compare%38171A5FAF98.body preserve=yes
  if ( !Keyword::compare(right) ) return false;
  const KeyData<T>& that = static_cast<const KeyData<T>&>(right);
  if (this->m_keyval != that.m_keyval) return false;
  return true;
    //## end CCfits::KeyData::compare%38171A5FAF98.body
  }

  template <typename T>
  KeyData <T>* KeyData<T>::clone () const
  {
    //## begin CCfits::KeyData::clone%3821D3010D70.body preserve=yes
  return new KeyData<T>(*this);
    //## end CCfits::KeyData::clone%3821D3010D70.body
  }

  template <typename T>
  void KeyData<T>::write ()
  {
    //## begin CCfits::KeyData::write%39357BA80119.body preserve=yes
   int status = 0;
   FITSUtil::MatchType<T> keyType;
   if ( fits_update_key(fitsPointer(),keyType(), 
			   const_cast<char *>(name().c_str()),
			   &m_keyval,  // fits_write_key takes a void* here 
			   const_cast<char *>(comment().c_str()), 
			   &status) ) throw FitsError(status);
    //## end CCfits::KeyData::write%39357BA80119.body
  }

  // Additional Declarations
    //## begin CCfits::KeyData%381716BBD3F8.declarations preserve=yes
    //## end CCfits::KeyData%381716BBD3F8.declarations

} // namespace CCfits

//## begin module%3817161C9470.epilog preserve=yes
//## end module%3817161C9470.epilog


#endif
