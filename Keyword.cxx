//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3803537BD3E0.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%3803537BD3E0.cm

//## begin module%3803537BD3E0.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%3803537BD3E0.cp

//## Module: Keyword%3803537BD3E0; Package body
//## Subsystem: CCfits::Keyword%3826DF71D818
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/Keyword.cxx

//## begin module%3803537BD3E0.additionalIncludes preserve=no
#include <iosfwd>
//## end module%3803537BD3E0.additionalIncludes

//## begin module%3803537BD3E0.includes preserve=yes
//## end module%3803537BD3E0.includes

// FitsError
#include "FitsError.h"
// HDU
#include "HDU.h"
// Keyword
#include "Keyword.h"
// FITS
#include "FITS.h"


//## begin module%3803537BD3E0.declarations preserve=no
//## end module%3803537BD3E0.declarations

//## begin module%3803537BD3E0.additionalDeclarations preserve=yes
#include "KeyData.h"
//## end module%3803537BD3E0.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  // Class CCfits::Keyword::WrongKeywordValueType 

  Keyword::WrongKeywordValueType::WrongKeywordValueType (const String& diag, bool silent)
    //## begin CCfits::Keyword::WrongKeywordValueType::WrongKeywordValueType%39B02294016C.hasinit preserve=yes
  : FitsException("Error: attempt to read keyword into variable of incorrect type",silent) 
    //## end CCfits::Keyword::WrongKeywordValueType::WrongKeywordValueType%39B02294016C.hasinit
    //## begin CCfits::Keyword::WrongKeywordValueType::WrongKeywordValueType%39B02294016C.initialization preserve=yes
    //## end CCfits::Keyword::WrongKeywordValueType::WrongKeywordValueType%39B02294016C.initialization
  {
    //## begin CCfits::Keyword::WrongKeywordValueType::WrongKeywordValueType%39B02294016C.body preserve=yes
  if ( FITS::verboseMode() || !silent) std::cerr << "\nKeyname:" << diag << "\n";
    //## end CCfits::Keyword::WrongKeywordValueType::WrongKeywordValueType%39B02294016C.body
  }


  // Class CCfits::Keyword 

  Keyword::Keyword(const Keyword &right)
    //## begin Keyword::Keyword%380395442F18_copy.hasinit preserve=yes
	: m_keytype(right.m_keytype),
        m_parent(right.m_parent),
	m_comment(right.m_comment),
        m_name(right.m_name)
    //## end Keyword::Keyword%380395442F18_copy.hasinit
    //## begin Keyword::Keyword%380395442F18_copy.initialization preserve=yes
    //## end Keyword::Keyword%380395442F18_copy.initialization
  {
    //## begin CCfits::Keyword::Keyword%380395442F18_copy.body preserve=yes
    //## end CCfits::Keyword::Keyword%380395442F18_copy.body
  }

  Keyword::Keyword (const String &keyname, ValueType keytype, HDU* p, const String &comment)
    //## begin CCfits::Keyword::Keyword%38C94E345C88.hasinit preserve=yes
	: m_keytype(keytype),
        m_parent(p),
	m_comment(comment),
        m_name(keyname)
    //## end CCfits::Keyword::Keyword%38C94E345C88.hasinit
    //## begin CCfits::Keyword::Keyword%38C94E345C88.initialization preserve=yes
    //## end CCfits::Keyword::Keyword%38C94E345C88.initialization
  {
    //## begin CCfits::Keyword::Keyword%38C94E345C88.body preserve=yes
    //## end CCfits::Keyword::Keyword%38C94E345C88.body
  }


  Keyword::~Keyword()
  {
    //## begin CCfits::Keyword::~Keyword%380395442F18_dest.body preserve=yes
    //## end CCfits::Keyword::~Keyword%380395442F18_dest.body
  }


  Keyword & Keyword::operator=(const Keyword &right)
  {
    //## begin CCfits::Keyword::operator=%380395442F18_assign.body preserve=yes
   if (this == &right) copy(right);
   return *this;
    //## end CCfits::Keyword::operator=%380395442F18_assign.body
  }


  bool Keyword::operator==(const Keyword &right) const
  {
    //## begin CCfits::Keyword::operator==%380395442F18_eq.body preserve=yes
   return compare(right);
    //## end CCfits::Keyword::operator==%380395442F18_eq.body
  }

  bool Keyword::operator!=(const Keyword &right) const
  {
    //## begin CCfits::Keyword::operator!=%380395442F18_neq.body preserve=yes
  return !compare(right);
    //## end CCfits::Keyword::operator!=%380395442F18_neq.body
  }



  //## Other Operations (implementation)
  void Keyword::copy (const Keyword& right)
  {
    //## begin CCfits::Keyword::copy%3817134AE9B8.body preserve=yes
  m_name = right.m_name;
  m_comment = right.m_comment;
  m_keytype  = right.m_keytype;
  m_parent  = right.m_parent;
    //## end CCfits::Keyword::copy%3817134AE9B8.body
  }

  bool Keyword::compare (const Keyword &right) const
  {
    //## begin CCfits::Keyword::compare%381713530558.body preserve=yes
  if (m_name != right.m_name) return false;
  if (m_keytype != right.m_keytype) return false;
  if (m_comment != right.m_comment) return false;
  if (m_parent  != right.m_parent) return false;
  return true;
    //## end CCfits::Keyword::compare%381713530558.body
  }

  fitsfile* Keyword::fitsPointer () const
  {
    //## begin CCfits::Keyword::fitsPointer%3937EE10016A.body preserve=yes
    //## end CCfits::Keyword::fitsPointer%3937EE10016A.body

    return m_parent->fitsPointer();
  }

  // Additional Declarations
    //## begin CCfits::Keyword%380395442F18.declarations preserve=yes
    //## end CCfits::Keyword%380395442F18.declarations

} // namespace CCfits

