
//	This is version 1.1.1 release dated Sept 2002

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	Sept 2002 Ben Dorman, L3-Communications
//	e-mail: ccfits@legacy.gsfc.nasa.gov


#ifndef IMAGE_H
#define IMAGE_H 1


// functional
#include <functional>
// vector
#include <vector>
// valarray
#include <valarray>
// numeric
#include <numeric>
#ifdef _MSC_VER
#include "MSconfig.h" //form std::min
#endif
#include "CCfits.h"
#include "FitsError.h"
#include "FITSUtil.h"




namespace CCfits {





  template <typename T>
  class Image 
  {

    public:
        Image(const Image< T > &right);

        Image (const std::valarray<T>& imageArray = std::valarray<T>());

        ~Image();

        Image< T > & operator=(const Image< T > &right);


        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        const std::valarray<T>& readImage (fitsfile* fPtr, long first, long nElements, T* nullValue, const std::vector<long>& naxes, bool& nulls);

        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        const std::valarray<T>& readImage (fitsfile* fPtr, const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::vector<long>& stride, T* nullValue, const std::vector<long>& naxes, bool& nulls);

        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        void writeImage (fitsfile* fPtr, long first, long nElements, const std::valarray<T>& inData, const std::vector<long>& naxes, T* nullValue = 0);

        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        void writeImage (fitsfile* fPtr, const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::valarray<T>& inData, const std::vector<long>& naxes);


        bool isRead () const;
        void isRead (bool value);


        const std::valarray< T >& image () const;
        void setImage (const std::valarray< T >& value);
        const T image (size_t index) const;
        void setImage (size_t index, T value);

      // Additional Public Declarations

    protected:
      // Additional Protected Declarations

    private:

        std::valarray<T>& image ();

        void prepareForSubset (const std::vector<long>& naxes, const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::valarray<T>& inData, long* firstPtr, long* lastPtr);

      // Additional Private Declarations

    private: //## implementation
      // Data Members for Class Attributes

        bool m_isRead;

      // Data Members for Associations

        std::valarray< T > m_image;

      // Additional Implementation Declarations

  };


  // Parameterized Class CCfits::Image 


  template <typename T>
  inline bool Image<T>::isRead () const
  {
    return m_isRead;
  }

  template <typename T>
  inline void Image<T>::isRead (bool value)
  {
    m_isRead = value;
  }


  template <typename T>
  inline const std::valarray< T >& Image<T>::image () const
  {
    return m_image;
  }

  template <typename T>
  inline void Image<T>::setImage (const std::valarray< T >& value)
  {
    m_image.resize(value.size());
    m_image = value;
  }

  template <typename T>
  inline const T Image<T>::image (size_t index) const
  {
    return m_image[index];
  }

  template <typename T>
  inline void Image<T>::setImage (size_t index, T value)
  {
    m_image[index]  = value;
  }

  // Parameterized Class CCfits::Image 

  template <typename T>
  Image<T>::Image(const Image<T> &right)
        : m_isRead(right.m_isRead),
          m_image(right.m_image)
  {
  }

  template <typename T>
  Image<T>::Image (const std::valarray<T>& imageArray)
        : m_isRead(false),
          m_image(imageArray)
  {
  }


  template <typename T>
  Image<T>::~Image()
  {
  }


  template <typename T>
  Image<T> & Image<T>::operator=(const Image<T> &right)
  {
      // all stack allocated.
     Image<T> __tmp(right);
     std::swap(m_isRead,right.m_isRead);
     std::swap(m_data,right.m_data);
     return *this;
  }



  template <typename T>
  const std::valarray<T>& Image<T>::readImage (fitsfile* fPtr, long first, long nElements, T* nullValue, const std::vector<long>& naxes, bool& nulls)
  {
        const size_t N(naxes.size());
        if (N > 0)
        {
                int status(0);
                int any (0);
                FITSUtil::MatchType<T> imageType;
                unsigned long init(1);
                unsigned long nelements(std::accumulate(&naxes[0],&naxes[N],init,
                                std::multiplies<long>()));
                
                // truncate to valid array size if too much data asked for.
                // note first is 1-based index)
                long elementsToRead(std::min(static_cast<unsigned long>(nElements),
                                nelements - first + 1));
                if ( elementsToRead < nElements)
                {
                        std::cerr << 
                                "***CCfits Warning: data request exceeds image size, truncating\n"; 
                }
                FITSUtil::auto_array_ptr<T> pArray(new T[elementsToRead]);
                T* array = pArray.get();
                if (fits_read_img(fPtr,imageType(),first,elementsToRead,
                                        nullValue,array,&any,&status) != 0) throw FitsError(status);
                FITSUtil::FitsNullValue<T> null;
                // initialize m_image to nullValue. resize if necessary.
                if (m_image.size() != static_cast<size_t>(elementsToRead)) 
                {
                        m_image.resize(elementsToRead,null());
                }

                std::copy(&array[0],&array[elementsToRead],&m_image[first-1]);

                nulls = (any != 0);
                m_isRead = (first == 1 && nelements == static_cast<unsigned long>(nElements)); 
        }
        else
        {
                m_isRead = true;
                m_image.resize(0);
        }
        return m_image;
  }

