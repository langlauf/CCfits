
//	This is version 1.2 release dated April 2003

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	April 2003 Ben Dorman, L3-Communications EER Systems Inc.
//	e-mail: ccfits@legacy.gsfc.nasa.gov




// Table
#include "Table.h"
// PHDU
#include "PHDU.h"
// FITSBase
#include "FITSBase.h"
// HDUCreator
#include "HDUCreator.h"
// PrimaryHDU
#include "PrimaryHDU.h"
// FITS
#include "FITS.h"



#ifdef _MSC_VER
#include "MSconfig.h" // for truncation warning
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef HAVE_SSTREAM
#include <strstream>
#else
#include <sstream>
#endif

using std::endl;
using std::cout;
using std::cerr;

#include <memory>


namespace CCfits {

  // Class CCfits::FITS::NoSuchHDU 

  FITS::NoSuchHDU::NoSuchHDU (const string& diag, bool silent)
  : FitsException("FITS Error: Cannot read HDU in FITS file:",silent)
  {
  //! Exception to be thrown by failed seek operations
  if ( FITS::verboseMode() || !silent) std::cerr << diag << "\n";
  }


  // Class CCfits::FITS::OperationNotSupported 

  FITS::OperationNotSupported::OperationNotSupported (const string& msg, bool silent)
  : FitsException("FITS Error: Operation not supported:",silent)
  {
    if ( FITS::verboseMode() || !silent)  std::cerr << msg << "\n";
  }


  // Class CCfits::FITS::CantOpen 

  FITS::CantOpen::CantOpen (const string& diag, bool silent)
   : FitsException("FITS Error: Cannot open file ",silent)
  {
    if ( FITS::verboseMode() || !silent)  std::cerr << diag << "\n";
  }


  // Class CCfits::FITS::CantCreate 

  FITS::CantCreate::CantCreate (const string& diag, bool silent)
   : FitsException(string("FITS Error: Cannot create file "),silent)
  {
  if ( FITS::verboseMode() || !silent) std::cerr << diag << '\n';
  }


  // Class CCfits::FITS 

  bool FITS::s_verboseMode = false;

  FITS::FITS(const FITS &right)
    : m_FITSImpl(right.m_FITSImpl->clone())
  {
  }

  FITS::FITS (const string &name, RWmode mode, bool readDataFlag, const std::vector<string>& primaryKeys)
  : m_FITSImpl(new FITSBase(name,mode))
  {
 


          if (mode == Read) 
          {
                open(mode);
                //        get the primary header.

                read(readDataFlag,primaryKeys);
                readExtensions(readDataFlag);
          }
          else
          {
  
                // create a primary header in the receiving structure. The user
                // didn't specify a primary in the constructor call so wants a dummy
                // primary with no data. If however the user is appending to an
                // existing file we don't want to do anything to the existing primary.
                // PHDU has a private constructor and must be instantiated here only.
                // this ensures that every FITS object has exactly one PHDU.
                if (create() )
                {
                        // create returns true if the file is either new
                        // or overwritten, in which case we need to create 
                        // and write a new primary with BITPIX=8 and NAXIS=0.
                        HDUCreator makePrimary(m_FITSImpl);
  
                        pHDU(makePrimary.createImage(8,0,std::vector<long>()));       
                }
                else
                {
                        // the difference is that this doesn't write anything to the file,
                        // it just reads the primary header information.  
                        read();
                }
          }
  }

  FITS::FITS (const string &name, RWmode mode, const string &hduName, bool readDataFlag, const std::vector<string>& hduKeys, const std::vector<string>& primaryKey, int version)
  : m_FITSImpl(new FITSBase(name,mode))
  {
          open(mode);

          // create and read the Primary: assume here that a single HDU other than
          // the primary is requested, so don't read primary data. We can however
          // read some header info from the primary if (optionally) specified.

          read(false,primaryKey);

          // create a primary header in the receiving structure.
          // PHDU has a private constructor and must be instantiated here only.
          // this ensures that every FITS object has exactly one PHDU

          read(hduName, readDataFlag, hduKeys,version);
  }

  FITS::FITS (const string &name, RWmode mode, const std::vector<string>& hduNames, bool readDataFlag, const std::vector<string>& primaryKey)
  : m_FITSImpl(new FITSBase(name,mode))
  {

        open(mode);

        read(readDataFlag,primaryKey);
        read(hduNames,readDataFlag);

  }

