
//	This is CCfits version 1.0-beta release August 2001
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov
#ifndef FITSUTILT_H
#define FITSUTILT_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "FITSUtil.h"

#include<typeinfo>
#include<iostream>

#ifdef HAVE_STRSTREAM
#include <strstream>
#else
#include<sstream>
#endif

namespace CCfits
{

        namespace FITSUtil
        {

                // vector to vector: specialize to restrict complex operations.

	        template <typename S, typename T> 
	        void 
	        fill(std::vector<S>& outArray, const std::vector<T>& inArray, size_t first, size_t last)
	        {
       		        // vector to vector assign. stdlib takes care of deletion.
                        int range = last - first + 1;
                        if (outArray.size() != static_cast<size_t>(range)) outArray.resize(range);
                        for (size_t j = first - 1; j < last; ++j)
                        {
                                outArray[j - first + 1] = static_cast<const S>(inArray[j]);
                        }
	        }  

                template <typename S, typename T>
                void fill(std::vector<S>& outArray, const std::vector<std::complex<T> >& inArray, size_t first, size_t last)

	        {
                        first = 0;
                        last  = 0;
                        throw InvalidConversion(errorMessage(outArray,inArray),false);
	        }  


	        template <typename S, typename T> 
	        void 
	        fill(std::vector<std::complex<S> >& outArray, const std::vector<T>& inArray, size_t first, size_t last)
	        {
                        first = 0;
                        last  = 0;
                        throw InvalidConversion(errorMessage(outArray,inArray),false);

	        }  


	        template <typename S, typename T> 
	        void 
	        fill(std::vector<std::complex<S> >& outArray, const std::vector<std::complex<T> >& inArray, size_t first, size_t last)
	        {
       		        // vector to vector assign. stdlib takes care of deletion.
                        int range = last - first + 1;
                        if (outArray.size() != range) outArray.resize(range);
                        for (size_t j = first - 1; j < last; ++j)
                        {
                                outArray[j] = static_cast<const std::complex<S> >(inArray[j]);
                        }
	        }  

                // throw exceptions for string conversions to anything other than string.


	        template <typename T> 
	        void 
	        fill(std::vector<string>& outArray, const std::vector<T>& inArray, size_t first, size_t last)
	        {
                        first = 0;
                        last  = 0;
                        throw InvalidConversion(errorMessage(outArray,inArray),false);

	        } 

 	        template <typename T> 
	        void fill(std::vector<T>& outArray, const std::vector<string>& inArray, size_t first, size_t last)
	        {
                        first = 0;
                        last  = 0;
                        throw InvalidConversion(errorMessage(outArray,inArray),false);
	        }  


                // vector to valarray conversion. Same problem with complex.

	        template <typename S, typename T> 
	        void fill(std::valarray<S>& outArray, const std::vector<T>& inArray, size_t first, size_t last)
	        {
     		        // vector to valarray assign
     		        int range = last - first + 1;
     		        if (outArray.size() != range) outArray.resize(range); 
                        for (size_t j = first - 1; j < last; ++j)
                        {
                                outArray[j - first + 1] = static_cast<const S>(inArray[j]);
                        }
	        }

	        template <typename S, typename T> 
	        void 
	        fill(std::valarray<std::complex<S> >& outArray, const std::vector<T>& inArray, size_t first, size_t last)
	        {
                        first = 0;
                        last  = 0;
                        throw InvalidConversion(errorMessage(outArray,inArray),false);

	        }  

 	        template <typename S, typename T> 
	        void 
	        fill(std::valarray<S>& outArray, const std::vector<std::complex<T> >& inArray, size_t first, size_t last)
	        {
                        first = 0;
                        last  = 0;
                        throw InvalidConversion(errorMessage(outArray,inArray),false);

	        }  

	        template <typename S, typename T> 
	        void fill(std::valarray<std::complex<S> >& outArray, const std::vector<std::complex<T> >& inArray)
	        {
                         size_t n = inArray.size();
       		         if (outArray.size() !=  n) outArray.resize(n);
                         std::copy(inArray.begin(),inArray.end(),&outArray[0]);
                         for (size_t j = 0; j < n; ++j)
                         {
                                 outArray[j] = static_cast<const std::complex<S> >(inArray[j]);
                         }
                }


                // valarray to valarray conversion.


	        template <typename S, typename T> 
	        void fill(std::valarray<S>& outArray, const std::valarray<T>& inArray)
	        {
                         size_t n = inArray.size();
       		         if (outArray.size() !=  n) outArray.resize(n);           
                         for (size_t j = 0;j < n; ++j) outArray[j] 
                                 = static_cast<const S>(inArray[j]);
	        }

	        template <typename S, typename T> 
	        void 
	        fill(std::valarray<std::complex<S> >& outArray, const std::valarray<T>& inArray)
	        {
                        throw InvalidConversion(errorMessage(outArray,inArray),false);

	        }  

 	        template <typename S, typename T> 
	        void 
	        fill(std::valarray<S>& outArray, const std::valarray<std::complex<T> >& inArray)
	        {
                        throw InvalidConversion(errorMessage(outArray,inArray),false);
	        }  

	        template <typename S, typename T> 
	        void fill(std::valarray<std::complex<S> >& outArray, const std::valarray<std::complex<T> >& inArray)
	        {
                         size_t n = inArray.size();
       		         if (outArray.size() !=  n) outArray.resize(n);
                         std::copy(&inArray[0],&inArray[n],&outArray[0]);
                         for (size_t j = 0; j < n; ++j)
                         {
                                 outArray[j] = static_cast<const std::complex<S> >(inArray[j]);
                         }

                }

                template<typename S, typename T>
                string errorMessage( const S& out, const T& in)
                {
        #ifdef HAVE_STRSTREAM
	                std::ostrstream errMsg;
        #else
                        std::ostringstream errMsg;
        #endif
                        errMsg << " Error: no conversion from " << typeid(in).name() << " to "
                               << typeid(out).name() << std::endl;
                        return errMsg.str();

                }

        }


        // partial specializations for complex numbers //
        /*  
          template <class T> class complex<T>
          T* FITSUtil::Carray<complex<T> >::operator() 
                          (const std::vector<complex<T> >& inArray); 

          template <class T> class complex<T>
          T* FITSUtil::Carray<complex<T> >::operator() 
                          (const std::valarray<complex<T> >& inArray); 

          template <class T> class complex<T>
          T* FITSUtil::Carray<complex<T> >::operator() 
                          (const std::vector<valarray<complex<T> > >& inArray); 
        */

} // namespace CCfits
                      
                        
#endif

