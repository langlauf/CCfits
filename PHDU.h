//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%380395D38528.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%380395D38528.cm

//## begin module%380395D38528.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%380395D38528.cp

//## Module: PHDU%380395D38528; Package specification
//## Subsystem: CCfits::HDU%3826DF628F48
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/PHDU.h

#ifndef PHDU_H
#define PHDU_H 1

//## begin module%380395D38528.additionalIncludes preserve=no
//## end module%380395D38528.additionalIncludes

// valarray
#include <valarray>
// HDU
#include "HDU.h"
// FITS
#include "FITS.h"
// FITSUtil
#include "FITSUtil.h"

namespace CCfits {
  class FITSBase;

} // namespace CCfits

//## begin module%380395D38528.includes preserve=yes
// for CLONE_DEFECT
#ifdef _MSC_VER
#include "MSconfig.h"
#endif
//## end module%380395D38528.includes

//## begin module%380395D38528.declarations preserve=no
//## end module%380395D38528.declarations

//## begin module%380395D38528.additionalDeclarations preserve=yes
//## end module%380395D38528.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  
  /*! \class PHDU
        \brief class representing the primary HDU for a FITS file.
        
        A PHDU object is automatically instantiated and added to a FITS
        object when a FITS file is accessed in any way. If a new file
        is created without specifying the data type for the header, CCfits
        assumes that the file is to be used for table extensions and creates
        a dummy header. PHDU instances are <i>only</i> created by FITS
        ctors. In the first release of CCfits, the Primary cannot be changed once
        declared.
        
        PHDU and ExtHDU provide the same interface to writing images: multiple
        overloads of the templated PHDU::read and PHDU::write operations provide
        for (a) writing image data specified in a number of ways [C-array, std::vector, 
        std::valarray] and with input location specified by
         initial pixel, by n-tuple, and by rectangular subset [generalized slice];
        (b) reading image data specified similarly to the write options into a std::valarray.
        
        \todo Implement functions that allow replacement of the primary image
  
  */
  
  /*! \fn PHDU::PHDU (FITSBase* p, int bpix, int naxis, const std::vector<long>& axes)
  
  \brief Writing Primary HDU constructor, called by PrimaryHDU<T> class
  
   Constructor used for creating new PHDU (i.e. for writing data to FITS).
   also doubles as default constructor since all arguments have default values,
  which are passed to the HDU constructor
   
  
  
  */

/* !\fn  PHDU::PHDU (FITSBase* p)

    \brief Reading Primary HDU constructor.
   Constructor used  when reading the primary HDU from an existing file.
    Does nothing except initialize, with the real work done by the subclass
    PrimaryHDU<T>.
         
*/

/* !\fn  PHDU::~PHDU();

        \brief destructor
*/

/* !\fn  virtual void PHDU::readData (bool readFlag = false, const std::vector<String>& keys = std::vector<String>())  = 0;
        \brief read primary HDU data
                        
        Called by FITS ctor, not intended for general use.
        parameters control how much gets read on initialization. An abstract function,
        implemented in the subclasses.
                        
        \param readFlag read the image data if true
        \param key      a vector of strings of keyword names to be read from the primary HDU                        



*/

/* !\fn  virtual PHDU::clone(FITSbase* p) const = 0;

        \brief virtual copy constructor for Primary HDUs. 
                        
        The operation is used when creating a copy of a FITS object.
                

*/

                        
                        
/*! \fn      template<typename S> void PHDU::read (std::valarray<S>& image, 
                                        long first,
                                        long nElements, 
                                        S* nullValue) ; 
        
                \brief read part of an image array, processing null values.
                                
                Implicit data conversion is supported (i.e. user does not need to know the 
                type of the data stored. A WrongExtensionType extension is thrown
                if *this is not an image. 
                                
                \param image The receiving container, a std::valarray reference 
                \param first The first pixel from the array to read [a long value]
                \param nElements The number of values to read
                \param nullValue A pointer containing the value in the table to be 
                        considered as undefined. See cfitsio for details
                

*/      
                
/*! \fn      template<typename S> void PHDU::read (std::valarray<S>& image, 
                                const std::vector<long>& first, 
		                long nElements, 
                                S* nullValue) ;
                                
             \brief read part of an image array, processing null values.
                             
             As above except for 
                             
             \param first a vector<long> representing an n-tuple giving the
                    coordinates in the image of the first pixel.
 

*/      
/*! \fn      template<typename S> void PHDU::read (std::valarray<S>& image, 
                                const std::vector<long>& firstVertex, 
		                const std::vector<long>& lastVertex, 
		                const std::vector<long>& stride, 
                                S* nullValue) ; 
                                
                                
             \brief read an image subset into valarray image, processing null values
                             
                The image subset is defined by two vertices and a stride
                indicating the 'denseness' of the values to be picked in each
                dimension (a stride = (1,1,1,...) means picking every 
                pixel in every dimension, whereas stride = (2,2,2,...)
                means picking every other value in each dimension.
                             
                             
*/      
/*! \fn      template<typename S> void PHDU::read (std::valarray<S>& image, 
                                long first,
                                long nElements); 
                        
              \brief read an image section starting at a specified pixel

*/      
                
