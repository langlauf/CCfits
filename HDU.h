//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%38034DE11FA8.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%38034DE11FA8.cm

//## begin module%38034DE11FA8.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%38034DE11FA8.cp

//## Module: HDU%38034DE11FA8; Package specification
//## Subsystem: CCfits::HDU%3826DF628F48
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/HDU.h

#ifndef HDU_H
#define HDU_H 1

//## begin module%38034DE11FA8.additionalIncludes preserve=no
#include <map>
//## end module%38034DE11FA8.additionalIncludes

#include <list>
// vector
#include <vector>
// CCfitsHeader
#include "CCfits.h"
// Keyword
#include "Keyword.h"
// NewKeyword
#include "NewKeyword.h"
// FitsError
#include "FitsError.h"
// FITSUtil
#include "FITSUtil.h"

namespace CCfits {
  class FITS;
  class FITSBase;

} // namespace CCfits

//## begin module%38034DE11FA8.includes preserve=yes
#ifdef _MSC_VER
#include "MSconfig.h" // for truncation warning
#endif
#include "KeywordT.h"
//## end module%38034DE11FA8.includes

//## begin module%38034DE11FA8.declarations preserve=no
//## end module%38034DE11FA8.declarations

//## begin module%38034DE11FA8.additionalDeclarations preserve=yes
//## end module%38034DE11FA8.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
        /*! \class HDU

                \brief Base class for all HDU [Header-Data Unit] objects.

                HDU objects in CCfits are either PHDU (Primary HDU objects) or	
		ExtHDU (Extension HDU) objects. Following the behavior.
ExtHDUs are further subclassed into ImageExt or Table objects, which are
finally AsciiTable or BinTable objects.

		HDU's public interface gives access to properties that are
common to all HDUs, largely required keywords, and functions that  are common
to all HDUs, principally the manipulation of keywords and their values.

		HDUs must be constructed by HDUCreator objects which are
called by FITS methods. Each HDU has an embedded pointer to a FITSBase
object, which is private to FITS [FITSBase is a pointer encapsulating the
resources of FITS. For details of this coding idiom see Exceptional C++
by Herb Sutter (2000) and references therein].

		
        */


        /*! \class HDU::InvalidExtensionType

		@ingroup FITSexcept
                @brief exception to be thrown if user requests extension type that can not be understood as 
                ImageExt, AsciiTable or BinTable.
        */


/*! \fn HDU::InvalidExtensionType::InvalidExtensionType (const String& diag, bool silent);

        \brief Exception ctor, prefixes the string "Fits Error: Extension Type: " before the specific message.
                        
        \param diag A specific diagnostic message
        \param silent if true, print message whether FITS::verboseMode is set or not.

*/        

        /*! \class HDU::InvalidImageDataType

		@ingroup FITSexcept
                @brief exception to be thrown if user requests creation of an image of type not
                supported by cfitsio.
        */
        
/*! \fn HDU::InvalidImageDataType::InvalidImageDataType (const String& diag, bool silent);

        \brief Exception ctor, prefixes the string "Fits Error: Invalid Data Type for Image " before the specific message.
                        
        \param diag A specific diagnostic message
        \param silent if true, print message whether FITS::verboseMode is set or not.

*/        

/*! \class HDU::NoSuchKeyword

		@ingroup FITSexcept
                @brief exception to be thrown on seek errors for keywords.
*/
        
/*! \fn HDU::NoSuchKeyword::NoSuchKeyword (const String& diag, bool silent);

        \brief Exception ctor, prefixes the string "Fits Error: Keyword not found:  " before the specific message.
                        
        \param diag A specific diagnostic message, usually the name of the keyword requested.
        \param silent if true, print message whether FITS::verboseMode is set or not.

*/        

/*! \class HDU::NoNullValue

		@ingroup FITSexcept
                @brief exception to be thrown on seek errors for keywords.
*/
        
