//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%38BAD0CF1E60.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%38BAD0CF1E60.cm

//## begin module%38BAD0CF1E60.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%38BAD0CF1E60.cp

//## Module: ColumnVectorData%38BAD0CF1E60; Package specification
//## Subsystem: CCfits::Column%3934116D0008
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/ColumnVectorData.h

#ifndef COLUMNVECTORDATA_H
#define COLUMNVECTORDATA_H 1

//## begin module%38BAD0CF1E60.additionalIncludes preserve=yes
#ifdef _MSC_VER
#include "MSconfig.h"
#endif
#include "CCfits.h"
//## end module%38BAD0CF1E60.additionalIncludes

// vector
#include <vector>
// valarray
#include <valarray>
// Column
#include "Column.h"
//## begin module%38BAD0CF1E60.includes preserve=yes
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef SSTREAM_DEFECT
#include <strstream>
#else
#include <sstream>
#endif

#include <memory>
#include <numeric>
//## end module%38BAD0CF1E60.includes

//## begin module%38BAD0CF1E60.declarations preserve=no
//## end module%38BAD0CF1E60.declarations

//## begin module%38BAD0CF1E60.additionalDeclarations preserve=yes
namespace CCfits {

        class Table;

}

#include "FITS.h"
#include "FITSUtil.h"
using std::complex;
//## end module%38BAD0CF1E60.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::ColumnVectorData%38BAD1B0AA40.preface preserve=yes
  //## end CCfits::ColumnVectorData%38BAD1B0AA40.preface

  //## Class: ColumnVectorData%38BAD1B0AA40; Parameterized Class
  //## Category: CCfits::Column%393417970264
  //## Subsystem: CCfits::Column%3934116D0008
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n
  //## Space Complexity: T



  //## Uses: <unnamed>%393EA834025B;std::valarray { -> }

  template <typename T>
  class ColumnVectorData : public Column  //## Inherits: <unnamed>%38BAD1D4D370
  {
    //## begin CCfits::ColumnVectorData%38BAD1B0AA40.initialDeclarations preserve=yes
    //## end CCfits::ColumnVectorData%38BAD1B0AA40.initialDeclarations

    public:
      //## Constructors (generated)
        ColumnVectorData(const ColumnVectorData< T > &right);

      //## Constructors (specified)
        //## Operation: ColumnVectorData%3937D8940092
        ColumnVectorData (Table* p = 0, T nullVal = FITSUtil::FitsNullValue<T>()());

        //## Operation: ColumnVectorData%3947C8B30086
        ColumnVectorData (int columnIndex, const string &columnName, ValueType type, const string &format, const string &unit, Table* p, int  rpt = 1, long w = 1, const string &comment = "", T nullVal = FITSUtil::FitsNullValue<T>()());

      //## Destructor (generated)
        ~ColumnVectorData();


      //## Other Operations (specified)
        //## Operation: readData%38BAD4E55B38
        virtual void readData (long firstrow, long nelements, long firstelem = 1);

        //## Operation: clone%38BAD53513B0
        virtual ColumnVectorData<T>* clone () const;

        //## Operation: setDimen%3948FFA702E2
        virtual void setDimen ();

        //## Operation: setDataLimits%3B420063035B
        void setDataLimits (T* limits);

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: minLegalValue%3B3CED5D00E4
        const T minLegalValue () const;
        void minLegalValue (T value);

        //## Attribute: maxLegalValue%3B3CED5F00EF
        const T maxLegalValue () const;
        void maxLegalValue (T value);

        //## Attribute: minDataValue%3B3CED6002A7
        const T minDataValue () const;
        void minDataValue (T value);

        //## Attribute: maxDataValue%3B3CED6200BF
        const T maxDataValue () const;
        void maxDataValue (T value);

      //## Get and Set Operations for Associations (generated)

        //## Association: CCfits::Column::Vector Data%3E9309C8002B
        //## Role: ColumnVectorData::data%3E9309CC0097
        //## Qualifier: i%3E9309DA03DA; int
        const std::vector<std::valarray<T> >& data () const;
        void setData (const std::vector<std::valarray<T> >& value);
        const std::valarray<T>& data (int i) const;
        void data (int i, const std::valarray<T>& value);

      // Additional Public Declarations
        //## begin CCfits::ColumnVectorData%38BAD1B0AA40.public preserve=yes
        friend class Column;
        //## end CCfits::ColumnVectorData%38BAD1B0AA40.public
    protected:
      // Additional Protected Declarations
        //## begin CCfits::ColumnVectorData%38BAD1B0AA40.protected preserve=yes
        //## end CCfits::ColumnVectorData%38BAD1B0AA40.protected

    private:
      //## Assignment Operation (generated)
        ColumnVectorData< T > & operator=(const ColumnVectorData< T > &right);


      //## Other Operations (specified)
        //## Operation: compare%38BAD52BCDD0
        virtual bool compare (const Column &right) const;

        //## Operation: resizeDataObject%3B20DBAA02B8
        void resizeDataObject (const std::vector<std::valarray<T> >& indata, size_t firstRow);

        //## Operation: readColumnData%395A4FD40034
        //	Reads a specified number of column rows.
        //
        //	There are no default arguments. The function
        //	Column::read(firstrow,firstelem,nelements)
        //	 is designed for reading the whole column.
        virtual void readColumnData (long first, long last, T* nullValue = 0);

        //## Operation: put%3985C35702F7
        virtual std::ostream& put (std::ostream& s) const;

        //## Operation: writeData%3A018B000355
        void writeData (const std::valarray<T>& indata, long numRows, long firstRow = 1, T* nullValue = 0);

        //## Operation: writeData%3B003FF302B8
        void writeData (const std::vector<std::valarray<T> >& indata, long firstRow = 1, T* nullValue = 0);

        //## Operation: readRow%3B0A8227012E
        //	Reads a specified number of column rows.
        //
        //	There are no default arguments. The function
        //	Column::read(firstrow,firstelem,nelements)
        //	 is designed for reading the whole column.
        virtual void readRow (size_t row, T* nullValue = 0);

        //## Operation: readVariableRow%3B0A91220009
        //	Reads a variable row..
        virtual void readVariableRow (size_t row, T* nullValue = 0);

        //## Operation: readColumnData%3B0A98EF033F
        void readColumnData (long firstrow, long nelements, long firstelem, T* nullValue = 0);

        //## Operation: writeData%3B0AAF0401BD
        void writeData (const std::valarray<T>& indata, const std::vector<long>& vectorLengths, long firstRow = 1, T* nullValue = 0);

        //## Operation: writeRow%3B0AAFCD0312
        void writeRow (const std::valarray<T>& data, long row, long firstElem = 1, T* nullValue = 0);

        //## Operation: writeFixedArray%3B0BDA2801BF
        void writeFixedArray (T* data, long nElements, long nRows, long firstRow, T* nullValue = 0);

        //## Operation: writeData%3B0D34D1024A
        void writeData (T* indata, long nElements, long numRows, long firstRow = 1, T* nullValue = 0);

        //## Operation: insertRows%3B2138F60241
        //	Insert one or more blank rows into a FITS column.
        virtual void insertRows (long first, long number = 1);

        //## Operation: deleteRows%3B2138FF03A4
        virtual void deleteRows (long first, long number = 1);

        //## Operation: doWrite%3CDFCBD402E6
        void doWrite (T* array, long row, long rowSize);

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: nullValue%39F452200285
        const T nullValue () const;
        void nullValue (T value);

      // Additional Private Declarations
        //## begin CCfits::ColumnVectorData%38BAD1B0AA40.private preserve=yes
        //## end CCfits::ColumnVectorData%38BAD1B0AA40.private

    private: //## implementation
      // Data Members for Class Attributes

        //## begin CCfits::ColumnVectorData::nullValue%39F452200285.attr preserve=no  private: T {U} nulVal
        T m_nullValue;
        //## end CCfits::ColumnVectorData::nullValue%39F452200285.attr

        //## begin CCfits::ColumnVectorData::minLegalValue%3B3CED5D00E4.attr preserve=no  public: T {U} 
        T m_minLegalValue;
        //## end CCfits::ColumnVectorData::minLegalValue%3B3CED5D00E4.attr

        //## begin CCfits::ColumnVectorData::maxLegalValue%3B3CED5F00EF.attr preserve=no  public: T {U} 
        T m_maxLegalValue;
        //## end CCfits::ColumnVectorData::maxLegalValue%3B3CED5F00EF.attr

        //## begin CCfits::ColumnVectorData::minDataValue%3B3CED6002A7.attr preserve=no  public: T {U} 
        T m_minDataValue;
        //## end CCfits::ColumnVectorData::minDataValue%3B3CED6002A7.attr

        //## begin CCfits::ColumnVectorData::maxDataValue%3B3CED6200BF.attr preserve=no  public: T {U} 
        T m_maxDataValue;
        //## end CCfits::ColumnVectorData::maxDataValue%3B3CED6200BF.attr

      // Data Members for Associations

        //## Association: CCfits::Column::Vector Data%3E9309C8002B
        //## begin CCfits::ColumnVectorData::data%3E9309CC0097.role preserve=no  public: std::vector { -> 1VHgN}
        std::vector<std::valarray<T> > m_data;
        //## end CCfits::ColumnVectorData::data%3E9309CC0097.role

      // Additional Implementation Declarations
        //## begin CCfits::ColumnVectorData%38BAD1B0AA40.implementation preserve=yes
        //## end CCfits::ColumnVectorData%38BAD1B0AA40.implementation

  };

  //## begin CCfits::ColumnVectorData%38BAD1B0AA40.postscript preserve=yes
  //## end CCfits::ColumnVectorData%38BAD1B0AA40.postscript

  // Parameterized Class CCfits::ColumnVectorData 


  //## Other Operations (inline)
  template <typename T>
  inline void ColumnVectorData<T>::readData (long firstrow, long nelements, long firstelem)
  {
    //## begin CCfits::ColumnVectorData::readData%38BAD4E55B38.body preserve=yes
    readColumnData(firstrow,nelements,firstelem,static_cast<T*>(0));
    //## end CCfits::ColumnVectorData::readData%38BAD4E55B38.body
  }

  //## Get and Set Operations for Class Attributes (inline)

  template <typename T>
  inline const T ColumnVectorData<T>::nullValue () const
  {
    //## begin CCfits::ColumnVectorData::nullValue%39F452200285.get preserve=no
    return m_nullValue;
    //## end CCfits::ColumnVectorData::nullValue%39F452200285.get
  }

  template <typename T>
  inline void ColumnVectorData<T>::nullValue (T value)
  {
    //## begin CCfits::ColumnVectorData::nullValue%39F452200285.set preserve=no
    m_nullValue = value;
    //## end CCfits::ColumnVectorData::nullValue%39F452200285.set
  }

  template <typename T>
  inline const T ColumnVectorData<T>::minLegalValue () const
  {
    //## begin CCfits::ColumnVectorData::minLegalValue%3B3CED5D00E4.get preserve=no
    return m_minLegalValue;
    //## end CCfits::ColumnVectorData::minLegalValue%3B3CED5D00E4.get
  }

  template <typename T>
  inline void ColumnVectorData<T>::minLegalValue (T value)
  {
    //## begin CCfits::ColumnVectorData::minLegalValue%3B3CED5D00E4.set preserve=no
    m_minLegalValue = value;
    //## end CCfits::ColumnVectorData::minLegalValue%3B3CED5D00E4.set
  }

  template <typename T>
  inline const T ColumnVectorData<T>::maxLegalValue () const
  {
    //## begin CCfits::ColumnVectorData::maxLegalValue%3B3CED5F00EF.get preserve=no
    return m_maxLegalValue;
    //## end CCfits::ColumnVectorData::maxLegalValue%3B3CED5F00EF.get
  }

  template <typename T>
  inline void ColumnVectorData<T>::maxLegalValue (T value)
  {
    //## begin CCfits::ColumnVectorData::maxLegalValue%3B3CED5F00EF.set preserve=no
    m_maxLegalValue = value;
    //## end CCfits::ColumnVectorData::maxLegalValue%3B3CED5F00EF.set
  }

  template <typename T>
  inline const T ColumnVectorData<T>::minDataValue () const
  {
    //## begin CCfits::ColumnVectorData::minDataValue%3B3CED6002A7.get preserve=no
    return m_minDataValue;
    //## end CCfits::ColumnVectorData::minDataValue%3B3CED6002A7.get
  }

  template <typename T>
  inline void ColumnVectorData<T>::minDataValue (T value)
  {
    //## begin CCfits::ColumnVectorData::minDataValue%3B3CED6002A7.set preserve=no
    m_minDataValue = value;
    //## end CCfits::ColumnVectorData::minDataValue%3B3CED6002A7.set
  }

  template <typename T>
  inline const T ColumnVectorData<T>::maxDataValue () const
  {
    //## begin CCfits::ColumnVectorData::maxDataValue%3B3CED6200BF.get preserve=no
    return m_maxDataValue;
    //## end CCfits::ColumnVectorData::maxDataValue%3B3CED6200BF.get
  }

  template <typename T>
  inline void ColumnVectorData<T>::maxDataValue (T value)
  {
    //## begin CCfits::ColumnVectorData::maxDataValue%3B3CED6200BF.set preserve=no
    m_maxDataValue = value;
    //## end CCfits::ColumnVectorData::maxDataValue%3B3CED6200BF.set
  }

  //## Get and Set Operations for Associations (inline)

  template <typename T>
  inline const std::vector<std::valarray<T> >& ColumnVectorData<T>::data () const
  {
    //## begin CCfits::ColumnVectorData::data%3E9309CC0097.get preserve=no
    return m_data;
    //## end CCfits::ColumnVectorData::data%3E9309CC0097.get
  }

  template <typename T>
  inline void ColumnVectorData<T>::setData (const std::vector<std::valarray<T> >& value)
  {
    //## begin CCfits::ColumnVectorData::setData%3E9309CC0097.set preserve=no
    m_data = value;
    //## end CCfits::ColumnVectorData::setData%3E9309CC0097.set
  }

  template <typename T>
  inline const std::valarray<T>& ColumnVectorData<T>::data (int i) const
  {
    //## begin CCfits::ColumnVectorData::data%3E9309CC0097.qualget preserve=yes
    return m_data[i - 1];
    //## end CCfits::ColumnVectorData::data%3E9309CC0097.qualget
  }

  template <typename T>
  inline void ColumnVectorData<T>::data (int i, const std::valarray<T>& value)
  {
    //## begin CCfits::ColumnVectorData::data%3E9309CC0097.qualset preserve=yes
     m_data[i - 1] = value;
    //## end CCfits::ColumnVectorData::data%3E9309CC0097.qualset
  }

  // Parameterized Class CCfits::ColumnVectorData 

  template <typename T>
  ColumnVectorData<T>::ColumnVectorData(const ColumnVectorData<T> &right)
    //## begin ColumnVectorData::ColumnVectorData%38BAD1B0AA40_copy.hasinit preserve=yes
      :Column(right),
       m_nullValue(right.m_nullValue),
       m_minLegalValue(right.m_minLegalValue),
       m_maxLegalValue(right.m_maxLegalValue),
       m_minDataValue(right.m_minDataValue),
       m_maxDataValue(right.m_maxDataValue),
       m_data(right.m_data)
    //## end ColumnVectorData::ColumnVectorData%38BAD1B0AA40_copy.hasinit
    //## begin ColumnVectorData::ColumnVectorData%38BAD1B0AA40_copy.initialization preserve=yes
    //## end ColumnVectorData::ColumnVectorData%38BAD1B0AA40_copy.initialization
  {
    //## begin CCfits::ColumnVectorData::ColumnVectorData%38BAD1B0AA40_copy.body preserve=yes
    //## end CCfits::ColumnVectorData::ColumnVectorData%38BAD1B0AA40_copy.body
  }

  template <typename T>
  ColumnVectorData<T>::ColumnVectorData (Table* p, T nullVal)
    //## begin CCfits::ColumnVectorData::ColumnVectorData%3937D8940092.hasinit preserve=yes
    : Column(p), m_nullValue(nullVal),
       m_minLegalValue(0),
       m_maxLegalValue(0),
       m_minDataValue(0),
       m_maxDataValue(0),
       m_data() 
    //## end CCfits::ColumnVectorData::ColumnVectorData%3937D8940092.hasinit
    //## begin CCfits::ColumnVectorData::ColumnVectorData%3937D8940092.initialization preserve=yes
    //## end CCfits::ColumnVectorData::ColumnVectorData%3937D8940092.initialization
  {
    //## begin CCfits::ColumnVectorData::ColumnVectorData%3937D8940092.body preserve=yes
    //## end CCfits::ColumnVectorData::ColumnVectorData%3937D8940092.body
  }

  template <typename T>
  ColumnVectorData<T>::ColumnVectorData (int columnIndex, const string &columnName, ValueType type, const string &format, const string &unit, Table* p, int  rpt, long w, const string &comment, T nullVal)
    //## begin CCfits::ColumnVectorData::ColumnVectorData%3947C8B30086.hasinit preserve=yes
        : Column(columnIndex,columnName,type,format,unit,p,rpt,w,comment),
          m_nullValue(nullVal),
          m_minLegalValue(0),
          m_maxLegalValue(0),
          m_minDataValue(0),
          m_maxDataValue(0), 
          m_data()
    //## end CCfits::ColumnVectorData::ColumnVectorData%3947C8B30086.hasinit
    //## begin CCfits::ColumnVectorData::ColumnVectorData%3947C8B30086.initialization preserve=yes
    //## end CCfits::ColumnVectorData::ColumnVectorData%3947C8B30086.initialization
  {
    //## begin CCfits::ColumnVectorData::ColumnVectorData%3947C8B30086.body preserve=yes
    //## end CCfits::ColumnVectorData::ColumnVectorData%3947C8B30086.body
  }


  template <typename T>
  ColumnVectorData<T>::~ColumnVectorData()
  {
    //## begin CCfits::ColumnVectorData::~ColumnVectorData%38BAD1B0AA40_dest.body preserve=yes
  // valarray destructor should do all the work.
    //## end CCfits::ColumnVectorData::~ColumnVectorData%38BAD1B0AA40_dest.body
  }



  //## Other Operations (implementation)
  template <typename T>
  bool ColumnVectorData<T>::compare (const Column &right) const
  {
    //## begin CCfits::ColumnVectorData::compare%38BAD52BCDD0.body preserve=yes
          if ( !Column::compare(right) ) return false;
          const ColumnVectorData<T>& that = static_cast<const ColumnVectorData<T>&>(right);
          size_t n = m_data.size();
          // m_data is of type valarray<T>.
          if ( that.m_data.size() != n ) return false;
          for (size_t i = 0; i < n ; i++)
          {
                size_t nn = m_data[i].size();
                // first check size (also, == on 2 valarrays is only defined if they
                // are equal in size).
                if (that.m_data[i].size() != nn ) return false;

                std::valarray<bool> test = (m_data[i] == that.m_data[i]);
                for (size_t j = 0; j < nn ; j++ ) if ( !test[j] ) return false;
          }
          return true;
    //## end CCfits::ColumnVectorData::compare%38BAD52BCDD0.body
  }

  template <typename T>
  ColumnVectorData<T>* ColumnVectorData<T>::clone () const
  {
    //## begin CCfits::ColumnVectorData::clone%38BAD53513B0.body preserve=yes
  return new ColumnVectorData<T>(*this);
    //## end CCfits::ColumnVectorData::clone%38BAD53513B0.body
  }

  template <typename T>
  void ColumnVectorData<T>::resizeDataObject (const std::vector<std::valarray<T> >& indata, size_t firstRow)
  {
    //## begin CCfits::ColumnVectorData::resizeDataObject%3B20DBAA02B8.body preserve=yes
          // the rows() call is the value before updating.
          // the updateRows() call at the end sets the call to return the
          // value from the fits pointer - which is changed by writeFixedArray
          // or writeRow.
          
          const size_t MM(indata.size() + firstRow - 1);
          const size_t newLastRow = std::max(MM,static_cast<size_t>(rows()));
          
          // if the write instruction increases the rows, we need to add
          // rows to the data member and preserve its current contents.
          // if not, we might have to preserve data in cells which may be 
          // only partially overwritten by this call.

          // rows() >= M, of course.
          const size_t M(m_data.size());
          // so this will always be an expansion. vector.resize() doesn't
          // invalidate any data on an expansion.
	  if (newLastRow > M) m_data.resize(newLastRow);
          
          // overlapping data, if any.
          for (size_t k = firstRow - 1; k < MM; ++k)
          {
                  std::valarray<T>& current = m_data[k];    
                  if (current.size() < indata[k - firstRow + 1].size())
                  {
                          // if the column is fixed width, make sure its
                          // width is repeat(), otherwise it's the width
                          // of the input array.
                          std::valarray<T> __tmp(current);
                          size_t n(current.size());
                          size_t validVecSize 
                                = !varLength() ? repeat() : indata[k - firstRow + 1].size();
                          current.resize(validVecSize);
                          std::copy(&__tmp[0],&__tmp[n],&current[0]);
                  }
          }

          // only if input size was smaller.
          for (size_t kk = M; kk < newLastRow; ++kk)
          {
                  size_t validVecSize 
                                = !varLength() ? repeat() : indata[kk - firstRow + 1].size();
                  m_data[kk].resize(validVecSize);       
          }


    //## end CCfits::ColumnVectorData::resizeDataObject%3B20DBAA02B8.body
  }

  template <typename T>
  void ColumnVectorData<T>::setDimen ()
  {
    //## begin CCfits::ColumnVectorData::setDimen%3948FFA702E2.body preserve=yes
  int status(0);
  FITSUtil:: auto_array_ptr<char> dimValue (new char[FLEN_VALUE]);
  
#ifdef SSTREAM_DEFECT
  std::ostrstream key;
#else
  std::ostringstream key;
#endif
  key << "TDIM" << index();

#ifdef SSTREAM_DEFECT
  fits_read_key_str(fitsPointer(), key.str(), dimValue.get(),0,&status);
#else
  char* keyChar = const_cast<char*>(key.str().c_str());
  fits_read_key_str(fitsPointer(),keyChar,dimValue.get(),0,&status);
#endif
  
  if (status == 0)
  {
        dimen(String(dimValue.get()));
  }
    //## end CCfits::ColumnVectorData::setDimen%3948FFA702E2.body
  }

  template <typename T>
  void ColumnVectorData<T>::readColumnData (long first, long last, T* nullValue)
  {
    //## begin CCfits::ColumnVectorData::readColumnData%395A4FD40034.body preserve=yes
  makeHDUCurrent();
   
   
          if ( rows() < last ) 
          {
                std::cerr << "CCfits: More data requested than contained in table. ";
                std::cerr << "Extracting complete column.\n";
                last = rows();
          }

          long nelements = (last - first + 1)*repeat();


          readColumnData(first,nelements,1,nullValue);   
          if (first <= 1 && last == rows()) isRead(true);
    //## end CCfits::ColumnVectorData::readColumnData%395A4FD40034.body
  }

  template <typename T>
  std::ostream& ColumnVectorData<T>::put (std::ostream& s) const
  {
    //## begin CCfits::ColumnVectorData::put%3985C35702F7.body preserve=yes
  // output header information
    Column::put(s);
    if ( FITS::verboseMode() )
    {
          s << " Column Legal limits: ( " << m_minLegalValue << "," << m_maxLegalValue << " )\n" 
          << " Column Data  limits: ( " << m_minDataValue << "," << m_maxDataValue << " )\n";
    }
    if (!m_data.empty())
    {
  	  for (size_t j = 0; j < m_data.size(); j++)
  	  {
                  size_t n = m_data[j].size();
		  if ( n )
        	  {
                          s << "Row " << j + 1 << " Vector Size " << n << '\n';
			  for (size_t k = 0; k < n - 1; k++)
        		  {
               		 	  s << m_data[j][k] << '\t';
        		  }
        		  s << m_data[j][n - 1] << '\n';
		  }
  	  }
    }
    //## end CCfits::ColumnVectorData::put%3985C35702F7.body

    return s;
  }

  template <typename T>
  void ColumnVectorData<T>::writeData (const std::valarray<T>& indata, long numRows, long firstRow, T* nullValue)
  {
    //## begin CCfits::ColumnVectorData::writeData%3A018B000355.body preserve=yes
          
          if (!varLength() && indata.size() < numRows*repeat() )
          {      
#ifdef SSTREAM_DEFECT
                std::ostrstream msgStr;
#else
                std::ostringstream msgStr;
#endif            
                msgStr << "column: " << name() 
                       <<  "\n input data size: " << indata.size() 
                       << " required: " << numRows*repeat();
                String msg(msgStr.str());
                throw InsufficientElements(msg);     
          }
          
          std::vector<std::valarray<T> > internalFormat(numRows);
          
          // support writing equal row lengths to variable columns.
          
          size_t cellsize = repeat();
          // won't do anything if < 0, and will give divide check if == 0.
          if (numRows <= 0) throw InvalidNumberOfRows(numRows);
          
          if (varLength())  cellsize = indata.size()/numRows;

          

          
          for (long j = 0; j < numRows; ++j)
          {
                  internalFormat[j].resize(cellsize);
                  internalFormat[j] = indata[std::slice(cellsize*j,cellsize,1)];
          }
          
          // change the size of m_data based on the first row to be written
          // and on the input data vector sizes.
          
          
          writeData(internalFormat,firstRow,nullValue);    

    //## end CCfits::ColumnVectorData::writeData%3A018B000355.body
  }

  template <typename T>
  void ColumnVectorData<T>::writeData (const std::vector<std::valarray<T> >& indata, long firstRow, T* nullValue)
  {
    //## begin CCfits::ColumnVectorData::writeData%3B003FF302B8.body preserve=yes
   
    // intended to optimize writing if user supplied data already in its internal
    // representation
          
    const size_t N(indata.size());   
    using  std::valarray;
    size_t totalElements(0);
    
    resizeDataObject(indata,firstRow);         
   
    // suppose the user wanted to write non-contiguous data to a vector column...
    // then the write would be short, and must be treated like a varlength array.
    if (!varLength())
    {
            for (size_t j = 0; j < N; ++j) totalElements += indata[j].size();
    }

    if (!varLength() && totalElements >= repeat()*N)
    {
            // concatenate the valarrays and write.
            const size_t M(repeat());         
            size_t nElements (M*N);
            FITSUtil::CVAarray<T> convert;
	    FITSUtil::auto_array_ptr<T> pArray(convert(indata));
            T* array = pArray.get();
            
            // if T is complex, then CVAarray returns a 
            // C-array of complex objects. But FITS requires an array of complex's
            // value_type.
            writeFixedArray(array,nElements,N,firstRow,nullValue);            
            
            // if successful, write the output array (writeFixedArray will throw
            // on errors in input data size and in fits writing).
            
            
            for (size_t j = 0; j < N ; ++j)
            {
                const valarray<T>& input   = indata[j];
                valarray<T>& current = m_data[j + firstRow - 1];
                // current should be resized by resizeDataObject.
                current = input;
            }
                         
                
    }
    else
    {

            // monumental pain in the neck but here goes
            
        
            // loop must be executed exactly N times starting with firstRow,
            // where firstRow >= 1 and row 1 corresponds to array 0.   
            for (size_t j = firstRow - 1; j < N + firstRow - 1; ++j)
            {
                    // each row must be resized, original contents preserved and
                    // data copied. Throw away any requested input that doesn't
                    // fit in a fixed row.
                    valarray<T>& current = m_data[j];
                    const valarray<T>& input   = indata[j - firstRow + 1];                   
                    size_t ic(input.size());
                    size_t tmpSize(std::max(current.size(),ic));
                    valarray<T> __tmp(tmpSize);
                    size_t validVecSize = !varLength() ? repeat()  : tmpSize;
                    current.resize(validVecSize);
                    std::copy(&current[ic],&current[validVecSize],&__tmp[ic]);
                    for (size_t k = 0; k < ic; ++k) __tmp[k] = input[k];
                    writeRow(__tmp,j,1,nullValue);
                    current = __tmp;
            } 
             // this is done by writeFixedArray in the upper block.         
            parent()->updateRows();            
    }
    //## end CCfits::ColumnVectorData::writeData%3B003FF302B8.body
  }

  template <typename T>
  void ColumnVectorData<T>::readRow (size_t row, T* nullValue)
  {
    //## begin CCfits::ColumnVectorData::readRow%3B0A8227012E.body preserve=yes
          makeHDUCurrent();



          if ( row > static_cast<size_t>(rows()) ) 
          {
#ifdef SSTREAM_DEFECT
                  std::ostrstream msg;
#else
                  std::ostringstream msg;
#endif
                msg << " row requested: " << row << " row range: 1 - " << rows();                
#ifdef SSTREAM_DEFECT
                msg << std::ends;
#endif

                throw Column::InvalidRowNumber(msg.str()); 
          }

          // this is really for documentation purposes. I expect the optimizer will
          // remove this redundant definition .
          bool variable(type() < 0); 


          long nelements(repeat());

          if (variable)
          {
              readVariableRow(row,nullValue);
          }
          else
          {      
              readColumnData(row,nelements,1,nullValue);      
          }
    //## end CCfits::ColumnVectorData::readRow%3B0A8227012E.body
  }

  template <typename T>
  void ColumnVectorData<T>::readVariableRow (size_t row, T* nullValue)
  {
    //## begin CCfits::ColumnVectorData::readVariableRow%3B0A91220009.body preserve=yes
      int status(0);
      long offset(0);
      long repeat(0);
      if (fits_read_descript(fitsPointer(),index(),static_cast<long>(row),
                      &repeat,&offset,&status)) throw FitsError(status);
      readColumnData(row,repeat,1,nullValue);   
    //## end CCfits::ColumnVectorData::readVariableRow%3B0A91220009.body
  }

  template <typename T>
  void ColumnVectorData<T>::readColumnData (long firstrow, long nelements, long firstelem, T* nullValue)
  {
    //## begin CCfits::ColumnVectorData::readColumnData%3B0A98EF033F.body preserve=yes
   int   status=0;

   FITSUtil::auto_array_ptr<T> pArray(new T[nelements]); 
   T*     array = pArray.get();
   int    anynul(0);

      

   if (fits_read_col(fitsPointer(), abs(type()),index(), firstrow, firstelem,
                          nelements, nullValue, array, &anynul, &status) != 0)  
       throw FitsError(status);
   
   size_t countRead = 0;
   const size_t ONE = 1;
   
   if (m_data.size() != static_cast<size_t>(rows())) m_data.resize(rows());
   size_t vectorSize(0);
   if (!varLength())
   {
   
        vectorSize = std::max(repeat(),ONE); // safety check.
         
   }
   else
   {
        // assume that the user specified the correct length for 
        // variable columns. This should be ok since readVariableColumns
        // uses fits_read_descripts to return this information from the
        // fits pointer, and this is passed as nelements here.
        vectorSize = nelements;       
   }
   size_t n = nelements; 
   
   int i = firstrow;
   int ii = i - 1;
   while ( countRead < n)
   {
         std::valarray<T>& current = m_data[ii];
         if (current.size() != vectorSize) current.resize(vectorSize);
         int elementsInFirstRow = vectorSize-firstelem + 1;
         bool lastRow = ( (nelements - countRead) < vectorSize);
         if (lastRow)
         {
               int elementsInLastRow = nelements - countRead;
               std::valarray<T> ttmp(array + vectorSize*(ii-firstrow) + elementsInFirstRow,
                                                     elementsInLastRow);
               for (int kk = 0; kk < elementsInLastRow; kk++) current[kk] = ttmp[kk];
               countRead += elementsInLastRow;
             
         }
         // what to do with complete rows
         else 
         {
                if (firstelem == 1 || (firstelem > 1 && i > firstrow) )
                {
                        std::valarray<T> ttmp(array + vectorSize*(ii - firstrow) + 
                                        elementsInFirstRow,vectorSize);
                        current = ttmp;
			ii++;
			i++;
                        countRead += vectorSize;   
                }   
                else
                { 
                        if (i == firstrow)
                        {
                                std::valarray<T> ttmp(array,elementsInFirstRow);
                                for (size_t kk = firstelem ; kk < vectorSize ; kk++)
                                      current[kk] = ttmp[kk-firstelem];   
                                countRead += elementsInFirstRow;
                                i++;
                                ii++;
                        }
                }
         }
    }
    //## end CCfits::ColumnVectorData::readColumnData%3B0A98EF033F.body
  }

  template <typename T>
  void ColumnVectorData<T>::writeData (const std::valarray<T>& indata, const std::vector<long>& vectorLengths, long firstRow, T* nullValue)
  {
    //## begin CCfits::ColumnVectorData::writeData%3B0AAF0401BD.body preserve=yes
    using namespace std;
    const size_t N(vectorLengths.size());
    vector<long> sums(N);
    // pre-calculate partial sums of vector lengths for use as array offsets.
    partial_sum(vectorLengths.begin(),vectorLengths.end(),sums.begin());
    // check that sufficient data have been supplied to carry out the entire operation.
    if (indata.size() < static_cast<size_t>(sums[N-1]) )
    {
#ifdef SSTREAM_DEFECT
        ostrstream msgStr;
#else
        ostringstream msgStr;
#endif            
        msgStr << " input data size: " << indata.size() << " vector length sum: " << sums[N-1];
#ifdef SSTREAM_DEFECT
        msgStr << std::ends;
#endif            

        String msg(msgStr.str());
        throw InsufficientElements(msg);     
    }
          
    vector<valarray<T> > vvArray(N);
    long& last = sums[0];
    for (long jj = 0; jj < last; ++jj) vvArray[0][jj] = indata[jj];

    for (size_t j = 1; j < N; ++j)
    {
               valarray<T>& __tmp = vvArray[j];
               // these  make the code much more readable
               long& first = sums[j-1];
               long& jlast = sums[j];
               __tmp.resize(jlast - first);
               for (long k = first; k < jlast; ++k)
               { 
                        __tmp[k - first] = indata[k];
               }
    }       

    writeData(vvArray,firstRow,nullValue);
    //## end CCfits::ColumnVectorData::writeData%3B0AAF0401BD.body
  }

  template <typename T>
  void ColumnVectorData<T>::writeRow (const std::valarray<T>& data, long row, long firstElem, T* nullValue)
  {
    //## begin CCfits::ColumnVectorData::writeRow%3B0AAFCD0312.body preserve=yes
          
          
    //  The support for
    // writing to any arbitrary individual row makes it possible to use the
    // variable row length versions of writeData to write arbitrary vector lengths 
    // < repeat() to a range of rows - not expected to be a common use, but fairly
    // simple to support. It throws an exception when asked to write more than 
    // will fit on the row, though.
     
    if (nullValue) m_nullValue = *nullValue;      
          
    std::valarray<T>& thisRow = m_data[row];    
    size_t n(data.size());
    long m(thisRow.size());
    
    long rowWidth(n);
    rowWidth += firstElem - 1;
    
    if ( type() > 0) 
    {
        if ( n > repeat() || firstElem  + n - 1 > repeat() )
        { 
#ifdef SSTREAM_DEFECT
                std::ostrstream msgStr;
#else
                std::ostringstream msgStr;
#endif            
                if (n > repeat()) 
                {
                        msgStr << " vector length " << repeat() 
                                        << " input data vector length " << n;
                }
                else
                {
                        msgStr << " requested write " << firstElem << " to " 
                               << firstElem  + n - 1 << " exceeds vector length " << repeat();
                }
                String msg(msgStr.str());
                throw InvalidRowParameter(msg);        
        }
         

    }


    // CANNOT give a strong exception safety guarantee because writing
    // data changes the file. Any corrective action that could be taken
    // [e.g. holding initial contents of the row and writing it back after
    // an exception is thrown] could in principle throw the same exception
    // we are trying to protect from.
    
    // routine does however give the weak guarantee (no resource leaks).    
    

    size_t newRowSize(std::max(m,rowWidth));
    FITSUtil::auto_array_ptr<T> pArray(new T[newRowSize]);
    T* array = pArray.get();
    
    
    // copy existing data to new T array if there is any (the test
    // just protects against an unnecessary function call).
    if (m != 0) std::copy(&thisRow[0],&thisRow[m],&array[0]);
    for (size_t j = 0; j < n; ++j) array[j+firstElem-1] = data[j];

    if (firstElem > 1 && m < firstElem)
    {
        // write sensible value to entries not defined by call.
        // tests mean: there are entries in the array which were not
        // assigned values from the existing data [thisRow] and won't be assigned
        // values from the input data [data]. This isn't the same as the user-supplied
        // "nullValue" that sets to TNULLn or NaN any array points that are equal to nullValue
        FITSUtil::FitsNullValue<T> null;
        T nullVal(null());
        for (long j= 0; j < firstElem - 1; ++j)  array[j] = nullVal;
    }

    doWrite( array, row, newRowSize  );
    
    
    
    // writing to disk was successful. Now update FITS object and return.
    std::valarray<T> __tmp(array,newRowSize);
    if (thisRow.size() != newRowSize) thisRow.resize(newRowSize);
    thisRow = __tmp;
    
    //## end CCfits::ColumnVectorData::writeRow%3B0AAFCD0312.body
  }

  template <typename T>
  void ColumnVectorData<T>::writeFixedArray (T* data, long nElements, long nRows, long firstRow, T* nullValue)
  {
    //## begin CCfits::ColumnVectorData::writeFixedArray%3B0BDA2801BF.body preserve=yes
    int status(0);
    
    // check for sanity of inputs, then write to file.
    // this function writes only complete rows to a table with
    // fixed width rows.
    
    
    if ( nElements < nRows*static_cast<long>(repeat()) )
    {
#ifdef SSTREAM_DEFECT
        std::ostrstream msgStr;
#else
        std::ostringstream msgStr;
#endif
        msgStr << " input array size: " << nElements << " required " << nRows*repeat();
        String msg(msgStr.str());
            
            throw Column::InsufficientElements(msg);
    } 
    
    if (nullValue) m_nullValue = *nullValue;      
    
    if (fits_write_colnull(fitsPointer(),abs(type()),index(),firstRow,
                        1,nElements,data,nullValue,&status)) throw FitsError(status);
    
    parent()->updateRows();
    
    //## end CCfits::ColumnVectorData::writeFixedArray%3B0BDA2801BF.body
  }

  template <typename T>
  void ColumnVectorData<T>::writeData (T* indata, long nElements, long numRows, long firstRow, T* nullValue)
  {
    //## begin CCfits::ColumnVectorData::writeData%3B0D34D1024A.body preserve=yes
          
          if (!varLength()) 
          {
                //
                // writeFixedArray will throw if the writeData inputs are invalid.
                // so, if the call is successful, we can assume that indata is large
                // enough for the following operations.
                writeFixedArray(indata,nElements,numRows,firstRow,nullValue);          

                size_t offset(0);
                size_t newLastRow(std::max(static_cast<long>(rows()),numRows+firstRow-1));
                m_data.resize(newLastRow);
                
                // writing contiguous data in C-array:
                // input data size and row size must be the same.
                for (long j = 0; j < numRows; ++j)
                {
                        std::valarray<T>& current = m_data[firstRow-1];
                        if (current.size() != repeat())  current.resize(repeat());
                        current = std::valarray<T>(indata + offset,repeat());
                        offset +=repeat();
                }

          }          
          else
          {
                // it's possible  that a user might want to write
                // equal lengths of data to columns of variable length row, 
                // so support this here.
                size_t offset(0);
                
                if (numRows <= 0) throw InvalidNumberOfRows(numRows);
                
                size_t vectorLength = nElements/numRows;
                
                for (long j = 0; j < numRows; ++j)
                {
                        writeRow(std::valarray<T>(indata+offset,vectorLength),
                                        j+firstRow-1,1,nullValue);
                        offset += vectorLength;
                }

          }    
          
          parent()->updateRows();

    //## end CCfits::ColumnVectorData::writeData%3B0D34D1024A.body
  }

  template <typename T>
  void ColumnVectorData<T>::insertRows (long first, long number)
  {
    //## begin CCfits::ColumnVectorData::insertRows%3B2138F60241.body preserve=yes
    typename std::vector<std::valarray<T> >::iterator in;
    if (first !=0) 
    {
            in = m_data.begin()+first;
    }
    else
    {
            in = m_data.begin();
    }           
    
    // non-throwing operations.
    m_data.insert(in,number,std::valarray<T>(T(),0));
    //## end CCfits::ColumnVectorData::insertRows%3B2138F60241.body
  }

  template <typename T>
  void ColumnVectorData<T>::deleteRows (long first, long number)
  {
    //## begin CCfits::ColumnVectorData::deleteRows%3B2138FF03A4.body preserve=yes
    // the following is an ugly workaround for a bug in g++ v3.0 that
    // does not erase vector elements cleanly in this case.
          
    size_t N(m_data.size());
    int newSize(N - number);      
    std::vector<std::valarray<T> > __tmp(newSize);
    
    int lastDeleted( number + first - 1 );
    int firstDeleted(first);
    int count(0);
	{
		for ( size_t j = 1; j <= N; ++j)
		{
			if (  (j - firstDeleted)*(lastDeleted - j) >= 0 )	
			{                ++count; 
			} 
			else
			{
                                __tmp[j - 1 - count].resize(m_data[j - 1].size());
                                __tmp[j - 1 - count] = m_data[j - 1];
			}
		}                           
    }
      
    m_data.clear();
    m_data.resize(newSize);
	{
		for (int j = 0; j < newSize; ++j)
		{
			m_data[j].resize(__tmp[j].size());
    		        m_data[j] = __tmp[j];
		}
	}
    //## end CCfits::ColumnVectorData::deleteRows%3B2138FF03A4.body
  }

  template <typename T>
  void ColumnVectorData<T>::setDataLimits (T* limits)
  {
    //## begin CCfits::ColumnVectorData::setDataLimits%3B420063035B.body preserve=yes
    m_minLegalValue = limits[0];
    m_maxLegalValue = limits[1];
    m_minDataValue = std::max(limits[2],limits[0]);
    m_maxDataValue = std::min(limits[3],limits[1]);
    //## end CCfits::ColumnVectorData::setDataLimits%3B420063035B.body
  }

  template <typename T>
  void ColumnVectorData<T>::doWrite (T* array, long row, long rowSize)
  {
    //## begin CCfits::ColumnVectorData::doWrite%3CDFCBD402E6.body preserve=yes
    int status(0);
    // internal functioning of write_colnull forbids its use for writing
    // variable width columns. If a nullvalue argument was supplied it will
    // be ignored.
    if ( !varLength())
    {
        if (fits_write_colnull(fitsPointer(),type(),index(),row,1,rowSize,
                    array,&m_nullValue,&status)) throw FitsError(status);
    }
    else
    {
        if (fits_write_col(fitsPointer(),abs(type()),index(),row,1,rowSize,
                    array,&status)) throw FitsError(status);
            
    }
    //## end CCfits::ColumnVectorData::doWrite%3CDFCBD402E6.body
  }

  // Additional Declarations
    //## begin CCfits::ColumnVectorData%38BAD1B0AA40.declarations preserve=yes
 
  // all functions that operate on complex data that call cfitsio 
  // need to be specialized. The signature containing complex<T>* objects
  // is unfortunate, perhaps, for this purpose, but the user will  access
  // rw operations through standard library containers.
  
  
  
  

