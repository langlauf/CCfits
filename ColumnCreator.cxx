
//	This is CCfits version 1.0-beta release August 2001

//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov




// Table
#include "Table.h"
// ColumnCreator
#include "ColumnCreator.h"
// Column
#include "Column.h"



#include <stdlib.h>
#include <complex>
using std::complex;


namespace CCfits {

  // Class CCfits::ColumnCreator 



  ColumnCreator::ColumnCreator (Table* p)
        : m_parent(p)
  {
  }


  ColumnCreator::~ColumnCreator()
  {
  }



  Column * ColumnCreator::MakeColumn (const int index, const string &name, const string &format, const string &unit, const long repeat, const long width, const string &comment, const int decimals)
  {
    return 0;
  }

  Column * ColumnCreator::getColumn (int number, const string& name, const string& format, const string& unit)
  {
   long  repeat=1;
   long  width=1;
   int   type=0;
   double tscale = 1;
   // initialize to something other than zero.
   unsigned int tzero  = 1;
   
   Column::getType(m_parent, number, &type, &repeat, &width, &tscale, &tzero);
   return createColumn(number,ValueType(type),name,format,unit,repeat,width,tscale,tzero);
 
  }

  Column * ColumnCreator::createColumn (int number, ValueType type, const string &name, const string &format, const string &unit, long repeat, long width, double scaleFactor, double offset, const string &comment)
  {
   

   
   switch(type)
   {
      case Tstring:
	        m_column = new ColumnData<string>(number, name, type, format, unit, 
                                                                             m_parent, 1, width);
	        break;
      case VTushort:
	        m_column = new ColumnVectorData<unsigned short>(number, name,  
                                        type, format,unit,  m_parent, repeat); 
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
      case VTulong:          
	        m_column = new ColumnVectorData<unsigned long>(number, name,  
                                        type, format,unit,  m_parent, repeat);                        
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
   if ( scaleFactor != 1 )
   {
       m_column->scale(scaleFactor);
       m_column->zero(offset); 
   }
      
   return m_column;
  }

  // Additional Declarations

} // namespace CCfits

