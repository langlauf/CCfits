//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%384D1F571C70.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%384D1F571C70.cm

//## begin module%384D1F571C70.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%384D1F571C70.cp

//## Module: FITSUtil%384D1F571C70; Package specification
//## Subsystem: CCfits::Utility%3949241F026A
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/FITSUtil.h

#ifndef FITSUTIL_H
#define FITSUTIL_H 1

//## begin module%384D1F571C70.additionalIncludes preserve=no
#include "CCfits.h"
//## end module%384D1F571C70.additionalIncludes

// string
#include <string>
// complex
#include <complex>
// vector
#include <vector>
// valarray
#include <valarray>
// functional
#include <functional>
// FitsError
#include "FitsError.h"
//## begin module%384D1F571C70.includes preserve=yes
#include <typeinfo>
//## end module%384D1F571C70.includes

//## begin module%384D1F571C70.declarations preserve=no
//## end module%384D1F571C70.declarations

//## begin module%384D1F571C70.additionalDeclarations preserve=yes
//## end module%384D1F571C70.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  namespace FITSUtil {
    //## begin CCfits::FITSUtil%3820548A5050.initialDeclarations preserve=yes
 
/*! \namespace FITSUtil

\brief FITSUtil is a namespace containing functions used internally by CCfits, but
which might be of use for other applications. 

*/



/*! \class  MatchName

    \brief  predicate for classes that have a name attribute; match input string with instance name.
    
    Usage: MatchName<NamedClass> Ex;
    
    list<NamedClass> ListObject;
    
    //
    ...
    ...
    //
    
    find_if(ListObject.begin(),ListObject().end(),bind2nd(Ex,"needle"));
    
    
    Since most of the classes within CCfits are not implemented with lists, these
    functions are now of little direct use.

*/



/*! \class  MatchPtrName

    \brief  as for MatchName, only with the input class a pointer.


*/

/*! \class  MatchNum

    \brief  predicate for classes that have an index attribute; match input index with instance value.

    Usage: MatchName<IndexedClass> Ex;
    
    list<NamedClass> ListObject;
    
    //
    ...
    ...
    //
    
    find_if(ListObject.begin(),ListObject().end(),bind2nd(Ex,5));
    
    
    Since most of the classes within CCfits are implemented with std::maps
	 rather than lists, these functions are now of little direct use.
*/

/*! \class  MatchPtrNum
    \brief  as for MatchNum, only with the input class a pointer.
*/

/*! \class  MatchType

    \brief  function object that returns the FITS ValueType corresponding to an input intrinsic type

    This is particularly useful inside templated class instances where calls to cfitsio
    need to supply a value type. With this function one can extract the value type from
    the class type.
    
    <I>
    usage:
    
    MatchType<T> type;
    
    ValueType dataType = type();
    </I>
    
    Uses run-time type information (RTTI) methods.

*/

/*! \class  MatchType::UnrecognizedType
    @ingroup FITSexcept
    @brief  exception thrown by MatchType if it encounters data type incompatible with cfitsio.
    
*/

 
    
/*! \class  auto_array_ptr

   \brief A class that mimics the std:: library auto_ptr class, but works
   with arrays.
   
   This code was written by Jack Reeves and first appeared C++ Report, March 1996
   edition. Although some authors think one shouldn't need such a contrivance, there
   seems to be a need for it when wrapping C code.
   
   Usage: replace
   
   float* <i>f</i> = new float[200];
   
   with
                   
   FITSUtil::auto_array_ptr<float> <i>f(new float[200])</i>;
   
   Then the memory will be managed correctly in the presence of exceptions, and
   delete will be called automatically for <i>f</i> when leaving scope.
   
*/   

/*! \fn          explicit auto_array_ptr<X>::auto_array_ptr (X* p = 0) throw ();

        \brief constructor. allows creation of pointer to null, can be modified by reset()
*/

/*! \fn          explicit auto_array_ptr<X>::auto_array_ptr (auto_array_ptr<X>& right) throw ();
        \brief copy constructor
*/

/*!\fn          auto_array_ptr<X>::~auto_array_ptr();
        \brief destructor.
*/


/*!\fn            void auto_array_ptr<X>::operator = (auto_array_ptr<X>& right);
                \brief assignment operator: transfer of ownership semantics

*/



/*!\fn            X& auto_array_ptr<X>::operator * () throw ();
                \brief deference operator


*/

/*!\fn            X& auto_array_ptr<X>::operator [] (size_t i) throw ();
                \brief return a reference to the ith element of the array
*/

/*!\fn            X auto_array_ptr<X>::operator [] (size_t i) const throw ();
                \brief return a copy of the ith element of the array

*/