#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
template <>
inline void ColumnVectorData<complex<float> >::setDataLimits (complex<float>* limits)
        {
                m_minLegalValue = limits[0];
                m_maxLegalValue = limits[1];
                m_minDataValue =  limits[2];
                m_maxDataValue =  limits[3];
        }
#else
template <>
  void 
  ColumnVectorData<complex<float> >::setDataLimits (complex<float>* limits);
#endif

#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
template <>
inline void ColumnVectorData<complex<double> >::setDataLimits (complex<double>* limits)
        {
                m_minLegalValue = limits[0];
                m_maxLegalValue = limits[1];
                m_minDataValue =  limits[2];
                m_maxDataValue =  limits[3];
        }
#else
 template <>
   void 
   ColumnVectorData<complex<double> >::setDataLimits (complex<double>* limits);
#endif
  
  
#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
        template <>
        inline void ColumnVectorData<std::complex<float> >::readColumnData(long firstRow, 
                                long nelements, long firstElem, std::complex<float>* null )
        {
            int   status=0;
            float nulval (0);
            FITSUtil::auto_array_ptr<float> pArray(new float[2*nelements]); 
            float*     array = pArray.get();
            int    anynul(0);

            if (fits_read_col_cmp(fitsPointer(),index(),firstRow, firstElem,
                            nelements,nulval,array,&anynul,&status) ) throw FitsError(status);

            if (m_data.size() != static_cast<size_t>(rows())) m_data.resize(rows());

            std::valarray<std::complex<float> > readData(nelements);
            for (long j = 0; j < nelements; ++j)
            {
                    readData[j] = std::complex<float>(array[2*j],array[2*j+1]);
            }
            size_t countRead = 0;
            const size_t ONE = 1;

            if (m_data.size() != static_cast<size_t>(rows())) m_data.resize(rows());
            size_t vectorSize(0);
            if (!varLength())
            {
                 vectorSize = std::max(repeat(),ONE); // safety check.
            }
            else
            {
                 // assume that the user specified the correct length for 
                 // variable columns. This should be ok since readVariableColumns
                 // uses fits_read_descripts to return this information from the
                 // fits pointer, and this is passed as nelements here.
                 vectorSize = nelements;       
            }
            size_t n = nelements; 

            int i = firstRow;
            int ii = i - 1;
            while ( countRead < n)
            {
                    std::valarray<complex<float> >& current = m_data[ii];
                    if (current.size() != vectorSize) current.resize(vectorSize,0.);
                    int elementsInFirstRow = vectorSize-firstElem + 1;
                    bool lastRow = ( (nelements - countRead) < vectorSize);
                    if (lastRow)
                    {
                            int elementsInLastRow = nelements - countRead;
                            std::copy(&readData[countRead],&readData[nelements],&current[0]);
                            countRead += elementsInLastRow;
                    }             
                    // what to do with complete rows. if firstElem == 1 the 
                    else 
                    {
                            if (firstElem == 1 || (firstElem > 1 && i > firstRow) )
                            {
                                    current = readData[std::slice(vectorSize*(ii-firstRow)+
                                                               elementsInFirstRow,vectorSize,1)];
			            ++ii;
			            ++i;
                                    countRead += vectorSize;   
                            }   
                            else
                            { 
                                    if (i == firstRow)
                                    {
                                            std::copy(&readData[0],&readData[elementsInFirstRow],
                                                                            &current[firstElem]);
                                            countRead += elementsInFirstRow;
                                            ++i;
                                            ++ii;
                                    }
                            }
                    }
            }
    }
