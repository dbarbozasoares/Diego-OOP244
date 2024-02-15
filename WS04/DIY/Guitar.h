// Student's name: Diego B Soares
// ID number: 145820239
// 02/15/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
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
#include <iomanip>

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

      // change string by string object with material and gauge and index position
      bool changeString(const GuitarStr& gs, int sn); 

      // Restring the guitar with the provided array of GuitarStr and the number of strings
      void reString(GuitarStr strs[], int ns); 

      // removes all strings and set to safe state
      void deString(); 

      // check if guitar has at least one string
      bool strung() const;  

      // Check if any string on the guitar has a gauge matching the specified value.
      bool matchGauge(double ga) const; 

      // overload output
      std::ostream& display(std::ostream& os = std::cout) const;

  };

}

#endif