  FITS::FITS (const string& fileName, const FITS& source)
    : m_FITSImpl(new FITSBase(fileName,Write))
  {
          
    if (create() )
    {
            // create returns true if the file is either new
            // or overwritten, in which case we need to create 
            // and write a new primary which is a clone of the source PHDU.

            pHDU(static_cast<PHDU*>(source.pHDU().clone(m_FITSImpl)));       
    }    
    int status(0);
    
    source.pHDU().makeThisCurrent();
       
    if (fits_copy_hdu(source.fitsPointer(),m_FITSImpl->fptr(),0,&status)) throw FitsError(status);
  
  }

  FITS::FITS (const string &name, RWmode mode, const std::vector<string>& hduNames, const std::vector<std::vector<string> >& hduKeys, bool readDataFlag, const std::vector<string>& primaryKeys, const std::vector<int>& hduVersions)
  : m_FITSImpl(new FITSBase(name,mode))
  {
          
          open(mode);


          // read the primary header and read the data if readDataFlag is set.
          // create returns a PHDU if the index is 0.

          read(readDataFlag,primaryKeys);



          // create a primary header in the receiving structure.
          // PHDU has a private constructor and must be instantiated here only.
          // this ensures that every FITS object has exactly one PHDU

          read(hduNames, hduKeys, readDataFlag, hduVersions);
  }

  FITS::FITS (const string& name, int bitpix, int naxis, long *naxes)
  : m_FITSImpl(new FITSBase(name,Write))
  {

        std::vector<long>    va_naxes(naxis);
        std::copy(&naxes[0],&naxes[naxis],va_naxes.begin());
  
        create();
  
        // create an HDU factory.
        HDUCreator makePrimary(m_FITSImpl);
  
        // set the PrimaryHDU. bitpix will determine the data type.
        pHDU(makePrimary.createImage(bitpix,naxis,va_naxes));
  }

  FITS::FITS (const string &name, RWmode mode, int hduIndex, bool readDataFlag, const std::vector<string>& hduKeys, const std::vector<string>& primaryKey)
  : m_FITSImpl(new FITSBase(name,mode))
  {

        open(mode);
        // read the primary header. Allowing the user to read the primary data
        // and optional keys costs nothing here, although the likely use of this
        // constructor is to read a specified HDU from a file other than the Primary.
        read(readDataFlag,primaryKey);
  
        read(hduIndex,readDataFlag,hduKeys);
  
  }

  FITS::FITS (const string &name, RWmode mode, const std::vector<string>& searchKeys, const std::vector<string> &searchValues, bool readDataFlag, const std::vector<string>& hduKeys, const std::vector<string>& primaryKey, int version)
  : m_FITSImpl(new FITSBase(name,mode))
  {
          
        open(mode);

        // read the primary header and read the data if readDataFlag is set.
        // create returns a PHDU if the index is 0.
   
        read(false,primaryKey);
   

        // create a primary header in the receiving structure.
        // PHDU has a private constructor and must be instantiated here only.
        // this ensures that every FITS object has exactly one PHDU

        read(searchKeys, searchValues, readDataFlag, hduKeys, version);
  }


  FITS::~FITS()
  {
    destroy();      
  }



  void FITS::unmapExtension (ExtHDU& doomed)
  {
    const string& doomedName = doomed.name();
    if ( extension().count(doomedName) == 1 )
    {
        ExtMapIt x = extension().lower_bound(doomedName);
        delete (*x).second;       
        extension().erase(x);
    }
    else
    {
            std::pair<ExtMapIt,ExtMapIt> named = extension().equal_range(doomedName);

            ExtMapIt x = named.first;

            while ( x != named.second)
            {

                    if ( (*x).second->version() == doomed.version())
                    {
                        delete (*x).second;
                        extension().erase(x);       
                        break;
                    }       
                    ++x;
            }
    }     
  }

  void FITS::clearErrors ()
  {
    fits_clear_errmsg();
  }

  void FITS::deleteExtension (const std::string& doomed, int version)
  {
    int status(0);
    ExtHDU& d = extension(doomed,version); // throws NoSuchHDU if it's not there.
    if (fits_delete_hdu(fitsPointer(),0,&status)) throw FitsError(status);
    unmapExtension(d);
  }

