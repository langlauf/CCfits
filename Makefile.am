## Process this file with automake to produce Makefile.in
#
# $Id: Makefile.am,v 2.14 2001/08/10 18:12:04 dorman Exp $
#
# Author: Paul_Kunz@slac.stanford.edu
#
# The following set,  else would follow GNU conventions
AUTOMAKE_OPTIONS = foreign no-dependencies

# Trick to add options to aclocal command
ACLOCAL = aclocal -I config/m4

EXTRA_DIST = config

bin_PROGRAMS = cookbook

cookbook_SOURCES = cookbook.cxx

cookbook_LDADD = libCCfits.la

## The following is needed for compiling cookbook.cxx
INCLUDES = -I$(top_srcdir)/..

## The library to be built
lib_LTLIBRARIES = libCCfits.la

libCCfits_la_SOURCES =				\
	AsciiTable.cxx				\
	BinTable.cxx				\
	Column.cxx				\
	ColumnCreator.cxx			\
	ColumnData.cxx				\
        ColumnVectorData.cxx                    \
        ExtHDU.cxx				\
	FITS.cxx				\
	FITSBase.cxx				\
	FITSUtil.cxx				\
	FitsError.cxx				\
	HDU.cxx					\
	HDUCreator.cxx				\
	Image.cxx				\
	KeyData.cxx				\
        Keyword.cxx				\
	KeywordCreator.cxx			\
	PHDU.cxx				\
	Table.cxx

# This will tell shared library which STD C++ library to use without
# needing the user to use LD_LIBRARY_PATH environment variable
libCCfits_la_LIBADD = $(LIBSTDCPP)

libCCfits_ladir = $(pkgincludedir)

libCCfits_la_HEADERS =				\
	AsciiTable.h				\
	BinTable.h				\
	CCfits					\
	CCfits.h				\
	Column.h				\
	ColumnT.h				\
	ColumnCreator.h				\
	ColumnData.h				\
	ColumnVectorData.h			\
        ExtHDU.h				\
        ExtHDUT.h                               \
	FITS.h					\
	FITSBase.h				\
	FITSUtil.h				\
	FITSUtilT.h				\
	FitsError.h				\
	HDU.h					\
	HDUCreator.h				\
	Image.h					\
	ImageExt.h				\
	KeyData.h				\
        Keyword.h				\
        KeywordT.h				\
	KeywordCreator.h			\
	NewColumn.h				\
	NewKeyword.h				\
	PHDU.h					\
        PHDUT.h                                 \
	PrimaryHDU.h				\
	Table.h

run_cookbook:
	cookbook

## The following is for Mac OS X.  
## It has not yet been tested.
## This workaround was contributed by Chris Jones
## <cdj@mail.lns.cornell.edu>

bundle:
	c++ -bundle -I. -DHAVE_STRSTREAM -o libCCfits.a *.cxx

## commented out in configure.in INCLUDES = -I@STLPORT@

docs:
	doxygen Doxyfile

clean-local:
	-rm -rf SunWS_cache
