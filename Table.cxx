//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3804A0860AC0.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%3804A0860AC0.cm

//## begin module%3804A0860AC0.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%3804A0860AC0.cp

//## Module: Table%3804A0860AC0; Package body
//## Subsystem: CCfits::HDU::Table%3826E0E37A78
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/Table.cxx

//## begin module%3804A0860AC0.additionalIncludes preserve=no
//## end module%3804A0860AC0.additionalIncludes

//## begin module%3804A0860AC0.includes preserve=yes
//## end module%3804A0860AC0.includes

// Column
#include "Column.h"
// ColumnCreator
#include "ColumnCreator.h"
// Table
#include "Table.h"
// FITS
#include "FITS.h"


//## begin module%3804A0860AC0.declarations preserve=no
//## end module%3804A0860AC0.declarations

//## begin module%3804A0860AC0.additionalDeclarations preserve=yes
#include <algorithm>
//## end module%3804A0860AC0.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  // Class CCfits::Table::NoSuchColumn 

  Table::NoSuchColumn::NoSuchColumn (const String& name, bool silent)
    //## begin CCfits::Table::NoSuchColumn::NoSuchColumn%397CB0CD0015.hasinit preserve=yes
  : FitsException("Fits Error: cannot find column named: ",silent)
    //## end CCfits::Table::NoSuchColumn::NoSuchColumn%397CB0CD0015.hasinit
    //## begin CCfits::Table::NoSuchColumn::NoSuchColumn%397CB0CD0015.initialization preserve=yes
    //## end CCfits::Table::NoSuchColumn::NoSuchColumn%397CB0CD0015.initialization
  {
    //## begin CCfits::Table::NoSuchColumn::NoSuchColumn%397CB0CD0015.body preserve=yes
    if (!silent || FITS::verboseMode() ) std::cerr << name << '\n';
    //## end CCfits::Table::NoSuchColumn::NoSuchColumn%397CB0CD0015.body
  }

  Table::NoSuchColumn::NoSuchColumn (int index, bool silent)
    //## begin CCfits::Table::NoSuchColumn::NoSuchColumn%397CB0F60292.hasinit preserve=yes
  : FitsException("Fits Error: no column numbered: ",silent)
    //## end CCfits::Table::NoSuchColumn::NoSuchColumn%397CB0F60292.hasinit
    //## begin CCfits::Table::NoSuchColumn::NoSuchColumn%397CB0F60292.initialization preserve=yes
    //## end CCfits::Table::NoSuchColumn::NoSuchColumn%397CB0F60292.initialization
  {
    //## begin CCfits::Table::NoSuchColumn::NoSuchColumn%397CB0F60292.body preserve=yes
    if (!silent || FITS::verboseMode() )  std::cerr << index << '\n';
    //## end CCfits::Table::NoSuchColumn::NoSuchColumn%397CB0F60292.body
  }


  // Class CCfits::Table::InvalidColumnSpecification 

  Table::InvalidColumnSpecification::InvalidColumnSpecification (const String& msg, bool silent)
    //## begin CCfits::Table::InvalidColumnSpecification::InvalidColumnSpecification%3B1E52EC03B0.hasinit preserve=yes
    : FitsException("Fits Error: illegal column specification ",silent)
    //## end CCfits::Table::InvalidColumnSpecification::InvalidColumnSpecification%3B1E52EC03B0.hasinit
    //## begin CCfits::Table::InvalidColumnSpecification::InvalidColumnSpecification%3B1E52EC03B0.initialization preserve=yes
    //## end CCfits::Table::InvalidColumnSpecification::InvalidColumnSpecification%3B1E52EC03B0.initialization
  {
    //## begin CCfits::Table::InvalidColumnSpecification::InvalidColumnSpecification%3B1E52EC03B0.body preserve=yes
    if (!silent || FITS::verboseMode() )  std::cerr << msg << '\n';
    //## end CCfits::Table::InvalidColumnSpecification::InvalidColumnSpecification%3B1E52EC03B0.body
  }


  // Class CCfits::Table 

  Table::Table(const Table &right)
    //## begin Table::Table%3804A0588338_copy.hasinit preserve=yes
  : ExtHDU(right),        
  m_numCols(right.m_numCols),
  m_column()
    //## end Table::Table%3804A0588338_copy.hasinit
    //## begin Table::Table%3804A0588338_copy.initialization preserve=yes
    //## end Table::Table%3804A0588338_copy.initialization
  {
    //## begin CCfits::Table::Table%3804A0588338_copy.body preserve=yes
  
  // deep-copy the right hand side data.
  copyData(right);
    //## end CCfits::Table::Table%3804A0588338_copy.body
  }

  Table::Table (FITSBase* p, HduType xtype, const String &hduName, int rows, const std::vector<String>& columnName, const std::vector<String>& columnFmt, const std::vector<String>& columnUnit, int version)
    //## begin CCfits::Table::Table%3805D315D0D0.hasinit preserve=yes
      : ExtHDU(p, xtype, hduName,  8, 2, std::vector<long>(2), version),
	 m_numCols(columnName.size()), m_column()
    //## end CCfits::Table::Table%3805D315D0D0.hasinit
    //## begin CCfits::Table::Table%3805D315D0D0.initialization preserve=yes
    //## end CCfits::Table::Table%3805D315D0D0.initialization
  {
    //## begin CCfits::Table::Table%3805D315D0D0.body preserve=yes

   int      status=0;
   
   // remember this is the writing constructor so user must specify
   // what kind of extension this is.
   int tblType = xtype;
   
   naxes(1) = rows;
   
   const size_t n(columnName.size());
   //FITSUtil::auto_array_ptr<char*> pCname(new char*[n]);
   //FITSUtil::auto_array_ptr<char*> pCformat(new char*[n]);
   //FITSUtil::auto_array_ptr<char*> pCunit(new char*[n]);
   char** cname = new char*[n];
   char** cformat = new char*[n];
   char** cunit = new char*[n];

   for (size_t i = 0; i < n; ++i)
   {
        cname[i] = const_cast<char*>(columnName[i].c_str());       
        cformat[i] =  const_cast<char*>(columnFmt[i].c_str());       
        cunit[i]  = const_cast<char*>(columnUnit[i].c_str());
   }
   
   
   if (fits_create_tbl(fitsPointer(), tblType, rows , m_numCols, cname,
			    cformat, cunit, const_cast<char*>(hduName.c_str()),
			    &status))  
   {
           delete [] cname;
           delete [] cformat;
           delete [] cunit;
           throw FitsError(status);
   } 
   
   delete[] cname;
   delete[] cformat;
   delete[] cunit;
   
    //## end CCfits::Table::Table%3805D315D0D0.body
  }

  Table::Table (FITSBase* p, HduType xtype, const String &hduName, int version)
    //## begin CCfits::Table::Table%3950DF79004B.hasinit preserve=yes
      : ExtHDU(p,xtype,hduName,version), m_numCols(0), m_column()
    //## end CCfits::Table::Table%3950DF79004B.hasinit
    //## begin CCfits::Table::Table%3950DF79004B.initialization preserve=yes
    //## end CCfits::Table::Table%3950DF79004B.initialization
  {
    //## begin CCfits::Table::Table%3950DF79004B.body preserve=yes
    getVersion();
    //## end CCfits::Table::Table%3950DF79004B.body
  }

  Table::Table (FITSBase* p, HduType xtype, int number)
    //## begin CCfits::Table::Table%395117FC018F.hasinit preserve=yes
  : ExtHDU(p,xtype,number),
  m_numCols(0),
  m_column()
    //## end CCfits::Table::Table%395117FC018F.hasinit
    //## begin CCfits::Table::Table%395117FC018F.initialization preserve=yes
    //## end CCfits::Table::Table%395117FC018F.initialization
  {
    //## begin CCfits::Table::Table%395117FC018F.body preserve=yes
    getVersion();
    //## end CCfits::Table::Table%395117FC018F.body
  }


  Table::~Table()
  {
    //## begin CCfits::Table::~Table%3804A0588338_dest.body preserve=yes
        // destroy existing data (garbage collection for heap objects).
        clearData();
    //## end CCfits::Table::~Table%3804A0588338_dest.body
  }



  //## Other Operations (implementation)
  void Table::initRead ()
  {
    //## begin CCfits::Table::initRead%3846B8A79D78.body preserve=yes
   int        ncols=0;
   int        i=0;
   int        status=0;

   status = fits_get_num_cols(fitsPointer(), &ncols, &status);
   if (status != 0)  throw FitsError(status);

  
   std::vector<String> colName(ncols,"");
   std::vector<String> colFmt(ncols,"");
   std::vector<String> colUnit(ncols,"");
   
   ColumnCreator create(this);
   // virtual
   readTableHeader(ncols, colName, colFmt, colUnit);


   for(i=0; i<m_numCols; i++)
   {
        m_column[colName[i]] =  create.getColumn(i+1, colName[i], colFmt[i],colUnit[i]);
        Column& col = column(colName[i]);
        col.setLimits(col.type());
   }
  

    //## end CCfits::Table::initRead%3846B8A79D78.body
  }

  std::ostream & Table::put (std::ostream &s) const
  {
    //## begin CCfits::Table::put%385A3E921210.body preserve=yes
  s << "FITS Table::  "  <<  " Name: " << name() << " BITPIX "<< bitpix() << "\n";

  s <<  " Number of Rows (NAXIS2) " << axis(1)  << "\n";
  
  s << " HISTORY: " << history() << '\n';
  
  s << " COMMENTS: " << comment() << '\n';
  
  s <<  " HDU number: " <<  index() + 1 << " No. of Columns: " << numCols() ;
  
  if ( version() ) s << " Version " << version();

  s << "\nNumber of keywords read: " << keyWord().size() <<  "\n";
  

  
  
  for (std::map<String,Keyword*>::const_iterator ki = keyWord().begin();
        ki != keyWord().end(); ki++)
  {
        s << *((*ki).second) << std::endl;              
  }  
  
  std::vector<Column*> __tmp;
  std::map<String,Column*>::const_iterator ciEnd(m_column.end());
  std::map<String,Column*>::const_iterator ci(m_column.begin());
  while (ci != ciEnd) 
  {
        __tmp.push_back((*ci).second);
        ++ci;
  } 
  std::sort(__tmp.begin(),__tmp.end(),FITSUtil::ComparePtrIndex<Column>());
  
  for (std::vector<Column*>::iterator lci = __tmp.begin(); lci != __tmp.end(); ++lci) 
  {
          s << **lci << std::flush;
  }

  
  return s;
    //## end CCfits::Table::put%385A3E921210.body
  }

  void Table::column (int columnNum, Column *value)
  {
    //## begin CCfits::Table::column%387C9CD66838.body preserve=yes
  std::map<String,Column*>::const_iterator columnByNum;
  
  for (columnByNum=m_column.begin(); columnByNum!=m_column.end(); 
       columnByNum++)
     if ( ((*columnByNum).second)->index() == columnNum) 
        break;
  
  m_column[(*columnByNum).first] = value;
    //## end CCfits::Table::column%387C9CD66838.body
  }

  void Table::init (bool readFlag, const std::vector<String>& keys)
  {
    //## begin CCfits::Table::init%395118A40342.body preserve=yes

  // read and defined the columns from the header.  
  initRead();

  // read data or keys if any are requested.
  if (readFlag || keys.size() > 0) readData(readFlag,keys);
    //## end CCfits::Table::init%395118A40342.body
  }

  void Table::clearData ()
  {
    //## begin CCfits::Table::clearData%39521D3A00B3.body preserve=yes
  // obliterate current contents, then remove pointers from the map.
  for (std::map<String,Column*>::const_iterator col = m_column.begin(); 
          col != m_column.end(); col++)
  {
        delete (*col).second;
  }
  
  m_column.clear();
    //## end CCfits::Table::clearData%39521D3A00B3.body
  }

  void Table::copyData (const Table& right)
  {
    //## begin CCfits::Table::copyData%39521E260007.body preserve=yes
    
  // ensure deep copy. clone() calls the copy constructor for Column.
  // Column has 'deep copy' because all its data members that need
  // to be copied (i.e. not the pointer to the fits file) are allocated
  // on the stack by being Container types.
  std::map<String,Column*> newColumnContainer;
          
  try
  {
        for (std::map<String,Column*>::const_iterator col = right.m_column.begin(); 
                col != right.m_column.end(); col++)
        {
                newColumnContainer[(*col).first] = (*col).second->clone();
        }
        m_column = newColumnContainer;
  }
  catch (...)  { throw; }
                  
    //## end CCfits::Table::copyData%39521E260007.body
  }

  Column& Table::column (const String& colName) const
  {
    //## begin CCfits::Table::column%397CAE7402E5.body preserve=yes
  std::map<String,Column*>::const_iterator key = m_column.find(colName);
  
  if ( key == m_column.end() ) throw NoSuchColumn(colName);
  
  return *((*key).second);
    //## end CCfits::Table::column%397CAE7402E5.body
  }

  Column& Table::column (int colIndex) const
  {
    //## begin CCfits::Table::column%397CAF0E01AB.body preserve=yes
  std::map<String,Column*>::const_iterator key;
            
  for ( key = m_column.begin(); key != m_column.end(); key++)
  {
        if ( ((*key).second)->index() == colIndex) break;    
            
  }
  
  if ( key == m_column.end() ) throw NoSuchColumn(colIndex); 
  
  return *((*key).second); 
    //## end CCfits::Table::column%397CAF0E01AB.body
  }

  void Table::updateRows ()
  {
    //## begin CCfits::Table::updateRows%3AFAB13302EB.body preserve=yes
    long numrows(0);
    int status(0);
    if (fits_get_num_rows(fitsPointer(),&numrows,&status) ) throw FitsError(status);
    naxes(1,numrows);
    //## end CCfits::Table::updateRows%3AFAB13302EB.body
  }

  void Table::column (const String& colname, Column* value)
  {
    //## begin CCfits::Table::column%3B042E810363.body preserve=yes
    // don't do map's default behavior which is to add a new column
    // if the input name and data don't exist.
    m_column[colname] = value;
    //## end CCfits::Table::column%3B042E810363.body
  }

  void Table::deleteColumn (const String& name)
  {
    //## begin CCfits::Table::deleteColumn%3B0AB97600D2.body preserve=yes
        Column& doomed = column(name);
        int status(0);
        if ( fits_delete_col(fitsPointer(),doomed.index(),&status) ) throw  FitsError(status);
        delete &doomed;
        m_column.erase(name);
        reindex();
        updateRows();
    //## end CCfits::Table::deleteColumn%3B0AB97600D2.body
  }

  void Table::insertRows (long first, long number)
  {
    //## begin CCfits::Table::insertRows%3B24ECDE013F.body preserve=yes
    int status(0);
    
    if (fits_insert_rows(fitsPointer(),first,number,&status)) throw FitsError(status);
    // cfitsio's semantics are that rows are insert after row first,
    // while vector's insert semantic is to insert before the initial.
    std::map<String,Column*>::iterator ci = m_column.begin();
    std::map<String,Column*>::iterator ciEnd = m_column.end();
    
    while (ci != ciEnd)
    {
        ((*ci).second)->insertRows(first,number);     
        ++ci;  
    }
    
    updateRows();
    //## end CCfits::Table::insertRows%3B24ECDE013F.body
  }

  void Table::deleteRows (long first, long number)
  {
    //## begin CCfits::Table::deleteRows%3B24ECE30071.body preserve=yes
     // this should only be able to throw the FitsError exception and
    // should not leak resources as per the standard library guarantee for vector.
    makeThisCurrent();
    int status(0);
    
    // cfitsio will reject invalid values of first, number. (e.g. first <= 0).
    if (fits_delete_rows(fitsPointer(),first,number,&status)) throw FitsError(status);
    
    std::map<String,Column*>::iterator ci = m_column.begin();
    std::map<String,Column*>::iterator ciEnd = m_column.end();
    
    while (ci != ciEnd)
    {
        ((*ci).second)->deleteRows(first,number);     
        ++ci;  
    }
    
    updateRows();
    //## end CCfits::Table::deleteRows%3B24ECE30071.body
  }

  void Table::deleteRows (const std::vector<long>& rowList)
  {
    //## begin CCfits::Table::deleteRows%3B24ECE80306.body preserve=yes
    int status(0);
    makeThisCurrent();
    FITSUtil::CVarray<long> convert;
    FITSUtil::auto_array_ptr<long> pDoomedRows(convert(rowList));
    long* doomedRows = pDoomedRows.get();
    if (fits_delete_rowlist(fitsPointer(),doomedRows,rowList.size(),&status)) 
                         throw FitsError(status);

        
    std::map<String,Column*>::iterator ci = m_column.begin();
    std::map<String,Column*>::iterator ciEnd = m_column.end();
    
    const size_t N(rowList.size());
    
    while (ci != ciEnd)
    {
        for (size_t j = 0; j < N; ++j)
        {
                ((*ci).second)->deleteRows(rowList[j],1);
        }     
        ++ci;  
    }
    
    updateRows();
    
    //## end CCfits::Table::deleteRows%3B24ECE80306.body
  }

  void Table::reindex ()
  {
    //## begin CCfits::Table::reindex%3B5DA20E0398.body preserve=yes
        makeThisCurrent();
        std::map<String,Column*>::iterator ci(m_column.begin());
        std::map<String,Column*>::iterator ciEnd(m_column.end());
        int status(0);
        
        while (ci != ciEnd)
        {
                int colnum(0);
                char* cname = const_cast<char*>((*ci).first.c_str());
                if (fits_get_colnum(fitsPointer(),CASESEN,cname,&colnum,&status))
                                        throw FitsError(status);
                (*ci).second->index(colnum);       
                ++ci;
        }       
            
    //## end CCfits::Table::reindex%3B5DA20E0398.body
  }

  // Additional Declarations
    //## begin CCfits::Table%3804A0588338.declarations preserve=yes
    //## end CCfits::Table%3804A0588338.declarations

} // namespace CCfits

//## begin module%3804A0860AC0.epilog preserve=yes
//## end module%3804A0860AC0.epilog
