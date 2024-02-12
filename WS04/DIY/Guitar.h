/***********************************************************************
// OOP244 Workshop #4 p2: tester program
// File  main.cpp
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H

#define MAT_LEN 10
#define MAX_MODEL_NAME 15
#include <iostream>

namespace seneca{


  class GuitarStr {
      char m_material[MAT_LEN]{};
      double m_gauge{};
  public:
      GuitarStr();
      GuitarStr(const char* ma, double ga);
      const char* material()const;
      double gauge()const;
  };

  class Guitar {
      GuitarStr* m_strings;
      int m_numStrings;
      char m_model[MAX_MODEL_NAME + 1];

  public:
      Guitar(const char* mod = "Stratocaster"); // default value if not declared
      Guitar(GuitarStr strs[], int ns, const char* mod);
      ~Guitar(); // destructor
      bool changeString(const GuitarStr& gs, int sn);
      void reString(GuitarStr strs[], int ns);
      void deString();
      bool strung() const;
      bool matchGauge(double ga) const;
      std::ostream& display(std::ostream& os = std::cout) const;

  };

}

#endif
