//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3AF969A5008D.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%3AF969A5008D.cm

//## begin module%3AF969A5008D.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%3AF969A5008D.cp

//## Module: Image%3AF969A5008D; Package specification
//## Subsystem: CCfits::HDU%3826DF628F48
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/Image.h

#ifndef IMAGE_H
#define IMAGE_H 1

//## begin module%3AF969A5008D.additionalIncludes preserve=no
//## end module%3AF969A5008D.additionalIncludes

// vector
#include <vector>
// valarray
#include <valarray>
// functional
#include <functional>
// numeric
#include <numeric>
//## begin module%3AF969A5008D.includes preserve=yes
#ifdef _MSC_VER
#include "MSconfig.h" //form std::min
#endif
#include "CCfits.h"
#include "FitsError.h"
#include "FITSUtil.h"
//## end module%3AF969A5008D.includes

//## begin module%3AF969A5008D.declarations preserve=no
//## end module%3AF969A5008D.declarations

//## begin module%3AF969A5008D.additionalDeclarations preserve=yes
//## end module%3AF969A5008D.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::Image%3AF96959039F.preface preserve=yes
  //## end CCfits::Image%3AF96959039F.preface

  //## Class: Image%3AF96959039F; Parameterized Class
  //## Category: CCfits::HDU%393417220088
  //## Subsystem: CCfits::HDU%3826DF628F48
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  template <typename T>
  class Image 
  {
    //## begin CCfits::Image%3AF96959039F.initialDeclarations preserve=yes
    //## end CCfits::Image%3AF96959039F.initialDeclarations

    public:
      //## Constructors (generated)
        Image(const Image< T > &right);

      //## Constructors (specified)
        //## Operation: Image%3AF96B0200A0
        Image (const std::valarray<T>& imageArray = std::valarray<T>());

      //## Destructor (generated)
        ~Image();

      //## Assignment Operation (generated)
        Image< T > & operator=(const Image< T > &right);


      //## Other Operations (specified)
        //## Operation: readImage%3AF96D270119
        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        const std::valarray<T>& readImage (fitsfile* fPtr, long first, long nElements, T* nullValue, const std::vector<long>& naxes, bool& nulls);

        //## Operation: readImage%3AF96D320095
        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        const std::valarray<T>& readImage (fitsfile* fPtr, const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::vector<long>& stride, T* nullValue, const std::vector<long>& naxes, bool& nulls);

        //## Operation: writeImage%3AF96D3702E7
        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        void writeImage (fitsfile* fPtr, long first, long nElements, const std::valarray<T>& inData, const std::vector<long>& naxes, T* nullValue = 0);

        //## Operation: writeImage%3AF96D3C013C
        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        void writeImage (fitsfile* fPtr, const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::valarray<T>& inData, const std::vector<long>& naxes);

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: isRead%3AF99EF002C6
        bool isRead () const;
        void isRead (bool value);

      //## Get and Set Operations for Associations (generated)

        //## Association: CCfits::HDU::<unnamed>%3AF96D9602F2
        //## Role: Image::image%3AF96D970262
        //## Qualifier: index%3AF96DBD03C5; size_t
        const std::valarray< T >& image () const;
        void setImage (const std::valarray< T >& value);
        const T image (size_t index) const;
        void setImage (size_t index, T value);

      // Additional Public Declarations
        //## begin CCfits::Image%3AF96959039F.public preserve=yes
        //## end CCfits::Image%3AF96959039F.public

    protected:
      // Additional Protected Declarations
        //## begin CCfits::Image%3AF96959039F.protected preserve=yes
        //## end CCfits::Image%3AF96959039F.protected

    private:

      //## Other Operations (specified)
        //## Operation: image%3AF96DD8009D
        std::valarray<T>& image ();

        //## Operation: prepareForSubset%3AFC075A02DE
        void prepareForSubset (const std::vector<long>& naxes, const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::valarray<T>& inData, long* firstPtr, long* lastPtr);

      // Additional Private Declarations
        //## begin CCfits::Image%3AF96959039F.private preserve=yes
        //## end CCfits::Image%3AF96959039F.private

    private: //## implementation
      // Data Members for Class Attributes

        //## begin CCfits::Image::isRead%3AF99EF002C6.attr preserve=no  public: bool {U} false
        bool m_isRead;
        //## end CCfits::Image::isRead%3AF99EF002C6.attr

      // Data Members for Associations

        //## Association: CCfits::HDU::<unnamed>%3AF96D9602F2
        //## begin CCfits::Image::image%3AF96D970262.role preserve=no  public: std::valarray< T > { -> 1VHgN}
        std::valarray< T > m_image;
        //## end CCfits::Image::image%3AF96D970262.role

      // Additional Implementation Declarations
        //## begin CCfits::Image%3AF96959039F.implementation preserve=yes
        //## end CCfits::Image%3AF96959039F.implementation

  };

  //## begin CCfits::Image%3AF96959039F.postscript preserve=yes
  //## end CCfits::Image%3AF96959039F.postscript

  // Parameterized Class CCfits::Image 

  //## Get and Set Operations for Class Attributes (inline)

  template <typename T>
  inline bool Image<T>::isRead () const
  {
    //## begin CCfits::Image::isRead%3AF99EF002C6.get preserve=no
    return m_isRead;
    //## end CCfits::Image::isRead%3AF99EF002C6.get
  }

  template <typename T>
  inline void Image<T>::isRead (bool value)
  {
    //## begin CCfits::Image::isRead%3AF99EF002C6.set preserve=no
    m_isRead = value;
    //## end CCfits::Image::isRead%3AF99EF002C6.set
  }

  //## Get and Set Operations for Associations (inline)

  template <typename T>
  inline const std::valarray< T >& Image<T>::image () const
  {
    //## begin CCfits::Image::image%3AF96D970262.get preserve=no
    return m_image;
    //## end CCfits::Image::image%3AF96D970262.get
  }

  template <typename T>
  inline void Image<T>::setImage (const std::valarray< T >& value)
  {
    //## begin CCfits::Image::setImage%3AF96D970262.set preserve=yes
    m_image.resize(value.size());
    m_image = value;
    //## end CCfits::Image::setImage%3AF96D970262.set
  }

  template <typename T>
  inline const T Image<T>::image (size_t index) const
  {
    //## begin CCfits::Image::image%3AF96D970262.qualget preserve=yes
    return m_image[index];
    //## end CCfits::Image::image%3AF96D970262.qualget
  }

  template <typename T>
  inline void Image<T>::setImage (size_t index, T value)
  {
    //## begin CCfits::Image::setImage%3AF96D970262.qualset preserve=yes
    m_image[index]  = value;
    //## end CCfits::Image::setImage%3AF96D970262.qualset
  }

  // Parameterized Class CCfits::Image 

  template <typename T>
  Image<T>::Image(const Image<T> &right)
    //## begin Image::Image%3AF96959039F_copy.hasinit preserve=yes
        : m_isRead(right.m_isRead),
          m_image(right.m_image)
    //## end Image::Image%3AF96959039F_copy.hasinit
    //## begin Image::Image%3AF96959039F_copy.initialization preserve=yes
    //## end Image::Image%3AF96959039F_copy.initialization
  {
    //## begin CCfits::Image::Image%3AF96959039F_copy.body preserve=yes
    //## end CCfits::Image::Image%3AF96959039F_copy.body
  }

  template <typename T>
  Image<T>::Image (const std::valarray<T>& imageArray)
    //## begin CCfits::Image::Image%3AF96B0200A0.hasinit preserve=yes
        : m_isRead(false),
          m_image(imageArray)
    //## end CCfits::Image::Image%3AF96B0200A0.hasinit
    //## begin CCfits::Image::Image%3AF96B0200A0.initialization preserve=yes
    //## end CCfits::Image::Image%3AF96B0200A0.initialization
  {
    //## begin CCfits::Image::Image%3AF96B0200A0.body preserve=yes
    //## end CCfits::Image::Image%3AF96B0200A0.body
  }


  template <typename T>
  Image<T>::~Image()
  {
    //## begin CCfits::Image::~Image%3AF96959039F_dest.body preserve=yes
    //## end CCfits::Image::~Image%3AF96959039F_dest.body
  }


  template <typename T>
  Image<T> & Image<T>::operator=(const Image<T> &right)
  {
    //## begin CCfits::Image::operator=%3AF96959039F_assign.body preserve=yes
      // all stack allocated.
     Image<T> __tmp(right);
     std::swap(m_isRead,right.m_isRead);
     std::swap(m_image,right.m_image);
     return *this;
    //## end CCfits::Image::operator=%3AF96959039F_assign.body
  }



  //## Other Operations (implementation)
  template <typename T>
  const std::valarray<T>& Image<T>::readImage (fitsfile* fPtr, long first, long nElements, T* nullValue, const std::vector<long>& naxes, bool& nulls)
  {
    //## begin CCfits::Image::readImage%3AF96D270119.body preserve=yes
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
    //## end CCfits::Image::readImage%3AF96D270119.body
  }

  template <typename T>
  const std::valarray<T>& Image<T>::readImage (fitsfile* fPtr, const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::vector<long>& stride, T* nullValue, const std::vector<long>& naxes, bool& nulls)
  {
    //## begin CCfits::Image::readImage%3AF96D320095.body preserve=yes
          
          
          
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
    //## end CCfits::Image::readImage%3AF96D320095.body
  }

  template <typename T>
  void Image<T>::writeImage (fitsfile* fPtr, long first, long nElements, const std::valarray<T>& inData, const std::vector<long>& naxes, T* nullValue)
  {
    //## begin CCfits::Image::writeImage%3AF96D3702E7.body preserve=yes

          
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
     
     
     
     m_image[std::slice(first-1,nElements,1)]  = inData;

    //## end CCfits::Image::writeImage%3AF96D3702E7.body
  }

  template <typename T>
  void Image<T>::writeImage (fitsfile* fPtr, const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::valarray<T>& inData, const std::vector<long>& naxes)
  {
    //## begin CCfits::Image::writeImage%3AF96D3C013C.body preserve=yes
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
    //## end CCfits::Image::writeImage%3AF96D3C013C.body
  }

  template <typename T>
  std::valarray<T>& Image<T>::image ()
  {
    //## begin CCfits::Image::image%3AF96DD8009D.body preserve=yes
    //## end CCfits::Image::image%3AF96DD8009D.body

    return m_image;
  }

  template <typename T>
  void Image<T>::prepareForSubset (const std::vector<long>& naxes, const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::valarray<T>& inData, long* firstPtr, long* lastPtr)
  {
    //## begin CCfits::Image::prepareForSubset%3AFC075A02DE.body preserve=yes
    
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
 
    //## end CCfits::Image::prepareForSubset%3AFC075A02DE.body
  }

  // Additional Declarations
    //## begin CCfits::Image%3AF96959039F.declarations preserve=yes
    //## end CCfits::Image%3AF96959039F.declarations

} // namespace CCfits

//## begin module%3AF969A5008D.epilog preserve=yes
//## end module%3AF969A5008D.epilog


#endif