/*!\fn            X* auto_array_ptr<X>::get () const;
        \brief return a token for the underlying content of *this


*/

/*!\fn            X* auto_array_ptr<X>::release () throw ();

        \brief return underlying content of  *this, transferring memory ownership


*/

/*!\fn            X* auto_array_ptr<X>::reset (X* p) throw ();

        \brief change the content of the  auto_array_ptr to p

*/
    
/*!\fn            static void auto_array_ptr<X>::remove (X*& x) throw ();

        \brief utility function to delete the memory owned by x and set it to null.

*/

/*! \fn  char** CharArray(const std::vector<string>& inArray)

    \brief  function object that returns a C-array of strings from a 
    std::vector< std::vector<std::string> > object, such as used in a string valued Table column.
    
    This exists because the return type for a specialization (T**) is incompatible
    with typenames T other than string, which return a T*.
*/                        
                            
/*! \class CVarray

        \brief Function object class for returning C arrays from standard library objects used
        in the FITS library implementation. 
        
        There are 3 versions which convert std::vector<T>, std::valarray<T>, 
        and std::vector<std::valarray<T> > objects to pointers to T, called
        CVarray, CAarray, and CVAarray.
        
        An alternative function, CharArray, is provided to deal with the special case of
        vector string arrays.
        
*/

/*! \fn  T* CVarray<T>::operator () (const std::vector<T>& inArray);

                \brief operator returning C array for use with scalar column data.
*/

/*! \class CAarray
        \brief  function object returning C array from a valarray. see CVarray for
        details                            
*/
   

                                                                                             
                                
/*! \fn  T* CAarray<T>::operator () (const std::valarray<T>& inArray);

                \brief operator returning C array for use with image data.

*/  
                                                              
/*! \class CVAarray
        \brief  function object returning C array from a vector of valarrays. see CVarray for
        details                            
*/                                

/*! \fn  T* CVAarray<T>::operator () (const std::vector< std::valarray<T> >& inArray);

                \brief operator returning C array for use with vector column data.

*/

                                
/*! \fn template <typename S, typename T> void fill(std::vector< S > &outArray, const std::vector< T > &inArray, size_t first, size_t last);
  
  \brief Convert input vector of type T to output vector of type S.

   The functions FITSUtil::fill do conversions between CCfits' internal representation
and user's input types. They encapsulate the task of
memory allocation also, facilitating support of implicit
conversions between the users data type and representation and what is
required by the CCfits implementation. For example a user can create a
std::vector<int> for storage in a single row of a Binary Table column,
of type long.  The internal representation is a std::valarray<long>
object.

\param outArray  output data
\param inArray  input data
\param first    first element of inArray to be written to outArray
\param last     last element of inArray to be written to outArray

*/ 

#ifdef _MSC_VER
#include "MSconfig.h" // for truncation double to float warning
#endif

     template <typename T>
    void swap(T& left,T& right);

    template <typename T>
    void swap(std::vector<T>& left, std::vector<T>& right);
    
    string lowerCase(const string& inputString);

    string upperCase(const string& inputString);

  struct InvalidConversion : public FitsException
  {
		InvalidConversion(const string& diag, bool silent=false);

  };
  
  struct MatchStem : public std::binary_function<string,string,bool>
  {
          bool operator()(const string& left, const string& right) const;
  };

  static const  double d1(0);
  static const  float  f1(0);
  static const  std::complex<float> c1(0.);
  static const  std::complex<double> d2(0.);
  static const  string s1("");
  static const  int    i1(0);
  static const  unsigned int  u1(0);        
  static const  long l1(0);
  static const  unsigned long ul1(0);
  static const  LONGLONG ll1(0);
  static const  short s2(0);
  static const  unsigned short us1(0); 
  static const  bool b1(false);
  static const  unsigned char b2(0);  

  char** CharArray(const std::vector<string>& inArray);
  
  string FITSType2String( int typeInt );
  

  template <typename S, typename T> 
  void fill(std::vector<S>& outArray, const std::vector<T>& inArray,size_t first, size_t last);
    
  template <typename S, typename T> 
  void fill(std::valarray<S>& outArray, const std::valarray<T>& inArray);
  
  template <typename S, typename T> 
  void fill(std::valarray<S>& outArray, const std::vector<T>& inArray,size_t first, size_t last);
   

  template <typename S, typename T> 
  void fill(std::vector<S>& outArray, const std::valarray<T>& inArray);

  // VF<-AF
   void fill(std::vector<std::complex<float> >& outArray, 
                  const std::valarray<std::complex<float> >& inArray);

  // VF<-AD
  void fill(std::vector<std::complex<float> >& outArray, 
                  const std::valarray<std::complex<double> >& inArray);
  
  // VD<-AD
  void fill(std::vector<std::complex<double> >& outArray, 
                  const std::valarray<std::complex<double> >& inArray);
  

  // VD<-AF
  void fill(std::vector<std::complex<double> >& outArray, 
                  const std::valarray<std::complex<float> >& inArray);
   
  template <typename T>
  void fill(std::vector<string>& outArray, const std::vector<T>& inArray, size_t first, size_t last);

  template <typename T>
  void fill(std::vector<T>& outArray, const std::vector<string>& inArray, size_t first, size_t last);

  template <typename S> 
  void fill(std::valarray<S>& outArray, const std::vector<string>& inArray,size_t first, size_t last);

