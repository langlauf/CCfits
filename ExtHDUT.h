
//	This is CCfits version 1.0-beta release August 2001
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov
#ifndef EXTHDUT_H
#define EXTHDUT_H
#include "ImageExt.h"
#include "Table.h"
#include "Column.h"

namespace CCfits 
{
        template <typename S>
        void ExtHDU::read (std::valarray<S>& image) throw (FitsException&)  
        {
                checkExtensionType();
                long init(1);
                long nElements(std::accumulate(naxes().begin(),naxes().end(),init,
                                std::multiplies<long>()));
                read(image,1,nElements,static_cast<S*>(0));

                
        }

        

        template <typename S>
        void ExtHDU::read (std::valarray<S>& image, long first,long nElements) 
                                                                throw (FitsException&)  
        {
                checkExtensionType();
                read(image, first,nElements,static_cast<S*>(0));
        }
        
        template <typename S>
        void ExtHDU::read (std::valarray<S>& image, long first, long nElements,  S* nulValue) 
                                                                        throw (FitsException&) 
        {
                checkExtensionType();
                
                try
                {
                        // proceed if cast is successful.
                        ImageExt<S>& extimage = dynamic_cast<ImageExt<S>&>(*this);                          
                        const std::valarray<S>& __tmp 
                                        = extimage.readImage(first,nElements,nulValue);
                        image.resize(__tmp.size());
                        image = __tmp;
                }
                catch (std::bad_cast)
                {
                        if (bitpix() == Ifloat)
                        {
                                ImageExt<float>& extimage 
                                                = dynamic_cast<ImageExt<float>&>(*this);
                                float nulVal(0);
                                if (nulValue) nulVal = static_cast<float>(*nulValue);                                 
                                FITSUtil::fill(image,
                                                extimage.readImage(first,nElements,&nulVal));
                        }
                        else if (bitpix() == Idouble)
                        {
                                ImageExt<double>& extimage 
                                                = dynamic_cast<ImageExt<double>&>(*this);
                                double nulVal(0);
                                if (nulValue) nulVal = static_cast<double>(*nulValue);                                 
                                FITSUtil::fill(image,
                                                extimage.readImage(first,nElements,&nulVal));
                        }
                        else if (bitpix() == Ibyte)
                        {
                                ImageExt<unsigned char>& extimage 
                                                = dynamic_cast<ImageExt<unsigned char>&>(*this);
                                unsigned char nulVal(0);
                                if (nulValue) nulVal = static_cast<unsigned char>(*nulValue);                                 
                                FITSUtil::fill(image,
                                                extimage.readImage(first,nElements,&nulVal));
                        } 
                        else if (bitpix() == Ilong)
                        {
                                ImageExt<long>& extimage = dynamic_cast<ImageExt<long>&>(*this);
                                long nulVal(0);
                                if (nulValue) nulVal = static_cast<long>(*nulValue);                                 
                                FITSUtil::fill(image,
                                                extimage.readImage(first,nElements,&nulVal));
                        }    
                        else if (bitpix() == Ishort)
                        {
                                ImageExt<short>& extimage = dynamic_cast<ImageExt<short>&>(*this);
                                short nulVal(0);
                                if (nulValue) nulVal = static_cast<short>(*nulValue);                                 
                                FITSUtil::fill(image,
                                                extimage.readImage(first,nElements,&nulVal));
                        }          
                        else if (bitpix() == Iulong)
                        {
                                ImageExt<unsigned long>& extimage 
                                                = dynamic_cast<ImageExt<unsigned long>&>(*this);
                                unsigned long nulVal(0);
                                if (nulValue) nulVal = static_cast<unsigned long>(*nulValue);                                 
                                FITSUtil::fill(image,
                                                extimage.readImage(first,nElements,&nulVal));
                        }    
                        else if (bitpix() == Iushort)
                        {
                                ImageExt<unsigned short>& extimage
                                                = dynamic_cast<ImageExt<unsigned short>&>(*this);
                                unsigned short nulVal(0);
                                if (nulValue) nulVal = static_cast<unsigned short>(*nulValue);                                 
                                FITSUtil::fill(image,
                                                extimage.readImage(first,nElements,&nulVal));
                        }     
                        else 
                        {
                                throw CCfits::FitsFatal(" casting image types ");
                        }     
                }

        }  
        
