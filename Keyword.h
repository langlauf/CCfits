
//	This is version 1.2 release dated April 2003

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	April 2003 Ben Dorman, L3-Communications EER Systems Inc.
//	e-mail: ccfits@legacy.gsfc.nasa.gov


#ifndef KEYWORD_H
#define KEYWORD_H 1

#include "CCfits.h"
using namespace CCfits;

// string
#include <string>
// FitsError
#include "FitsError.h"

namespace CCfits {
  class HDU;

} // namespace CCfits



using std::string;
using std::ostream;


namespace CCfits {

/*! \class Keyword

        \brief Abstract base class implementing the common behavior of Keyword objects.
        
        Keywords consists of a name, a value and a comment field. Concrete templated
        subclasses, KeyData<T>,  have a data member that holds the value of keyword.
        
        Typically, the mandatory keywords for a given HDU type are not stored as
        object of type Keyword, but as intrinsic data types. The Keyword hierarchy
        is used to store user-supplied information.
                        
*/


/*! \fn Keyword::Keyword(const Keyword &right);
      
      \brief copy constructor
      
*/


/*!  \fn Keyword::Keyword (const string &keyname, ValueType keytype, HDU* p, const string &comment = "");

      \brief Keyword constructor. 
      
      This is the common behavior of Keywords of any type. Constructor is protected 
      as the class is abstract.

*/
      
/* \fn friend ostream& operator << (ostream &s, const Keyword &right);

        \brief output operator for Keywords.
      
*/

/*!   \fn virtual Keyword::~Keyword();
      
      \brief virtual destructor

*/

/*!    \fn Keyword & Keyword::operator=(const Keyword &right);
      
      \brief assignment operator

*/

/*!    \fn bool Keyword::operator==(const Keyword &right) const;

        \brief equality operator

*/

/*!       \fn bool Keyword::operator!=(const Keyword &right) const;


        \brief inequality operator

*/


/*!       \fn virtual Keyword * Keyword::clone () const;

        \brief virtual copy constructor
*/

/*!       \fn virtual void Keyword::write ();

        \brief write operation
*/


/*!   \fn       fitsfile* Keyword::fitsPointer () const;

        \brief return a pointer to the FITS file containing the parent HDU.

*/


/*!    \fn      const HDU* Keyword::parent () const;

        \brief return a pointer to parent HDU.

*/

/*!    \fn      const std::string& Keyword::comment () const;

        \brief return the comment field of the keyword

*/
 

/*! \fn  const ValueType Keyword::keytype() const

     \brief return the type of a keyword


*/


/*! \fn  void  Keyword::keytype(ValueType)

      \brief  set keyword type.


*/


/*! \fn  const std::string& Keyword::name() const

        return the name of a keyword


*/







  class Keyword 
  {

    public:



      class WrongKeywordValueType : public FitsException  //## Inherits: <unnamed>%39B0221700E2
      {
        public:
            WrongKeywordValueType (const string& diag, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

        Keyword(const Keyword &right);

        Keyword (const string &keyname, ValueType keytype, HDU* p, const string &comment = "");

        virtual ~Keyword();

        Keyword & operator=(const Keyword &right);

        bool operator==(const Keyword &right) const;

        bool operator!=(const Keyword &right) const;


        virtual ostream & put (ostream &s) const = 0;

        virtual Keyword * clone () const = 0;

        virtual void write () = 0;

        fitsfile* fitsPointer () const;


        const std::string& name () const;

        const std::string& comment () const;

    public:
      // Additional Public Declarations
      template <typename T>
      T& value(T& val) const;
      
      template <typename T>
      void setValue(const T& newValue);
    protected:

        virtual void copy (const Keyword& right);

        virtual bool compare (const Keyword &right) const;


        ValueType keytype () const;
        void keytype (ValueType value);


        const HDU* parent () const;

      // Additional Protected Declarations

    private:
      // Additional Private Declarations

    private: //## implementation
      // Data Members for Class Attributes

        ValueType m_keytype;

      // Data Members for Associations

        HDU* m_parent;

        std::string m_name;

        std::string m_comment;

      // Additional Implementation Declarations
      friend ostream &operator << (ostream &s, const Keyword &right);
      
  };

inline ostream& operator << (ostream &s, const Keyword &right)
{
   return right.put(s);
}  

  // Class CCfits::Keyword::WrongKeywordValueType 

  // Class CCfits::Keyword 


  inline ValueType Keyword::keytype () const
  {
    return m_keytype;
  }

  inline void Keyword::keytype (ValueType value)
  {
    m_keytype = value;
  }


  inline const HDU* Keyword::parent () const
  {
    return m_parent;
  }

  inline const std::string& Keyword::name () const
  {
    return m_name;
  }

  inline const std::string& Keyword::comment () const
  {
    return m_comment;
  }

} // namespace CCfits



#endif
