
//	This is CCfits version 1.0-beta

//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov


#ifndef COLUMNDATA_H
#define COLUMNDATA_H 1

#include "fitsio.h"

#include<complex>
#include <memory>

// vector
#include <vector>
// Column
#include "Column.h"
#include "FITSUtil.h"

using std::complex;


namespace CCfits {



  template <class T>
  class ColumnData : public Column  //## Inherits: <unnamed>%385E51565EE8
  {

    public:
        ColumnData(const ColumnData< T > &right);

        ColumnData (Table* p = 0, T nullVal = FITSUtil::FitsNullValue<T>()());

        ColumnData (int columnIndex, const string &columnName, ValueType type, const string &format, const string &unit, Table* p, int  rpt = 1, long w = 1, const string &comment = "", T nullVal = FITSUtil::FitsNullValue<T>()()) throw (FitsException&);

        ~ColumnData();


        virtual ColumnData<T>* clone () const;

        virtual void readData (long firstRow, long nelements, long firstElem = 1);

        void setDataLimits (T* limits);


        const T minLegalValue () const;
        void minLegalValue (T value);

        const T maxLegalValue () const;
        void maxLegalValue (T value);

        const T minDataValue () const;
        void minDataValue (T value);

        const T maxDataValue () const;
        void maxDataValue (T value);


        const std::vector<T>& data () const;
        void setData (const std::vector<T>& value);
        const T data (int i) const;
        void data (int i, T value);

      // Additional Public Declarations
        friend class Column;
    protected:
      // Additional Protected Declarations

    private:
        ColumnData< T > & operator=(const ColumnData< T > &right);


        void readColumnData (long firstRow, long nelements, T* nullValue = 0);

        virtual bool compare (const Column &right) const;

        virtual std::ostream& put (std::ostream& s) const;

        void writeData (T* indata, long nRows = 1, long firstRow = 1, T* nullValue = 0);

        void writeData (const std::vector<T>& indata, long firstRow = 1, T* nullValue = 0);

        //	Insert one or more blank rows into a FITS column.
        virtual void insertRows (long first, long number = 1);

        virtual void deleteRows (long first, long number = 1);


        const T nullValue () const;
        void nullValue (T value);

      // Additional Private Declarations

    private: //## implementation
      // Data Members for Class Attributes

        T m_nullValue;

        T m_minLegalValue;

        T m_maxLegalValue;

        T m_minDataValue;

        T m_maxDataValue;

      // Data Members for Associations

        std::vector<T> m_data;

      // Additional Implementation Declarations

  };


  // Parameterized Class CCfits::ColumnData 


  template <class T>
  inline void ColumnData<T>::readData (long firstRow, long nelements, long firstElem)
  {
   readColumnData(firstRow,nelements,static_cast<T*>(0));
  }


  template <class T>
  inline const T ColumnData<T>::nullValue () const
  {
    return m_nullValue;
  }

  template <class T>
  inline void ColumnData<T>::nullValue (T value)
  {
    m_nullValue = value;
  }

  template <class T>
  inline const T ColumnData<T>::minLegalValue () const
  {
    return m_minLegalValue;
  }

  template <class T>
  inline void ColumnData<T>::minLegalValue (T value)
  {
    m_minLegalValue = value;
  }

  template <class T>
  inline const T ColumnData<T>::maxLegalValue () const
  {
    return m_maxLegalValue;
  }

  template <class T>
  inline void ColumnData<T>::maxLegalValue (T value)
  {
    m_maxLegalValue = value;
  }

  template <class T>
  inline const T ColumnData<T>::minDataValue () const
  {
    return m_minDataValue;
  }

  template <class T>
  inline void ColumnData<T>::minDataValue (T value)
  {
    m_minDataValue = value;
  }

  template <class T>
  inline const T ColumnData<T>::maxDataValue () const
  {
    return m_maxDataValue;
  }

  template <class T>
  inline void ColumnData<T>::maxDataValue (T value)
  {
    m_maxDataValue = value;
  }


