//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%380B42E7BB88.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%380B42E7BB88.cm

//## begin module%380B42E7BB88.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%380B42E7BB88.cp

//## Module: HDUCreator%380B42E7BB88; Package specification
//## Subsystem: CCfits::HDU%3826DF628F48
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/HDUCreator.h

#ifndef HDUCREATOR_H
#define HDUCREATOR_H 1

//## begin module%380B42E7BB88.additionalIncludes preserve=no
//## end module%380B42E7BB88.additionalIncludes

// string
#include <string>
// typeinfo
#include <typeinfo>
// vector
#include <vector>
// valarray
#include <valarray>
// CCfitsHeader
#include "CCfits.h"
// FitsError
#include "FitsError.h"

namespace CCfits {
  class FITSBase;
  class HDU;
  class PHDU;
  class ExtHDU;

} // namespace CCfits

//## begin module%380B42E7BB88.includes preserve=yes
//## end module%380B42E7BB88.includes

//## begin module%380B42E7BB88.declarations preserve=no
//## end module%380B42E7BB88.declarations

//## begin module%380B42E7BB88.additionalDeclarations preserve=yes
//## end module%380B42E7BB88.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::HDUCreator%380B42942CC0.preface preserve=yes
  //## end CCfits::HDUCreator%380B42942CC0.preface

  //## Class: HDUCreator%380B42942CC0; private
  //## Category: CCfits::HDU%393417220088
  //## Subsystem: CCfits::HDU%3826DF628F48
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%380B469F4A58;HDU { -> F}
  //## Uses: <unnamed>%3AF990350321;PHDU { -> F}
  //## Uses: <unnamed>%3AF9906B01BC;ExtHDU { -> F}
  //## Uses: <unnamed>%3B3386CE0287;FitsException { -> F}

  class HDUCreator 
  {
    //## begin CCfits::HDUCreator%380B42942CC0.initialDeclarations preserve=yes
    //## end CCfits::HDUCreator%380B42942CC0.initialDeclarations

    public:
      //## Constructors (specified)
        //## Operation: HDUCreator%394FD3AC025B
        HDUCreator (FITSBase* p);

      //## Destructor (generated)
        ~HDUCreator();


      //## Other Operations (specified)
        //## Operation: getHdu%38D2A19CFCF8
        //	Read a specified HDU from given fitsfile and
        //	return a pointer to it.
        HDU * getHdu (const String& hduName, bool readDataFlag = false, const std::vector<String> &keys = std::vector<String>(), bool primary = false, int version = 1);

        //## Operation: createImage%3816FF89CDC0
        PHDU * createImage (int bitpix, long naxis, const std::vector<long>& naxes);

        //## Operation: reset%380B6CDDD508
        void reset ();

        //## Operation: Make%394FD3660090
        HDU * Make (const String& hduName, bool readDataFlag, const std::vector<String> &keys, bool primary, int version);

        //## Operation: createTable%39523C1301CB
        HDU* createTable (const String &name, HduType xtype, int rows, const std::vector<String>& colName, const std::vector<String> colFmt, const std::vector<String> colUnit, int version);

        //## Operation: getHdu%3957C9D400FE
        //	Read a specified HDU from given fitsfile and
        //	return a pointer to it.
        //
        //	With no arguments this reads the PrimaryHDU.
        HDU * getHdu (int index = 0, bool readDataFlag = false, const std::vector<String> &keys = std::vector<String>());

        //## Operation: createImage%3AF989A102CA
        ExtHDU * createImage (const String &name, int bitpix, long naxis, const std::vector<long>& naxes, int version);

      // Additional Public Declarations
        //## begin CCfits::HDUCreator%380B42942CC0.public preserve=yes
        //## end CCfits::HDUCreator%380B42942CC0.public

    protected:
      // Additional Protected Declarations
        //## begin CCfits::HDUCreator%380B42942CC0.protected preserve=yes
        //## end CCfits::HDUCreator%380B42942CC0.protected

    private:

      //## Other Operations (specified)
        //## Operation: MakeImage%394FD34901AA
        PHDU * MakeImage (int bpix, int naxis, const std::vector<long>& naxes);

        //## Operation: MakeTable%39523AAE0033
        HDU* MakeTable (const String &name, HduType xtype, int rows, const std::vector<String>& colName, const std::vector<String>& colFmt, const std::vector<String>& colUnit, int version);

        //## Operation: Make%3957CA840334
        HDU * Make (int index, bool readDataFlag, const std::vector<String> &keys);

        //## Operation: MakeImage%3AF989DB0029
        ExtHDU * MakeImage (const String &name, int bpix, long naxis, const std::vector<long>& naxes, int version);

        //## Operation: getScaling%3CC6CFC40122
        void getScaling (long& type, double& zero, double& scale, long& unscaledType) const;

      //## Get and Set Operations for Associations (generated)

        //## Association: CCfits::HDU::<unnamed>%3A1BDEE100A0
        //## Role: HDUCreator::parent%3A1BDEE100A1
        void parent (FITSBase* value);

      // Data Members for Class Attributes

        //## Attribute: hdu%380B550B5B10
        //## begin CCfits::HDUCreator::hdu%380B550B5B10.attr preserve=no  protected: HDU * {U} 
        HDU *m_hdu;
        //## end CCfits::HDUCreator::hdu%380B550B5B10.attr

      // Additional Private Declarations
        //## begin CCfits::HDUCreator%380B42942CC0.private preserve=yes
        //## end CCfits::HDUCreator%380B42942CC0.private

    private: //## implementation
      // Data Members for Associations

        //## Association: CCfits::HDU::<unnamed>%3A1BDEE100A0
        //## begin CCfits::HDUCreator::parent%3A1BDEE100A1.role preserve=no  private: CCfits::FITSBase { -> 1..1RFHgN}
        FITSBase* m_parent;
        //## end CCfits::HDUCreator::parent%3A1BDEE100A1.role

      // Additional Implementation Declarations
        //## begin CCfits::HDUCreator%380B42942CC0.implementation preserve=yes
        //## end CCfits::HDUCreator%380B42942CC0.implementation

  };

  //## begin CCfits::HDUCreator%380B42942CC0.postscript preserve=yes
  //## end CCfits::HDUCreator%380B42942CC0.postscript

  // Class CCfits::HDUCreator 


  //## Other Operations (inline)
  inline HDU * HDUCreator::getHdu (const String& hduName, bool readDataFlag, const std::vector<String> &keys, bool primary, int version)
  {
    //## begin CCfits::HDUCreator::getHdu%38D2A19CFCF8.body preserve=yes
  //! Read an existing HDU object from the current fits file and return a pointer.
  if ( m_hdu == 0 ) m_hdu = Make(hduName,readDataFlag,keys,primary,version);
  return m_hdu;
    //## end CCfits::HDUCreator::getHdu%38D2A19CFCF8.body
  }

  inline void HDUCreator::reset ()
  {
    //## begin CCfits::HDUCreator::reset%380B6CDDD508.body preserve=yes
  m_hdu = 0;
    //## end CCfits::HDUCreator::reset%380B6CDDD508.body
  }

  inline HDU* HDUCreator::createTable (const String &name, HduType xtype, int rows, const std::vector<String>& colName, const std::vector<String> colFmt, const std::vector<String> colUnit, int version)
  {
    //## begin CCfits::HDUCreator::createTable%39523C1301CB.body preserve=yes
        //! Create new Table extension (write method),  and return a pointer to it.
        if (m_hdu == 0) m_hdu = MakeTable(name,xtype,rows,colName,colFmt,colUnit,version);
        return m_hdu;
    //## end CCfits::HDUCreator::createTable%39523C1301CB.body
  }

  inline HDU * HDUCreator::getHdu (int index, bool readDataFlag, const std::vector<String> &keys)
  {
    //## begin CCfits::HDUCreator::getHdu%3957C9D400FE.body preserve=yes
  //! Read HDU specified by HDU number
  if ( m_hdu == 0 ) m_hdu = Make(index,readDataFlag,keys);
  return m_hdu;
    //## end CCfits::HDUCreator::getHdu%3957C9D400FE.body
  }

  //## Get and Set Operations for Associations (inline)

  inline void HDUCreator::parent (FITSBase* value)
  {
    //## begin CCfits::HDUCreator::parent%3A1BDEE100A1.set preserve=no
    m_parent = value;
    //## end CCfits::HDUCreator::parent%3A1BDEE100A1.set
  }

} // namespace CCfits

//## begin module%380B42E7BB88.epilog preserve=yes
//## end module%380B42E7BB88.epilog


#endif