#else
template <>
void ColumnVectorData<complex<float> >::readColumnData(long firstRow, 
                        long nelements, 
                        long firstElem, complex<float>* null);
#endif

#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
    template <>
    inline void ColumnVectorData<complex<double> >::readColumnData (long firstRow, 
              long nelements,long firstElem, 
              complex<double>* nullValue)
    {

        // duplicated for each complex type to work around imagined or
        // actual compiler deficiencies.
            int   status=0;
            double nulval (0);
            FITSUtil::auto_array_ptr<double> pArray(new double[2*nelements]); 
            double*     array = pArray.get();
            int    anynul(0);

            if (fits_read_col_dblcmp(fitsPointer(),index(),firstRow, firstElem,
                            nelements,nulval,array,&anynul,&status) ) throw FitsError(status);

            if (m_data.size() != static_cast<size_t>(rows())) m_data.resize(rows());

            std::valarray<std::complex<double> > readData(nelements);
            for (long j = 0; j < nelements; ++j)
            {
                    readData[j] = std::complex<double>(array[2*j],array[2*j+1]);
            }
            size_t countRead = 0;
            const size_t ONE = 1;

            if (m_data.size() != static_cast<size_t>(rows())) m_data.resize(rows());
            size_t vectorSize(0);
            if (!varLength())
            {
                 vectorSize = std::max(repeat(),ONE); // safety check.
            }
            else
            {
                 // assume that the user specified the correct length for 
                 // variable columns. This should be ok since readVariableColumns
                 // uses fits_read_descripts to return this information from the
                 // fits pointer, and this is passed as nelements here.
                 vectorSize = nelements;       
            }
            size_t n = nelements; 

            int i = firstRow;
            int ii = i - 1;
            while ( countRead < n)
            {
                    std::valarray<std::complex<double> >& current = m_data[ii];
                    if (current.size() != vectorSize) current.resize(vectorSize,0.);
                    int elementsInFirstRow = vectorSize-firstElem + 1;
                    bool lastRow = ( (nelements - countRead) < vectorSize);
                    if (lastRow)
                    {
                            int elementsInLastRow = nelements - countRead;
                            std::copy(&readData[countRead],&readData[nelements],&current[0]);
                            countRead += elementsInLastRow;
                    }             
                    // what to do with complete rows. if firstElem == 1 the 
                    else 
                    {
                            if (firstElem == 1 || (firstElem > 1 && i > firstRow) )
                            {
                                    current = readData[std::slice(vectorSize*(ii-firstRow)+
                                                               elementsInFirstRow,vectorSize,1)];
			            ++ii;
			            ++i;
                                    countRead += vectorSize;   
                            }   
                            else
                            { 
                                    if (i == firstRow)
                                    {
                                            std::copy(&readData[0],&readData[elementsInFirstRow],
                                                                            &current[firstElem]);
                                            countRead += elementsInFirstRow;
                                            ++i;
                                            ++ii;
                                    }
                            }
                    }
            }
    }
