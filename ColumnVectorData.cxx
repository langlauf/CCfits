
//	This is CCfits version 1.0-beta release August 2001

//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov




// ColumnVectorData
#include "ColumnVectorData.h"



namespace CCfits
{

        template <>
        void ColumnVectorData<complex<float> >::readColumnData(long firstRow, 
                                long nelements, long firstElem, 
                                complex<float>* nullValue)
        {

        }

        template <>
        void ColumnVectorData<complex<double> >::readColumnData (long firstRow, 
                                long nelements,long firstElem, 
                                complex<double>* nullValue)
        {

        }

        template <>
        void ColumnVectorData<complex<float> >::writeFixedArray 
                        (complex<float>* data, long nElements, long nRows, long firstRow, 
                         complex<float>* nullValue) throw (FitsException&)
        {

        }

        template <>
        void ColumnVectorData<complex<double> >::writeFixedArray 
                        (complex<double>* data, long nElements, long nRows, long firstRow, 
                         complex<double>* nullValue) throw (FitsException&)
        {

        }

        template <>
        void  ColumnVectorData<complex<float> >::writeRow
                        (const std::valarray<complex<float> >& data, long row, long firstElem, 
                         complex<float>* nullValue)
        {

        }


        template <>
        void  ColumnVectorData<complex<double> >::writeRow
                        (const std::valarray<complex<double> >& data, long row, long firstElem, 
                         complex<double>* nullValue)
        {

        }

        template <>
        void ColumnVectorData<complex<float> >::setDataLimits (complex<float>* limits)
        {
                m_minLegalValue = limits[0];
                m_maxLegalValue = limits[1];
                m_minDataValue = std::max(norm(limits[2]),norm(limits[0]));
                m_maxDataValue = std::min(norm(limits[3]),norm(limits[1]));
        }
                
  
        template <>
        void ColumnVectorData<complex<double> >::setDataLimits (complex<double>* limits)
        {
                m_minLegalValue = limits[0];
                m_maxLegalValue = limits[1];
                m_minDataValue = std::max(norm(limits[2]),norm(limits[0]));
                m_maxDataValue = std::min(norm(limits[3]),norm(limits[1]));
        }
        
        
}
