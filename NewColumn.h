
//	This is version 1.1.1 release dated Sept 2002

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	Sept 2002 Ben Dorman, L3-Communications
//	e-mail: ccfits@legacy.gsfc.nasa.gov


#ifndef NEWCOLUMN_H
#define NEWCOLUMN_H 1


// vector
#include <vector>
// valarray
#include <valarray>
// ColumnCreator
#include "ColumnCreator.h"
// FITSUtil
#include "FITSUtil.h"




namespace CCfits {





  template <typename T>
  class NewColumn : public ColumnCreator  //## Inherits: <unnamed>%394167D103C5
  {

    public:
        NewColumn (vector<T>& data);

        virtual ~NewColumn();

      // Additional Public Declarations

    protected:

        virtual Column* MakeColumn (const int index, const string &name, const string &format, const string &unit, const long repeat, const long width, const string &comment = "", const int decimals = 0);

      // Additional Protected Declarations

    private:
        NewColumn(const NewColumn< T > &right);

        NewColumn< T > & operator=(const NewColumn< T > &right);


        const std::vector<T>& newData () const;

      // Additional Private Declarations

    private: //## implementation
      // Data Members for Associations

        std::vector<T> m_newData;

      // Additional Implementation Declarations

  };







  template <typename T>
  class NewVectorColumn : public ColumnCreator  //## Inherits: <unnamed>%394167CE0009
  {

    public:
        NewVectorColumn (std::vector<std::valarray<T> >& data);

        virtual ~NewVectorColumn();

      // Additional Public Declarations

    protected:

        virtual Column * MakeColumn (const int index, const string &name, const string &format, const string &unit, const long repeat, const long width, const string &comment = "", const int decimals = 0);

      // Additional Protected Declarations

    private:
        NewVectorColumn(const NewVectorColumn< T > &right);

        NewVectorColumn< T > & operator=(const NewVectorColumn< T > &right);


        const std::vector< std::valarray<T> >& newData () const;

      // Additional Private Declarations

    private: //## implementation
      // Data Members for Associations

        std::vector< std::valarray<T> > m_newData;

      // Additional Implementation Declarations

  };


  // Parameterized Class CCfits::NewColumn 


  template <typename T>
  inline const std::vector<T>& NewColumn<T>::newData () const
  {
    return m_newData;
  }

  // Parameterized Class CCfits::NewVectorColumn 


  template <typename T>
  inline const std::vector< std::valarray<T> >& NewVectorColumn<T>::newData () const
  {
    return m_newData;
  }

  // Parameterized Class CCfits::NewColumn 

  template <typename T>
  NewColumn<T>::NewColumn (vector<T>& data)
     : m_newData(data)
  {
  }


  template <typename T>
  NewColumn<T>::~NewColumn()
  {
  }



  template <typename T>
  Column* NewColumn<T>::MakeColumn (const int index, const string &name, const string &format, const string &unit, const long repeat, const long width, const string &comment, const int decimals)
  {
   FITSUtils::MatchType<T> findType;
   
   
   ColumnData<T>* newColumn = new ColumnData(index,name,findType(),format,unit,p,repeat,width,comment);  
   newColumn->data(m_newData);
   return newColumn;   
  }

  // Additional Declarations

  // Parameterized Class CCfits::NewVectorColumn 

  template <typename T>
  NewVectorColumn<T>::NewVectorColumn (std::vector<std::valarray<T> >& data)
  {
  }


  template <typename T>
  NewVectorColumn<T>::~NewVectorColumn()
  {
  }



  template <typename T>
  Column * NewVectorColumn<T>::MakeColumn (const int index, const string &name, const string &format, const string &unit, const long repeat, const long width, const string &comment, const int decimals)
  {
  }

  // Additional Declarations

} // namespace CCfits



#endif
