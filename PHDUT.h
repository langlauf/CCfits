
//	This is CCfits version 1.0-beta release August 2001
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov
#ifndef PHDUT_H
#define PHDUT_H
#include "PrimaryHDU.h"
#include <iostream>
#include <exception>

namespace CCfits
{
        
        template <typename S>
        void PHDU::read (std::valarray<S>& image) throw (FitsException&)  
        {
                long init(1);
                long nElements(std::accumulate(naxes().begin(),naxes().end(),init,
                                std::multiplies<long>()));
                
                read(image,1,nElements,static_cast<S*>(0));
        }
        
        
        template <typename S>
        void  PHDU::read (std::valarray<S>& image, long first,long nElements) throw (FitsException&)  
        {
                read(image, first,nElements,static_cast<S*>(0));
        }
        
        template <typename S>
        void  PHDU::read (std::valarray<S>& image, long first, long nElements,  S* nullValue) 
                                                                        throw (FitsException&) 
        {
                try
                {
                        // proceed if cast is successful.
                        PrimaryHDU<S>& phdu = dynamic_cast<PrimaryHDU<S>&>(*this);
                        const std::valarray<S>& __tmp = phdu.readImage(first,nElements,nullValue);                           
                        image.resize(__tmp.size());
                        image = __tmp;
                }
                catch (...)
                {
                        if (bitpix() == Ifloat)
                        {
                                PrimaryHDU<float>& phdu 
                                                = dynamic_cast<PrimaryHDU<float>&>(*this);
                                float nulVal(0);
                                if (nullValue) nulVal = static_cast<float>(*nullValue);                                 
                                FITSUtil::fill(image,phdu.readImage(first,nElements,&nulVal));
                        }
                        else if (bitpix() == Idouble)
                        {
                                PrimaryHDU<double>& phdu 
                                                = dynamic_cast<PrimaryHDU<double>&>(*this);
                                double nulVal(0);
                                if (nullValue) nulVal = static_cast<double>(*nullValue);                                 
                                FITSUtil::fill(image,phdu.readImage(first,nElements,&nulVal));
                              
                        }
                        else if (bitpix() == Ibyte)
                        {
                                PrimaryHDU<unsigned char>& phdu 
                                                = dynamic_cast<PrimaryHDU<unsigned char>&>(*this);
                                unsigned char nulVal(0);
                                if (nullValue) nulVal = static_cast<unsigned char>(*nullValue);                                 
                                FITSUtil::fill(image,phdu.readImage(first,nElements,&nulVal));                               
                        } 
                        else if (bitpix() == Ilong)
                        {
                                PrimaryHDU<long>& phdu = dynamic_cast<PrimaryHDU<long>&>(*this);
                                long nulVal(0);
                                if (nullValue) nulVal = static_cast<long>(*nullValue);                                 
                                FITSUtil::fill(image,phdu.readImage(first,nElements,&nulVal));                              
                        }    
                        else if (bitpix() == Ishort)
                        {
                                PrimaryHDU<short>& phdu = dynamic_cast<PrimaryHDU<short>&>(*this);
                                short nulVal(0);
                                if (nullValue) nulVal = static_cast<short>(*nullValue);                                 
                                FITSUtil::fill(image,phdu.readImage(first,nElements,&nulVal));                             
                        }          
                        else if (bitpix() == Iulong)
                        {
                                PrimaryHDU<unsigned long>& phdu 
                                                = dynamic_cast<PrimaryHDU<unsigned long>&>(*this);
                                unsigned long nulVal(0);
                                if (nullValue) nulVal = static_cast<unsigned long>(*nullValue);                                 
                                FITSUtil::fill(image,phdu.readImage(first,nElements,&nulVal));                             
                        }    
                        else if (bitpix() == Iushort)
                        {
                                PrimaryHDU<unsigned short>& phdu
                                                = dynamic_cast<PrimaryHDU<unsigned short>&>(*this);
                                unsigned short nulVal(0);
                                if (nullValue) nulVal = static_cast<unsigned short>(*nullValue);                                 
                                FITSUtil::fill(image,phdu.readImage(first,nElements,&nulVal));                                
                        }     
                        else 
                        {
                                throw CCfits::FitsFatal(" casting image types ");
                        }     
                }

        }  
        