/*! \fn      template<typename S> void PHDU::read (std::valarray<S>& image, 
                                const std::vector<long>& first,
                                long nElements); 
                                                   
              \brief read an image section starting at a location specified by an n-tuple
*/      
/*! \fn      template<typename S> void PHDU::read (std::valarray<S>& image, 
                                const std::vector<long>& firstVertex, 
		                const std::vector<long>& lastVertex, 
		                const std::vector<long>& stride);    


                \brief read an image subset

*/

/*! \fn      template <typename S> void PHDU::write(const std::vector<long>& first,
                    long nElements,
                    const std::valarray<S>& data,
                    S* nullValue);
                    
        \brief Write a set of pixels to an image extension with the first pixel specified by an n-tuple, processing undefined data

        All the overloaded versions of PHDU::write perform operations on *this if
        it is an image and throw a WrongExtensionType exception if not.
        Where appropriate, alternate versions allow undefined data to be processed
                        
        \param first an n-tuple of dimension equal to the image dimension specifying the 
                first pixel in the range to be written
        \param nElements number of pixels to be written
        \param data array of data to be written
        \param pointer to null value (data with this value written as undefined; needs
                the BLANK keyword to have been specified).
                                
*/
                        
      
/*! \fn template <typename S> void PHDU::write(long first,
                    long nElements, const std::valarray<S>& data, S* nullValue);
                
        \brief write array to image starting with a specified pixel and allowing undefined data to be processed
                        
        parameters after the first are as for version with n-tuple specifying first element.
        these two version are equivalent, except that it is possible for the
        first pixel number to exceed the range of 32-bit integers, which is
        how long datatype is commonly implemented.                
*/
                
/*! \fn template <typename S> void PHDU::write(const std::vector<long>& first,
                    long nElements, const std::valarray<S>& data);
                
        \brief write array starting from specified n-tuple, without undefined data processing
*/
                
/*! \fn template <typename S> void PHDU::write(long first, long nElements,
                    const std::valarray<S>& data);
                    
        \brief write array starting from specified pixel number, without undefined data processing
             
                    
*/
                
/*! \fn      template <typename S> void PHDU::write(const std::vector<long>& firstVertex,
                    const std::vector<long>& lastVertex,
                    const std::valarray<S>& data);     
                
              \brief write a subset (generalize slice) of data to the image
                        
                A generalized slice/subset is a subset of the image (e.g. one plane
                of a data cube of size <= the dimension of the cube). It is specified
                by two opposite vertices. The equivalent cfitsio call does not support
                undefined data processing so there is no version that allows a null
                value to be specified.
                              
                \param firstVertex the coordinates specifying lower and upper vertices of the n-dimensional slice 
                \param lastVertex
                \param data The data to be written              
*/

