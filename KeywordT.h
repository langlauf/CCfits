//1
//2
//3
//4

//	This is version 1.3 dated Feb 2005

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.

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
                        // Exact type match is required, through use of dynamic_cast.
                        // One exception (so far) is for case of converting ints
                        // to floats or doubles.
                        if ((typeid(val) == typeid(float) || typeid(val) == typeid(double)) 
                           && typeid(*this) == typeid(KeyData<int>))
                        {
                           const KeyData<int>& thisKey = static_cast<const KeyData<int>&>(*this);
                           val = thisKey.keyval();
                           return val;
                        }
                        else
                        {
                           const KeyData<T>& thisKey = dynamic_cast<const KeyData<T>&>(*this);
		           val = thisKey.keyval();
                           return val;
                        }
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
