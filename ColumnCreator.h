//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%387B3FB16F00.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%387B3FB16F00.cm

//## begin module%387B3FB16F00.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%387B3FB16F00.cp

//## Module: ColumnCreator%387B3FB16F00; Package specification
//## Subsystem: CCfits::Column%3934116D0008
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/ColumnCreator.h

#ifndef COLUMNCREATOR_H
#define COLUMNCREATOR_H 1

//## begin module%387B3FB16F00.additionalIncludes preserve=no
#include <iostream>
//## end module%387B3FB16F00.additionalIncludes

// ColumnVectorData
#include "ColumnVectorData.h"
// ColumnData
#include "ColumnData.h"

namespace CCfits {
  class Table;
  class Column;

} // namespace CCfits

//## begin module%387B3FB16F00.includes preserve=yes
#include <string>
#include <vector>
//## end module%387B3FB16F00.includes

//## begin module%387B3FB16F00.declarations preserve=no
//## end module%387B3FB16F00.declarations

//## begin module%387B3FB16F00.additionalDeclarations preserve=yes
//## end module%387B3FB16F00.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::ColumnCreator%387B3F5C4150.preface preserve=yes
  //## end CCfits::ColumnCreator%387B3F5C4150.preface

  //## Class: ColumnCreator%387B3F5C4150
  //## Category: CCfits::Column%393417970264
  //## Subsystem: CCfits::Column%3934116D0008
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%3948EB1300DC;ColumnData { -> F}
  //## Uses: <unnamed>%3948EB2501A4;ColumnVectorData { -> F}
  //## Uses: <unnamed>%3948F05300B3;Column { -> F}
  //## Uses: <unnamed>%39806F5D0175;Table { -> F}
  //## Uses: <unnamed>%3B0D30FD014A;ColumnVectorData { -> }
  //## Uses: <unnamed>%3B0D31000238;ColumnData { -> }

  class ColumnCreator 
  {
    //## begin CCfits::ColumnCreator%387B3F5C4150.initialDeclarations preserve=yes
    //## end CCfits::ColumnCreator%387B3F5C4150.initialDeclarations

    public:
      //## Constructors (specified)
        //## Operation: ColumnCreator%3B000490020D
        ColumnCreator (Table* p);

      //## Destructor (generated)
        virtual ~ColumnCreator();


      //## Other Operations (specified)
        //## Operation: reset%387B42144D90
        void reset ();

        //## Operation: getColumn%394682C701CA
        //	getColumn is a calling function for MakeColumn, i.e.
        //	it specifies a column in an existing file to be  "got"
        Column * getColumn (int number, const String& name, const String& format, const String& unit = "");

        //## Operation: createColumn%3B000364025A
        //	createColumn is for specifying input data for creating
        //	new columns in tables.
        Column * createColumn (int number, ValueType type, const String &name, const String &format, const String &unit, long repeat = 1, long width = 1, double scaleFactor = 1., double offset = 0, const String &comment = "");

      // Additional Public Declarations
        //## begin CCfits::ColumnCreator%387B3F5C4150.public preserve=yes
        //## end CCfits::ColumnCreator%387B3F5C4150.public

    protected:

      //## Other Operations (specified)
        //## Operation: MakeColumn%38F629D3C010
        //	MakeColumn is a virtual function that makes a Column
        //	object with appropriate data member from an existing
        //	column in a file.
        virtual Column * MakeColumn (const int index, const String &name, const String &format, const String &unit, const long repeat, const long width, const String &comment = "", const int decimals = 0);

      // Additional Protected Declarations
        //## begin CCfits::ColumnCreator%387B3F5C4150.protected preserve=yes
        //## end CCfits::ColumnCreator%387B3F5C4150.protected

    private:

      //## Other Operations (specified)
        //## Operation: getScaling%3CC996820340
        void getScaling (int index, int& type, long& repeat, long& width, double& tscale, double& tzero);

      //## Get and Set Operations for Class Attributes (generated)

        //## Attribute: parent%3B0003D703BA
        const Table* parent () const;
        void parent (Table* value);

      // Additional Private Declarations
        //## begin CCfits::ColumnCreator%387B3F5C4150.private preserve=yes
        //## end CCfits::ColumnCreator%387B3F5C4150.private

    private: //## implementation
      // Data Members for Class Attributes

        //## Attribute: column%387B40A7AB38
        //## begin CCfits::ColumnCreator::column%387B40A7AB38.attr preserve=no  private: Column * {U} 
        Column *m_column;
        //## end CCfits::ColumnCreator::column%387B40A7AB38.attr

        //## begin CCfits::ColumnCreator::parent%3B0003D703BA.attr preserve=no  private: Table* {U} p
        Table* m_parent;
        //## end CCfits::ColumnCreator::parent%3B0003D703BA.attr

      // Additional Implementation Declarations
        //## begin CCfits::ColumnCreator%387B3F5C4150.implementation preserve=yes
        //## end CCfits::ColumnCreator%387B3F5C4150.implementation

  };

  //## begin CCfits::ColumnCreator%387B3F5C4150.postscript preserve=yes
  //## end CCfits::ColumnCreator%387B3F5C4150.postscript

  // Class CCfits::ColumnCreator 


  //## Other Operations (inline)
  inline void ColumnCreator::reset ()
  {
    //## begin CCfits::ColumnCreator::reset%387B42144D90.body preserve=yes
    m_column = 0;
    //## end CCfits::ColumnCreator::reset%387B42144D90.body
  }

  //## Get and Set Operations for Class Attributes (inline)

  inline const Table* ColumnCreator::parent () const
  {
    //## begin CCfits::ColumnCreator::parent%3B0003D703BA.get preserve=no
    return m_parent;
    //## end CCfits::ColumnCreator::parent%3B0003D703BA.get
  }

  inline void ColumnCreator::parent (Table* value)
  {
    //## begin CCfits::ColumnCreator::parent%3B0003D703BA.set preserve=no
    m_parent = value;
    //## end CCfits::ColumnCreator::parent%3B0003D703BA.set
  }

} // namespace CCfits

//## begin module%387B3FB16F00.epilog preserve=yes
//## end module%387B3FB16F00.epilog


#endif
