
//	This is version 1.1.1 release dated Sept 2002

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	Sept 2002 Ben Dorman, L3-Communications
//	e-mail: ccfits@legacy.gsfc.nasa.gov

#ifndef KEYWORDT_H
#define KEYWORDT_H
#include "KeyData.h"
#include "HDU.h"
#include <typeinfo>

// contains definitions of templated member functions for Keyword. This separate
// file organization is necessary to break cyclic dependency of Keyword on its
// subclass, KeyData.


namespace CCfits 
{

        template <typename T>
        T& Keyword::value (T& val) const
        {
                try
                {
                        // downcast. Exact type match is required: this should
                        // be smoothed out to allow implicit casting.
                        const KeyData<T>& thisKey = dynamic_cast<const KeyData<T>&>(*this);
		        val = thisKey.keyval();
                        return val;
                }
                catch (std::bad_cast)
                {
                        throw Keyword::WrongKeywordValueType(name());
                }

        }

        template <typename T>
        void Keyword::setValue (const T& newValue)
        {
                try
                {
                        KeyData<T>& thisKey = dynamic_cast<KeyData<T>&>(*this);
		        thisKey.keyval(newValue);
                }
                catch (std::bad_cast)
                {
                        throw Keyword::WrongKeywordValueType(name());
                }

        }
        
} // namespace CCfits

#endif
