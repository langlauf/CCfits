//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3804E9058790.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%3804E9058790.cm

//## begin module%3804E9058790.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%3804E9058790.cp

//## Module: Column%3804E9058790; Package specification
//## Subsystem: CCfits::Column%3934116D0008
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/Column.h

#ifndef COLUMN_H
#define COLUMN_H 1

//## begin module%3804E9058790.additionalIncludes preserve=no
#include <iostream>
//## end module%3804E9058790.additionalIncludes

// CCfitsHeader
#include "CCfits.h"
// Table
#include "Table.h"
// FitsError
#include "FitsError.h"
// FITSUtil
#include "FITSUtil.h"


//## begin module%3804E9058790.includes preserve=yes
//## end module%3804E9058790.includes

//## begin module%3804E9058790.declarations preserve=no
//## end module%3804E9058790.declarations

//## begin module%3804E9058790.additionalDeclarations preserve=yes
#include <complex>
//## end module%3804E9058790.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes



/*! \class Column

    \brief Abstract base class for Column objects. 
   
   Columns are the data containers used in FITS tables. Columns of scalar type
   (one entry per cell) are implemented by the template subclass ColumnData<T>.
   Columns of vector type (vector and variable rows) are implemented with the 
   template subclass ColumnVectorData<T>. AsciiTables may only contain Columns
   of type ColumnData<T>,  where T is an implemented FITS data type (see the
   CCfits.h header for a complete list. This requirement is enforced by ensuring
   that AsciiTable's addColumn method may only create an AsciiTable compatible
   column. The ColumnData<T> class stores its data in a std::vector<T> object.
   
   
   BinTables may contain either ColumnData<T> or ColumnVectorData<T>. 
   For ColumnVectorData, T must be a numeric type: string vectors are 
   handled by ColumnData<T>; string arrays are not supported. The internal
   representation of the data is a std::vector<std::valarray<T> > object.
   The std::valarray class is designed for efficient numeric processing and
   has many vectorized numeric and transcendental functions defined on it.
   
   Member template functions for read/write operations are provided in multiple
   overloads as the interface to data operations. Implicit data type conversions
   are supported but where they are required make the operations less efficient.
   Reading numeric column data as character arrays, supported by cfitsio, is
   not supported by CCfits.
   
   As a base class, Column provides protected accessor/mutator inline functions to 
   allow only its subclasses to access data members.
  
*/

/*! \class Column::RangeError
    @ingroup FITSexcept
    @brief exception to be thrown for inputs that cause range errors in column read operations.

    Range errors here mean  (last < first) in a request to read a range of rows.
*/



/*! \fn Column::RangeError::RangeError (const String& msg, bool silent);

        \brief Exception ctor, prefixes the string "FitsError: Range error in operation " before the specific message.
                        
        \param msg A specific diagnostic message
        \param silent if true, print message whether FITS::verboseMode is set or not.

*/ 

/*! \class Column::InvalidDataType

        @ingroup FITSExcept
        @brief Exception thrown for invalid data type inputs
        
        This exception is thrown if the user requests an implicit data type conversion
        to a datatype that is not one of the supported types (see fitsio.h for details).
*/

       


/*! \fn Column::InvalidDataType::InvalidDataType (const String& str, bool silent);

        \brief Exception ctor, prefixes the string "FitsError: Incorrect data type:  " before the specific message.
                        
        \param str A specific diagnostic message
        \param silent if true, print message whether FITS::verboseMode is set or not.

*/        


/*! \class Column::InvalidRowParameter

        @ingroup FITSExcept
        @brief Exception thrown on incorrect row writing request
        
        This exception is thrown if the user requests writing more data than a 
        fixed width row can accommodate. An exception is thrown rather than
        a truncation because it is likely that the user will not otherwise
        realize that data loss is happening.
*/


/*! \fn Column::InvalidRowParameter::InvalidRowParameter (const String& diag, bool silent);

        \brief Exception ctor, prefixes the string "FitsError: row offset or length incompatible with column declaration  " before the specific message.
                        
        \param diag A specific diagnostic message, usually the column name
        \param silent if true, print message whether FITS::verboseMode is set or not.

*/        


/*! \class Column::WrongColumnType

        @ingroup FITSExcept
        @brief Exception thrown on attempting to access a scalar column as vector data.
        
        This exception will be thrown if the user tries to call a read/write operation
        with a signature appropriate for a vector column on a scalar column, or vice versa.
        For example in the case of write operations, 
        the vector versions require the specification of (a) a number of rows to write
        over, (b) a vector of lengths to write to each row or (c) a subset specification.
        The scalar versions only require a number of rows if the input array is a plain
        C-array, otherwise the range to be written is the size of the input vector.
       
        

*/

/*! \fn  Column::WrongColumnType::WrongColumnType (const String& diag, bool silent);

        \brief Exception ctor, prefixes the string "FitsError: Attempt to return scalar data from vector column, or vice versa - Column: " before the specific message.
                        
        \param diag A specific diagnostic message, usually the column name.
        \param silent if true, print message whether FITS::verboseMode is set or not.

*/        


/*! \class Column::InvalidRowNumber

        @ingroup FITSExcept
        @brief Exception thrown on attempting to read a row number beyond the end of a table.

*/

/*! \fn Column::InvalidRowNumber::InvalidRowNumber (const String& diag, bool silent);

        \brief Exception ctor, prefixes the string "FitsError: Invalid Row Number - Column: " before the specific message.
                        
        \param diag A specific diagnostic message, usually the column name.
        \param silent if true, print message whether FITS::verboseMode is set or not.

*/        
                        


/*! \class Column::InsufficientElements

        @ingroup FITSExcept
        @brief Exception thrown if the data supplied for a write operation is less than declared.
        
        This circumstance generates an exception to avoid unexpected behaviour after
        the write operation is completed. It  can be avoided by resizing the input
        array appropriately.

*/

/*! \fn Column::InsufficientElements::InsufficientElements (const String& msg, bool silent);

        \brief Exception ctor, prefixes the string "FitsError: not enough elements supplied for write operation:  " before the specific message.
                        
        \param diag A specific diagnostic message, usually the column name
        \param silent if true, print message whether FITS::verboseMode is set or not.

*/        

                        
/*! \class Column::NoNullValue

        @ingroup FITSExcept
        @brief Exception thrown  if a null value is specified without support from existing column header.
        
        This exception is analogous to the fact that cfitsio returns a non-zero status code if
        TNULLn doesn't exist an a null value (convert all input data with the null value to the TNULLn keyword) is
        specified. It is only relevant for integer type data (see cfitsio manual for details).
*/

/*! \fn Column::NoNullValue::NoNullValue (const String& diag, bool silent);

        \brief Exception ctor, prefixes the string "Fits Error: No null value specified for column: " before the specific message.
                        
        \param diag A specific diagnostic message
        \param silent if true, print message whether FITS::verboseMode is set or not.

*/        


/*! \class Column::InvalidNumberOfRows

        @ingroup FITSExcept
        @brief Exception thrown  if user enters a non-positive number for the number of rows to write.
        
*/


/*! \fn Column::InvalidNumberOfRows::InvalidNumberOfRows (size_t number, bool silent);

        \brief Exception ctor, prefixes the string "Fits Error: number of rows to write must be positive " before the specific message.
                        
        \param number The number of rows entered.
        \param silent if true, print message whether FITS::verboseMode is set or not.

*/        

/*!  \fn Column::Column(const Column& right);

      \brief copy constructor, used in copying Columns to standard library containers.
                      
      The copy constructor is for internal use only: it does not affect the disk
      fits file associated with the object.


*/


/*!  \fn virtual Column::~Column();

      \brief destructor.


*/