  int FITS::nextVersionNumber (const string& inputName) const
  {
    int n(0);
    int status(0);
    int current(0);
    if (fits_get_num_hdus(fitsPointer(),&n,&status)) throw FitsError(status);
    fits_get_hdu_num(fitsPointer(),&current);

    int count(0);
    for (int j = 2; j <= n; ++j)
    {
        if (nameOfUnmapped(j) == inputName) ++count;
    }
    if (fits_movabs_hdu(fitsPointer(),current,0,&status)) throw FitsError(status);
    return count+1;      
  }

  void FITS::read (bool readDataFlag, const std::vector<string>& keys)
  {

   HDUCreator create(m_FITSImpl);
   
   
   pHDU(static_cast<PHDU*>(create.getHdu(0,readDataFlag,keys)));

  }

  void FITS::read (const string &hduName, bool readDataFlag, const std::vector<string> &keys, int version)
  {
       HDUCreator create(m_FITSImpl);
   
        try
        {
                // primary is always false here.   
                ExtHDU* newHDU = static_cast<ExtHDU*>(create.getHdu(hduName, readDataFlag, keys, false, version));
                // add a specified HDU in the file to the list of extensions.
                addExtension(newHDU);
        }
        catch ( ... )
        {
                throw NoSuchHDU(hduName);
        }

  }

  void FITS::read (const std::vector<string> &hduNames, bool readDataFlag)
  {
   int  nhdu=hduNames.size();
   HDUCreator create(m_FITSImpl);
   
   for (int i = 0; i < nhdu ; i++)
   {
        try
        {
                // getHdu can throw.
                 // add a specified HDU in the file to the list of extensions.
                addExtension(static_cast<ExtHDU*>(create.getHdu(hduNames[i], readDataFlag)));
                create.reset();
        }
        catch ( NoSuchHDU )
        {
            // catch this one (likely, no such HDU present, but any reason why 
            // reading a specific HDU in the list supplied ) and continue.
                continue;       
        }
        catch ( ... )
        {
                throw;
        }
    }


  }

  void FITS::read (const std::vector<string> &hduNames, const std::vector<std::vector<string> > &keys, bool readDataFlag, const std::vector<int>& hduVersions)
  {

   int  nhdu=hduNames.size();
  
   // a bit of duplication here, but I didn't want to slow down the less general case.
   HDUCreator create(m_FITSImpl);
   
   for (int i = 0; i < nhdu ; i++)
   {
        try
        {
                // getHdu can throw.
                // add a specified HDU in the file to the list of extensions.
                if ( hduVersions.size() != hduNames.size())
                {
                
                
                        addExtension(static_cast<ExtHDU*>
                            (create.getHdu(hduNames[i], readDataFlag,keys[i],false)));
                }
                else
                {
                        addExtension(static_cast<ExtHDU*>
                            (create.getHdu(hduNames[i], readDataFlag,keys[i],false,hduVersions[i])));
                        
                }

                create.reset();
        }
        catch ( NoSuchHDU )
        {
            // catch this one (likely, no such HDU present, but any reason why 
            // reading a specific HDU in the list supplied ) and continue.
                // catch this one and continue.
                continue;       
        }
        catch ( ... )
        {
                throw;       
        }
    }

  }

  void FITS::open (RWmode mode)
  {
  int status=0;
  // unused:  bool silentMode = true;

  status = fits_open_file(&m_FITSImpl->fptr(), m_FITSImpl->name().c_str(), mode, &status);

  if (status != 0)  
  {
          if (status == FILE_NOT_OPENED) throw CantOpen(m_FITSImpl->name()); 
          else throw FitsError(status);
  }

  }

  bool FITS::create ()
  {

          int status(0);

          // if the filename indicates overwrite (starts with a '!' - see 
          // fits_create_file documentation)
          // or the filename does not correspond to an existing file, create file.
          // otherwise throw an overwrite exception.
 
          // if the file is writeable and the name doesn't begin with '!'
          // we want read/write access so should use fits_open_file,
          // otherwise create it. We let cfitsio worry about what
          // happens if open-with-write-mode or create fails.
          // but we must know whether the file exists.
          string fName = m_FITSImpl->name();
          if (m_FITSImpl->name()[0] == '!') 
          {
          	  m_FITSImpl->name() = fName.substr(1);
          }

	  try
          {
                  // create a new file.
		  // the '!' is processed by ffinit
                  fits_create_file(&m_FITSImpl->fptr(),fName.c_str(),&status);
                  if (status == FILE_NOT_CREATED) 
                  {
                          // turn off warning message unless verbose is
                          string warn(fName);
                          warn += " attempting to open existing file";
                          throw FITS::CantCreate(warn,true);
                  }
                  else if (status) throw FitsError(status);
                  return true; 
          }
          catch ( CantCreate )
          {
		  // try again, to see if the error  was a pre-existing file.
		  // open( RWmode ) throws CantOpen and FitsError.
                  open(Write);
                  return false;
          }



  }