        template<typename S>
        void  PHDU::read (std::valarray<S>& image, const std::vector<long>& first, 
				long nElements, 
				S* nullValue) throw (FitsException&) 
        {
                long firstElement(0);
                long dimSize(1);
                std::vector<long> inputDimensions(naxis(),1);
                size_t n(std::min(naxis(),first.size()));
                std::copy(&first[0],&first[n],&inputDimensions[0]);                
                for (long i = 0; i < naxis(); ++i)
                {

                   firstElement +=  ((inputDimensions[i] - 1)*dimSize);
                   dimSize *=naxes(i);   
                }
                ++firstElement;                
                

                read(image, firstElement,nElements,nullValue);


                   
        } 

        template<typename S>
        void  PHDU::read (std::valarray<S>& image, const std::vector<long>& first, 
				long nElements) throw (FitsException&) 
        {
                read(image, firstElement,nElements,static_cast<S*>(0));
                   
        } 
                
        template<typename S>
        void  PHDU::read (std::valarray<S>& image, const std::vector<long>& firstVertex, 
				const std::vector<long>& lastVertex, 
				const std::vector<long>& stride, 
				S* nullValue) throw (FitsException&) 
        {
                try
                {
                        PrimaryHDU<S>& phdu = dynamic_cast<PrimaryHDU<S>&>(*this);
                        const std::valarray<S>& __tmp 
                                        = phdu.readImage(firstVertex,lastVertex,stride,nullValue);                         
                        image.resize(__tmp.size());
                        image = __tmp;
                }
                catch (...)
                {
                        // FITSutil::fill will take care of sizing.
                        if (bitpix() == Ifloat)
                        {
                                float nulVal(0);
                                if (nullValue) nulVal = static_cast<float>(*nullValue);                                 
                                PrimaryHDU<float>& phdu = dynamic_cast<PrimaryHDU<float>&>(*this);
                                FITSUtil::fill(image,
                                        phdu.readImage(firstVertex,lastVertex,stride,&nulVal));
                        }
                        else if (bitpix() == Idouble)
                        {
                                PrimaryHDU<double>& phdu = dynamic_cast<PrimaryHDU<double>&>(*this);
                                double nulVal(0);
                                if (nullValue) nulVal = static_cast<double>(*nullValue);                                 
                                FITSUtil::fill(image,
                                                phdu.readImage(firstVertex,lastVertex,stride,&nulVal));                              
                        }
                        else if (bitpix() == Ibyte)
                        {
                                PrimaryHDU<unsigned char>& phdu 
                                                = dynamic_cast<PrimaryHDU<unsigned char>&>(*this);
                                unsigned char nulVal(0);
                                if (nullValue) nulVal = static_cast<unsigned char>(*nullValue);                                 
                                FITSUtil::fill(image,
                                                phdu.readImage(firstVertex,lastVertex,stride,&nulVal));
                                return outputArray;                                
                        } 
                        else if (bitpix() == Ilong)
                        {
                                PrimaryHDU<long>& phdu = dynamic_cast<PrimaryHDU<long>&>(*this);
                                long nulVal(0);
                                if (nullValue) nulVal = static_cast<long>(*nullValue);                                 
                                FITSUtil::fill(image,
                                                phdu.readImage(firstVertex,lastVertex,stride,&nulVal));                            
                        }    
                        else if (bitpix() == Ishort)
                        {
                                PrimaryHDU<short>& phdu = dynamic_cast<PrimaryHDU<short>&>(*this);
                                short nulVal(0);
                                if (nullValue) nulVal = static_cast<short>(*nullValue);                                 
                                FITSUtil::fill(image,
                                                phdu.readImage(firstVertex,lastVertex,stride,&nulVal));                               
                        }          
                        else if (bitpix() == Iulong)
                        {
                                PrimaryHDU<unsigned long>& phdu 
                                                = dynamic_cast<PrimaryHDU<unsigned long>&>(*this);
                                unsigned long nulVal(0);
                                if (nullValue) nulVal = static_cast<unsigned long>(*nullValue);                                 
                                FITSUtil::fill(image,
                                                phdu.readImage(firstVertex,lastVertex,stride,&nulVal));                            
                        }    
                        else if (bitpix() == Iushort)
                        {
                                PrimaryHDU<unsigned short>& phdu 
                                                = dynamic_cast<PrimaryHDU<unsigned short>&>(*this);
                                unsigned short nulVal(0);
                                if (nullValue) nulVal = static_cast<unsigned short>(*nullValue);                                 
                                FITSUtil::fill(image,
                                                phdu.readImage(firstVertex,lastVertex,stride,&nulVal));                             
                        }     
                        else 
                        {
                                throw CCfits::FitsFatal(" casting image types ");
                        }     
                }
        }  