        template<typename S>
        void ExtHDU::read (std::valarray<S>& image, const std::vector<long>& first,
				long nElements, 
				S* nulValue) throw (FitsException&) 
        {
                checkExtensionType();
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
                

                read(image, firstElement,nElements,nulValue);


                   
        } 

        template<typename S>
        void ExtHDU::read (std::valarray<S>& image, const std::vector<long>& first, 
				long nElements) throw (FitsException&) 
        {
                checkExtensionType();
                read(image, firstElement,nElements,static_cast<S*>(0));
                   
        } 
                
        template<typename S>
        void ExtHDU::read (std::valarray<S>& image, const std::vector<long>& firstVertex, 
				const std::vector<long>& lastVertex, 
				const std::vector<long>& stride, 
				S* nulValue) throw (FitsException&) 
        {
                checkExtensionType();
                
                try
                {
                        ImageExt<S>& extimage = dynamic_cast<ImageExt<S>&>(*this);
                        const std::valarray<S>& __tmp 
                                      = extimage.readImage(firstVertex,lastVertex,stride,nulValue);
                        image.resize(__tmp.size());
                        image = __tmp;
                }
                catch (std::bad_cast)
                {
                        // FITSutil::fill will take care of sizing.
                        if (bitpix() == Ifloat)
                        {
                                float nulVal(0);
                                if (nulValue) nulVal = static_cast<float>(*nulValue);                                 
                                ImageExt<float>& extimage = dynamic_cast<ImageExt<float>&>(*this);
                                FITSUtil::fill(image,
                                        extimage.readImage(firstVertex,lastVertex,stride,&nulVal));
                        }
                        else if (bitpix() == Idouble)
                        {
                                ImageExt<double>& extimage = dynamic_cast<ImageExt<double>&>(*this);
                                double nulVal(0);
                                if (nulValue) nulVal = static_cast<double>(*nulValue);                                 
                                FITSUtil::fill(image,
                                         extimage.readImage(firstVertex,lastVertex,stride,&nulVal));
                        }
                        else if (bitpix() == Ibyte)
                        {
                                ImageExt<unsigned char>& extimage 
                                                = dynamic_cast<ImageExt<unsigned char>&>(*this);
                                unsigned char nulVal(0);
                                if (nulValue) nulVal = static_cast<unsigned char>(*nulValue);                                 
                                FITSUtil::fill(image,
                                         extimage.readImage(firstVertex,lastVertex,stride,&nulVal));
                        } 
                        else if (bitpix() == Ilong)
                        {
                                ImageExt<long>& extimage = dynamic_cast<ImageExt<long>&>(*this);
                                long nulVal(0);
                                if (nulValue) nulVal = static_cast<long>(*nulValue);                                 
                                FITSUtil::fill(image,
                                         extimage.readImage(firstVertex,lastVertex,stride,&nulVal));
                        }    
                        else if (bitpix() == Ishort)
                        {
                                ImageExt<short>& extimage = dynamic_cast<ImageExt<short>&>(*this);
                                short nulVal(0);
                                if (nulValue) nulVal = static_cast<short>(*nulValue);                                 
                                FITSUtil::fill(image,
                                         extimage.readImage(firstVertex,lastVertex,stride,&nulVal));
                        }          
                        else if (bitpix() == Iulong)
                        {
                                ImageExt<unsigned long>& extimage 
                                                = dynamic_cast<ImageExt<unsigned long>&>(*this);
                                unsigned long nulVal(0);
                                if (nulValue) nulVal = static_cast<unsigned long>(*nulValue);                                 
                                FITSUtil::fill(image,
                                         extimage.readImage(firstVertex,lastVertex,stride,&nulVal));
                        }    
                        else if (bitpix() == Iushort)
                        {
                                ImageExt<unsigned short>& extimage 
                                                = dynamic_cast<ImageExt<unsigned short>&>(*this);
                                unsigned short nulVal(0);
                                if (nulValue) nulVal = static_cast<unsigned short>(*nulValue);                                 
                                FITSUtil::fill(image,
                                         extimage.readImage(firstVertex,lastVertex,stride,&nulVal));
                        }     
                        else 
                        {
                                throw CCfits::FitsFatal(" casting image types ");
                        }     
                }
        }  