  int FITS::close () throw ()
  {
  int   status=0;
  if (m_FITSImpl == 0) return 0;

  status = fits_close_file(m_FITSImpl->fptr(), &status);
  return status;
  }

  FITS * FITS::clone () const
  {
  return new FITS(*this);
  }

  const ExtHDU& FITS::extension (int i) const
  {

  const ExtMap& ext = m_FITSImpl->extension();
  ExtMapConstIt hduByNum = ext.begin();
  ExtMapConstIt endOfList = ext.end();
  while (hduByNum != endOfList)
  {
          if ((*hduByNum).second->index() == i) break;
          ++hduByNum;
  }
  
  if (hduByNum == endOfList) 
  {
#ifndef HAVE_SSTREAM
       std::strstream msg;
#else
       std::ostringstream msg;
#endif
       msg << "No HDU with index " << i << '\n';
       throw NoSuchHDU(msg.str());
  }
  (*hduByNum).second->makeThisCurrent();
  return *((*hduByNum).second);   
  }

  ostream & FITS::put (ostream &s) const
  {
  s << "FITS:: Primary HDU: \n" ;
  
  s << *m_FITSImpl->pHDU() << endl;

  s << "FITS:: Extensions: \n";
  
  const ExtMap& ext = m_FITSImpl->extension();
  ExtMapConstIt endOfList = ext.end();
  
  for (ExtMapConstIt it = ext.begin();
       it != endOfList;
       ++it)
     s << *((*it).second) << endl;

  return s;

  }

  fitsfile*& FITS::fitsPointer () const
  {

    return m_FITSImpl->fptr();
  }

  ExtHDU& FITS::extension (int i)
  {
  ExtMap& ext = m_FITSImpl->extension();
  ExtMapIt hduByNum = ext.begin();
  ExtMapIt endOfList = ext.end();
  
  while (hduByNum != endOfList)
  {
     if ((*hduByNum).second->index() == i)  break;
     ++hduByNum;     
  }

  if (hduByNum == endOfList) 
  {
#ifndef HAVE_SSTREAM
       std:: strstream msg;
#else
       std::ostringstream msg;
#endif
       msg << "No HDU with index " << i;
       throw NoSuchHDU(msg.str());
  }
  (*hduByNum).second->makeThisCurrent();
  return *((*hduByNum).second);    
  }

  const ExtHDU& FITS::extension (const string& hduName, int version) const
  {
   
  return extbyVersion(hduName,version);
  }

  const PHDU& FITS::pHDU () const
  {

    return *m_FITSImpl->pHDU();
  }

  PHDU& FITS::pHDU ()
  {

    return *m_FITSImpl->pHDU();
  }

  ExtHDU& FITS::extbyVersion (const string& hduName, int version) const
  {
  // hey! remember it's a multimap and we need to work a little harder!
  // first, for convenience...
  // how many extensions with name hduName?
  ExtMap& ext = m_FITSImpl->extension();        
  ExtMap::size_type n = ext.count(hduName);
 
  if (n == 0) 
  {
#ifndef HAVE_SSTREAM
       std::strstream msg;
#else
       std::ostringstream msg;
#endif
       msg << "No HDU with name " << hduName;
       if (version) msg << " and version " << version;
       throw NoSuchHDU(msg.str());
  }
  
  // ignore version checking if there is only one version present.
        ExtMapIt c = ext.lower_bound(hduName);
        if ( n > 1)
        {
             ExtMapIt last = ext.upper_bound(hduName);
             while ( c != last )
             {
                    if ((*c).second->version() == version) break;
                    c++;
             }
             if ( c == last )
             {
#ifndef HAVE_SSTREAM
                 std::ostrstream msg;
#else
                 std::ostringstream msg;
#endif
                 msg << "No HDU with name " << hduName;
                 if (version != 1) msg << " and version " << version;
                 throw NoSuchHDU(msg.str());
             }
        }
        (*c).second->makeThisCurrent();
        return *((*c).second);
  }