  template <typename T>
  const std::valarray<T>& Image<T>::readImage (fitsfile* fPtr, const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::vector<long>& stride, T* nullValue, const std::vector<long>& naxes, bool& nulls)
  {
          
          
          
     FITSUtil::CVarray<long> carray;
                        

     int any(0);
     int status(0);
     const size_t N(naxes.size());
     
     size_t arraySize(1);
                             
     for (size_t j = 0; j < N; ++j)
     {
             arraySize *= (lastVertex[j] - firstVertex[j] + 1);       
     }
          
     FITSUtil::auto_array_ptr<T>    pArray(new T[arraySize]);
     FITSUtil::auto_array_ptr<long> pFpixel(carray(firstVertex));
     FITSUtil::auto_array_ptr<long> pLpixel(carray(lastVertex));
     FITSUtil::auto_array_ptr<long> pStride(carray(stride));
     
     FITSUtil::MatchType<T> imageType;

     if (fits_read_subset(fPtr,imageType(),
                             pLpixel.get(),pLpixel.get(),
                             pStride.get(),nullValue,pArray.get(),&any,&status) != 0)
     {
                throw FitsError(status);        
             
     }
     
     size_t n(m_image.size());
     if (n < arraySize)  m_image.resize(arraySize);
     m_image = std::valarray<T>(pArray.get(),arraySize);
     //size_t imageSize(std::accumulate(&naxes[0],&naxes[N],init,std::multiplies<T>() ));
     // m_isRead = (startPoint  == 0 && imageSize == static_cast<unsigned long>(nElements)); 
     nulls = (any != 0);
     return m_image;    
  }

  template <typename T>
  void Image<T>::writeImage (fitsfile* fPtr, long first, long nElements, const std::valarray<T>& inData, const std::vector<long>& naxes, T* nullValue)
  {

          
     int status(0);
     const size_t N(naxes.size());
     size_t init(1);   
     size_t totalSize= static_cast<size_t>(std::accumulate(&naxes[0],&naxes[N],init,std::multiplies<long>() ));
     FITSUtil::FitsNullValue<T> null;
     if (m_image.size() != totalSize) m_image.resize(totalSize,null());
     FITSUtil::CAarray<T> convert;
     FITSUtil::auto_array_ptr<T>    pArray(convert(inData));                     
     T* array = pArray.get();
     
     
     FITSUtil::MatchType<T> imageType;
     long type(imageType());
     
     if (fits_write_imgnull(fPtr,type,first,nElements,array,
                     nullValue,&status) || fits_flush_file(fPtr,&status) != 0)
     {
                throw FitsError(status);        
             
     }
     
     
     
     m_image[std::slice(first,nElements,1)]  = inData;

  }

  template <typename T>
  void Image<T>::writeImage (fitsfile* fPtr, const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::valarray<T>& inData, const std::vector<long>& naxes)
  {
        long* fPixel = 0;
        long* lPixel = 0;
        
        prepareForSubset(naxes,firstVertex,lastVertex,inData,fPixel,lPixel);

        FITSUtil::CAarray<T> convert;
        FITSUtil::auto_array_ptr<T> pArray(convert(inData));
        T* array = pArray.get();
        FITSUtil::MatchType<T> imageType;        
        int status(0);
        
        if ( fits_write_subset(fPtr,imageType(),fPixel,lPixel,array,&status) 
                        || fits_flush_file(fPtr,&status)  != 0) throw FitsError(status);
          
          // must be specialized.
  }

  template <typename T>
  std::valarray<T>& Image<T>::image ()
  {

    return m_image;
  }

  template <typename T>
  void Image<T>::prepareForSubset (const std::vector<long>& naxes, const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::valarray<T>& inData, long* firstPtr, long* lastPtr)
  {
    
    // in 3 words: What A Mess!      
          
          
    const size_t N(naxes.size()); 
    const size_t M(firstVertex.size()); 
    size_t init(1);   
    FITSUtil::auto_array_ptr<long> pLast(new long[M]);
    long* last = pLast.get();
    FITSUtil::auto_array_ptr<long> pFirst(new long[M]);
    
    size_t imageSize(std::accumulate(&naxes[0],&naxes[N],init,std::multiplies<long>() ));
    FITSUtil::FitsNullValue<T> null;
    if (m_image.size() != imageSize) 
    {
            m_image.resize(imageSize,null());
    }
    
    // ensure that the lastVertex and stride vectors are the same size as firstVertex.

    long ml(std::min(lastVertex.size(),M));
    
    
    // valarrays are all very well, but it's nice to have random access iterators...
    std::copy(firstVertex.begin(),firstVertex.end(),&pFirst.get()[0]);
    std::copy(lastVertex.begin(),lastVertex.begin()+ml,&last[0]);
    
    // non-unit strides not currently supported.
    //ms = std::min(stride.size(),M);
    //std::copy(stride.begin(),stride.begin()+ms,fullLast.begin());
    
    //std::vector<long> offsets(M,1);
    //for (size_t j  = M - 2; j > 0 ; --j)
    //{
    //           offsets[j] *= offsets[j+1]; 
    //}
     
    
    std::valarray<size_t> vLength(1,M);  
    {  
        for (size_t j = 0; j < M; ++j)
        {
                last[j] = std::max(firstVertex[j],last[j]);
                vLength[j]   = last[j]-pFirst.get()[j]+1;
        }   
    }
    
    size_t startPoint(firstVertex[0] - 1);
    

    {
        for (size_t j = 1; j < M; ++j)
        {
                startPoint += naxes[j]*(firstVertex[j] - 1);       
        }
    }
    std::valarray<size_t> vStride(1,M);
    
    m_image[std::gslice(startPoint,vLength,vStride)] = inData;
    
    firstPtr = pFirst.release();
    lastPtr = pLast.release();
 
  }

  // Additional Declarations

} // namespace CCfits



#endif