/*!   \fn  template <typename S> void Column::read(std::vector<S>& vals, long first, long last);
        
        \brief Retrieve data from a scalar column into a std::vector
        
        This and the following functions perform implicit data conversions. An
        exception will be thrown if no conversion exists.
        
        \param vals The output container. The function will resize this as necessary
        \param first,last the span of row numbers to read.
        
*/
  
/*!   \fn  template <typename S> void Column::read(std::vector<S>& vals, long first, long last, S* nullValue) ;
        
        \brief Retrieve data from a scalar column into a std::vector, setting nullvalue
        
        As above, only a pointer to a null value is also recognized. If the column is
        of integer type, then any column value that equals this null value is set equal
        to the value of the TNULLn keyword. An exception is thrown if TNULLn is not
        specified. See cfitsio documentation for further details
        
        \param vals The output container. The function will resize this as necessary
        \param first,last the span of row numbers to read.
        \param nullValue, pointer to integer value regarded as undefined
        
*/
         /*!  \fn   template <typename S> void Column::read(std::valarray<S>& vals, long first, long last) ;

        \brief Retrieve data from a scalar column into a std::valarray
        
        \param vals The output container. The function will resize this as necessary
        \param first,last the span of row numbers to read.


*/    
  
/*!  \fn   template <typename S> void Column::read(std::valarray<S>& vals, long first, long last, S* nullValue) ;

        \brief Retrieve data from a scalar column into a std::valarray, setting undefined values 
        
        \param vals The output container. The function will resize this as necessary
        \param first,last the span of row numbers to read.


*/
                        
/*!  \fn template <typename S> void Column::read(std::valarray<S>& vals, long rows) ;

        \brief return a single row of a vector column into a std::valarray
                        
        \param vals The output valarray object
        \param rows The row number to be retrieved (starting at 1).
*/
                
/*!  \fn  template <typename S> void Column::read(std::valarray<S>& vals, long rows, S* nullValue) ;

        \brief return a single row of a vector column into a std::valarray, setting undefined values

*/
                        
/*!  \fn    template <typename S> void Column::readArrays(std::vector<std::valarray<S> >& vals, long first,long last);

        \brief return a set of rows of a vector column into a vector of valarrays

        \param vals The output container. The function will resize this as necessary
        \param first,last the span of row numbers to read.
*/
        
/*!  \fn  template <typename S>  void Column::readArrays(std::vector<std::valarray<S> >& vals, long first, long last, S* nullValue);
        \brief return a set of rows of a vector column into a container, setting undefined values

        \param vals The output container. The function will resize this as necessary
        \param first,last the span of row numbers to read.

*/  


/*!   \fn  template <typename S> void Column::write(const std::vector<S>& indata, long firstRow);

      \brief write a vector of values into a row starting with firstRow
      
      \param indata   The data to be written.
      \param firstRow The first row to be written
*/  
                       
/*!   \fn  template <typename S> void Column::write(const std::valarray<S>& indata, long firstRow);

      \brief write a valarray of values into a scalar column starting with firstRow
      
      \param indata   The data to be written.
      \param firstRow The first row to be written
*/   
                                                               
 /*!   \fn  template <typename S> void Column::write(const std::vector<S>& indata, long firstRow,  S* nullValue);

      \brief write a vector of values into a row starting with firstRow with undefined values set to nullValue.
      
      \param indata   The data to be written.
      \param firstRow The first row to be written
      \param nullValue Pointer to the value in the input array to be set to undefined values
*/
                       
  
  
                                           
 /*!   \fn  template <typename S> void Column::write(const std::valarray<S>& indata, long firstRow,  S* nullValue);

      \brief write a valarray of values into a scalar column starting with firstRow with undefined values set to nullValue.
      
      \param indata   The data to be written.
      \param firstRow The first row to be written
      \param nullValue Pointer to the value in the input array to be set to undefined values
*/
                       
  
                        


/*!   \fn  template <typename S> void Column::write(S* indata, long nRows, long firstRow);

      \brief write a C array of size nRows into a scalar Column starting with row firstRow.
      
      \param indata   The data to be written.
      \param nRows    The size of the data array to be written
      \param firstRow The first row to be written


*/
         


/*!   \fn  template <typename S> void Column::write(S* indata, long nRows, long firstRow,  S* nullValue);

      \brief write a C array into a scalar Column, processing undefined values.
      
      \param indata   The data to be written.
      \param nRows    The size of the data array to be written
      \param firstRow The first row to be written
      \param nullValue Pointer to the value in the input array to be set to undefined values


*/
  
/*!   \fn   template <typename S>  void Column::write (const std::valarray<S>& indata, long nRows, long firstRow);

        \brief write a valarray of values into a range of rows of a vector column.
                        
        This and the equivalent vector version write a vector of values into nRows. The primary use of this
        is for fixed width columns, in which case Column's repeat attribute is used to determine how many
        elements are written to each row; if indata.size() is too small an exception will be thrown. 
        If the column is variable width, the call will write indata.size()/nRows elements to each row.
 
      \param indata   The data to be written.
      \param nRows    the number of rows to which to write the data.
      \param firstRow The first row to be written
                         
*/
                      

/*!   \fn   template <typename S>  void Column::write (const std::valarray<S>& indata, long nRows, long firstRow, S* nullValue);

        \brief write a valarray of values into a range of rows of a vector column.
                        
        see version without undefined processing for details.
  
*/
   
                        
/*!   \fn   template <typename S>  void Column::write (const std::vector<S>& indata, long nRows, long firstRow);

        \brief write a vector of values into a range of rows of a vector column
                        
        see valarray version for details.

*/
                                           
/*!   \fn   template <typename S>  void Column<S>::write (const std::vector<S>& indata, long nRows, long firstRow, S* nullValue);

        \brief write a vector of values into a range of rows of a vector column, processing undefined values 
                        
         see valarray version for details.

*/
                
/*!   \fn   template <typename S>  void Column::write (S* indata, long nElements, long nRows, long firstRow);

        \brief write a C array of values into a range of rows of a vector column
        
        Details are as for vector input; only difference is the need to supply the size of the C-array. 
                        
      \param indata    The data to be written.
      \param nElements The size of indata
      \param nRows     the number of rows to which to write the data.
      \param firstRow  The first row to be written

*/
                
/*!   \fn   template <typename S> void Column::write (S* indata, long nElements, long nRows, long firstRow, S* nullValue);

        \brief write a C array of values into a range of rows of a vector column, processing undefined values.
 
*/        
                       
/*!   \fn   template <typename S>   void Column::write (const std::valarray<S>& indata,  
                        const std::vector<long>& vectorLengths, 
                        long firstRow);        
                        
        \brief write a valarray of values into a column with specified number of entries written per row.
        
        Data are written into vectorLengths.size() rows, with vectorLength[n] elements written to
        row n+firstRow -1. Although clearly designed for wrapping calls to multiple variable-width
        vector column rows, the code is written to write a variable number of elements to fixed-width
        column rows (cfitsio requires these operations to be done on a row-by-row basis).
                        
        Since cfitsio does not support null value processing for variable width columns
        this function and its variants do not have version which process undefined values
                
        \param indata The data to be written
        \param vectorLengths the number of elements to write to each successive row.
        \param firstRow the first row to be written.        
                
*/
                        
/*!   \fn   template <typename S> void Column::write (const std::vector<S>& indata, 
                        const std::vector<long>& vectorLengths, 
                        long firstRow);
                        
        \brief write a vector of values into a column with specified number of entries written per row.

*/

/*!   \fn   template <typename S>  void Column::write (S* indata, long nElements,  
                        const std::vector<long>& vectorLengths, 
                        long firstRow);
                        
        \brief write a C-array of values of size nElements into a column with specified number of entries written per row.

*/
                