  void FITS::pHDU (PHDU* value)
  {
    m_FITSImpl->pHDU() = value;

  }

  void FITS::read (int hduIndex, bool readDataFlag, const std::vector<string> &keys)
  {
         HDUCreator create(m_FITSImpl);
   
        try
        {
                int status = 0;
                int totalHDUs = 1;
                if (fits_get_num_hdus(m_FITSImpl->fptr(),&totalHDUs,&status) != 0) 
                        throw FitsError(status);
                else
                {
                        if (hduIndex < 0 || hduIndex > totalHDUs) 
                        {
#ifndef HAVE_SSTREAM
			        std::ostrstream diags;
#else
                                std::ostringstream diags;
#endif
                                diags << "Invalid HDU number " << hduIndex <<
                                  " requested from FITS file " << m_FITSImpl->name();
                                throw NoSuchHDU(diags.str());
                        }
                        if (hduIndex == 0) 
                        {
                                std::cerr << 
                                   "Primary header is always read, doesn't need to be requested" << endl;   
                                return;
                        }
                }   
                addExtension(static_cast<ExtHDU*>(create.getHdu(hduIndex, readDataFlag, keys)));
        }
        catch ( ... )
        {
                // catch this one and rethrow.
#ifndef HAVE_SSTREAM
	        std::ostrstream msg;
#else
                std::ostringstream msg;
#endif
                msg << "Error: Could not read extension: " << hduIndex;
                throw NoSuchHDU(msg.str());
        }
  }

  void FITS::readExtensions (bool readDataFlag)
  {
   HDUCreator create(m_FITSImpl);
   int status = 0;
   int numHDUs = 0;
      
   if (fits_get_num_hdus(m_FITSImpl->fptr(),&numHDUs,&status) != 0) throw FitsError(status);

   // Not clearly exception safe : revisit!!!
      
   // Unused:   ExtHDU* newExt = 0;
   // there's one less Extension than HDUs. Here, if there are 5 HDUs there are 4 extensions,
   // and this loop should execute 4 times. HDU index 1 is the first extension, not the primary.
   for (int i = 1; i < numHDUs ; i++)
   {
       addExtension(static_cast<ExtHDU*>(create.getHdu(i,readDataFlag)));
       create.reset();
   }
  }

  Table* FITS::addTable (string& hduName, int rows, const std::vector<string>& columnName, const std::vector<string>& columnFmt, const std::vector<string>& columnUnit, HduType type, int version)
  {
    // use std::auto_ptr<T> to make ownership explicit.
   HDUCreator newTable(m_FITSImpl);
   Table* newHDU = static_cast<Table*>(newTable.createTable(hduName, type, rows,
                                                 columnName, columnFmt,  columnUnit, version));   
   return static_cast<Table*>(addExtension(newHDU));
  }

  ExtHDU* FITS::addImage (const string& hduName, int bpix, std::vector<long>& naxes, int version)
  {
   HDUCreator newImage(m_FITSImpl);
   ExtHDU* newHDU = newImage.createImage(hduName, bpix, naxes.size(), naxes,  version);  
   return addExtension(newHDU);
  }

  void FITS::destroy () throw ()
  {
        // close the file associated with this FITS object if it is open.
        // close () can't throw because it only calls cfitsio's close function,
        // so error messages are handled here.
        // destroyPrimary and destroyExtensions call delete which is guaranteed nothrow,
        // destroyExtensions also calls multimap::erase
        close();

        // nullify and delete memory allocated for  primary HDU pointer
        // delete memory allocated for Extensions and clear the map.
        delete m_FITSImpl;
        // nullify the fitsfile pointer, so that it passes "deallocated" tests
        // such as: if ( x.fptr() == 0 )
        m_FITSImpl = 0;
  }

  void FITS::flush ()
  {
    int status (0);
    if (fits_flush_file(m_FITSImpl->fptr(),&status)) throw FitsError(status);
  }

  const string& FITS::currentExtensionName () const
  {

    return m_FITSImpl->currentExtensionName();
  }

  ExtHDU* FITS::addExtension (ExtHDU* ext)
  {
   int status(0);
   string& extName = ext->name();
   ExtMap::value_type addHDUEntry(extName,ext);
   m_FITSImpl->currentExtensionName() = extName;
   ExtMapIt added = m_FITSImpl->extension().insert(addHDUEntry);
   if (fits_set_hdustruc(fitsPointer(),&status)) throw FitsError(status);
   (*added).second->index(fitsPointer()->HDUposition);
   return (*added).second;
  }

