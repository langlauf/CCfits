//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%37FE40B76648.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%37FE40B76648.cm

//## begin module%37FE40B76648.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%37FE40B76648.cp

//## Module: FITS%37FE40B76648; Package body
//## Subsystem: CCfits::FITS%393411910327
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/FITS.cxx

//## begin module%37FE40B76648.additionalIncludes preserve=no
//## end module%37FE40B76648.additionalIncludes

//## begin module%37FE40B76648.includes preserve=yes
//## end module%37FE40B76648.includes

// Table
#include "Table.h"
// PHDU
#include "PHDU.h"
// FITSBase
#include "FITSBase.h"
// PrimaryHDU
#include "PrimaryHDU.h"
// FITS
#include "FITS.h"


//## begin module%37FE40B76648.declarations preserve=no
//## end module%37FE40B76648.declarations

//## begin module%37FE40B76648.additionalDeclarations preserve=yes
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

using std::endl;
using std::cout;
using std::cerr;

#include <memory>
//## end module%37FE40B76648.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  // Class CCfits::FITS::NoSuchHDU 

  FITS::NoSuchHDU::NoSuchHDU (const String& diag, bool silent)
    //## begin CCfits::FITS::NoSuchHDU::NoSuchHDU%396C908003D3.hasinit preserve=yes
  : FitsException("FITS Error: Cannot read HDU in FITS file:",silent)
    //## end CCfits::FITS::NoSuchHDU::NoSuchHDU%396C908003D3.hasinit
    //## begin CCfits::FITS::NoSuchHDU::NoSuchHDU%396C908003D3.initialization preserve=yes
    //## end CCfits::FITS::NoSuchHDU::NoSuchHDU%396C908003D3.initialization
  {
    //## begin CCfits::FITS::NoSuchHDU::NoSuchHDU%396C908003D3.body preserve=yes
  //! Exception to be thrown by failed seek operations
  if ( FITS::verboseMode() || !silent) std::cerr << diag << "\n";
    //## end CCfits::FITS::NoSuchHDU::NoSuchHDU%396C908003D3.body
  }


  // Class CCfits::FITS::OperationNotSupported 

  FITS::OperationNotSupported::OperationNotSupported (const String& msg, bool silent)
    //## begin CCfits::FITS::OperationNotSupported::OperationNotSupported%39806C3302FE.hasinit preserve=yes
  : FitsException("FITS Error: Operation not supported:",silent)
    //## end CCfits::FITS::OperationNotSupported::OperationNotSupported%39806C3302FE.hasinit
    //## begin CCfits::FITS::OperationNotSupported::OperationNotSupported%39806C3302FE.initialization preserve=yes
    //## end CCfits::FITS::OperationNotSupported::OperationNotSupported%39806C3302FE.initialization
  {
    //## begin CCfits::FITS::OperationNotSupported::OperationNotSupported%39806C3302FE.body preserve=yes
    if ( FITS::verboseMode() || !silent)  std::cerr << msg << "\n";
    //## end CCfits::FITS::OperationNotSupported::OperationNotSupported%39806C3302FE.body
  }


  // Class CCfits::FITS::CantOpen 

  FITS::CantOpen::CantOpen (const String& diag, bool silent)
    //## begin CCfits::FITS::CantOpen::CantOpen%39C8E9FA01BA.hasinit preserve=yes
   : FitsException("FITS Error: Cannot open file ",silent)
    //## end CCfits::FITS::CantOpen::CantOpen%39C8E9FA01BA.hasinit
    //## begin CCfits::FITS::CantOpen::CantOpen%39C8E9FA01BA.initialization preserve=yes
    //## end CCfits::FITS::CantOpen::CantOpen%39C8E9FA01BA.initialization
  {
    //## begin CCfits::FITS::CantOpen::CantOpen%39C8E9FA01BA.body preserve=yes
    if ( FITS::verboseMode() || !silent)  std::cerr << diag << "\n";
    //## end CCfits::FITS::CantOpen::CantOpen%39C8E9FA01BA.body
  }


  // Class CCfits::FITS::CantCreate 

  FITS::CantCreate::CantCreate (const String& diag, bool silent)
    //## begin CCfits::FITS::CantCreate::CantCreate%39C8EA2C01E0.hasinit preserve=yes
   : FitsException(string("FITS Error: Cannot create file "),silent)
    //## end CCfits::FITS::CantCreate::CantCreate%39C8EA2C01E0.hasinit
    //## begin CCfits::FITS::CantCreate::CantCreate%39C8EA2C01E0.initialization preserve=yes
    //## end CCfits::FITS::CantCreate::CantCreate%39C8EA2C01E0.initialization
  {
    //## begin CCfits::FITS::CantCreate::CantCreate%39C8EA2C01E0.body preserve=yes
  if ( FITS::verboseMode() || !silent) std::cerr << diag << '\n';
    //## end CCfits::FITS::CantCreate::CantCreate%39C8EA2C01E0.body
  }


  // Class CCfits::FITS 

  //## begin CCfits::FITS::verboseMode%39AA762B03E3.attr preserve=no  public: static bool {V} false
  bool FITS::s_verboseMode = false;
  //## end CCfits::FITS::verboseMode%39AA762B03E3.attr

  FITS::FITS(const FITS &right)
    //## begin FITS::FITS%37FE367A41D0_copy.hasinit preserve=yes
    : m_FITSImpl(right.m_FITSImpl->clone())
    //## end FITS::FITS%37FE367A41D0_copy.hasinit
    //## begin FITS::FITS%37FE367A41D0_copy.initialization preserve=yes
    //## end FITS::FITS%37FE367A41D0_copy.initialization
  {
    //## begin CCfits::FITS::FITS%37FE367A41D0_copy.body preserve=yes
    //## end CCfits::FITS::FITS%37FE367A41D0_copy.body
  }

  FITS::FITS (const String &name, RWmode mode, bool readDataFlag, const std::vector<String>& primaryKeys)
    //## begin CCfits::FITS::FITS%38D292027BA0.hasinit preserve=yes
  : m_FITSImpl(new FITSBase(name,mode))
    //## end CCfits::FITS::FITS%38D292027BA0.hasinit
    //## begin CCfits::FITS::FITS%38D292027BA0.initialization preserve=yes
    //## end CCfits::FITS::FITS%38D292027BA0.initialization
  {
    //## begin CCfits::FITS::FITS%38D292027BA0.body preserve=yes
 


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
    //## end CCfits::FITS::FITS%38D292027BA0.body
  }

  FITS::FITS (const String &name, RWmode mode, const string &hduName, bool readDataFlag, const std::vector<String>& hduKeys, const std::vector<String>& primaryKey, int version)
    //## begin CCfits::FITS::FITS%38D2918EBC78.hasinit preserve=yes
  : m_FITSImpl(new FITSBase(name,mode))
    //## end CCfits::FITS::FITS%38D2918EBC78.hasinit
    //## begin CCfits::FITS::FITS%38D2918EBC78.initialization preserve=yes
    //## end CCfits::FITS::FITS%38D2918EBC78.initialization
  {
    //## begin CCfits::FITS::FITS%38D2918EBC78.body preserve=yes
          open(mode);

          // create and read the Primary: assume here that a single HDU other than
          // the primary is requested, so don't read primary data. We can however
          // read some header info from the primary if (optionally) specified.

          read(false,primaryKey);

          // create a primary header in the receiving structure.
          // PHDU has a private constructor and must be instantiated here only.
          // this ensures that every FITS object has exactly one PHDU

          read(hduName, readDataFlag, hduKeys,version);
    //## end CCfits::FITS::FITS%38D2918EBC78.body
  }

  FITS::FITS (const String &name, RWmode mode, const std::vector<String>& hduNames, bool readDataFlag, const std::vector<String>& primaryKey)
    //## begin CCfits::FITS::FITS%38D290450D98.hasinit preserve=yes
  : m_FITSImpl(new FITSBase(name,mode))
    //## end CCfits::FITS::FITS%38D290450D98.hasinit
    //## begin CCfits::FITS::FITS%38D290450D98.initialization preserve=yes
    //## end CCfits::FITS::FITS%38D290450D98.initialization
  {
    //## begin CCfits::FITS::FITS%38D290450D98.body preserve=yes

        open(mode);

        read(readDataFlag,primaryKey);
        read(hduNames,readDataFlag);

    //## end CCfits::FITS::FITS%38D290450D98.body
  }

  FITS::FITS (const String& fileName, const FITS& source)
    //## begin CCfits::FITS::FITS%3B38A690017E.hasinit preserve=yes
    : m_FITSImpl(new FITSBase(fileName,Write))
    //## end CCfits::FITS::FITS%3B38A690017E.hasinit
    //## begin CCfits::FITS::FITS%3B38A690017E.initialization preserve=yes
    //## end CCfits::FITS::FITS%3B38A690017E.initialization
  {
    //## begin CCfits::FITS::FITS%3B38A690017E.body preserve=yes
          
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
  
    //## end CCfits::FITS::FITS%3B38A690017E.body
  }

  FITS::FITS (const String &name, RWmode mode, const std::vector<String>& hduNames, const std::vector<std::vector<String> >& hduKeys, bool readDataFlag, const std::vector<String>& primaryKeys, const std::vector<int>& hduVersions)
    //## begin CCfits::FITS::FITS%37FE3AFC2620.hasinit preserve=yes
  : m_FITSImpl(new FITSBase(name,mode))
    //## end CCfits::FITS::FITS%37FE3AFC2620.hasinit
    //## begin CCfits::FITS::FITS%37FE3AFC2620.initialization preserve=yes
    //## end CCfits::FITS::FITS%37FE3AFC2620.initialization
  {
    //## begin CCfits::FITS::FITS%37FE3AFC2620.body preserve=yes
          
          open(mode);


          // read the primary header and read the data if readDataFlag is set.
          // create returns a PHDU if the index is 0.

          read(readDataFlag,primaryKeys);



          // create a primary header in the receiving structure.
          // PHDU has a private constructor and must be instantiated here only.
          // this ensures that every FITS object has exactly one PHDU

          read(hduNames, hduKeys, readDataFlag, hduVersions);
    //## end CCfits::FITS::FITS%37FE3AFC2620.body
  }

  FITS::FITS (const String& name, int bitpix, int naxis, long *naxes)
    //## begin CCfits::FITS::FITS%38454495F730.hasinit preserve=yes
  : m_FITSImpl(new FITSBase(name,Write))
    //## end CCfits::FITS::FITS%38454495F730.hasinit
    //## begin CCfits::FITS::FITS%38454495F730.initialization preserve=yes
    //## end CCfits::FITS::FITS%38454495F730.initialization
  {
    //## begin CCfits::FITS::FITS%38454495F730.body preserve=yes

        std::vector<long>    va_naxes(naxis);
        std::copy(&naxes[0],&naxes[naxis],va_naxes.begin());
  
        create();
  
        // create an HDU factory.
        HDUCreator makePrimary(m_FITSImpl);
  
        // set the PrimaryHDU. bitpix will determine the data type.
        pHDU(makePrimary.createImage(bitpix,naxis,va_naxes));
    //## end CCfits::FITS::FITS%38454495F730.body
  }

  FITS::FITS (const string &name, RWmode mode, int hduIndex, bool readDataFlag, const std::vector<String>& hduKeys, const std::vector<String>& primaryKey)
    //## begin CCfits::FITS::FITS%395B856A00D9.hasinit preserve=yes
  : m_FITSImpl(new FITSBase(name,mode))
    //## end CCfits::FITS::FITS%395B856A00D9.hasinit
    //## begin CCfits::FITS::FITS%395B856A00D9.initialization preserve=yes
    //## end CCfits::FITS::FITS%395B856A00D9.initialization
  {
    //## begin CCfits::FITS::FITS%395B856A00D9.body preserve=yes

        open(mode);
        // read the primary header. Allowing the user to read the primary data
        // and optional keys costs nothing here, although the likely use of this
        // constructor is to read a specified HDU from a file other than the Primary.
        read(readDataFlag,primaryKey);
  
        read(hduIndex,readDataFlag,hduKeys);
  
    //## end CCfits::FITS::FITS%395B856A00D9.body
  }

  FITS::FITS (const String &name, RWmode mode, const std::vector<String>& searchKeys, const std::vector<String> &searchValues, bool readDataFlag, const std::vector<String>& hduKeys, const std::vector<String>& primaryKey, int version)
    //## begin CCfits::FITS::FITS%39B562CD0158.hasinit preserve=yes
  : m_FITSImpl(new FITSBase(name,mode))
    //## end CCfits::FITS::FITS%39B562CD0158.hasinit
    //## begin CCfits::FITS::FITS%39B562CD0158.initialization preserve=yes
    //## end CCfits::FITS::FITS%39B562CD0158.initialization
  {
    //## begin CCfits::FITS::FITS%39B562CD0158.body preserve=yes
          
        open(mode);

        // read the primary header and read the data if readDataFlag is set.
        // create returns a PHDU if the index is 0.
   
        read(false,primaryKey);
   

        // create a primary header in the receiving structure.
        // PHDU has a private constructor and must be instantiated here only.
        // this ensures that every FITS object has exactly one PHDU

        read(searchKeys, searchValues, readDataFlag, hduKeys, version);
    //## end CCfits::FITS::FITS%39B562CD0158.body
  }


  FITS::~FITS()
  {
    //## begin CCfits::FITS::~FITS%37FE367A41D0_dest.body preserve=yes
    destroy();      
    //## end CCfits::FITS::~FITS%37FE367A41D0_dest.body
  }



  //## Other Operations (implementation)
  void FITS::unmapExtension (ExtHDU& doomed)
  {
    //## begin CCfits::FITS::unmapExtension%3B3B4E550101.body preserve=yes
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
    //## end CCfits::FITS::unmapExtension%3B3B4E550101.body
  }

  void FITS::clearErrors ()
  {
    //## begin CCfits::FITS::clearErrors%3B66F73A007C.body preserve=yes
    fits_clear_errmsg();
    //## end CCfits::FITS::clearErrors%3B66F73A007C.body
  }

  void FITS::deleteExtension (const String& doomed, int version)
  {
    //## begin CCfits::FITS::deleteExtension%3B66F795013E.body preserve=yes
    int status(0);
    ExtHDU& d = extension(doomed,version); // throws NoSuchHDU if it's not there.
    if (fits_delete_hdu(fitsPointer(),0,&status)) throw FitsError(status);
    unmapExtension(d);
    //## end CCfits::FITS::deleteExtension%3B66F795013E.body
  }

  int FITS::nextVersionNumber (const String& inputName) const
  {
    //## begin CCfits::FITS::nextVersionNumber%3B3B79F50084.body preserve=yes
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
    //## end CCfits::FITS::nextVersionNumber%3B3B79F50084.body
  }

  void FITS::read (bool readDataFlag, const std::vector<String>& keys)
  {
    //## begin CCfits::FITS::read%38D298347AE8.body preserve=yes

   HDUCreator create(m_FITSImpl);
   
   
   pHDU(static_cast<PHDU*>(create.getHdu(0,readDataFlag,keys)));

    //## end CCfits::FITS::read%38D298347AE8.body
  }

  void FITS::read (const String &hduName, bool readDataFlag, const std::vector<String> &keys, int version)
  {
    //## begin CCfits::FITS::read%387DD1011578.body preserve=yes
        // grab the requested extension if present. If not, create an ExtHDU object and add it, if it
        // exists in the file. The first clause copes with the results from the ctor that reads the 
        // entire file for HDUs, the second when adding a new HDU from a file which selected HDUs were
        // read on construction.
        ExtMap& ext = m_FITSImpl->extension();        
        ExtMap::size_type n = ext.count(hduName);

         
        if ( n > 0 )
        {
                std::pair<ExtMap::iterator,ExtMap::iterator> r 
                                        = m_FITSImpl->extension().equal_range(hduName);
                 ExtHDU* requested(0);
                 if (version == 1)
                 {
                         requested = (r.first)->second;
                 } 
                 else 
                 {
                       for (ExtMap::iterator i = r.first; i != r.second; ++i)
                       {
                                if ( i->second->version() == version )
                                {
                                        requested = i->second;
                                        break;
                                }       
                       }                      
                       if (!requested)
                       {
                               std::ostringstream msg;
                               msg  << hduName << " with version " << version;
                               throw NoSuchHDU(msg.str());
                       } 
                 }
                 requested->readData(readDataFlag,keys);
                 
        }
        else
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
          
 
    //## end CCfits::FITS::read%387DD1011578.body
  }

  void FITS::read (const std::vector<String> &hduNames, bool readDataFlag)
  {
    //## begin CCfits::FITS::read%387DFBA281E0.body preserve=yes
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


    //## end CCfits::FITS::read%387DFBA281E0.body
  }

  void FITS::read (const std::vector<String> &hduNames, const std::vector<std::vector<String> > &keys, bool readDataFlag, const std::vector<int>& hduVersions)
  {
    //## begin CCfits::FITS::read%38D2944902F0.body preserve=yes

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

    //## end CCfits::FITS::read%38D2944902F0.body
  }

  void FITS::open (RWmode mode)
  {
    //## begin CCfits::FITS::open%380B3C3FACA8.body preserve=yes
  int status=0;
  // unused:  bool silentMode = true;

  status = fits_open_file(&m_FITSImpl->fptr(), m_FITSImpl->name().c_str(), mode, &status);

  if (status != 0)  
  {
          if (status == FILE_NOT_OPENED) throw CantOpen(m_FITSImpl->name()); 
          else throw FitsError(status);
  }

    //## end CCfits::FITS::open%380B3C3FACA8.body
  }

  bool FITS::create ()
  {
    //## begin CCfits::FITS::create%383424B67D30.body preserve=yes

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

          // create a new file.
	  // the '!' is processed by ffinit
          fits_create_file(&m_FITSImpl->fptr(),fName.c_str(),&status);
          if ( status )
          {
                  try
                  {
                          if (status == FILE_NOT_CREATED ) 
                          {
                                  string warn(" File already exists: ");
                                  warn += fName;
                                  warn += " attempting to open existing file";
                                  if (verboseMode()) std::cerr << warn << '\n';
                                  open(Write);
                          }
                  }
                  catch (FitsException&) {} 
                  return false;
          }
          return true; 
    //## end CCfits::FITS::create%383424B67D30.body
  }

  int FITS::close () throw ()
  {
    //## begin CCfits::FITS::close%380B3C655888.body preserve=yes
  int   status=0;
  if (m_FITSImpl == 0) return 0;

  status = fits_close_file(m_FITSImpl->fptr(), &status);
  return status;
    //## end CCfits::FITS::close%380B3C655888.body
  }

  FITS * FITS::clone () const
  {
    //## begin CCfits::FITS::clone%382039362818.body preserve=yes
  return new FITS(*this);
    //## end CCfits::FITS::clone%382039362818.body
  }

  const ExtHDU& FITS::extension (int i) const
  {
    //## begin CCfits::FITS::extension%381F03932200.body preserve=yes

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
#ifdef SSTREAM_DEFECT
       std::strstream msg;
#else
       std::ostringstream msg;
#endif
       msg << "No HDU with index " << i << '\n';
       throw NoSuchHDU(msg.str());
  }
  (*hduByNum).second->makeThisCurrent();
  return *((*hduByNum).second);   
    //## end CCfits::FITS::extension%381F03932200.body
  }

  std::ostream & FITS::put (std::ostream &s) const
  {
    //## begin CCfits::FITS::put%38ECDB29BE30.body preserve=yes
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

    //## end CCfits::FITS::put%38ECDB29BE30.body
  }

  fitsfile*& FITS::fitsPointer () const
  {
    //## begin CCfits::FITS::fitsPointer%394122F101BF.body preserve=yes
    //## end CCfits::FITS::fitsPointer%394122F101BF.body

    return m_FITSImpl->fptr();
  }

  ExtHDU& FITS::extension (int i)
  {
    //## begin CCfits::FITS::extension%39463D1E003A.body preserve=yes
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
#ifdef SSTREAM_DEFECT
       std:: strstream msg;
#else
       std::ostringstream msg;
#endif
       msg << "No HDU with index " << i;
       throw NoSuchHDU(msg.str());
  }
  (*hduByNum).second->makeThisCurrent();
  return *((*hduByNum).second);    
    //## end CCfits::FITS::extension%39463D1E003A.body
  }

  const ExtHDU& FITS::extension (const String& hduName, int version) const
  {
    //## begin CCfits::FITS::extension%39463E9502B8.body preserve=yes
   
  return extbyVersion(hduName,version);
    //## end CCfits::FITS::extension%39463E9502B8.body
  }

  const PHDU& FITS::pHDU () const
  {
    //## begin CCfits::FITS::pHDU%394E7AC8015A.body preserve=yes
    //## end CCfits::FITS::pHDU%394E7AC8015A.body

    return *m_FITSImpl->pHDU();
  }

  PHDU& FITS::pHDU ()
  {
    //## begin CCfits::FITS::pHDU%394E7B9F0063.body preserve=yes
    //## end CCfits::FITS::pHDU%394E7B9F0063.body

    return *m_FITSImpl->pHDU();
  }

  ExtHDU& FITS::extbyVersion (const String& hduName, int version) const
  {
    //## begin CCfits::FITS::extbyVersion%394F892902A0.body preserve=yes
  // hey! remember it's a multimap and we need to work a little harder!
  // first, for convenience...
  // how many extensions with name hduName?
  ExtMap& ext = m_FITSImpl->extension();        
  ExtMap::size_type n = ext.count(hduName);
 
  if (n == 0) 
  {
#ifdef SSTREAM_DEFECT
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
#ifdef SSTREAM_DEFECT
                 std::ostrstream msg;
#else
                 std::ostringstream msg;
#endif
                 msg << "No HDU with name " << hduName;
                 if (version != 1) msg << " and version " << version;
#ifdef SSTREAM_DEFECT
	         msg << std::ends;
#endif         
                 throw NoSuchHDU(msg.str());
             }
        }
        (*c).second->makeThisCurrent();
        return *((*c).second);
    //## end CCfits::FITS::extbyVersion%394F892902A0.body
  }

  void FITS::pHDU (PHDU* value)
  {
    m_FITSImpl->pHDU() = value;

    //## begin CCfits::FITS::pHDU%394FA9D0038C.body preserve=yes
    //## end CCfits::FITS::pHDU%394FA9D0038C.body
  }

  void FITS::read (int hduIndex, bool readDataFlag, const std::vector<String> &keys)
  {
    //## begin CCfits::FITS::read%395B890A0390.body preserve=yes
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
#ifdef SSTREAM_DEFECT
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
#ifdef SSTREAM_DEFECT
	        std::ostrstream msg;
#else
                std::ostringstream msg;
#endif
                msg << "Error: Could not read extension: " << hduIndex;
                throw NoSuchHDU(msg.str());
        }
    //## end CCfits::FITS::read%395B890A0390.body
  }

  void FITS::readExtensions (bool readDataFlag)
  {
    //## begin CCfits::FITS::readExtensions%396CD0CF001A.body preserve=yes
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
    //## end CCfits::FITS::readExtensions%396CD0CF001A.body
  }

  Table* FITS::addTable (const String& hduName, int rows, const std::vector<String>& columnName, const std::vector<String>& columnFmt, const std::vector<String>& columnUnit, HduType type, int version)
  {
    //## begin CCfits::FITS::addTable%3964B05001A2.body preserve=yes
   ExtHDU* current(0);
   size_t N(extension().count(hduName));
   std::pair<ExtMapIt,ExtMapIt> matches(extension().equal_range(hduName));
   if ( N > 0 )
   {
        ExtMapIt s(matches.first);
        while  ( s != matches.second )
        {
                current = s->second;
                if ( current->version() == version && dynamic_cast<Table*>(current) )
                {
                        std::cerr << " Table Extension " << hduName << " with version " 
                                << version << " already exists "
                                << " returning token for existing version \n";
                        
                         
                }
                ++s;       
        } 
   }      
   if ( !current )
   {
           HDUCreator newTable(m_FITSImpl);
           Table* newHDU = static_cast<Table*>(newTable.createTable(hduName, type, rows,
                                                    columnName, columnFmt,  columnUnit, version));   
           current = addExtension(newHDU);
   }
   return static_cast<Table*>(current);
  
    //## end CCfits::FITS::addTable%3964B05001A2.body
  }

  ExtHDU* FITS::addImage (const String& hduName, int bpix, std::vector<long>& naxes, int version)
  {
    //## begin CCfits::FITS::addImage%3964D03901D3.body preserve=yes
   ExtHDU* current(0);
   size_t N(extension().count(hduName));
   std::pair<ExtMapIt,ExtMapIt> matches(extension().equal_range(hduName));
   if ( N > 0 )
   {
        ExtMapIt s(matches.first);
        while  ( s != matches.second )
        {
                current = s->second;
                if ( current->version() == version  )
                {
                        std::cerr << " Extension " << hduName << " with version " 
                                << version << " already exists "
                                << " returning token for existing version \n";
                        
                         
                }
                ++s;       
        } 
   }      
   if (!current)
   {
        HDUCreator newImage(m_FITSImpl);
        ExtHDU* newHDU = newImage.createImage(hduName, bpix, naxes.size(), naxes,  version);  
        current =  addExtension(newHDU);
   }
   return current;
    //## end CCfits::FITS::addImage%3964D03901D3.body
  }

  void FITS::destroy () throw ()
  {
    //## begin CCfits::FITS::destroy%396E1B7B0088.body preserve=yes
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
    //## end CCfits::FITS::destroy%396E1B7B0088.body
  }

  void FITS::flush ()
  {
    //## begin CCfits::FITS::flush%3D88E4EE02FC.body preserve=yes
    int status (0);
    if (fits_flush_file(m_FITSImpl->fptr(),&status)) throw FitsError(status);
    //## end CCfits::FITS::flush%3D88E4EE02FC.body
  }

  const String& FITS::currentExtensionName () const
  {
    //## begin CCfits::FITS::currentExtensionName%39CA286C018F.body preserve=yes
    //## end CCfits::FITS::currentExtensionName%39CA286C018F.body

    return m_FITSImpl->currentExtensionName();
  }

  ExtHDU* FITS::addExtension (ExtHDU* ext)
  {
    //## begin CCfits::FITS::addExtension%39CA34CA025B.body preserve=yes
   int status(0);
   const String& extName = ext->name();
   ExtMap::value_type addHDUEntry(extName,ext);
   m_FITSImpl->currentExtensionName() = extName;
   ExtMapIt added = m_FITSImpl->extension().insert(addHDUEntry);
   if (fits_set_hdustruc(fitsPointer(),&status)) throw FitsError(status);
   (*added).second->index(fitsPointer()->HDUposition);
   return (*added).second;
    //## end CCfits::FITS::addExtension%39CA34CA025B.body
  }

  void FITS::read (const std::vector<String>& searchKeys, const std::vector<String> &searchValues, bool readDataFlag, const std::vector<String>& hduKeys, int version)
  {
    //## begin CCfits::FITS::read%3A0036810026.body preserve=yes
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
	std::vector<String> testKeys(searchKeys);
	std::vector<String> testResults(searchKeys.size(),"");
	testHDU->readKeys(testKeys,testResults); 
        using namespace FITSUtil;
                     
	// first: we need to have matched as many keys as were input.
                     
	if (testKeys.size() == searchKeys.size()) 
	{
	   // now go through and check the values that were read
	   // against the input value list.
	   size_t k = 0;
	   gotIt = true;   
           std::vector<String>::const_iterator vi(searchValues.begin());   
          std::vector<String>::const_iterator  viEnd(searchValues.end());   
                
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
     String extname("");
     int extver = 1;
     ExtHDU::readHduName(m_FITSImpl->fptr(),hduIndex,extname,extver);
     read(extname,readDataFlag,hduKeys,extver);
     currentExtensionName(extname);
  }
     
  else
  {
#ifdef SSTREAM_DEFECT
     std::ostrstream err;
#else
     std::ostringstream err;
#endif
      err << "Error: Unable to find extension containing keywords ";
      std::copy(searchKeys.begin(),searchKeys.end(),
		std::ostream_iterator<String>(err," "));
      err << "\nwith required values and version number ";	
#ifdef SSTREAM_DEFECT
      err << std::ends;
#endif
      
      throw NoSuchHDU(err.str());
  }     
    //## end CCfits::FITS::read%3A0036810026.body
  }

  void FITS::swap (FITS& right)
  {
    //## begin CCfits::FITS::swap%3A1942E100A9.body preserve=yes
    FITSUtil::swap(m_FITSImpl,right.m_FITSImpl);
    //## end CCfits::FITS::swap%3A1942E100A9.body
  }

  const ExtMap& FITS::extension () const
  {
    //## begin CCfits::FITS::extension%3A194B1F0133.body preserve=yes
    //## end CCfits::FITS::extension%3A194B1F0133.body

    return m_FITSImpl->extension();
  }

  void FITS::resetPosition ()
  {
    //## begin CCfits::FITS::resetPosition%3B3C916C03A9.body preserve=yes
    int status(0);
    if (fits_movabs_hdu(fitsPointer(),1,0,&status)) throw FitsError(status);
    //## end CCfits::FITS::resetPosition%3B3C916C03A9.body
  }

  void FITS::currentExtensionName (const String& extName)
  {
    m_FITSImpl->currentExtensionName() = extName;

    //## begin CCfits::FITS::currentExtensionName%3A1950E101EF.body preserve=yes
    //## end CCfits::FITS::currentExtensionName%3A1950E101EF.body
  }

  const String& FITS::name () const
  {
    //## begin CCfits::FITS::name%3A1AD2260281.body preserve=yes
    //## end CCfits::FITS::name%3A1AD2260281.body

    return m_FITSImpl->name();
  }

  fitsfile*& FITS::fitsPointer ()
  {
    //## begin CCfits::FITS::fitsPointer%3B38A97B038A.body preserve=yes
    //## end CCfits::FITS::fitsPointer%3B38A97B038A.body

    return m_FITSImpl->fptr();
  }

  void FITS::copy (const HDU& source)
  {
    //## begin CCfits::FITS::copy%3B38B52F009E.body preserve=yes
    int status(0);
    
    source.makeThisCurrent();
    
    if (fits_copy_hdu(source.fitsPointer(),fitsPointer(),0,&status)) 
                throw FitsError(status);      
          
    // the fits file has been updated, although the data have not 
    // been read.
      
          
    //## end CCfits::FITS::copy%3B38B52F009E.body
  }

  Table& FITS::filter (const String& expression, ExtHDU& inputTable, bool overwrite, bool readData)
  {
    //## begin CCfits::FITS::filter%3B38C51E035F.body preserve=yes
    
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
               String tableName = table.name();
               int tableVersion(table.version());
               char* cExpression = const_cast<char*>(expression.c_str());
               int status(0);
               
               
               // check if the two file names are the same. Checking the pointers
               // are the same doesn't allow for the possibility that there are
               // two views of the same file.
               if (fits_file_name(inputFitsPointer,pName1.get(),&status)) throw FitsError(status);
               if (fits_file_name(fitsPointer(),pName2.get(),&status)) throw FitsError(status);
               const String& infile = String(pName1.get());
               const String& outfile = String(pName2.get());

               // store list of what has been read so far so it can be read back.
               std::vector<String> 
                    keyStore(table.keyWord().size() + table.column().size());

               std::map<String,Keyword*>::const_iterator keyIt(table.keyWord().begin());
               std::map<String,Keyword*>::const_iterator keyItEnd(table.keyWord().end());
               std::map<String,Column*>::const_iterator colIt(table.column().begin());
               std::map<String,Column*>::const_iterator colItEnd(table.column().end());

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

    
    
    //## end CCfits::FITS::filter%3B38C51E035F.body
  }

  ExtMap& FITS::extension ()
  {
    //## begin CCfits::FITS::extension%3B38FA2B02EC.body preserve=yes
    //## end CCfits::FITS::extension%3B38FA2B02EC.body

    return m_FITSImpl->extension();
  }

  ExtHDU& FITS::currentExtension ()
  {
    //## begin CCfits::FITS::currentExtension%3B3B6C9100E1.body preserve=yes
    // return the current extension. Must have been previously instantiated by
    // CCfits.
    int num(0);
    fits_get_hdu_num(fitsPointer(),&num);
    // extensions start counting at 1, HDU indices at 2.
    return extension(num - 1);
    //## end CCfits::FITS::currentExtension%3B3B6C9100E1.body
  }

  String FITS::nameOfUnmapped (int hduNum) const
  {
    //## begin CCfits::FITS::nameOfUnmapped%3B3B85700157.body preserve=yes
          
    // return the name of HDUs not yet mapped.    
          
    static char EXTNAME[] = "EXTNAME";
    static char HDUNAME[] = "HDUNAME";
    String retVal("");
    int current(0);
    int status(0);
    fits_get_hdu_num(fitsPointer(),&current);
    if (fits_movabs_hdu(fitsPointer(),hduNum,0,&status)) throw FitsError(status);
    
    FITSUtil::auto_array_ptr<char> pTestKey(new char[FLEN_VALUE]);
    char* testKey = pTestKey.get();
    
    if (fits_read_key_str(fitsPointer(),EXTNAME,testKey,0,&status) == 0)
    {
            retVal = String(testKey);
    }
    else 
    {   
        if (status == KEY_NO_EXIST)
        {
                status = 0;
                fits_read_key_str(fitsPointer(),HDUNAME,testKey,0,&status) ;
                if (status == 0) 
                {
                        retVal = String(testKey);
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
    
    //## end CCfits::FITS::nameOfUnmapped%3B3B85700157.body
  }

  void FITS::cloneHeader (const ExtHDU& source)
  {
    //## begin CCfits::FITS::cloneHeader%3B4073EA005D.body preserve=yes
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
        std::vector<String> cards(nKeys);
        {     
                for (int j = 1; j <= nKeys; ++j)
                {
                        if (fits_read_record(sourcePointer,j,card,&status)) throw FitsError(status);  
                        cards[j-1] = String(card);     
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
    //## end CCfits::FITS::cloneHeader%3B4073EA005D.body
  }

  void FITS::deleteExtension (int doomed)
  {
    //## begin CCfits::FITS::deleteExtension%3B66F7BB007D.body preserve=yes
    int status(0);
    ExtHDU& d = extension(doomed); // throws NoSuchHDU if it's not there.
    if (fits_delete_hdu(fitsPointer(),0,&status)) throw FitsError(status);
    unmapExtension(d);
    //## end CCfits::FITS::deleteExtension%3B66F7BB007D.body
  }

  // Additional Declarations
    //## begin CCfits::FITS%37FE367A41D0.declarations preserve=yes
    //## end CCfits::FITS%37FE367A41D0.declarations

} // namespace CCfits

//## begin module%37FE40B76648.epilog preserve=yes
//## end module%37FE40B76648.epilog
