
//	This is CCfits version 1.0-beta release August 2001
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov
#include "Image.h"

#include "FITSUtil.h"

 namespace CCfits {
                                       
  template<>
  void Image<long>::writeImage (fitsfile* fPtr, 
                                const std::vector<long>& firstVertex, 
                                const std::vector<long>& lastVertex, 
                                const std::valarray<long>& inData, 
                                const std::vector<long>& naxes) throw (FitsException&)
  {
        long* fPixel(0);
        long* lPixel(0);
        
        prepareForSubset(naxes,firstVertex,lastVertex,inData,fPixel,lPixel);

        FITSUtil::Carray<long> convert;
        FITSUtil::auto_array_ptr<long> pArray(convert(inData));
        long* array(pArray.get());
        
        long N(naxes.size());
        int status(0);
        long groupDum(0);
        FITSUtil::auto_array_ptr<long> pNaxes(new long[N]);
        long* Naxes(pNaxes.get());
        std::copy(naxes.begin(),naxes.end(),&Naxes[0]);
        
        if ( fits_write_subset_lng(fPtr,groupDum,N,Naxes,
                            fPixel,lPixel,array,&status) != 0) throw FitsError(status);
        
             
  }
 
  template<>
  void Image<short>::writeImage (fitsfile* fPtr, 
                                const std::vector<long>& firstVertex, 
                                const std::vector<long>& lastVertex, 
                                const std::valarray<short>& inData, 
                                const std::vector<long>& naxes) throw (FitsException&)
  {
        long* fPixel(0);
        long* lPixel(0);
        
        prepareForSubset(naxes,firstVertex,lastVertex,inData,fPixel,lPixel);

        FITSUtil::Carray<short> convert;
        FITSUtil::auto_array_ptr<short> pArray(convert(inData));
        short* array(pArray.get());
        
        long N(naxes.size());
        int status(0);
        long groupDum(0);
        FITSUtil::auto_array_ptr<long> pNaxes(new long[N]);
        long* Naxes(pNaxes.get());
        std::copy(naxes.begin(),naxes.end(),&Naxes[0]);
        
        if ( fits_write_subset_sht(fPtr,groupDum,N,Naxes,
                            fPixel,lPixel,array,&status) != 0) throw FitsError(status);
                  
  }
  

  template<>
  void Image<unsigned long>::writeImage (fitsfile* fPtr, 
                                const std::vector<long>& firstVertex, 
                                const std::vector<long>& lastVertex, 
                                const std::valarray<unsigned long>& inData, 
                                const std::vector<long>& naxes) throw (FitsException&)
  {
        long* fPixel(0);
        long* lPixel(0);
        
        prepareForSubset(naxes,firstVertex,lastVertex,inData,fPixel,lPixel);

        FITSUtil::Carray<unsigned long> convert;
        FITSUtil::auto_array_ptr<unsigned long> pArray(convert(inData));
        unsigned long* array(pArray.get());
        
        long N(naxes.size());
        int status(0);
        long groupDum(0);
        FITSUtil::auto_array_ptr<long> pNaxes(new long[N]);
        long* Naxes(pNaxes.get());
        std::copy(naxes.begin(),naxes.end(),&Naxes[0]);
        
        if ( fits_write_subset_ulng(fPtr,groupDum,N,Naxes,
                            fPixel,lPixel,array,&status) != 0) throw FitsError(status);
  }
  
  template<>
  void Image<unsigned short>::writeImage (fitsfile* fPtr, 
                                const std::vector<long>& firstVertex, 
                                const std::vector<long>& lastVertex, 
                                const std::valarray<unsigned short>& inData, 
                                const std::vector<long>& naxes) throw (FitsException&)
  {
        long* fPixel(0);
        long* lPixel(0);
        
        prepareForSubset(naxes,firstVertex,lastVertex,inData,fPixel,lPixel);

        FITSUtil::Carray<unsigned short> convert;
        FITSUtil::auto_array_ptr<unsigned short> pArray(convert(inData));
        unsigned short* array(pArray.get());
        
        long N(naxes.size());
        int status(0);
        long groupDum(0);
        FITSUtil::auto_array_ptr<long> pNaxes(new long[N]);
        long* Naxes(pNaxes.get());
        std::copy(naxes.begin(),naxes.end(),&Naxes[0]);
        
        if ( fits_write_subset_usht(fPtr,groupDum,N,Naxes,
                            fPixel,lPixel,array,&status) != 0) throw FitsError(status);          
  }
  template<>
  void Image<float>::writeImage (fitsfile* fPtr, 
                                const std::vector<long>& firstVertex, 
                                const std::vector<long>& lastVertex, 
                                const std::valarray<float>& inData, 
                                const std::vector<long>& naxes) throw (FitsException&)
  {
        long* fPixel(0);
        long* lPixel(0);
        
        prepareForSubset(naxes,firstVertex,lastVertex,inData,fPixel,lPixel);

        FITSUtil::Carray<float> convert;
        FITSUtil::auto_array_ptr<float> pArray(convert(inData));
        float* array(pArray.get());
        
        long N(naxes.size());
        int status(0);
        long groupDum(0);
        FITSUtil::auto_array_ptr<long> pNaxes(new long[N]);
        long* Naxes(pNaxes.get());
        std::copy(naxes.begin(),naxes.end(),&Naxes[0]);
        
        if ( fits_write_subset_flt(fPtr,groupDum,N,Naxes,
                            fPixel,lPixel,array,&status) != 0) throw FitsError(status);          
  }
  
  template<>
  void Image<double>::writeImage (fitsfile* fPtr, 
                                const std::vector<long>& firstVertex, 
                                const std::vector<long>& lastVertex, 
                                const std::valarray<double>& inData, 
                                const std::vector<long>& naxes) throw (FitsException&)
  {
        long* fPixel(0);
        long* lPixel(0);
        
        prepareForSubset(naxes,firstVertex,lastVertex,inData,fPixel,lPixel);

        FITSUtil::Carray<double> convert;
        FITSUtil::auto_array_ptr<double> pArray(convert(inData));
        double* array(pArray.get());
        
        long N(naxes.size());
        int status(0);
        long groupDum(0);
        FITSUtil::auto_array_ptr<long> pNaxes(new long[N]);
        long* Naxes(pNaxes.get());
        std::copy(naxes.begin(),naxes.end(),&Naxes[0]);
        
        if ( fits_write_subset_dbl(fPtr,groupDum,N,Naxes,
                            fPixel,lPixel,array,&status) != 0) throw FitsError(status);          
  }
  
  template<>
  void Image<unsigned char>::writeImage (fitsfile* fPtr, 
                                const std::vector<long>& firstVertex, 
                                const std::vector<long>& lastVertex, 
                                const std::valarray<unsigned char>& inData,  
                                const std::vector<long>& naxes) throw (FitsException&)
  {
        long* fPixel(0);
        long* lPixel(0);
        
        prepareForSubset(naxes,firstVertex,lastVertex,inData,fPixel,lPixel);

        FITSUtil::Carray<unsigned char> convert;
        FITSUtil::auto_array_ptr<unsigned char> pArray(convert(inData));
        unsigned char* array(pArray.get());
        
        long N(naxes.size());
        int status(0);
        long groupDum(0);
        FITSUtil::auto_array_ptr<long> pNaxes(new long[N]);
        long* Naxes(pNaxes.get());
        std::copy(naxes.begin(),naxes.end(),&Naxes[0]);
        
        if ( fits_write_subset_byt(fPtr,groupDum,N,Naxes,
                            fPixel,lPixel,array,&status) != 0) throw FitsError(status);          
  }

                  
} // namespace CCfits