/*!   \fn   template <typename S> void Column::writeArrays (const std::vector<std::valarray<S> >& indata, long firstRow); 

        \brief write a vector of valarray objects to the column, starting at row firstRow >= 1


*/
                        
/*!   \fn   template <typename S>  void Column::writeArrays (const std::vector<std::valarray<S> >& indata, long firstRow, S* nullValue);  

        \brief write a vector of valarray objects to the column, starting at row firstRow >= 1, processing undefined values


*/              
                    

/*! \fn         template <typename T>   void Column::addNullValue(T nullVal);

                \brief Set the TNULLn keyword for the column
                                
                Only relevant for integer valued columns, TNULLn is the value
                used by cfitsio in undefined processing. All entries in the
                table equal to an input "null value" are set equal to the value
                of TNULLn. (For floating point columns a system NaN values is used). 
                        
                
*/

/*!        \fn virtual void Column::readData (long firstRow = 1,  long nelements = 1, long firstElem = 1) = 0;

      \brief read method.
      
      \param firstRow The first row to be read
      \param firstElem the number of the element on the first row to start at 
              (ignored for scalar columns)
      \param nRows The number of rows to read
      

*/



/*!        \fn void Column::setDisplay ();

      \brief set the TDISPn keyword


*/

/*!        \fn void Column::rows() const;

      \brief return the number of rows in the table.

*/


/*!   \fn virtual void Column::setDimen ();

      \brief set the TDIMn keyword.


*/

/*!   \fn std::ostream& operator <<(std::ostream& s, const Column& right);

      \brief output operator for Column objects. 
*/


/*!        \fn int Column::index () const;

      \brief get the Column index (the n in TTYPEn etc).


      
*/


/*!         \fn size_t Column::repeat () const;

      \brief get the repeat count for the rows


       
*/

/*!         \fn const bool Column::varLength () const;

      \brief boolean, set to true if Column has variable length vector rows.


       
*/


/*!        \fn const double Column::scale () const;

      \brief get TSCALn value
      
      TSCALn is  used to convert a data array represented
      on disk in integer format as floating. Useful for compact storage of digitized
      data.

      
*/


/*!        \fn const double Column::zero () const;

      \brief get TZEROn value
      
      TZEROn is an integer offset used in the implementation of unsigned data


      
*/



/*!        \fn const String& Column::name () const;

      \brief  return  name of Column (TTYPEn keyword)


      
*/


/*!        \fn const String& Column::unit () const;

      \brief get units of data in Column (TUNITn keyword)
*/


/*!        \fn Column::Column (int columnIndex, const String &columnName,const ValueType type, 
                const String &format,
                const String &unit,
                Table* p,
                int  rpt = 1, 
                long w = 1, 
                const String &comment = "");
                
      \brief new column creation constructor
      
      This constructor allows the specification of:
      
      \param columnIndex The column number
      \param columnName The column name, keyword TTYPEn
      \param type     used for determining class of T in  ColumnData<T>, ColumnVectorData<T>
      \param format   the column data format, TFORMn keyword
      \param unit   the column data unit, TUNITn keyword
      \param p      the Table pointer
      \param rpt    (optional) repeat count for the row ( == 1 for AsciiTables)
      \param w      the row width
      \param comment comment to be added to the header.

*/

/*!        \fn Column::Column (Table* p = 0);

      \brief Simple constructor to be called by subclass reading ctors.

*/



/*!        \fn fitsfile* Column::fitsPointer ();

      \brief fits pointer corresponding to fits file containing column data.



*/

/*!        \fn void Column::makeHDUCurrent ();

      \brief make HDU containing this the current HDU of the fits file.



*/

/*!        \fn int Column::rows () const;

      \brief return number of rows in the Column
      
 


*/

/*!        \fn virtual std::ostream& Column::put (std::ostream& s) const;

      \brief internal implementation of << operator.



*/

/*!        \fn const ValueType  Column::type () const;

      \brief returns the data type of the column


      
*/


/*!        \fn  const bool Column::isRead () const;

      \brief flag set to true if the entire column data has been read from disk


      
*/


                      
/*!        \fn long Column::width () const;

      \brief return column data width


      
*/      


/*!        \fn String& Column::display () const;

      \brief return TDISPn keyword
      
      TDISPn  is suggested format for output of column data.



*/

/*!        \fn String& Column::dimen () const;

      \brief return TDIMn keyword
      
      represents dimensions of data arrays in vector columns.
      for scalar columns, returns a default value.



*/

/*!        \fn const String& Column::format () const;
 
      \brief return TFORMn keyword

      TFORMn specifies data format stored in disk file.

     
*/