  void FITS::read (const std::vector<string>& searchKeys, const std::vector<string> &searchValues, bool readDataFlag, const std::vector<string>& hduKeys, int version)
  {
  int totalHDUs = 1;
  int status = 0;
  if (fits_get_num_hdus(m_FITSImpl->fptr(),&totalHDUs,&status) != 0) throw FitsError(status);
  HDUCreator createTest(m_FITSImpl);
 
  int hduIndex;
  // there's one less extension than total HDUs!
  bool gotIt = false;
  for  (hduIndex = 1; hduIndex < totalHDUs; hduIndex++ )
  {
     try
     {
        std::auto_ptr<ExtHDU> 
	  testHDU(static_cast<ExtHDU*>(createTest.getHdu(hduIndex,false,searchKeys)));
	// if the keyword was not present, getKeywordValue will
	// throw a NoSuchKeyword.
	std::vector<string> testKeys(searchKeys);
	std::vector<string> testResults(searchKeys.size(),"");
	testHDU->readKeys(testKeys,testResults); 
        using namespace FITSUtil;
                     
	// first: we need to have matched as many keys as were input.
                     
	if (testKeys.size() == searchKeys.size()) 
	{
	   // now go through and check the values that were read
	   // against the input value list.
	   size_t k = 0;
	   gotIt = true;   
           std::vector<string>::const_iterator vi(searchValues.begin());   
          std::vector<string>::const_iterator  viEnd(searchValues.end());   
                
           while (vi != viEnd && gotIt)
	   {

	      if (vi->length())
	      {
                   // we can at least ignore whitespace
                   size_t first (testResults[k].find_first_not_of(" \t"));
                   size_t last  (testResults[k].find_last_not_of(" \t"));
		   gotIt = (lowerCase(testResults[k].substr(first,last+first+1)) == lowerCase(*vi));
	      }
              ++k,++vi;
	   }
                        
	   if (gotIt)
	   {
	      if (version == 1) break;
	      else
	      {
		 int extver = 1;
#ifdef TEMPLATE_AMBIG_DEFECT
		 testHDU->readKeyMS("EXTVER",extver);
#else
		 testHDU->readKey("EXTVER",extver);                                        
#endif
		 if (extver == version) break;
		 else gotIt = false;
	      }
	   }
	}
     }

     catch (HDU::NoSuchKeyword)
     {
        // catches the case where the version is requested but there
        // is no version key present.
        continue;
     }

     catch (FitsError)
     {                
        continue;       
     }

     catch (...)
     {
        throw;
     }

     createTest.reset();        
  }
     
  if (gotIt)
  {
     string extname("");
     int extver = 0;
     ExtHDU::readHduName(m_FITSImpl->fptr(),hduIndex,extname,extver);
     read(extname,readDataFlag,hduKeys,extver);
     currentExtensionName(extname);
  }
     
  else
  {
#ifndef HAVE_SSTREAM
     std::ostrstream err;
#else
     std::ostringstream err;
#endif
      err << "Error: Unable to find extension containing keywords ";
      std::copy(searchKeys.begin(),searchKeys.end(),
		std::ostream_iterator<string>(err," "));
      err << "\nwith required values and version number ";	
      throw NoSuchHDU(err.str());
  }     
  }

  void FITS::swap (FITS& right)
  {
    FITSUtil::swap(m_FITSImpl,right.m_FITSImpl);
  }

  const std::multimap<string,ExtHDU*>& FITS::extension () const
  {

    return m_FITSImpl->extension();
  }

  void FITS::resetPosition ()
  {
    int status(0);
    if (fits_movabs_hdu(fitsPointer(),1,0,&status)) throw FitsError(status);
  }

  void FITS::currentExtensionName (const string& extName)
  {
    m_FITSImpl->currentExtensionName() = extName;

  }

  const string& FITS::name () const
  {

    return m_FITSImpl->name();
  }

  fitsfile*& FITS::fitsPointer ()
  {

    return m_FITSImpl->fptr();
  }

  void FITS::copy (const HDU& source)
  {
    int status(0);
    
    source.makeThisCurrent();
    
    if (fits_copy_hdu(source.fitsPointer(),fitsPointer(),0,&status)) 
                throw FitsError(status);      
          
    // the fits file has been updated, although the data have not 
    // been read.
      
          
  }

