//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3804A65BE720.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%3804A65BE720.cm

//## begin module%3804A65BE720.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%3804A65BE720.cp

//## Module: AsciiTable%3804A65BE720; Package specification
//## Subsystem: CCfits::HDU::Table%3826E0E37A78
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/AsciiTable.h

#ifndef ASCIITABLE_H
#define ASCIITABLE_H 1

//## begin module%3804A65BE720.additionalIncludes preserve=no
//## end module%3804A65BE720.additionalIncludes

// HDUCreator
#include "HDUCreator.h"
// Table
#include "Table.h"
//## begin module%3804A65BE720.includes preserve=yes
// needed for CLONE_DEFECT
#ifdef _MSC_VER
#include "MSconfig.h"
#endif
//## end module%3804A65BE720.includes

//## begin module%3804A65BE720.declarations preserve=no
//## end module%3804A65BE720.declarations

//## begin module%3804A65BE720.additionalDeclarations preserve=yes
//## end module%3804A65BE720.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes

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


/*!  \fn     virtual void AsciiTable::readData (bool readFlag, const std::vector<String>& keys);

    \brief read columns and keys specified in the input array.
    
    See Table class documentation for further details.
*/

/*! \fn     AsciiTable::AsciiTable (FITSBase * p, const String &hduName, bool readFlag, const std::vector<String>& keys, int version);
        
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

/*!  \fn  AsciiTable::AsciiTable (FITSBase* p, const String &hduName, int rows,  const std::vector<String>& columnName = std::vector<String>(), const std::vector<String>& columnFmt = std::vector<String>(), const std::vector<String>& columnUnit = std::vector<String>(), int version = 1);

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


/*!  \fn   virtual void AsciiTable::readTableHeader (int ncols, std::vector<String>& colName, std::vector<String>& colFmt, std::vector<String>& colUnit);
 
    \brief read the table header. constructor internal call.
*/

  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::AsciiTable%3804A5CFC420.preface preserve=yes
  //## end CCfits::AsciiTable%3804A5CFC420.preface

  //## Class: AsciiTable%3804A5CFC420; protected
  //## Category: CCfits::HDU::Table%3934174000CE
  //## Subsystem: CCfits::HDU::Table%3826E0E37A78
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%39DDEDE40231;ColumnCreator { -> }
  //## Uses: <unnamed>%3B252DE10026;Column { -> }

  class AsciiTable : public Table  //## Inherits: <unnamed>%3804A75CE420
  {
    //## begin CCfits::AsciiTable%3804A5CFC420.initialDeclarations preserve=yes
    //## end CCfits::AsciiTable%3804A5CFC420.initialDeclarations

    public:

      //## Other Operations (specified)
        //## Operation: clone%381F030480E0
        virtual AsciiTable * clone (FITSBase* p) const;

        //## Operation: readData%395107670360
        virtual void readData (bool readFlag = false, const std::vector<String>& keys = std::vector<String>());

        //## Operation: addColumn%3B0BC43603BD
        virtual void addColumn (ValueType type, const String& columnName, long repeatWidth, const String& colUnit = String(""), long decimals = 0, size_t columnNumber = 0);

      // Additional Public Declarations
        //## begin CCfits::AsciiTable%3804A5CFC420.public preserve=yes
        //## end CCfits::AsciiTable%3804A5CFC420.public

    protected:
      //## Constructors (specified)
        //## Operation: AsciiTable%38D6520E0790
        AsciiTable (FITSBase* p, const String &hduName = String(""), bool readFlag = false, const std::vector<String>& keys = std::vector<String>(), int version = 1);

        //## Operation: AsciiTable%38467E7FB0C0
        AsciiTable (FITSBase* p, const String &hduName, int rows, const std::vector<String>& columnName = std::vector<String>(), const std::vector<String>& columnFmt = std::vector<String>(), const std::vector<String>& columnUnit = std::vector<String>(), int version = 1);

        //## Operation: AsciiTable%395118790186
        //	ExtHDU constructor for getting ExtHDUs by number.
        //	Necessary since EXTNAME is a reserved not required
        //	keyword.
        AsciiTable (FITSBase* p, int number);

      //## Destructor (generated)
        ~AsciiTable();

      // Additional Protected Declarations
        //## begin CCfits::AsciiTable%3804A5CFC420.protected preserve=yes
        //## end CCfits::AsciiTable%3804A5CFC420.protected

    private:
      //## Constructors (generated)
        AsciiTable(const AsciiTable &right);


      //## Other Operations (specified)
        //## Operation: readTableHeader%38D7E4E38DF0
        virtual void readTableHeader (int ncols, std::vector<String>& colName, std::vector<String>& colFmt, std::vector<String>& colUnit);

      // Additional Private Declarations
        //## begin CCfits::AsciiTable%3804A5CFC420.private preserve=yes
        //## end CCfits::AsciiTable%3804A5CFC420.private

    private: //## implementation
      // Additional Implementation Declarations
        //## begin CCfits::AsciiTable%3804A5CFC420.implementation preserve=yes
      friend class HDUCreator;
        //## end CCfits::AsciiTable%3804A5CFC420.implementation
  };

  //## begin CCfits::AsciiTable%3804A5CFC420.postscript preserve=yes
  //## end CCfits::AsciiTable%3804A5CFC420.postscript

  // Class CCfits::AsciiTable 

} // namespace CCfits

//## begin module%3804A65BE720.epilog preserve=yes
//## end module%3804A65BE720.epilog


#endif
