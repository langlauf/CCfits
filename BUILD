   This project uses the GNU Build tools.  The fashion to build the
library and test program differ for developers (those making fresh
check-out from CVS and users (those who received a tar.gz file...

- For Developers, after the checkout, run the following commands

  > cd CCfits
  > autogen
  > configure
  > make

  or if building in outside the source tree (recommended)

  > cd CCfits
  > autogen
  > cd ..
  > mkdir CCfits-build # or any other name
  > cd CCfits-build
  > ../CCfits/configure
  > make
  
  Developers will need to have autoconf, automake, and libtool installed.

- For users. it is the same as above but skipping the `autogen' step.
  Users will not need to have autoconf and automake installed.   If a
  user also does not have libtool installed, then shared libraries can
  not be built with the supplied Makefiles, but can be disabled  by
  running configure with the `--disabled-shared' option.

Both developers and users need to add to the configure step the option
`--with-cfitsio=PATH', where PATH is an installation path to a `lib'
directory containing `libcfitsio.a' and a `include' directory containing
`fitsio.h'.   If no such PATH exists, then the user can specify
`--with-cfitsio-include=INCDIR --with-cfitsio-libdir=LIBDIR' where
INCDIR and LIBDIR are directories containing the `fitsio.h' and
`libcfitsio.a' files respectively.

Paul_Kunz@slac.stanford.edu
