//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%37FE40B458D8.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%37FE40B458D8.cm

//## begin module%37FE40B458D8.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%37FE40B458D8.cp

//## Module: FITS%37FE40B458D8; Package specification
//## Subsystem: CCfits::FITS%393411910327
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/FITS.h

#ifndef FITS_H
#define FITS_H 1

//## begin module%37FE40B458D8.additionalIncludes preserve=no
//## end module%37FE40B458D8.additionalIncludes

// string
#include <string>
// exception
#include <exception>
// map
#include <map>
// ExtHDU
#include "ExtHDU.h"
// HDUCreator
#include "HDUCreator.h"
// FitsError
#include "FitsError.h"

namespace CCfits {
  class FITSBase;
  class PHDU;
  class Table;

} // namespace CCfits

//## begin module%37FE40B458D8.includes preserve=yes
//class PHDU;
extern "C"
{
#       include <sys/stat.h>
}           
//## end module%37FE40B458D8.includes

//## begin module%37FE40B458D8.declarations preserve=no
//## end module%37FE40B458D8.declarations

//## begin module%37FE40B458D8.additionalDeclarations preserve=yes
#include <memory>
//## end module%37FE40B458D8.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
/*!  
        
     \class FITS
     \brief Memory object representation of a disk FITS file
     
     Constructors are provided to get FITS data from an existing file or to create
     new FITS data sets. Overloaded versions allow the user to 
     
     a) read from one or more specified extensions, specified by EXTNAME and VERSION
        or by HDU number.
     b  either just header information or  data on construction
     c) to specify scalar keyword values to be read on construction
     d) to open and read an extension that has specified keyword values
     e) create a new FITS object and corresponding file, including an
        empty primary header.
        
     The memory fits object as constructed is always an image of a valid
     FITS object, i.e. a primary HDU is created on construction.
     
     calling the destructor closes the disk file, so that FITS files are automatically
     deleted at the end of scope unless other arrangements are made.
          
     
*/

/*!   @defgroup FITSexcept FITS Exceptions

*/

/*!
     \class FITS::NoSuchHDU
     @ingroup FITSexcept
     @brief exception thrown by HDU retrieval methods. 
*/

/*! \fn FITS::NoSuchHDU::NoSuchHDU(const string& diag, bool silent)

        \brief Exception ctor, prefixes the string "FITS Error: Cannot read HDU in FITS file:" before the specific message.
                        
        \param diag A specific diagnostic message, usually the name of the extension whose read was attempted.
        \param silent if true, print message whether FITS::verboseMode is set or not.


*/

/*!
     \class FITS::CantOpen
     @ingroup FITSexcept
     @brief thrown on failure to open existing file
*/

/*! \fn FITS::CantOpen::CantOpen(const string& diag, bool silent)
     
     \brief Exception ctor prefixes the string: "FITS Error: Cannot create file " before specific message
     
     This exception will be thrown if users attempt to open an existing file for
     write access to which they do not have permission, or of course if the file does
     not exist. 
     
        \param diag A specific diagnostic message, the name of the file that was to be created.
        \param silent if true, print message whether FITS::verboseMode is set or not.
     
*/


/*!
     \class FITS::CantCreate
     @ingroup FITSexcept
     @brief thrown on failure to create new file
     
*/

/*! \fn FITS::CantCreate::CantCreate(const string& msg, bool silent)
     
     \brief Exception ctor prefixes the string: "FITS Error: Cannot create file " before specific message
     
     This exception will be thrown if the user attempts to write to a protected directory or 
     attempts to create a new file with the same name as an existing file
     without specifying overwrite [overwrite is specified by adding the character '!' before
     the filename, following the cfitsio convention].
     
        \param msg A specific diagnostic message, the name of the file that was to be created.
        \param silent if true, print message whether FITS::verboseMode is set or not.
     
*/


/*!
     \class FITS::OperationNotSupported
     @ingroup FITSexcept
     @brief thrown for unsupported operations, such as attempted to select rows from
      an image extension.
     
*/
/*! \fn FITS::OperationNotSupported::OperationNotSupported(const string& msg, bool silent)

        \brief Exception ctor, prefixes the string "FITS Error: Operation not supported:" before the specific message.
                        
        \param msg A specific diagnostic message.
        \param silent if true, print message whether FITS::verboseMode is set or not.


*/

     
/*!   
      \fn FITS::FITS(const FITS &right)
      \brief copy constructor
      
*/
      