  template <class T>
  inline const std::vector<T>& ColumnData<T>::data () const
  {
    return m_data;
  }

  template <class T>
  inline void ColumnData<T>::setData (const std::vector<T>& value)
  {
    m_data = value;
  }

  template <class T>
  inline const T ColumnData<T>::data (int i) const
  {
    // return data stored in the ith row, which is in the i-1 th location in the array.
    return m_data[i - 1];
  }

  template <class T>
  inline void ColumnData<T>::data (int i, T value)
  {
    // assign data to i-1 th location in the array, representing the ith row.
    m_data[i - 1] = value;
  }

  // Parameterized Class CCfits::ColumnData 







  template <class T>
  ColumnData<T>::ColumnData(const ColumnData<T> &right)
      :Column(right),
       m_nullValue(right.m_nullValue),
       m_minLegalValue(right.m_minLegalValue),
       m_maxLegalValue(right.m_maxLegalValue),
       m_minDataValue(right.m_minDataValue),
       m_maxDataValue(right.m_maxDataValue),
       m_data(right.m_data)
  {
  }

  template <class T>
  ColumnData<T>::ColumnData (Table* p, T nullVal)
  : Column(p), m_nullValue(nullVal),
       m_minLegalValue(),
       m_maxLegalValue(),
       m_minDataValue(),
       m_maxDataValue(), 
       m_data()
  {
  }

  template <class T>
  ColumnData<T>::ColumnData (int columnIndex, const string &columnName, ValueType type, const string &format, const string &unit, Table* p, int  rpt, long w, const string &comment, T nullVal) throw (FitsException&)
        : Column(columnIndex,columnName,type,format,unit,p,rpt,w,comment), 
        m_nullValue(nullVal), 
        m_minLegalValue(),
        m_maxLegalValue(),
        m_minDataValue(),
        m_maxDataValue(),
        m_data()
          
  {
  }


  template <class T>
  ColumnData<T>::~ColumnData()
  {
  }



  template <class T>
  void ColumnData<T>::readColumnData (long firstRow, long nelements, T* nullValue)
  {
  if ( rows() < nelements ) 
  {
        std::cerr << "CCfits: More data requested than contained in table. ";
        std::cerr << "Extracting complete column.\n";
        nelements = rows();
   }   
   
   int   status(0);
   int   anynul(0);
   
   FITSUtil::auto_array_ptr<T> array(new T[nelements]); 

   makeHDUCurrent();

   if ( fits_read_col(fitsPointer(),type(),  index(), firstRow, 1, 
  	nelements, nullValue, array.get(), &anynul, &status) ) throw FitsError(status);
   
   
   if (m_data.size() != static_cast<size_t>( rows() ) ) m_data.resize(rows());
   
   std::copy(&array[0],&array[nelements],m_data.begin()+firstRow-1);
   if (nelements == rows()) isRead(true); 
  }

  template <class T>
  bool ColumnData<T>::compare (const Column &right) const
  {
  if ( !Column::compare(right) ) return false;
  const ColumnData<T>& that = static_cast<const ColumnData<T>&>(right);
  unsigned int n = m_data.size();
  if ( that.m_data.size() != n ) return false;
  for (unsigned int i = 0; i < n ; i++)
  {
        if (m_data[i] != that.m_data[i]) return false;   
  }
  return true;
  }

  template <class T>
  ColumnData<T>* ColumnData<T>::clone () const
  {
  return new ColumnData<T>(*this);
  }

  template <class T>
  std::ostream& ColumnData<T>::put (std::ostream& s) const
  {
  Column::put(s);
  if (FITS::verboseMode() && type() != Tstring)
  {
        s << " Column Legal limits: ( " << m_minLegalValue << "," << m_maxLegalValue << " )\n" 
        << " Column Data  limits: ( " << m_minDataValue << "," << m_maxDataValue << " )\n";
  }
  if (!m_data.empty())
  {
        std::ostream_iterator<T> output(s,"\n");
        // output each row on a separate line.
        // user can supply manipulators to stream for formatting.
        std::copy(m_data.begin(),m_data.end(),output);
  }

    return s;
  }

