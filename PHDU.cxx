//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%380395D1F870.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%380395D1F870.cm

//## begin module%380395D1F870.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%380395D1F870.cp

//## Module: PHDU%380395D1F870; Package body
//## Subsystem: CCfits::HDU%3826DF628F48
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/PHDU.cxx

//## begin module%380395D1F870.additionalIncludes preserve=no
//## end module%380395D1F870.additionalIncludes

//## begin module%380395D1F870.includes preserve=yes
//## end module%380395D1F870.includes

// FITS
#include "FITS.h"
// FITSBase
#include "FITSBase.h"
// PHDU
#include "PHDU.h"


//## begin module%380395D1F870.declarations preserve=no
//## end module%380395D1F870.declarations

//## begin module%380395D1F870.additionalDeclarations preserve=yes
//## end module%380395D1F870.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  // Class CCfits::PHDU 

  PHDU::PHDU(const PHDU &right)
    //## begin PHDU::PHDU%394E6F7701E6_copy.hasinit preserve=yes
        : HDU(right), m_simple(true),
          m_extend(true)
    //## end PHDU::PHDU%394E6F7701E6_copy.hasinit
    //## begin PHDU::PHDU%394E6F7701E6_copy.initialization preserve=yes
    //## end PHDU::PHDU%394E6F7701E6_copy.initialization
  {
    //## begin CCfits::PHDU::PHDU%394E6F7701E6_copy.body preserve=yes
    //## end CCfits::PHDU::PHDU%394E6F7701E6_copy.body
  }

  PHDU::PHDU (FITSBase* p, int bpix, int naxis, const std::vector<long>& axes)
    //## begin CCfits::PHDU::PHDU%394E738D0238.hasinit preserve=yes
      : HDU(p,bpix,naxis, axes), m_simple(true), m_extend(true)
    //## end CCfits::PHDU::PHDU%394E738D0238.hasinit
    //## begin CCfits::PHDU::PHDU%394E738D0238.initialization preserve=yes
    //## end CCfits::PHDU::PHDU%394E738D0238.initialization
  {
    //## begin CCfits::PHDU::PHDU%394E738D0238.body preserve=yes
   long *naxesArray = 0;
   int  status (0);
   FITSUtil::CVarray<long> convert;

   naxesArray = convert(axes);

   if (fits_create_img(fitsPointer(), bpix, naxis, naxesArray, &status) != 0)  
                throw FitsError(status);
   
   if (fits_flush_file(fitsPointer(),&status)) throw FitsError(status);
   index(0);
   
   delete [] naxesArray;  
    //## end CCfits::PHDU::PHDU%394E738D0238.body
  }

  PHDU::PHDU (FITSBase* p)
    //## begin CCfits::PHDU::PHDU%394E754400FE.hasinit preserve=yes
  //! Reading Primary HDU constructor.
  /*! Constructor used  when reading the primary HDU from an existing file.
  *  Does nothing except initialize, with the real work done by the subclass
  *  PrimaryHDU<T>.
  */       
        : HDU(p), m_simple(true),
        m_extend(true)
    //## end CCfits::PHDU::PHDU%394E754400FE.hasinit
    //## begin CCfits::PHDU::PHDU%394E754400FE.initialization preserve=yes
    //## end CCfits::PHDU::PHDU%394E754400FE.initialization
  {
    //## begin CCfits::PHDU::PHDU%394E754400FE.body preserve=yes
    //## end CCfits::PHDU::PHDU%394E754400FE.body
  }


  PHDU::~PHDU()
  {
    //## begin CCfits::PHDU::~PHDU%394E6F7701E6_dest.body preserve=yes
  //! Destructor
    //## end CCfits::PHDU::~PHDU%394E6F7701E6_dest.body
  }



  //## Other Operations (implementation)
  void PHDU::initRead ()
  {
    //## begin CCfits::PHDU::initRead%394E714C0347.body preserve=yes
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
           long* axes = pAxes.get();
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
    //## end CCfits::PHDU::initRead%394E714C0347.body
  }

  void PHDU::zero (double value)
  {
    //## begin CCfits::PHDU::zero%3CE2A915005C.body preserve=yes
    HDU::zero(value);
    if ( naxis())
    {
        int status(0);
        if (fits_set_bscale(fitsPointer(),scale(),value,&status)) throw FitsError(status);
    }
    //## end CCfits::PHDU::zero%3CE2A915005C.body
  }

  void PHDU::scale (double value)
  {
    //## begin CCfits::PHDU::scale%3CE2A93801B9.body preserve=yes
    HDU::scale(value);
    if (naxis())
    {
        int status(0);
        if (fits_set_bscale(fitsPointer(),value,zero(),&status)) throw FitsError(status);
    }
    //## end CCfits::PHDU::scale%3CE2A93801B9.body
  }

  double PHDU::zero () const
  {
    //## begin CCfits::PHDU::zero%3CE2ABAB01E6.body preserve=yes
    //## end CCfits::PHDU::zero%3CE2ABAB01E6.body

    return HDU::zero();
  }

  double PHDU::scale () const
  {
    //## begin CCfits::PHDU::scale%3CE2ABDC0224.body preserve=yes
    //## end CCfits::PHDU::scale%3CE2ABDC0224.body

    return HDU::scale();
  }

  // Additional Declarations
    //## begin CCfits::PHDU%394E6F7701E6.declarations preserve=yes
    //## end CCfits::PHDU%394E6F7701E6.declarations

} // namespace CCfits

//## begin module%380395D1F870.epilog preserve=yes
//## end module%380395D1F870.epilog
