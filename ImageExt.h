
//	This is CCfits version 1.0-beta

//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov


#ifndef IMAGEEXT_H
#define IMAGEEXT_H 1



// ExtHDU
#include "ExtHDU.h"
// HDUCreator
#include "HDUCreator.h"
// Image
#include "Image.h"
// FITSUtil
#include "FITSUtil.h"



namespace CCfits {
/*! \class ImageExt

     \brief   Templated concrete class representing Image Extension HDUs.
     
    
     

     
*/


/*! \fn      ImageExt<T>::ImageExt(const ImageExt< T > &right);

\brief copy constructor.

*/


/*! \fn       ImageExt<T>::ImageExt(FITSBase* p, const string &hduName, bool readDataFlag = false, const std::vector<string>& keys = std::vector<string>(), int version = 0) throw (FitsException&);

\brief  construct and read Image Extension from disk fitsfile by name.

*/


/*! \fn       ImageExt<T>::ImageExt(FITSBase* p, const string &hduName, int bpix, int  naxis, const std::vector<long>& naxes, int version = 0) throw (FitsException&);

\brief construct new image extension in FITS object p.

*/


/*! \fn       ImageExt<T>::~ImageExt();

\brief destructor.

*/



/*! \fn       virtual ImageExt<T> * ImageExt<T>::clone (FITSBase* p) const;

\brief virtual copy constructor.

*/


/*! \fn       virtual void ImageExt<T>::readData (bool readFlag = false, const std::vector<string>& keys = std::vector<string>());
	
\brief Read data reads the image if readFlag is true and optional keywords if supplied. 
       Thus, with no arguments, readData() does nothing.


*/


/*! \fn       virtual void ImageExt<T>::readImage (long first, long last, T* nullValue) throw (FitsException&);

\brief read parts of image specified between first and last. Null value can be specified optionally.


*/


/*! \fn       const std::valarray< T >& ImageExt<T>::image () const;
  
\brief return a const reference to the image array

*/

    
/*! \fn       void ImageExt<T>::image (const std::valarray< T >& value);

\brief set the image array.

*/











  template <typename T>
  class ImageExt : public ExtHDU  //## Inherits: <unnamed>%3804A11121D8
  {

    public:
        ImageExt(const ImageExt< T > &right);

        ~ImageExt();


        virtual ImageExt<T> * clone (FITSBase* p) const;

        const std::valarray<T>& image () const;

        void setImage (const std::valarray<T>& inData);

      // Additional Public Declarations

    protected:
        ImageExt (FITSBase* p, const string &hduName, bool readDataFlag = false, const std::vector<string>& keys = std::vector<string>(), int version = 0) throw (FitsException&);

        ImageExt (FITSBase* p, const string &hduName, int bpix, int  naxis, const std::vector<long>& naxes, int version = 0) throw (FitsException&);

      // Additional Protected Declarations

    private:

        virtual void initRead ();

        virtual ostream & put (ostream &s) const;

        virtual void readData (bool readFlag = false, const std::vector<string>& keys = std::vector<string>()) throw (FitsException&);

        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        virtual const std::valarray<T>& readImage (long first, long nElements, T* nullValue) throw (FitsException&);

        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        virtual const std::valarray<T>& readImage (const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::vector<long>& stride, T* nullValue) throw (FitsException&);

        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        virtual void writeImage (long first, long nElements, const std::valarray<T>& inData, T* nullValue = 0) throw (FitsException&);

        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        virtual void writeImage (const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::valarray<T>& inData) throw (FitsException&);


        const Image<T>& data () const;

      // Additional Private Declarations

    private: //## implementation
      // Data Members for Associations

        Image<T> m_data;

      // Additional Implementation Declarations
      friend class ExtHDU;
      friend class HDUCreator;
  };


  // Parameterized Class CCfits::ImageExt 


  template <typename T>
  inline ostream & ImageExt<T>::put (ostream &s) const
  {
  s << "Image Extension::  "  <<  " Name: " << name() << " Extension: " << xtension() 
          << " BITPIX "<< bitpix() << '\n';

  s <<  " Axis Lengths: \n";
  for (size_t j =1; j < static_cast<size_t>( axes() ) ; j++)
  {
        s << " Axis: " << j << "  " << axis(j-1) << '\n';  
  }

  
  
  s << "Image Extension:: Version: " << version() << " HDU number: " <<  index() << '\n';

  s << " HISTORY: " << history() << '\n';
  s << " COMMENTS: " <<comment() << '\n';

  s << "BinTable:: nKeywords: " << keyWord().size() << '\n';


    return s;
  }


