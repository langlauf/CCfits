//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%380353775EB0.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%380353775EB0.cm

//## begin module%380353775EB0.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%380353775EB0.cp

//## Module: Keyword%380353775EB0; Package specification
//## Subsystem: CCfits::Keyword%3826DF71D818
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/Keyword.h

#ifndef KEYWORD_H
#define KEYWORD_H 1

//## begin module%380353775EB0.additionalIncludes preserve=yes
#include "CCfits.h"
// using namespace CCfits;
//## end module%380353775EB0.additionalIncludes

// FitsError
#include "FitsError.h"

namespace CCfits {
  class HDU;

} // namespace CCfits

//## begin module%380353775EB0.includes preserve=yes
//## end module%380353775EB0.includes

//## begin module%380353775EB0.declarations preserve=no
//## end module%380353775EB0.declarations

//## begin module%380353775EB0.additionalDeclarations preserve=yes
//## end module%380353775EB0.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes

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


/*!  \fn Keyword::Keyword (const String &keyname, ValueType keytype, HDU* p, const String &comment = "");

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

/*!    \fn      const String& Keyword::comment () const;

        \brief return the comment field of the keyword

*/
 

/*! \fn  const ValueType Keyword::keytype() const

     \brief return the type of a keyword


*/


/*! \fn  void  Keyword::keytype(ValueType)

      \brief  set keyword type.


*/


