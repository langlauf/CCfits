//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3804A089FCC8.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%3804A089FCC8.cm

//## begin module%3804A089FCC8.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%3804A089FCC8.cp

//## Module: Table%3804A089FCC8; Package specification
//## Subsystem: CCfits::HDU::Table%3826E0E37A78
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/Table.h

#ifndef TABLE_H
#define TABLE_H 1

//## begin module%3804A089FCC8.additionalIncludes preserve=no
//## end module%3804A089FCC8.additionalIncludes

// ExtHDU
#include "ExtHDU.h"
// FitsError
#include "FitsError.h"

namespace CCfits {
  class Column;

} // namespace CCfits

//## begin module%3804A089FCC8.includes preserve=yes

#ifdef _MSC_VER
#include "MSconfig.h" // for truncation warning
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef SSTREAM_DEFECT
#include <strstream>
#else
#include <sstream>
#endif
//## end module%3804A089FCC8.includes

//## begin module%3804A089FCC8.declarations preserve=no
//## end module%3804A089FCC8.declarations

//## begin module%3804A089FCC8.additionalDeclarations preserve=yes
//## end module%3804A089FCC8.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes

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

  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::Table%3804A0588338.preface preserve=yes
  //## end CCfits::Table%3804A0588338.preface

  //## Class: Table%3804A0588338
  //## Category: CCfits::HDU::Table%3934174000CE
  //## Subsystem: CCfits::HDU::Table%3826E0E37A78
  //## Persistence: Persistent
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%397F439401BF;Column { -> F}
  //## Uses: <unnamed>%39DDEA440302;ColumnCreator { -> }

  class Table : public ExtHDU  //## Inherits: <unnamed>%3804A126EB10
  {
    //## begin CCfits::Table%3804A0588338.initialDeclarations preserve=yes
    //## end CCfits::Table%3804A0588338.initialDeclarations

    public:
      //## Class: NoSuchColumn%397CB04E00FB
      //## Category: CCfits::HDU::Table%3934174000CE
      //## Subsystem: CCfits::HDU::Table%3826E0E37A78
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class NoSuchColumn : public FitsException  //## Inherits: <unnamed>%397CB0970174
      {
        public:
          //## Constructors (specified)
            //## Operation: NoSuchColumn%397CB0CD0015
            NoSuchColumn (const String& name, bool silent = true);

            //## Operation: NoSuchColumn%397CB0F60292
            NoSuchColumn (int index, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Class: InvalidColumnSpecification%3B1E527503B2
      //## Category: CCfits::HDU::Table%3934174000CE
      //## Subsystem: CCfits::HDU::Table%3826E0E37A78
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class InvalidColumnSpecification : public FitsException  //## Inherits: <unnamed>%3B1E52D703B0
      {
        public:
          //## Constructors (specified)
            //## Operation: InvalidColumnSpecification%3B1E52EC03B0
            InvalidColumnSpecification (const String& msg, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Constructors (generated)
        Table(const Table &right);

      //## Destructor (generated)
        virtual ~Table();


      //## Other Operations (specified)
        //## Operation: column%395139580181
        const std::map<String,Column*>& column () const;

        //## Operation: column%397CAE7402E5
        //	! return reference to a column given by column name.
        virtual Column& column (const String& colName) const;

        //## Operation: column%397CAF0E01AB
        virtual Column& column (int colIndex	// ! return reference to a column given by a column index number
        ) const;

        //## Operation: rows%397F35AE0022
        virtual long rows () const;

        //## Operation: updateRows%3AFAB13302EB
        void updateRows ();

        //## Operation: rows%3B04653502FD
        void rows (long numRows);

        //## Operation: deleteColumn%3B0AB97600D2
        virtual void deleteColumn (const String& name);

        //## Operation: insertRows%3B24ECDE013F
        //	Insert one or more blank rows into a FITS column.
        void insertRows (long first, long number = 1);

        //## Operation: deleteRows%3B24ECE30071
        void deleteRows (long first, long number = 1);

        //## Operation: deleteRows%3B24ECE80306
        void deleteRows (const std::vector<long>& rowList);

      //## Get and Set Operations for Associations (generated)

        //## Association: CCfits::<unnamed>%3804EA595B88
        //## Role: Table::column%3804EA597BF0
        //## Qualifier: colname%385E58B84C00; string
        virtual std::map<string, Column*>& column ();

    public:
      // Additional Public Declarations
        //## begin CCfits::Table%3804A0588338.public preserve=yes
        //## end CCfits::Table%3804A0588338.public

    protected:
      //## Constructors (specified)
        //## Operation: Table%3805D315D0D0
        Table (FITSBase* p, HduType xtype, const String &hduName, int rows, 	// ! Number of rows in table at creation, to be used to initialize NAXIS2
        const std::vector<String>& columnName, const std::vector<String>& columnFmt, const std::vector<String>& columnUnit = std::vector<String>(), int version = 1);

        //## Operation: Table%3950DF79004B
        //	To be called by reading operations.
        Table (FITSBase* p, HduType xtype, const String &hduName = String(""), int version = 1);

        //## Operation: Table%395117FC018F
        //	ExtHDU constructor for getting ExtHDUs by number.
        //	Necessary since EXTNAME is a reserved not required
        //	keyword.
        Table (FITSBase* p, HduType xtype, int number);


      //## Other Operations (specified)
        //## Operation: put%385A3E921210
        virtual std::ostream & put (std::ostream &s) const;

        //## Operation: column%387C9CD66838
        void column (int columnNum, Column *value);

        //## Operation: init%395118A40342
        void init (bool readFlag = false, const std::vector<String>& keys = std::vector<String>());

        //## Operation: column%3B042E810363
        virtual void column (const String& colname, Column* value);

        //## Operation: reindex%3B5DA20E0398
        void reindex ();

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: numCols%3805D88D9ED8
        int numCols () const;
        void numCols (int value);

      // Additional Protected Declarations
        //## begin CCfits::Table%3804A0588338.protected preserve=yes
        //## end CCfits::Table%3804A0588338.protected

    private:

      //## Other Operations (specified)
        //## Operation: initRead%3846B8A79D78
        virtual void initRead ();

        //## Operation: readTableHeader%38D7E36F4AB0
        virtual void readTableHeader (int ncols, std::vector<String>& colName, std::vector<String>& colFmt, std::vector<String>& colUnit) = 0;

        //## Operation: clearData%39521D3A00B3
        //	deep erasure , to be called by  assignment and dtors.
        void clearData ();

        //## Operation: copyData%39521E260007
        void copyData (const Table& right);

      // Additional Private Declarations
        //## begin CCfits::Table%3804A0588338.private preserve=yes
        //## end CCfits::Table%3804A0588338.private

    private: //## implementation
      // Data Members for Class Attributes

        //## begin CCfits::Table::numCols%3805D88D9ED8.attr preserve=no  protected: int {U} 0
        int m_numCols;
        //## end CCfits::Table::numCols%3805D88D9ED8.attr

      // Data Members for Associations

        //## Association: CCfits::<unnamed>%3804EA595B88
        //## begin CCfits::Table::column%3804EA597BF0.role preserve=no  public: CCfits::Column {1..n -> 1..nRFHgN}
        std::map<string, Column*> m_column;
        //## end CCfits::Table::column%3804EA597BF0.role

      // Additional Implementation Declarations
        //## begin CCfits::Table%3804A0588338.implementation preserve=yes
        //## end CCfits::Table%3804A0588338.implementation

    //## begin CCfits::Table%3804A0588338.friends preserve=no
      friend class Column;
    //## end CCfits::Table%3804A0588338.friends
  };

  //## begin CCfits::Table%3804A0588338.postscript preserve=yes
  //## end CCfits::Table%3804A0588338.postscript

  // Class CCfits::Table::NoSuchColumn 

  // Class CCfits::Table::InvalidColumnSpecification 

  // Class CCfits::Table 


  //## Other Operations (inline)
  inline const std::map<String,Column*>& Table::column () const
  {
    //## begin CCfits::Table::column%395139580181.body preserve=yes
  return m_column;
    //## end CCfits::Table::column%395139580181.body
  }

  inline long Table::rows () const
  {
    //## begin CCfits::Table::rows%397F35AE0022.body preserve=yes
    //## end CCfits::Table::rows%397F35AE0022.body

    return axis(1);
  }

  inline void Table::rows (long numRows)
  {
    //## begin CCfits::Table::rows%3B04653502FD.body preserve=yes
    //## end CCfits::Table::rows%3B04653502FD.body

    naxes(1) = numRows;
  }

  //## Get and Set Operations for Class Attributes (inline)

  inline int Table::numCols () const
  {
    //## begin CCfits::Table::numCols%3805D88D9ED8.get preserve=no
    return m_numCols;
    //## end CCfits::Table::numCols%3805D88D9ED8.get
  }

  inline void Table::numCols (int value)
  {
    //## begin CCfits::Table::numCols%3805D88D9ED8.set preserve=no
    m_numCols = value;
    //## end CCfits::Table::numCols%3805D88D9ED8.set
  }

  //## Get and Set Operations for Associations (inline)

  inline std::map<string, Column*>& Table::column ()
  {
    //## begin CCfits::Table::column%3804EA597BF0.get preserve=no
    return m_column;
    //## end CCfits::Table::column%3804EA597BF0.get
  }

} // namespace CCfits

//## begin module%3804A089FCC8.epilog preserve=yes
//## end module%3804A089FCC8.epilog


#endif
