//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3804A653F4B0.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%3804A653F4B0.cm

//## begin module%3804A653F4B0.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%3804A653F4B0.cp

//## Module: BinTable%3804A653F4B0; Package body
//## Subsystem: CCfits::HDU::Table%3826E0E37A78
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/BinTable.cxx

//## begin module%3804A653F4B0.additionalIncludes preserve=no
//## end module%3804A653F4B0.additionalIncludes

//## begin module%3804A653F4B0.includes preserve=yes
//## end module%3804A653F4B0.includes

// ColumnCreator
#include "ColumnCreator.h"
// Column
#include "Column.h"
// BinTable
#include "BinTable.h"
//## begin module%3804A653F4B0.declarations preserve=no
//## end module%3804A653F4B0.declarations

//## begin module%3804A653F4B0.additionalDeclarations preserve=yes
#ifdef SSTREAM_DEFECT
#include <strstream>
#else
#include <sstream>
#endif

//## end module%3804A653F4B0.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  // Class CCfits::BinTable 

  BinTable::BinTable(const BinTable &right)
    //## begin BinTable::BinTable%3804A5C78008_copy.hasinit preserve=yes
      : Table(right)
    //## end BinTable::BinTable%3804A5C78008_copy.hasinit
    //## begin BinTable::BinTable%3804A5C78008_copy.initialization preserve=yes
    //## end BinTable::BinTable%3804A5C78008_copy.initialization
  {
    //## begin CCfits::BinTable::BinTable%3804A5C78008_copy.body preserve=yes
    //## end CCfits::BinTable::BinTable%3804A5C78008_copy.body
  }

  BinTable::BinTable (FITSBase* p, const String &hduName, bool readFlag, const std::vector<String>& keys, int version)
    //## begin CCfits::BinTable::BinTable%38D651B8DBF8.hasinit preserve=yes
      : Table(p, BinaryTbl, hduName, version)
    //## end CCfits::BinTable::BinTable%38D651B8DBF8.hasinit
    //## begin CCfits::BinTable::BinTable%38D651B8DBF8.initialization preserve=yes
    //## end CCfits::BinTable::BinTable%38D651B8DBF8.initialization
  {
    //## begin CCfits::BinTable::BinTable%38D651B8DBF8.body preserve=yes

  init(readFlag,keys);
  
    //## end CCfits::BinTable::BinTable%38D651B8DBF8.body
  }

  BinTable::BinTable (FITSBase* p, const String &hduName, int rows, const std::vector<String>& columnName, const std::vector<String>& columnFmt, const std::vector<String>& columnUnit, int version)
    //## begin CCfits::BinTable::BinTable%38467DFACEA8.hasinit preserve=yes
      : Table(p, BinaryTbl, hduName, rows,  columnName, columnFmt, columnUnit, version)
    //## end CCfits::BinTable::BinTable%38467DFACEA8.hasinit
    //## begin CCfits::BinTable::BinTable%38467DFACEA8.initialization preserve=yes
    //## end CCfits::BinTable::BinTable%38467DFACEA8.initialization
  {
    //## begin CCfits::BinTable::BinTable%38467DFACEA8.body preserve=yes
  long           repeat=0;
  long           width=0;
  int            status=0;
  int            colType=0;
  
  ColumnCreator create(this);

  for (int i=0; i < numCols(); i++)
  {
     status = fits_binary_tform(const_cast<char *>(columnFmt[i].c_str()), 
				&colType, &repeat, &width, &status);
     
     column(columnName[i],create.createColumn(i+1, ValueType(colType),
                                columnName[i], columnFmt[i], 
                                columnUnit[i],repeat,width));
     
     column(columnName[i]).setLimits(ValueType(colType));
     
  }
    //## end CCfits::BinTable::BinTable%38467DFACEA8.body
  }

  BinTable::BinTable (FITSBase* p, int number)
    //## begin CCfits::BinTable::BinTable%3951184201FD.hasinit preserve=yes
        : Table(p,BinaryTbl,number)
    //## end CCfits::BinTable::BinTable%3951184201FD.hasinit
    //## begin CCfits::BinTable::BinTable%3951184201FD.initialization preserve=yes
    //## end CCfits::BinTable::BinTable%3951184201FD.initialization
  {
    //## begin CCfits::BinTable::BinTable%3951184201FD.body preserve=yes
  init();
    //## end CCfits::BinTable::BinTable%3951184201FD.body
  }


  BinTable::~BinTable()
  {
    //## begin CCfits::BinTable::~BinTable%3804A5C78008_dest.body preserve=yes
    //## end CCfits::BinTable::~BinTable%3804A5C78008_dest.body
  }



  //## Other Operations (implementation)
  void BinTable::readTableHeader (int ncols, std::vector<String>& colName, std::vector<String>& colFmt, std::vector<String>& colUnit)
  {
    //## begin CCfits::BinTable::readTableHeader%38D7E3FB7E28.body preserve=yes
   int   status=0;
   char  hduName[FLEN_KEYWORD];
   
   char** columnName = new char*[ncols];
   char** columnFmt  = new char*[ncols];
   char** columnUnit = new char*[ncols];
   int i = 0; // for MS VC++  
   for( ; i < ncols; i++)
   {
      columnName[i] = new char[FLEN_KEYWORD];
      columnFmt[i]  = new char[FLEN_KEYWORD];
      columnUnit[i] = new char[FLEN_KEYWORD];
   }

   long pct = 0;
   long nr  = 0;
   int tf  = 0;
   status = fits_read_btblhdr(fitsPointer(), ncols, &nr, &tf, columnName,
			      columnFmt, columnUnit, hduName, &pct,&status);
   pcount(pct);
   rows(nr);
   numCols(tf);
   
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
  
   // throw the exception after the garbage has been collected.
   
   if (status != 0)  throw FitsError(status);
    //## end CCfits::BinTable::readTableHeader%38D7E3FB7E28.body
  }

  BinTable * BinTable::clone (FITSBase* p) const
  {
    //## begin CCfits::BinTable::clone%381F02F226F0.body preserve=yes
  BinTable* cloned = new BinTable(*this);
  cloned->parent() = p;
  return cloned;
    //## end CCfits::BinTable::clone%381F02F226F0.body
  }

  void BinTable::readData (bool readFlag, const std::vector<String>& keys)
  {
    //## begin CCfits::BinTable::readData%395107210396.body preserve=yes
   int             rowsRead=0;
   std::vector<String>     varCols;
   int status = 0;
   long rowSize = 0;
   
   // grab the optimal rowsize using the get_rowsize call. It just
   // might have changed since the Table HDU was constructed so it should
   // be set just before reading takes place.
   if (fits_get_rowsize(fitsPointer(), &rowSize, &status))  throw FitsError(status);

   // if a set of strings were supplied, interpret these as
   // keywords and columns to be read.
   
   std::map<String,Column*>::iterator endColumn = column().end();
   size_t keysRead = 0;
   size_t nkey=keys.size();
   
   // get a container for keys which correspond to columns.
   std::vector<String> colKeys;
   colKeys.reserve(nkey);
   
   
   if (nkey > 0)
   {
       // first, look for keywords if strings are supplied and read them.
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
	                // if the column is not of variable repeat count... 
                        if (!current.varLength())
                        {
                             current.readData(rowsRead+1,
                                             current.repeat()*std::min<size_t>(rowSize,rows()-rowsRead),1);
                        }
                        else
                        {
                        // store the column numbers of variable columns for later.
                             varCols.push_back(current.name());
                        }
                }
        }
        else
        {
                // if no keys that correspond to column names were supplied, read all the data.
	        for(col = column().begin(); col != column().end(); col++ )
                {      
                        Column& current = *(*col).second;
	                if (!current.varLength()) 
                        { 
                                current.readData(rowsRead+1,
                                          current.repeat()*std::min<size_t>(rowSize,rows() - rowsRead),1);
                        }
                        else
                        {
                                varCols.push_back(current.name());
                        }
      
                }
         }
   }
 
   // if successful, mark read columns.
   
   if (colKeys.size() ==  0)
   {
        // mark all columns read
        for (std::map<String,Column*>::iterator col = column().begin(); 
                col != column().end(); ++col) 
        {
                if (!(*col).second->varLength()) (*col).second->isRead(true);
        }
   }
   else
   {
        for (size_t i=0; i < colKeys.size() ; i++)
        {
                // if a set of keys was entered, read the data in the ones
                // that correspond to columns, as checked earlier.
                std::map<String,Column*>::iterator col = column().find(colKeys[i]);
                 
                if (!(*col).second->varLength()) (*col).second->isRead(true);
        }
               
   }

   
   // now read the variable length columns that were found earlier.
   
   if (varCols.size() > 0 ) readVariableColumns(varCols);
    //## end CCfits::BinTable::readData%395107210396.body
  }

  void BinTable::readVariableColumns (const std::vector<String> &varColumns)
  {
    //## begin CCfits::BinTable::readVariableColumns%395108470150.body preserve=yes
    int   rowsRead=0;
    int   status=0;
    int   sz=varColumns.size();


    int i = 0;
    FITSUtil::auto_array_ptr<long> pBinSizes(new long[rows()]);
    long*  binSizes = pBinSizes.get();
    FITSUtil::auto_array_ptr<long> pOffsets(new long[rows()]);
    long*  offsets  = pOffsets.get();
    while ( i < sz && status == 0 )  
    {
       // Get bin size for the current column 
       Column& thisColumn = column(varColumns[i]);
       int colnum = thisColumn.index();
       status = fits_read_descripts(fitsPointer(), colnum, 1, rows() , binSizes,
				    offsets, &status);
       if (status != 0) break;

       for (rowsRead=0; rowsRead < rows() ; rowsRead++)
       {
	  if (binSizes[rowsRead] > 0)
	     thisColumn.readData(rowsRead+1, binSizes[rowsRead], 1);
       }
       column(varColumns[i]).isRead(true);
       i++;

    }


    if (status != 0)  throw FitsError(status);
    //## end CCfits::BinTable::readVariableColumns%395108470150.body
  }

  void BinTable::addColumn (ValueType type, const String& columnName, long repeatWidth, const String& colUnit, long decimals, size_t columnNumber)
  {
    //## begin CCfits::BinTable::addColumn%3B0BC4460024.body preserve=yes
#ifdef SSTREAM_DEFECT
        std::ostrstream tformStr;
#else
        std::ostringstream tformStr;          
#endif
      
        // we do NOT support the extension allowed by cfitsio whereby multiple
        // strings can be saved in a binary table column cell.
          
        String diag("");   
        
        if ( repeatWidth != 1 && type != Tstring) 
        { 
                tformStr << repeatWidth;       
        }
        
        // this is safe since there's no VTstring type.
        if (type < 0) tformStr << 'P';
        
        switch (type)
        {
                case Tstring:
                        tformStr << 'A' << repeatWidth;
                        break;
                case Tbyte:
                case VTbyte:
                        tformStr << 'B';
                        break;                
                case Tbit:
                case VTbit:
                        tformStr << 'X';             
                        break; 
                        
                case Tlogical:
                case VTlogical:
                        tformStr << 'L';             
                        break;   
  
                case Tushort:
                case VTushort:
                        tformStr << 'U';
                        break;
                
                case Tshort:
                case VTshort:
                        tformStr << 'I';
                        break;
                        
                case Tulong:
                case VTulong:
                        tformStr << 'V';
                        break;
                        
                case Tlong:
                case VTlong:
                        tformStr << 'J';
                        break;   
                
                case Tlonglong:
                case VTlonglong:
                        tformStr << 'K';
                        break;        
                case Tuint:
                case VTuint:
                        tformStr << 'V';
                        break;
                       
                case Tint:
                case VTint:
                        tformStr << 'J';
                        break;  
                        
                case Tfloat:
                case VTfloat:
                        tformStr << 'E';
                        break;  
                         
                case Tdouble:
                case VTdouble:
                        tformStr << 'D';
                        break;  

                case Tcomplex:
                case VTcomplex:
                        tformStr << 'C';
                        break;  
        
                case Tdblcomplex:
                case VTdblcomplex:
                        tformStr << 'M';
                        break;  

                default:           
                        diag += "Unrecognized data type for column: ";
                        diag += columnName;
                        throw InvalidColumnSpecification(diag);            
        }
#ifdef SSTREAM_DEFECT
        tformStr << std::ends;
#endif

        int status(0);
        int colNum(0);
        if ( columnNumber == 0)
        {
            // add one to number of existing columns.
            if (fits_get_num_cols(fitsPointer(),&colNum,&status)) throw FitsError(status);
            colNum +=1;
        }
        else 
        {
                colNum = columnNumber;
        }
       
        String tfString(tformStr.str());
        // the C prototypes don't use const, so these casts are necessary.       
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
        if (type != Tstring)
        {
                 column(columnName,create.createColumn(colNum,type,columnName,tfString,
                      colUnit,repeatWidth,1));
                 column(columnName).setLimits(type);
        }
        else
        {
                column(columnName,create.createColumn(colNum,type,columnName,tfString,
                      colUnit,1,repeatWidth));                
        }
        
         if (columnNumber != 0) reindex();
    //## end CCfits::BinTable::addColumn%3B0BC4460024.body
  }

  // Additional Declarations
    //## begin CCfits::BinTable%3804A5C78008.declarations preserve=yes
    //## end CCfits::BinTable%3804A5C78008.declarations

} // namespace CCfits

//## begin module%3804A653F4B0.epilog preserve=yes
//## end module%3804A653F4B0.epilog