#else
template <>
void ColumnVectorData<complex<double> >::readColumnData (long firstRow, 
                        long nelements,
                        long firstElem, complex<double>* null);
#endif

#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
        template <>
        inline void ColumnVectorData<complex<float> >::writeFixedArray 
                        (complex<float>* data, long nElements, long nRows, long firstRow, 
                         complex<float>* nullValue)
        {

                int status(0);
    
    // check for sanity of inputs, then write to file.
    // this function writes only complete rows to a table with
    // fixed width rows.
    
    
                if ( nElements < nRows*static_cast<long>(repeat()) )
                {
#ifdef SSTREAM_DEFECT
                        std::ostrstream msgStr;
#else
                        std::ostringstream msgStr;
#endif
                        msgStr << " input array size: " << nElements 
                                        << " required " << nRows*repeat();
#ifdef SSTREAM_DEFECT
                        msgStr << std::ends;
#endif
                        
                        
                        String msg(msgStr.str());
            
                        throw Column::InsufficientElements(msg);
                } 
                
                FITSUtil::auto_array_ptr<float> realData(new float[2*nElements]);
                
                for (int j = 0; j < nElements; ++j)
                {
                        realData[2*j] = data[j].real();
                        realData[2*j+1] = data[j].imag();       
                }
                
                
    
                if (fits_write_col_cmp(fitsPointer(),index(),firstRow,
                        1,nElements,realData.get(),&status)) throw FitsError(status);
    
                parent()->updateRows();
        }
