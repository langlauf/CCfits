//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3804A6599288.cm preserve=no
//	This is version 1.3 dated February 2005
//## end module%3804A6599288.cm

//## begin module%3804A6599288.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author:  Ben Dorman, L3-Communications EER Systems Inc.
//## end module%3804A6599288.cp

//## Module: AsciiTable%3804A6599288; Package body
//## Subsystem: CCfits::HDU::Table%3826E0E37A78
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/AsciiTable.cxx

//## begin module%3804A6599288.additionalIncludes preserve=no
//## end module%3804A6599288.additionalIncludes

//## begin module%3804A6599288.includes preserve=yes
#ifdef _MSC_VER
#include "MSconfig.h" // for truncation warning
#endif
//## end module%3804A6599288.includes

// ColumnCreator
#include "ColumnCreator.h"
// Column
#include "Column.h"
// AsciiTable
#include "AsciiTable.h"
//## begin module%3804A6599288.declarations preserve=no
//## end module%3804A6599288.declarations

//## begin module%3804A6599288.additionalDeclarations preserve=yes
#ifdef SSTREAM_DEFECT
#include <strstream>
#else
#include <sstream>
#endif


//## end module%3804A6599288.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  // Class CCfits::AsciiTable 

  AsciiTable::AsciiTable(const AsciiTable &right)
    //## begin AsciiTable::AsciiTable%3804A5CFC420_copy.hasinit preserve=yes
      : Table(right)
    //## end AsciiTable::AsciiTable%3804A5CFC420_copy.hasinit
    //## begin AsciiTable::AsciiTable%3804A5CFC420_copy.initialization preserve=yes
    //## end AsciiTable::AsciiTable%3804A5CFC420_copy.initialization
  {
    //## begin CCfits::AsciiTable::AsciiTable%3804A5CFC420_copy.body preserve=yes
    //## end CCfits::AsciiTable::AsciiTable%3804A5CFC420_copy.body
  }

  AsciiTable::AsciiTable (FITSBase* p, const String &hduName, bool readFlag, const std::vector<String>& keys, int version)
    //## begin CCfits::AsciiTable::AsciiTable%38D6520E0790.hasinit preserve=yes
      : Table(p, AsciiTbl,hduName,version)
    //## end CCfits::AsciiTable::AsciiTable%38D6520E0790.hasinit
    //## begin CCfits::AsciiTable::AsciiTable%38D6520E0790.initialization preserve=yes
    //## end CCfits::AsciiTable::AsciiTable%38D6520E0790.initialization
  {
    //## begin CCfits::AsciiTable::AsciiTable%38D6520E0790.body preserve=yes

  init(readFlag,keys);

    //## end CCfits::AsciiTable::AsciiTable%38D6520E0790.body
  }

  AsciiTable::AsciiTable (FITSBase* p, const String &hduName, int rows, const std::vector<String>& columnName, const std::vector<String>& columnFmt, const std::vector<String>& columnUnit, int version)
    //## begin CCfits::AsciiTable::AsciiTable%38467E7FB0C0.hasinit preserve=yes
      : Table(p, AsciiTbl , hduName,  rows,  columnName, columnFmt, columnUnit,  version)
    //## end CCfits::AsciiTable::AsciiTable%38467E7FB0C0.hasinit
    //## begin CCfits::AsciiTable::AsciiTable%38467E7FB0C0.initialization preserve=yes
    //## end CCfits::AsciiTable::AsciiTable%38467E7FB0C0.initialization
  {
    //## begin CCfits::AsciiTable::AsciiTable%38467E7FB0C0.body preserve=yes
        long           width=0;
        int            decimals=0;
        int            status=0;
        int            colType=0;

        ColumnCreator create(this);
  

        for (int i=0; i< numCols(); i++)
        {

                status = fits_ascii_tform(const_cast<char *>(columnFmt[i].c_str()), 
			       &colType, &width, &decimals, &status);

                if (status != 0)  throw FitsError(status);
                column(columnName[i],create.createColumn(i+1,ValueType(colType),
                        columnName[i], columnFmt[i], columnUnit[i],1,width));
                
                column(columnName[i]).setLimits(ValueType(colType));
                
        }
    //## end CCfits::AsciiTable::AsciiTable%38467E7FB0C0.body
  }

  AsciiTable::AsciiTable (FITSBase* p, int number)
    //## begin CCfits::AsciiTable::AsciiTable%395118790186.hasinit preserve=yes
    : Table(p,AsciiTbl,number)
    //## end CCfits::AsciiTable::AsciiTable%395118790186.hasinit
    //## begin CCfits::AsciiTable::AsciiTable%395118790186.initialization preserve=yes
    //## end CCfits::AsciiTable::AsciiTable%395118790186.initialization
  {
    //## begin CCfits::AsciiTable::AsciiTable%395118790186.body preserve=yes
    
  init();
  
    //## end CCfits::AsciiTable::AsciiTable%395118790186.body
  }


  AsciiTable::~AsciiTable()
  {
    //## begin CCfits::AsciiTable::~AsciiTable%3804A5CFC420_dest.body preserve=yes
    //## end CCfits::AsciiTable::~AsciiTable%3804A5CFC420_dest.body
  }



  //## Other Operations (implementation)
  void AsciiTable::readTableHeader (int ncols, std::vector<String>& colName, std::vector<String>& colFmt, std::vector<String>& colUnit)
  {
    //## begin CCfits::AsciiTable::readTableHeader%38D7E4E38DF0.body preserve=yes
   long  rowlen=0;
   long  *tbcol = new long[ncols];
   int   status=0;
   // hduName has already been set in ExtHDU so it is allocated and
   // read here only because cfitsio requires it.
   char  hduName[FLEN_KEYWORD];

   char** columnName = new char*[ncols];
   char** columnFmt  = new char*[ncols];
   char** columnUnit = new char*[ncols];

   int i = 0; // for MS VC++
   for(; i < ncols; i++)
   {
      columnName[i] = new char[FLEN_KEYWORD];
      columnFmt[i]  = new char[FLEN_KEYWORD];
      columnUnit[i] = new char[FLEN_KEYWORD];
   }

   long nRows = 0;
   int fields = 0;
   status = fits_read_atblhdr(fitsPointer(), ncols, &rowlen, &nRows, &fields,
			      columnName, tbcol, columnFmt, columnUnit,
			      hduName, &status);
   
   rows(nRows);
   numCols(fields);
   
   for( i = 0; i < ncols; i++)
   {
      colName[i] = String(columnName[i]);
      colFmt[i]  = String(columnFmt[i]);
      colUnit[i] = String(columnUnit[i]);
      delete [] columnName[i];
      delete [] columnFmt[i];
      delete [] columnUnit[i];
   }

   delete [] columnName;
   delete [] columnFmt;
   delete [] columnUnit;

   if (status != 0)  throw FitsError(status);

   delete [] tbcol;
    //## end CCfits::AsciiTable::readTableHeader%38D7E4E38DF0.body
  }

  AsciiTable * AsciiTable::clone (FITSBase* p) const
  {
    //## begin CCfits::AsciiTable::clone%381F030480E0.body preserve=yes
  AsciiTable* cloned = new AsciiTable(*this);
  cloned->parent() = p;
  return cloned;
    //## end CCfits::AsciiTable::clone%381F030480E0.body
  }

  void AsciiTable::readData (bool readFlag, const std::vector<String>& keys)
  {
    //## begin CCfits::AsciiTable::readData%395107670360.body preserve=yes
   int             rowsRead=0;
   int status = 0;
   long rowSize = 0;
   
   // grab the optimal rowsize using the get_rowsize call. It just
   // might have changed since the Table HDU was constructed so it should
   // be set just before reading takes place.

      if (fits_get_rowsize(fitsPointer(), &rowSize, &status))  throw FitsError(status);

   size_t keysRead = 0;
   size_t nkey=keys.size();
   std::map<String,Column*>::iterator endColumn = column().end();
  // if a set of strings were supplied, interpret these as
   // keywords and columns to be read.
   // get a container for keys which correspond to columns.
   std::vector<String> colKeys;
   colKeys.reserve(nkey);
   
   if (nkey > 0)
   {
        for (keysRead = 0; keysRead < nkey; keysRead++)
        {
                try
                {
                        // after the read function is called by the ctor,
                        // the columns in the table have been indexed.
                        // check that the key in question is not a column
                        // name. 
                        if (column().find(keys[keysRead]) == endColumn)   readKeyword(keys[keysRead]);
                        else colKeys.push_back(keys[keysRead]);
                }
                catch (HDU::NoSuchKeyword)
                {
                        continue;
                }
                catch (...)
                {
                        throw;
                }
        } 
   }  
   
   // if readFlag is false, don't get any data. 
   
   if (!readFlag) return;      
       
   // the data consist of scalars in each row. For an ASCII table,
   // rowSize is probably quite big because there's just one element per row.
   for (rowsRead=0; rowsRead< rows() ; rowsRead+=rowSize)
   {     
        std::map<String,Column*>::iterator col;
        if (colKeys.size() > 0)
        {
                for (size_t i=0; i < colKeys.size() ; i++)
                {
                        // if a set of keys was entered, read the data in the ones
                        // that correspond to columns, as checked earlier
                        col = column().find(colKeys[i]); 
                        Column&  current = *((*col).second);
                        current.readData(rowsRead+1,
                                        current.repeat()*std::min<size_t>(rowSize,rows()-rowsRead),1);
                }
        }
        else
        {
                // if no keys that correspond to column names were supplied, read all the data.
	        for(col = column().begin(); col != column().end(); col++ )
                {      
                        Column& current = *((*col).second);
                        current.readData(rowsRead+1,
                                          current.repeat()*std::min<size_t>(rowSize,rows() - rowsRead),1);
      
                }
         }
   }
   
   if (colKeys.size() ==  0)
   {
        // mark all columns read
        for (std::map<String,Column*>::iterator col = column().begin(); 
                        col != column().end(); ++col) 
        {
                (*col).second->isRead(true);
        }
   }
   else
   {
        for (size_t i=0; i < colKeys.size() ; i++)
        {
                // if a set of keys was entered, read the data in the ones
                // that correspond to columns, as checked earlier
                std::map<String,Column*>::iterator col = column().find(colKeys[i]); 
                (*col).second->isRead(true);
        }
               
   }
    //## end CCfits::AsciiTable::readData%395107670360.body
  }

  void AsciiTable::addColumn (ValueType type, const String& columnName, long repeatWidth, const String& colUnit, long decimals, size_t columnNumber)
  {
    //## begin CCfits::AsciiTable::addColumn%3B0BC43603BD.body preserve=yes
    String diag("");   
    
    // repeatWidth has the following semantics:
    
    // for non-string represents the multiplicity of entries in the column cell, and
    // is therefore always 1 for numeric datatypes.
    // for strings it represents the string width.
    // In cfitsio, the information about datatypes is carried in the width field,
    // but here this is carried by the type value.
    
    if (type < 0 ) 
    {
        diag += " writing vector-valued column to ASCII table: ";
        diag += name(); // name of ascii table extension 
        throw InvalidColumnSpecification(diag);      
    }    
    if (Tstring && repeatWidth < 1)
    {   
            diag += " length of string values unspecified for Column:  ";
            diag += columnName;
        throw InvalidColumnSpecification(diag);      
                
    }  
    if ( ( type == Tfloat || type == Tdouble ) )
    {
        if ( decimals < 0 || decimals > repeatWidth )
        {    
                diag += " invalid specification for floating point data format in Column  " ;
                diag += columnName;
                throw InvalidColumnSpecification(diag); 
        }    
           
    }
#ifdef SSTREAM_DEFECT
                std::ostrstream tformStr;
#else
                std::ostringstream tformStr;          
#endif
    
    

    switch (type)
    {
                case Tstring:
                        tformStr << 'A' << repeatWidth; 
                        break;
                case Tshort:
                case Tint:
                        tformStr << 'I' << 6;
                        break;
                case Tlong:
                        tformStr << 'I' << 12; 
                        break;
                case Tfloat:
                        if (repeatWidth <= 7)
                        {
                                tformStr << 'E' << repeatWidth << '.' << decimals;
                        }
                        else
                        {
                                tformStr << 'D' << repeatWidth << '.' << decimals;
                        }
                        break;
                case Tdouble:
                        tformStr << 'D' << repeatWidth << '.' << decimals;
                        break;                    
                default:
                        diag += "Invalid data type for ASCII table ";
                        diag += name();
                        throw WrongExtensionType(diag);
    }
# ifdef SSTREAM_DEFECT
        tformStr << std::ends;  
# endif
    makeThisCurrent();   
    // the user is allowed to specify which column number to create although
    // this is frowned down upon because the user shouldn't care how the data
    // are written internally.
     
    int colNum(0);
    int status(0);
    if ( columnNumber == 0)
    {

            if (fits_get_num_cols(fitsPointer(),&colNum,&status)) throw FitsError(status);
            colNum +=1;
    }
    else colNum = columnNumber;

    //string ColumnName(FITSUtil::upperCase(columnName));
    
    String tfString(tformStr.str());
    char* tform = const_cast<char*>(tfString.c_str());    

    
    char* ttype = const_cast<char*>(columnName.c_str());
    
    if (fits_insert_col(fitsPointer(),colNum,ttype,tform,&status)) throw FitsError(status);
    
    if (colUnit.size()) 
    {           
                std::ostringstream ustream;
                char unitComment[] = "";
                ustream << "TUNIT" << colNum;
                if (fits_write_key (fitsPointer(), Tstring,
                           const_cast<char*>(ustream.str().c_str()),
                           const_cast<char*>(colUnit.c_str()), 
                           unitComment, &status))
                {
                           throw FitsError (status);
                }

    }
    
    ColumnCreator create(this);
    column(columnName,create.createColumn(colNum,type,columnName,tfString,
                      colUnit,1,repeatWidth));
    if (type != Tstring) column(columnName).setLimits(type);
    
    
    if (columnNumber != 0) reindex();
    //## end CCfits::AsciiTable::addColumn%3B0BC43603BD.body
  }

  // Additional Declarations
    //## begin CCfits::AsciiTable%3804A5CFC420.declarations preserve=yes
    //## end CCfits::AsciiTable%3804A5CFC420.declarations

} // namespace CCfits

//## begin module%3804A6599288.epilog preserve=yes
//## end module%3804A6599288.epilog
