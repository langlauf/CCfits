
//	This is version 1.1 release dated May 2002

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	May 2002 Ben Dorman, L3-Com Analytics Corporation
//	e-mail: ccfits@legacy.gsfc.nasa.gov


#ifndef COLUMNCREATOR_H
#define COLUMNCREATOR_H 1

#include <iostream>

// ColumnVectorData
#include "ColumnVectorData.h"
// ColumnData
#include "ColumnData.h"

namespace CCfits {
  class Table;
  class Column;

} // namespace CCfits

#include <string>
#include <vector>


using std::string;


namespace CCfits {






  class ColumnCreator 
  {

    public:
        ColumnCreator (Table* p);

        virtual ~ColumnCreator();


        void reset ();

        //	getColumn is a calling function for MakeColumn, i.e.
        //	it specifies a column in an existing file to be  "got"
        Column * getColumn (int number, const string& name, const string& format, const string& unit = "");

        //	createColumn is for specifying input data for creating
        //	new columns in tables.
        Column * createColumn (int number, ValueType type, const string &name, const string &format, const string &unit, long repeat = 1, long width = 1, double scaleFactor = 1., double offset = 0, const string &comment = "");

      // Additional Public Declarations

    protected:

        //	MakeColumn is a virtual function that makes a Column
        //	object with appropriate data member from an existing
        //	column in a file.
        virtual Column * MakeColumn (const int index, const string &name, const string &format, const string &unit, const long repeat, const long width, const string &comment = "", const int decimals = 0);

      // Additional Protected Declarations

    private:

        void getScaling (int index, int& type, long& repeat, long& width, double& tscale, double& tzero);


        const Table* parent () const;
        void parent (Table* value);

      // Additional Private Declarations

    private: //## implementation
      // Data Members for Class Attributes

        Column *m_column;

        Table* m_parent;

      // Additional Implementation Declarations

  };


  // Class CCfits::ColumnCreator 


  inline void ColumnCreator::reset ()
  {
    m_column = 0;
  }


  inline const Table* ColumnCreator::parent () const
  {
    return m_parent;
  }

  inline void ColumnCreator::parent (Table* value)
  {
    m_parent = value;
  }

} // namespace CCfits



#endif
