
//	This is CCfits version 1.0-beta release August 2001

//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov




// PHDU
#include "PHDU.h"
// FITS
#include "FITS.h"
// FITSBase
#include "FITSBase.h"





namespace CCfits {

  // Class CCfits::PHDU 




  PHDU::PHDU(const PHDU &right)
        : HDU(right), m_simple(true),
          m_extend(true)
  {
  }

  PHDU::PHDU (FITSBase* p, int bpix, int naxis, const std::vector<long>& axes)
      : HDU(p,bpix,naxis, axes), m_simple(true), m_extend(true)
  {
   long *naxesArray=0;
   int  status=0;
   FITSUtil::Carray<long> convert;

   naxesArray = convert(axes);

   if (fits_create_img(fitsPointer(), bpix, naxis, naxesArray, &status) != 0)  
                throw FitsError(status);
   
   if (fits_flush_file(fitsPointer(),&status)) throw FitsError(status);
   index(0);
   
   delete [] naxesArray;  
  }

  PHDU::PHDU (FITSBase* p)
  //! Reading Primary HDU constructor.
  /*! Constructor used  when reading the primary HDU from an existing file.
  *  Does nothing except initialize, with the real work done by the subclass
  *  PrimaryHDU<T>.
  */       
        : HDU(p), m_simple(true),
        m_extend(true)
  {
  }


  PHDU::~PHDU()
  {
  //! Destructor
  }



  void PHDU::initRead ()
  {
           //! Read image header and update fits pointer accordingly. 
           /*! Private: called by ctor.  
           */

           long  pcount=0, gcount=0;
           int   status=0;
           int   simp = 0;
           int   xtend = 0;
           int   numAxes = 0;

           if (fits_get_img_dim(fitsPointer(), &numAxes, &status) != 0)  
           {
                   throw FitsError(status);
           }

           naxis() = numAxes;

           FITSUtil::auto_array_ptr<long> pAxes(0); 
           if (numAxes > 0) pAxes.reset(new long[numAxes]);
           long* axes(pAxes.get());
           int bpix = 0;

           if (fits_read_imghdr(fitsPointer(), MAXDIM, &simp, &bpix, &numAxes,
			             axes, &pcount, &gcount, &xtend, &status) != 0)  
               throw FitsError(status);

           bitpix(bpix);
           simple(simp != 0);
           extend(xtend != 0);

           if  (numAxes > 0)
           {
                naxes().resize(naxis()); 
                std::copy(&axes[0],&axes[numAxes],naxes().begin());
           }
  }

  // Additional Declarations

} // namespace CCfits

