//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3804A6561110.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%3804A6561110.cm

//## begin module%3804A6561110.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%3804A6561110.cp

//## Module: BinTable%3804A6561110; Package specification
//## Subsystem: CCfits::HDU::Table%3826E0E37A78
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/BinTable.h

#ifndef BINTABLE_H
#define BINTABLE_H 1

//## begin module%3804A6561110.additionalIncludes preserve=no
//## end module%3804A6561110.additionalIncludes

// HDUCreator
#include "HDUCreator.h"
// Table
#include "Table.h"
//## begin module%3804A6561110.includes preserve=yes

// needed for CLONE_DEFECT
#ifdef _MSC_VER
#include "MSconfig.h"
#endif
//## end module%3804A6561110.includes

//## begin module%3804A6561110.declarations preserve=no
//## end module%3804A6561110.declarations

//## begin module%3804A6561110.additionalDeclarations preserve=yes
//## end module%3804A6561110.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes

/*!  \class BinTable

     \brief Class Representing Binary Table Extensions. Contains columns with scalar or vector row entries


     BinTable (re)implements functions prescribed in the Table abstract class.
     The implementations allow the calling of cfitsio specialized routines for
     BinTable header construction. functions particular to the BinTable class
     include those dealing with variable width columns
     
     Direct instantiation of BinTable objects is disallowed: they are created
     by explicit calls to FITS::addTable( ... ), FITS::read(...) or internally
     by one of the FITS ctors on initialization. For addTable, creation of 
     BinTables is the default.
          
*/




/*! \fn BinTable::~BinTable();
    \brief destructor.    
*/


/*!  \fn     virtual void BinTable::readData (bool readFlag = false, const std::vector<String>& keys = std::vector<String>());

    \brief read columns and keys specified in the input array.
    
    See Table class documentation for further details.
*/

/*! \fn     BinTable::BinTable (FITSBase* p, const String &hduName, bool readFlag, const std::vector<String>& keys, int version);

    \brief  reading constructor. 
                    
    Construct a BinTable extension from an extension of an existing disk file.
    The Table is specified by name and optional version number within the file.
    An array of strings representing columns or keys indicates which data are to
    be read. The column data are only  read if readFlag is true. Reading on construction
    is optimized, so it is more efficient to read data at the point of instantiation.
    This favours a "resource acquisition is initialization" model of data management.
    
    \param hduName  name of BinTable object to be read.
    \param readFlag flag to determine whether to read data on construction
    \param keys     (optional) a list of keywords/columns to be read. The implementation
                     will determine which are keywords. If none are specified, the 
                     constructor will simply read the  header
    \param version (optional) version number. If not specified, will read the first
                    extension that matches hduName.
*/

/*!  \fn   BinTable::BinTable (FITSBase* p, const String &hduName, int rows,  const std::vector<String>& columnName, const std::vector<String>& columnFmt, const std::vector<String>& columnUnit, int version);

    \brief writing constructor
                    
    The constructor creates a valid HDU which is ready for Column::write or
    insertRows operations. The disk FITS file is update accordingly. The data type
    of each column is determined by the columnFmt argument (TFORM keywords). See
    cfitsio documentation for acceptable values.
        
    \param hduName  name of BinTable object to be written
    \param rows     number of rows in the table (NAXIS2)    
    \param columnName     array of column names for columns to be constructed.
    \param columnFmt      array of column formats for columns to be constructed.
    \param columnUnit     (optional)  array of units for data in columns.
    \param version        (optional) version number for HDU.
    
    The dimensions of columnType, columnName and columnFmt must match, but this
    is not enforced.
    
    
*/

/*!  \fn    BinTable::BinTable (FITSBase* p, int number);

    \brief read BinTable with HDU number \p number from existing file represented by fitsfile pointer p.
*/



  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::BinTable%3804A5C78008.preface preserve=yes
  //## end CCfits::BinTable%3804A5C78008.preface

  //## Class: BinTable%3804A5C78008
  //## Category: CCfits::HDU::Table%3934174000CE
  //## Subsystem: CCfits::HDU::Table%3826E0E37A78
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%39DDEDD5035C;ColumnCreator { -> }
  //## Uses: <unnamed>%3B252DBF0399;Column { -> }

  class BinTable : public Table  //## Inherits: <unnamed>%3804A7E75F10
  {
    //## begin CCfits::BinTable%3804A5C78008.initialDeclarations preserve=yes
    //## end CCfits::BinTable%3804A5C78008.initialDeclarations

    public:

      //## Other Operations (specified)
        //## Operation: clone%381F02F226F0
        virtual BinTable * clone (FITSBase* p) const;

        //## Operation: readData%395107210396
        virtual void readData (bool readFlag = false, const std::vector<String>& keys = std::vector<String>());

        //## Operation: addColumn%3B0BC4460024
        virtual void addColumn (ValueType type, const String& columnName, long repeatWidth, const String& colUnit = String(""), long decimals = 0, size_t columnNumber = 0);

      // Additional Public Declarations
        //## begin CCfits::BinTable%3804A5C78008.public preserve=yes
        //## end CCfits::BinTable%3804A5C78008.public

    protected:
      //## Constructors (specified)
        //## Operation: BinTable%38D651B8DBF8
        BinTable (FITSBase* p, const String &hduName = String(""), bool readFlag = false, const std::vector<String>& keys = std::vector<String>(), int version = 1);

        //## Operation: BinTable%38467DFACEA8
        BinTable (FITSBase* p, const String &hduName, int rows, const std::vector<String>& columnName = std::vector<String>(), const std::vector<String>& columnFmt = std::vector<String>(), const std::vector<String>& columnUnit = std::vector<String>(), int version = 1);

        //## Operation: BinTable%3951184201FD
        //	ExtHDU constructor for getting ExtHDUs by number.
        //	Necessary since EXTNAME is a reserved not required
        //	keyword.
        BinTable (FITSBase* p, int number);

      //## Destructor (generated)
        ~BinTable();

      // Additional Protected Declarations
        //## begin CCfits::BinTable%3804A5C78008.protected preserve=yes
        //## end CCfits::BinTable%3804A5C78008.protected

    private:
      //## Constructors (generated)
        BinTable(const BinTable &right);


      //## Other Operations (specified)
        //## Operation: readTableHeader%38D7E3FB7E28
        virtual void readTableHeader (int ncols, std::vector<String>& colName, std::vector<String>& colFmt, std::vector<String>& colUnit);

        //## Operation: readVariableColumns%395108470150
        void readVariableColumns (const std::vector<String> &varColumns);

      // Additional Private Declarations
        //## begin CCfits::BinTable%3804A5C78008.private preserve=yes
        //## end CCfits::BinTable%3804A5C78008.private

    private: //## implementation
      // Additional Implementation Declarations
        //## begin CCfits::BinTable%3804A5C78008.implementation preserve=yes
      friend class HDUCreator;
        //## end CCfits::BinTable%3804A5C78008.implementation
  };

  //## begin CCfits::BinTable%3804A5C78008.postscript preserve=yes
  //## end CCfits::BinTable%3804A5C78008.postscript

  // Class CCfits::BinTable 

} // namespace CCfits

//## begin module%3804A6561110.epilog preserve=yes
//## end module%3804A6561110.epilog


#endif
