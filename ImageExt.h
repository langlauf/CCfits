//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%38049F97A1A0.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%38049F97A1A0.cm

//## begin module%38049F97A1A0.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%38049F97A1A0.cp

//## Module: ImageExt%38049F97A1A0; Package specification
//## Subsystem: CCfits::HDU%3826DF628F48
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/ImageExt.h

#ifndef IMAGEEXT_H
#define IMAGEEXT_H 1

//## begin module%38049F97A1A0.additionalIncludes preserve=no
//## end module%38049F97A1A0.additionalIncludes

// ExtHDU
#include "ExtHDU.h"
// HDUCreator
#include "HDUCreator.h"
// Image
#include "Image.h"
// FITSUtil
#include "FITSUtil.h"
//## begin module%38049F97A1A0.includes preserve=yes
#ifdef _MSC_VER
#include "MSconfig.h" // for truncation warning
#endif
//## end module%38049F97A1A0.includes

//## begin module%38049F97A1A0.declarations preserve=no
//## end module%38049F97A1A0.declarations

//## begin module%38049F97A1A0.additionalDeclarations preserve=yes
//## end module%38049F97A1A0.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::ImageExt%38049FC84FB8.preface preserve=yes
  //## end CCfits::ImageExt%38049FC84FB8.preface

  //## Class: ImageExt%38049FC84FB8; Parameterized Class
  //## Category: CCfits::HDU%393417220088
  //## Subsystem: CCfits::HDU%3826DF628F48
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  template <typename T>
  class ImageExt : public ExtHDU  //## Inherits: <unnamed>%3804A11121D8
  {
    //## begin CCfits::ImageExt%38049FC84FB8.initialDeclarations preserve=yes
    //## end CCfits::ImageExt%38049FC84FB8.initialDeclarations

    public:
      //## Constructors (generated)
        ImageExt(const ImageExt< T > &right);

      //## Destructor (generated)
        ~ImageExt();


      //## Other Operations (specified)
        //## Operation: clone%381F02B16578
        virtual ImageExt<T> * clone (FITSBase* p) const;

        //## Operation: readData%3950C85B0238
        virtual void readData (bool readFlag = false, const std::vector<String>& keys = std::vector<String>());

        //## Operation: image%3AF996B702CA
        const std::valarray<T>& image () const;

        //## Operation: setImage%3AF996BF02BE
        void setImage (const std::valarray<T>& inData);

        //## Operation: zero%3CE2A9630218
        virtual void zero (double value);

        //## Operation: scale%3CE2A97B0346
        virtual void scale (double value);

        //## Operation: zero%3CE2AC4301CA
        virtual double zero () const;

        //## Operation: scale%3CE2AC47012A
        virtual double scale () const;

      // Additional Public Declarations
        //## begin CCfits::ImageExt%38049FC84FB8.public preserve=yes
        //## end CCfits::ImageExt%38049FC84FB8.public

    protected:
      //## Constructors (specified)
        //## Operation: ImageExt%38D65101F418
        ImageExt (FITSBase* p, const String &hduName, bool readDataFlag = false, const std::vector<String>& keys = std::vector<String>(), int version = 1);

        //## Operation: ImageExt%3804A454C978
        ImageExt (FITSBase* p, const String &hduName, int bpix, int naxis, const std::vector<long>& naxes, int version = 1);

      // Additional Protected Declarations
        //## begin CCfits::ImageExt%38049FC84FB8.protected preserve=yes
        virtual void checkExtensionType() const;
        //## end CCfits::ImageExt%38049FC84FB8.protected
    private:

      //## Other Operations (specified)
        //## Operation: initRead%3804E4845658
        virtual void initRead ();

        //## Operation: put%385A3E5F38F0
        virtual std::ostream & put (std::ostream &s) const;

        //## Operation: readImage%3AFAA181036A
        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        virtual const std::valarray<T>& readImage (long first, long nElements, T* nullValue);

        //## Operation: readImage%3AFAA185035D
        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        virtual const std::valarray<T>& readImage (const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::vector<long>& stride, T* nullValue);

        //## Operation: writeImage%3AFAA1890134
        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        virtual void writeImage (long first, long nElements, const std::valarray<T>& inData, T* nullValue = 0);

        //## Operation: writeImage%3AFAA18C02F6
        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        virtual void writeImage (const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::valarray<T>& inData);

      //## Get and Set Operations for Associations (generated)

        //## Association: CCfits::HDU::<unnamed>%3AF995FF02B0
        //## Role: ImageExt::data%3AF9960001A5
        const Image<T>& data () const;

      // Additional Private Declarations
        //## begin CCfits::ImageExt%38049FC84FB8.private preserve=yes
        //## end CCfits::ImageExt%38049FC84FB8.private

    private: //## implementation
      // Data Members for Associations

        //## Association: CCfits::HDU::<unnamed>%3AF995FF02B0
        //## begin CCfits::ImageExt::data%3AF9960001A5.role preserve=no  private: CCfits::Image { -> 1VHgN}
        Image<T> m_data;
        //## end CCfits::ImageExt::data%3AF9960001A5.role

      // Additional Implementation Declarations
        //## begin CCfits::ImageExt%38049FC84FB8.implementation preserve=yes
      friend class ExtHDU;
      friend class HDUCreator;
        //## end CCfits::ImageExt%38049FC84FB8.implementation
  };

  //## begin CCfits::ImageExt%38049FC84FB8.postscript preserve=yes
  //## end CCfits::ImageExt%38049FC84FB8.postscript

  // Parameterized Class CCfits::ImageExt 


  //## Other Operations (inline)
  template <typename T>
  inline std::ostream & ImageExt<T>::put (std::ostream &s) const
  {
    //## begin CCfits::ImageExt::put%385A3E5F38F0.body preserve=yes
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

    //## end CCfits::ImageExt::put%385A3E5F38F0.body

    return s;
  }

  //## Get and Set Operations for Associations (inline)

  template <typename T>
  inline const Image<T>& ImageExt<T>::data () const
  {
    //## begin CCfits::ImageExt::data%3AF9960001A5.get preserve=no
    return m_data;
    //## end CCfits::ImageExt::data%3AF9960001A5.get
  }

  // Parameterized Class CCfits::ImageExt 

  template <typename T>
  ImageExt<T>::ImageExt(const ImageExt<T> &right)
    //## begin ImageExt::ImageExt%38049FC84FB8_copy.hasinit preserve=yes
      : ExtHDU(right), m_data(right.m_data)
    //## end ImageExt::ImageExt%38049FC84FB8_copy.hasinit
    //## begin ImageExt::ImageExt%38049FC84FB8_copy.initialization preserve=yes
    //## end ImageExt::ImageExt%38049FC84FB8_copy.initialization
  {
    //## begin CCfits::ImageExt::ImageExt%38049FC84FB8_copy.body preserve=yes
    //## end CCfits::ImageExt::ImageExt%38049FC84FB8_copy.body
  }

  template <typename T>
  ImageExt<T>::ImageExt (FITSBase* p, const String &hduName, bool readDataFlag, const std::vector<String>& keys, int version)
    //## begin CCfits::ImageExt::ImageExt%38D65101F418.hasinit preserve=yes
      : ExtHDU(p,ImageHdu,hduName,version),  m_data()
    //## end CCfits::ImageExt::ImageExt%38D65101F418.hasinit
    //## begin CCfits::ImageExt::ImageExt%38D65101F418.initialization preserve=yes
    //## end CCfits::ImageExt::ImageExt%38D65101F418.initialization
  {
    //## begin CCfits::ImageExt::ImageExt%38D65101F418.body preserve=yes
  initRead();
  if (readDataFlag || keys.size() ) readData(readDataFlag,keys);  
    //## end CCfits::ImageExt::ImageExt%38D65101F418.body
  }

  template <typename T>
  ImageExt<T>::ImageExt (FITSBase* p, const String &hduName, int bpix, int naxis, const std::vector<long>& naxes, int version)
    //## begin CCfits::ImageExt::ImageExt%3804A454C978.hasinit preserve=yes
      : ExtHDU(p,ImageHdu,hduName,bpix,naxis,naxes,version), m_data()
    //## end CCfits::ImageExt::ImageExt%3804A454C978.hasinit
    //## begin CCfits::ImageExt::ImageExt%3804A454C978.initialization preserve=yes
    //## end CCfits::ImageExt::ImageExt%3804A454C978.initialization
  {
    //## begin CCfits::ImageExt::ImageExt%3804A454C978.body preserve=yes
  // resize m_image according to naxes, and data according to m_image,
  // and equate them. Valarray = must be performed on items of the same
  // size according to the standard.
  int status (0);
  FITSUtil::CVarray<long> convert;
  FITSUtil::auto_array_ptr<long> axis(convert(naxes));
  static char EXTNAME[] = "EXTNAME";
  static char HDUVERS[] = "HDUVERS";
  
          if ( fits_create_img(fitsPointer(), bpix, naxis, axis.get(), &status) )
          {

                throw FitsError(status);
          } 
          else
          {
                char * comment = 0;
                if (fits_write_key(fitsPointer(),Tstring,EXTNAME,
                                const_cast<char*>(hduName.c_str()), comment,&status)) 
                {
                        throw FitsError(status);
                }                
                if (version != 0 && fits_write_key(fitsPointer(),Tint,HDUVERS,&version,
                                        comment,&status)) throw FitsError(status);     
          }      
    //## end CCfits::ImageExt::ImageExt%3804A454C978.body
  }


  template <typename T>
  ImageExt<T>::~ImageExt()
  {
    //## begin CCfits::ImageExt::~ImageExt%38049FC84FB8_dest.body preserve=yes
    //## end CCfits::ImageExt::~ImageExt%38049FC84FB8_dest.body
  }



  //## Other Operations (implementation)
  template <typename T>
  void ImageExt<T>::initRead ()
  {
    //## begin CCfits::ImageExt::initRead%3804E4845658.body preserve=yes
    //## end CCfits::ImageExt::initRead%3804E4845658.body
  }

  template <typename T>
  ImageExt<T> * ImageExt<T>::clone (FITSBase* p) const
  {
    //## begin CCfits::ImageExt::clone%381F02B16578.body preserve=yes
  ImageExt<T>* cloned = new ImageExt<T>(*this);
  cloned->parent() = p;
  return cloned;
    //## end CCfits::ImageExt::clone%381F02B16578.body
  }

  template <typename T>
  void ImageExt<T>::readData (bool readFlag, const std::vector<String>& keys)
  {
    //## begin CCfits::ImageExt::readData%3950C85B0238.body preserve=yes
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
    //## end CCfits::ImageExt::readData%3950C85B0238.body
  }

  template <typename T>
  const std::valarray<T>& ImageExt<T>::image () const
  {
    //## begin CCfits::ImageExt::image%3AF996B702CA.body preserve=yes
    //## end CCfits::ImageExt::image%3AF996B702CA.body

    return m_data.image();
  }

  template <typename T>
  void ImageExt<T>::setImage (const std::valarray<T>& inData)
  {
    //## begin CCfits::ImageExt::setImage%3AF996BF02BE.body preserve=yes
    //## end CCfits::ImageExt::setImage%3AF996BF02BE.body
  }

  template <typename T>
  const std::valarray<T>& ImageExt<T>::readImage (long first, long nElements, T* nullValue)
  {
    //## begin CCfits::ImageExt::readImage%3AFAA181036A.body preserve=yes
    checkExtensionType();
    return m_data.readImage(fitsPointer(),first,nElements,nullValue,naxes(),anynul());
    //## end CCfits::ImageExt::readImage%3AFAA181036A.body
  }

  template <typename T>
  const std::valarray<T>& ImageExt<T>::readImage (const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::vector<long>& stride, T* nullValue)
  {
    //## begin CCfits::ImageExt::readImage%3AFAA185035D.body preserve=yes
    checkExtensionType();
    return m_data.readImage(fitsPointer(),firstVertex,lastVertex,stride,nullValue,naxes(),anynul());
    //## end CCfits::ImageExt::readImage%3AFAA185035D.body
  }

  template <typename T>
  void ImageExt<T>::writeImage (long first, long nElements, const std::valarray<T>& inData, T* nullValue)
  {
    //## begin CCfits::ImageExt::writeImage%3AFAA1890134.body preserve=yes
    checkExtensionType();
    m_data.writeImage(fitsPointer(),first,nElements,inData,naxes(),nullValue);
    //## end CCfits::ImageExt::writeImage%3AFAA1890134.body
  }

  template <typename T>
  void ImageExt<T>::writeImage (const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::valarray<T>& inData)
  {
    //## begin CCfits::ImageExt::writeImage%3AFAA18C02F6.body preserve=yes
    checkExtensionType();
    m_data.writeImage(fitsPointer(),firstVertex,lastVertex,inData,naxes());
    //## end CCfits::ImageExt::writeImage%3AFAA18C02F6.body
  }

  template <typename T>
  void ImageExt<T>::zero (double value)
  {
    //## begin CCfits::ImageExt::zero%3CE2A9630218.body preserve=yes
    HDU::zero(value);
    if (naxis())
    {
        int status(0);
        if (fits_set_bscale(fitsPointer(),scale(),value,&status)) throw FitsError(status);
    }
    //## end CCfits::ImageExt::zero%3CE2A9630218.body
  }

  template <typename T>
  void ImageExt<T>::scale (double value)
  {
    //## begin CCfits::ImageExt::scale%3CE2A97B0346.body preserve=yes
    HDU::scale(value);
    if (naxis())
    {
        int status(0);
        if (fits_set_bscale(fitsPointer(),value,zero(),&status)) throw FitsError(status);
    } 
    //## end CCfits::ImageExt::scale%3CE2A97B0346.body
  }

  template <typename T>
  double ImageExt<T>::zero () const
  {
    //## begin CCfits::ImageExt::zero%3CE2AC4301CA.body preserve=yes
    //## end CCfits::ImageExt::zero%3CE2AC4301CA.body

    return HDU::zero();
  }

  template <typename T>
  double ImageExt<T>::scale () const
  {
    //## begin CCfits::ImageExt::scale%3CE2AC47012A.body preserve=yes
    //## end CCfits::ImageExt::scale%3CE2AC47012A.body

    return HDU::scale();
  }

  // Additional Declarations
    //## begin CCfits::ImageExt%38049FC84FB8.declarations preserve=yes
    template <typename T>
    inline void ImageExt<T>::checkExtensionType() const
    {
            
    }
    //## end CCfits::ImageExt%38049FC84FB8.declarations
} // namespace CCfits

//## begin module%38049F97A1A0.epilog preserve=yes
//## end module%38049F97A1A0.epilog


#endif
