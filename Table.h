
//	This is version 1.1 release dated May 2002

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	May 2002 Ben Dorman, L3-Com Analytics Corporation
//	e-mail: ccfits@legacy.gsfc.nasa.gov


#ifndef TABLE_H
#define TABLE_H 1


// ExtHDU
#include "ExtHDU.h"
// FitsError
#include "FitsError.h"

namespace CCfits {
  class Column;

} // namespace CCfits


#ifdef _MSC_VER
#include "MSconfig.h" // for truncation warning
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_STRSTREAM
#include <strstream>
using std::ostrstream;
#else
#include <sstream>
#endif




namespace CCfits {

/*! \class Table

        Table is the abstract common interface to Binary and Ascii Table HDUs. 
        
        Table is a subclass of ExtHDU that contains an associative array of
        Column objects. It implements methods for reading and writing columns
        
         
*/

/*! \class Table::NoSuchColumn

	@ingroup FITSexcept
        @brief  Exception to be thrown on a failure to retrieve a column specified either by name
        or index number. 
        
        When a Table object is created, the header is read and a column object
        created for each column defined. Thus id this exception is thrown
        the column requested does not exist in the HDU (note that the column
        can easily exist and not contain any data since the user controls whether
        the column will be read when the FITS object is instantiated).
        
        It is expected that the index number calls will be primarily internal.
        The underlying implementation makes lookup by name more efficient.
        
        The exception has two variants, which take either an integer or a string
        as parameter. These are used according to the accessor that threw them,
        either by name or index.



*/ 

/*! \fn Table::NoSuchColumn::NoSuchColumn (const string& name, bool silent = true);
        \brief Exception ctor for exception thrown if the requested column (specified by name) is not present
        
        Message: Fits Error: cannot find Column named: <i>name</i> is printed.
                                      
        \param name  the requested column name
        \param silent if true, print message whether FITS::verboseMode is set or not.
*/
                
/*! \fn Table::NoSuchColumn::NoSuchColumn (int index, bool silent = true);
       \brief Exception ctor for exception thrown if the requested column (specified by name) is not present
        
        Message: Fits Error: column not present - Column number <i>index</i> is printed.
                                      
        \param index  the requested column number
        \param silent if true, print message whether FITS::verboseMode is set or not.
*/


/*! \fn void Table::init (bool readFlag = false, const std::vector<string>& keys = std::vector<string>());


    "Late Constructor." wrap-up of calls needed to construct a table. Reads header information
    and sets up the array of column objects in the table. 
    
    Protected function, provided to allow the implementation of extensions of the library.

*/ 

/*! \fn virtual Table::~Table();
    \brief destructor

*/

/*! \fn virtual Table::Table(const Table& right);
    \brief copy constructor

*/


/*!   \fn Column& Table::column (const string& colName) const;

     \brief  return a reference to the column of name colName.
        
        \exceptions Table::NoSuchColumn  passes colName to the diagnostic message 
        printed when the exception is thrown
        
*/
 
 
/*!  \fn    Column& Table::column (int colIndex) const;

        \brief return a reference to the column identified by colIndex
        
        Throws NoSuchColumn if the index
        is out of range -index must satisfy (1 <= index <= numCols() ).
        
        N.B. the column number is assigned as 1-based, as in FORTRAN rather 
        than 0-based as in C.
        
        \exceptions Table::NoSuchColumn  passes colIndex to the diagnostic message 
        printed when the exception is thrown

*/

/*!   \fn void Table::deleteRows (long first, long number=1);

     \brief  delete a range of rows in a table. 
                     
                     
        In both this and the overloaded version which allows a selection of
        rows to be deleted, the cfitsio library is called first to perform the
        operation on the disk file, and then the FITS object is updated. 
                     
                     
        \param first the start row of the range
        \param number the number of rows to delete; defaults to 1.
                     
                     
        
        \exceptions FitsError  thrown if the  cfitsio call fails to return
                     without error.
        
*/

/*!   \fn void Table::deleteRows (const std::vector<long>& rowlist);

     \brief  delete a set of rows in the table specified by an input array.
                     
        \param rowlist The vector of row numbers to be deleted.        
                     
        
        \exceptions FitsError  thrown if the underlying cfitsio call fails to return
                     without error.
        
*/
                     
/*!   \fn void Table::insertRows (long first, long number);

     \brief  insert empty rows into the table
                     
        \param first the start row of the range
        \param number the number of rows to insert.
                     
        
        \exceptions FitsError  thrown if the underlying cfitsio call fails to return
                     without error.
        
*/


/*! \fn      long Table::rows () const;
        
        \brief return the number of rows in the table (NAXIS2).
*/

/*! \fn      void Table::updateRows ();
        
        \brief update the number of rows in the table
                        
        Called to force the Table to reset its internal "rows" attribute.
        public, but is called when needed internally.
*/
                        


/*! \fn   Table::Table (FITSBase* p, HduType xtype, const string &hduName, int rows, 	// ! Number of rows in table at creation, to be used to initialize NAXIS2
        const std::vector<string>& columnName, const std::vector<string>& columnFmt, const std::vector<string>& columnUnit = std::vector<string>(), int version = 0);


        \brief Constructor to be used for creating new HDUs.
        
        \param p        The FITS file in which to place the new HDU
        
        \param rows     The number of rows in the new HDU (the value of the NAXIS2 keyword).
        \param columnType a vector of types for the columns.
        \param columnName a vector of names for the columns.
        \param columnFmt  the format strings for the columns
        \param columnUnit the units for the columns.
        \param version    a version number
*/
        
 
/*! \fn      Table::Table (FITSBase* p, HduType xtype, const string &hduName = string(""), int version = 1);

      	\brief Constructor to be called by operations that read Table specified by hduName and version.

        \param xtype The type of the Table (AsciiTbl or BinaryTbl)
      
*/

/*! \fn      Table::Table (FITSBase* p, HduType xtype, int number);

      \brief Table constructor for getting Tables by number. 
      
      
      Necessary since EXTNAME  is a reserved not required keyword, and users may thus read
      FITS files without an extension name. Since an HDU is completely specified
      by extension number, this is part of the public interface.

*/


/*! \fn   const map<string,Column*>& Table::column () const;

        \brief return a reference to the array containing the columns. 
        
        This public version might be used to query the size of the column container
        in a routine that manipulates column table data.

*/

/*! \fn   map<string,Column*>& Table::column ();

        \brief return a reference to the array containing the columns. 
        
        To be used  in the implementation of subclasses.

*/


/*! \fn      void Table::rows (long value);

        \brief set the number of rows in the Table.
*/

/*! \fn      const int Table::numCols () const;
        
        
        \brief return the number of Columns in the Table (the TFIELDS keyword).
*/
      
/*! \fn      void Table::numCols (int value);

        \brief set the number of Columns in the Table
*/



/*! \fn      void Table::column (const string& colname, Column *value);

        \brief set the column with name colname to the input value.
        
 */