/*! \fn HDU::NoNullValue::NoNullValue (const String& diag, bool silent);

        \brief Exception ctor, prefixes the string "Fits Error: No Null Pixel Value specified for Image " before the specific message.
                        
        \param diag A specific diagnostic message, the name of the HDU if not the primary.
        \param silent if true, print message whether FITS::verboseMode is set or not.

*/        

        /*! \fn      HDU::HDU(const HDU &right);

        \brief copy constructor

        */

        /*! \fn       virtual HDU::~HDU();

        \brief destructor

        */


        /*! \fn       bool HDU::operator==(const HDU &right) const;

        \brief equality operator

        */

        /*! \fn       bool HDU::operator!=(const HDU &right) const;

        \brief inequality operator

        */

           
        /*! \fn  const String& HDU::getHistory();
                \brief read the history information from the HDU and add it to the FITS object.
        
                The history string found in the header is concatenated and returned
                to the calling function
        */                

         /*! \fn  const String& HDU::getComments();
                \brief read the comments from the HDU and add it to the FITS object.
                                
                The comment string found in the header is concatenated and returned
                to the calling function
        
        */   
                     
        /*! \fn void HDU::readAllKeys();
                \brief read all of the keys in the header
                                
                This member function reads keys that are not meta data for
                columns or image information, [which are considered to be
                part of the column or image objects]. Also, history and 
                comment keys are read and returned by getHistory() and getComment().
                                
                Note that readAllKeys can only construct keys of type
                string, float, complex<float>, integer, and bool because
                the FITS header records do not encode exact type information.

                 
        
        */
              
         /*! \fn void HDU::writeComment(const String& comment = "Generic Comment");                      
                \brief write a comment string. 
                                
                A default value for the string is given ("Generic Comment String") 
                so users can put a placeholder call to this function in their code.
        */
                        
        /*! \fn  void HDU::writeHistory (const String& history = "Generic History String");
                \brief write a history string. 
        
                A default value for the string is given ("Generic History String") 
                so users can put a placeholder call to this function in their code.
        */            
                
        /*! \fn void HDU::writeDate();
                \brief write a date string to *this.
        
        */ 
                                
         /*! \fn void HDU::deleteKey(const String& doomed)
                \brief delete a keyword from the header 
                
                
                removes <i>doomed<i> from the FITS file and from the FITS object
         
         */
                                                                                          
         /*! \fn const String& HDU::history() const;
                \brief return the history string previously read by getHistory()
        
        */  

        /*! \fn const String& HDU::comment() const;
                \brief return the comment string previously read by getComment()
        
        */  
 
                                                                                             
        /*! \fn   template <typename T> void HDU::readKey(const String& keyName, T& val);
      
            
        \brief read a  keyword of specified type from the header of a disk  FITS file
and return its value. 
                        
        T is one of the types String, float, int, std::complex<float>, and bool.
                

        */

        /*! \fn  template <typename T> void HDU::readKeys(std::vector<String>& keyNames, std::vector<T>& vals);

        \brief read a set of specified keywords of the same data type
		from the header of a disk  FITS file and return their values
                
        T is one of the types String, float, int, std::complex<float>, and bool.
                        

        */


        /*! \fn       virtual HDU * HDU::clone (FITSBase* p) const = 0;

        \brief virtual copy constructor, to be implemented in subclasses.

        */


        /*! \fn       void HDU::makeThisCurrent () const;

              \brief move the fitsfile pointer to this current HDU. 

		This function should never need to be called by the user
		since it is called internally whenever required.

        */


        /*! \fn       Keyword* HDU::keyWord (const String& keyName);

        \brief  return a (previously read) keyword from the HDU object.

        */


        /*! \fn       int HDU::index () const;

        \brief return the HDU number

        */

        /*! \fn       void HDU::index (int value);

        \brief set the HDU number

        */


        /*! \fn       const std::map<String,Keyword*>& HDU::keyWord () const;

        \brief  return the associative array containing the HDU Keywords that have been read so far.

        */

        /*! \fn      const Keyword * HDU::keyWord (const String& keyname) const;

        \brief return a (previously read) keyword from the HDU object. const version

        */

        /*! \fn       void HDU::setKeyWord (const String& keyname, Keyword& value);

        \brief set Keyword keyname to specified value

        */

        /*! \fn       HDU::HDU (FITSBase* p = 0);

        \brief default constructor, called by HDU subclasses that read from FITS files.

        */

        /*! \fn       HDU::HDU (FITSBase* p, int bitpix,int naxis, const std::vector<long>& axes);

        \brief constructor for creating new HDU objects, called by HDU subclasses writing to FITS files.

        */



        /*! \fn       virtual bool HDU::compare (const HDU &right) const;

        \brief internal implementation of equality operations.

        */


        /*! \fn       fitsfile* HDU::fitsPointer () const;

        \brief return the fitsfile pointer for the FITS object containing the HDU

        */

        /*! \fn       std::map<String, Keyword*> HDU::keyWord ();

        \brief return the associative  array containing the HDU keywords so far read.

        */



        /*! \fn       long HDU::axis (size_t index) const;

        \brief return the size of axis numbered index [zero based].

        */

        /*! \fn       void HDU::axes () const;

        \brief  return the number of axes in the HDU data section (always 2 for tables).

        */


        /*! \fn       const long HDU::bitpix () const;

        \brief return the data type keyword. 

        Takes values denoting the image data type for images, and takes the fixed value 8 for
        tables.

        */

        /*! \fn       void HDU::bitpix (long value);

        \brief set the data type keyword

        */


        /*! \fn       const FITSBase *& HDU::parent () const;

        \brief return reference to the pointer representing the FITSBase object containing the HDU

        */



        /*! \fn       std::vector< long >& HDU::naxes ();

        \brief return the HDU data axis array.


        */


        /*! \fn       long HDU::axis (size_t i) const;

                \brief return the length of HDU data axis i.

        */
                                
        /*! \fn       double HDU::zero () const;

                \brief return the BZERO keyword value

        */
                                
                                
        /*! \fn       double HDU::scale () const;

                \brief return the BSCALE keyword value

        */

        /*! \fn       template <typename T> Keyword& HDU::addKey(const String& name, T value,  const String& comment) ;

                \brief create a new keyword in the HDU with specified value and comment fields

                the function returns a reference to keyword object just created. 
                                
                Parameters:
                \param name (String) The keyword name
                \param value (T = String, float, std::complex<float>, int, or bool
                \param comment (String) the keyword value
                                
                Note the limitations on T, which arise for historical reasons (i.e.
                since keywords do not contain explicit type information, routines
                in CCfits must assign a type). The limitation may be removed in a
                future release
                
                It is possible however to create a keyword of any of the allowed
                data types in fitsio (see the cfitsio manual section 4.3). The
                required calls are, e.g. for a floating point double valued keyword:
                
                NewKeyword<double> keyCreate( hdu, double val1 );
                Keyword* key1  = Keyword keyCreate.MakeKeyword(keyName1, const String& comment);
                keyCreate.keyData(val2);
                Keyword* key2  = Keyword keyCreate.MakeKeyword(keyName2, const String& comment);
                
                key1->write();
                key2->write();
                
                ... which is essentially what addKey does for its allowed types.
                
                 

        */


                        
        /*! \fn std::ostream& operator << (std::ostream& s, const CCfits::HDU& right);
        
                \brief insertion operator.
        
        */  
  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::HDU%38034D916A68.preface preserve=yes
  //## end CCfits::HDU%38034D916A68.preface

  //## Class: HDU%38034D916A68; protected
  //## Category: CCfits::HDU%393417220088
  //## Subsystem: CCfits::HDU%3826DF628F48
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%39AFC54E029E;NewKeyword { -> }
  //## Uses: <unnamed>%3B38906F01B3;FITS { -> F}
  //## Uses: <unnamed>%3E92FE430141;std::vector { -> }
  //## Uses: <unnamed>%3EEF5EED035C;String { -> }

  class HDU 
  {
    //## begin CCfits::HDU%38034D916A68.initialDeclarations preserve=yes
    //## end CCfits::HDU%38034D916A68.initialDeclarations

    public:
      //## Class: InvalidImageDataType%394FB99800C5
      //## Category: CCfits::HDU%393417220088
      //## Subsystem: CCfits::HDU%3826DF628F48
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class InvalidImageDataType : public FitsException  //## Inherits: <unnamed>%394FBA12005C
      {
        public:
          //## Constructors (specified)
            //## Operation: InvalidImageDataType%39B54E68004D
            InvalidImageDataType (const string& diag, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Class: InvalidExtensionType%3952423800C0
      //## Category: CCfits::HDU%393417220088
      //## Subsystem: CCfits::HDU%3826DF628F48
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class InvalidExtensionType : public FitsException  //## Inherits: <unnamed>%3964C1D00352
      {
        public:
          //## Constructors (specified)
            //## Operation: InvalidExtensionType%39B54A7A008C
            InvalidExtensionType (const string& diag, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Class: NoSuchKeyword%398862C900BD
      //## Category: CCfits::HDU%393417220088
      //## Subsystem: CCfits::HDU%3826DF628F48
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class NoSuchKeyword : public FitsException  //## Inherits: <unnamed>%398865D10264
      {
        public:
          //## Constructors (specified)
            //## Operation: NoSuchKeyword%398862DD008E
            NoSuchKeyword (const string& diag, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Class: NoNullValue%3B0D57FE009C
      //## Category: CCfits::HDU%393417220088
      //## Subsystem: CCfits::HDU%3826DF628F48
      //## Persistence: Transient
      //## Cardinality/Multiplicity: n



      class NoNullValue : public FitsException  //## Inherits: <unnamed>%3B0D58CE0306
      {
        public:
          //## Constructors (specified)
            //## Operation: NoNullValue%3B0D581B039E
            NoNullValue (const string& diag, bool silent = true);

        protected:
        private:
        private: //## implementation
      };

      //## Constructors (generated)
        HDU(const HDU &right);

      //## Equality Operations (generated)
        bool operator==(const HDU &right) const;

        bool operator!=(const HDU &right) const;


      //## Other Operations (specified)
        //## Operation: clone%381F0205D838
        virtual HDU * clone (FITSBase* p) const = 0;

        //## Operation: fitsPointer%3937DEB20035
        fitsfile* fitsPointer () const;

        //## Operation: makeThisCurrent%393FEAFD009B
        //	By all means necessary, set the fitsfile pointer so that
        //	this HDU is the current HDU.
        //
        //	This would appear to be a good candidate for the public
        //	interface.
        virtual void makeThisCurrent () const;

        //## Operation: keyWord%39467076039D
        std::map<String, Keyword*> keyWord ();

        //## Operation: keyWord%394A7ED900AD
        Keyword& keyWord (const String& keyName);

        //## Operation: getHistory%39AFB37D01F3
        const String& getHistory ();

        //## Operation: getComments%39AFB38400DA
        const String& getComments ();

        //## Operation: operator<<%3A14643D01B1
        friend std::ostream& operator << (std::ostream& s, const CCfits::HDU& right);

        //## Operation: writeHistory%3B33A2C302AA
        //	Write a history string. A default value for the string is given
        //	"Generic History String" so users can put a placeholder call
        //	to this function in their code before knowing quite what should go in it.
        void writeHistory (const String& history = "Generic History String");

        //## Operation: writeComment%3B33A36D022C
        //	Write a history string. A default value for the string is given
        //	"GenericComment" so users can put a placeholder call
        //	to this function in their code before knowing quite what should go in it.
        void writeComment (const String& comment = "Generic Comment");

        //## Operation: writeDate%3B33A43F0164
        //	Write a date card.
        void writeDate ();

        //## Operation: parent%3B38956B00A3
        FITSBase* parent () const;

        //## Operation: readAllKeys%3B4B248200A1
        void readAllKeys ();

        //## Operation: axes%3B4DB00B0184
        long axes () const;

        //## Operation: axis%3B4DB04400CF
        long axis (size_t index) const;

        //## Operation: index%3B5EE0B40269
        void index (int value);

        //## Operation: deleteKey%3B66F7E501AF
        void deleteKey (const String& doomed);

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: bitpix%3805D3F96E18
        long bitpix () const;
        void bitpix (long value);

        //## Attribute: index%3816FC7F9028
        int index () const;

        //## Attribute: history%3B4B54060399
        const string& history () const;

        //## Attribute: comment%3B4B54270048
        const string& comment () const;

        //## Attribute: zero%3CC6F0AF015A
        virtual double zero () const;
        virtual void zero (double value);

        //## Attribute: scale%3CC6F0B30252
        //	Floating point scale factor for image data that takes
        //	the value of the BSCALE parameter.
        virtual double scale () const;
        virtual void scale (double value);

      //## Get and Set Operations for Associations (generated)

        //## Association: CCfits::<unnamed>%3803955F7650
        //## Role: HDU::keyWord%3803956020F8
        //## Qualifier: keyname%3818C07EE9F0; const string&
        const std::map<string,Keyword*>& keyWord () const;
        const Keyword& keyWord (const string& keyname) const;
        void setKeyWord (const string& keyname, Keyword& value);

    public:
      // Additional Public Declarations
        //## begin CCfits::HDU%38034D916A68.public preserve=yes
      template <typename T>
      Keyword& addKey(const String& name, T val,  const String& comment);
  
      Keyword& addKey(const String& name, const char* charString, const String& comment);
      
      template <typename T>
      void readKey(const String& keyName, T& val);
      
      template <typename T>
      void readKeys(std::vector<String>& keyNames, std::vector<T>& vals);

#ifdef TEMPLATE_AMBIG_DEFECT
      inline void readKeyMS(const String& keyName, int & val);
      inline void readKeys(std::vector<String>& keyNames, std::vector<String>& vals);
      
#endif

        //## end CCfits::HDU%38034D916A68.public
    protected:
      //## Constructors (specified)
        //## Operation: HDU%387F49C44258
        //	Functions as the default constructor, which is required for
        //	the map container class.
        HDU (FITSBase* p = 0);

        //## Operation: HDU%3803834F9260
        HDU (FITSBase* p, int bitpix, int naxis, const std::vector<long>& axes);

      //## Destructor (generated)
        virtual ~HDU();


      //## Other Operations (specified)
        //## Operation: readKeyword%38CE6054A2C0
        Keyword& readKeyword (const String &keyname);

        //## Operation: readKeywords%38CE62D8D050
        void readKeywords (std::list<String>& keynames);

        //## Operation: put%385A3D6D2B80
        virtual std::ostream & put (std::ostream &s) const = 0;

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: naxis%38452C8E2830
        long& naxis ();
        void naxis (const long& value);

        //## Attribute: anynul%3AF9919D025E
        //	Flags whether there were any null values found in the
        //	last read operation.
        bool& anynul ();
        void anynul (const bool& value);

      //## Get and Set Operations for Associations (generated)

        //## Association: CCfits::HDU::<unnamed>%3A1BDF0202B5
        //## Role: HDU::parent%3A1BDF0202B6
        FITSBase*& parent ();

        //## Association: CCfits::HDU::<unnamed>%3E92FCA30283
        //## Role: HDU::naxes%3E92FCA40176
        //## Qualifier: index%3E92FD6B00B4; size_t
        std::vector< long >& naxes ();
        long& naxes (size_t index);
        void naxes (size_t index, const long& value);

      // Additional Protected Declarations
        //## begin CCfits::HDU%38034D916A68.protected preserve=yes
        //## end CCfits::HDU%38034D916A68.protected

    private:

      //## Other Operations (specified)
        //## Operation: clearKeys%39522169007F
        //	clear the FITS Keyword map. To be called by
        //	the dtor and the copy/assignment operations.
        void clearKeys ();

        //## Operation: initRead%380376BE8AB0
        virtual void initRead () = 0;

        //## Operation: readHduInfo%388786291C20
        void readHduInfo ();

        //## Operation: addKeyword%397EFAA40263
        Keyword* addKeyword (Keyword* newKey);

        //## Operation: compare%380376C81C50
        virtual bool compare (const HDU &right) const;

        //## Operation: copyKeys%395221E50097
        //	clear the FITS Keyword map. To be called by
        //	the dtor and the copy/assignment operations.
        void copyKeys (const HDU& right);

        //## Operation: getNamedLines%39AFB2DD038E
        String getNamedLines (const String& name);

        //## Operation: saveReadKeyword%3CCEA0A003C7
        //	save keyword found by read all keys into the array of keywords that have been read.
        //	Similar to addKeyword except there's no write and no returned value. For use by readAllKeys()
        void saveReadKeyword (Keyword* newKey);

      // Additional Private Declarations
        //## begin CCfits::HDU%38034D916A68.private preserve=yes
        //## end CCfits::HDU%38034D916A68.private

    private: //## implementation
      // Data Members for Class Attributes

        //## begin CCfits::HDU::naxis%38452C8E2830.attr preserve=no  protected: long {U} 
        long m_naxis;
        //## end CCfits::HDU::naxis%38452C8E2830.attr

        //## begin CCfits::HDU::bitpix%3805D3F96E18.attr preserve=no  public: long {U} 
        long m_bitpix;
        //## end CCfits::HDU::bitpix%3805D3F96E18.attr

        //## begin CCfits::HDU::index%3816FC7F9028.attr preserve=no  public: int {U} 0
        int m_index;
        //## end CCfits::HDU::index%3816FC7F9028.attr

        //## begin CCfits::HDU::anynul%3AF9919D025E.attr preserve=no  protected: bool {U} false
        bool m_anynul;
        //## end CCfits::HDU::anynul%3AF9919D025E.attr

        //## begin CCfits::HDU::history%3B4B54060399.attr preserve=no  public: string {U} ""
        string m_history;
        //## end CCfits::HDU::history%3B4B54060399.attr

        //## begin CCfits::HDU::comment%3B4B54270048.attr preserve=no  public: string {U} ""
        string m_comment;
        //## end CCfits::HDU::comment%3B4B54270048.attr

        //## begin CCfits::HDU::zero%3CC6F0AF015A.attr preserve=no  public: double {U} 0
        double m_zero;
        //## end CCfits::HDU::zero%3CC6F0AF015A.attr

        //## begin CCfits::HDU::scale%3CC6F0B30252.attr preserve=no  public: double {U} 1.0
        double m_scale;
        //## end CCfits::HDU::scale%3CC6F0B30252.attr

      // Data Members for Associations

        //## Association: CCfits::<unnamed>%3803955F7650
        //## begin CCfits::HDU::keyWord%3803956020F8.role preserve=no  public: CCfits::Keyword {1..n -> 1..1RHgN}
        std::map<string,Keyword*> m_keyWord;
        //## end CCfits::HDU::keyWord%3803956020F8.role

        //## Association: CCfits::HDU::<unnamed>%3A1BDF0202B5
        //## begin CCfits::HDU::parent%3A1BDF0202B6.role preserve=no  protected: CCfits::FITSBase { -> 1..1RFHgN}
        FITSBase* m_parent;
        //## end CCfits::HDU::parent%3A1BDF0202B6.role

        //## Association: CCfits::HDU::<unnamed>%3E92FCA30283
        //## begin CCfits::HDU::naxes%3E92FCA40176.role preserve=no  protected: std::vector< long > { -> 1VHgN}
        std::vector< long > m_naxes;
        //## end CCfits::HDU::naxes%3E92FCA40176.role

      // Additional Implementation Declarations
        //## begin CCfits::HDU%38034D916A68.implementation preserve=yes
      friend fitsfile* Keyword::fitsPointer() const;
      friend Keyword* KeywordCreator::getKeyword(const String& keyname, HDU* p);
      friend Keyword* KeywordCreator::getKeyword(const String& keyname, ValueType keyType, HDU* p);
        //## end CCfits::HDU%38034D916A68.implementation
  };

  //## begin CCfits::HDU%38034D916A68.postscript preserve=yes
  template <typename T>
  Keyword& HDU::addKey(const String& name, T value,  const String& comment)
  {
              makeThisCurrent();
              NewKeyword<T> keyCreator(this,value);
              Keyword& newKey = *(addKeyword(keyCreator.createKeyword(name,comment)));
              return newKey;
  } 

  template <typename T>
  void HDU::readKey(const String& keyName, T& val)
  {
          makeThisCurrent();
          Keyword& key = readKeyword(keyName);
          key.value(val);
  }


  template <typename T>
  void HDU::readKeys(std::vector<String>& keyNames, std::vector<T>& vals)
  {
          size_t nRead = keyNames.size();

          std::list<String> valKeys;
          std::list<T>      valList;
          for (size_t i = 0; i < nRead; i++) valKeys.push_back(keyNames[i]);
          // read all the keys requested, rejecting those that don't exist.

          readKeywords(valKeys);

          // get the values of all of the requested keys, rejecting those of the
          // wrong type.

          T current;
          std::list<String>::iterator it = valKeys.begin(); 
          while (it != valKeys.end())
          {
                  try
                  {
                          m_keyWord[*it]->value(current);
                          valList.push_back(current);       
			  ++it;
                  }
                  catch ( Keyword::WrongKeywordValueType )
                  {
                          it = valKeys.erase(it);                         
                  }
          }

          keyNames.erase(keyNames.begin(),keyNames.end());       

          if (!valList.empty())
          {
                  if (valList.size() != vals.size()) vals.resize(valList.size());

                  size_t i=0;
                  for (typename std::list<T>::const_iterator it1 
                                  = valList.begin(); it1 != valList.end(); ++it1,++i)
                  {
                          vals[i] = *it1;
                  }
                  for (std::list<String>::const_iterator it1= valKeys.begin(); it1 != valKeys.end(); ++it1)
                  {
                          keyNames.push_back(*it1);
                  }
          }

  }
  //## end CCfits::HDU%38034D916A68.postscript

  // Class CCfits::HDU::InvalidImageDataType 

  // Class CCfits::HDU::InvalidExtensionType 

  // Class CCfits::HDU::NoSuchKeyword 

  // Class CCfits::HDU::NoNullValue 

  // Class CCfits::HDU 


  //## Other Operations (inline)
  inline std::map<String, Keyword*> HDU::keyWord ()
  {
    //## begin CCfits::HDU::keyWord%39467076039D.body preserve=yes
    //## end CCfits::HDU::keyWord%39467076039D.body

    return m_keyWord;
  }

  inline Keyword& HDU::keyWord (const String& keyName)
  {
    //## begin CCfits::HDU::keyWord%394A7ED900AD.body preserve=yes
  std::map<String,Keyword*>::iterator key = m_keyWord.find(keyName);
  if (key == m_keyWord.end()) throw HDU::NoSuchKeyword(keyName);
  return *((*key).second);
    //## end CCfits::HDU::keyWord%394A7ED900AD.body
  }

  inline std::ostream& operator << (std::ostream& s, const CCfits::HDU& right)
  {
    //## begin CCfits::HDU::operator<<%3A14643D01B1.body preserve=yes
     return right.put(s);
    //## end CCfits::HDU::operator<<%3A14643D01B1.body
  }

  inline long HDU::axes () const
  {
    //## begin CCfits::HDU::axes%3B4DB00B0184.body preserve=yes
    //## end CCfits::HDU::axes%3B4DB00B0184.body

    return m_naxis;
  }

  inline long HDU::axis (size_t index) const
  {
    //## begin CCfits::HDU::axis%3B4DB04400CF.body preserve=yes
    //## end CCfits::HDU::axis%3B4DB04400CF.body

    return m_naxes[index];
  }

  inline void HDU::index (int value)
  {
    //## begin CCfits::HDU::index%3B5EE0B40269.body preserve=yes
    //## end CCfits::HDU::index%3B5EE0B40269.body

    m_index = value;
  }

  inline void HDU::saveReadKeyword (Keyword* newKey)
  {
    //## begin CCfits::HDU::saveReadKeyword%3CCEA0A003C7.body preserve=yes
    m_keyWord.insert(std::map<String,Keyword*>::value_type(newKey->name(),newKey->clone()));
    //## end CCfits::HDU::saveReadKeyword%3CCEA0A003C7.body
  }

  //## Get and Set Operations for Class Attributes (inline)

  inline long& HDU::naxis ()
  {
    //## begin CCfits::HDU::naxis%38452C8E2830.get preserve=no
    return m_naxis;
    //## end CCfits::HDU::naxis%38452C8E2830.get
  }

  inline void HDU::naxis (const long& value)
  {
    //## begin CCfits::HDU::naxis%38452C8E2830.set preserve=no
    m_naxis = value;
    //## end CCfits::HDU::naxis%38452C8E2830.set
  }

  inline long HDU::bitpix () const
  {
    //## begin CCfits::HDU::bitpix%3805D3F96E18.get preserve=no
    return m_bitpix;
    //## end CCfits::HDU::bitpix%3805D3F96E18.get
  }

  inline void HDU::bitpix (long value)
  {
    //## begin CCfits::HDU::bitpix%3805D3F96E18.set preserve=no
    m_bitpix = value;
    //## end CCfits::HDU::bitpix%3805D3F96E18.set
  }

  inline int HDU::index () const
  {
    //## begin CCfits::HDU::index%3816FC7F9028.get preserve=no
    return m_index;
    //## end CCfits::HDU::index%3816FC7F9028.get
  }

  inline bool& HDU::anynul ()
  {
    //## begin CCfits::HDU::anynul%3AF9919D025E.get preserve=no
    return m_anynul;
    //## end CCfits::HDU::anynul%3AF9919D025E.get
  }

  inline void HDU::anynul (const bool& value)
  {
    //## begin CCfits::HDU::anynul%3AF9919D025E.set preserve=no
    m_anynul = value;
    //## end CCfits::HDU::anynul%3AF9919D025E.set
  }

  inline const string& HDU::history () const
  {
    //## begin CCfits::HDU::history%3B4B54060399.get preserve=no
    return m_history;
    //## end CCfits::HDU::history%3B4B54060399.get
  }

  inline const string& HDU::comment () const
  {
    //## begin CCfits::HDU::comment%3B4B54270048.get preserve=no
    return m_comment;
    //## end CCfits::HDU::comment%3B4B54270048.get
  }

  inline double HDU::zero () const
  {
    //## begin CCfits::HDU::zero%3CC6F0AF015A.get preserve=no
    return m_zero;
    //## end CCfits::HDU::zero%3CC6F0AF015A.get
  }

  inline void HDU::zero (double value)
  {
    //## begin CCfits::HDU::zero%3CC6F0AF015A.set preserve=no
    m_zero = value;
    //## end CCfits::HDU::zero%3CC6F0AF015A.set
  }

  inline double HDU::scale () const
  {
    //## begin CCfits::HDU::scale%3CC6F0B30252.get preserve=no
    return m_scale;
    //## end CCfits::HDU::scale%3CC6F0B30252.get
  }

  inline void HDU::scale (double value)
  {
    //## begin CCfits::HDU::scale%3CC6F0B30252.set preserve=no
    m_scale = value;
    //## end CCfits::HDU::scale%3CC6F0B30252.set
  }

  //## Get and Set Operations for Associations (inline)

  inline const std::map<string,Keyword*>& HDU::keyWord () const
  {
    //## begin CCfits::HDU::keyWord%3803956020F8.get preserve=no
    return m_keyWord;
    //## end CCfits::HDU::keyWord%3803956020F8.get
  }

  inline const Keyword& HDU::keyWord (const string& keyname) const
  {
    //## begin CCfits::HDU::keyWord%3803956020F8.qualget preserve=yes
  std::map<String,Keyword*>::const_iterator key = m_keyWord.find(keyname);
  if (key == m_keyWord.end()) throw HDU::NoSuchKeyword(keyname);
  return *((*key).second);
    //## end CCfits::HDU::keyWord%3803956020F8.qualget
  }

  inline void HDU::setKeyWord (const string& keyname, Keyword& value)
  {
    //## begin CCfits::HDU::setKeyWord%3803956020F8.qualset preserve=yes
  m_keyWord[keyname] = &value;
    //## end CCfits::HDU::setKeyWord%3803956020F8.qualset
  }

  inline FITSBase*& HDU::parent ()
  {
    //## begin CCfits::HDU::parent%3A1BDF0202B6.get preserve=no
    return m_parent;
    //## end CCfits::HDU::parent%3A1BDF0202B6.get
  }

  inline std::vector< long >& HDU::naxes ()
  {
    //## begin CCfits::HDU::naxes%3E92FCA40176.get preserve=no
    return m_naxes;
    //## end CCfits::HDU::naxes%3E92FCA40176.get
  }

  inline long& HDU::naxes (size_t index)
  {
    //## begin CCfits::HDU::naxes%3E92FCA40176.qualget preserve=yes
    return m_naxes[index];
    //## end CCfits::HDU::naxes%3E92FCA40176.qualget
  }

  inline void HDU::naxes (size_t index, const long& value)
  {
    //## begin CCfits::HDU::naxes%3E92FCA40176.qualset preserve=yes
    m_naxes[index] = value;
    //## end CCfits::HDU::naxes%3E92FCA40176.qualset
  }

} // namespace CCfits

//## begin module%38034DE11FA8.epilog preserve=yes
#ifdef SPEC_TEMPLATE_IMP_DEFECT
namespace CCfits {
        
  inline void HDU::readKeyMS(const String& keyName, int & val)
  {
          makeThisCurrent();
          Keyword& key = readKeyword(keyName);
          key.value(val);
  }

  inline void HDU::readKeys(std::vector<String>& keyNames, std::vector<String>& vals)
  {
          size_t nRead = keyNames.size();

          std::list<String> valKeys;
          std::list<String>      valList;
          for (size_t i = 0; i < nRead; i++) valKeys.push_back(keyNames[i]);
          // read all the keys requested, rejecting those that don't exist.

          readKeywords(valKeys);

          // get the values of all of the requested keys, rejecting those of the
          // wrong type.

          String current;
          std::list<String>::iterator it = valKeys.begin(); 
          while (it != valKeys.end())
          {
                  try
                  {
                          m_keyWord[*it]->value(current);
                          valList.push_back(current);       
			  ++it;
                  }
                  catch ( Keyword::WrongKeywordValueType )
                  {
                          it = valKeys.erase(it);                         
                  }
          }

          keyNames.erase(keyNames.begin(),keyNames.end());       

          if (!valList.empty())
          {
                  if (valList.size() != vals.size()) vals.resize(valList.size());

                  size_t i=0;
				  std::list<String>::const_iterator it1 = valList.begin();
                  for ( ; it1 != valList.end(); ++it1,++i)
                  {
                          vals[i] = *it1;
                  }
                  for ( it1= valKeys.begin(); it1 != valKeys.end(); ++it1)
                  {
                          keyNames.push_back(*it1);
                  }
          }

  }
}
 #endif
//## end module%38034DE11FA8.epilog


#endif
