
//	This is CCfits version 1.0-beta release August 2001

//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	August 2001 Ben Dorman, Emergent-IT, Inc.
//	e-mail: ccfits@lheamail.gsfc.nasa.gov




// FITS
#include "FITS.h"
// FitsError
#include "FitsError.h"



namespace CCfits {

  // Class CCfits::FitsError 

  FitsError::FitsError (int errornum, bool silent)
  : FitsException("FITS Error: ", silent)
  {
  if (FITS::verboseMode() || !silent) printMsg(errornum);
  }



  void FitsError::printMsg (int error)
  {
  char message[FLEN_ERRMSG];


  fits_get_errstatus(error, message);
  std::cerr << message << "\n";
  }

  // Class CCfits::FitsFatal 

  FitsFatal::FitsFatal (const string& diag)
  {
     std::cerr << "*** CCfits Fatal Error: " << diag 
               << " please report this to xanprob@olegacy.gsfc.nasa.gov\n";
     std::terminate();
  }


  // Class CCfits::FitsException 

  FitsException::FitsException (const string& msg, bool& silent)
  {
  if (FITS::verboseMode() || !silent) 
  {
          std::cerr << '\n' << msg;
          // set this to false for the purpose of this exception.
          // does NOT change verbose mode setting so this value is thrown
          // away after the exception completes.
          silent = false;
  }
  }


} // namespace CCfits