//## begin module%3803537BD3E0.epilog preserve=yes
namespace CCfits
{
#ifndef SPEC_TEMPLATE_IMP_DEFECT
#ifndef SPEC_TEMPLATE_DECL_DEFECT
   template<>
   float& Keyword::value(float& val) const
   {
      double dval=.0;
      val = static_cast<float>(value(dval));
      return val;
   }
   
   template<>
   double& Keyword::value(double& val) const
   {
      switch (m_keytype)
      {
         case Tint:
            {
               const KeyData<int>& thisKey = static_cast<const KeyData<int>&>(*this);
               val = thisKey.keyval();
            }
            break;
         case Tfloat:
            {
               const KeyData<float>& thisKey = static_cast<const KeyData<float>&>(*this);
               val = thisKey.keyval();
            }
            break;
         case Tdouble:
            {
               // Note: if val is of type float some precision will be lost here,
               // but allow anyway.  Presumably the user doesn't mind or they
               // wouldn't be using single precision.
               const KeyData<double>& thisKey = static_cast<const KeyData<double>&>(*this);
               val = thisKey.keyval();
            }
            break;
         case Tstring:
            {
               // Allow only if string can be converted to an integer.
               const KeyData<String>& thisKey = static_cast<const KeyData<String>&>(*this); 
               std::istringstream testStream(thisKey.keyval());
               int stringInt = 0;
               if (!(testStream >> stringInt) || !testStream.eof())
               {
                  throw Keyword::WrongKeywordValueType(name());
               }
               val = stringInt;
            }
            break;
         default:
            throw Keyword::WrongKeywordValueType(name());
            break;
      }
      return val;
   }
   
   template <>
   int& Keyword::value(int& val) const
   {
         if (m_keytype == Tstring)
         {
            // Allow only if string can be converted to an integer.
            const KeyData<String>& thisKey = static_cast<const KeyData<String>&>(*this); 
            std::istringstream testStream(thisKey.keyval());
            int stringInt = 0;
            if (!(testStream >> stringInt) || !testStream.eof())
            {
               throw Keyword::WrongKeywordValueType(name());
            }
            val = stringInt;         
         } 
         else if (m_keytype == Tint)
         {
            const KeyData<int>& thisKey = static_cast<const KeyData<int>&>(*this);
            val = thisKey.keyval();
         } 
         else
         {
            throw Keyword::WrongKeywordValueType(name());
         }
         return val;    
   }
#endif
#endif
}
//## end module%3803537BD3E0.epilog
