
//	This is CCfits version 1.0-beta release August 2001

//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov




// ColumnData
#include "ColumnData.h"

namespace CCfits
{

        template <>
        void ColumnData<string>::writeData (const std::vector<string>& indata, 
                        long firstRow, string* nullValue)
        {
          int    status=0;
          char** columnData=FITSUtil::CharArray(indata);

          if ( fits_write_colnull(fitsPointer(), TSTRING, index(), firstRow, 1, indata.size(),
			          columnData, 0, &status) != 0 )
              throw FitsError(status);
          unsigned long elementsToWrite (indata.size() + firstRow - 1);
          std::vector<string> __tmp(m_data);
          if (m_data.size() < elementsToWrite) 
          {
                  m_data.resize(elementsToWrite,"");
                  std::copy(__tmp.begin(),__tmp.end(),m_data.begin());
          }
          std::copy(indata.begin(),indata.end(),m_data.begin()+firstRow-1);
           
          
          for (size_t i = 0; i < indata.size(); ++i)
          {
                delete [] columnData[i];
          }
          delete [] columnData;
        }  


        template <>
        void ColumnData<string>::readColumnData (long firstRow, 
                                        long nelements, 
                                        string* nullValue)
        {
          int status = 0;

           int   anynul = 0;
           char** array = new char*[nelements]; 

           for (int j = 0; j < nelements; j++)
           {
               array[j] = new char[width() + 1];
           }

           char* nulval(0);
           if (nullValue) 
           {
                   nulval = const_cast<char*>(nullValue->c_str());
           }
           else
           {
                nulval = new char;
                *nulval = '\0';
           }

           makeHDUCurrent();

          try
          {
                if (fits_read_col_str(fitsPointer(),index(), firstRow,1,nelements,
                  nulval,array, &anynul,&status) ) throw FitsError(status);
          }
          catch (FitsError)
          {
                // ugly. but better than leaking resources.       
                for (int j = 0; j < nelements; j++)
                {
                        delete [] array[j];
                }     

                delete [] array; 
                delete nulval;
                throw; 
          }



          if (m_data.size() == 0) setData(std::vector<string>(rows(),string(nulval)));

          // the 'first -1 ' converts to zero based indexing.

          for (int j = 0; j < nelements; j++)
          {
                m_data[j - 1 + firstRow] = string(array[j]);
          }

          for (int j = 0; j < nelements; j++)
          {
                delete [] array[j];
          }     

          delete [] array; 
          delete nulval; 

        }




        template <>
        void ColumnData<complex<float> >::readColumnData (long firstRow,
                                                long nelements,
                                                complex<float>* nullValue)
        {
          // specialization for ColumnData<string> 
          int status(0);
          int   anynul(0);
          FITSUtil::auto_array_ptr<float> pArray(new float[nelements*2]); 
          float* array(pArray.get());           
          float  nulval(nullValue->real());

          makeHDUCurrent();


          if (fits_read_col(fitsPointer(),TCOMPLEX,index(), firstRow,1,nelements,
                  &nulval,array, &anynul,&status) ) throw FitsError(status);



          if (m_data.size() == 0) m_data.resize(rows());

          // the 'j -1 ' converts to zero based indexing.

          for (int j = firstRow; j < nelements; j++)
          {
                std::complex<float> x(array[2*j],array[2*j+1]);
                m_data[j - 1] = x;
          }

          delete [] array;

        }

        template <>
        void ColumnData<complex<double> >::readColumnData (long firstRow, 
                                                        long nelements,
                                                        complex<double>* nullValue)
        {
          // specialization for ColumnData<complex<double> > 
           int status(0);
           int   anynul(0);
           FITSUtil::auto_array_ptr<double> pArray(new double[nelements*2]); 
           double* array(pArray.get());
           double  nulval(nullValue->real());

           makeHDUCurrent();


          if (fits_read_col(fitsPointer(),TDBLCOMPLEX, index(), firstRow,1,nelements,
                  &nulval,array, &anynul,&status) ) throw FitsError(status);




          if (m_data.size() == 0) setData(std::vector<complex<double> >(rows(),nulval));

          // the 'j -1 ' converts to zero based indexing.

          for (int j = firstRow; j < nelements; j++)
          {
                complex<double> x(array[2*j],array[2*j+1]);
                m_data[j - 1] = x;
          }

          delete [] array;

        }

        template <>
        void ColumnData<complex<float> >::writeData (const std::vector<complex<float> >& inData, 
                                long firstRow, 
                                complex<float>* nullValue)
        {
                // not implemented yet       
        }

        template <>
        void ColumnData<complex<double> >::writeData (const std::vector<complex<double> >& inData,
                                long firstRow, 
                                complex<double>* nullValue)
        {
                // not implemented yet
        }

        
        template <>
        void ColumnData<complex<float> >::setDataLimits (complex<float>* limits)
        {
                m_minLegalValue = limits[0];
                m_maxLegalValue = limits[1];
                m_minDataValue = std::max(norm(limits[2]),norm(limits[0]));
                m_maxDataValue = std::min(norm(limits[3]),norm(limits[1]));
        }
           
        template <>
        void ColumnData<complex<double> >::setDataLimits (complex<double>* limits)
        {
                m_minLegalValue = limits[0];
                m_maxLegalValue = limits[1];
                m_minDataValue = std::max(norm(limits[2]),norm(limits[0]));
                m_maxDataValue = std::min(norm(limits[3]),norm(limits[1]));
        }
        
} // namespace CCfits


