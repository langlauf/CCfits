//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%394167F501A4.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%394167F501A4.cm

//## begin module%394167F501A4.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%394167F501A4.cp

//## Module: NewColumn%394167F501A4; Package specification
//## Subsystem: CCfits::Column%3934116D0008
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/NewColumn.h

#ifndef NEWCOLUMN_H
#define NEWCOLUMN_H 1

//## begin module%394167F501A4.additionalIncludes preserve=no
//## end module%394167F501A4.additionalIncludes

// valarray
#include <valarray>
// ColumnCreator
#include "ColumnCreator.h"
// FITSUtil
#include "FITSUtil.h"
//## begin module%394167F501A4.includes preserve=yes
//## end module%394167F501A4.includes

//## begin module%394167F501A4.declarations preserve=no
//## end module%394167F501A4.declarations

//## begin module%394167F501A4.additionalDeclarations preserve=yes
//## end module%394167F501A4.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::NewColumn%39416761003E.preface preserve=yes
  //## end CCfits::NewColumn%39416761003E.preface

  //## Class: NewColumn%39416761003E; Parameterized Class
  //## Category: CCfits::Column%393417970264
  //## Subsystem: CCfits::Column%3934116D0008
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  template <typename T>
  class NewColumn : public ColumnCreator  //## Inherits: <unnamed>%394167D103C5
  {
    //## begin CCfits::NewColumn%39416761003E.initialDeclarations preserve=yes
    //## end CCfits::NewColumn%39416761003E.initialDeclarations

    public:
      //## Constructors (specified)
        //## Operation: NewColumn%39490A2A0224
        NewColumn (vector<T>& data);

      //## Destructor (generated)
        virtual ~NewColumn();

      // Additional Public Declarations
        //## begin CCfits::NewColumn%39416761003E.public preserve=yes
        //## end CCfits::NewColumn%39416761003E.public

    protected:

      //## Other Operations (specified)
        //## Operation: MakeColumn%3946730802B0
        virtual Column* MakeColumn (const int index, const string &name, const string &format, const string &unit, const long repeat, const long width, const string &comment = "", const int decimals = 0);

      // Additional Protected Declarations
        //## begin CCfits::NewColumn%39416761003E.protected preserve=yes
        //## end CCfits::NewColumn%39416761003E.protected

    private:
      //## Constructors (generated)
        NewColumn(const NewColumn< T > &right);

      //## Assignment Operation (generated)
        NewColumn< T > & operator=(const NewColumn< T > &right);

      // Additional Private Declarations
        //## begin CCfits::NewColumn%39416761003E.private preserve=yes
        //## end CCfits::NewColumn%39416761003E.private

    private: //## implementation
      // Additional Implementation Declarations
        //## begin CCfits::NewColumn%39416761003E.implementation preserve=yes
        //## end CCfits::NewColumn%39416761003E.implementation

  };

  //## begin CCfits::NewColumn%39416761003E.postscript preserve=yes
  //## end CCfits::NewColumn%39416761003E.postscript

  //## begin CCfits::NewVectorColumn%3941677F0324.preface preserve=yes
  //## end CCfits::NewVectorColumn%3941677F0324.preface

  //## Class: NewVectorColumn%3941677F0324; Parameterized Class
  //## Category: CCfits::Column%393417970264
  //## Subsystem: CCfits::Column%3934116D0008
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%394908F8035D;std::valarray { -> }

  template <typename T>
  class NewVectorColumn : public ColumnCreator  //## Inherits: <unnamed>%394167CE0009
  {
    //## begin CCfits::NewVectorColumn%3941677F0324.initialDeclarations preserve=yes
    //## end CCfits::NewVectorColumn%3941677F0324.initialDeclarations

    public:
      //## Constructors (specified)
        //## Operation: NewVectorColumn%39490994038E
        NewVectorColumn (std::vector<std::valarray<T> >& data);

      //## Destructor (generated)
        virtual ~NewVectorColumn();

      // Additional Public Declarations
        //## begin CCfits::NewVectorColumn%3941677F0324.public preserve=yes
        //## end CCfits::NewVectorColumn%3941677F0324.public

    protected:

      //## Other Operations (specified)
        //## Operation: MakeColumn%39467360014E
        virtual Column * MakeColumn (const int index, const string &name, const string &format, const string &unit, const long repeat, const long width, const string &comment = "", const int decimals = 0);

      // Additional Protected Declarations
        //## begin CCfits::NewVectorColumn%3941677F0324.protected preserve=yes
        //## end CCfits::NewVectorColumn%3941677F0324.protected

    private:
      //## Constructors (generated)
        NewVectorColumn(const NewVectorColumn< T > &right);

      //## Assignment Operation (generated)
        NewVectorColumn< T > & operator=(const NewVectorColumn< T > &right);

      // Additional Private Declarations
        //## begin CCfits::NewVectorColumn%3941677F0324.private preserve=yes
        //## end CCfits::NewVectorColumn%3941677F0324.private

    private: //## implementation
      // Additional Implementation Declarations
        //## begin CCfits::NewVectorColumn%3941677F0324.implementation preserve=yes
        //## end CCfits::NewVectorColumn%3941677F0324.implementation

  };

  //## begin CCfits::NewVectorColumn%3941677F0324.postscript preserve=yes
  //## end CCfits::NewVectorColumn%3941677F0324.postscript

  // Parameterized Class CCfits::NewColumn 

  // Parameterized Class CCfits::NewVectorColumn 

  // Parameterized Class CCfits::NewColumn 

  template <typename T>
  NewColumn<T>::NewColumn (vector<T>& data)
    //## begin CCfits::NewColumn::NewColumn%39490A2A0224.hasinit preserve=yes
     : m_newData(data)
    //## end CCfits::NewColumn::NewColumn%39490A2A0224.hasinit
    //## begin CCfits::NewColumn::NewColumn%39490A2A0224.initialization preserve=yes
    //## end CCfits::NewColumn::NewColumn%39490A2A0224.initialization
  {
    //## begin CCfits::NewColumn::NewColumn%39490A2A0224.body preserve=yes
    //## end CCfits::NewColumn::NewColumn%39490A2A0224.body
  }


  template <typename T>
  NewColumn<T>::~NewColumn()
  {
    //## begin CCfits::NewColumn::~NewColumn%39416761003E_dest.body preserve=yes
    //## end CCfits::NewColumn::~NewColumn%39416761003E_dest.body
  }



  //## Other Operations (implementation)
  template <typename T>
  Column* NewColumn<T>::MakeColumn (const int index, const string &name, const string &format, const string &unit, const long repeat, const long width, const string &comment, const int decimals)
  {
    //## begin CCfits::NewColumn::MakeColumn%3946730802B0.body preserve=yes
   FITSUtils::MatchType<T> findType;
   
   
   ColumnData<T>* newColumn = new ColumnData(index,name,findType(),format,unit,p,repeat,width,comment);  
   newColumn->data(m_newData);
   return newColumn;   
    //## end CCfits::NewColumn::MakeColumn%3946730802B0.body
  }

  // Additional Declarations
    //## begin CCfits::NewColumn%39416761003E.declarations preserve=yes
    //## end CCfits::NewColumn%39416761003E.declarations

  // Parameterized Class CCfits::NewVectorColumn 

  template <typename T>
  NewVectorColumn<T>::NewVectorColumn (std::vector<std::valarray<T> >& data)
    //## begin CCfits::NewVectorColumn::NewVectorColumn%39490994038E.hasinit preserve=no
    //## end CCfits::NewVectorColumn::NewVectorColumn%39490994038E.hasinit
    //## begin CCfits::NewVectorColumn::NewVectorColumn%39490994038E.initialization preserve=yes
    //## end CCfits::NewVectorColumn::NewVectorColumn%39490994038E.initialization
  {
    //## begin CCfits::NewVectorColumn::NewVectorColumn%39490994038E.body preserve=yes
    //## end CCfits::NewVectorColumn::NewVectorColumn%39490994038E.body
  }


  template <typename T>
  NewVectorColumn<T>::~NewVectorColumn()
  {
    //## begin CCfits::NewVectorColumn::~NewVectorColumn%3941677F0324_dest.body preserve=yes
    //## end CCfits::NewVectorColumn::~NewVectorColumn%3941677F0324_dest.body
  }



  //## Other Operations (implementation)
  template <typename T>
  Column * NewVectorColumn<T>::MakeColumn (const int index, const string &name, const string &format, const string &unit, const long repeat, const long width, const string &comment, const int decimals)
  {
    //## begin CCfits::NewVectorColumn::MakeColumn%39467360014E.body preserve=yes
    //## end CCfits::NewVectorColumn::MakeColumn%39467360014E.body
  }

  // Additional Declarations
    //## begin CCfits::NewVectorColumn%3941677F0324.declarations preserve=yes
    //## end CCfits::NewVectorColumn%3941677F0324.declarations

} // namespace CCfits

//## begin module%394167F501A4.epilog preserve=yes
//## end module%394167F501A4.epilog


#endif
