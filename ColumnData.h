//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%385E5287F550.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%385E5287F550.cm

//## begin module%385E5287F550.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%385E5287F550.cp

//## Module: ColumnData%385E5287F550; Package specification
//## Subsystem: CCfits::Column%3934116D0008
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/ColumnData.h

#ifndef COLUMNDATA_H
#define COLUMNDATA_H 1

//## begin module%385E5287F550.additionalIncludes preserve=no
#include "CCfits.h"
//## end module%385E5287F550.additionalIncludes

// vector
#include <vector>
// Column
#include "Column.h"
//## begin module%385E5287F550.includes preserve=yes
#ifdef _MSC_VER
#include "MSconfig.h"
#endif

#include <complex>
#include <memory>
//## end module%385E5287F550.includes

//## begin module%385E5287F550.declarations preserve=yes
#include "FITSUtil.h"
//## end module%385E5287F550.declarations

//## begin module%385E5287F550.additionalDeclarations preserve=yes
using std::complex;
#include "FITS.h"
//## end module%385E5287F550.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::ColumnData%385E514A2C78.preface preserve=yes
  //## end CCfits::ColumnData%385E514A2C78.preface

  //## Class: ColumnData%385E514A2C78; private; Parameterized Class
  //## Category: CCfits::Column%393417970264
  //## Subsystem: CCfits::Column%3934116D0008
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n
  //## Space Complexity: T



  template <typename T>
  class ColumnData : public Column  //## Inherits: <unnamed>%385E51565EE8
  {
    //## begin CCfits::ColumnData%385E514A2C78.initialDeclarations preserve=yes
    //## end CCfits::ColumnData%385E514A2C78.initialDeclarations

    public:
      //## Constructors (generated)
        ColumnData(const ColumnData< T > &right);

      //## Constructors (specified)
        //## Operation: ColumnData%3937D46302D5
        ColumnData (Table* p = 0, T nullVal = FITSUtil::FitsNullValue<T>()());

        //## Operation: ColumnData%3947C860026F
        ColumnData (int columnIndex, const string &columnName, ValueType type, const String &format, const String &unit, Table* p, int rpt = 1, long w = 1, const String &comment = "", T nullVal = FITSUtil::FitsNullValue<T>()());

      //## Destructor (generated)
        ~ColumnData();


      //## Other Operations (specified)
        //## Operation: clone%385E51BCCEF8
        virtual ColumnData<T>* clone () const;

        //## Operation: readData%3B0A98AE0215
        virtual void readData (long firstRow, long nelements, long firstElem = 1);

        //## Operation: setDataLimits%3B41FF7803AF
        void setDataLimits (T* limits);

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: minLegalValue%3B3CECAD00E2
        const T minLegalValue () const;
        void minLegalValue (T value);

        //## Attribute: maxLegalValue%3B3CECD000D2
        const T maxLegalValue () const;
        void maxLegalValue (T value);

        //## Attribute: minDataValue%3B3CECD10344
        const T minDataValue () const;
        void minDataValue (T value);

        //## Attribute: maxDataValue%3B3CECD300EC
        const T maxDataValue () const;
        void maxDataValue (T value);

      //## Get and Set Operations for Associations (generated)

        //## Association: CCfits::Column::Data%3E93052302B7
        //## Role: ColumnData::data%3E93052500BA
        //## Qualifier: i%3E9306AF003B; int
        const std::vector<T>& data () const;
        void setData (const std::vector<T>& value);
        T data (int i);
        void data (int i, T value);

      // Additional Public Declarations
        //## begin CCfits::ColumnData%385E514A2C78.public preserve=yes
        friend class Column;
        //## end CCfits::ColumnData%385E514A2C78.public
    protected:
      // Additional Protected Declarations
        //## begin CCfits::ColumnData%385E514A2C78.protected preserve=yes
        //## end CCfits::ColumnData%385E514A2C78.protected

    private:
      //## Assignment Operation (generated)
        ColumnData< T > & operator=(const ColumnData< T > &right);


      //## Other Operations (specified)
        //## Operation: readColumnData%389F1A923990
        void readColumnData (long firstRow, long nelements, T* nullValue = 0);

        //## Operation: compare%385E519F0E48
        virtual bool compare (const Column &right) const;

        //## Operation: put%3985C34501ED
        virtual std::ostream& put (std::ostream& s) const;

        //## Operation: writeData%39FF42B9033C
        void writeData (T* indata, long nRows = 1, long firstRow = 1, T* nullValue = 0);

        //## Operation: writeData%3B0D748D0281
        void writeData (const std::vector<T>& indata, long firstRow = 1, T* nullValue = 0);

        //## Operation: insertRows%3B21383403B2
        //	Insert one or more blank rows into a FITS column.
        virtual void insertRows (long first, long number = 1);

        //## Operation: deleteRows%3B213838015C
        virtual void deleteRows (long first, long number = 1);

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: nullValue%39F451CA0123
        const T nullValue () const;
        void nullValue (T value);

      // Additional Private Declarations
        //## begin CCfits::ColumnData%385E514A2C78.private preserve=yes
        //## end CCfits::ColumnData%385E514A2C78.private

    private: //## implementation
      // Data Members for Class Attributes

        //## begin CCfits::ColumnData::nullValue%39F451CA0123.attr preserve=no  private: T {U} nulVal
        T m_nullValue;
        //## end CCfits::ColumnData::nullValue%39F451CA0123.attr

        //## begin CCfits::ColumnData::minLegalValue%3B3CECAD00E2.attr preserve=no  public: T {U} 
        T m_minLegalValue;
        //## end CCfits::ColumnData::minLegalValue%3B3CECAD00E2.attr

        //## begin CCfits::ColumnData::maxLegalValue%3B3CECD000D2.attr preserve=no  public: T {U} 
        T m_maxLegalValue;
        //## end CCfits::ColumnData::maxLegalValue%3B3CECD000D2.attr

        //## begin CCfits::ColumnData::minDataValue%3B3CECD10344.attr preserve=no  public: T {U} 
        T m_minDataValue;
        //## end CCfits::ColumnData::minDataValue%3B3CECD10344.attr

        //## begin CCfits::ColumnData::maxDataValue%3B3CECD300EC.attr preserve=no  public: T {U} 
        T m_maxDataValue;
        //## end CCfits::ColumnData::maxDataValue%3B3CECD300EC.attr

      // Data Members for Associations

        //## Association: CCfits::Column::Data%3E93052302B7
        //## begin CCfits::ColumnData::data%3E93052500BA.role preserve=no  public: std::vector { -> 1VHgN}
        std::vector<T> m_data;
        //## end CCfits::ColumnData::data%3E93052500BA.role

      // Additional Implementation Declarations
        //## begin CCfits::ColumnData%385E514A2C78.implementation preserve=yes
        //## end CCfits::ColumnData%385E514A2C78.implementation

  };

  //## begin CCfits::ColumnData%385E514A2C78.postscript preserve=yes
  //## end CCfits::ColumnData%385E514A2C78.postscript

  // Parameterized Class CCfits::ColumnData 


  //## Other Operations (inline)
  template <typename T>
  inline void ColumnData<T>::readData (long firstRow, long nelements, long firstElem)
  {
    //## begin CCfits::ColumnData::readData%3B0A98AE0215.body preserve=yes
   readColumnData(firstRow,nelements,static_cast<T*>(0));
    //## end CCfits::ColumnData::readData%3B0A98AE0215.body
  }

  //## Get and Set Operations for Class Attributes (inline)

  template <typename T>
  inline const T ColumnData<T>::nullValue () const
  {
    //## begin CCfits::ColumnData::nullValue%39F451CA0123.get preserve=no
    return m_nullValue;
    //## end CCfits::ColumnData::nullValue%39F451CA0123.get
  }

  template <typename T>
  inline void ColumnData<T>::nullValue (T value)
  {
    //## begin CCfits::ColumnData::nullValue%39F451CA0123.set preserve=no
    m_nullValue = value;
    //## end CCfits::ColumnData::nullValue%39F451CA0123.set
  }

  template <typename T>
  inline const T ColumnData<T>::minLegalValue () const
  {
    //## begin CCfits::ColumnData::minLegalValue%3B3CECAD00E2.get preserve=no
    return m_minLegalValue;
    //## end CCfits::ColumnData::minLegalValue%3B3CECAD00E2.get
  }

  template <typename T>
  inline void ColumnData<T>::minLegalValue (T value)
  {
    //## begin CCfits::ColumnData::minLegalValue%3B3CECAD00E2.set preserve=no
    m_minLegalValue = value;
    //## end CCfits::ColumnData::minLegalValue%3B3CECAD00E2.set
  }

  template <typename T>
  inline const T ColumnData<T>::maxLegalValue () const
  {
    //## begin CCfits::ColumnData::maxLegalValue%3B3CECD000D2.get preserve=no
    return m_maxLegalValue;
    //## end CCfits::ColumnData::maxLegalValue%3B3CECD000D2.get
  }

  template <typename T>
  inline void ColumnData<T>::maxLegalValue (T value)
  {
    //## begin CCfits::ColumnData::maxLegalValue%3B3CECD000D2.set preserve=no
    m_maxLegalValue = value;
    //## end CCfits::ColumnData::maxLegalValue%3B3CECD000D2.set
  }

  template <typename T>
  inline const T ColumnData<T>::minDataValue () const
  {
    //## begin CCfits::ColumnData::minDataValue%3B3CECD10344.get preserve=no
    return m_minDataValue;
    //## end CCfits::ColumnData::minDataValue%3B3CECD10344.get
  }

  template <typename T>
  inline void ColumnData<T>::minDataValue (T value)
  {
    //## begin CCfits::ColumnData::minDataValue%3B3CECD10344.set preserve=no
    m_minDataValue = value;
    //## end CCfits::ColumnData::minDataValue%3B3CECD10344.set
  }

  template <typename T>
  inline const T ColumnData<T>::maxDataValue () const
  {
    //## begin CCfits::ColumnData::maxDataValue%3B3CECD300EC.get preserve=no
    return m_maxDataValue;
    //## end CCfits::ColumnData::maxDataValue%3B3CECD300EC.get
  }

  template <typename T>
  inline void ColumnData<T>::maxDataValue (T value)
  {
    //## begin CCfits::ColumnData::maxDataValue%3B3CECD300EC.set preserve=no
    m_maxDataValue = value;
    //## end CCfits::ColumnData::maxDataValue%3B3CECD300EC.set
  }

  //## Get and Set Operations for Associations (inline)

  template <typename T>
  inline const std::vector<T>& ColumnData<T>::data () const
  {
    //## begin CCfits::ColumnData::data%3E93052500BA.get preserve=no
    return m_data;
    //## end CCfits::ColumnData::data%3E93052500BA.get
  }

  template <typename T>
  inline void ColumnData<T>::setData (const std::vector<T>& value)
  {
    //## begin CCfits::ColumnData::setData%3E93052500BA.set preserve=no
    m_data = value;
    //## end CCfits::ColumnData::setData%3E93052500BA.set
  }

  template <typename T>
  inline T ColumnData<T>::data (int i)
  {
    //## begin CCfits::ColumnData::data%3E93052500BA.qualget preserve=yes
    // return data stored in the ith row, which is in the i-1 th location in the array.
    return m_data[i - 1];
    //## end CCfits::ColumnData::data%3E93052500BA.qualget
  }

  template <typename T>
  inline void ColumnData<T>::data (int i, T value)
  {
    //## begin CCfits::ColumnData::data%3E93052500BA.qualset preserve=yes
    // assign data to i-1 th location in the array, representing the ith row.
    m_data[i - 1] = value;
    //## end CCfits::ColumnData::data%3E93052500BA.qualset
  }

  // Parameterized Class CCfits::ColumnData 

  template <typename T>
  ColumnData<T>::ColumnData(const ColumnData<T> &right)
    //## begin ColumnData::ColumnData%385E514A2C78_copy.hasinit preserve=yes
      :Column(right),
       m_nullValue(right.m_nullValue),
       m_minLegalValue(right.m_minLegalValue),
       m_maxLegalValue(right.m_maxLegalValue),
       m_minDataValue(right.m_minDataValue),
       m_maxDataValue(right.m_maxDataValue),
       m_data(right.m_data)
    //## end ColumnData::ColumnData%385E514A2C78_copy.hasinit
    //## begin ColumnData::ColumnData%385E514A2C78_copy.initialization preserve=yes
    //## end ColumnData::ColumnData%385E514A2C78_copy.initialization
  {
    //## begin CCfits::ColumnData::ColumnData%385E514A2C78_copy.body preserve=yes
    //## end CCfits::ColumnData::ColumnData%385E514A2C78_copy.body
  }

  template <typename T>
  ColumnData<T>::ColumnData (Table* p, T nullVal)
    //## begin CCfits::ColumnData::ColumnData%3937D46302D5.hasinit preserve=yes
  : Column(p), m_nullValue(nullVal),
       m_minLegalValue(),
       m_maxLegalValue(),
       m_minDataValue(),
       m_maxDataValue(), 
       m_data()
    //## end CCfits::ColumnData::ColumnData%3937D46302D5.hasinit
    //## begin CCfits::ColumnData::ColumnData%3937D46302D5.initialization preserve=yes
    //## end CCfits::ColumnData::ColumnData%3937D46302D5.initialization
  {
    //## begin CCfits::ColumnData::ColumnData%3937D46302D5.body preserve=yes
    //## end CCfits::ColumnData::ColumnData%3937D46302D5.body
  }

  template <typename T>
  ColumnData<T>::ColumnData (int columnIndex, const string &columnName, ValueType type, const String &format, const String &unit, Table* p, int rpt, long w, const String &comment, T nullVal)
    //## begin CCfits::ColumnData::ColumnData%3947C860026F.hasinit preserve=yes
        : Column(columnIndex,columnName,type,format,unit,p,rpt,w,comment), 
        m_nullValue(nullVal), 
        m_minLegalValue(),
        m_maxLegalValue(),
        m_minDataValue(),
        m_maxDataValue(),
        m_data()
          
    //## end CCfits::ColumnData::ColumnData%3947C860026F.hasinit
    //## begin CCfits::ColumnData::ColumnData%3947C860026F.initialization preserve=yes
    //## end CCfits::ColumnData::ColumnData%3947C860026F.initialization
  {
    //## begin CCfits::ColumnData::ColumnData%3947C860026F.body preserve=yes
    //## end CCfits::ColumnData::ColumnData%3947C860026F.body
  }


  template <typename T>
  ColumnData<T>::~ColumnData()
  {
    //## begin CCfits::ColumnData::~ColumnData%385E514A2C78_dest.body preserve=yes
    //## end CCfits::ColumnData::~ColumnData%385E514A2C78_dest.body
  }



  //## Other Operations (implementation)
  template <typename T>
  void ColumnData<T>::readColumnData (long firstRow, long nelements, T* nullValue)
  {
    //## begin CCfits::ColumnData::readColumnData%389F1A923990.body preserve=yes
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
    //## end CCfits::ColumnData::readColumnData%389F1A923990.body
  }

  template <typename T>
  bool ColumnData<T>::compare (const Column &right) const
  {
    //## begin CCfits::ColumnData::compare%385E519F0E48.body preserve=yes
  if ( !Column::compare(right) ) return false;
  const ColumnData<T>& that = static_cast<const ColumnData<T>&>(right);
  unsigned int n = m_data.size();
  if ( that.m_data.size() != n ) return false;
  for (unsigned int i = 0; i < n ; i++)
  {
        if (m_data[i] != that.m_data[i]) return false;   
  }
  return true;
    //## end CCfits::ColumnData::compare%385E519F0E48.body
  }

  template <typename T>
  ColumnData<T>* ColumnData<T>::clone () const
  {
    //## begin CCfits::ColumnData::clone%385E51BCCEF8.body preserve=yes
        return new ColumnData<T>(*this);
    //## end CCfits::ColumnData::clone%385E51BCCEF8.body
  }

  template <typename T>
  std::ostream& ColumnData<T>::put (std::ostream& s) const
  {
    //## begin CCfits::ColumnData::put%3985C34501ED.body preserve=yes
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
    //## end CCfits::ColumnData::put%3985C34501ED.body

    return s;
  }

  template <typename T>
  void ColumnData<T>::writeData (T* indata, long nRows, long firstRow, T* nullValue)
  {
    //## begin CCfits::ColumnData::writeData%39FF42B9033C.body preserve=yes
  
          // set columnData's data member to equal what's written to file.
          // indata has size nRows: elements firstRow to firstRow + nRows - 1 will be written.
          // if this exceeds the current rowlength of the HDU, update the return value for
          // rows() in the parent after the fitsio call.
          int status(0);
          long elementsToWrite(nRows + firstRow -1);
          // get a copy for restorative action.   
          std::vector<T> __tmp(m_data);
          
          if (nullValue) m_nullValue = *nullValue;

          if (elementsToWrite != static_cast<long>(m_data.size())) 
          {

                  m_data.resize(elementsToWrite,T());
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

    //## end CCfits::ColumnData::writeData%39FF42B9033C.body
  }

  template <typename T>
  void ColumnData<T>::writeData (const std::vector<T>& indata, long firstRow, T* nullValue)
  {
    //## begin CCfits::ColumnData::writeData%3B0D748D0281.body preserve=yes
        FITSUtil::CVarray<T> convert;
        FITSUtil::auto_array_ptr<T> pcolData (convert(indata));
        T* columnData  = pcolData.get();
        writeData(columnData,indata.size(),firstRow,nullValue);
    //## end CCfits::ColumnData::writeData%3B0D748D0281.body
  }

  template <typename T>
  void ColumnData<T>::insertRows (long first, long number)
  {
    //## begin CCfits::ColumnData::insertRows%3B21383403B2.body preserve=yes
    FITSUtil::FitsNullValue<T> blank;
    typename std::vector<T>::iterator in;
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
    //## end CCfits::ColumnData::insertRows%3B21383403B2.body
  }

  template <typename T>
  void ColumnData<T>::deleteRows (long first, long number)
  {
    //## begin CCfits::ColumnData::deleteRows%3B213838015C.body preserve=yes
    m_data.erase(m_data.begin()+first-1,m_data.begin()+first-1+number);
    //## end CCfits::ColumnData::deleteRows%3B213838015C.body
  }

  template <typename T>
  void ColumnData<T>::setDataLimits (T* limits)
  {
    //## begin CCfits::ColumnData::setDataLimits%3B41FF7803AF.body preserve=yes
    m_minLegalValue = limits[0];
    m_maxLegalValue = limits[1];
    m_minDataValue = std::max(limits[2],limits[0]);
    m_maxDataValue = std::min(limits[3],limits[1]);
    //## end CCfits::ColumnData::setDataLimits%3B41FF7803AF.body
  }

  // Additional Declarations
    //## begin CCfits::ColumnData%385E514A2C78.declarations preserve=yes
  
  // all functions that operate on strings or complex data that call cfitsio 
  // need to be specialized.

#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
template <>
inline void ColumnData<complex<float> >::setDataLimits (complex<float>* limits)
       {
                m_minLegalValue = limits[0];
                m_maxLegalValue = limits[1];
                m_minDataValue =  limits[2];
                m_maxDataValue =  limits[3];
        }
#else
template <>
  void ColumnData<complex<float> >::setDataLimits (complex<float>* limits);
#endif

#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
template <>
inline void ColumnData<complex<double> >::setDataLimits (complex<double>* limits)
        {
                m_minLegalValue = limits[0];
                m_maxLegalValue = limits[1];
                m_minDataValue =  limits[2];
                m_maxDataValue =  limits[3];
        }
#else
 template <>
  void ColumnData<complex<double> >::setDataLimits (complex<double>* limits);
#endif


#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
        template <>
        inline void ColumnData<string>::readColumnData (long firstRow, 
                                        long nelements, 
                                        string* nullValue)
        {
          int status = 0;

           int   anynul = 0;
           char** array = new char*[nelements]; 

           int j(0);
           for ( ; j < nelements; ++j)
           {
               array[j] = new char[width() + 1];
           }

           char* nulval = 0;
           if (nullValue) 
           {
                   nulval = const_cast<char*>(nullValue->c_str());
           }
           else
           {
                nulval = new char;
                *nulval = '\0';       
           }


          try
          {
                makeHDUCurrent();
                if (fits_read_col_str(fitsPointer(),index(), firstRow,1,nelements,
                  nulval,array, &anynul,&status) ) throw FitsError(status);
          }
          catch (FitsError)
          {
                // ugly. but better than leaking resources.       
                for (int jj = 0; jj < nelements; ++jj)
                {
                        delete [] array[jj];
                }     

                delete [] array; 
                delete nulval;
                throw; 
          }


          if (m_data.size() == 0) setData(std::vector<string>(rows(),string(nulval)));

          // the 'first -1 ' converts to zero based indexing.

          for ( j = 0; j < nelements; j++)
          {
                m_data[j - 1 + firstRow] = string(array[j]);
          }

          for ( j = 0; j < nelements; j++)
          {
                delete [] array[j];
          }     

          delete [] array; 
          delete nulval; 

        }
#else 
 template <>
void ColumnData<string>::readColumnData (long firstRow, long nelements, string* nullValue);
#endif


#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
        template <>
        inline void ColumnData<complex<float> >::readColumnData (long firstRow,
                                                long nelements,
                                                complex<float>* nullValue)
        {
          // specialization for ColumnData<string> 
          int status(0);
          int   anynul(0);
          FITSUtil::auto_array_ptr<float> pArray(new float[nelements*2]); 
          float* array = pArray.get();
          float nulval(0);
          makeHDUCurrent();


          if (fits_read_col_cmp(fitsPointer(),index(), firstRow,1,nelements,
                  nulval,array, &anynul,&status) ) throw FitsError(status);


          if (m_data.size() == 0) m_data.resize(rows());

          // the 'j -1 ' converts to zero based indexing.

          for (int j = firstRow; j < nelements; ++j)
          {
                
                m_data[j - 1] = std::complex<float>(array[2*j],array[2*j+1]);
          }

        }
#else
template <> 
void ColumnData<complex<float> >::readColumnData (long firstRow, long nelements,complex<float>* nullValue );
#endif

#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
        template <>
        inline void ColumnData<complex<double> >::readColumnData (long firstRow, 
                                                        long nelements,
                                                        complex<double>* nullValue)
        {
          // specialization for ColumnData<complex<double> > 
           int status(0);
           int   anynul(0);
           FITSUtil::auto_array_ptr<double> pArray(new double[nelements*2]); 
           double* array = pArray.get();
           double nulval(0);
           makeHDUCurrent();


          if (fits_read_col_dblcmp(fitsPointer(), index(), firstRow,1,nelements,
                  nulval,array, &anynul,&status) ) throw FitsError(status);




          if (m_data.size() == 0) setData(std::vector<complex<double> >(rows(),nulval));

          // the 'j -1 ' converts to zero based indexing.

          for (int j = firstRow; j < nelements; j++)
          {
                
                m_data[j - 1] = std::complex<double>(array[2*j],array[2*j+1]);
          }

        }
#else
template <>
void ColumnData<complex<double> >::readColumnData (long firstRow, long nelements,complex<double>* nullValue);
#endif

#if SPEC_TEMPLATE_DECL_DEFECT
  template <>
  inline void ColumnData<string>::writeData (const std::vector<string>& indata, 
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
#else
template <>
void ColumnData<string>::writeData (const std::vector<string>& inData, long firstRow, string* nullValue);
#endif

#ifdef SPEC_TEMPLATE_DECL_DEFECT
  template <>
  inline void ColumnData<complex<float> >::writeData (const std::vector<complex<float> >& inData, 
					       long firstRow, 
					       complex<float>* nullValue)
  {
    int status(0);
    int nRows (inData.size());
    FITSUtil::auto_array_ptr<float> pData(new float[nRows*2]);
    float* Data = pData.get();
    std::vector<complex<float> > __tmp(m_data);
    for (int j = firstRow; j < nRows; ++j)
      {
	Data[ 2*j] = inData[j].real();
	Data[ 2*j + 1] = inData[j].imag();
      }     
                
    try
      {

	if (fits_write_col_cmp(fitsPointer(), index(), firstRow, 1, 
			       nRows,Data, &status) != 0) throw FitsError(status);
	long elementsToWrite(nRows + firstRow -1);
	if (elementsToWrite > static_cast<long>(m_data.size())) 
	  {

	    m_data.resize(elementsToWrite);
	  }

	std::copy(inData.begin(),inData.end(),m_data.begin()+firstRow-1);

	// tell the Table that the number of rows has changed
	parent()->updateRows();
      }
    catch (FitsError) // the only thing that can throw here.
      {
	// reset to original content and rethrow the exception.
	m_data.resize(__tmp.size());
	m_data = __tmp;
      }      

  }

#else
template <>
void ColumnData<complex<float> >::writeData (const std::vector<complex<float> >& inData, long firstRow, 
                                complex<float>* nullValue);
#endif

#ifdef SPEC_TEMPLATE_DECL_DEFECT
  template <>
  inline void ColumnData<complex<double> >::writeData (const std::vector<complex<double> >& inData, 
						long firstRow, 
						complex<double>* nullValue)
  {
    int status(0);
    int nRows (inData.size());
    FITSUtil::auto_array_ptr<double> pData(new double[nRows*2]);
    double* Data = pData.get();
    std::vector<complex<double> > __tmp(m_data);
    for (int j = firstRow; j < nRows; ++j)
      {
	pData[ 2*j] = inData[j].real();
	pData[ 2*j + 1] = inData[j].imag();
      }     
                
    try
      {

	if (fits_write_col_dblcmp(fitsPointer(), index(), firstRow, 1, 
                                  nRows,Data, &status) != 0) throw FitsError(status);
	long elementsToWrite(nRows + firstRow -1);
	if (elementsToWrite > static_cast<long>(m_data.size())) 
	  {

	    m_data.resize(elementsToWrite);
	  }

	std::copy(inData.begin(),inData.end(),m_data.begin()+firstRow-1);

	// tell the Table that the number of rows has changed
	parent()->updateRows();
      }
    catch (FitsError) // the only thing that can throw here.
      {
	// reset to original content and rethrow the exception.
	m_data.resize(__tmp.size());
	m_data = __tmp;
      }      

  }
       
#else
template <>
void ColumnData<complex<double> >::writeData (const std::vector<complex<double> >& inData, long firstRow, 
                                complex<double>* nullValue);

#endif
    //## end CCfits::ColumnData%385E514A2C78.declarations
} // namespace CCfits

//## begin module%385E5287F550.epilog preserve=yes
//## end module%385E5287F550.epilog


#endif