/*! \fn  PHDU::PHDU(const PHDU& right)
        \brief copy constructor
        
        required for cloning primary HDUs when copying FITS files.


*/



  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::PHDU%394E6F7701E6.preface preserve=yes
  //## end CCfits::PHDU%394E6F7701E6.preface

  //## Class: PHDU%394E6F7701E6
  //## Category: CCfits::HDU%393417220088
  //## Subsystem: CCfits::HDU%3826DF628F48
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%394F74E90318;FITS { -> F}
  //## Uses: <unnamed>%3A15B4790261;FITSBase { -> F}

  class PHDU : public HDU  //## Inherits: <unnamed>%394E6F9800C3
  {
    //## begin CCfits::PHDU%394E6F7701E6.initialDeclarations preserve=yes
    //## end CCfits::PHDU%394E6F7701E6.initialDeclarations

    public:
      //## Destructor (generated)
        virtual ~PHDU();


      //## Other Operations (specified)
        //## Operation: readData%394E78E40315
        //	Read data reads the image if readFlag is true and
        //	optional keywords if supplied. Thus, with no arguments,
        //	readData() does nothing.
        virtual void readData (bool readFlag = false, const std::vector<String>& keys = std::vector<String>()) = 0;

        //## Operation: clone%395A11CD034A
        virtual PHDU * clone (FITSBase* p) const = 0;

        //## Operation: zero%3CE2A915005C
        virtual void zero (double value);

        //## Operation: scale%3CE2A93801B9
        virtual void scale (double value);

        //## Operation: zero%3CE2ABAB01E6
        virtual double zero () const;

        //## Operation: scale%3CE2ABDC0224
        virtual double scale () const;

    public:
      // Additional Public Declarations
        //## begin CCfits::PHDU%394E6F7701E6.public preserve=yes
      // image reading/writing interface. 
                    
      // The S template parameter, like for Column, denotes the fact that
      // the type of the input array and the object to be read may not match.
      
                    
      // the rw interface for images consists of equivalents for fits_read_img,
      // fits_read_pix, and fits_read_subset.
      
      // the paradigm for reading is that the image object (a valarray<T> type)
      // is the size of the data already read.
      
      // write_subset has no null value aware analogue.
        template <typename S>
        void write(const std::vector<long>& first,
                        long nElements,
                        const std::valarray<S>& data,
                        S* nullValue);


        template <typename S>
        void write(long first,
                        long nElements,
                        const std::valarray<S>& data,
                        S* nullValue);
                     
                    
        template <typename S>
        void write(const std::vector<long>& first,
                        long nElements,
                        const std::valarray<S>& data);


        template <typename S>
        void write(long first,
                        long nElements,
                        const std::valarray<S>& data);

        template <typename S>
        void write(const std::vector<long>& firstVertex,
                        const std::vector<long>& lastVertex,
                        const std::vector<long>& stride, 
                        const std::valarray<S>& data); 
        
        // read image data and return an array. Can't return a reference
        // because the type conversion needs to allocate a new object in general.
        
        template<typename S>
        void read(std::valarray<S>& image) ; 
            
 	template<typename S>
        void  read (std::valarray<S>& image, long first,long nElements); 
                              
	template<typename S>
        void read (std::valarray<S>& image, long first,long nElements, S* nullValue) ; 

	template<typename S>
        void read (std::valarray<S>& image, const std::vector<long>& first,long nElements)  ; 
        
	template<typename S>
        void read (std::valarray<S>& image, const std::vector<long>& first, long nElements, 
                                        S* nullValue); 
        
        template<typename S>
        void read (std::valarray<S>& image, const std::vector<long>& firstVertex, 
				const std::vector<long>& lastVertex, 
				const std::vector<long>& stride)  ;      
         
        template<typename S>
        void read (std::valarray<S>& image, const std::vector<long>& firstVertex, 
				const std::vector<long>& lastVertex, 
				const std::vector<long>& stride, 
                                S* nullValue) ; 

        
        
        //## end CCfits::PHDU%394E6F7701E6.public
    protected:
      //## Constructors (generated)
        PHDU(const PHDU &right);

      //## Constructors (specified)
        //## Operation: PHDU%394E738D0238
        //	Constructor for new FITS objects, takes as arguments
        //	the required keywords for a primary HDU.
        PHDU (FITSBase* p, int bpix, int naxis, const std::vector<long>& axes);

        //## Operation: PHDU%394E754400FE
        //	Custom constructor. Allows specification of data to be read and whether to read data at
        //	construction or wait until the image data are requested. The default is 'lazy initialization:'
        //	wait until asked.
        PHDU (FITSBase* p = 0);


      //## Other Operations (specified)
        //## Operation: initRead%394E714C0347
        virtual void initRead ();

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: simple%394E7070015C
        bool simple () const;
        void simple (bool value);

        //## Attribute: extend%394E708A0006
        bool extend () const;
        void extend (bool value);

      // Additional Protected Declarations
        //## begin CCfits::PHDU%394E6F7701E6.protected preserve=yes
        //## end CCfits::PHDU%394E6F7701E6.protected

    private:
      // Additional Private Declarations
        //## begin CCfits::PHDU%394E6F7701E6.private preserve=yes
        //## end CCfits::PHDU%394E6F7701E6.private

    private: //## implementation
      // Data Members for Class Attributes

        //## begin CCfits::PHDU::simple%394E7070015C.attr preserve=no  protected: bool {U} true
        bool m_simple;
        //## end CCfits::PHDU::simple%394E7070015C.attr

        //## begin CCfits::PHDU::extend%394E708A0006.attr preserve=no  protected: bool {U} true
        bool m_extend;
        //## end CCfits::PHDU::extend%394E708A0006.attr

      // Additional Implementation Declarations
        //## begin CCfits::PHDU%394E6F7701E6.implementation preserve=yes
        //## end CCfits::PHDU%394E6F7701E6.implementation

  };

  //## begin CCfits::PHDU%394E6F7701E6.postscript preserve=yes
  //## end CCfits::PHDU%394E6F7701E6.postscript

  // Class CCfits::PHDU 

  //## Get and Set Operations for Class Attributes (inline)

  inline bool PHDU::simple () const
  {
    //## begin CCfits::PHDU::simple%394E7070015C.get preserve=no
    return m_simple;
    //## end CCfits::PHDU::simple%394E7070015C.get
  }

  inline void PHDU::simple (bool value)
  {
    //## begin CCfits::PHDU::simple%394E7070015C.set preserve=no
    m_simple = value;
    //## end CCfits::PHDU::simple%394E7070015C.set
  }

  inline bool PHDU::extend () const
  {
    //## begin CCfits::PHDU::extend%394E708A0006.get preserve=no
    return m_extend;
    //## end CCfits::PHDU::extend%394E708A0006.get
  }

  inline void PHDU::extend (bool value)
  {
    //## begin CCfits::PHDU::extend%394E708A0006.set preserve=no
    m_extend = value;
    //## end CCfits::PHDU::extend%394E708A0006.set
  }

} // namespace CCfits

//## begin module%380395D38528.epilog preserve=yes
//## end module%380395D38528.epilog


#endif