#else
template <>
void ColumnVectorData<complex<float> >::writeFixedArray 
     (complex<float>* data, long nElements, long nRows, long firstRow, std::complex<float>* null);
#endif

#if SPEC_TEMPLATE_IMP_DEFECT || SPEC_TEMPLATE_DECL_DEFECT
        template <>
        inline void ColumnVectorData<complex<double> >::writeFixedArray 
                        (complex<double>* data, long nElements, long nRows, long firstRow, 
                         complex<double>* nullValue)
        {
                int status(0);
    
    // check for sanity of inputs, then write to file.
    // this function writes only complete rows to a table with
    // fixed width rows.
    
    
                if ( nElements < nRows*static_cast<long>(repeat()) )
                {
#ifdef SSTREAM_DEFECT
                        std::ostrstream msgStr;
#else
                        std::ostringstream msgStr;
#endif
                        msgStr << " input array size: " << nElements 
                                        << " required " << nRows*repeat();
#ifdef SSTREAM_DEFECT
                        msgStr << std::ends;
#endif
                        
                        String msg(msgStr.str());
            
                        throw Column::InsufficientElements(msg);
                } 
                
                FITSUtil::auto_array_ptr<double> realData(new double[2*nElements]);
                
                for (int j = 0; j < nElements; ++j)
                {
                        realData[2*j] = data[j].real();
                        realData[2*j+1] = data[j].imag();       
                }
                
                
    
                if (fits_write_col_dblcmp(fitsPointer(),index(),firstRow,
                        1,nElements,realData.get(),&status)) throw FitsError(status);
    
                parent()->updateRows();

        }
