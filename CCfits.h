

//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov


#ifndef CCFITS_H
#define CCFITS_H 1


// fitsio
#include "fitsio.h"
#include <sys/types.h>


#include "longnam.h"


namespace CCfits {
  static const int BITPIX = -32;
  static const int  NAXIS =   2;
  static const int  MAXDIM = 99;



  typedef enum {Read=READONLY,Write=READWRITE} RWmode;




  typedef enum {Tnull, Tbit = TBIT, Tbyte = TBYTE, Tlogical = TLOGICAL, Tstring = TSTRING, Tushort = TUSHORT, Tshort = TSHORT,Tuint = TUINT,Tint = TINT, Tulong = TULONG,Tlong = TLONG, Tfloat = TFLOAT, Tdouble = TDOUBLE, Tcomplex = TCOMPLEX, Tdblcomplex=TDBLCOMPLEX, VTbit= -TBIT, VTbyte=-TBYTE,VTlogical=-Tlogical, VTushort=-TUSHORT,VTshort=-TSHORT,VTuint=-TUINT, VTint=-TINT,VTulong=-TULONG,VTlong=-TLONG,VTfloat=-TFLOAT,VTdouble=-TDOUBLE,VTcomplex=-TCOMPLEX,VTdblcomplex=-TDBLCOMPLEX} ValueType;




  typedef enum {AnyHdu=-1, ImageHdu, AsciiTbl, BinaryTbl} HduType;




  typedef enum { Ibyte=BYTE_IMG, 
  Ishort = SHORT_IMG,
  Ilong = LONG_IMG, 
  Ifloat = FLOAT_IMG, 
  Idouble = DOUBLE_IMG, 
  Iushort = USHORT_IMG, 
  Iulong = ULONG_IMG} ImageType;


} // namespace CCfits



#endif