  template <class T>
  void ColumnData<T>::writeData (T* indata, long nRows, long firstRow, T* nullValue)
  {
  
          // set columnData's data member to equal what's written to file.
          // indata has size nRows: elements firstRow to firstRow + nRows - 1 will be written.
          // if this exceeds the current rowlength of the HDU, update the return value for
          // rows() in the parent after the fitsio call.
          int status(0);
          long elementsToWrite(nRows + firstRow -1);
          // get a copy for restorative action.   
          std::vector<T> __tmp(m_data);
          
          if (nullValue) m_nullValue = *nullValue;

          if (elementsToWrite > static_cast<long>(m_data.size())) 
          {

                  m_data.resize(elementsToWrite,T());
                  std::copy(__tmp.begin(),__tmp.end(),m_data.begin());
          }

          std::copy(&indata[0],&indata[nRows],m_data.begin()+firstRow-1);

          // if successful, write to disk.

          try
          {

                if (fits_write_colnull(fitsPointer(), type(), index(), firstRow, 1, nRows,
			          indata, nullValue, &status) != 0) throw FitsError(status);

                // tell the Table that the number of rows has changed
                parent()->updateRows();
          }
          catch (FitsError) // the only thing that can throw here.
          {
                  // reset to original content and rethrow the exception.
                  m_data = __tmp;
                  if (status == NO_NULL) throw NoNullValue(name());
                  else throw;
          }      

  }

  template <class T>
  void ColumnData<T>::writeData (const std::vector<T>& indata, long firstRow, T* nullValue)
  {
        FITSUtil::Carray<T> convert;
        FITSUtil::auto_array_ptr<T> pcolData(convert(indata));
        T* columnData(pcolData.get());
        
        writeData(columnData,indata.size(),firstRow,nullValue);
  }

  template <class T>
  void ColumnData<T>::insertRows (long first, long number)
  {
    FITSUtil::FitsNullValue<T> blank;
    std::vector<T>::iterator in;
    if (first !=0) 
    {
            in = m_data.begin()+first;
    }
    else
    {
            in = m_data.begin();
    }           
    
    // non-throwing operations.
    m_data.insert(in,number,blank());
  }

  template <class T>
  void ColumnData<T>::deleteRows (long first, long number)
  {
    m_data.erase(m_data.begin()+first-1,m_data.begin()+first-1+number);
  }

  template <class T>
  void ColumnData<T>::setDataLimits (T* limits)
  {
    m_minLegalValue = limits[0];
    m_maxLegalValue = limits[1];
    m_minDataValue = std::max(limits[2],limits[0]);
    m_maxDataValue = std::min(limits[3],limits[1]);
  }

  // Additional Declarations
  
  // all functions that operate on strings or complex data that call cfitsio 
  // need to be specialized.
template <>
void ColumnData<complex<float> >::setDataLimits (complex<float>* limits);
  
template <>
void ColumnData<complex<double> >::setDataLimits (complex<double>* limits);
  

template <>
void ColumnData<string>::readColumnData (long firstRow, long nelements, string* nullValue);

template <>
void ColumnData<complex<float> >::readColumnData (long firstRow, long nelements,complex<float>* nullValue);


template <>
void ColumnData<complex<double> >::readColumnData (long firstRow, long nelements,complex<double>* nullValue);

template <>
void ColumnData<string>::writeData (const std::vector<string>& inData, long firstRow, string* nullValue);

template <>
void ColumnData<complex<float> >::writeData (const std::vector<complex<float> >& inData, long firstRow, 
                                complex<float>* nullValue);

template <>
void ColumnData<complex<double> >::writeData (const std::vector<complex<double> >& inData, long firstRow, 
                                complex<double>* nullValue);


} // namespace CCfits



#endif