        template<typename S>
        void  PHDU::read (std::valarray<S>& image, const std::vector<long>& firstVertex, 
				const std::vector<long>& lastVertex, 
				const std::vector<long>& stride) throw (FitsException&) 
        {
                read(image, firstVertex,lastVertex,stride,static_cast<S*>(0));
        }  

        template <typename S>
        void PHDU::write(long first,
                            long nElements,
                        const std::valarray<S>& data,
                        S* nullValue)
        {                
                
                // for integer types, must do the null value substitution before
                // data conversion.
                
                try
                {

                        PrimaryHDU<S>& image = dynamic_cast<PrimaryHDU<S>&>(*this);
                        image.writeImage(first,nElements,data,nullValue);

                        
                }
                catch (...)
                {
                        if (bitpix() == Ifloat)
                        {
                                std::valarray<float> __tmp;                               
                                PrimaryHDU<float>& phdu = dynamic_cast<PrimaryHDU<float>&>(*this);
                                FITSUtil::fill(__tmp,data);
                                phdu.writeImage(first,nElements,__tmp,static_cast<float*>(nullValue));
                        }
                        else if (bitpix() == Idouble)
                        {
                                std::valarray<double> __tmp;                                
                                PrimaryHDU<double>& phdu 
                                                = dynamic_cast<PrimaryHDU<double>&>(*this);
                                FITSUtil::fill(__tmp,data);
                                phdu.writeImage(first,nElements,__tmp,
                                                static_cast<double*>(nullValue));                              
                        }
                        else if (bitpix() == Ibyte)
                        {
                                PrimaryHDU<unsigned char>& phdu 
                                                = dynamic_cast<PrimaryHDU<unsigned char>&>(*this);
                                std::valarray<unsigned char> __tmp;         
                                unsigned char blankVal(0);      
                                try 
                                {
                                        readKey("BLANK",blankVal);
                                        std::valarray<S> copyData(data);
                                        std::replace(&copyData[0],&copyData[data.size()],
                                                static_cast<unsigned char>(*nullValue),blankVal);
                             
                                        FITSUtil::fill(__tmp,copyData);                                        

                                        phdu.writeImage(first,nElements,__tmp);                          }
                                catch (HDU::NoSuchKeyword)
                                {
                                        throw NoNullValue("Primary");
                                }

                        } 
                        else if (bitpix() == Ilong)
                        {                               
                                PrimaryHDU<long>& phdu = dynamic_cast<PrimaryHDU<long>&>(*this);
                                std::valarray<long> __tmp;   
                                long blankVal(0);                              
                                try 
                                {
                                        readKey("BLANK",blankVal);
                                        std::valarray<S> copyData(data);
                                        std::replace(&copyData[0],&copyData[data.size()],
                                             static_cast<long>(*nullValue),blankVal);
       
                                        FITSUtil::fill(__tmp,copyData);                                        
                                        phdu.writeImage(first,nElements,__tmp);                          
                                }
                                catch (HDU::NoSuchKeyword)
                                {
                                        throw NoNullValue("Primary");
                                }                        
                        }    
                        else if (bitpix() == Ishort)
                        {
                                PrimaryHDU<short>& phdu 
                                                = dynamic_cast<PrimaryHDU<short>&>(*this);
                                std::valarray<short> __tmp;   
                                short blankVal(0);                             
                                try 
                                {
                                        readKey("BLANK",blankVal);
                                        std::valarray<S> copyData(data);
                                        std::replace(&copyData[0],&copyData[data.size()],
                                                 static_cast<short>(*nullValue),blankVal);
       
                                        FITSUtil::fill(__tmp,copyData);                                        
                                        phdu.writeImage(first,nElements,__tmp);                          
                                }
                                catch (HDU::NoSuchKeyword)
                                {
                                        throw NoNullValue("Primary");
                                }   
                        }        
                        else if (bitpix() == Iulong)
                        {
                                PrimaryHDU<unsigned long>& phdu
                                                = dynamic_cast<PrimaryHDU<unsigned long>&>(*this);
                                std::valarray<unsigned long> __tmp;
                                unsigned long blankVal(0);
                                try 
                                {
                                        readKey("BLANK",blankVal);
                                        std::valarray<S> copyData(data);
                                        std::replace(&copyData[0],&copyData[data.size()],
                                                static_cast<unsigned long>(*nullValue),blankVal);
       
                                        FITSUtil::fill(__tmp,copyData);                                        
                                        phdu.writeImage(first,nElements,__tmp);                          
                                }
                                catch (HDU::NoSuchKeyword)
                                {
                                        throw NoNullValue("Primary");
                                }                           
                        }    
                        else if (bitpix() == Iushort)
                        {
                                PrimaryHDU<unsigned short>& phdu
                                                = dynamic_cast<PrimaryHDU<unsigned short>&>(*this);
                                std::valarray<unsigned short> __tmp;
                                unsigned short blankVal(0);
                                try 
                                {
                                        readKey("BLANK",blankVal);
                                        std::valarray<S> copyData(data);
                                        std::replace(&copyData[0],&copyData[data.size()],
                                             static_cast<unsigned short>(*nullValue),blankVal);
       
                                        FITSUtil::fill(__tmp,copyData);                                        
                                        phdu.writeImage(first,nElements,__tmp);                          
                                }
                                catch (HDU::NoSuchKeyword)
                                {
                                        throw NoNullValue("Primary");
                                }                           
                        }     
                        else 
                        {
                                throw CCfits::FitsFatal(" casting image types ");
                        }     
                }
        }

  
        template <typename S>
        void PHDU::write(long first,
                            long nElements,
                        const std::valarray<S>& data)
        {                
                
                // for integer types, must do the null value substitution before
                // data conversion.
                
                try
                {
                        PrimaryHDU<S>& image = dynamic_cast<PrimaryHDU<S>&>(*this);
                        image.writeImage(first,nElements,data);
                }
                catch (...)
                {
                        if (bitpix() == Ifloat)
                        {
                                std::valarray<float> __tmp;                               
                                PrimaryHDU<float>& phdu = dynamic_cast<PrimaryHDU<float>&>(*this);
                                FITSUtil::fill(__tmp,data);
                                phdu.writeImage(first,nElements,__tmp);
                        }
                        else if (bitpix() == Idouble)
                        {
                                std::valarray<double> __tmp;                                
                                PrimaryHDU<double>& phdu 
                                                = dynamic_cast<PrimaryHDU<double>&>(*this);
                                FITSUtil::fill(__tmp,data);
                                phdu.writeImage(first,nElements,__tmp);                              
                        }
                        else if (bitpix() == Ibyte)
                        {
                                PrimaryHDU<unsigned char>& phdu 
                                                = dynamic_cast<PrimaryHDU<unsigned char>&>(*this);
                                std::valarray<unsigned char> __tmp;         
                                FITSUtil::fill(__tmp,data);                                        
                                phdu.writeImage(first,nElements,__tmp);
                        } 
                        else if (bitpix() == Ilong)
                        {                               
                                PrimaryHDU<long>& phdu = dynamic_cast<PrimaryHDU<long>&>(*this);
                                std::valarray<long> __tmp;   
                                FITSUtil::fill(__tmp,data);                                        
                                phdu.writeImage(first,nElements,__tmp);                          
                        }    
                        else if (bitpix() == Ishort)
                        {
                                PrimaryHDU<short>& phdu 
                                                = dynamic_cast<PrimaryHDU<short>&>(*this);
                                std::valarray<short> __tmp;   
                                FITSUtil::fill(__tmp,data);                                        
                                phdu.writeImage(first,nElements,__tmp);                          
                        }        
                        else if (bitpix() == Iulong)
                        {
                                PrimaryHDU<unsigned long>& phdu
                                                = dynamic_cast<PrimaryHDU<unsigned long>&>(*this);
                                std::valarray<unsigned long> __tmp;
                                FITSUtil::fill(__tmp,data);                                        
                                phdu.writeImage(first,nElements,__tmp);                          
                        }    
                        else if (bitpix() == Iushort)
                        {
                                PrimaryHDU<unsigned short>& phdu
                                                = dynamic_cast<PrimaryHDU<unsigned short>&>(*this);
                                std::valarray<unsigned short> __tmp;
                                FITSUtil::fill(__tmp,data);                                        
                                phdu.writeImage(first,nElements,__tmp); 
                        }     
                        else 
                        {
                                throw CCfits::FitsFatal(" casting image types ");
                        }     
                }
        }        
              
