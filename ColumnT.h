
//	This is CCfits version 1.0-beta release August 2001
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov

#ifndef COLUMNT_H
#define COLUMNT_H

#include "ColumnData.h"
#include "ColumnVectorData.h"
#include "FITSUtil.h"
#include <typeinfo>
#include <vector>
#include <algorithm>
#include "NewKeyword.h"

#ifdef HAVE_STRSTREAM
#       include <strstream>
#else
#       include <sstream>
#endif


// by design, if the data are not read yet we will return an exception.
// here the test is if the entire column has already been read. 
using std::complex;

// get specified elements of a scalar column. These two functions allow the
// user to return either a vector or a valarray depending on the input container.

namespace CCfits 
{
        template <typename S>
        void Column::read(std::vector<S>& vals, size_t first, size_t last) throw (FitsException&)
        {
                read(vals,first,last,static_cast<S*>(0));
        }
        

        template <typename S>
        void Column::read(std::vector<S>& vals, size_t first, size_t last, S* nullValue) throw (FitsException&)
        {
                // problem: S does not give the type of the Column, but the return type,
                // so the user must specify this.

                // user expects 1 based indexing. If 0 based indices are supplied,
                // add one to both ranges.
                if (first == 0)
                {
                        first +=1;
                        last = std::min(static_cast<size_t>(rows()),last+1);       
                }

                last  = std::min((size_t)rows(),last);
                if (last < first ) throw RangeError(name());
                long nelements(last - first + 1);

                try 
                {
                        // fails if user requested outputType different from input type.

                        ColumnData<S>& col = dynamic_cast<ColumnData<S>&>(*this);
                        if (!isRead()) col.readColumnData(first,nelements,nullValue);
                        // scalar column with vector output can just be assigned.
                        FITSUtil::fill(vals,col.data(),first,last);
                }
                catch (std::bad_cast)
                {
                        FITSUtil::MatchType<S> outputType;
                        if ( outputType() == type() ) 
                        { 
                                // in this case user tried to read vector data from scalar,
                                // (i.e. first argument was vector<valarray<S> >.
                                // since the cast won't fail on template parameter grounds.
                                throw Column::WrongColumnType(name());
                        }

                        try
                        {
                            // about exceptions. The dynamic_casts could throw
                            // std::bad_cast. If this happens something is seriously
                            // wrong since the Column stores the value of type() 
                            // appropriate to each of the casts on construction.
                            // 
                            // the InvalidDataType exception should not be possible.
                            if  ( type() == Tdouble )
		            {
                                    double nullVal(0);
                                    if (nullValue) nullVal = *nullValue;                                 
                                    ColumnData<double>& col 
                                              = dynamic_cast<ColumnData<double>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                  
                                    FITSUtil::fill(vals,col.data(),first,last);

                            }
		            else if (type() == Tfloat)
		            {
                                    float nullVal(0);
                                    if (nullValue) nullVal = *nullValue;                                     
                                    ColumnData<float>& col 
                                            = dynamic_cast<ColumnData<float>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                  
                                    FITSUtil::fill(vals,col.data(),first,last);
                            }
		            else if (type() == Tcomplex)
		            {
                                    complex<float> nullVal(0);
                                    if (nullValue) nullVal = complex<float>(*nullValue,0);                                       
                                    ColumnData<complex<float> >& col =  
                                           dynamic_cast<ColumnData<complex<float> >&>(*this);
                                     if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                  
                                     FITSUtil::fill(vals,col.data(),first,last);
		            }
		            else if (type() == Tdblcomplex)
		            {
                                    complex<double> nullVal(0);
                                    if (nullValue) nullVal = complex<double>(*nullValue,0);                                     
                                    ColumnData<complex<double> >& col  = 
                                          dynamic_cast<ColumnData<complex<double> >&>(*this);
                                    FITSUtil::fill(vals,col.data(),first,last);
		            }
		            else if (type() == Tint)
		            {
                                    int nullVal(0);
                                    if (nullValue) nullVal = *nullValue;
                                    ColumnData<int>& col  
                                       = dynamic_cast<ColumnData<int>&>(*this);
                                    FITSUtil::fill(vals,col.data(),first,last);
		            }
		            else if (type() == Tshort)
                            {
                                    short nullVal(0);
                                    if (nullValue) nullVal = *nullValue;
                                    ColumnData<short>& col 
                                     = dynamic_cast<ColumnData<short>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                  
                                    FITSUtil::fill(vals,col.data(),first,last);
                            }
		            else if (type() == Tlong)
		            {	
                                    long nullVal(0);
                                    if (nullValue) nullVal = *nullValue; 
                                    ColumnData<long>& col 
                                      = dynamic_cast<ColumnData<long>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                  
                                    FITSUtil::fill(vals,col.data(),first,last);
                            }
		            else if (type() == Tlogical)
		            {	
                                    bool nullVal(0);
                                    if (nullValue) nullVal = *nullValue; 
                                    ColumnData<bool>& col 
                                      = dynamic_cast<ColumnData<bool>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                  
                                    FITSUtil::fill(vals,col.data(),first,last);
		            }
		            else if (type() == Tbit || type() == Tbyte)
		            {
                                    unsigned char nullVal(0);
                                    if (nullValue) nullVal = *nullValue; 
                                    ColumnData<unsigned char>& col 
                                            = dynamic_cast<ColumnData<unsigned char>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal); 
                                    FITSUtil::fill(vals,col.data(),first,last);
                            }
		            else if (type() == Tushort)
                            {
                                    unsigned short nullVal(0);
                                    if (nullValue) nullVal = *nullValue;
                                    ColumnData<unsigned short>& col 
                                            = dynamic_cast<ColumnData<unsigned short>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                  
                                    FITSUtil::fill(vals,col.data(),first,last);
                            }
		            else if (type() == Tuint)
                            {
                                    unsigned int nullVal(0);
                                    if (nullValue) nullVal = *nullValue;
                                    ColumnData<unsigned int>& col 
                                            = dynamic_cast<ColumnData<unsigned int>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                  
                                    FITSUtil::fill(vals,col.data(),first,last);
		            }
		            else if (type() == Tulong)
                            {
                                    unsigned long nullVal(0);
                                    if (nullValue) nullVal = *nullValue;
                                    ColumnData<unsigned long>& col 
                                             = dynamic_cast<ColumnData<unsigned long>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                  
                                    FITSUtil::fill(vals,col.data(),first,last);
                            }
		            else
                            {
                                      throw InvalidDataType(name());

                            }

                        }
                        catch (std::bad_cast)
                        {
			        throw WrongColumnType(name());
                        }
                }

        }

        template <typename S>
        void Column::read(std::valarray<S>& vals, size_t first, size_t last) throw (FitsException&)
        {
                read(vals,first,last,static_cast<S*>(0));
        }


        template <typename S>
        void Column::read(std::valarray<S>& vals, size_t first, size_t last, S* nullValue) throw (FitsException&)
        {        
                // require the whole scalar column to have been read.


                FITSUtil::MatchType<S> outputType;
                // user expects 1 based indexing. If 0 based indices are supplied,
                // add one to both ranges.                
                if (first == 0)
                {
                        first +=1;
                        last = std::min(static_cast<size_t>(rows()),last+1);       
                }

                last  = std::min((size_t)rows(),last);

                if (last < first) throw RangeError(name());
                long nelements(last - first + 1);
                
                try 
                {
                        // fails if user requested outputType different from input type.

                        ColumnData<S>& col = dynamic_cast<ColumnData<S>&>(*this);
                        if (!isRead()) col.readColumnData(first,nelements,nullValue);                                  
                        FITSUtil::fill(vals,col.data(),first,last);

                }
                catch (std::bad_cast)
                {
                        if ( outputType() == type() ) 
                        { 
                                // in this case user tried to read vector data from scalar,
                                // (i.e. first argument was vector<valarray<S> >.
                                // since the cast won't fail on template parameter grounds.
                                throw Column::WrongColumnType(name());
                        }

                        try
                        {
                            // about exceptions. The dynamic_casts could throw
                            // std::bad_cast. If this happens something is seriously
                            // wrong since the Column stores the value of type() 
                            // appropriate to each of the casts on construction.
                            // 
                            // the InvalidDataType exception should not be possible.
                            if  ( type() == Tdouble )
		            {
                                    double nullVal(0);
                                    if (nullValue) nullVal = static_cast<double>(*nullValue); 
                                    ColumnData<double>& col 
                                              = dynamic_cast<ColumnData<double>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                  
                                    FITSUtil::fill(vals,col.data(),first,last);
                            }
		            else if (type() == Tfloat)
		            {
                                    float nullVal(0);
                                    if (nullValue) nullVal = static_cast<float>(*nullValue); 
                                    ColumnData<float>& col 
                                            = dynamic_cast<ColumnData<float>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                  
                                    FITSUtil::fill(vals,col.data(),first,last);
                            }
		            else if (type() == Tcomplex)
		            {
                                    complex<float> nullVal;
                                    if (nullValue) nullVal = static_cast<float>(*nullValue); 
                                    ColumnData<complex<float> >& col 
                                        = dynamic_cast<ColumnData<complex<float> >&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                    
                                    FITSUtil::fill(vals,col.data(),first,last);
		            }
		            else if (type() == Tdblcomplex)
		            {
                                    complex<double> nullVal;
                                    if (nullValue) nullVal = static_cast<double>(*nullValue); 
                                    ColumnData<complex<double> >& col 
                                          = dynamic_cast<ColumnData<complex<double> >&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                    
                                    FITSUtil::fill(vals,col.data(),first,last);
		            }
		            else if (type() == Tint)
		            {
                                    int nullVal(0);
                                    if (nullValue) nullVal = static_cast<int>(*nullValue); 
                                    ColumnData<int>& col  
                                            = dynamic_cast<ColumnData<int>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                    
                                    FITSUtil::fill(vals,col.data(),first,last);
		            }
		            else if (type() == Tshort)
                            {
                                    short nullVal(0);
                                    if (nullValue) nullVal = static_cast<short>(*nullValue); 
                                    ColumnData<short>& col 
                                            = dynamic_cast<ColumnData<short>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                    
                                    FITSUtil::fill(vals,col.data(),first,last);
                            }
		            else if (type() == Tlong)
		            {	
                                    long nullVal(0);
                                    if (nullValue) nullVal = static_cast<long>(*nullValue); 
                                    ColumnData<long>& col 
                                            = dynamic_cast<ColumnData<long>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);
                                    FITSUtil::fill(vals,col.data(),first,last);
                            }
		            else if (type() == Tlogical)
		            {	
                                    bool nullVal(0);
                                    if (nullValue) nullVal = static_cast<bool>(*nullValue); 
                                    ColumnData<bool>& col 
                                            = dynamic_cast<ColumnData<bool>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                    
                                    FITSUtil::fill(vals,col.data(),first,last);
		            }
		            else if (type() == Tbit || type() == Tbyte)
		            {
                                    unsigned char nullVal(0);
                                    if (nullValue) nullVal = static_cast<unsigned char>(*nullValue); 
                                    ColumnData<unsigned char>& col 
                                            = dynamic_cast<ColumnData<unsigned char>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                    
                                    FITSUtil::fill(vals,col.data(),first,last);
                            }
		            else if (type() == Tushort)
                            {
                                    unsigned short nullVal(0);
                                    if (nullValue) nullVal 
                                            = static_cast<unsigned short>(*nullValue); 
                                    ColumnData<unsigned short>& col 
                                            = dynamic_cast<ColumnData<unsigned short>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                    
                                    FITSUtil::fill(vals,col.data(),first,last);
                            }
		            else if (type() == Tuint)
                            {
                                    unsigned int nullVal(0);
                                    if (nullValue) nullVal 
                                            = static_cast<unsigned int>(*nullValue); 
                                    ColumnData<unsigned int>& col 
                                            = dynamic_cast<ColumnData<unsigned int>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                    
                                    FITSUtil::fill(vals,col.data(),first,last);
		            }
		            else if (type() == Tulong)
                            {
                                    unsigned long nullVal(0);
                                    if (nullValue) nullVal 
                                            = static_cast<unsigned long>(*nullValue); 
                                    ColumnData<unsigned long>& col 
                                            = dynamic_cast<ColumnData<unsigned long>&>(*this);
                                    if (!isRead()) col.readColumnData(first,nelements,&nullVal);                                    
                                    FITSUtil::fill(vals,col.data(),first,last);
                            }
		            else
                            {
                                      throw InvalidDataType(name());

                            }

                        }
                        catch (std::bad_cast)
                        {
		             throw WrongColumnType(name());
                        }
                    }

        }

        // get a single row from a vector column. There's no default row number, must
        // be specified.
        template <typename S>
        void Column::read(std::valarray<S>& vals, size_t row) throw (FitsException&)
        {
                read(vals,row,static_cast<S*>(0));
        }


        template <typename S>
        void Column::read(std::valarray<S>& vals, size_t row, S* nullValue) throw (FitsException&)
        {
                // isRead() returns true if the data were read in the ctor.
                
                try 
                {
                        // fails if user requested outputType different from input type.

                        ColumnVectorData<S>& col = dynamic_cast<ColumnVectorData<S>&>(*this);

                        // input and output are both valarrays. Since one should not
                        // be able to call a constructor for a non-numeric valarray type,
                        // there shouldn't be any InvalidType problems. However, there
                        // is still the vector/scalar possibility and the implicit
                        // conversion request to deal with.

                        if (!isRead()) col.readRow(row,nullValue);
                        FITSUtil::fill(vals,col.data(row));
                }
                catch (std::bad_cast)
                {
                        FITSUtil::MatchType<S> outputType;
                        if ( outputType() == type() ) 
                        { 
                                // in this case user tried to read vector row from scalar column.
                                // one could be charitable and return a valarray of size 1,
                                // but... I'm going to throw an exception suggesting the user
                                // might not have meant that.

                                throw Column::WrongColumnType(name());
                        }

                        // the InvalidDataType exception should not be possible.
                        try
                        {
                            // about exceptions. The dynamic_casts could throw
                            // std::bad_cast. If this happens something is seriously
                            // wrong since the Column stores the value of type() 
                            // appropriate to each of the casts on construction.
                            // 
                            // the InvalidDataType exception should not be possible.
                            if  ( type() == Tdouble || type() == VTdouble )
		            {
                                    double nullVal(0);
                                    if (nullValue) nullVal = static_cast<double>(*nullValue); 
                                    ColumnVectorData<double>& col 
                                              = dynamic_cast<ColumnVectorData<double>&>(*this);
                                    if (!isRead()) col.readRow(row,&nullVal);                                  
                                    FITSUtil::fill(vals,col.data(row));

                            }
		            else if (type() == Tfloat  || type() == VTfloat )
		            {
                                    float nullVal(0);
                                    if (nullValue) nullVal = static_cast<float>(*nullValue); 
                                    ColumnVectorData<float>& col 
                                          = dynamic_cast<ColumnVectorData<float>&>(*this);
                                    if (!isRead()) col.readRow(row,&nullVal); 
                                    FITSUtil::fill(vals,col.data(row));
                            }
		            else if (type() == Tcomplex  || type() == VTcomplex  )
		            {
                                    complex<float> nullVal;
                                    if (nullValue) nullVal = static_cast<float>(*nullValue); 
                                    ColumnVectorData<complex<float> >& col 
                                    = dynamic_cast<ColumnVectorData<complex<float> >&>(*this);
                                    if (!isRead()) col.readRow(row,&nullVal); 
                                    FITSUtil::fill(vals,col.data(row));
		            }
		            else if (type() == Tdblcomplex  || type() == VTdblcomplex )
		            {
                                    complex<double> nullVal;
                                    if (nullValue) nullVal = static_cast<double>(*nullValue); 
                                    ColumnVectorData<complex<double> >& col 
                                      = dynamic_cast<ColumnVectorData<complex<double> >&>(*this);
                                    if (!isRead()) col.readRow(row,&nullVal); 
                                    FITSUtil::fill(vals,col.data(row));
		            }
		            else if (type() == Tint  || type() == VTint )
		            {
                                    int nullVal(0);
                                    if (nullValue) nullVal = static_cast<int>(*nullValue); 
                                    ColumnVectorData<int>& col  
                                            = dynamic_cast<ColumnVectorData<int>&>(*this);
                                    if (!isRead()) col.readRow(row,&nullVal); 
                                    FITSUtil::fill(vals,col.data(row));
		            }
		            else if (type() == Tshort  || type() == VTshort  )
                            {
                                    short nullVal(0);
                                    if (nullValue) nullVal = static_cast<short>(*nullValue); 
                                    ColumnVectorData<short>& col 
                                            = dynamic_cast<ColumnVectorData<short>&>(*this);
                                    if (!isRead()) col.readRow(row,&nullVal); 
                                    FITSUtil::fill(vals,col.data(row));
                            }
		            else if (type() == Tlong  || type() == VTlong )
		            {	
                                    long nullVal(0);
                                    if (nullValue) nullVal = static_cast<long>(*nullValue); 
                                    ColumnVectorData<long>& col 
                                            = dynamic_cast<ColumnVectorData<long>&>(*this);
                                    if (!isRead()) col.readRow(row,&nullVal); 
                                    FITSUtil::fill(vals,col.data(row));
                            }
		            else if (type() == Tlogical  || type() == VTlogical )
		            {	
                                    bool nullVal(0);
                                    if (nullValue) nullVal = static_cast<bool>(*nullValue); 
                                    ColumnVectorData<bool>& col 
                                            = dynamic_cast<ColumnVectorData<bool>&>(*this);
                                    if (!isRead()) col.readRow(row,&nullVal); 
                                    FITSUtil::fill(vals,col.data(row));
		            }
		            else if (type() == Tbit || type() == Tbyte ||  
                                    type() == VTbit || type() == VTbyte )
		            {
                                    unsigned char nullVal(0);
                                    if (nullValue) nullVal 
                                                = static_cast<unsigned char>(*nullValue); 
                                    ColumnVectorData<unsigned char>& col 
                                          = dynamic_cast<ColumnVectorData<unsigned char>&>(*this);
                                    if (!isRead()) col.readRow(row,&nullVal); 
                                    FITSUtil::fill(vals,col.data(row));
                            }
		            else if (type() == Tushort || type() == VTushort)
                            {
                                    unsigned short nullVal(0);
                                    if (nullValue) nullVal 
                                                = static_cast<unsigned short>(*nullValue); 
                                    ColumnVectorData<unsigned short>& col 
                                          = dynamic_cast<ColumnVectorData<unsigned short>&>(*this);
                                    if (!isRead()) col.readRow(row,&nullVal); 
                                    FITSUtil::fill(vals,col.data(row));
                            }
		            else if (type() == Tuint || type() == VTuint)
                            {
                                    unsigned int nullVal(0);
                                    if (nullValue) nullVal 
                                                = static_cast<unsigned int>(*nullValue); 
                                    ColumnVectorData<unsigned int>& col 
                                          = dynamic_cast<ColumnVectorData<unsigned int>&>(*this);
                                    if (!isRead()) col.readRow(row,&nullVal); 
                                    FITSUtil::fill(vals,col.data(row));
		            }
		            else if (type() == Tulong || type() == VTulong)
                            {
                                    unsigned long nullVal(0);
                                    if (nullValue) nullVal 
                                                = static_cast<unsigned long>(*nullValue); 
                                    ColumnVectorData<unsigned long>& col 
                                            = dynamic_cast<ColumnVectorData<unsigned long>&>(*this);
                                    if (!isRead()) col.readRow(row,&nullVal); 
                                    FITSUtil::fill(vals,col.data(row));
                            }
		            else
                            {
                                    throw InvalidDataType(name());

                            }

                        }
                        catch (std::bad_cast)
                        {
                            throw WrongColumnType(name());
                        }     
                 }
        }

        template <typename S>
        void Column::read(std::vector<std::valarray<S> >& vals, 
                        size_t first, size_t last)  throw (FitsException&)
        {
                read(vals,first,last,static_cast<S*>(0));
        }

        template <typename S>
        void Column::read(std::vector<std::valarray<S> >& vals, 
                        size_t first, size_t last, S* nullValue)  throw (FitsException&)
        {

                // again, can only call this if the entire column has been read from disk.
                // user expects 1 based indexing. If 0 based indices are supplied,
                // add one to both ranges.
                if (first == 0)
                {
                        first +=1;
                        last = std::min(static_cast<size_t>(rows()),last+1);       
                }

                last  = std::min((size_t)rows(),last);

                int range = last-first+1;
                if (range < 0) throw RangeError(name());

                vals.resize(range);


                try 
                {
                        ColumnVectorData<S>& col = dynamic_cast<ColumnVectorData<S>&>(*this);


                        for (size_t j = 0; j < range; ++j) 
                        {
                                if (!isRead()) col.readRow(j + first,nullValue);                             
                                FITSUtil::fill(vals[j],col.data(j+first));
                        }


                }
                catch (std::bad_cast)
                {
                        FITSUtil::MatchType<S> outputType;
                        if ( outputType() == type() ) 
                        { 
                                // in this case user tried to read vector data from scalar,
                                // (i.e. first argument was vector<valarray<S> >.
                                // since the cast won't fail on template parameter grounds.
                                throw Column::WrongColumnType(name());
                        }
                        // the InvalidDataType exception should not be possible.
                        try
                        {
                            // no string case.
                            if  ( type() == Tdouble || type() == VTdouble )
		            {
                                    double nullVal(0);
                                    if (nullValue) nullVal = static_cast<double>(*nullValue); 
                                    ColumnVectorData<double>& col 
                                            = dynamic_cast<ColumnVectorData<double>&>(*this);
                                    for (size_t j = 0; j < range; ++j) 
                                    {
                                        if (!isRead()) col.readRow(j + first,&nullVal); 
                                        FITSUtil::fill(vals[j],col.data(j+first));
                                    }
                            }
                            else if  ( type() == Tfloat || type() == VTfloat  )
		            {
                                    float nullVal(0);
                                    if (nullValue) nullVal  = static_cast<float>(*nullValue); 
                                    ColumnVectorData<float>& col 
                                            = dynamic_cast<ColumnVectorData<float>&>(*this);
                                    for (size_t j = 0; j < range; ++j) 
                                    {
                                        if (!isRead()) col.readRow(j + first,&nullVal); 
                                        FITSUtil::fill(vals[j],col.data(j+first));
                                    }
                            }
                            else if  ( type() == Tcomplex  || type() == VTcomplex  )
		            {
                                    complex<float> nullVal(0);
                                    if (nullValue) nullVal  = static_cast<float>(*nullValue); 
                                    ColumnVectorData<complex<float> >& col 
                                       = dynamic_cast<ColumnVectorData<complex<float> >&>(*this);
                                    for (size_t j = 0; j < range; ++j) 
                                    {
                                        if (!isRead()) col.readRow(j + first,&nullVal); 
                                        FITSUtil::fill(vals[j],col.data(j+first));
                                    }
                            }
                            else if  ( type() == Tdblcomplex   || type() == VTdblcomplex)
		            {
                                    complex<double> nullVal(0);
                                    if (nullValue) nullVal  = static_cast<double>(*nullValue); 
                                    ColumnVectorData<complex<double> >& col 
                                       = dynamic_cast<ColumnVectorData<complex<double> >&>(*this);
                                    for (size_t j = 0; j < range; ++j) 
                                    {
                                        if (!isRead()) col.readRow(j + first,&nullVal); 
                                        FITSUtil::fill(vals[j],col.data(j+first));
                                    }
                            }
                            else if  ( type() == Tint   || type() == VTint )
		            {
                                    int nullVal(0);
                                    if (nullValue) nullVal  = static_cast<int>(*nullValue); 
                                    ColumnVectorData<int>& col  
                                            = dynamic_cast<ColumnVectorData<int>&>(*this);
                                    for (size_t j = 0; j < range; ++j) 
                                    {
                                        if (!isRead()) col.readRow(j + first,&nullVal); 
                                        FITSUtil::fill(vals[j],col.data(j+first));
                                    }
                            }
                            else if  ( type() == Tshort  || type() == VTshort )
		            {
                                    short nullVal(0);
                                    if (nullValue) nullVal  = static_cast<short>(*nullValue); 
                                    ColumnVectorData<short>& col 
                                            = dynamic_cast<ColumnVectorData<short>&>(*this);
                                    for (size_t j = 0; j < range; ++j) 
                                    {
                                        if (!isRead()) col.readRow(j + first,&nullVal); 
                                        FITSUtil::fill(vals[j],col.data(j+first));
                                    }
                            }
                            else if  ( type() == Tlong   || type() == VTlong )
		            {
                                    long nullVal(0);
                                    if (nullValue) nullVal  = static_cast<long>(*nullValue); 
                                    ColumnVectorData<long>& col 
                                            = dynamic_cast<ColumnVectorData<long>&>(*this);
                                    for (size_t j = 0; j < range; ++j) 
                                    {
                                        if (!isRead()) col.readRow(j + first,&nullVal); 
                                        FITSUtil::fill(vals[j],col.data(j+first));
                                    }
                            }
                            else if  ( type() == Tlogical   || type() == VTlogical )
		            {
                                    bool nullVal(0);
                                    if (nullValue) nullVal   = static_cast<bool>(*nullValue); 
                                    ColumnVectorData<bool>& col 
                                            = dynamic_cast<ColumnVectorData<bool>&>(*this);
                                    for (size_t j = 0; j < range; ++j) 
                                    {
                                        if (!isRead()) col.readRow(j + first,&nullVal); 
                                        FITSUtil::fill(vals[j],col.data(j+first));
                                    }
                            }
		            else if (type() == Tbit || type() == Tbyte ||  
                                    type() == VTbit || type() == VTbyte )
		            {
                                    unsigned char nullVal(0);
                                    if (nullValue) nullVal 
                                                = static_cast<unsigned char>(*nullValue); 
                                    ColumnVectorData<unsigned char>& col 
                                           = dynamic_cast<ColumnVectorData<unsigned char>&>(*this);
                                    for (size_t j = 0; j < range; ++j) 
                                    {
                                        if (!isRead()) col.readRow(j + first,&nullVal); 
                                        FITSUtil::fill(vals[j],col.data(j+first));
				    }
                            }                            
                            else if  ( type() == Tushort   || type() == VTushort )
		            {
                                    unsigned short nullVal(0);
                                    if (nullValue) nullVal 
                                                = static_cast<unsigned short>(*nullValue); 
                                    ColumnVectorData<unsigned short>& col 
                                        = dynamic_cast<ColumnVectorData<unsigned short>&>(*this);
                                    for (size_t j = 0; j < range; ++j) 
                                    {
                                        if (!isRead()) col.readRow(j + first,&nullVal); 
                                        FITSUtil::fill(vals[j],col.data(j+first));
                                    }
                            }
                            else if  ( type() == Tuint   || type() == VTuint )
		            {
                                    unsigned int nullVal(0);
                                    if (nullValue) nullVal 
                                                = static_cast<unsigned int>(*nullValue); 
                                    ColumnVectorData<unsigned int>& col 
                                            = dynamic_cast<ColumnVectorData<unsigned int>&>(*this);
                                    for (size_t j = 0; j < range; ++j) 
                                    {
                                        if (!isRead()) col.readRow(j + first,&nullVal); 
                                        FITSUtil::fill(vals[j],col.data(j+first));
                                    }
                            }
                            else if  ( type() == Tulong   || type() == VTulong  )
		            {
                                    unsigned long nullVal(0);
                                    if (nullValue) nullVal 
                                                = static_cast<unsigned long>(*nullValue); 
                                    ColumnVectorData<unsigned long>& col 
                                          = dynamic_cast<ColumnVectorData<unsigned long>&>(*this);
                                    for (size_t j = 0; j < range; ++j) 
                                    {
                                        if (!isRead()) col.readRow(j + first,&nullVal); 
                                        FITSUtil::fill(vals[j],col.data(j+first));
                                    }
                            } 
                            else
                            {
                                    throw InvalidDataType(name());
                            }

                        }
                        catch (std::bad_cast)
                        {
                            throw WrongColumnType(name());

                        }     

                }        
        }

        template <typename S>                   
        void Column::write (const std::vector<S>& indata, long firstRow)
        {
                // nullValue is now a pointer, so this is ok. 
                // got to cast the 0 to a pointer to S to avoid
                // overloading ambiguities.      
                write(indata,firstRow,static_cast<S*>(0));
        }

        template <typename S>                   
        void Column::write (const std::valarray<S>& indata, long firstRow)
        {
                size_t n(indata.size());
                std::vector<S> __tmp(n);
                for (size_t j = 0; j < n; ++j) __tmp[j] = indata[j];
                write(__tmp,firstRow,static_cast<S*>(0));
        }

        template <typename S>                   
        void Column::write (S* indata, long nRows, long firstRow)
        {
                write(indata,nRows,firstRow,static_cast<S*>(0));                
        }

        
        template <typename S>                   
        void Column::write (const std::vector<S>& indata, long firstRow, S* nullValue)
        {
                // although underlying code needs to convert the input vector
                // into a C array, this must be the underlying implementation
                // [which the others call] because it accepts string arguments
                // which the version with a pointer won't. [no version that
                // translates to a char** argument].
                
                
                firstRow = std::max(firstRow,static_cast<long>(1));
                try
                {
                        ColumnData<S>& col = dynamic_cast<ColumnData<S>&>(*this);
                        col.writeData(indata,firstRow,nullValue);
                }
                catch (std::bad_cast)
                {
                        // alright, input data type has to be rewritten as output
                        // data type.
                        FITSUtil::MatchType<S> inType;
                        if ( inType() == type()) 
                        {
                                string msg("Incorrect call: writing to vector column ");
                                msg += name();
                                msg += " requires specification of # rows or vector lengths";
                                throw WrongColumnType(msg);
                        }
                        else
                        {
                            if  ( type() == Tdouble )
		            {
                                double nullVal(0);
                                if (nullValue) nullVal = static_cast<double>(*nullValue);
                                ColumnData<double>& col 
                                        = dynamic_cast<ColumnData<double>&>(*this);
                                std::vector<double> __tmp;
                                FITSUtil::fill(__tmp,indata,0,indata.size());
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tfloat )
		            {
                                float nullVal(0);
                                if (nullValue) nullVal = static_cast<float>(*nullValue); 
                                ColumnData<float>& col 
                                        = dynamic_cast<ColumnData<float>&>(*this);
                                std::vector<float> __tmp;
                                FITSUtil::fill(__tmp,indata,0,indata.size());
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tcomplex )
		            {
                                complex<float> nullVal;
                                if (nullValue) nullVal = static_cast<float>(*nullValue);
                                ColumnData<complex<float> >& col 
                                      = dynamic_cast<ColumnData<complex<float> >&>(*this);
                                std::vector<complex<float> > __tmp;
                                FITSUtil::fill(__tmp,indata,0,indata.size());
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tdblcomplex )
		            {
                                complex<double> nullVal;
                                if (nullValue) nullVal = static_cast<double>(*nullValue);
                                ColumnData<complex<double> >& col 
                                      = dynamic_cast<ColumnData<complex<double> >&>(*this);
                                std::vector<complex<double> > __tmp;
                                FITSUtil::fill(__tmp,indata,0,indata.size());
                                col.writeData(__tmp,firstRow,&nullVal); 
                            }
                            else if  ( type() == Tint )
		            {
                                int nullVal(0);
                                if (nullValue) nullVal = static_cast<int>(*nullValue); 
                                ColumnData<int>& col  
                                        = dynamic_cast<ColumnData<int>&>(*this);
                                std::vector<int> __tmp;
                                FITSUtil::fill(__tmp,indata,0,indata.size());
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tshort )
		            {
                                short nullVal(0);
                                if (nullValue) nullVal = static_cast<short>(*nullValue); 
                                ColumnData<short>& col 
                                        = dynamic_cast<ColumnData<short>&>(*this);
                                std::vector<short> __tmp;
                                FITSUtil::fill(__tmp,indata,0,indata.size());
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tlong )
		            {
                                long nullVal(0);
                                if (nullValue) nullVal = static_cast<long>(*nullValue); 
                                ColumnData<long>& col 
                                        = dynamic_cast<ColumnData<long>&>(*this);
                                std::vector<long> __tmp;
                                FITSUtil::fill(__tmp,indata,0,indata.size());
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tlogical )
		            {
                                bool nullVal(0);
                                if (nullValue) nullVal = static_cast<bool>(*nullValue); 
                                ColumnData<bool>& col 
                                        = dynamic_cast<ColumnData<bool>&>(*this);
                                std::vector<bool> __tmp;
                                FITSUtil::fill(__tmp,indata,0,indata.size());
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tbyte )
		            {
                                unsigned char nullVal(0);
                                if (nullValue) nullVal = static_cast<unsigned char>(*nullValue); 
                                ColumnData<unsigned char>& col 
                                        = dynamic_cast<ColumnData<unsigned char>&>(*this);
                                std::vector<unsigned char> __tmp;
                                FITSUtil::fill(__tmp,indata,0,indata.size());
                                col.writeData(__tmp,firstRow,&nullVal);
                            }                            
                            else if  ( type() == Tushort )
		            {
                                unsigned short nullVal(0);
                                if (nullValue) nullVal = static_cast<unsigned short>(*nullValue); 
                                ColumnData<unsigned short>& col 
                                        = dynamic_cast<ColumnData<unsigned short>&>(*this);
                                std::vector<unsigned short> __tmp;
                                FITSUtil::fill(__tmp,indata,0,indata.size());
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tuint )
		            {
                                unsigned int nullVal(0);
                                if (nullValue) nullVal = static_cast<unsigned int>(*nullValue); 
                                ColumnData<unsigned int>& col 
                                        = dynamic_cast<ColumnData<unsigned int>&>(*this);
                                std::vector<unsigned int> __tmp;
                                FITSUtil::fill(__tmp,indata,0,indata.size());
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tulong )
		            {
                                unsigned long nullVal(0);
                                if (nullValue) nullVal = static_cast<unsigned long>(*nullValue); 
                                ColumnData<unsigned long>& col 
                                        = dynamic_cast<ColumnData<unsigned long>&>(*this);
                                std::vector<unsigned long> __tmp;
                                FITSUtil::fill(__tmp,indata,0,indata.size());
                                col.writeData(__tmp,firstRow,&nullVal);
                            } 
                            else
                            {
                                    throw InvalidDataType(name());
                            }
                        }
                }
        }
        
                
        template <typename S>                   
        void Column::write (const std::valarray<S>& indata, long firstRow, S* nullValue)
        {
                // for scalar columns.        
                std::vector<S> __tmp;
                FITSUtil::fill(__tmp,indata);    
                write(__tmp,firstRow,nullValue);          
        }

        template <typename S>                   
        void Column::write (S* indata, long nRows, long firstRow, S* nullValue)
        {
                // for scalar columns, data specified with C array
                if (nRows <= 0) throw InvalidNumberOfRows(nRows);
                std::vector<S> __tmp(nRows);
                std::copy(&indata[0],&indata[nRows],__tmp.begin());
                write(__tmp,firstRow, nullValue);

        }
        
        template <typename S>
        void Column::write (const std::valarray<S>& indata, const std::vector<long>& vectorLengths,  
                                long firstRow)
        {
                // downcast and call.
                
                using std::valarray;
                firstRow = std::max(firstRow,static_cast<long>(1));
                try
                {
                        ColumnData<S>& col = dynamic_cast<ColumnData<S>&>(*this);
                        col.writeData(indata,vectorLengths,firstRow);
                }
                catch (std::bad_cast)
                {
                        // alright, input data type has to be rewritten as output
                        // data type.
                        FITSUtil::MatchType<S> inType;
                        if ( inType() == type()) 
                        {
                                string msg("Incorrect call: scalar column ");
                                msg += name();
                                msg += " does not have vector lengths";
                                throw WrongColumnType(msg);
                        }
                        else
                        {
                            if  ( type() == Tdouble )
		            {
                                ColumnData<double>& col 
                                        = dynamic_cast<ColumnData<double>&>(*this);
                                valarray<double> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,vectorLengths,firstRow);
                            }
                            else if  ( type() == Tfloat )
		            {
                                ColumnData<float>& col 
                                        = dynamic_cast<ColumnData<float>&>(*this);
                                valarray<float> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,vectorLengths,firstRow);
                            }
                            else if  ( type() == Tcomplex )
		            {
                                ColumnData<complex<float> >& col 
                                      = dynamic_cast<ColumnData<complex<float> >&>(*this);
                                valarray<complex<float> > __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,vectorLengths,firstRow);
                            }
                            else if  ( type() == Tdblcomplex )
		            {
                                ColumnData<complex<double> >& col 
                                      = dynamic_cast<ColumnData<complex<double> >&>(*this);
                                valarray<complex<double> > __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,vectorLengths,firstRow); 
                            }
                            else if  ( type() == Tint )
		            {
                                ColumnData<int>& col  
                                        = dynamic_cast<ColumnData<int>&>(*this);
                                valarray<int> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,vectorLengths,firstRow);
                            }
                            else if  ( type() == Tshort )
		            {
                                ColumnData<short>& col 
                                        = dynamic_cast<ColumnData<short>&>(*this);
                                valarray<short> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,vectorLengths,firstRow);
                            }
                            else if  ( type() == Tlong )
		            {
                                ColumnData<long>& col 
                                        = dynamic_cast<ColumnData<long>&>(*this);
                                valarray<long> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,vectorLengths,firstRow);
                            }
                            else if  ( type() == Tlogical )
		            {
                                ColumnData<bool>& col 
                                        = dynamic_cast<ColumnData<bool>&>(*this);
                                valarray<bool> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,vectorLengths,firstRow);
                            }
                            else if  ( type() == Tbyte )
		            {
                                ColumnData<unsigned char>& col 
                                        = dynamic_cast<ColumnData<unsigned char>&>(*this);
                                valarray<unsigned char> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,firstRow);
                            }                            
                            else if  ( type() == Tushort )
		            {
                                ColumnData<unsigned short>& col 
                                        = dynamic_cast<ColumnData<unsigned short>&>(*this);
                                valarray<unsigned short> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,vectorLengths,firstRow);
                            }
                            else if  ( type() == Tuint )
		            {
                                ColumnData<unsigned int>& col 
                                        = dynamic_cast<ColumnData<unsigned int>&>(*this);
                                valarray<unsigned int> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,vectorLengths,firstRow);
                            }
                            else if  ( type() == Tulong )
		            {
                                ColumnData<unsigned long>& col 
                                        = dynamic_cast<ColumnData<unsigned long>&>(*this);
                                valarray<unsigned long> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,vectorLengths,firstRow);
                            } 
                            else
                            {
                                    throw InvalidDataType(name());
                            }
                        }
                }
        }
        
        template <typename S>
        void Column::write (const std::vector<S>& indata,const std::vector<long>& vectorLengths,
                                long firstRow)
        {
                // variable length write
                // implement as valarray version
                valarray<S> __tmp(indata.size());
                std::copy(indata.begin(),indata.end(),&__tmp[0]);
                write(__tmp,vectorLengths,firstRow);  

        }
        
        template <typename S>
        void Column::write (S* indata, long nelements, const std::vector<long>& vectorLengths,
                                        long firstRow)
        {
                // implement as valarray version, which will also check array size.
                size_t n(vectorLengths.size());
                valarray<S> __tmp(indata,nelements);
                write(__tmp,vectorLengths,firstRow);
        }        
 
        template <typename S>
        void Column::write (const std::valarray<S>& indata, long nRows, long firstRow)
        {
                write(indata,nRows,firstRow,static_cast<S*>(0));
        }
        
        template <typename S>
        void Column::write (const std::vector<S>& indata, long nRows, long firstRow)
        {
                write(indata,nRows,firstRow,static_cast<S*>(0));  
        }
        
        template <typename S>
        void Column::write (S* indata, long nelements, long nRows, long firstRow)
        {
                write(indata,nelements,nRows,firstRow,static_cast<S*>(0));              
        }        

        

        template <typename S>
        void Column::write (const std::valarray<S>& indata, long nRows, long firstRow,
                                S* nullValue)
        {
                // primary implementation,  nullValue  
                if (nRows <= 0) throw InvalidNumberOfRows(nRows);

                firstRow = std::max(firstRow,static_cast<long>(1));
                try
                {
                        ColumnVectorData<S>& col = dynamic_cast<ColumnVectorData<S>&>(*this);
                        col.writeData(indata,nRows,firstRow,nullValue);
                }
                catch (std::bad_cast)
                {
                        // alright, input data type has to be rewritten as output
                        // data type.
                        FITSUtil::MatchType<S> inType;
                        if ( inType() == type()) 
                        {
                                string 
                                  msg("Incorrect call: writing to valarray data to scalar column: ");
                                  msg += name();
                                  msg += " does not require specification of number of rows";
                                throw WrongColumnType(msg);
                        }
                        else
                        {
                            if  ( type() == Tdouble )
		            {
                                double nullVal(0);
                                if (nullValue) nullVal = static_cast<double>(*nullValue); 
                                ColumnVectorData<double>& col 
                                        = dynamic_cast<ColumnVectorData<double>&>(*this);
                                std::valarray<double> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,nRows,firstRow,&nullVal);
                            }
                            else if  ( type() == Tfloat )
		            {
                                float nullVal(0);
                                if (nullValue) nullVal = static_cast<float>(*nullValue); 
                                ColumnVectorData<float>& col 
                                        = dynamic_cast<ColumnVectorData<float>&>(*this);
                                std::valarray<float> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,nRows,firstRow,&nullVal);
                            }
                            else if  ( type() == Tcomplex )
		            {
                                complex<float> nullVal;
                                if (nullValue) nullVal = static_cast<float>(*nullValue);
                                ColumnVectorData<complex<float> >& col 
                                      = dynamic_cast<ColumnVectorData<complex<float> >&>(*this);
                                std::valarray<complex<float> > __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,nRows,firstRow,&nullVal);
                            }
                            else if  ( type() == Tdblcomplex )
		            {
                                complex<double> nullVal;
                                if (nullValue) nullVal = static_cast<double>(*nullValue);
                                ColumnVectorData<complex<double> >& col 
                                      = dynamic_cast<ColumnVectorData<complex<double> >&>(*this);
                                std::valarray<complex<double> > __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,nRows,firstRow,&nullVal);                            }
                            else if  ( type() == Tint )
		            {
                                int nullVal(0);
                                if (nullValue) nullVal = static_cast<int>(*nullValue); 
                                ColumnVectorData<int>& col  
                                        = dynamic_cast<ColumnVectorData<int>&>(*this);
                                std::valarray<int> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,nRows,firstRow,&nullVal);
                            }
                            else if  ( type() == Tshort )
		            {
                                short nullVal(0);
                                if (nullValue) nullVal = static_cast<short>(*nullValue); 
                                ColumnVectorData<short>& col 
                                        = dynamic_cast<ColumnVectorData<short>&>(*this);
                                std::valarray<short> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,nRows,firstRow,&nullVal);
                            }
                            else if  ( type() == Tlong )
		            {
                                long nullVal(0);
                                if (nullValue) nullVal = static_cast<long>(*nullValue); 
                                ColumnVectorData<long>& col 
                                        = dynamic_cast<ColumnVectorData<long>&>(*this);
                                std::valarray<long> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,nRows,firstRow,&nullVal);
                            }
                            else if  ( type() == Tlogical )
		            {
                                bool nullVal(0);
                                if (nullValue) nullVal = static_cast<bool>(*nullValue); 
                                ColumnVectorData<bool>& col 
                                        = dynamic_cast<ColumnVectorData<bool>&>(*this);
                                std::valarray<bool> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,nRows,firstRow,&nullVal);
                            }
                            else if  ( type() == Tbyte )
		            {
                                unsigned char nullVal(0);
                                if (nullValue) nullVal = static_cast<unsigned char>(*nullValue);
                                ColumnVectorData<unsigned char>& col 
                                        = dynamic_cast<ColumnVectorData<unsigned char>&>(*this);
                                std::valarray<unsigned char> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,nRows,firstRow,&nullVal);
                            }                            
                            else if  ( type() == Tushort )
		            {
                                unsigned short nullVal(0);
                                if (nullValue) nullVal = static_cast<unsigned short>(*nullValue);
                                ColumnVectorData<unsigned short>& col 
                                        = dynamic_cast<ColumnVectorData<unsigned short>&>(*this);
                                std::valarray<unsigned short> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,nRows,firstRow,&nullVal);
                            }
                            else if  ( type() == Tuint )
		            {
                                unsigned int nullVal(0);
                                if (nullValue) nullVal = static_cast<unsigned int>(*nullValue);
                                ColumnVectorData<unsigned int>& col 
                                        = dynamic_cast<ColumnVectorData<unsigned int>&>(*this);
                                std::valarray<unsigned int> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,nRows,firstRow,&nullVal);
                            }
                            else if  ( type() == Tulong )
		            {
                                unsigned long nullVal(0);
                                if (nullValue) nullVal = static_cast<unsigned long>(*nullValue);
                                ColumnVectorData<unsigned long>& col 
                                        = dynamic_cast<ColumnVectorData<unsigned long>&>(*this);
                                std::valarray<unsigned long> __tmp;
                                FITSUtil::fill(__tmp,indata);
                                col.writeData(__tmp,nRows,firstRow,&nullVal);
                            } 
                            else
                            {
                                    throw InvalidDataType(name());
                            }
                        }
                }
        }
        
        template <typename S>
        void Column::write (const std::vector<S>& indata, long nRows, long firstRow, S* nullValue)
        {
                // fixed length write of vector
                // implement as valarray version
                if (nRows <= 0) throw InvalidNumberOfRows(nRows);
                valarray<S> __tmp(indata.size());
                std::copy(indata.begin(),indata.end(),&__tmp[0]);
                write(__tmp,nRows,firstRow, nullValue);  
        }
        
        template <typename S>
        void Column::write (S* indata, long nelements, long nRows, long firstRow, S* nullValue)
        {
                // fixed length write of C-array
                // implement as valarray version
                if (nRows <= 0) throw InvalidNumberOfRows(nRows);
                valarray<S> __tmp(indata,nelements);
                write(__tmp,nRows,firstRow, nullValue);              
        }        
        
               
        template <typename S>
        void Column::write (const std::vector<std::valarray<S> >& indata, long firstRow)
        {
                // vector<valarray>, no null value. 
                write(indata,firstRow,static_cast<S*>(0));
        } 
        
        template <typename S>
        void Column::write (const std::vector<std::valarray<S> >& indata, long firstRow,
                                        S* nullValue)
        {
                // vector<valarray>, null value. primary
                
                
                using std::valarray;
                using std::vector;
                firstRow = std::max(firstRow,static_cast<long>(1));
                try
                {
                        ColumnVectorData<S>& col = dynamic_cast<ColumnVectorData<S>&>(*this);
                        col.writeData(indata,firstRow,nullValue);
                }
                catch (std::bad_cast)
                {
                        // alright, input data type has to be rewritten as output
                        // data type.
                        FITSUtil::MatchType<S> inType;
                        if ( inType() == type()) 
                        {
                                string msg("Incorrect call: writing vectors to scalar column ");
                                throw WrongColumnType(msg);
                        }
                        else
                        {
                            size_t n(indata.size());                            
                            if  ( type() == Tdouble )
		            {
                                ColumnVectorData<double>& col 
                                        = dynamic_cast<ColumnVectorData<double>&>(*this);
                                vector<valarray<double> > __tmp(n);
                                double nullVal(0);
                                if (nullValue) nullVal = static_cast<double>(*nullValue);
                                for (size_t i = 0; i < n; ++i)
                                {
                                        FITSUtil::fill(__tmp[i],indata[i]);
                                }
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tfloat )
		            {
                                ColumnVectorData<float>& col 
                                        = dynamic_cast<ColumnVectorData<float>&>(*this);
                                vector<valarray<float> > __tmp(n);
                                float nullVal(0);
                                if (nullValue) nullVal = static_cast<float>(*nullValue);
                                for (size_t i = 0; i < n; ++i)
                                {
                                        FITSUtil::fill(__tmp[i],indata[i]);
                                }                                
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tcomplex )
		            {
                                ColumnVectorData<complex<float> >& col 
                                      = dynamic_cast<ColumnVectorData<complex<float> >&>(*this);
                                vector<valarray<complex<float> > > __tmp(n);
                                complex<float> nullVal;
                                if (nullValue) nullVal = static_cast<complex<float> >(*nullValue);
                                for (size_t i = 0; i < n; ++i)
                                {
                                        FITSUtil::fill(__tmp[i],indata[i]);
                                }                                
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tdblcomplex )
		            {
                                ColumnVectorData<complex<double> >& col 
                                   = dynamic_cast<ColumnVectorData<complex<double> >&>(*this);
                                vector<valarray<complex<double> > > __tmp(n);
                                complex<double> nullVal;
                                if (nullValue) nullVal = static_cast<complex<double> >(*nullValue);
                                for (size_t i = 0; i < n; ++i)
                                {
                                        FITSUtil::fill(__tmp[i],indata[i]);
                                }                                
                                col.writeData(__tmp,firstRow,&nullVal);                            
                            }
                            else if  ( type() == Tint )
		            {
                                ColumnVectorData<int>& col  
                                        = dynamic_cast<ColumnVectorData<int>&>(*this);
                                vector<valarray<int> > __tmp(n);
                                int nullVal(0);
                                if (nullValue) nullVal = static_cast<int>(*nullValue);
                                for (size_t i = 0; i < n; ++i)
                                {
                                        FITSUtil::fill(__tmp[i],indata[i]);
                                }                                
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tshort )
		            {
                                ColumnVectorData<short>& col 
                                        = dynamic_cast<ColumnVectorData<short>&>(*this);
                                vector<valarray<short> > __tmp(n);
                                short nullVal(0);
                                if (nullValue) nullVal = static_cast<short>(*nullValue);
                                for (size_t i = 0; i < n; ++i)
                                {
                                        FITSUtil::fill(__tmp[i],indata[i]);
                                }                                
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tlong )
		            {
                                ColumnVectorData<long>& col 
                                        = dynamic_cast<ColumnVectorData<long>&>(*this);
                                vector<valarray<long> > __tmp(n);
                                long nullVal(0);
                                if (nullValue) nullVal = static_cast<long>(*nullValue);
                                for (size_t i = 0; i < n; ++i)
                                {
                                        FITSUtil::fill(__tmp[i],indata[i]);
                                }                                
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tlogical )
		            {
                                ColumnVectorData<bool>& col 
                                        = dynamic_cast<ColumnVectorData<bool>&>(*this);
                                bool nullVal(0);
                                if (nullValue) nullVal = static_cast<bool>(*nullValue);
                                vector<valarray<bool> > __tmp(n);
                                for (size_t i = 0; i < n; ++i)
                                {
                                        FITSUtil::fill(__tmp[i],indata[i]);
                                }                                
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tbyte )
		            {
                                ColumnVectorData<unsigned char>& col 
                                        = dynamic_cast<ColumnVectorData<unsigned char>&>(*this);
                                unsigned char nullVal(0);
                                if (nullValue) nullVal = static_cast<unsigned char>(*nullValue);
                                vector<valarray<unsigned char> > __tmp(n);
                                for (size_t i = 0; i < n; ++i)
                                {
                                        FITSUtil::fill(__tmp[i],indata[i]);
                                }                                                                
                                col.writeData(__tmp,firstRow,&nullVal);
                            }                            
                            else if  ( type() == Tushort )
		            {
                                ColumnVectorData<unsigned short>& col 
                                        = dynamic_cast<ColumnVectorData<unsigned short>&>(*this);
                                unsigned short nullVal(0);
                                if (nullValue) nullVal = static_cast<unsigned short>(*nullValue);
                                vector<valarray<unsigned short> > __tmp(n);
                                for (size_t i = 0; i < n; ++i)
                                {
                                        FITSUtil::fill(__tmp[i],indata[i]);
                                }                                
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tuint )
		            {
                                ColumnVectorData<unsigned int>& col 
                                        = dynamic_cast<ColumnVectorData<unsigned int>&>(*this);
                                unsigned int nullVal(0);
                                if (nullValue) nullVal = static_cast<unsigned int>(*nullValue);
                                vector<valarray<unsigned int> > __tmp(n);
                                for (size_t i = 0; i < n; ++i)
                                {
                                        FITSUtil::fill(__tmp[i],indata[i]);
                                }                                
                                col.writeData(__tmp,firstRow,&nullVal);
                            }
                            else if  ( type() == Tulong )
		            {
                                ColumnVectorData<unsigned long>& col 
                                        = dynamic_cast<ColumnVectorData<unsigned long>&>(*this);
                                unsigned long nullVal(0);
                                if (nullValue) nullVal = static_cast<unsigned long>(*nullValue);
                                vector<valarray<unsigned long> > __tmp(n);
                                for (size_t i = 0; i < n; ++i)
                                {
                                        FITSUtil::fill(__tmp[i],indata[i]);
                                }                                
                                col.writeData(__tmp,firstRow,&nullVal);
                            } 
                            else
                            {
                                    throw InvalidDataType(name());
                            }
                        }
                }
        } 
        
        
        template <typename T>
        void Column::addNullValue(T nullVal)
        {
                int status(0);
#ifdef HAVE_STRSTREAM
                std::ostrstream keyName;
                keyName << "TNULL" << index();
                char* nullKey(const_cast<char*>(keyName.str()));
#else
                std::ostringstream keyName;          
                keyName << "TNULL" << index();
                char* nullKey(const_cast<char*>(keyName.str().c_str()));
#endif
                
                
             
                FITSUtil::MatchType<T> type;
                
                T dataType(type());
                // update key but don't add to keyword list because it's really a column
                // property not a table metadata property. And it needs to be automatically
                // renumbered if columns are inserted or deleted.
                if (fits_update_key(fitsPointer(),dataType,nullKey,&nullVal,0,&status))
                        throw FitsError(status);

                if (fits_set_hdustruc(fitsPointer(),&status)) throw FitsError(status);   
                
                
                try
                {
                        ColumnVectorData<T>& col = dynamic_cast<ColumnVectorData<T>&>(*this);
                        col.nullValue(nullVal);
                }
                catch (std::bad_cast)
                {
                        try
                        {
                                ColumnData<T>& col 
                                        = dynamic_cast<ColumnData<T>&>(*this);
                                col.nullValue(nullVal); 
                        }
                        catch (std::bad_cast)
                        {
                                throw InvalidDataType(" setting null value for column ");
                        }                       
                }
                
        }
} // namespace CCfits

#endif