//  template <typename S, typename T>
//  void fill(std::valarray<std::complex<S> >& outArray, const std::valarray<std::complex<T> >& inArray);            
  // seems no other way of doing this.
  
  // VF<-VF
#ifdef TEMPLATE_AMBIG_DEFECT
  void fillMSvfvf(std::vector<std::complex<float> >& outArray, 
                  const std::vector<std::complex<float> >& inArray, size_t first, size_t last);
#endif

  void fill(std::vector<std::complex<float> >& outArray, 
                  const std::vector<std::complex<float> >& inArray, size_t first, size_t last);
  
  // VF<-VD
#ifdef TEMPLATE_AMBIG_DEFECT
    void fillMSvfvd(std::vector<std::complex<float> >& outArray, 
                  const std::vector<std::complex<double> >& inArray, size_t first, size_t last);
#endif

   void fill(std::vector<std::complex<float> >& outArray, 
                  const std::vector<std::complex<double> >& inArray, size_t first, size_t last);
   
   // VD<-VD
#ifdef TEMPLATE_AMBIG_DEFECT
 void fillMSvdvd(std::vector<std::complex<double> >& outArray, 
                  const std::vector<std::complex<double> >& inArray, size_t first, size_t last);
#endif

   void fill(std::vector<std::complex<double> >& outArray, 
                  const std::vector<std::complex<double> >& inArray, size_t first, size_t last);

#ifdef TEMPLATE_AMBIG_DEFECT
  void fillMSvdvf(std::vector<std::complex<double> >& outArray, 
				const std::vector<std::complex<float> >& inArray, 
                        size_t first, size_t last);
#else
  void fill(std::vector<std::complex<double> >& outArray, 
                  const std::vector<std::complex<float> >& inArray, size_t first, size_t last);
#endif
 
  // AF<-VD
  void fill(std::valarray<std::complex<float> >& outArray, 
                  const std::vector<std::complex<double> >& inArray, size_t first, size_t last);
  
  // AF<-VF
#ifdef TEMPLATE_AMBIG_DEFECT
 void fillMSafvf(std::valarray<std::complex<float> >& outArray, 
                  const std::vector<std::complex<float> >& inArray, size_t first, size_t last);
#else
 void fill(std::valarray<std::complex<float> >& outArray, 
                  const std::vector<std::complex<float> >& inArray, size_t first, size_t last);
#endif

 // AD<-VF
#ifdef TEMPLATE_AMBIG_DEFECT
  void fillMSadvf(std::valarray<std::complex<double> >& outArray, 
                  const std::vector<std::complex<float> >& inArray, size_t first, size_t last);
#else
  void fill(std::valarray<std::complex<double> >& outArray, 
                  const std::vector<std::complex<float> >& inArray, size_t first, size_t last);
#endif
  
  // AD<-VD
#ifdef TEMPLATE_AMBIG_DEFECT
  void fillMSadvd(std::valarray<std::complex<double> >& outArray, 
                  const std::vector<std::complex<double> >& inArray, size_t first, size_t last);
#else
  void fill(std::valarray<std::complex<double> >& outArray, 
                  const std::vector<std::complex<double> >& inArray, size_t first, size_t last);
#endif
  
  // AF<-AF
  void fill(std::valarray<std::complex<float> >& outArray,  
                  const std::valarray<std::complex<float> >& inArray);
  // AD<-AD
  void fill(std::valarray<std::complex<double> >& outArray,  
                  const std::valarray<std::complex<double> >& inArray);
  // AF<-AD
  void fill(std::valarray<std::complex<float> >& outArray, 
                  const std::valarray<std::complex<double> >& inArray);
  // AD<-AF
  void fill(std::valarray<std::complex<double> >& outArray,  
                  const std::valarray<std::complex<float> >& inArray);
  
#if TEMPLATE_AMBIG_DEFECT || TEMPLATE_AMBIG7_DEFECT
  void fillMSvsvs(std::vector<string>& outArray, const std::vector<string>& inArray, size_t first, size_t last);