        template<typename S>
        void ExtHDU::read (std::valarray<S>& image, const std::vector<long>& firstVertex, 
				const std::vector<long>& lastVertex, 
				const std::vector<long>& stride) throw (FitsException&) 
        {
                checkExtensionType();
                read(image, firstVertex,lastVertex,stride,static_cast<S*>(0));
        }  

        template <typename S>
        void ExtHDU::write(long first,
                            long nElements,
                        const std::valarray<S>& data,
                        S* nulValue)
        {                
                // throw if we called image read/write operations on a table.
                checkExtensionType();
                                
                try
                {

                        ImageExt<S>& image = dynamic_cast<ImageExt<S>&>(*this);
                        image.writeImage(first,nElements,data,nulValue);

                        
                }
                catch (std::bad_cast)
                {
                        if (bitpix() == Ifloat)
                        {
                                std::valarray<float> __tmp;                               
                                ImageExt<float>& imageExt = dynamic_cast<ImageExt<float>&>(*this);
                                FITSUtil::fill(__tmp,data);
                                imageExt.writeImage(first,nElements,__tmp,
                                                static_cast<float*>(nulValue));
                        }
                        else if (bitpix() == Idouble)
                        {
                                std::valarray<double> __tmp;                                
                                ImageExt<double>& imageExt 
                                                = dynamic_cast<ImageExt<double>&>(*this);
                                FITSUtil::fill(__tmp,data);
                                imageExt.writeImage(first,nElements,__tmp,static_cast<double*>(nulValue));                              
                        }
                        else if (bitpix() == Ibyte)
                        {
                                ImageExt<unsigned char>& imageExt 
                                                = dynamic_cast<ImageExt<unsigned char>&>(*this);
                                std::valarray<unsigned char> __tmp; 
                                unsigned char blankVal(0);                                
                                try 
                                {

                                        readKey("BLANK",blankVal);
                                        std::valarray<S> copyData(data);
                                        std::replace(&copyData[0],&copyData[data.size()],
                                            static_cast<unsigned char>(*nulValue),blankVal);
                                 
                                        FITSUtil::fill(__tmp,copyData);                                        

                                        imageExt.writeImage(first,nElements,__tmp);                          }
                                catch (HDU::NoSuchKeyword)
                                {
                                        throw NoNullValue("Primary");
                                }

                        } 
                        else if (bitpix() == Ilong)
                        {                               
                                ImageExt<long>& imageExt = dynamic_cast<ImageExt<long>&>(*this);
                                std::valarray<long> __tmp;                                 
                                long  blankVal(0);                                
                                try 
                                {

                                        readKey("BLANK",blankVal);
                                        std::valarray<S> copyData(data);
                                        std::replace(&copyData[0],&copyData[data.size()],
                                                        static_cast<long>(*nulValue),blankVal);
       
                                        FITSUtil::fill(__tmp,copyData);                                        
                                        imageExt.writeImage(first,nElements,__tmp);                          
                                }
                                catch (HDU::NoSuchKeyword)
                                {
                                        throw NoNullValue("Primary");
                                }                        
                        }    
                        else if (bitpix() == Ishort)
                        {
                                ImageExt<short>& imageExt 
                                                = dynamic_cast<ImageExt<short>&>(*this);
                                std::valarray<short> __tmp; 
                                short blankVal(0);                               
                                try 
                                {
                                        readKey("BLANK",blankVal);
                                        std::valarray<S> copyData(data);
                                        std::replace(&copyData[0],&copyData[data.size()],
                                                       static_cast<short>(*nulValue),blankVal);
       
                                        FITSUtil::fill(__tmp,copyData);                                        
                                        imageExt.writeImage(first,nElements,__tmp);                          
                                }
                                catch (HDU::NoSuchKeyword)
                                {
                                        throw NoNullValue("Primary");
                                }   
                        }        
                        else if (bitpix() == Iulong)
                        {
                                ImageExt<unsigned long>& imageExt
                                                = dynamic_cast<ImageExt<unsigned long>&>(*this);
                                std::valarray<unsigned long> __tmp;
                                unsigned long blankVal(0);                                
                                try 
                                {

                                        readKey("BLANK",blankVal);
                                        std::valarray<S> copyData(data);
                                        std::replace(&copyData[0],&copyData[data.size()],
                                             static_cast<unsigned long>(*nulValue),blankVal);
       
                                        FITSUtil::fill(__tmp,copyData);                                        
                                        imageExt.writeImage(first,nElements,__tmp);                          
                                }
                                catch (HDU::NoSuchKeyword)
                                {
                                        throw NoNullValue("Primary");
                                }                           
                        }    
                        else if (bitpix() == Iushort)
                        {
                                ImageExt<unsigned short>& imageExt
                                                = dynamic_cast<ImageExt<unsigned short>&>(*this);
                                std::valarray<unsigned short> __tmp;
                                unsigned short blankVal(0);
                                try 
                                {
                                        readKey("BLANK",blankVal);
                                        std::valarray<S> copyData(data);
                                        std::replace(&copyData[0],&copyData[data.size()],
                                            static_cast<unsigned short>(*nulValue),blankVal);
       
                                        FITSUtil::fill(__tmp,copyData);                                        
                                        imageExt.writeImage(first,nElements,__tmp);                          
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
        void ExtHDU::write(long first,
                            long nElements,const std::valarray<S>& data)
        {                
                
                checkExtensionType();
                
                try
                {
                        ImageExt<S>& image = dynamic_cast<ImageExt<S>&>(*this);
                        image.writeImage(first,nElements,data);   
                }
                catch (std::bad_cast)
                {
                        if (bitpix() == Ifloat)
                        {
                                std::valarray<float> __tmp;                               
                                ImageExt<float>& imageExt = dynamic_cast<ImageExt<float>&>(*this);
                                FITSUtil::fill(__tmp,data);
                                imageExt.writeImage(first,nElements,__tmp);
                        }
                        else if (bitpix() == Idouble)
                        {
                                std::valarray<double> __tmp;                                
                                ImageExt<double>& imageExt 
                                                = dynamic_cast<ImageExt<double>&>(*this);
                                FITSUtil::fill(__tmp,data);
                                imageExt.writeImage(first,nElements,__tmp);                              
                        }
                        else if (bitpix() == Ibyte)
                        {
                                ImageExt<unsigned char>& imageExt 
                                                = dynamic_cast<ImageExt<unsigned char>&>(*this);
                                std::valarray<unsigned char> __tmp;         
                                FITSUtil::fill(__tmp,data);                                        
                                imageExt.writeImage(first,nElements,__tmp);
                        } 
                        else if (bitpix() == Ilong)
                        {                               
                                ImageExt<long>& imageExt = dynamic_cast<ImageExt<long>&>(*this);
                                std::valarray<long> __tmp;   
                                FITSUtil::fill(__tmp,data);                                        
                                imageExt.writeImage(first,nElements,__tmp);                          
                        }    
                        else if (bitpix() == Ishort)
                        {
                                ImageExt<short>& imageExt 
                                                = dynamic_cast<ImageExt<short>&>(*this);
                                std::valarray<short> __tmp;   
                                FITSUtil::fill(__tmp,data);                                        
                                imageExt.writeImage(first,nElements,__tmp);                          
                        }        
                        else if (bitpix() == Iulong)
                        {
                                ImageExt<unsigned long>& imageExt
                                                = dynamic_cast<ImageExt<unsigned long>&>(*this);
                                std::valarray<unsigned long> __tmp;
                                FITSUtil::fill(__tmp,data);                                        
                                imageExt.writeImage(first,nElements,__tmp);                          
                        }    
                        else if (bitpix() == Iushort)
                        {
                                ImageExt<unsigned short>& imageExt
                                                = dynamic_cast<ImageExt<unsigned short>&>(*this);
                                std::valarray<unsigned short> __tmp;
                                FITSUtil::fill(__tmp,data);                                        
                                imageExt.writeImage(first,nElements,__tmp); 
                         
                        }     
                        else 
                        {
                                throw CCfits::FitsFatal(" casting image types ");
                        }     
                }
        }
        
        template <typename S>
        void ExtHDU::write(const std::vector<long>& first,
                        long nElements,
                        const std::valarray<S>& data,
                        S* nulValue)
        {        
                // throw if we called image read/write operations on a table.
                checkExtensionType();
                                
                size_t n(first.size());
                long firstElement(0);
                long dimSize(1);
                for (long i = 0; i < first.size(); ++i)
                {
                        firstElement +=  ((first[i] - 1)*dimSize);
                        dimSize *=naxes(i);   
                }       
                ++firstElement;
                
                write(firstElement,nElements,data,nulValue);
        }
        
        template <typename S>
        void ExtHDU::write(const std::vector<long>& first,
                        long nElements,
                        const std::valarray<S>& data)
        {        
                // throw if we called image read/write operations on a table.
                checkExtensionType();
                                
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
        void ExtHDU::write(const std::vector<long>& firstVertex,
                        const std::vector<long>& lastVertex,
                        const std::valarray<S>& data)
        {
                // throw if we called image read/write operations on a table.
                checkExtensionType();                
                
                try
                {
                        ImageExt<S>& ExtHDU = dynamic_cast<ImageExt<S>&>(*this);
                        ExtHDU.writeImage(firstVertex,lastVertex,stride,data);  
                }
                catch (std::bad_cast)
                {
                         // write input type S to Image type...

                        if (bitpix() == Ifloat)
                        {
                                ImageExt<float>& ExtHDU = dynamic_cast<ImageExt<float>&>(*this);
                                size_t n(data.size());
                                std::valarray<float> __tmp(n);
                                for (size_t j= 0; j < n; ++j) __tmp[j] = data[j];
                                ExtHDU.writeImage(firstVertex,lastVertex,stride,__tmp);

                        }
                        else if (bitpix() == Idouble)
                        {
                                ImageExt<double>& ExtHDU 
                                        = dynamic_cast<ImageExt<double>&>(*this);
                                size_t n(data.size());
                                std::valarray<double> __tmp(n);
                                for (size_t j= 0; j < n; ++j) __tmp[j] = data[j];
                                ExtHDU.writeImage(firstVertex,lastVertex,stride,__tmp);
                        }
                        else if (bitpix() == Ibyte)
                        {
                                ImageExt<unsigned char>& ExtHDU 
                                        = dynamic_cast<ImageExt<unsigned char>&>(*this);
                                size_t n(data.size());
                                std::valarray<unsigned char> __tmp(n);
                                for (size_t j= 0; j < n; ++j) __tmp[j] = data[j];
                                ExtHDU.writeImage(firstVertex,lastVertex,stride,__tmp);                        
                        } 
                        else if (bitpix() == Ilong)
                        {
                                ImageExt<long>& ExtHDU = dynamic_cast<ImageExt<long>&>(*this);
                                size_t n(data.size());
                                std::valarray<long> __tmp(n);
                                for (size_t j= 0; j < n; ++j) __tmp[j] = data[j];
                                ExtHDU.writeImage(firstVertex,lastVertex,stride,__tmp);                               
                        }    
                        else if (bitpix() == Ishort)
                        {
                                ImageExt<short>& ExtHDU = dynamic_cast<ImageExt<short>&>(*this);
                                size_t n(data.size());
                                std::valarray<short> __tmp(n);
                                for (size_t j= 0; j < n; ++j) __tmp[j] = data[j];
                                ExtHDU.writeImage(firstVertex,lastVertex,stride,__tmp);                         
                        }          
                        else if (bitpix() == Iulong)
                        {
                                ImageExt<unsigned long>& ExtHDU 
                                                = dynamic_cast<ImageExt<unsigned long>&>(*this);
                                size_t n(data.size());
                                std::valarray<unsigned long> __tmp(n);
                                for (size_t j= 0; j < n; ++j) __tmp[j] = data[j];
                                ExtHDU.writeImage(firstVertex,lastVertex,stride,__tmp);                              
                        }    
                        else if (bitpix() == Iushort)
                        {
                                ImageExt<unsigned short>& 
                                        ExtHDU = dynamic_cast<ImageExt<unsigned short>&>(*this);
                                size_t n(data.size());
                                std::valarray<unsigned short> __tmp(n);
                                for (size_t j= 0; j < n; ++j) __tmp[j] = data[j];
                                ExtHDU.writeImage(firstVertex,lastVertex,stride,__tmp);                               
                        }     
                        else 
                        {
                                throw CCfits::FitsFatal(" casting image types ");
                        }     
                }  
        }  
        

} //namespace CCfits

#endif
