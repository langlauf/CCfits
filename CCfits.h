//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%3A15B8060246.cm preserve=no
//	This is version 1.2 release dated April 2003
//## end module%3A15B8060246.cm

//## begin module%3A15B8060246.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	April 2003 Ben Dorman, L3-Communications EER Systems Inc.
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//## end module%3A15B8060246.cp

//## Module: CCfitsHeader%3A15B8060246; Package specification
//## Subsystem: CCfits%37FE40D94FC0
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/CCfits.h

#ifndef CCFITS_H
#define CCFITS_H 1

//## begin module%3A15B8060246.additionalIncludes preserve=no
//## end module%3A15B8060246.additionalIncludes

// string
#include <string>
// fitsio
#include "fitsio.h"

namespace CCfits {
  class ExtHDU;

} // namespace CCfits

//## begin module%3A15B8060246.includes preserve=yes
#include <map>
#include <sys/types.h>
//## end module%3A15B8060246.includes

//## begin module%3A15B8060246.declarations preserve=no
//## end module%3A15B8060246.declarations

//## begin module%3A15B8060246.additionalDeclarations preserve=yes
#include "longnam.h"
#include "float.h"
//## end module%3A15B8060246.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  static const int BITPIX = -32;
  static const int  NAXIS =   2;
  static const int  MAXDIM = 99;
  extern const unsigned long USBASE;
  extern const unsigned long  ULBASE;
  
  extern  char BSCALE[7];
  extern  char BZERO[6];
  //## end CCfits%37FE4140B6F8.initialDeclarations

  //## begin CCfits::RWmode%39C2854902D2.preface preserve=yes
  //## end CCfits::RWmode%39C2854902D2.preface

  //## Class: RWmode%39C2854902D2
  //## Category: CCfits::FITS%393416E90118
  //## Subsystem: CCfits%37FE40D94FC0
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  typedef enum {Read=READONLY,Write=READWRITE} RWmode;

  //## begin CCfits::RWmode%39C2854902D2.postscript preserve=yes
  //## end CCfits::RWmode%39C2854902D2.postscript

  //## begin CCfits::ValueType%3A15B929019D.preface preserve=yes
  //## end CCfits::ValueType%3A15B929019D.preface

  //## Class: ValueType%3A15B929019D
  //## Category: CCfits::FITS%393416E90118
  //## Subsystem: CCfits%37FE40D94FC0
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  typedef enum {Tnull, Tbit = TBIT, Tbyte = TBYTE, Tlogical = TLOGICAL, Tstring = TSTRING, Tushort = TUSHORT, Tshort = TSHORT,Tuint = TUINT,Tint = TINT, Tulong = TULONG,Tlong = TLONG, Tlonglong = TLONGLONG, Tfloat = TFLOAT, Tdouble = TDOUBLE, Tcomplex = TCOMPLEX, Tdblcomplex=TDBLCOMPLEX, VTbit= -TBIT, VTbyte=-TBYTE,VTlogical=-Tlogical, VTushort=-TUSHORT,VTshort=-TSHORT,VTuint=-TUINT, VTint=-TINT,VTulong=-TULONG,VTlong=-TLONG,VTlonglong=-TLONGLONG,VTfloat=-TFLOAT,VTdouble=-TDOUBLE,VTcomplex=-TCOMPLEX,VTdblcomplex=-TDBLCOMPLEX} ValueType;

  //## begin CCfits::ValueType%3A15B929019D.postscript preserve=yes
  //## end CCfits::ValueType%3A15B929019D.postscript

  //## begin CCfits::HduType%3A15BC88038D.preface preserve=yes
  //## end CCfits::HduType%3A15BC88038D.preface

  //## Class: HduType%3A15BC88038D
  //## Category: CCfits::FITS%393416E90118
  //## Subsystem: CCfits%37FE40D94FC0
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  typedef enum {AnyHdu=-1, ImageHdu, AsciiTbl, BinaryTbl} HduType;

  //## begin CCfits::HduType%3A15BC88038D.postscript preserve=yes
  //## end CCfits::HduType%3A15BC88038D.postscript

  //## begin CCfits::ImageType%3AFA9EA302A8.preface preserve=yes
  //## end CCfits::ImageType%3AFA9EA302A8.preface

  //## Class: ImageType%3AFA9EA302A8
  //## Category: CCfits::FITS%393416E90118
  //## Subsystem: CCfits%37FE40D94FC0
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  typedef enum {Inotype = 0, Ibyte=BYTE_IMG, 
  Ishort = SHORT_IMG,
  Ilong = LONG_IMG, 
  Ifloat = FLOAT_IMG, 
  Idouble = DOUBLE_IMG, 
  Iushort = USHORT_IMG, 
  Iulong = ULONG_IMG} ImageType;

  //## begin CCfits::ImageType%3AFA9EA302A8.postscript preserve=yes
  //## end CCfits::ImageType%3AFA9EA302A8.postscript

  //## Class: String%3EEF551F023D
  //## Category: CCfits::FITS%393416E90118
  //## Subsystem: CCfits%37FE40D94FC0
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%4135F25A00BF;std::string { -> }

  typedef std::string String;

  //## Class: ExtMap%4135ED960112
  //## Category: CCfits::FITS%393416E90118
  //## Subsystem: CCfits%37FE40D94FC0
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  //## Uses: <unnamed>%4135F1700366;ExtHDU { -> F}

  typedef std::multimap<String,CCfits::ExtHDU*> ExtMap;

  //## Class: ExtMapConstIt%4135EF3A00F3
  //## Category: CCfits::FITS%393416E90118
  //## Subsystem: CCfits%37FE40D94FC0
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  typedef ExtMap::const_iterator ExtMapConstIt;

  //## Class: ExtMapIt%4135EF7D0122
  //## Category: CCfits::FITS%393416E90118
  //## Subsystem: CCfits%37FE40D94FC0
  //## Persistence: Transient
  //## Cardinality/Multiplicity: n



  typedef ExtMap::iterator ExtMapIt;

} // namespace CCfits

//## begin module%3A15B8060246.epilog preserve=yes
//## end module%3A15B8060246.epilog


#endif