/*!   \fn  FITS::FITS(const string &name, RWmode mode, bool readDataFlag, const std::vector<string>& primaryKeys) 
      \brief basic constructor
      
      This basic constructor makes a FITS object from the given filename. The filename
      string is passed directly to the cfitsio library: thus all of the extended
      filename syntax described in the cfitsio manual should work as documented.
      
      If the mode is Read [default], it will read all of the headers in the file, and all of the data if the
      readDataFlag is supplied as true. It will also read optional primary keys.
      
      The file name is the only  required argument. If the mode is Write and
      the file does not already exist, a default primary HDU will be created in
      the file with BITPIX=8 and NAXIS=0: this mode is designed for writing
      FITS files with table extensions only. For files with image data the 
      constructor that specified the data type and number of axes should be called.
          
           
      \param name The name of the FITS file to be read/written
      \param mode The read/write mode: must be Read or Write
      \param readDataFlag boolean: read data on construction if true
      \param primaryKeys Allows optional reading of primary header keys on construction
      
      
      \exception NoSuchHDU thrown on HDU seek error either by index or {name,version}
      \exception FitsError thrown on non-zero status code from cfitsio when not overriden
                 by FitsException error to produce more illuminating message.

*/



/*!      \fn  FITS::FITS (const string &name, RWmode mode, const std::vector<string>& searchKeys, const std::vector<string> &searchValues, bool readDataFlag = false, const std::vector<string>& hduKeys = std::vector<string>(), const std::vector<string>& primaryKey = std::vector<string>(), int version = 1);
      \brief open fits file and read HDU which contains supplied keywords
           with [optional] specified values (sometimes one just wants to know that the keyword is present).

        Optional parameters allows the reading of specified primary HDU keys and 
        specified columns and keywords in the HDU of interest.
                          
      \param name The name of the FITS file to be read
      \param mode The read/write mode: must be Read or Write
      \param searchKeys A string vector of keywords to search for in each header
      
      \param searchValues A string vector of values those keywords are required to have for success.
                          Note that the keys must be of type string. If any value does not
                          need to be checked the corresponding searchValue element can be empty.
      \param readDataFlag boolean: if true, read data if HDU is found                    
      \param hduKeys Allows optional reading of keys in the HDU that is searched for if it 
                      is successfully found
      \param primaryKeys Allows optional reading of primary header keys on construction
      \param version   Optional version number. If specified, checks the EXTVERS keyword.
      
      
      \exception FitsError thrown on non-zero status code from cfitsio when not overriden
                 by FitsException error to produce more illuminating message.

*/

  
/*!   \fn FITS::FITS(const string &name, RWmode mode, const string &hduName, bool readDataFlag, const std::vector<string>& hduKeys, const std::vector<string>& primaryKey, int version);
      \brief Open a FITS file and read a single specified HDU.      
      
      This and similar constructor variants support reading table data.

      Optional arguments allow the reading of primary header keys and specified
      data from hduName, the HDU to be read. An object representing the primary
      HDU is always created: if it contains an image, that
      image may be read by subsequent calls.
      
      \param name The name of the FITS file to be read
      \param mode The read/write mode: takes values Read or Write
      \param hduName The name of the HDU to be read.
      \param hduKeys Optional array of keywords to be read from the HDU
      \param version Optional version number. If not supplied the first HDU
             with name <I>hduName</I> is read
      see above for other parameter definitions
  
*/


  /*! \fn FITS::FITS(const string &name, RWmode mode, const std::vector<string>& hduNames, bool readDataFlag, const std::vector<string>& primaryKey);
     
     This is intended as a convenience where the file consists of single versions of
     HDUs and data only, not keys are to be read.
     \param hduNames array of HDU names to be read.
     see above for other parameter definitions.
  */

  /*! \fn FITS::FITS(const string &name, RWmode mode, const std::vector<string>& hduNames, const std::vector<std::vector<string> >& hduKeys, bool readDataFlag, const std::vector<string>& primaryKeys, const std::vector<int>& hduVersions);
      \brief FITS read constructor in full generality.
      
      \param hduVersions an optional version number for each HDU to be read
      \param hduKeys an array of keywords for each HDU to be read.
     see above for other parameter definitions.
  */  
  
    /*! \fn FITS::FITS(const string& name, int bitpix, int naxis, long *naxes) ;
      \brief Constructor for creating new FITS objects containing images.
      
      This constructor is only called for creating new files (mode is not an argument)
      and creates a new primary HDU with the datatype & axes specified by bitpix,
      naxis, and naxes. The data are added to the new fits object and file by
      subsequent calls to FITS::pHDU().write( <arguments> )
      
      Valid values of bitpix are given in the fitsio.h header.
      If the filename corresponds to an existing file and does not start with the '!'
      character the construction will fail with a CantCreate exception.
       
     
      
      
     The arguments are:
     \param name The file to be written to disk
     \param bitpix the datatype of the primary image (see cfitsio documentation
            for allowed values.
     \param naxis the data dimension of the primary image
     \param naxes the array of axis lengths for the primary image. Ignored if naxis =0,
            i.e. the primary header is empty.
     extensions can be added arbitrarily to the file after this constructor is
     called. The constructors should write header information to disk:
 */
  
    /*! \fn FITS::FITS(const string &name, RWmode mode, int hduIndex, bool readDataFlag, const std::vector<string>& hduKeys, const std::vector<string>& primaryKey) ;
      \brief read a single numbered HDU. 
      
      Constructor analogous to the version that reads by name. This is required since
      HDU extensions are not required to have the EXTNAME or HDUNAME keyword by
      the standard. If there is no name, a dummy name based on the HDU number is
      created and becomes the key.
      
      \param hduIndex The index of the HDU to be read.
     see above for other parameter definitions.
  */
    
    /*! \fn FITS::~FITS()
     \brief destructor

    */
     
    /*! \fn FITS::FITS (const string& fileName, const FITS& source)
      \brief create a new FITS object and corresponding file with copy of the primary header of the source
      
      
      \param fileName New file to be created.
      \param source A previously created FITS object to be copied.
      
     see above for other parameter definitions.
  */

  /*! \fn static void FITS::clearErrors()
        
        \brief clear the error stack and set status to zero.
  
  */
   
   /*! \fn void FITS::deleteExtension(const std::string& doomed, int version=1)
   
        \brief Delete extension specified by name and version number.
        
        Removes extension from FITS object and memory copy.
        
        \param doomed the name of the extension to be deleted
        \param version an optional version number, the EXTVER keyword, defaults to 1
        
        \exception NoSuchHDU Thrown if there is no extension with the specified version number
        \exception FitsError Thrown if there is a non-zero status code from cfitsio, e.g.
                if the delete operation is applied to a FITS file opened for read only access.
    */
    
   /*! \fn void FITS::deleteExtension(int doomed)
   
        \brief Delete extension specified by extension number
                
        \overload
    */
         
    
        
   /*! \fn void FITS::read(const string &hduName, bool readDataFlag, const std::vector<string> &keys, int version=1) ;
       \brief get data from single HDU from disk file.
       
       This is provided to allow the adding of additional HDUs to the FITS
       object after construction of the FITS object.
       After the read() functions have been called for the FITS object, subsequent
       read method to the Primary, ExtHDU, and Column objects will retrieve data
       from the FITS object in memory (those methods can be called to read data
       in those HDU objects that was not read when the HDU objects were constructed.
       
       All the read functions will throw NoSuchHDU exceptions 
       on seek errors since they involve constructing HDU objects.  
       
       The parameter definitions are as documented for the corresponding constructor.
   */     
 
 /*!      \fn  FITS::read (const std::vector<string>& searchKeys, const std::vector<string> &searchValues, bool readDataFlag, const std::vector<string>& hduKeys,  int version=1) ;

        \brief read method for read header or HDU that contains specified  keywords.
      
      \param searchKeys A string vector of keywords to search for in each header
      
      \param searchValues A string vector of values those keywords are required to have for success.
                          Note that the keys must be of type string. If any value does not
                          need to be checked the corresponding searchValue element can be empty.
      \param readDataFlag boolean: if true, read data if HDU is found                    
      \param hduKeys Allows optional reading of keys in the HDU that is searched for if it 
                      is successfully found
      \param primaryKeys Allows optional reading of primary header keys on construction
      \param version   Optional version number. If specified, checks the EXTVERS keyword.
      
      
*/