/*! \fn  const String& Keyword::name() const

        return the name of a keyword


*/

  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::Keyword%380395442F18.preface preserve=yes
  //## end CCfits::Keyword%380395442F18.preface

  //## Class: Keyword%380395442F18
  //## Category: CCfits::Keyword%393417BC003C
  //## Subsystem: CCfits::Keyword%3826DF71D818
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%39B5624B011D;FitsException { -> F}
  //## Uses: <unnamed>%3EEF857D03D0;String { -> }

  class Keyword 
  {
    //## begin CCfits::Keyword%380395442F18.initialDeclarations preserve=yes
    //## end CCfits::Keyword%380395442F18.initialDeclarations

    public:
      //## Class: WrongKeywordValueType%39B021AF02BE
      //## Category: CCfits::Keyword%393417BC003C
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class WrongKeywordValueType : public FitsException  //## Inherits: <unnamed>%39B0221700E2
      {
        public:
          //## Constructors (specified)
            //## Operation: WrongKeywordValueType%39B02294016C
            WrongKeywordValueType (const String& diag, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Constructors (generated)
        Keyword(const Keyword &right);

      //## Constructors (specified)
        //## Operation: Keyword%38C94E345C88
        Keyword (const String &keyname, ValueType keytype, HDU* p, const String &comment = "");

      //## Destructor (generated)
        virtual ~Keyword();

      //## Assignment Operation (generated)
        Keyword & operator=(const Keyword &right);

      //## Equality Operations (generated)
        bool operator==(const Keyword &right) const;

        bool operator!=(const Keyword &right) const;


      //## Other Operations (specified)
        //## Operation: put%38D1212DC588
        virtual std::ostream & put (std::ostream &s) const = 0;

        //## Operation: clone%3821D2C6C7D0
        virtual Keyword * clone () const = 0;

        //## Operation: write%39357B490339
        virtual void write () = 0;

        //## Operation: fitsPointer%3937EE10016A
        fitsfile* fitsPointer () const;

      //## Get and Set Operations for Associations (generated)

        //## Association: CCfits::HDU::<unnamed>%3EEF85800221
        //## Role: Keyword::comment%3EEF85800222
        const String& comment () const;

        //## Association: CCfits::HDU::<unnamed>%3EEF85840235
        //## Role: Keyword::name%3EEF85840236
        const String& name () const;

    public:
      // Additional Public Declarations
        //## begin CCfits::Keyword%380395442F18.public preserve=yes
      template <typename T>
      T& value(T& val) const;
      
      template <typename T>
      void setValue(const T& newValue);
        //## end CCfits::Keyword%380395442F18.public
    protected:

      //## Other Operations (specified)
        //## Operation: copy%3817134AE9B8
        virtual void copy (const Keyword& right);

        //## Operation: compare%381713530558
        virtual bool compare (const Keyword &right) const;

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: keytype%3817107B0D58
        ValueType keytype () const;
        void keytype (ValueType value);

      //## Get and Set Operations for Associations (generated)

        //## Association: CCfits::<unnamed>%3803955F7650
        //## Role: Keyword::parent%3803956030E8
        const HDU* parent () const;

      // Additional Protected Declarations
        //## begin CCfits::Keyword%380395442F18.protected preserve=yes
        //## end CCfits::Keyword%380395442F18.protected

    private:
      // Additional Private Declarations
        //## begin CCfits::Keyword%380395442F18.private preserve=yes
        //## end CCfits::Keyword%380395442F18.private

    private: //## implementation
      // Data Members for Class Attributes

        //## begin CCfits::Keyword::keytype%3817107B0D58.attr preserve=no  protected: ValueType {U} Tnull
        ValueType m_keytype;
        //## end CCfits::Keyword::keytype%3817107B0D58.attr

      // Data Members for Associations

        //## Association: CCfits::<unnamed>%3803955F7650
        //## begin CCfits::Keyword::parent%3803956030E8.role preserve=no  protected: CCfits::HDU {1..1 -> 1..nRFHGN}
        HDU* m_parent;
        //## end CCfits::Keyword::parent%3803956030E8.role

        //## Association: CCfits::HDU::<unnamed>%3EEF85800221
        //## begin CCfits::Keyword::comment%3EEF85800222.role preserve=no  public: CCfits::String { -> 1..1VHgN}
        String m_comment;
        //## end CCfits::Keyword::comment%3EEF85800222.role

        //## Association: CCfits::HDU::<unnamed>%3EEF85840235
        //## begin CCfits::Keyword::name%3EEF85840236.role preserve=no  public: CCfits::String { -> 1..1VHgN}
        String m_name;
        //## end CCfits::Keyword::name%3EEF85840236.role

      // Additional Implementation Declarations
        //## begin CCfits::Keyword%380395442F18.implementation preserve=yes
      friend std::ostream &operator << (std::ostream &s, const Keyword &right);
      
        //## end CCfits::Keyword%380395442F18.implementation
  };

  //## begin CCfits::Keyword%380395442F18.postscript preserve=yes
inline std::ostream& operator << (std::ostream &s, const Keyword &right)
{
   return right.put(s);
}  
  //## end CCfits::Keyword%380395442F18.postscript

  // Class CCfits::Keyword::WrongKeywordValueType 

  // Class CCfits::Keyword 

  //## Get and Set Operations for Class Attributes (inline)

  inline ValueType Keyword::keytype () const
  {
    //## begin CCfits::Keyword::keytype%3817107B0D58.get preserve=no
    return m_keytype;
    //## end CCfits::Keyword::keytype%3817107B0D58.get
  }

  inline void Keyword::keytype (ValueType value)
  {
    //## begin CCfits::Keyword::keytype%3817107B0D58.set preserve=no
    m_keytype = value;
    //## end CCfits::Keyword::keytype%3817107B0D58.set
  }

  //## Get and Set Operations for Associations (inline)

  inline const HDU* Keyword::parent () const
  {
    //## begin CCfits::Keyword::parent%3803956030E8.get preserve=no
    return m_parent;
    //## end CCfits::Keyword::parent%3803956030E8.get
  }

  inline const String& Keyword::comment () const
  {
    //## begin CCfits::Keyword::comment%3EEF85800222.get preserve=no
    return m_comment;
    //## end CCfits::Keyword::comment%3EEF85800222.get
  }

  inline const String& Keyword::name () const
  {
    //## begin CCfits::Keyword::name%3EEF85840236.get preserve=no
    return m_name;
    //## end CCfits::Keyword::name%3EEF85840236.get
  }

} // namespace CCfits

//## begin module%380353775EB0.epilog preserve=yes
//## end module%380353775EB0.epilog


#endif