/*!        \fn const String& Column::comment () const;

      \brief retrieve comment for Column


      
*/


  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::Column%3804E8D06FF8.preface preserve=yes
  //## end CCfits::Column%3804E8D06FF8.preface

  //## Class: Column%3804E8D06FF8; protected
  //## Category: CCfits::Column%393417970264
  //## Subsystem: CCfits::Column%3934116D0008
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%394664E50121;friend Table { -> }

  class Column 
  {
    //## begin CCfits::Column%3804E8D06FF8.initialDeclarations preserve=yes
    //## end CCfits::Column%3804E8D06FF8.initialDeclarations

    public:
      //## Class: RangeError%3946508D013B
      //## Category: CCfits::Column%393417970264
      //## Subsystem: CCfits::Column%3934116D0008
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class RangeError : public FitsException  //## Inherits: <unnamed>%3946526D031A
      {
        public:
          //## Constructors (specified)
            //## Operation: RangeError%394651000189
            RangeError (const String& msg, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Class: InvalidDataType%3947CE880080
      //## Category: CCfits::Column%393417970264
      //## Subsystem: CCfits::Column%3934116D0008
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class InvalidDataType : public FitsException  //## Inherits: <unnamed>%3947CF30033E
      {
        public:
          //## Constructors (specified)
            //## Operation: InvalidDataType%3947CF410349
            InvalidDataType (const String& str = string(), bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Class: InvalidRowParameter%39B52EC30097
      //## Category: CCfits::Column%393417970264
      //## Subsystem: CCfits::Column%3934116D0008
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class InvalidRowParameter : public FitsException  //## Inherits: <unnamed>%39B5310F01A0
      {
        public:
          //## Constructors (specified)
            //## Operation: InvalidRowParameter%39B52EE000AF
            InvalidRowParameter (const String& diag, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Class: WrongColumnType%39B544FE0334
      //## Category: CCfits::Column%393417970264
      //## Subsystem: CCfits::Column%3934116D0008
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class WrongColumnType : public FitsException  //## Inherits: <unnamed>%39B545780082
      {
        public:
          //## Constructors (specified)
            //## Operation: WrongColumnType%39B5452302B7
            WrongColumnType (const String& diag, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Class: UnspecifiedLengths%3A018C2C03C0
      //## Category: CCfits::Column%393417970264
      //## Subsystem: CCfits::Column%3934116D0008
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class UnspecifiedLengths : public FitsException  //## Inherits: <unnamed>%3A018C9D007D
      {
        public:
          //## Constructors (specified)
            //## Operation: UnspecifiedLengths%3A018C550303
            UnspecifiedLengths (const String& diag, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Class: InvalidRowNumber%3B0A835403BF
      //## Category: CCfits::Column%393417970264
      //## Subsystem: CCfits::Column%3934116D0008
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class InvalidRowNumber : public FitsException  //## Inherits: <unnamed>%3B0A850F0307
      {
        public:
          //## Constructors (specified)
            //## Operation: InvalidRowNumber%3B0A83990352
            InvalidRowNumber (const String& diag, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Class: InsufficientElements%3B0BE5C000CA
      //## Category: CCfits::Column%393417970264
      //## Subsystem: CCfits::Column%3934116D0008
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class InsufficientElements : public FitsException  //## Inherits: <unnamed>%3B0BE611010A
      {
        public:
          //## Constructors (specified)
            //## Operation: InsufficientElements%3B0BE63102DD
            InsufficientElements (const String& msg, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Class: NoNullValue%3B0D58680220
      //## Category: CCfits::Column%393417970264
      //## Subsystem: CCfits::Column%3934116D0008
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class NoNullValue : public FitsException  //## Inherits: <unnamed>%3B0D589A0092
      {
        public:
          //## Constructors (specified)
            //## Operation: NoNullValue%3B0D58680222
            NoNullValue (const String& diag, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Class: InvalidNumberOfRows%3B20E74C01FF
      //## Category: CCfits::Column%393417970264
      //## Subsystem: CCfits::Column%3934116D0008
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class InvalidNumberOfRows : public FitsException  //## Inherits: <unnamed>%3B20EB8B0205
      {
        public:
          //## Constructors (specified)
            //## Operation: InvalidNumberOfRows%3B20E7690328
            InvalidNumberOfRows (size_t number, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Constructors (generated)
        Column(const Column &right);

      //## Destructor (generated)
        virtual ~Column();

      //## Equality Operations (generated)
        bool operator==(const Column &right) const;

        bool operator!=(const Column &right) const;


      //## Other Operations (specified)
        //## Operation: readData%389F1C05F968
        virtual void readData (long firstRow, long nelements, long firstElem = 1) = 0;

        //## Operation: clone%38973982EF98
        //	Virtual copy constructor.
        virtual Column * clone () const = 0;

        //## Operation: rows%39465C400353
        int rows () const;

        //## Operation: setDisplay%3948FF000114
        void setDisplay ();

        //## Operation: setDimen%3948FF150314
        virtual void setDimen ();

        //## Operation: operator<<%39513B5002D4
        friend std::ostream& operator << (std::ostream& s, const Column& right);

        //## Operation: operator<%3B24D02E0107
        //	Inequality operators for imposing sort order on columns.
        friend bool operator < (const Column& left, const Column& right);

        //## Operation: operator>%3B24D08402F7
        //	Inequality operators for imposing sort order on columns.
        friend bool operator > (const Column& left, const Column& right);

        //## Operation: setLimits%3B41E12B010C
        void setLimits (ValueType type);

        //## Operation: unit%3B545F61014D
        void unit (const String& value);

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: index%385E756F4FE8
        int index () const;
        void index (int value);

        //## Attribute: isRead%387F44AD55B8
        bool isRead () const;
        void isRead (bool value);

        //## Attribute: width%38AC6549D488
        long width () const;
        void width (long value);

        //## Attribute: repeat%38AAF89B2B60
        size_t repeat () const;

        //## Attribute: varLength%38AB18B454A0
        bool varLength () const;

        //## Attribute: scale%3948E3A203B0
        double scale () const;
        void scale (double value);

        //## Attribute: zero%3948E3C5034B
        double zero () const;
        void zero (double value);

        //## Attribute: display%3948FEAF0124
        const String& display () const;

        //## Attribute: dimen%3948FEEE00BF
        const String& dimen () const;
        void dimen (const String& value);

        //## Attribute: type%39EC8D2D030E
        ValueType type () const;
        void type (ValueType value);

        //## Attribute: TFORM%3B41E4C401F8
        static const String& TFORM ();

        //## Attribute: TDISP%3B41E4D4025C
        static const String& TDISP ();

        //## Attribute: TSCAL%3B41E4FE0096
        static const String& TSCAL ();

        //## Attribute: TZERO%3B41E6730238
        static const String& TZERO ();

        //## Attribute: TDIM%3B41E793003F
        static const String& TDIM ();

      //## Get and Set Operations for Associations (generated)

        //## Association: CCfits::Column::<unnamed>%3EEF75E500A5
        //## Role: Column::format%3EEF75E500A6
        const String& format () const;

        //## Association: CCfits::Column::<unnamed>%3EEF75EB025A
        //## Role: Column::unit%3EEF75EB025B
        const String& unit () const;

        //## Association: CCfits::Column::<unnamed>%3EEF75F103BF
        //## Role: Column::name%3EEF75F103C0
        const String& name () const;

    public:
      // Additional Public Declarations
        //## begin CCfits::Column%3804E8D06FF8.public preserve=yes
             
        // scalar column interface. Column's Data Member is a std::vector<T>,
        // input data is std::vector<S>, std::valarray<S> or S* where S is not
        // in general the same as T.
                                
        template <typename S>                   
        void write (const std::vector<S>& indata, long firstRow);

        void write (const std::vector<std::complex<float> >& indata, long firstRow);
        
        void write (const std::vector<std::complex<double> >& indata, long firstRow);

        template <typename S>                   
        void write (const std::valarray<S>& indata, long firstRow);
        
        void write (const std::valarray<std::complex<float> >& indata, long firstRow);

        void write (const std::valarray<std::complex<double> >& indata, long firstRow);

        template <typename S>                   
        void write (S* indata, long nRows, long firstRow);
        
                                
        template <typename S>                   
        void write (const std::vector<S>& indata, long firstRow, S* nullValue);

        template <typename S>                   
        void write (const std::valarray<S>& indata, long firstRow, S* nullValue);

        template <typename S>                   
        void write (S* indata, long nRows, long firstRow, S* nullValue);        
        // vector column interface. We provide an interface that allows input of a vector, valarray and C-array.
	// there are versions that write variable numbers of elements per row as specified
        // in the vectorLengths argument. The user also can directly write a vector<valarray<T> >
        // object which is how the data are stored in the ColumnVectorData object. 
        // this last one is also used internally to implement the variable lengths versions.
        
        // fixed length write to binary table from valarray.
       
                    
        template <typename S>
        void write (const std::valarray<S>& indata, long nRows, long firstRow);

        void write (const std::valarray<std::complex<float> >& indata, long nRows, long firstRow);
        
        void write (const std::valarray<std::complex<double> >& indata, long nRows, long firstRow);

        
        template <typename S>
        void write (const std::vector<S>& indata, long nRows, long firstRow);

        void write (const std::vector<std::complex<float> >& indata, long nRows, long firstRow);
        
        void write (const std::vector<std::complex<double> >& indata, long nRows, long firstRow);
        
        
        
        template <typename S>
        void write (S* indata, long nElements, long nRows, long firstRow);

        
        template <typename S>
        void write (const std::valarray<S>& indata, long nRows, long firstRow, S* nullValue);

        
        template <typename S>
        void write (const std::vector<S>& indata, long nRows, long firstRow, S* nullValue);

        template <typename S>
        void write (S* indata, long nElements, long nRows, long firstRow, S* nullValue);
        
        // variable-length write to vector column from valarray or vector.
        
        template <typename S>
        void write (const std::valarray<S>& indata,  
                        const std::vector<long>& vectorLengths, 
                        long firstRow);        
        
        void write (const std::valarray<std::complex<float> >& indata,  
                        const std::vector<long>& vectorLengths, 
                        long firstRow);        

        void write (const std::valarray<std::complex<double> >& indata,  
                        const std::vector<long>& vectorLengths, 
                        long firstRow);      
          
        template <typename S>
        void write (const std::vector<S>& indata, 
                        const std::vector<long>& vectorLengths, 
                        long firstRow);


        
        void write (const std::vector<std::complex<float> >& indata, 
                        const std::vector<long>& vectorLengths, 
                        long firstRow);
        
        void write (const std::vector<std::complex<double> >& indata, 
                        const std::vector<long>& vectorLengths, 
                        long firstRow);

        template <typename S>
        void write (S* indata, long nElements,  
                        const std::vector<long>& vectorLengths, 
                        long firstRow);
        
        template <typename S>
        void writeArrays (const std::vector<std::valarray<S> >& indata, long firstRow); 

        void writeArrays (const std::vector<std::valarray<std::complex<float> > >& indata, long firstRow); 
        
        void writeArrays (const std::vector<std::valarray<std::complex<double> > >& indata, long firstRow); 
                        
	template <typename S>
        void writeArrays (const std::vector<std::valarray<S> >& indata, long firstRow, S* nullValue);  
              
        // get specified elements of a scalar column, returned as a std::vector
        // S is NOT the type of the column data itself, it is the type of the returned
        // data.
                    
        template <typename S>
        void read(std::vector<S>& vals, long first, long last) ;
        
        // VC++, at least, won't compile these as template covering std::complex instances.
        void read(std::vector< std::complex<float> >& , long first, long last);
        
        void read(std::vector< std::complex<double> >& , long first, long last);
        
        void read(std::vector<String>& vals, long first, long last);
  
        // return a set of rows from a scalar column as a valarray.
        template <typename S>
        void read(std::valarray<S>& vals, long first, long last) ;

        void read(std::valarray<std::complex<float> >& vals, long first, long last) ;
        
        void read(std::valarray<std::complex<double> >& vals, long first, long last) ;
        
        // return a single  row of a vector column.
        template <typename S>
        void read(std::valarray<S>& vals, long rows) ;
        
        void read(std::valarray<std::complex<float> >& vals, long rows) ;
        
        void read(std::valarray<std::complex<double> >& vals, long rows) ;

        // get a set of rows from a vector column.
        template <typename S>
        void readArrays(std::vector<std::valarray<S> >& vals, long first, long last) ;

        void readArrays(std::vector<std::valarray<std::complex<float> > >& vals, long first, long last) ;
        
        void readArrays(std::vector<std::valarray<std::complex<double> > >& vals, long first, long last) ;
        
        // nullValue has no meaning when the target column has floating point/std::complex
        // type. Also, implict conversion of std::complex to pure real is not supported
        // by cfitsio.
        
        template <typename S>
        void read(std::vector<S>& vals, long first, long last, S* nullValue) ;
  
        // return a set of rows from a scalar column as a valarray.
        template <typename S>
        void read(std::valarray<S>& vals, long first, long last, S* nullValue);

        // return a single  row of a vector column.
        template <typename S>
        void read(std::valarray<S>& vals, long rows, S* nullValue) ;
        
        // get a set of rows from a vector column.
        template <typename S>
        void readArrays(std::vector<std::valarray<S> >& vals, long first, long last, S* nullValue);
                
        // add a null value to the column 
        template <typename T>
        void addNullValue(T nullVal);
        
        void write (const std::vector<String>& indata, long firstRow);

        friend void Table::insertRows(long first, long number);
        
        friend void Table::deleteRows(long first, long number);
        
        friend void Table::deleteRows(const std::vector<long>& rowList);
        
        friend void Table::initRead();
        
        friend void Table::reindex();
        //## end CCfits::Column%3804E8D06FF8.public
    protected:
      //## Constructors (specified)
        //## Operation: Column%385E7153FA28
        Column (int columnIndex, 	// The column index, i.e. the integer n in the keyword TCOLn
        const String &columnName, 	// The column name, curiously TTYPEn
        ValueType type, const String &format, 	// The TFORMn keyword.
        const String &unit, 	// The TUNITn keyword
        Table* p, 	// ! The Table containing the Column object
        int rpt = 1, long w = 1, const String &comment = "");

        //## Operation: Column%3937C21F0138
        Column (Table* p = 0);


      //## Other Operations (specified)
        //## Operation: compare%3832D29BD548
        virtual bool compare (const Column &right) const;

        //## Operation: fitsPointer%3937DCD0038C
        fitsfile* fitsPointer ();

        //## Operation: makeHDUCurrent%393FE92F029F
        //	Protected method to set the current HDU to be the one containing this Column object. For use in
        //	public read/write methods to ensure that data regarding numbers of rows and width relate to the
        //	right HDU
        void makeHDUCurrent ();

        //## Operation: put%39513C7401F6
        virtual std::ostream& put (std::ostream& s) const;

        //## Operation: parent%3B0154C00364
        Table* parent () const;

        //## Operation: varLength%3B7188120167
        void varLength (bool value);

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: TBCOL%3B41E45800B2
        static const String& TBCOL ();

        //## Attribute: TTYPE%3B41E4B6013B
        static const String& TTYPE ();

        //## Attribute: TUNIT%3B41E4EC0050
        static const String& TUNIT ();

        //## Attribute: TNULL%3B41E807029A
        static const String& TNULL ();

        //## Attribute: TLMIN%3B41E8300368
        static const String& TLMIN ();

        //## Attribute: TLMAX%3B41E8330127
        static const String& TLMAX ();

        //## Attribute: TDMAX%3B41E86F00AF
        static const String& TDMAX ();

        //## Attribute: TDMIN%3B41E87301A5
        static const String& TDMIN ();

      //## Get and Set Operations for Associations (generated)

        //## Association: CCfits::Column::<unnamed>%397F36A20379
        //## Role: Column::parent%397F36A203BF
        Table* parent ();

        //## Association: CCfits::Column::<unnamed>%3B41E8CC001E
        //## Role: Column::columnKeys%3B41E8CD029C
        static const std::vector<String>& columnKeys ();

        //## Association: CCfits::Column::<unnamed>%3EEF75DE03A1
        //## Role: Column::comment%3EEF75DE03A2
        const String& comment () const;

      // Additional Protected Declarations
        //## begin CCfits::Column%3804E8D06FF8.protected preserve=yes
        //## end CCfits::Column%3804E8D06FF8.protected

    private:
      //## Assignment Operation (generated)
        Column & operator=(const Column &right);


      //## Other Operations (specified)
        //## Operation: insertRows%3B21363D0324
        //	Insert one or more blank rows into a FITS column.
        virtual void insertRows (long first, long number = 1) = 0;

        //## Operation: deleteRows%3B2136D40151
        virtual void deleteRows (long first, long number = 1) = 0;

        //## Operation: loadColumnKeys%3B41EB140398
        static void loadColumnKeys ();

        //## Operation: name%3B545ED20305
        void name (const String& value);

        //## Operation: format%3B545FC8006E
        void format (const String& value);

        //## Operation: numberOfElements%3CDFCA860268
        long numberOfElements (long& first, long& last);

      // Data Members for Class Attributes

        //## begin CCfits::Column::TBCOL%3B41E45800B2.attr preserve=no  protected: static String {VC} "TBCOL"
        static const String s_TBCOL;
        //## end CCfits::Column::TBCOL%3B41E45800B2.attr

        //## begin CCfits::Column::TTYPE%3B41E4B6013B.attr preserve=no  protected: static String {VC} "TTYPE"
        static const String s_TTYPE;
        //## end CCfits::Column::TTYPE%3B41E4B6013B.attr

        //## begin CCfits::Column::TFORM%3B41E4C401F8.attr preserve=no  public: static const String {VC} "TFORM"
        static const String s_TFORM;
        //## end CCfits::Column::TFORM%3B41E4C401F8.attr

        //## begin CCfits::Column::TDISP%3B41E4D4025C.attr preserve=no  public: static String {VC} "TDISP"
        static const String s_TDISP;
        //## end CCfits::Column::TDISP%3B41E4D4025C.attr

        //## begin CCfits::Column::TUNIT%3B41E4EC0050.attr preserve=no  protected: static String {VC} "TUNIT"
        static const String s_TUNIT;
        //## end CCfits::Column::TUNIT%3B41E4EC0050.attr

        //## begin CCfits::Column::TSCAL%3B41E4FE0096.attr preserve=no  public: static String {VC} "TSCAL"
        static const String s_TSCAL;
        //## end CCfits::Column::TSCAL%3B41E4FE0096.attr

        //## begin CCfits::Column::TZERO%3B41E6730238.attr preserve=no  public: static String {VC} "TZERO"
        static const String s_TZERO;
        //## end CCfits::Column::TZERO%3B41E6730238.attr

        //## begin CCfits::Column::TDIM%3B41E793003F.attr preserve=no  public: static String {VC} "TDIM"
        static const String s_TDIM;
        //## end CCfits::Column::TDIM%3B41E793003F.attr

        //## begin CCfits::Column::TNULL%3B41E807029A.attr preserve=no  protected: static String {VC} "TNULL"
        static const String s_TNULL;
        //## end CCfits::Column::TNULL%3B41E807029A.attr

        //## begin CCfits::Column::TLMIN%3B41E8300368.attr preserve=no  protected: static String {VC} "TLMIN"
        static const String s_TLMIN;
        //## end CCfits::Column::TLMIN%3B41E8300368.attr

        //## begin CCfits::Column::TLMAX%3B41E8330127.attr preserve=no  protected: static String {VC} "TLMAX"
        static const String s_TLMAX;
        //## end CCfits::Column::TLMAX%3B41E8330127.attr

        //## begin CCfits::Column::TDMAX%3B41E86F00AF.attr preserve=no  protected: static String {VC} "TDMAX"
        static const String s_TDMAX;
        //## end CCfits::Column::TDMAX%3B41E86F00AF.attr

        //## begin CCfits::Column::TDMIN%3B41E87301A5.attr preserve=no  protected: static String {VC} "TDMIN"
        static const String s_TDMIN;
        //## end CCfits::Column::TDMIN%3B41E87301A5.attr

      // Additional Private Declarations
        //## begin CCfits::Column%3804E8D06FF8.private preserve=yes
        //## end CCfits::Column%3804E8D06FF8.private

    private: //## implementation
      // Data Members for Class Attributes

        //## begin CCfits::Column::index%385E756F4FE8.attr preserve=no  public: int {U} 
        int m_index;
        //## end CCfits::Column::index%385E756F4FE8.attr

        //## begin CCfits::Column::isRead%387F44AD55B8.attr preserve=no  public: bool {U} false
        bool m_isRead;
        //## end CCfits::Column::isRead%387F44AD55B8.attr

        //## begin CCfits::Column::width%38AC6549D488.attr preserve=no  public: long {U} 
        long m_width;
        //## end CCfits::Column::width%38AC6549D488.attr

        //## begin CCfits::Column::repeat%38AAF89B2B60.attr preserve=no  public: size_t {U} 1
        size_t m_repeat;
        //## end CCfits::Column::repeat%38AAF89B2B60.attr

        //## begin CCfits::Column::varLength%38AB18B454A0.attr preserve=no  public: bool {U} false
        bool m_varLength;
        //## end CCfits::Column::varLength%38AB18B454A0.attr

        //## begin CCfits::Column::scale%3948E3A203B0.attr preserve=no  public: double {U} 1.0
        double m_scale;
        //## end CCfits::Column::scale%3948E3A203B0.attr

        //## begin CCfits::Column::zero%3948E3C5034B.attr preserve=no  public: double {U} 1
        double m_zero;
        //## end CCfits::Column::zero%3948E3C5034B.attr

        //## begin CCfits::Column::display%3948FEAF0124.attr preserve=no  public: String {U} ""
        String m_display;
        //## end CCfits::Column::display%3948FEAF0124.attr

        //## begin CCfits::Column::dimen%3948FEEE00BF.attr preserve=no  public: String {U} ""
        String m_dimen;
        //## end CCfits::Column::dimen%3948FEEE00BF.attr

        //## begin CCfits::Column::type%39EC8D2D030E.attr preserve=no  public: ValueType {U} Tnull
        ValueType m_type;
        //## end CCfits::Column::type%39EC8D2D030E.attr

        //## Attribute: LLIMITSHORT%3B41EF3800F8
        //## begin CCfits::Column::LLIMITSHORT%3B41EF3800F8.attr preserve=no  private: static short {VC} SHRT_MIN
        static const short LLIMITSHORT;
        //## end CCfits::Column::LLIMITSHORT%3B41EF3800F8.attr

        //## Attribute: LLIMITLONG%3B41EF710302
        //## begin CCfits::Column::LLIMITLONG%3B41EF710302.attr preserve=no  private: static long {VC} LONG_MIN
        static const long LLIMITLONG;
        //## end CCfits::Column::LLIMITLONG%3B41EF710302.attr

        //## Attribute: LLIMITUSHORT%3B41EF9D0367
        //## begin CCfits::Column::LLIMITUSHORT%3B41EF9D0367.attr preserve=no  private: static unsigned short {VC} 0
        static const unsigned short LLIMITUSHORT;
        //## end CCfits::Column::LLIMITUSHORT%3B41EF9D0367.attr

        //## Attribute: LLIMITULONG%3B41EFC40063
        //## begin CCfits::Column::LLIMITULONG%3B41EFC40063.attr preserve=no  private: static unsigned long {VC} 0
        static const unsigned long LLIMITULONG;
        //## end CCfits::Column::LLIMITULONG%3B41EFC40063.attr

        //## Attribute: LLIMITUCHAR%3B41EFD50177
        //## begin CCfits::Column::LLIMITUCHAR%3B41EFD50177.attr preserve=no  private: static unsigned char {VC} 0
        static const unsigned char LLIMITUCHAR;
        //## end CCfits::Column::LLIMITUCHAR%3B41EFD50177.attr

        //## Attribute: LLIMITFLOAT%3B41EFEA021B
        //## begin CCfits::Column::LLIMITFLOAT%3B41EFEA021B.attr preserve=no  private: static float {VC} FLT_MIN
        static const float LLIMITFLOAT;
        //## end CCfits::Column::LLIMITFLOAT%3B41EFEA021B.attr

        //## Attribute: LLIMITDOUBLE%3B41F003025F
        //## begin CCfits::Column::LLIMITDOUBLE%3B41F003025F.attr preserve=no  private: static double {VC} DBL_MIN
        static const double LLIMITDOUBLE;
        //## end CCfits::Column::LLIMITDOUBLE%3B41F003025F.attr

        //## Attribute: ULIMITSHORT%3B41F02201C1
        //## begin CCfits::Column::ULIMITSHORT%3B41F02201C1.attr preserve=no  private: static short {VC} SHRT_MAX
        static const short ULIMITSHORT;
        //## end CCfits::Column::ULIMITSHORT%3B41F02201C1.attr

        //## Attribute: ULIMITLONG%3B41F0270291
        //## begin CCfits::Column::ULIMITLONG%3B41F0270291.attr preserve=no  private: static long {VC} LONG_MAX
        static const long ULIMITLONG;
        //## end CCfits::Column::ULIMITLONG%3B41F0270291.attr

        //## Attribute: ULIMITUSHORT%3B41F02B032A
        //## begin CCfits::Column::ULIMITUSHORT%3B41F02B032A.attr preserve=no  private: static unsigned short {VC} USHRT_MAX
        static const unsigned short ULIMITUSHORT;
        //## end CCfits::Column::ULIMITUSHORT%3B41F02B032A.attr

        //## Attribute: ULIMITULONG%3B41F02F0325
        //## begin CCfits::Column::ULIMITULONG%3B41F02F0325.attr preserve=no  private: static unsigned long {VC} ULONG_MAX
        static const unsigned long ULIMITULONG;
        //## end CCfits::Column::ULIMITULONG%3B41F02F0325.attr

        //## Attribute: ULIMITUCHAR%3B41F03701B2
        //## begin CCfits::Column::ULIMITUCHAR%3B41F03701B2.attr preserve=no  private: static unsigned char {VC} UCHAR_MAX
        static const unsigned char ULIMITUCHAR;
        //## end CCfits::Column::ULIMITUCHAR%3B41F03701B2.attr

        //## Attribute: ULIMITFLOAT%3B41F03B00F1
        //## begin CCfits::Column::ULIMITFLOAT%3B41F03B00F1.attr preserve=no  private: static float {VC} FLT_MAX
        static const float ULIMITFLOAT;
        //## end CCfits::Column::ULIMITFLOAT%3B41F03B00F1.attr

        //## Attribute: ULIMITDOUBLE%3B41F03F0040
        //## begin CCfits::Column::ULIMITDOUBLE%3B41F03F0040.attr preserve=no  private: static double {VC} DBL_MAX
        static const double ULIMITDOUBLE;
        //## end CCfits::Column::ULIMITDOUBLE%3B41F03F0040.attr

        //## Attribute: LLIMITINT%3B41F0A5018E
        //## begin CCfits::Column::LLIMITINT%3B41F0A5018E.attr preserve=no  private: static int {VC} INT_MIN
        static const int LLIMITINT;
        //## end CCfits::Column::LLIMITINT%3B41F0A5018E.attr

        //## Attribute: ULIMITINT%3B41F0A80334
        //## begin CCfits::Column::ULIMITINT%3B41F0A80334.attr preserve=no  private: static int {VC} INT_MAX
        static const int ULIMITINT;
        //## end CCfits::Column::ULIMITINT%3B41F0A80334.attr

        //## Attribute: LLIMITUINT%3B41F0AC022F
        //## begin CCfits::Column::LLIMITUINT%3B41F0AC022F.attr preserve=no  private: static unsigned int {VC} 0
        static const unsigned int LLIMITUINT;
        //## end CCfits::Column::LLIMITUINT%3B41F0AC022F.attr

        //## Attribute: ULIMITUINT%3B41F0AF028A
        //## begin CCfits::Column::ULIMITUINT%3B41F0AF028A.attr preserve=no  private: static unsigned int {VC} UINT_MAX
        static const unsigned int ULIMITUINT;
        //## end CCfits::Column::ULIMITUINT%3B41F0AF028A.attr

        //## Attribute: LLIMITLONGLONG%4134E15F012E
        //## begin CCfits::Column::LLIMITLONGLONG%4134E15F012E.attr preserve=no  private: static LONGLONG {VC} LONGLONG_MIN
        static const LONGLONG LLIMITLONGLONG;
        //## end CCfits::Column::LLIMITLONGLONG%4134E15F012E.attr

        //## Attribute: ULIMITLONGLONG%4134E1D10336
        //## begin CCfits::Column::ULIMITLONGLONG%4134E1D10336.attr preserve=no  private: static LONGLONG {VC} LONGLONG_MAX
        static const LONGLONG ULIMITLONGLONG;
        //## end CCfits::Column::ULIMITLONGLONG%4134E1D10336.attr

      // Data Members for Associations

        //## Association: CCfits::Column::<unnamed>%397F36A20379
        //## begin CCfits::Column::parent%397F36A203BF.role preserve=no  protected: CCfits::Table { -> 1..1RFHgN}
        Table* m_parent;
        //## end CCfits::Column::parent%397F36A203BF.role

        //## Association: CCfits::Column::<unnamed>%3B41E8CC001E
        //## begin CCfits::Column::columnKeys%3B41E8CD029C.role preserve=no  protected: static CCfits::String {1 -> 1..nVHgN}
        static std::vector<String> s_columnKeys;
        //## end CCfits::Column::columnKeys%3B41E8CD029C.role

        //## Association: CCfits::Column::<unnamed>%3EEF75DE03A1
        //## begin CCfits::Column::comment%3EEF75DE03A2.role preserve=no  protected: CCfits::String { -> 1..1VHgN}
        String m_comment;
        //## end CCfits::Column::comment%3EEF75DE03A2.role

        //## Association: CCfits::Column::<unnamed>%3EEF75E500A5
        //## begin CCfits::Column::format%3EEF75E500A6.role preserve=no  public: CCfits::String { -> 1..1VHgN}
        String m_format;
        //## end CCfits::Column::format%3EEF75E500A6.role

        //## Association: CCfits::Column::<unnamed>%3EEF75EB025A
        //## begin CCfits::Column::unit%3EEF75EB025B.role preserve=no  public: CCfits::String { -> 1..1VHgN}
        String m_unit;
        //## end CCfits::Column::unit%3EEF75EB025B.role

        //## Association: CCfits::Column::<unnamed>%3EEF75F103BF
        //## begin CCfits::Column::name%3EEF75F103C0.role preserve=no  public: CCfits::String { -> 1..1VHgN}
        String m_name;
        //## end CCfits::Column::name%3EEF75F103C0.role

      // Additional Implementation Declarations
        //## begin CCfits::Column%3804E8D06FF8.implementation preserve=yes
        //## end CCfits::Column%3804E8D06FF8.implementation

  };

  //## begin CCfits::Column%3804E8D06FF8.postscript preserve=yes
  //## end CCfits::Column%3804E8D06FF8.postscript

  // Class CCfits::Column::RangeError 

  // Class CCfits::Column::InvalidDataType 

  // Class CCfits::Column::InvalidRowParameter 

  // Class CCfits::Column::WrongColumnType 

  // Class CCfits::Column::UnspecifiedLengths 

  // Class CCfits::Column::InvalidRowNumber 

  // Class CCfits::Column::InsufficientElements 

  // Class CCfits::Column::NoNullValue 

  // Class CCfits::Column::InvalidNumberOfRows 

  // Class CCfits::Column 


  //## Other Operations (inline)
  inline void Column::setDimen ()
  {
    //## begin CCfits::Column::setDimen%3948FF150314.body preserve=yes
  // default implementation: do nothing. Overridden by ColumnVectorData.
    //## end CCfits::Column::setDimen%3948FF150314.body
  }

  inline std::ostream& operator << (std::ostream& s, const Column& right)
  {
    //## begin CCfits::Column::operator<<%39513B5002D4.body preserve=yes
    //## end CCfits::Column::operator<<%39513B5002D4.body

    return right.put(s);
  }

  inline bool operator < (const Column& left, const Column& right)
  {
    //## begin CCfits::Column::operator<%3B24D02E0107.body preserve=yes
    //## end CCfits::Column::operator<%3B24D02E0107.body

    return left.m_index < right.m_index;
  }

  inline bool operator > (const Column& left, const Column& right)
  {
    //## begin CCfits::Column::operator>%3B24D08402F7.body preserve=yes
    //## end CCfits::Column::operator>%3B24D08402F7.body

    return left.m_index > right.m_index;
  }

  //## Get and Set Operations for Class Attributes (inline)

  inline int Column::index () const
  {
    //## begin CCfits::Column::index%385E756F4FE8.get preserve=no
    return m_index;
    //## end CCfits::Column::index%385E756F4FE8.get
  }

  inline void Column::index (int value)
  {
    //## begin CCfits::Column::index%385E756F4FE8.set preserve=no
    m_index = value;
    //## end CCfits::Column::index%385E756F4FE8.set
  }

  inline bool Column::isRead () const
  {
    //## begin CCfits::Column::isRead%387F44AD55B8.get preserve=no
    return m_isRead;
    //## end CCfits::Column::isRead%387F44AD55B8.get
  }

  inline void Column::isRead (bool value)
  {
    //## begin CCfits::Column::isRead%387F44AD55B8.set preserve=no
    m_isRead = value;
    //## end CCfits::Column::isRead%387F44AD55B8.set
  }

  inline long Column::width () const
  {
    //## begin CCfits::Column::width%38AC6549D488.get preserve=no
    return m_width;
    //## end CCfits::Column::width%38AC6549D488.get
  }

  inline void Column::width (long value)
  {
    //## begin CCfits::Column::width%38AC6549D488.set preserve=no
    m_width = value;
    //## end CCfits::Column::width%38AC6549D488.set
  }

  inline size_t Column::repeat () const
  {
    //## begin CCfits::Column::repeat%38AAF89B2B60.get preserve=no
    return m_repeat;
    //## end CCfits::Column::repeat%38AAF89B2B60.get
  }

  inline bool Column::varLength () const
  {
    //## begin CCfits::Column::varLength%38AB18B454A0.get preserve=no
    return m_varLength;
    //## end CCfits::Column::varLength%38AB18B454A0.get
  }

  inline double Column::scale () const
  {
    //## begin CCfits::Column::scale%3948E3A203B0.get preserve=no
    return m_scale;
    //## end CCfits::Column::scale%3948E3A203B0.get
  }

  inline void Column::scale (double value)
  {
    //## begin CCfits::Column::scale%3948E3A203B0.set preserve=yes
    m_scale = value;
    int status(0);
    if (fits_set_tscale(fitsPointer(),m_index,value,m_zero,&status)) throw FitsError(status);
    //## end CCfits::Column::scale%3948E3A203B0.set
  }

  inline double Column::zero () const
  {
    //## begin CCfits::Column::zero%3948E3C5034B.get preserve=no
    return m_zero;
    //## end CCfits::Column::zero%3948E3C5034B.get
  }

  inline void Column::zero (double value)
  {
    //## begin CCfits::Column::zero%3948E3C5034B.set preserve=no
    m_zero = value;
    //## end CCfits::Column::zero%3948E3C5034B.set
  }

  inline const String& Column::display () const
  {
    //## begin CCfits::Column::display%3948FEAF0124.get preserve=no
    return m_display;
    //## end CCfits::Column::display%3948FEAF0124.get
  }

  inline const String& Column::dimen () const
  {
    //## begin CCfits::Column::dimen%3948FEEE00BF.get preserve=no
    return m_dimen;
    //## end CCfits::Column::dimen%3948FEEE00BF.get
  }

  inline void Column::dimen (const String& value)
  {
    //## begin CCfits::Column::dimen%3948FEEE00BF.set preserve=no
    m_dimen = value;
    //## end CCfits::Column::dimen%3948FEEE00BF.set
  }

  inline ValueType Column::type () const
  {
    //## begin CCfits::Column::type%39EC8D2D030E.get preserve=no
    return m_type;
    //## end CCfits::Column::type%39EC8D2D030E.get
  }

  inline void Column::type (ValueType value)
  {
    //## begin CCfits::Column::type%39EC8D2D030E.set preserve=no
    m_type = value;
    //## end CCfits::Column::type%39EC8D2D030E.set
  }

  inline const String& Column::TBCOL ()
  {
    //## begin CCfits::Column::TBCOL%3B41E45800B2.get preserve=no
    return s_TBCOL;
    //## end CCfits::Column::TBCOL%3B41E45800B2.get
  }

  inline const String& Column::TTYPE ()
  {
    //## begin CCfits::Column::TTYPE%3B41E4B6013B.get preserve=no
    return s_TTYPE;
    //## end CCfits::Column::TTYPE%3B41E4B6013B.get
  }

  inline const String& Column::TFORM ()
  {
    //## begin CCfits::Column::TFORM%3B41E4C401F8.get preserve=no
    return s_TFORM;
    //## end CCfits::Column::TFORM%3B41E4C401F8.get
  }

  inline const String& Column::TDISP ()
  {
    //## begin CCfits::Column::TDISP%3B41E4D4025C.get preserve=no
    return s_TDISP;
    //## end CCfits::Column::TDISP%3B41E4D4025C.get
  }

  inline const String& Column::TUNIT ()
  {
    //## begin CCfits::Column::TUNIT%3B41E4EC0050.get preserve=no
    return s_TUNIT;
    //## end CCfits::Column::TUNIT%3B41E4EC0050.get
  }

  inline const String& Column::TSCAL ()
  {
    //## begin CCfits::Column::TSCAL%3B41E4FE0096.get preserve=no
    return s_TSCAL;
    //## end CCfits::Column::TSCAL%3B41E4FE0096.get
  }

  inline const String& Column::TZERO ()
  {
    //## begin CCfits::Column::TZERO%3B41E6730238.get preserve=no
    return s_TZERO;
    //## end CCfits::Column::TZERO%3B41E6730238.get
  }

  inline const String& Column::TDIM ()
  {
    //## begin CCfits::Column::TDIM%3B41E793003F.get preserve=no
    return s_TDIM;
    //## end CCfits::Column::TDIM%3B41E793003F.get
  }

  inline const String& Column::TNULL ()
  {
    //## begin CCfits::Column::TNULL%3B41E807029A.get preserve=no
    return s_TNULL;
    //## end CCfits::Column::TNULL%3B41E807029A.get
  }

  inline const String& Column::TLMIN ()
  {
    //## begin CCfits::Column::TLMIN%3B41E8300368.get preserve=no
    return s_TLMIN;
    //## end CCfits::Column::TLMIN%3B41E8300368.get
  }

  inline const String& Column::TLMAX ()
  {
    //## begin CCfits::Column::TLMAX%3B41E8330127.get preserve=no
    return s_TLMAX;
    //## end CCfits::Column::TLMAX%3B41E8330127.get
  }

  inline const String& Column::TDMAX ()
  {
    //## begin CCfits::Column::TDMAX%3B41E86F00AF.get preserve=no
    return s_TDMAX;
    //## end CCfits::Column::TDMAX%3B41E86F00AF.get
  }

  inline const String& Column::TDMIN ()
  {
    //## begin CCfits::Column::TDMIN%3B41E87301A5.get preserve=no
    return s_TDMIN;
    //## end CCfits::Column::TDMIN%3B41E87301A5.get
  }

  //## Get and Set Operations for Associations (inline)

  inline Table* Column::parent ()
  {
    //## begin CCfits::Column::parent%397F36A203BF.get preserve=no
    return m_parent;
    //## end CCfits::Column::parent%397F36A203BF.get
  }

  inline const std::vector<String>& Column::columnKeys ()
  {
    //## begin CCfits::Column::columnKeys%3B41E8CD029C.get preserve=no
    return s_columnKeys;
    //## end CCfits::Column::columnKeys%3B41E8CD029C.get
  }

  inline const String& Column::comment () const
  {
    //## begin CCfits::Column::comment%3EEF75DE03A2.get preserve=no
    return m_comment;
    //## end CCfits::Column::comment%3EEF75DE03A2.get
  }

  inline const String& Column::format () const
  {
    //## begin CCfits::Column::format%3EEF75E500A6.get preserve=no
    return m_format;
    //## end CCfits::Column::format%3EEF75E500A6.get
  }

  inline const String& Column::unit () const
  {
    //## begin CCfits::Column::unit%3EEF75EB025B.get preserve=no
    return m_unit;
    //## end CCfits::Column::unit%3EEF75EB025B.get
  }

  inline const String& Column::name () const
  {
    //## begin CCfits::Column::name%3EEF75F103C0.get preserve=no
    return m_name;
    //## end CCfits::Column::name%3EEF75F103C0.get
  }

} // namespace CCfits

//## begin module%3804E9058790.epilog preserve=yes
//## end module%3804E9058790.epilog


#endif