  class Table : public ExtHDU  //## Inherits: <unnamed>%3804A126EB10
  {

    public:



      class NoSuchColumn : public FitsException  //## Inherits: <unnamed>%397CB0970174
      {
        public:
            NoSuchColumn (const string& name, bool silent = true);

            NoSuchColumn (int index, bool silent = true);

        protected:
        private:
        private: //## implementation
      };




      class InvalidColumnSpecification : public FitsException  //## Inherits: <unnamed>%3B1E52D703B0
      {
        public:
            InvalidColumnSpecification (const string& msg, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

        Table(const Table &right);

        virtual ~Table();


        const std::map<string,Column*>& column () const;

        //	! return reference to a column given by column name.
        virtual Column& column (const string& colName) const;

        virtual Column& column (int colIndex	// ! return reference to a column given by a column index number
        ) const;

        virtual long rows () const;

        void updateRows ();

        void rows (long numRows);

        virtual void deleteColumn (const string& name);

        //	Insert one or more blank rows into a FITS column.
        void insertRows (long first, long number = 1);

        void deleteRows (long first, long number = 1);

        void deleteRows (const std::vector<long>& rowList);


        virtual std::map<string, Column*>& column ();

    public:
      // Additional Public Declarations

    protected:
        Table (FITSBase* p, HduType xtype, const string &hduName, int rows, 	// ! Number of rows in table at creation, to be used to initialize NAXIS2
        const std::vector<string>& columnName, const std::vector<string>& columnFmt, const std::vector<string>& columnUnit = std::vector<string>(), int version = 1);

        //	To be called by reading operations.
        Table (FITSBase* p, HduType xtype, const string &hduName = string(""), int version = 1);

        //	ExtHDU constructor for getting ExtHDUs by number.
        //	Necessary since EXTNAME is a reserved not required
        //	keyword.
        Table (FITSBase* p, HduType xtype, int number);


        virtual ostream & put (ostream &s) const;

        void column (int columnNum, Column *value);

        void init (bool readFlag = false, const std::vector<string>& keys = std::vector<string>());

        virtual void column (const string& colname, Column* value);

        void reindex ();


        int numCols () const;
        void numCols (int value);

      // Additional Protected Declarations

    private:

        virtual void initRead ();

        virtual void readTableHeader (int ncols, std::vector<string>& colName, std::vector<string>& colFmt, std::vector<string>& colUnit) = 0;

        //	deep erasure , to be called by  assignment and dtors.
        void clearData ();

        void copyData (const Table& right);

      // Additional Private Declarations

    private: //## implementation
      // Data Members for Class Attributes

        int m_numCols;

      // Data Members for Associations

        std::map<string, Column*> m_column;

      // Additional Implementation Declarations

      friend class Column;
  };


  // Class CCfits::Table::NoSuchColumn 

  // Class CCfits::Table::InvalidColumnSpecification 

  // Class CCfits::Table 


  inline const std::map<string,Column*>& Table::column () const
  {
  return m_column;
  }

  inline long Table::rows () const
  {

    return axis(1);
  }

  inline void Table::rows (long numRows)
  {

    naxes(1) = numRows;
  }


  inline int Table::numCols () const
  {
    return m_numCols;
  }

  inline void Table::numCols (int value)
  {
    m_numCols = value;
  }


  inline std::map<string, Column*>& Table::column ()
  {
    return m_column;
  }

} // namespace CCfits



#endif