  template <typename T>
  inline const Image<T>& ImageExt<T>::data () const
  {
    return m_data;
  }

  // Parameterized Class CCfits::ImageExt 


  template <typename T>
  ImageExt<T>::ImageExt(const ImageExt<T> &right)
      : ExtHDU(right), m_data(right.m_data)
  {
  }

  template <typename T>
  ImageExt<T>::ImageExt (FITSBase* p, const string &hduName, bool readDataFlag, const std::vector<string>& keys, int version) throw (FitsException&)
      : ExtHDU(p,ImageHdu,hduName,version),  m_data()
  {
  unsigned int zero = 0;
  initRead();
  
  if (readDataFlag || keys.size() > zero) readData(readDataFlag,keys);  
    
    
  }

  template <typename T>
  ImageExt<T>::ImageExt (FITSBase* p, const string &hduName, int bpix, int  naxis, const std::vector<long>& naxes, int version) throw (FitsException&)
      : ExtHDU(p,ImageHdu,hduName,bpix,naxis,naxes,version), m_data()
  {
  // resize m_image according to naxes, and data according to m_image,
  // and equate them. Valarray = must be performed on items of the same
  // size according to the standard.
  }


  template <typename T>
  ImageExt<T>::~ImageExt()
  {
  }



  template <typename T>
  void ImageExt<T>::initRead ()
  {
  }

  template <typename T>
  ImageExt<T> * ImageExt<T>::clone (FITSBase* p) const
  {
  ImageExt<T>* cloned = new ImageExt<T>(*this);
  cloned->parent() = p;
  return cloned;
  }

  template <typename T>
  void ImageExt<T>::readData (bool readFlag, const std::vector<string>& keys) throw (FitsException&)
  {
  // Default reading mode. Read everything if readFlag is true.
  // this is identical to the equivalent method for PrimaryHDU<T>,
  // so will one day turn this into a simple call that shares the code.
  makeThisCurrent();
  
  if ( keys.size() > 0) 
  {
        std::list<string> keyList;
        // keys is converted to a list so that any keys not in the header
        // can be easily erased. internally an exception will be thrown,
        // on a missing key, and its catch clause will print a message.
        for (std::vector<string>::const_iterator j = keys.begin(); j != keys.end(); ++j)
        {
                keyList.push_back(*j);
        } 
        readKeywords(keyList);
  }
  
  if ( readFlag)  // read the entire image, setting null values to FLT_MIN.
  {

        FITSUtil::FitsNullValue<T> null;
        T nulval = null();
        long first(1);
        long nelements(1);
        for (size_t i = 0; i < naxes().size(); i++) nelements *= naxes(i);
        m_data.readImage(fitsPointer(),first,nelements,&nulval,naxes(),anynul());
                
    }
  }

  template <typename T>
  const std::valarray<T>& ImageExt<T>::image () const
  {

    return m_data.image();
  }

  template <typename T>
  void ImageExt<T>::setImage (const std::valarray<T>& inData)
  {
  }

  template <typename T>
  const std::valarray<T>& ImageExt<T>::readImage (long first, long nElements, T* nullValue) throw (FitsException&)
  {
    makeThisCurrent();
    return m_data.readImage(fitsPointer(),first,nElements,nullValue,naxes(),anynul());
  }

  template <typename T>
  const std::valarray<T>& ImageExt<T>::readImage (const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::vector<long>& stride, T* nullValue) throw (FitsException&)
  {
    makeThisCurrent();
    return m_data.readImage(fitsPointer(),firstVertex,lastVertex,stride,nullValue,naxes(),anynul());
  }

  template <typename T>
  void ImageExt<T>::writeImage (long first, long nElements, const std::valarray<T>& inData, T* nullValue) throw (FitsException&)
  {
    m_data.writeImage(fitsPointer(),first,nElements,inData,naxes(),nullValue);
  }

  template <typename T>
  void ImageExt<T>::writeImage (const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::valarray<T>& inData) throw (FitsException&)
  {
    m_data.writeImage(fitsPointer(),firstVertex,lastVertex,inData,naxes());
  }

  // Additional Declarations

} // namespace CCfits



#endif
