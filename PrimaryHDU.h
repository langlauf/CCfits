//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3936C4EA03B5.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%3936C4EA03B5.cm

//## begin module%3936C4EA03B5.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%3936C4EA03B5.cp

//## Module: PrimaryHDU%3936C4EA03B5; Package specification
//## Subsystem: CCfits::HDU%3826DF628F48
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/PrimaryHDU.h

#ifndef PRIMARYHDU_H
#define PRIMARYHDU_H 1

//## begin module%3936C4EA03B5.additionalIncludes preserve=no
//## end module%3936C4EA03B5.additionalIncludes

// valarray
#include <valarray>
// PHDU
#include "PHDU.h"
// HDUCreator
#include "HDUCreator.h"
// Image
#include "Image.h"
// FITS
#include "FITS.h"
//## begin module%3936C4EA03B5.includes preserve=yes
//## end module%3936C4EA03B5.includes

//## begin module%3936C4EA03B5.declarations preserve=no
//## end module%3936C4EA03B5.declarations

//## begin module%3936C4EA03B5.additionalDeclarations preserve=yes
#include "CCfits.h"
#include <functional>
#include <numeric>
#include <memory>
//## end module%3936C4EA03B5.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::PrimaryHDU%380481CF79A8.preface preserve=yes
  //## end CCfits::PrimaryHDU%380481CF79A8.preface

  //## Class: PrimaryHDU%380481CF79A8; Parameterized Class
  //## Category: CCfits::HDU%393417220088
  //## Subsystem: CCfits::HDU%3826DF628F48
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%394F9B98018F;FITS { -> }

  template <typename T>
  class PrimaryHDU : public PHDU  //## Inherits: <unnamed>%394E6F870338
  {
    //## begin CCfits::PrimaryHDU%380481CF79A8.initialDeclarations preserve=yes
    //## end CCfits::PrimaryHDU%380481CF79A8.initialDeclarations

    public:

      //## Other Operations (specified)
        //## Operation: clone%381F025325B8
        virtual PrimaryHDU<T> * clone (FITSBase* p) const;

        //## Operation: readData%394FADBB03B0
        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        virtual void readData (bool readFlag = false, const std::vector<String>& keys = std::vector<String>());

        //## Operation: image%3AF996410226
        const std::valarray<T>& image () const;

        //## Operation: image%3AF9966E02C5
        std::valarray<T>& image ();

        //## Operation: setImage%3AF9967B02FF
        void setImage (const std::valarray<T>& inData);

        //## Operation: readImage%3AF9A0D1002F
        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        virtual const std::valarray<T>& readImage (long first, long nElements, T* nullValue);

        //## Operation: readImage%3AF9A0D60326
        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        virtual const std::valarray<T>& readImage (const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::vector<long>& stride, T* nullValue);

        //## Operation: writeImage%3AF9A0DB0342
        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        virtual void writeImage (long first, long nElements, const std::valarray<T>& inData, T* nullValue = 0);

        //## Operation: writeImage%3AF9A0E102E2
        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        virtual void writeImage (const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::vector<long>& stride, const std::valarray<T>& inData);

      // Additional Public Declarations
        //## begin CCfits::PrimaryHDU%380481CF79A8.public preserve=yes
        //## end CCfits::PrimaryHDU%380481CF79A8.public

    protected:
      //## Constructors (specified)
        //## Operation: PrimaryHDU%394F96B60262
        //	Constructor for new FITS objects, takes as arguments
        //	the required keywords for a primary HDU.
        PrimaryHDU (FITSBase* p, const int bitpix, const int naxis, const std::vector<long>& naxes, const std::valarray<T>& data = std::valarray<T>());

        //## Operation: PrimaryHDU%394F96EC00E3
        //	Custom constructor. Allows specification of data to be read and whether to read data at
        //	construction or wait until the image data are requested. The default is 'lazy initialization:'
        //	wait until asked.
        PrimaryHDU (FITSBase* p, bool readFlag = false, const std::vector<String>& keys = std::vector<String>());

      // Additional Protected Declarations
        //## begin CCfits::PrimaryHDU%380481CF79A8.protected preserve=yes
        //## end CCfits::PrimaryHDU%380481CF79A8.protected

    private:
      //## Constructors (generated)
        PrimaryHDU(const PrimaryHDU< T > &right);

      //## Assignment Operation (generated)
        PrimaryHDU< T > & operator=(const PrimaryHDU< T > &right);


      //## Other Operations (specified)
        //## Operation: put%385A3DDF4638
        virtual std::ostream & put (std::ostream &s) const;

      //## Get and Set Operations for Associations (generated)

        //## Association: CCfits::HDU::<unnamed>%3AF995A000A6
        //## Role: PrimaryHDU::data%3AF995A0030F
        const Image<T>& data () const;

      // Additional Private Declarations
        //## begin CCfits::PrimaryHDU%380481CF79A8.private preserve=yes
        //## end CCfits::PrimaryHDU%380481CF79A8.private

    private: //## implementation
      // Data Members for Associations

        //## Association: CCfits::HDU::<unnamed>%3AF995A000A6
        //## begin CCfits::PrimaryHDU::data%3AF995A0030F.role preserve=no  private: CCfits::Image { -> 1VHgN}
        Image<T> m_data;
        //## end CCfits::PrimaryHDU::data%3AF995A0030F.role

      // Additional Implementation Declarations
        //## begin CCfits::PrimaryHDU%380481CF79A8.implementation preserve=yes
      friend class HDUCreator;
      friend class PHDU;
        //## end CCfits::PrimaryHDU%380481CF79A8.implementation
  };

  //## begin CCfits::PrimaryHDU%380481CF79A8.postscript preserve=yes
  //## end CCfits::PrimaryHDU%380481CF79A8.postscript

  // Parameterized Class CCfits::PrimaryHDU 


  //## Other Operations (inline)
  template <typename T>
  inline std::ostream & PrimaryHDU<T>::put (std::ostream &s) const
  {
    //## begin CCfits::PrimaryHDU::put%385A3DDF4638.body preserve=yes
  s << "PrimaryHDU:: Simple? " << simple() << " Extend?: " << extend() << 
    " Bitpix: " << bitpix() << " naxis = " << axes() << "\n";
  s << "Axis Lengths: \n";
    
 
  
  for (int i=0; i < axes(); i++)
     s  << " axis[" << i << "] " << axis(i) << "\n";
  
 s << "\nNumber of keywords read: " << keyWord().size() <<  "\n";
  
  for (std::map<String,Keyword*>::const_iterator ki = keyWord().begin();
        ki != keyWord().end(); ki++)
  {
        s << *((*ki).second) << std::endl;              
  }  
  
  
  s << " HISTORY: " << history() << '\n';
  s << " COMMENTS: " <<comment() << '\n';
  return s;  
    //## end CCfits::PrimaryHDU::put%385A3DDF4638.body
  }

  //## Get and Set Operations for Associations (inline)

  template <typename T>
  inline const Image<T>& PrimaryHDU<T>::data () const
  {
    //## begin CCfits::PrimaryHDU::data%3AF995A0030F.get preserve=no
    return m_data;
    //## end CCfits::PrimaryHDU::data%3AF995A0030F.get
  }

  // Parameterized Class CCfits::PrimaryHDU 

  template <typename T>
  PrimaryHDU<T>::PrimaryHDU(const PrimaryHDU<T> &right)
    //## begin PrimaryHDU::PrimaryHDU%380481CF79A8_copy.hasinit preserve=yes
      : PHDU(right), m_data(right.m_data)
    //## end PrimaryHDU::PrimaryHDU%380481CF79A8_copy.hasinit
    //## begin PrimaryHDU::PrimaryHDU%380481CF79A8_copy.initialization preserve=yes
    //## end PrimaryHDU::PrimaryHDU%380481CF79A8_copy.initialization
  {
    //## begin CCfits::PrimaryHDU::PrimaryHDU%380481CF79A8_copy.body preserve=yes
    //## end CCfits::PrimaryHDU::PrimaryHDU%380481CF79A8_copy.body
  }

  template <typename T>
  PrimaryHDU<T>::PrimaryHDU (FITSBase* p, const int bitpix, const int naxis, const std::vector<long>& naxes, const std::valarray<T>& data)
    //## begin CCfits::PrimaryHDU::PrimaryHDU%394F96B60262.hasinit preserve=yes
        : PHDU(p,bitpix,naxis,naxes),m_data(data)
    //## end CCfits::PrimaryHDU::PrimaryHDU%394F96B60262.hasinit
    //## begin CCfits::PrimaryHDU::PrimaryHDU%394F96B60262.initialization preserve=yes
    //## end CCfits::PrimaryHDU::PrimaryHDU%394F96B60262.initialization
  {
    //## begin CCfits::PrimaryHDU::PrimaryHDU%394F96B60262.body preserve=yes
    //## end CCfits::PrimaryHDU::PrimaryHDU%394F96B60262.body
  }

  template <typename T>
  PrimaryHDU<T>::PrimaryHDU (FITSBase* p, bool readFlag, const std::vector<String>& keys)
    //## begin CCfits::PrimaryHDU::PrimaryHDU%394F96EC00E3.hasinit preserve=yes
        : PHDU(p), m_data()
    //## end CCfits::PrimaryHDU::PrimaryHDU%394F96EC00E3.hasinit
    //## begin CCfits::PrimaryHDU::PrimaryHDU%394F96EC00E3.initialization preserve=yes
    //## end CCfits::PrimaryHDU::PrimaryHDU%394F96EC00E3.initialization
  {
    //## begin CCfits::PrimaryHDU::PrimaryHDU%394F96EC00E3.body preserve=yes
  initRead();
  
  if (readFlag || keys.size()) readData(readFlag,keys);  
    
    
    //## end CCfits::PrimaryHDU::PrimaryHDU%394F96EC00E3.body
  }



  //## Other Operations (implementation)
  template <typename T>
  PrimaryHDU<T> * PrimaryHDU<T>::clone (FITSBase* p) const
  {
    //## begin CCfits::PrimaryHDU::clone%381F025325B8.body preserve=yes
  PrimaryHDU<T>* cloned = new PrimaryHDU<T>(*this);
  cloned->parent() = p;
  return cloned;
    //## end CCfits::PrimaryHDU::clone%381F025325B8.body
  }

  template <typename T>
  void PrimaryHDU<T>::readData (bool readFlag, const std::vector<String>& keys)
  {
    //## begin CCfits::PrimaryHDU::readData%394FADBB03B0.body preserve=yes
    
  // Default reading mode. Read everything if readFlag is true.
  makeThisCurrent();
  
  if ( keys.size() > 0) 
  {
        std::list<String> keyList(keys.size());
        // keys is converted to a list so that any keys not in the header
        // can be easily erased. internally an exception will be thrown,
        // on a missing key, and its catch clause will print a message.
        std::copy(keys.begin(),keys.end(),keyList.begin());
        readKeywords(keyList);
  }
  // read the entire image, setting null values to the
  // return value from FitsNullValue<T>. It would be easy to make the null value
  // a user defined input, but that's not implemented yet.
  if ( readFlag && (naxis() > 0) )  
  {
        FITSUtil::FitsNullValue<T> null;
        long init(1);
        T nulValue(null());
        long nelements(std::accumulate(&naxes()[0],&naxes()[naxis()],init,std::multiplies<long>() ));
        readImage(1,nelements,&nulValue);
                
    }
    //## end CCfits::PrimaryHDU::readData%394FADBB03B0.body
  }

  template <typename T>
  const std::valarray<T>& PrimaryHDU<T>::image () const
  {
    //## begin CCfits::PrimaryHDU::image%3AF996410226.body preserve=yes
    //## end CCfits::PrimaryHDU::image%3AF996410226.body

    return m_data.image();
  }

  template <typename T>
  std::valarray<T>& PrimaryHDU<T>::image ()
  {
    //## begin CCfits::PrimaryHDU::image%3AF9966E02C5.body preserve=yes
    //## end CCfits::PrimaryHDU::image%3AF9966E02C5.body

    return m_data.image();
  }

  template <typename T>
  void PrimaryHDU<T>::setImage (const std::valarray<T>& inData)
  {
    //## begin CCfits::PrimaryHDU::setImage%3AF9967B02FF.body preserve=yes
    m_data.image().resize(inData.size());
    m_data.setImage(inData);
    //## end CCfits::PrimaryHDU::setImage%3AF9967B02FF.body
  }

  template <typename T>
  const std::valarray<T>& PrimaryHDU<T>::readImage (long first, long nElements, T* nullValue)
  {
    //## begin CCfits::PrimaryHDU::readImage%3AF9A0D1002F.body preserve=yes
    makeThisCurrent();
    return m_data.readImage(fitsPointer(),first,nElements,nullValue,naxes(),anynul());
    //## end CCfits::PrimaryHDU::readImage%3AF9A0D1002F.body
  }

  template <typename T>
  const std::valarray<T>& PrimaryHDU<T>::readImage (const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::vector<long>& stride, T* nullValue)
  {
    //## begin CCfits::PrimaryHDU::readImage%3AF9A0D60326.body preserve=yes
    makeThisCurrent();
    return m_data.readImage(fitsPointer(),firstVertex,lastVertex,stride,nullValue,naxes(),anynul());
    //## end CCfits::PrimaryHDU::readImage%3AF9A0D60326.body
  }

  template <typename T>
  void PrimaryHDU<T>::writeImage (long first, long nElements, const std::valarray<T>& inData, T* nullValue)
  {
    //## begin CCfits::PrimaryHDU::writeImage%3AF9A0DB0342.body preserve=yes
    m_data.writeImage(fitsPointer(),first,nElements,inData,naxes(),nullValue);
    //## end CCfits::PrimaryHDU::writeImage%3AF9A0DB0342.body
  }

  template <typename T>
  void PrimaryHDU<T>::writeImage (const std::vector<long>& firstVertex, const std::vector<long>& lastVertex, const std::vector<long>& stride, const std::valarray<T>& inData)
  {
    //## begin CCfits::PrimaryHDU::writeImage%3AF9A0E102E2.body preserve=yes
    m_data.writeImage(fitsPointer(),firstVertex,lastVertex,stride,inData,naxes());
    //## end CCfits::PrimaryHDU::writeImage%3AF9A0E102E2.body
  }

  // Additional Declarations
    //## begin CCfits::PrimaryHDU%380481CF79A8.declarations preserve=yes
    //## end CCfits::PrimaryHDU%380481CF79A8.declarations

} // namespace CCfits

//## begin module%3936C4EA03B5.epilog preserve=yes
//## end module%3936C4EA03B5.epilog


#endif
