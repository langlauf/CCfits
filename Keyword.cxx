
//	This is version 1.1.1 release dated Sept 2002

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	Sept 2002 Ben Dorman, L3-Communications
//	e-mail: ccfits@legacy.gsfc.nasa.gov


#include <iosfwd>


// FitsError
#include "FitsError.h"
// HDU
#include "HDU.h"
// Keyword
#include "Keyword.h"
// FITS
#include "FITS.h"





namespace CCfits {

  // Class CCfits::Keyword::WrongKeywordValueType 

  Keyword::WrongKeywordValueType::WrongKeywordValueType (const string& diag, bool silent)
  : FitsException("Error: attempt to read keyword into variable of incorrect type",silent) 
  {
  if ( FITS::verboseMode() || !silent) std::cerr << "\nKeyname:" << diag << "\n";
  }


  // Class CCfits::Keyword 

  Keyword::Keyword(const Keyword &right)
	: m_keytype(right.m_keytype),
        m_parent(right.m_parent),
        m_name(right.m_name),
	m_comment(right.m_comment)
  {
  }

  Keyword::Keyword (const string &keyname, ValueType keytype, HDU* p, const string &comment)
	: m_keytype(keytype),
        m_parent(p),
        m_name(keyname),
	m_comment(comment)
  {
  }


  Keyword::~Keyword()
  {
  }


  Keyword & Keyword::operator=(const Keyword &right)
  {
   if (this == &right) copy(right);
   return *this;
  }


  bool Keyword::operator==(const Keyword &right) const
  {
   return compare(right);
  }

  bool Keyword::operator!=(const Keyword &right) const
  {
  return !compare(right);
  }



  void Keyword::copy (const Keyword& right)
  {
  m_name = right.m_name;
  m_comment = right.m_comment;
  m_keytype  = right.m_keytype;
  m_parent  = right.m_parent;
  }

  bool Keyword::compare (const Keyword &right) const
  {
  if (m_name != right.m_name) return false;
  if (m_keytype != right.m_keytype) return false;
  if (m_comment != right.m_comment) return false;
  if (m_parent  != right.m_parent) return false;
  return true;
  }

  fitsfile* Keyword::fitsPointer () const
  {

    return m_parent->fitsPointer();
  }

  // Additional Declarations

} // namespace CCfits