  Table& FITS::filter (const string& expression, ExtHDU& inputTable, bool overwrite, bool readData)
  {
    
    // there are three cases to deal with:
    // a) inputHDU belongs to a different file than *this  
    //    In this case the selectRows call will simply write to this.
    // b) inputHDU belongs to *this and
    //     i) outHDUVersion is different from any version key in inputHDU.
    //     ii) outHDUVersion matches the version key in inputHDU or neither
    //         inputHDU has a version key nor outHDUVersion is specified.
    
    // In case i) a new HDU with new version is written.
    // In case ii) the instruction is to overwrite inputHDU with the filtered version.
    // in this case the HDU is marked as "unread" by deleting it from the list of
    // HDUs in *this.
       static char EXTVER[] = "EXTVER";
       
           
       try
       {
               Table& table = dynamic_cast<Table&>(inputTable);
               fitsfile* inputFitsPointer = inputTable.fitsPointer() ;
               FITSUtil::auto_array_ptr<char> pName1(new char[FLEN_FILENAME]);
               FITSUtil::auto_array_ptr<char> pName2(new char[FLEN_FILENAME]);
               string tableName = table.name();
               int tableVersion(table.version());
               char* cExpression = const_cast<char*>(expression.c_str());
               int status(0);
               
               
               // check if the two file names are the same. Checking the pointers
               // are the same doesn't allow for the possibility that there are
               // two views of the same file.
               if (fits_file_name(inputFitsPointer,pName1.get(),&status)) throw FitsError(status);
               if (fits_file_name(fitsPointer(),pName2.get(),&status)) throw FitsError(status);
               const string& infile = string(pName1.get());
               const string& outfile = string(pName2.get());

               // store list of what has been read so far so it can be read back.
               std::vector<string> 
                    keyStore(table.keyWord().size() + table.column().size());

               std::map<string,Keyword*>::const_iterator keyIt(table.keyWord().begin());
               std::map<string,Keyword*>::const_iterator keyItEnd(table.keyWord().end());
               std::map<string,Column*>::const_iterator colIt(table.column().begin());
               std::map<string,Column*>::const_iterator colItEnd(table.column().end());

               size_t count(0);
               if (!table.keyWord().empty())
               {
                        while ( keyIt != keyItEnd )
                        {
                                keyStore[count] = (*keyIt).first;       
                                ++keyIt, ++count;
                        }
               }
               
               if ( !table.column().empty())
               {
                        while ( colIt != colItEnd )
                        {

                                keyStore[count] = (*colIt).first;       
                                ++colIt, ++count;
                        }
               }
               int revisedVersion(tableVersion);
               if (infile ==  outfile)
               {
                       if (overwrite)
                       {
                                // delete the current HDU from the set of "mapped"
                                // since the contents are being changed. Its header
                                // will be remapped afterward, and if readData is
                                // set to true then the resulting filtered data is
                                // also read back.
                                unmapExtension(inputTable);
                       }
                       else
                       {
                                revisedVersion = nextVersionNumber(tableName);   
                                // create a new header from the source and set it to be the
                                // current HDU
                                cloneHeader(inputTable);
                                if (fits_write_key_lng(fitsPointer(),EXTVER,revisedVersion,0,&status)) 
                                        throw FitsError(status);
                       }

                       if (fits_select_rows(inputFitsPointer,fitsPointer(),cExpression,&status))
                            throw FitsError(status);
                       if (fits_flush_file(fitsPointer(),&status)) throw FitsError(status);

               }
               else
               {
                       // create a new header from the source and set it to be the
                       // current HDU
                       revisedVersion = nextVersionNumber(tableName);
                       cloneHeader(inputTable);
                       
                       if (fits_select_rows(inputFitsPointer,fitsPointer(),cExpression,&status))
                            throw FitsError(status);       
           
                       if (fits_write_key_lng(fitsPointer(),EXTVER,revisedVersion,0,&status)) 
                               throw FitsError(status);
                       if (fits_flush_file(fitsPointer(),&status)) throw FitsError(status);

               }


               HDUCreator create(m_FITSImpl); 
               ExtHDU* readBack 
                = static_cast<ExtHDU*>(create.getHdu(tableName,readData,keyStore,
                                false,revisedVersion)); 
               return static_cast<Table&>(*addExtension(readBack)); 
       }
       catch (std::bad_cast)
       {
               throw OperationNotSupported(" filtering rows from an image ");       
       }
       
       // output 

    
    
  }

