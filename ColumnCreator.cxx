//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%387B3EF7F130.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%387B3EF7F130.cm

//## begin module%387B3EF7F130.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%387B3EF7F130.cp

//## Module: ColumnCreator%387B3EF7F130; Package body
//## Subsystem: CCfits::Column%3934116D0008
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/ColumnCreator.cxx

//## begin module%387B3EF7F130.additionalIncludes preserve=no
//## end module%387B3EF7F130.additionalIncludes

//## begin module%387B3EF7F130.includes preserve=yes
//## end module%387B3EF7F130.includes

// Column
#include "Column.h"
// Table
#include "Table.h"
// ColumnData
#include "ColumnData.h"
// ColumnVectorData
#include "ColumnVectorData.h"
// ColumnCreator
#include "ColumnCreator.h"


//## begin module%387B3EF7F130.declarations preserve=no
//## end module%387B3EF7F130.declarations

//## begin module%387B3EF7F130.additionalDeclarations preserve=yes
#include <stdlib.h>
#include <complex>
using std::complex;
//## end module%387B3EF7F130.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  // Class CCfits::ColumnCreator 

  ColumnCreator::ColumnCreator (Table* p)
    //## begin CCfits::ColumnCreator::ColumnCreator%3B000490020D.hasinit preserve=no
        : m_parent(p)
    //## end CCfits::ColumnCreator::ColumnCreator%3B000490020D.hasinit
    //## begin CCfits::ColumnCreator::ColumnCreator%3B000490020D.initialization preserve=yes
    //## end CCfits::ColumnCreator::ColumnCreator%3B000490020D.initialization
  {
    //## begin CCfits::ColumnCreator::ColumnCreator%3B000490020D.body preserve=yes
    //## end CCfits::ColumnCreator::ColumnCreator%3B000490020D.body
  }


  ColumnCreator::~ColumnCreator()
  {
    //## begin CCfits::ColumnCreator::~ColumnCreator%387B3F5C4150_dest.body preserve=yes
    //## end CCfits::ColumnCreator::~ColumnCreator%387B3F5C4150_dest.body
  }



  //## Other Operations (implementation)
  Column * ColumnCreator::MakeColumn (const int index, const String &name, const String &format, const String &unit, const long repeat, const long width, const String &comment, const int decimals)
  {
    //## begin CCfits::ColumnCreator::MakeColumn%38F629D3C010.body preserve=yes
    return 0;
    //## end CCfits::ColumnCreator::MakeColumn%38F629D3C010.body
  }

  Column * ColumnCreator::getColumn (int number, const String& name, const String& format, const String& unit)
  {
    //## begin CCfits::ColumnCreator::getColumn%394682C701CA.body preserve=yes
   long  repeat=1;
   long  width=1;
   int   type=0;
   double tscale = 1;
   double tzero  = 0;
   
   getScaling(number, type, repeat, width, tscale, tzero);
   return createColumn(number,ValueType(type),name,format,unit,repeat,width,tscale,tzero);
 
    //## end CCfits::ColumnCreator::getColumn%394682C701CA.body
  }

  Column * ColumnCreator::createColumn (int number, ValueType type, const String &name, const String &format, const String &unit, long repeat, long width, double scaleFactor, double offset, const String &comment)
  {
    //## begin CCfits::ColumnCreator::createColumn%3B000364025A.body preserve=yes
   

   
   switch(type)
   {
      case Tstring:
	        m_column = new ColumnData<String>(number, name, type, format, unit, 
                                                                             m_parent, 1, width);
	        break;
      case VTushort:
	        m_column = new ColumnVectorData<unsigned short>(number, name,  
                                        type, format,unit,  m_parent, repeat); 
                m_column->zero(USBASE);
                m_column->scale(1);
                break;      
      case Tushort:
                if (repeat == 1)
                {
	                m_column = new ColumnData<unsigned short>(number, name,  
                                        type, format,unit,  m_parent);
                }
                else
                {
	                m_column = new ColumnVectorData<unsigned short>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        
                }	
                m_column->zero(USBASE);
                m_column->scale(1);
                break;
      case VTshort:
	        m_column = new ColumnVectorData<short>(number, name, 
                                	type, format,unit,  m_parent, repeat);  
                break;      
      case Tshort:
                if (repeat == 1)
                {
	                m_column = new ColumnData<short>(number, name,  
                                        type, format,unit,  m_parent);
                }
                else
                {
	                m_column = new ColumnVectorData<short>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        
                }	
                break;
      case VTlogical:
	        m_column = new ColumnVectorData<bool>(number, name,  
                                        type, format,unit,  m_parent, repeat); 
                break;                 
      case Tlogical:  
               if (repeat == 1)
                {
	                m_column = new ColumnData<bool>(number, name,  
                                        type, format,unit,  m_parent);
                }
                else
                {
	                m_column = new ColumnVectorData<bool>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        
                }	
                break;
      case VTbyte:
      case VTbit:
                m_column = new ColumnVectorData<unsigned char>(number, name,  
                                        type, format,unit,  m_parent, repeat);     
                break;     
      case Tbit:
      case Tbyte:
                if (repeat == 1)
                {
	                m_column = new ColumnData<unsigned char>(number, name,  
                                        type, format,unit,  m_parent);
                }
                else
                {
	                m_column = new ColumnVectorData<unsigned char>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        
                }	
                break;
      case VTint:	                
                m_column = new ColumnVectorData<int>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        	
                break;
      case Tint:
                if (repeat == 1)
                {
	                m_column = new ColumnData<int>(number, name,  
                                        type, format,unit,  m_parent);
                }
                else
                {
	                m_column = new ColumnVectorData<int>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        
                }	
                break;
      case VTuint:
	        m_column = new ColumnVectorData<unsigned int>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        	
                m_column->zero(ULBASE);
                m_column->scale(1);
                break;
      case Tuint:
                if (repeat == 1)
                {
	                m_column = new ColumnData<unsigned int>(number, name,  
                                        type, format,unit,  m_parent);
                }
                else
                {
	                m_column = new ColumnVectorData<unsigned int>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        
                }	
                m_column->zero(ULBASE);
                m_column->scale(1);
                break;
      case VTlong:
	        m_column = new ColumnVectorData<long>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        	
                break;
      case Tlong:
                if (repeat == 1)
                {
	                m_column = new ColumnData<long>(number, name,  
                                        type, format,unit,  m_parent);
                }
                else
                {
	                m_column = new ColumnVectorData<long>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        
                }	
                break;
      case VTlonglong:
                m_column = new ColumnVectorData<LONGLONG>(number, name,  
                                        type, format,unit,  m_parent, repeat);
                break;
      case Tlonglong:
                if (repeat == 1)
                {
	                m_column = new ColumnData<LONGLONG>(number, name,  
                                        type, format,unit,  m_parent);
                }
                else
                {
	                m_column = new ColumnVectorData<LONGLONG>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        
                }	
                break;      
      case VTulong:          
	        m_column = new ColumnVectorData<unsigned long>(number, name,  
                                        type, format,unit,  m_parent, repeat);   
                m_column->zero(ULBASE);
                m_column->scale(1);                                  
                break;
      case Tulong:
                if (repeat == 1)
                {
	                m_column = new ColumnData<unsigned long>(number, name,  
                                        type, format,unit,  m_parent);
                }
                else
                {
	                m_column = new ColumnVectorData<unsigned long>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        
                }	
                m_column->zero(ULBASE);
                m_column->scale(1);
                break;
      case VTfloat:
	        m_column = new ColumnVectorData<float>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        
                break;
      case Tfloat:
                if (repeat == 1)
                {
	                m_column = new ColumnData<float>(number, name,  
                                        type, format,unit,  m_parent);
                }
                else
                {
	                m_column = new ColumnVectorData<float>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        
                }	
                break;
      case VTdouble:
	        m_column = new ColumnVectorData<double>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        	
                break;      
      case Tdouble:
                if (repeat == 1)
                {
	                m_column = new ColumnData<double>(number, name,  
                                        type, format,unit,  m_parent);
                }
                else
                {
	                m_column = new ColumnVectorData<double>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        
                }	
                break;
       case VTcomplex:
	        m_column = new ColumnVectorData<complex<float> >(number, name,  
                                        type, format,unit,  m_parent, repeat);                        	
                break;
       case Tcomplex:
                if (repeat == 1)
                {
	                m_column = new ColumnData<complex<float> >(number, name,  
                                        type, format,unit,  m_parent);
                }
                else
                {
	                m_column = new ColumnVectorData<complex<float> >(number, name,  
                                        type, format,unit,  m_parent, repeat);                        
                }	
                break;
       case VTdblcomplex:
	        m_column = new ColumnVectorData<complex<double> >(number, name,  
                                        type, format,unit,  m_parent, repeat);                        	
                break;
       case Tdblcomplex:
                if (repeat == 1)
                {
	                m_column = new ColumnData<complex<double> >(number, name,  
                                        type, format,unit,  m_parent);
                }
                else
                {
	                m_column = new ColumnVectorData<complex<double> >(number, name,  
                                        type, format,unit,  m_parent, repeat);                        
                }	
                break;
      default:
         // replace with exception.
         throw FitsFatal("Unknown ValueType in ColumnCreator");
   }    
   if ( scaleFactor != 1)
   {
        m_column->scale(scaleFactor);
        m_column->zero(offset); 
   }   
   return m_column;
    //## end CCfits::ColumnCreator::createColumn%3B000364025A.body
  }

  void ColumnCreator::getScaling (int index, int& type, long& repeat, long& width, double& tscale, double& tzero)
  {
    //## begin CCfits::ColumnCreator::getScaling%3CC996820340.body preserve=yes
      int status (0);      
          
          
      if (fits_get_coltype(m_parent->fitsPointer(), index, &type, &repeat, &width, &status)) 
      { 
              throw FitsError(status);
      }

      int absType (std::abs(type)) ;

    
      FITSUtil::auto_array_ptr<char> pKeyname( new char[FLEN_KEYWORD]);
      char* keyname = pKeyname.get();
      sprintf(keyname, "%s%d",Column::TSCAL().c_str(),index);
      bool scalePresent (!fits_read_key(m_parent->fitsPointer(),Tdouble,keyname,&tscale,0,&status));
      
      // reset the status flag if there was no scale factor so cfitsio will not
      // propagate the error code.
      if (!scalePresent) status = 0;
      sprintf(keyname, "%s%d", Column::TZERO().c_str(),index);
      fits_read_key(m_parent->fitsPointer(),Tdouble,keyname,&tzero,0,&status);
      // if there is no BSCALE key present or BSCALE == 1 ... 
      if (!scalePresent || scalePresent &&  tscale == 1)
      {
           if ( !status )
           {
                   switch (absType)
                   {
                           case Tshort:
                                  if (tzero == USBASE)
                                  { 
                                        type > 0 ? type = Tushort : type = VTushort ;
                                  }
                                  break;
                           case Tint:
                                   if (tzero == ULBASE)
                                   {
                                        type > 0 ? type = Tuint : type = VTuint ;
                                   }
                                   break;
                           case Tlong:
                                   if (tzero == ULBASE)
                                   {
                                        type > 0 ? type = Tulong : type = VTulong ;
                                   }
                                   break;
                           default:
                                   break;
                   }
           }       
     }
     else // scale present and tmpScale != 1.
     {
             switch (absType)
             {
                 case Tbit:
                 case Tbyte:
                 case Tint:
                 case Tshort:
                         type > 0 ? type = Tfloat: type = VTfloat;
                         break;
                 case Tlong:
                 case Tlonglong:
                         type > 0 ? type = Tdouble: type = VTdouble;
                         break; 
                 default:
                         break; // do nothing.    
             }
     }                
    //## end CCfits::ColumnCreator::getScaling%3CC996820340.body
  }

  // Additional Declarations
    //## begin CCfits::ColumnCreator%387B3F5C4150.declarations preserve=yes
    //## end CCfits::ColumnCreator%387B3F5C4150.declarations

} // namespace CCfits

//## begin module%387B3EF7F130.epilog preserve=yes
//## end module%387B3EF7F130.epilog
