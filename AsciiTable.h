
//	This is version 1.1.1 release dated Sept 2002

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	Sept 2002 Ben Dorman, L3-Communications
//	e-mail: ccfits@legacy.gsfc.nasa.gov


#ifndef ASCIITABLE_H
#define ASCIITABLE_H 1


// HDUCreator
#include "HDUCreator.h"
// Table
#include "Table.h"
// needed for CLONE_DEFECT
#ifdef _MSC_VER
#include "MSconfig.h"
#endif




namespace CCfits {

/*!  \class AsciiTable

     \brief Class Representing Ascii Table Extensions. 
     
     May only contain columns with scalar row entries and a small range of data types.
     AsciiTable (re)implements functions prescribed in the Table abstract class.
     The implementations allow the calling of cfitsio specialized routines for
     AsciiTable header construction. 
     
     Direct instantiation of AsciiTable objects is disallowed: they are created
     by explicit calls to FITS::addTable( ... ), FITS::read(...) or internally
     by one of the FITS ctors on initialization. The default for FITS::addTable
     is to produce BinTable extensions.
     

*/


/*! \fn AsciiTable::~AsciiTable();
    \brief destructor. 
    
*/


/*!  \fn     virtual void AsciiTable::readData (bool readFlag, const std::vector<string>& keys);

    \brief read columns and keys specified in the input array.
    
    See Table class documentation for further details.
*/

/*! \fn     AsciiTable::AsciiTable (FITSBase * p, const string &hduName, bool readFlag, const std::vector<string>& keys, int version);
        
    \brief reading constructor:  Construct a AsciiTable extension from an extension of an existing disk file.
 
    The Table is specified by name and optional version number within the file.
    An array of strings representing columns or keys indicates which data are to
    be read. The column data are only  read if readFlag is true. Reading on construction
    is optimized, so it is more efficient to read data at the point of instantiation.
    This favours a "resource acquisition is initialization" model of data management.
    
    \param hduName  name of AsciiTable object to be read.
    \param readFlag flag to determine whether to read data on construction
    \param keys     (optional) a list of keywords/columns to be read. The implementation
                     will determine which are keywords. If none are specified, the 
                     constructor will simply read the  header
    \param version (optional) version number. If not specified, will read the first
                    extension that matches hduName.
*/

/*!  \fn  AsciiTable::AsciiTable (FITSBase* p, const string &hduName, int rows,  const std::vector<string>& columnName = std::vector<string>(), const std::vector<string>& columnFmt = std::vector<string>(), const std::vector<string>& columnUnit = std::vector<string>(), int version = 1);

    \brief writing constructor: create new Ascii Table object with the specified columns
                    
                    
    The constructor creates a valid HDU which is ready for Column::write or
    insertRows operations. The disk FITS file is update accordingly. The data type
    of each column is determined by the columnFmt argument (TFORM keywords). See
    cfitsio documentation for acceptable values.
    
    \param hduName  name of AsciiTable object to be written
    \param rows     number of rows in the table (NAXIS2)
    \param columnName      array of column names for columns to be constructed.
    \param columnFmt       array of column formats for columns to be constructed.
    \param columnUnit     (optional)  array of units for data in columns.
    \param version        (optional) version number for HDU.
    
    The dimensions of columnType, columnName and columnFmt must match, although
    this is not enforced at present.
    
    \todo{enforce equal dimensions for arrays input to AsciiTable, BinTable writing ctor}
    
    
*/

/*!  \fn    AsciiTable::AsciiTable (FITSBase* p, int number);

    \brief read AsciiTable with HDU number \p number from existing file. 
                    
    This is used internally by methods that need to access HDUs for which no
    EXTNAME [or equivalent] keyword exists.
*/


/*!  \fn   virtual void AsciiTable::readTableHeader (int ncols, std::vector<string>& colName, std::vector<string>& colFmt, std::vector<string>& colUnit);
 
    \brief read the table header. constructor internal call.
*/







  class AsciiTable : public Table  //## Inherits: <unnamed>%3804A75CE420
  {

    public:

        virtual AsciiTable * clone (FITSBase* p) const;

        virtual void readData (bool readFlag = false, const std::vector<string>& keys = std::vector<string>());

        virtual void addColumn (ValueType type, const string& columnName, long repeatWidth, const string& colUnit = string(""), long decimals = -1, size_t  columnNumber = 0);

      // Additional Public Declarations

    protected:
        AsciiTable (FITSBase* p, const string &hduName = string(""), bool readFlag = false, const std::vector<string>& keys = std::vector<string>(), int version = 1);

        AsciiTable (FITSBase* p, const string &hduName, int rows, const std::vector<string>& columnName = std::vector<string>(), const std::vector<string>& columnFmt = std::vector<string>(), const std::vector<string>& columnUnit = std::vector<string>(), int version = 1);

        //	ExtHDU constructor for getting ExtHDUs by number.
        //	Necessary since EXTNAME is a reserved not required
        //	keyword.
        AsciiTable (FITSBase* p, int number);

        ~AsciiTable();

      // Additional Protected Declarations

    private:
        AsciiTable(const AsciiTable &right);


        virtual void readTableHeader (int ncols, std::vector<string>& colName, std::vector<string>& colFmt, std::vector<string>& colUnit);

      // Additional Private Declarations

    private: //## implementation
      // Additional Implementation Declarations
      friend class HDUCreator;
  };


  // Class CCfits::AsciiTable 

} // namespace CCfits



#endif
