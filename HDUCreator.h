
//	This is version 1.1 release dated May 2002

//	Laboratory for High Energy Astrophysics,
//	NASA/ Goddard Space Flight Center
//	HEASARC
//	http://heasarc.gsfc.nasa.gov
//
//	May 2002 Ben Dorman, L3-Com Analytics Corporation
//	e-mail: ccfits@legacy.gsfc.nasa.gov


#ifndef HDUCREATOR_H
#define HDUCREATOR_H 1


// typeinfo
#include <typeinfo>
// vector
#include <vector>
// valarray
#include <valarray>
// string
#include <string>
// CCfitsHeader
#include "CCfits.h"
// FitsError
#include "FitsError.h"

namespace CCfits {
  class FITSBase;
  class HDU;
  class PHDU;
  class ExtHDU;

} // namespace CCfits



using std::string;


namespace CCfits {






  class HDUCreator 
  {

    public:
        HDUCreator (FITSBase* p);

        ~HDUCreator();


        //	Read a specified HDU from given fitsfile and
        //	return a pointer to it.
        HDU * getHdu (const string& hduName, bool readDataFlag = false, const std::vector<string> &keys = std::vector<string>(), bool primary = false, int version = 1);

        PHDU * createImage (int bitpix, long naxis, const std::vector<long>& naxes);

        void reset ();

        HDU* createTable (const string &name, HduType xtype, int rows, const std::vector<string>& colName, const std::vector<string> colFmt, const std::vector<string> colUnit, int version);

        //	Read a specified HDU from given fitsfile and
        //	return a pointer to it.
        //
        //	With no arguments this reads the PrimaryHDU.
        HDU * getHdu (int index = 0, bool readDataFlag = false, const std::vector<string> &keys = std::vector<string>());

        ExtHDU * createImage (const string &name, int bitpix, long naxis, const std::vector<long>& naxes, int version);

      // Additional Public Declarations

    protected:
      // Additional Protected Declarations

    private:

        PHDU * MakeImage (int bpix, int naxis, const std::vector<long>& naxes);

        HDU * Make (const string& hduName, bool readDataFlag, const std::vector<string> &keys, bool primary, int version);

        HDU* MakeTable (const string &name, HduType xtype, int rows, const std::vector<string>& colName, const std::vector<string>& colFmt, const std::vector<string>& colUnit, int version);

        HDU * Make (int index, bool readDataFlag, const std::vector<string> &keys);

        ExtHDU * MakeImage (const string &name, int bpix, long naxis, const std::vector<long>& naxes, int version);

        void getScaling (long& type, double& zero, double& scale) const;

      // Data Members for Class Attributes

        HDU *m_hdu;

      // Additional Private Declarations

    private: //## implementation
      // Data Members for Associations

        FITSBase* m_parent;

      // Additional Implementation Declarations

  };


  // Class CCfits::HDUCreator 


  inline HDU * HDUCreator::getHdu (const string& hduName, bool readDataFlag, const std::vector<string> &keys, bool primary, int version)
  {
  //! Read an existing HDU object from the current fits file and return a pointer.
  if ( m_hdu == 0 ) m_hdu = Make(hduName,readDataFlag,keys,primary,version);
  return m_hdu;
  }

  inline void HDUCreator::reset ()
  {
  m_hdu = 0;
  }

  inline HDU* HDUCreator::createTable (const string &name, HduType xtype, int rows, const std::vector<string>& colName, const std::vector<string> colFmt, const std::vector<string> colUnit, int version)
  {
        //! Create new Table extension (write method),  and return a pointer to it.
        if (m_hdu == 0) m_hdu = MakeTable(name,xtype,rows,colName,colFmt,colUnit,version);
        return m_hdu;
  }

  inline HDU * HDUCreator::getHdu (int index, bool readDataFlag, const std::vector<string> &keys)
  {
  //! Read HDU specified by HDU number
  if ( m_hdu == 0 ) m_hdu = Make(index,readDataFlag,keys);
  return m_hdu;
  }

} // namespace CCfits



#endif