  std::multimap<string,ExtHDU*>& FITS::extension ()
  {

    return m_FITSImpl->extension();
  }

  ExtHDU& FITS::currentExtension ()
  {
    // return the current extension. Must have been previously instantiated by
    // CCfits.
    int num(0);
    fits_get_hdu_num(fitsPointer(),&num);
    // extensions start counting at 1, HDU indices at 2.
    return extension(num - 1);
  }

  string FITS::nameOfUnmapped (int hduNum) const
  {
          
    // return the name of HDUs not yet mapped.    
          
    static char EXTNAME[] = "EXTNAME";
    static char HDUNAME[] = "HDUNAME";
    string retVal("");
    int current(0);
    int status(0);
    fits_get_hdu_num(fitsPointer(),&current);
    if (fits_movabs_hdu(fitsPointer(),hduNum,0,&status)) throw FitsError(status);
    
    FITSUtil::auto_array_ptr<char> pTestKey(new char[FLEN_VALUE]);
    char* testKey = pTestKey.get();
    
    if (fits_read_key_str(fitsPointer(),EXTNAME,testKey,0,&status) == 0)
    {
            retVal = string(testKey);
    }
    else 
    {   
        if (status == KEY_NO_EXIST)
        {
                status = 0;
                fits_read_key_str(fitsPointer(),HDUNAME,testKey,0,&status) ;
                if (status == 0) 
                {
                        retVal = string(testKey);
                }
                else 
                {
                        if (status != KEY_NO_EXIST) throw FitsError(status);
                }
        }
        else 
        {
                throw FitsError(status);
        }
    }
    if (fits_movabs_hdu(fitsPointer(),current,0,&status)) throw FitsError(status);
        
    return retVal;
    
  }

  void FITS::cloneHeader (const ExtHDU& source)
  {
    // raw copy header info from source to a new HDU in *this.
          
    // first,
    // check that source is current HDU in whichever file it is
    source.makeThisCurrent();
    
    fitsfile* sourcePointer = source.fitsPointer();
    int nKeys(0);
    int dum(0);
    int status(0);
    
    
    // get number of keys in source HDU.
    // don't care what key will be read next, so keynum argument is dummy.
    if (fits_get_hdrpos(sourcePointer,&nKeys,&dum,&status)) throw FitsError(status);
    FITSUtil::auto_array_ptr<char> pCard(new char[FLEN_CARD]);
    char* card = pCard.get();
  
    // Must copy the keys of the source before creating the new HDU
    // because one cannot movabs to a raw HDU created by create_hdu:
    // the required keywords are not there and it returns an error.
    if (sourcePointer == fitsPointer())
    {
        std::vector<string> cards(nKeys);
        {     
                for (int j = 1; j <= nKeys; ++j)
                {
                        if (fits_read_record(sourcePointer,j,card,&status)) throw FitsError(status);  
                        cards[j-1] = string(card);     
                }
        }      
    // fits_create_hdu makes a new HDU and makes it current.
        if (fits_create_hdu(fitsPointer(),&status)) throw FitsError(status);
        {
                for (int j = 1; j <= nKeys; ++j)
                {
                        if (fits_write_record(fitsPointer(),cards[j-1].c_str(),&status)) 
                                                                        throw FitsError(status);       
                }
        }  
    }
  
    
    else
    {
        if (fits_create_hdu(fitsPointer(),&status)) throw FitsError(status);
        for (int j = 1; j <= nKeys; ++j)
        {
                if (fits_read_record(sourcePointer,j,card,&status)) 
                        throw FitsError(status);       
                if (fits_write_record(fitsPointer(),card,&status)) 
                        throw FitsError(status);       
        }
    }
    // set the number of rows NAXIS2 in the new HDU back to zero - 
    // it's been raw copied from source.
    
    static char ROWS[] = "NAXIS2";
    if (fits_update_key_lng(fitsPointer(),ROWS,0,0,&status)) throw FitsError(status);
    if (fits_flush_file(fitsPointer(),&status)) throw FitsError(status);
  }

  void FITS::deleteExtension (int doomed)
  {
    int status(0);
    ExtHDU& d = extension(doomed); // throws NoSuchHDU if it's not there.
    if (fits_delete_hdu(fitsPointer(),0,&status)) throw FitsError(status);
    unmapExtension(d);
  }

  // Additional Declarations

} // namespace CCfits