#endif


  void fill(std::vector<string>& outArray, const std::vector<string>& inArray, size_t first, size_t last);

  template <typename S, typename T>
  string errorMessage(const S& out, const T& in);

  // copy a fitsfile pointer.
  fitsfile* copyFitsPtr(fitsfile * inPtr);


    //## end CCfits::FITSUtil%3820548A5050.initialDeclarations

    //## Class: MatchPtrName%3AC8BF35020B; Parameterized Class
    //## Category: CCfits::FITSUtil%3820548A5050
    //## Subsystem: CCfits::Utility%3949241F026A
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    //## Uses: <unnamed>%39491C7D0119;std::string { -> }

    template <class T>
    struct MatchPtrName : public std::binary_function<T,std::string,bool>  //## Inherits: <unnamed>%39491BC9025D
    {

        //## Other Operations (specified)
          //## Operation: operator %3AC8BF350246;  C++
          //	Parameterized Class MatchPtrName
          bool operator () (const T& left, const string& right) const;

      public:
      protected:
      private:
      private: //## implementation
    };

    //## Class: MatchName%3AC8BF350253; Parameterized Class
    //## Category: CCfits::FITSUtil%3820548A5050
    //## Subsystem: CCfits::Utility%3949241F026A
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    //## Uses: <unnamed>%39491C8402BF;std::string { -> }

    template <class T>
    struct MatchName : public std::binary_function<T,std::string,bool>  //## Inherits: <unnamed>%39491BC50121
    {

        //## Other Operations (specified)
          //## Operation: operator %3AC8BF35025E;  C++
          bool operator () (const T& left, const string& right) const;

      public:
      protected:
      private:
      private: //## implementation
    };

    //## Class: MatchNum%383C36F58058; Parameterized Class
    //## Category: CCfits::FITSUtil%3820548A5050
    //## Subsystem: CCfits::Utility%3949241F026A
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    template <class T>
    struct MatchNum : public std::binary_function<T,int,bool>  //## Inherits: <unnamed>%39491BCE01C0
    {

        //## Other Operations (specified)
          //## Operation: operator()%383C381F2068
          bool operator () (const T& left, const int& right) const;

      public:
      protected:
      private:
      private: //## implementation
    };

    //## Class: MatchType%39491CB900CB; Parameterized Class
    //## Category: CCfits::FITSUtil%3820548A5050
    //## Subsystem: CCfits::Utility%3949241F026A
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    template <typename T>
    struct MatchType 
    {

        //## Other Operations (specified)
          //## Operation: operator()%39491D27033B
          ValueType operator () ();

      public:
      protected:
      private:
      private: //## implementation
    };

    //## Class: CVarray%39491F640098; private; Parameterized Class
    //## Category: CCfits::FITSUtil%3820548A5050
    //## Subsystem: CCfits::Utility%3949241F026A
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    template <typename T>
    struct CVarray 
    {

        //## Other Operations (specified)
          //## Operation: operator()%39491FAF0239
          T* operator () (const std::vector<T>& inArray);

      public:
      protected:
      private:
      private: //## implementation
    };

    //## Class: FitsNullValue%397F48F303B5; Parameterized Class
    //## Category: CCfits::FITSUtil%3820548A5050
    //## Subsystem: CCfits::Utility%3949241F026A
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    template <typename T>
    struct FitsNullValue 
    {

        //## Other Operations (specified)
          //## Operation: operator()%397F49B902A4
          T operator () ();

      public:
      protected:
      private:
      private: //## implementation
    };

    //## Class: MatchImageType%3AFA9C950281; Parameterized Class
    //## Category: CCfits::FITSUtil%3820548A5050
    //## Subsystem: CCfits::Utility%3949241F026A
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    template <typename T>
    struct MatchImageType 
    {

        //## Other Operations (specified)
          //## Operation: operator()%3AFA9CDE0298
          ImageType operator () ();

      public:
      protected:
      private:
      private: //## implementation
    };

    //## Class: MatchPtrNum%383C36F8A768; private; Parameterized Class
    //## Category: CCfits::FITSUtil%3820548A5050
    //## Subsystem: CCfits::Utility%3949241F026A
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    template <class T>
    struct MatchPtrNum : public std::binary_function<T,int,bool>  //## Inherits: <unnamed>%39491BD3034B
    {

        //## Other Operations (specified)
          //## Operation: operator()%383C386AE318
          bool operator () (const T& left, const int& right) const;

      public:
      protected:
      private:
      private: //## implementation
    };

    //## Class: auto_array_ptr%3AFC94C90276; Parameterized Class
    //	auto_ptr analogue for arrays.
    //## Category: CCfits::FITSUtil%3820548A5050
    //## Subsystem: CCfits::Utility%3949241F026A
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    template <typename X>
    class auto_array_ptr 
    {
      public:
        //## Constructors (specified)
          //## Operation: auto_array_ptr%3AFC9CE603A9
          //## Exceptions: ()
          explicit auto_array_ptr (X* p = 0) throw ();

          //## Operation: auto_array_ptr%3AFC9D7F025A
          //## Exceptions: ()
          explicit auto_array_ptr (auto_array_ptr<X>& right) throw ();

        //## Destructor (generated)
          ~auto_array_ptr();


        //## Other Operations (specified)
          //## Operation: operator=%3AFC9FF103CE
          void operator = (auto_array_ptr<X>& right);

          //## Operation: operator*%3AFCA075003E
          //## Exceptions: ()
          X& operator * () throw ();

          //## Operation: operator[]%3AFCA0990172
          //## Exceptions: ()
          X& operator [] (size_t i) throw ();

          //## Operation: operator[]%3AFCA0C80269
          //## Exceptions: ()
          X operator [] (size_t i) const throw ();

          //## Operation: get%3AFCA14C00F8
          X* get () const;

          //## Operation: release%3AFCA1710251
          //## Exceptions: ()
          X* release () throw ();

          //## Operation: reset%3AFCA1C30353
          //## Exceptions: ()
          X* reset (X* p) throw ();

          //## Operation: remove%3AFCA20900EB
          static void remove (X*& x);

      protected:
      private:
      private: //## implementation
        // Data Members for Class Attributes

          //## Attribute: p%3AFC9F6303CD
          //## begin CCfits::FITSUtil::auto_array_ptr::p%3AFC9F6303CD.attr preserve=no  private: X* {U} p
          X* m_p;
          //## end CCfits::FITSUtil::auto_array_ptr::p%3AFC9F6303CD.attr

    };

    //## Class: ComparePtrIndex%3B24DB4301E0; Parameterized Class
    //## Category: CCfits::FITSUtil%3820548A5050
    //## Subsystem: CCfits::Utility%3949241F026A
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    template <typename T>
    struct ComparePtrIndex : public std::binary_function<T,T,bool>  //## Inherits: <unnamed>%3B24DB930299
    {

        //## Other Operations (specified)
          //## Operation: operator()%3B24DB680377
          bool operator () (const T* left, const T* right);

      public:
      protected:
      private:
      private: //## implementation
    };

    //## Class: CAarray%3BFA7D6C0304; Parameterized Class
    //## Category: CCfits::FITSUtil%3820548A5050
    //## Subsystem: CCfits::Utility%3949241F026A
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    template <typename T>
    struct CAarray 
    {

        //## Other Operations (specified)
          //## Operation: operator()%3BFA7DA701F6
          T* operator () (const std::valarray<T>& inArray);

      public:
      protected:
      private:
      private: //## implementation
    };

    //## Class: CVAarray%3BFA7DE1030B; Parameterized Class
    //## Category: CCfits::FITSUtil%3820548A5050
    //## Subsystem: CCfits::Utility%3949241F026A
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    template <typename T>
    struct CVAarray 
    {

        //## Other Operations (specified)
          //## Operation: operator()%3BFA7E1500D3
          T* operator () (const std::vector< std::valarray<T> >& inArray);

      public:
      protected:
      private:
      private: //## implementation
    };

    //## Class: UnrecognizedType%3CE1433D00F5
    //## Category: CCfits::FITSUtil%3820548A5050
    //## Subsystem: CCfits::Utility%3949241F026A
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n



    class UnrecognizedType : public FitsException  //## Inherits: <unnamed>%3CE143AB00C6
    {
      public:
        //## Constructors (specified)
          //## Operation: UnrecognizedType%3CE143740244
          UnrecognizedType (string diag, bool silent = true);

      protected:
      private:
      private: //## implementation
    };

    // Parameterized Class CCfits::FITSUtil::MatchPtrName 


    //## Other Operations (inline)
    template <class T>
    inline bool MatchPtrName<T>::operator () (const T& left, const string& right) const
    {
      //## begin CCfits::FITSUtil::MatchPtrName::operator %3AC8BF350246.body preserve=yes
       return left->name() == right;
      //## end CCfits::FITSUtil::MatchPtrName::operator %3AC8BF350246.body
    }

    // Parameterized Class CCfits::FITSUtil::MatchName 


    //## Other Operations (inline)
    template <class T>
    inline bool MatchName<T>::operator () (const T& left, const string& right) const
    {
      //## begin CCfits::FITSUtil::MatchName::operator %3AC8BF35025E.body preserve=yes
       return left.name() == right;
      //## end CCfits::FITSUtil::MatchName::operator %3AC8BF35025E.body
    }

    // Parameterized Class CCfits::FITSUtil::MatchNum 


    //## Other Operations (inline)
    template <class T>
    inline bool MatchNum<T>::operator () (const T& left, const int& right) const
    {
      //## begin CCfits::FITSUtil::MatchNum::operator()%383C381F2068.body preserve=yes
    return left.index() == right;
      //## end CCfits::FITSUtil::MatchNum::operator()%383C381F2068.body
    }

    // Parameterized Class CCfits::FITSUtil::MatchType 

    // Parameterized Class CCfits::FITSUtil::CVarray 


    //## Other Operations (inline)
    template <typename T>
    inline T* CVarray<T>::operator () (const std::vector<T>& inArray)
    {
      //## begin CCfits::FITSUtil::CVarray::operator()%39491FAF0239.body preserve=yes
      
      // convert std containers used commonly in FITS to C arrays in an exception
      // safe manner that is also clear about resource ownership.      
      auto_array_ptr<T> pC(new T[inArray.size()]);
      T* c = pC.get();
      std::copy(inArray.begin(),inArray.end(),&c[0]);
      return pC.release();
      //## end CCfits::FITSUtil::CVarray::operator()%39491FAF0239.body
    }

    // Parameterized Class CCfits::FITSUtil::FitsNullValue 


    //## Other Operations (inline)
    template <typename T>
    inline T FitsNullValue<T>::operator () ()
    {
      //## begin CCfits::FITSUtil::FitsNullValue::operator()%397F49B902A4.body preserve=yes
           FITSUtil::MatchType<T> null;  
           switch ( null() )
           {
                // the casts have no function apart from removing compiler warnings.
                case Tfloat:
                case Tcomplex:
                        return static_cast<T>(FLOATNULLVALUE);
                case Tdouble:
                case Tdblcomplex:
                        return static_cast<T>(DOUBLENULLVALUE);
                default:
                        return 0;
            }
      //## end CCfits::FITSUtil::FitsNullValue::operator()%397F49B902A4.body
    }

    // Parameterized Class CCfits::FITSUtil::MatchImageType 

    // Parameterized Class CCfits::FITSUtil::MatchPtrNum 


    //## Other Operations (inline)
    template <class T>
    inline bool MatchPtrNum<T>::operator () (const T& left, const int& right) const
    {
      //## begin CCfits::FITSUtil::MatchPtrNum::operator()%383C386AE318.body preserve=yes
    return left->index() == right;
      //## end CCfits::FITSUtil::MatchPtrNum::operator()%383C386AE318.body
    }

    // Parameterized Class CCfits::FITSUtil::auto_array_ptr 

    // Parameterized Class CCfits::FITSUtil::ComparePtrIndex 

    // Parameterized Class CCfits::FITSUtil::CAarray 

    // Parameterized Class CCfits::FITSUtil::CVAarray 

    // Class CCfits::FITSUtil::UnrecognizedType 

    // Parameterized Class CCfits::FITSUtil::MatchPtrName 

    // Parameterized Class CCfits::FITSUtil::MatchName 

    // Parameterized Class CCfits::FITSUtil::MatchNum 

    // Parameterized Class CCfits::FITSUtil::MatchType 


    //## Other Operations (implementation)
    template <typename T>
    ValueType MatchType<T>::operator () ()
    {
      //## begin CCfits::FITSUtil::MatchType::operator()%39491D27033B.body preserve=yes

    if ( typeid(T) == typeid(d1) ) return Tdouble;
    if ( typeid(T) == typeid(f1) ) return Tfloat;
    if ( typeid(T) == typeid(c1) ) return Tcomplex;
    if ( typeid(T) == typeid(d2) ) return Tdblcomplex;
    if ( typeid(T) == typeid(s1) ) return Tstring;
    if ( typeid(T) == typeid(i1) ) return Tint;
    if ( typeid(T) == typeid(u1) ) return Tuint;
    if ( typeid(T) == typeid(s2) ) return Tshort;
    if ( typeid(T) == typeid(us1) ) return Tushort;
    if ( typeid(T) == typeid(b1) ) return Tlogical;
    if ( typeid(T) == typeid(b2) ) return Tbyte;
    if ( typeid(T) == typeid(l1) ) return Tlong;
    if ( typeid(T) == typeid(ul1) ) return Tulong;
    // Carefull, on some compilers LONGLONG == long,
    // so this should go after test for long.
    if ( typeid(T) == typeid(ll1) ) return Tlonglong;
    throw UnrecognizedType("Invalid data type for FITS Data I/O\n");    
    
      //## end CCfits::FITSUtil::MatchType::operator()%39491D27033B.body
    }

    // Parameterized Class CCfits::FITSUtil::CVarray 

    // Parameterized Class CCfits::FITSUtil::MatchImageType 


    //## Other Operations (implementation)
    template <typename T>
    ImageType MatchImageType<T>::operator () ()
    {
      //## begin CCfits::FITSUtil::MatchImageType::operator()%3AFA9CDE0298.body preserve=yes
    if ( typeid(T) == typeid(b2) ) return Ibyte;    
    if ( typeid(T) == typeid(s2) ) return Ishort;
    if ( typeid(T) == typeid(l1) ) return Ilong;
    if ( typeid(T) == typeid(f1) ) return Ifloat;
    if ( typeid(T) == typeid(d1) ) return Idouble;
    if ( typeid(T) == typeid(us1) ) return Iushort;
    if ( typeid(T) == typeid(ul1) ) return Iulong;
    MatchType<T> errType;
    string diag ("Image: ");
    diag += FITSType2String(errType());
    throw UnrecognizedType(diag);        
      //## end CCfits::FITSUtil::MatchImageType::operator()%3AFA9CDE0298.body
    }

    // Parameterized Class CCfits::FITSUtil::MatchPtrNum 

    // Parameterized Class CCfits::FITSUtil::auto_array_ptr 

    template <typename X>
    auto_array_ptr<X>::auto_array_ptr (X* p) throw ()
      //## begin CCfits::FITSUtil::auto_array_ptr::auto_array_ptr%3AFC9CE603A9.hasinit preserve=no
          : m_p(p)
      //## end CCfits::FITSUtil::auto_array_ptr::auto_array_ptr%3AFC9CE603A9.hasinit
      //## begin CCfits::FITSUtil::auto_array_ptr::auto_array_ptr%3AFC9CE603A9.initialization preserve=yes
      //## end CCfits::FITSUtil::auto_array_ptr::auto_array_ptr%3AFC9CE603A9.initialization
    {
      //## begin CCfits::FITSUtil::auto_array_ptr::auto_array_ptr%3AFC9CE603A9.body preserve=yes
      //## end CCfits::FITSUtil::auto_array_ptr::auto_array_ptr%3AFC9CE603A9.body
    }

    template <typename X>
    auto_array_ptr<X>::auto_array_ptr (auto_array_ptr<X>& right) throw ()
      //## begin CCfits::FITSUtil::auto_array_ptr::auto_array_ptr%3AFC9D7F025A.hasinit preserve=yes
          : m_p(right.release())
      //## end CCfits::FITSUtil::auto_array_ptr::auto_array_ptr%3AFC9D7F025A.hasinit
      //## begin CCfits::FITSUtil::auto_array_ptr::auto_array_ptr%3AFC9D7F025A.initialization preserve=yes
      //## end CCfits::FITSUtil::auto_array_ptr::auto_array_ptr%3AFC9D7F025A.initialization
    {
      //## begin CCfits::FITSUtil::auto_array_ptr::auto_array_ptr%3AFC9D7F025A.body preserve=yes
      //## end CCfits::FITSUtil::auto_array_ptr::auto_array_ptr%3AFC9D7F025A.body
    }


    template <typename X>
    auto_array_ptr<X>::~auto_array_ptr()
    {
      //## begin CCfits::FITSUtil::auto_array_ptr::~auto_array_ptr%3AFC94C90276_dest.body preserve=yes
      delete [] m_p;
      //## end CCfits::FITSUtil::auto_array_ptr::~auto_array_ptr%3AFC94C90276_dest.body
    }



    //## Other Operations (implementation)
    template <typename X>
    void auto_array_ptr<X>::operator = (auto_array_ptr<X>& right)
    {
      //## begin CCfits::FITSUtil::auto_array_ptr::operator=%3AFC9FF103CE.body preserve=yes
      if (this != &right)
      {
                remove(m_p);
                m_p = right.release();       
      }
      //## end CCfits::FITSUtil::auto_array_ptr::operator=%3AFC9FF103CE.body
    }

    template <typename X>
    X& auto_array_ptr<X>::operator * () throw ()
    {
      //## begin CCfits::FITSUtil::auto_array_ptr::operator*%3AFCA075003E.body preserve=yes
      return *m_p;
      //## end CCfits::FITSUtil::auto_array_ptr::operator*%3AFCA075003E.body
    }

    template <typename X>
    X& auto_array_ptr<X>::operator [] (size_t i) throw ()
    {
      //## begin CCfits::FITSUtil::auto_array_ptr::operator[]%3AFCA0990172.body preserve=yes
      return m_p[i];
      //## end CCfits::FITSUtil::auto_array_ptr::operator[]%3AFCA0990172.body
    }

    template <typename X>
    X auto_array_ptr<X>::operator [] (size_t i) const throw ()
    {
      //## begin CCfits::FITSUtil::auto_array_ptr::operator[]%3AFCA0C80269.body preserve=yes
      return m_p[i];
      //## end CCfits::FITSUtil::auto_array_ptr::operator[]%3AFCA0C80269.body
    }

    template <typename X>
    X* auto_array_ptr<X>::get () const
    {
      //## begin CCfits::FITSUtil::auto_array_ptr::get%3AFCA14C00F8.body preserve=yes
      return m_p;
      //## end CCfits::FITSUtil::auto_array_ptr::get%3AFCA14C00F8.body
    }

    template <typename X>
    X* auto_array_ptr<X>::release () throw ()
    {
      //## begin CCfits::FITSUtil::auto_array_ptr::release%3AFCA1710251.body preserve=yes
      return reset(0);
      //## end CCfits::FITSUtil::auto_array_ptr::release%3AFCA1710251.body
    }

    template <typename X>
    X* auto_array_ptr<X>::reset (X* p) throw ()
    {
      //## begin CCfits::FITSUtil::auto_array_ptr::reset%3AFCA1C30353.body preserve=yes
      // set the auto_ptr to manage p and return the old pointer it was managing.
      X* __tmp = m_p; 
      m_p = p;
      return __tmp;
      //## end CCfits::FITSUtil::auto_array_ptr::reset%3AFCA1C30353.body
    }

    template <typename X>
    void auto_array_ptr<X>::remove (X*& x)
    {
      //## begin CCfits::FITSUtil::auto_array_ptr::remove%3AFCA20900EB.body preserve=yes
      X* __tmp(x);
      x = 0;
      delete [] __tmp;
      //## end CCfits::FITSUtil::auto_array_ptr::remove%3AFCA20900EB.body
    }

    // Parameterized Class CCfits::FITSUtil::ComparePtrIndex 


    //## Other Operations (implementation)
    template <typename T>
    bool ComparePtrIndex<T>::operator () (const T* left, const T* right)
    {
      //## begin CCfits::FITSUtil::ComparePtrIndex::operator()%3B24DB680377.body preserve=yes
      return (left->index() < right->index());
      //## end CCfits::FITSUtil::ComparePtrIndex::operator()%3B24DB680377.body
    }

    // Parameterized Class CCfits::FITSUtil::CAarray 


    //## Other Operations (implementation)
    template <typename T>
    T* CAarray<T>::operator () (const std::valarray<T>& inArray)
    {
      //## begin CCfits::FITSUtil::CAarray::operator()%3BFA7DA701F6.body preserve=yes
      size_t n(inArray.size());
      auto_array_ptr<T> pC(new T[n]);
      T* c= pC.get();
      for (size_t j = 0; j < n; ++j) c[j] = inArray[j];
      return pC.release();      
      //## end CCfits::FITSUtil::CAarray::operator()%3BFA7DA701F6.body
    }

    // Parameterized Class CCfits::FITSUtil::CVAarray 


    //## Other Operations (implementation)
    template <typename T>
    T* CVAarray<T>::operator () (const std::vector< std::valarray<T> >& inArray)
    {
      //## begin CCfits::FITSUtil::CVAarray::operator()%3BFA7E1500D3.body preserve=yes
      size_t  sz(0);
      size_t  n(inArray.size());

      std::vector<size_t> nr(n);

      size_t i = 0; // for MS VC++ bug
      for ( i = 0; i < n; ++i)
      {
         nr[i] = inArray[i].size();
	 sz += nr[i];
         
      }
      auto_array_ptr<T> pC(new T[sz]);
      T* c = pC.get();

      size_t k(0);
      for ( i = 0; i < n; ++i)
      {
         size_t& m = nr[i];
         const std::valarray<T>& current = inArray[i];
	 for (size_t j=0; j < m ; ++j) c[k++] = current[j];
      }

      return pC.release();      
      //## end CCfits::FITSUtil::CVAarray::operator()%3BFA7E1500D3.body
    }

  } // namespace FITSUtil
} // namespace CCfits

//## begin module%384D1F571C70.epilog preserve=yes

namespace CCfits
{
        
        
        namespace FITSUtil
        {                

                template <typename T>
                void swap(T& left, T& right)
                {
                        T temp(left);
                        left = right;
                        right = temp;                
                }
                
                template <typename T>
                void swap(std::vector<T>& left, std::vector<T>& right)
                {
                        left.swap(right);        
                }
                
                template <>
                inline string FitsNullValue<string>::operator () ()
                {
	                return string("");
                }

        }
}

  
//## end module%384D1F571C70.epilog


#endif