/*!\fn void FITS::copy(const HDU& source);
        \brief copy the HDU source into the FITS object.
                        
        This function adds a copy of an HDU from another file into *this. It
        does not create a duplicate of an HDU in the file associated with *this.

*/
 
 
 
   /*! \fn void FITS::read(const std::vector<string> &hduNames, bool readDataFlag)
      \brief get data from a set of HDUs from disk file.
      
      This is provided to allow  reading of  HDUs after construction.  
      see above for parameter definitions. 
  */ 
  
   /*! \fn void FITS::read(const std::vector<string> &hduNames, const std::vector<std::vector<string> > &keys, bool readDataFlag = false, const std::vector<int>& hduVersions = std::vector<int>());
      \brief get data from a set of HDUs from disk file, specifying keys and version numbers.
      
      This is provided to allow  reading of  HDUs after construction.  
      see above for parameter definitions. 
  */ 

    /*! \fn void FITS::read (int hduIndex, bool readDataFlag = false, const std::vector<string> &keys = std::vector<string>()) ;
   
       \brief read an HDU specified by index number.
      
      This is provided to allow  reading of  HDUs after construction.
      see above for parameter definitions. 

   */

  /*! \fn const string& FITS::currentExtensionName () const
      \brief return the name of the extension that the fitsfile is currently addressing.
      
      If the extension in question does not have an EXTNAME or HDUNAME keyword, then
      the function returns $HDU$n, where n is the sequential HDU index number (primary
      HDU = 0).
      
  */ 

  
  /*! \fn void FITS::open(RWmode mode= Read) ;
      \brief open the file with mode as specified on construction.
  */ 

  /*! \fn bool FITS::create() ;
      \brief create new fits file on disk and construct the fitsfile pointer
  */ 

  /*! \fn void FITS::close() throw();
      \brief close the file. 
  */ 

  /*! \fn FITS * FITS::clone() const
      \brief clone function: to allow implementation later of reference counting.
  */ 

  /*! \fn const FITS::ExtHDU&  FITS::extension(int i) const
      \brief return FITS extension by index number. 
      N.B. The input index number is currently defined as enumerating
      extensions, so the extension(1) returns HDU number 2.
  */ 
  
  /*! \fn  FITS::ExtHDU&  FITS::extension(int i) ;
      \brief return FITS extension by index number. non-const version.
      see const version for details.
  */ 

    /*! \fn friend ostream & operator << (ostream &s, const FITS& right)
      \brief Output operator. Calls output operators for HDUs in turn.

      This operator acts similarly to the ftool fdump for a fits file,
      except that there is no freedom to output partial information.

      The current implementation of this operator for PHDU objects
	only outputs the array sizes, not the data, which that for
	tables prints the data also.

	Provision of this operator is intended largely for debugging
	purposes.
        
      

  */

  /*! \fn  const ExtHDU& FITS::extension(const string& hduName, int version) const
      \brief return FITS extension by name and (optionally) version number.
  */ 

  /*! \fn  ExtHDU& FITS::extension(const string& hduName, int version) 
      \brief return FITS extension by name and (optionally) version number.
  */ 


  /*! \fn  const std::multimap<std::string,ExtHDU*>& FITS::extension () const;
      \brief return const reference to the extension container
      
      This is useful for such operations as extension().size() etc.
  */ 

  
   /*! \fn  Table* FITS::addTable (string& hduName, 
			int rows, 
                        const std::vector<string>& columnName,
        		const std::vector<string>& columnFmt,
        		const std::vector<string>& columnUnit,
        		HduType type, 
			int version);

       \brief Add a table extension to an existing FITS object. 
       Add extension to FITS object for file with w or rw access.
       \param rows    The number of rows in the table to be created.
       \param columnName A vector containing the table column names
       \param columnFmt  A vector containing the table column formats
       \param columnUnit (Optional) a vector giving the units of the columns.
       \param HduType The table type - AsciiTbl or BinaryTbl (defaults to BinaryTbl)
      the lists of columns are optional - one can create an empty table extension
      but if supplied, colType, columnName and colFmt must have equal dimensions.

	\todo the code should one day check that the version keyword is higher than any other versions already added to the FITS object (although cfitsio doesn't
do this either).
      
   */

   /*! \fn void FITS::addImage (const string& hduName, int bpix, std::vector<long>& naxes, int version)
     \brief Add an image extension to an existing FITS object. (File with w or rw access).
     
     Does not make primary images, which are built in the constructor for the FITS file.
     The image data is not added here: it can be added by a second call.

     \todo Add a function for replacing the primary image
   */
 
 
   /*! \fn FITS::resetPosition() ;
   
      \brief explicit call to set the fits file pointer to the primary.
   */   
 
   /*! \fn PHDU& FITS::pHDU()
   
      \brief return a reference to the primary HDU.
   */   
                      
   /*! \fn const PHDU& FITS::pHDU() const
   
      \brief return a const reference to the primary HDU.
   */   
 
   /*! \fn FITS::currentExtension();
   
      \brief return a non-const reference to whichever is the current extension.
   */   
 
 
   /*! \fn       Table& FITS::filter (const string& expression, ExtHDU& inputTable, bool overwrite = true, bool readData = false);

   
      \brief Filter the rows of the inputTable with the condition expression, and return a reference
             to the resulting Table.
                      
             This function provides an object oriented version of cfitsio's fits_select_rows call. 
             The expression string is any boolean expression involving the names of the columns in the
             input table (e.g., if there were a column called "density", a valid expression
             might be "DENSITY > 3.5": see the cfitsio documentation for further details).              
             
             [N.B. the "append" functionality described below does not work when linked with
             cfitsio 2.202 or prior because of a known issue with that version of the library.
             This causes the output to be a new extension with a correct header copy and
             version number but without the filtered data].
             If the inputTable is an Extension HDU of this FITS object, then if overwrite is
             true the operation will overwrite the inputTable with the filtered version, otherwise
             it will append a new HDU with the same extension name but the next highest
             version (EXTVER) number available.
        
   */   
 
                      
                      
   /*! \fn void FITS::destroy() throw()
   
      \brief Erase FITS object and close corresponding file.
   
      Force deallocation and erase of elements of a FITS memory object. Allows a reset of everything
      inside the FITS object, and closes the file. The object is inaccessible after this call.

      destroy is public to allow users to reuse a symbol for a new file,
      but it is identical in operation to the destructor.
    
   */
   
   /*! \fn void FITS::flush()
        
        \brief flush buffer contents to disk
        
        Provides manual control of disk writing operation. Image data are flushed
        automatically to disk after the write operation is completed, but not
        column data.
   
   */
   
   /*! \fn const std::string& FITS::name () const
   
        \brief return filename of file corresponding to FITS object
   */
   
   /*! \fn static const bool FITS::verboseMode ()
   
        \brief return verbose setting for library
        
        If true, all messages that are reported by exceptions are printed to std::cerr.
   */

   /*! \fn static void FITS::setVerboseMode (bool ) 
   
        \brief set verbose setting for library
        
        
   */
  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::FITS%37FE367A41D0.preface preserve=yes
  //## end CCfits::FITS%37FE367A41D0.preface

  //## Class: FITS%37FE367A41D0; private
  //	! The FITS object class. Contains a primary HDU and Extensions indexed by name.
  //## Category: CCfits::FITS%393416E90118
  //## Subsystem: CCfits::FITS%393411910327
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%3937E43B002A;std::multimap { -> }
  //## Uses: <unnamed>%397DFD74039E;Table { -> F}
  //## Uses: <unnamed>%3A1934AA03B1;PHDU { -> F}
  //## Uses: <unnamed>%3B374F7E0164;PrimaryHDU { -> }
  //## Uses: <unnamed>%3EF07E5000FA;ExtHDU { -> }

  class FITS 
  {
    //## begin CCfits::FITS%37FE367A41D0.initialDeclarations preserve=yes
    //## end CCfits::FITS%37FE367A41D0.initialDeclarations

    public:
      //## Class: NoSuchHDU%396C9033032A
      //## Category: CCfits::FITS%393416E90118
      //## Subsystem: CCfits::FITS%393411910327
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class NoSuchHDU : public FitsException  //## Inherits: <unnamed>%396C90CB0236
      {
        public:
          //## Constructors (specified)
            //## Operation: NoSuchHDU%396C908003D3
            NoSuchHDU (const String& diag, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Class: OperationNotSupported%39806BFF003C
      //## Category: CCfits::FITS%393416E90118
      //## Subsystem: CCfits::FITS%393411910327
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class OperationNotSupported : public FitsException  //## Inherits: <unnamed>%39806C7600D5
      {
        public:
          //## Constructors (specified)
            //## Operation: OperationNotSupported%39806C3302FE
            OperationNotSupported (const String& msg, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Class: CantOpen%39C8E9C401CF
      //## Category: CCfits::FITS%393416E90118
      //## Subsystem: CCfits::FITS%393411910327
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class CantOpen : public FitsException  //## Inherits: <unnamed>%39C8EB1D02C0
      {
        public:
          //## Constructors (specified)
            //## Operation: CantOpen%39C8E9FA01BA
            CantOpen (const String& diag, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Class: CantCreate%39C8E9DF00D7
      //## Category: CCfits::FITS%393416E90118
      //## Subsystem: CCfits::FITS%393411910327
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      struct CantCreate : public FitsException  //## Inherits: <unnamed>%39C8EB10020B
      {
          //## Constructors (specified)
            //## Operation: CantCreate%39C8EA2C01E0
            CantCreate (const String& diag, bool silent = false);

        public:
        protected:
        private:
        private: //## implementation
      };

      //## Constructors (specified)
        //## Operation: FITS%38D292027BA0
        FITS (const String &name, RWmode mode = Read, bool readDataFlag = false, const std::vector<String>& primaryKeys = std::vector<String>());

        //## Operation: FITS%38D2918EBC78
        //	Open a file and read a specified HDU.
        //
        //	Optional parameter allows the reading of specified primary HDU keys.
        FITS (const String &name, RWmode mode, const string &hduName, bool readDataFlag = false, const std::vector<String>& hduKeys = std::vector<String>(), const std::vector<String>& primaryKey = std::vector<String>(), int version = 1);

        //## Operation: FITS%38D290450D98
        //	Read data from a set of specified HDUs. keywords can only be specified for the primary here.
        //	The code will call a different constructor for the case where keywords are required for
        //	the extensions.
        FITS (const String &name, RWmode mode, const std::vector<String>& hduNames, bool readDataFlag = false, const std::vector<String>& primaryKey = std::vector<String>());

        //## Operation: FITS%3B38A690017E
        //	Initialize a new FITS file object with the primary from a
        //	different file.
        FITS (const String& fileName, const FITS& source);

        //## Operation: FITS%37FE3AFC2620
        //	Fully general FITS HDU reader. May read any part of fits file by
        //	supplying HDU names and version numbers, and optionally
        //	the data read flag.
        FITS (const String &name, RWmode mode, const std::vector<String>& hduNames, const std::vector<std::vector<String> >& hduKeys, bool readDataFlag = false, const std::vector<String>& primaryKeys = std::vector<String>(), const std::vector<int>& hduVersions = std::vector<int>());

        //## Operation: FITS%38454495F730
        //	Writing constructor. Takes a name and information to create an empty
        //	Primary HDU which can then be filled with calls to HDU methods.
        FITS (const String& name, int bitpix, int naxis, long *naxes);

        //## Operation: FITS%395B856A00D9
        //	Open a file and read a specified HDU.
        //
        //	Optional parameter allows the reading of specified primary HDU keys.
        FITS (const string &name, RWmode mode, int hduIndex, bool readDataFlag = false, const std::vector<String>& hduKeys = std::vector<String>(), const std::vector<String>& primaryKey = std::vector<String>());

        //## Operation: FITS%39B562CD0158
        //	Open a file and read a HDU that contains  specified
        //	search keywords with [optional] specified values
        //	(sometimes one just wants to know that the keyword is present).
        //
        //	Optional parameters allows the reading of specified primary HDU keys and specified keywords in
        //	the HDU of interest.
        FITS (const String &name, RWmode mode, const std::vector<String>& searchKeys, const std::vector<String> &searchValues, bool readDataFlag = false, const std::vector<String>& hduKeys = std::vector<String>(), const std::vector<String>& primaryKey = std::vector<string>(), int version = 1);

      //## Destructor (generated)
        ~FITS();


      //## Other Operations (specified)
        //## Operation: clearErrors%3B66F73A007C
        static void clearErrors ();

        //## Operation: deleteExtension%3B66F795013E
        void deleteExtension (const String& doomed, int version = 1);

        //## Operation: read%387DD1011578
        //	Read keys and data from a single ExtHDU in the file.
        void read (const String &hduName, bool readDataFlag = false, const std::vector<String> &keys = std::vector<String>(), int version = 1);

        //## Operation: read%387DFBA281E0
        //	Read multiple ExtHDUs. If the version number needs to be specified then one must call a
        //	different method.
        void read (const std::vector<String> &hduNames, bool readDataFlag = false);

        //## Operation: read%38D2944902F0
        //	Read selected data from multiple ExtHDUs
        void read (const std::vector<String> &hduNames, const std::vector<std::vector<String> > &keys, bool readDataFlag = false, const std::vector<int>& hduVersions = std::vector<int>());

        //## Operation: clone%382039362818
        FITS * clone () const;

        //## Operation: extension%381F03932200
        const ExtHDU& extension (int i) const;

        //## Operation: extension%39463D1E003A
        ExtHDU& extension (int i);

        //## Operation: extension%39463E9502B8
        const ExtHDU& extension (const String& hduName, int version = 1) const;

        //## Operation: pHDU%394E7AC8015A
        const PHDU& pHDU () const;

        //## Operation: pHDU%394E7B9F0063
        PHDU& pHDU ();

        //## Operation: extension%394F8196015C
        ExtHDU& extension (const String& hduName, int version = 1);

        //## Operation: operator <<%3952303802B6
        friend std::ostream& operator << (std::ostream& s, const FITS& right);

        //## Operation: read%395B890A0390
        //	Read keys and data from a single ExtHDU in the file.
        void read (int hduIndex, 	// Construct and Read HDU specified by number. One can add further HDUs by number using
        	// the HDUCreator factory.
        bool readDataFlag = false, const std::vector<String> &keys = std::vector<String>());

        //## Operation: addTable%3964B05001A2
        //	! add a new Table extension to a FITS object
        Table* addTable (const String& hduName, int rows, 	// ! Number of rows in new table. Mandatory
        const std::vector<String>& columnName = std::vector<String>(), 	// ! Optional set of column names for new table
        const std::vector<String>& columnFmt = std::vector<String>(), 	// ! Column formats for column units. Mandatory if columnName is specified
        const std::vector<String>& columnUnit = std::vector<String>(), 	// ! Column formats for column units. Optional
        HduType type = BinaryTbl, int version = 1);

        //## Operation: addImage%3964D03901D3
        //	! add a new ImageExt (image extension) to the FITS object. A "writing" method.
        ExtHDU* addImage (const String& hduName, int bpix, std::vector<long>& naxes, int version = 1);

        //## Operation: destroy%396E1B7B0088
        //	Force destruction of the FITS object. Essentially
        //	is a manual destructor call.
        //## Exceptions: ()
        void destroy () throw ();

        //## Operation: flush%3D88E4EE02FC
        void flush ();

        //## Operation: currentExtensionName%39CA286C018F
        const String& currentExtensionName () const;

        //## Operation: read%3A0036810026
        //	Open a file and read a HDU that contains  specified
        //	search keywords with [optional] specified values
        //	(sometimes one just wants to know that the keyword is present).
        //
        //	Optional parameters allows the reading of specified primary HDU keys and specified keywords in
        //	the HDU of interest.
        void read (const std::vector<String>& searchKeys, const std::vector<String> &searchValues, bool readDataFlag = false, const std::vector<String>& hduKeys = std::vector<String>(), int version = 1);

        //## Operation: extension%3A194B1F0133
        const ExtMap& extension () const;

        //## Operation: resetPosition%3B3C916C03A9
        void resetPosition ();

        //## Operation: currentExtensionName%3A1950E101EF
        void currentExtensionName (const String& extName);

        //## Operation: name%3A1AD2260281
        const String& name () const;

        //## Operation: copy%3B38B52F009E
        void copy (const HDU& source);

        //## Operation: filter%3B38C51E035F
        Table& filter (const String& expression, ExtHDU& inputTable, bool overwrite = true, bool readData = false);

        //## Operation: currentExtension%3B3B6C9100E1
        ExtHDU& currentExtension ();

        //## Operation: deleteExtension%3B66F7BB007D
        void deleteExtension (int doomed);

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: verboseMode%39AA762B03E3
        static bool verboseMode ();
        static void setVerboseMode (bool value);

    public:
      // Additional Public Declarations
        //## begin CCfits::FITS%37FE367A41D0.public preserve=yes
        //## end CCfits::FITS%37FE367A41D0.public

    protected:
      // Additional Protected Declarations
        //## begin CCfits::FITS%37FE367A41D0.protected preserve=yes
        //## end CCfits::FITS%37FE367A41D0.protected

    private:
      //## Constructors (generated)
        FITS(const FITS &right);

      //## Assignment Operation (generated)
        FITS & operator=(const FITS &right);


      //## Other Operations (specified)
        //## Operation: unmapExtension%3B3B4E550101
        void unmapExtension (ExtHDU& doomed);

        //## Operation: nextVersionNumber%3B3B79F50084
        int nextVersionNumber (const String& inputName) const;

        //## Operation: read%38D298347AE8
        //	read the primary HDU. Read the image if
        //	readDataFlag is true.
        void read (bool readDataFlag = false, const std::vector<String>& keys = std::vector<String>());

        //## Operation: open%380B3C3FACA8
        void open (RWmode mode = Read);

        //## Operation: create%383424B67D30
        //	Create returns true if a new file was created or an
        //	existing file overwritten, false if appending.
        //
        //
        //	It throws exception CantCreate or CantOpen if either fails.
        bool create ();

        //## Operation: close%380B3C655888
        //	Close the fits file.
        //
        //	Called in destructors so must not throw.
        //## Exceptions: ()
        int close () throw ();

        //## Operation: put%38ECDB29BE30
        std::ostream & put (std::ostream &s) const;

        //## Operation: fitsPointer%394122F101BF
        fitsfile*& fitsPointer () const;

        //## Operation: extbyVersion%394F892902A0
        ExtHDU& extbyVersion (const String& hduName, int version) const;

        //## Operation: pHDU%394FA9D0038C
        void pHDU (PHDU* value);

        //## Operation: readExtensions%396CD0CF001A
        void readExtensions (bool readDataFlag = false);

        //## Operation: addExtension%39CA34CA025B
        ExtHDU* addExtension (ExtHDU* ext);

        //## Operation: swap%3A1942E100A9
        void swap (FITS& right);

        //## Operation: fitsPointer%3B38A97B038A
        fitsfile*& fitsPointer ();

        //## Operation: extension%3B38FA2B02EC
        ExtMap& extension ();

        //## Operation: nameOfUnmapped%3B3B85700157
        String nameOfUnmapped (int hduNum) const;

        //## Operation: cloneHeader%3B4073EA005D
        void cloneHeader (const ExtHDU& source);

      // Additional Private Declarations
        //## begin CCfits::FITS%37FE367A41D0.private preserve=yes
        //## end CCfits::FITS%37FE367A41D0.private

    private: //## implementation
      // Data Members for Class Attributes

        //## begin CCfits::FITS::verboseMode%39AA762B03E3.attr preserve=no  public: static bool {V} false
        static bool s_verboseMode;
        //## end CCfits::FITS::verboseMode%39AA762B03E3.attr

      // Data Members for Associations

        //## Association: CCfits::<unnamed>%3A15B2C40372
        //## Role: FITS::FITSImpl%3A15B2C50307
        //## begin CCfits::FITS::FITSImpl%3A15B2C50307.role preserve=no  private: CCfits::FITSBase { -> 1RFHgN}
        FITSBase* m_FITSImpl;
        //## end CCfits::FITS::FITSImpl%3A15B2C50307.role

      // Additional Implementation Declarations
        //## begin CCfits::FITS%37FE367A41D0.implementation preserve=yes
      friend HDU* HDUCreator::Make (const string& hduName, bool readDataFlag, 
                                        const std::vector<String> &keys, bool primary, int version);  
      friend HDU* HDUCreator::Make (int index, bool readDataFlag, const std::vector<String> &keys);

      friend fitsfile* HDU::fitsPointer() const;
      friend void HDU::makeThisCurrent() const;
        //## end CCfits::FITS%37FE367A41D0.implementation
  };

  //## begin CCfits::FITS%37FE367A41D0.postscript preserve=yes
  //## end CCfits::FITS%37FE367A41D0.postscript

  // Class CCfits::FITS::NoSuchHDU 

  // Class CCfits::FITS::OperationNotSupported 

  // Class CCfits::FITS::CantOpen 

  // Class CCfits::FITS::CantCreate 

  // Class CCfits::FITS 


  //## Other Operations (inline)
  inline ExtHDU& FITS::extension (const String& hduName, int version)
  {
    //## begin CCfits::FITS::extension%394F8196015C.body preserve=yes
    //## end CCfits::FITS::extension%394F8196015C.body

    return extbyVersion(hduName,version);
  }

  inline std::ostream& operator << (std::ostream& s, const FITS& right)
  {
    //## begin CCfits::FITS::operator <<%3952303802B6.body preserve=yes
    //## end CCfits::FITS::operator <<%3952303802B6.body

    return right.put(s);
  }

  //## Get and Set Operations for Class Attributes (inline)

  inline bool FITS::verboseMode ()
  {
    //## begin CCfits::FITS::verboseMode%39AA762B03E3.get preserve=no
    return s_verboseMode;
    //## end CCfits::FITS::verboseMode%39AA762B03E3.get
  }

  inline void FITS::setVerboseMode (bool value)
  {
    //## begin CCfits::FITS::setVerboseMode%39AA762B03E3.set preserve=no
    s_verboseMode = value;
    //## end CCfits::FITS::setVerboseMode%39AA762B03E3.set
  }

} // namespace CCfits

//## begin module%37FE40B458D8.epilog preserve=yes
//## end module%37FE40B458D8.epilog


#endif