        template <typename S>
        void PHDU::write(const std::vector<long>& first,
                        long nElements,
                        const std::valarray<S>& data,
                        S* nullValue)
        {        
                size_t n(first.size());
                long firstElement(0);
                long dimSize(1);
                for (long i = 0; i < first.size(); ++i)
                {
                        firstElement +=  ((first[i] - 1)*dimSize);
                        dimSize *=naxes(i);   
                }       
                ++firstElement;
                
                write(firstElement,nElements,data,nullValue);
        }
        
        template <typename S>
        void PHDU::write(const std::vector<long>& first,
                        long nElements,
                        const std::valarray<S>& data)
        {        
                size_t n(first.size());
                long firstElement(0);
                long dimSize(1);
                for (long i = 0; i < first.size(); ++i)
                {

                        firstElement +=  ((first[i] - 1)*dimSize);
                        dimSize *=naxes(i);   
                }       
                ++firstElement;
                
                write(firstElement,nElements,data);                     
        }        
        

        template <typename S>
        void PHDU::write(const std::vector<long>& firstVertex,
                        const std::vector<long>& lastVertex,
                        const std::valarray<S>& data)
        {
                try
                {
                        PrimaryHDU<S>& phdu = dynamic_cast<PrimaryHDU<S>&>(*this);
                        phdu.writeImage(firstVertex,lastVertex,stride,data);  
                }
                // WRONG but will do for a test. it should be std::bad_cast or
                // std::exception& and let FitsErrors propagate upward.
                catch (...)
                {
                         // write input type S to Image type...

                        if (bitpix() == Ifloat)
                        {
                                PrimaryHDU<float>& phdu = dynamic_cast<PrimaryHDU<float>&>(*this);
                                size_t n(data.size());
                                std::valarray<float> __tmp(n);
                                for (size_t j= 0; j < n; ++j) __tmp[j] = data[j];
                                phdu.writeImage(firstVertex,lastVertex,stride,__tmp);

                        }
                        else if (bitpix() == Idouble)
                        {
                                PrimaryHDU<double>& phdu 
                                        = dynamic_cast<PrimaryHDU<double>&>(*this);
                                size_t n(data.size());
                                std::valarray<double> __tmp(n);
                                for (size_t j= 0; j < n; ++j) __tmp[j] = data[j];
                                phdu.writeImage(firstVertex,lastVertex,stride,__tmp);
                        }
                        else if (bitpix() == Ibyte)
                        {
                                PrimaryHDU<unsigned char>& phdu 
                                        = dynamic_cast<PrimaryHDU<unsigned char>&>(*this);
                                size_t n(data.size());
                                std::valarray<unsigned char> __tmp(n);
                                for (size_t j= 0; j < n; ++j) __tmp[j] = data[j];
                                phdu.writeImage(firstVertex,lastVertex,stride,__tmp);                        
                        } 
                        else if (bitpix() == Ilong)
                        {
                                PrimaryHDU<long>& phdu = dynamic_cast<PrimaryHDU<long>&>(*this);
                                size_t n(data.size());
                                std::valarray<long> __tmp(n);
                                for (size_t j= 0; j < n; ++j) __tmp[j] = data[j];
                                phdu.writeImage(firstVertex,lastVertex,stride,__tmp);                               
                        }    
                        else if (bitpix() == Ishort)
                        {
                                PrimaryHDU<short>& phdu = dynamic_cast<PrimaryHDU<short>&>(*this);
                                size_t n(data.size());
                                std::valarray<short> __tmp(n);
                                for (size_t j= 0; j < n; ++j) __tmp[j] = data[j];
                                phdu.writeImage(firstVertex,lastVertex,stride,__tmp);                         
                        }          
                        else if (bitpix() == Iulong)
                        {
                                PrimaryHDU<unsigned long>& phdu = dynamic_cast<PrimaryHDU<unsigned long>&>(*this);
                                size_t n(data.size());
                                std::valarray<unsigned long> __tmp(n);
                                for (size_t j= 0; j < n; ++j) __tmp[j] = data[j];
                                phdu.writeImage(firstVertex,lastVertex,stride,__tmp);                              
                        }    
                        else if (bitpix() == Iushort)
                        {
                                PrimaryHDU<unsigned short>& 
                                        phdu = dynamic_cast<PrimaryHDU<unsigned short>&>(*this);
                                size_t n(data.size());
                                std::valarray<unsigned short> __tmp(n);
                                for (size_t j= 0; j < n; ++j) __tmp[j] = data[j];
                                phdu.writeImage(firstVertex,lastVertex,stride,__tmp);                               
                        }     
                        else 
                        {
                                throw CCfits::FitsFatal(" casting image types ");
                        }     
                }  
        }  
        
                
        
        
} // namespace CCfits
#endif