#else
template <>
void ColumnVectorData<complex<double> >::writeFixedArray 
                (complex<double>* data, long nElements, long nRows, long firstRow, 
                 std::complex<double>* null);
#endif

#ifdef SPEC_TEMPLATE_DECL_DEFECT
  template <>
  inline void  
  ColumnVectorData<std::complex<float> >::doWrite 
  (std::complex<float>* data, long row, long rowSize )
  {
    int status(0);
    FITSUtil::auto_array_ptr<float> carray( new float[2*rowSize]); 
    for ( long j = 0 ; j < rowSize; ++ j)
      {
	carray[2*j] = data[j].real();
	carray[2*j + 1] = data[j].imag();
      }
    if (fits_write_col_cmp(fitsPointer(),index(),row,1,rowSize,
			   carray.get(),&status)) throw FitsError(status);
  }


  template <>
  inline void  
  ColumnVectorData<std::complex<double> >::doWrite
  (std::complex<double>* data, long row, long rowSize )
  {
    int status(0);
    FITSUtil::auto_array_ptr<double> carray( new double[2*rowSize]); 
    for ( long j = 0 ; j < rowSize; ++ j)
      {
	carray[2*j] = data[j].real();
	carray[2*j + 1] = data[j].imag();
      }
    if (fits_write_col_dblcmp(fitsPointer(),index(),row,1,rowSize,
			      carray.get(),&status)) throw FitsError(status);

  }

#else
template<>
void 
ColumnVectorData<complex<float> >::doWrite 
                ( complex<float>* data, long row, long rowSize );

template<>
void 
ColumnVectorData<complex<double> >::doWrite 
                ( complex<double>* data, long row, long rowSize );
#endif

    //## end CCfits::ColumnVectorData%38BAD1B0AA40.declarations
} // namespace CCfits

//## begin module%38BAD0CF1E60.epilog preserve=yes
//## end module%38BAD0CF1E60.epilog


#endif
