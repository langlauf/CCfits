//## begin module%1.4%.codegen_version preserve=yes
//   Read the documentation to learn more about C++ code generator
//   versioning.
//## end module%1.4%.codegen_version

//## begin module%38316E173E78.cm preserve=no
//	This is version 1.3 release dated Feb 2005
//## end module%38316E173E78.cm

//## begin module%38316E173E78.cp preserve=no
//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//	e-mail: ccfits@legacy.gsfc.nasa.gov
//
//	Original author: Ben Dorman, L3-Communications EER Systems Inc.
//## end module%38316E173E78.cp

//## Module: FitsError%38316E173E78; Package body
//## Subsystem: CCfits::FITS%393411910327
//## Source file: /local/data/xerxes1/gordon/headas/heacore/CCfits/FitsError.cxx

//## begin module%38316E173E78.additionalIncludes preserve=no
//## end module%38316E173E78.additionalIncludes

//## begin module%38316E173E78.includes preserve=yes
#ifdef _MSC_VER
#include "MSconfig.h" // for truncation warning
#include <cassert>
#endif

//## end module%38316E173E78.includes

// FITS
#include "FITS.h"
// FitsError
#include "FitsError.h"
//## begin module%38316E173E78.declarations preserve=no
//## end module%38316E173E78.declarations

//## begin module%38316E173E78.additionalDeclarations preserve=yes
//## end module%38316E173E78.additionalDeclarations


namespace CCfits {
  //## begin CCfits%37FE4140B6F8.initialDeclarations preserve=yes
  //## end CCfits%37FE4140B6F8.initialDeclarations

  // Class CCfits::FitsError 

  FitsError::FitsError (int errornum, bool silent)
    //## begin CCfits::FitsError::FitsError%38316F6835A0.hasinit preserve=yes
  : FitsException("FITS Error: ", silent)
    //## end CCfits::FitsError::FitsError%38316F6835A0.hasinit
    //## begin CCfits::FitsError::FitsError%38316F6835A0.initialization preserve=yes
    //## end CCfits::FitsError::FitsError%38316F6835A0.initialization
  {
    //## begin CCfits::FitsError::FitsError%38316F6835A0.body preserve=yes
  if (FITS::verboseMode() || !silent) printMsg(errornum);
    //## end CCfits::FitsError::FitsError%38316F6835A0.body
  }



  //## Other Operations (implementation)
  void FitsError::printMsg (int error)
  {
    //## begin CCfits::FitsError::printMsg%38316FECD898.body preserve=yes
  char message[FLEN_ERRMSG];


  fits_get_errstatus(error, message);
  std::cerr << message << "\n";
    //## end CCfits::FitsError::printMsg%38316FECD898.body
  }

  // Class CCfits::FitsException 

  FitsException::FitsException (const string& msg, bool& silent)
    //## begin CCfits::FitsException::FitsException%394651CD036A.hasinit preserve=no
    //## end CCfits::FitsException::FitsException%394651CD036A.hasinit
    //## begin CCfits::FitsException::FitsException%394651CD036A.initialization preserve=yes
    //## end CCfits::FitsException::FitsException%394651CD036A.initialization
  {
    //## begin CCfits::FitsException::FitsException%394651CD036A.body preserve=yes
  if (FITS::verboseMode() || !silent) 
  {
          std::cerr << '\n' << msg;
          // set this to false for the purpose of this exception.
          // does NOT change verbose mode setting so this value is thrown
          // away after the exception completes.
          silent = false;
  }
    //## end CCfits::FitsException::FitsException%394651CD036A.body
  }


  // Class CCfits::FitsFatal 

  FitsFatal::FitsFatal (const string& diag)
    //## begin CCfits::FitsFatal::FitsFatal%3AFAA825005B.hasinit preserve=no
    //## end CCfits::FitsFatal::FitsFatal%3AFAA825005B.hasinit
    //## begin CCfits::FitsFatal::FitsFatal%3AFAA825005B.initialization preserve=yes
    //## end CCfits::FitsFatal::FitsFatal%3AFAA825005B.initialization
  {
    //## begin CCfits::FitsFatal::FitsFatal%3AFAA825005B.body preserve=yes
     std::cerr << "*** CCfits Fatal Error: " << diag 
               << " please report this to xanprob@olegacy.gsfc.nasa.gov\n";

#ifdef TERMINATE_DEFECT
     // terminate() is not there as documented
	 assert ( false );
#else
	 std::terminate();
#endif
    //## end CCfits::FitsFatal::FitsFatal%3AFAA825005B.body
  }


} // namespace CCfits

//## begin module%38316E173E78.epilog preserve=yes
//## end module%38316E173E78.epilog
