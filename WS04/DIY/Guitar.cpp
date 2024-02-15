// Student's name: Diego B Soares
// ID number: 145820239
// 02/15/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/***********************************************************************
// OOP244 Workshop #4 p2: tester program
//
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
#include <iostream>
#include <cstring>
#include "Guitar.h"
using namespace std;

namespace seneca{
   const char* GuitarStr::material() const
   {
      return m_material;
   }
   double GuitarStr::gauge() const 
   {
      return m_gauge;
   }

   // default constructor
   GuitarStr::GuitarStr() {};

   GuitarStr::GuitarStr(const char* ma, double ga) 
   {
      strncpy(m_material, ma, MAT_LEN);
      m_gauge = ga;
   }

   Guitar::Guitar(const char* mod)
   {

       // initializing in a safe state
       this->m_numStrings = 0;
       this->m_strings = nullptr;
       this->m_model[0] = '\0';

       // make sure we receive a valid name model size
       if (strlen(mod) < MAX_MODEL_NAME && strlen(mod) > 0)
       {
           strcpy(this->m_model, mod); // assign new model name
       }
   };

   // Constructor for initializing a Guitar object with GuitarStr objects, the number of strings, and a model name
   Guitar::Guitar(GuitarStr strs[], int ns, const char* mod) {
       // initialize current object to safe state
       m_strings = nullptr;
       m_numStrings = 0;
       m_model[0] = '\0';
      
       // checks for max model and number of strings
       if (ns > 0 && ns <= 10 && mod != nullptr && strlen(mod) <= 15) {
           m_strings = new GuitarStr[ns];
           m_numStrings = ns;
           strcpy(this->m_model, mod);

           // assign each string from array parameter to current guitar's string array
           for (int i = 0; i < ns; ++i) {
               m_strings[i] = strs[i];
           }
       }
   }

   Guitar::~Guitar() {
       delete[] m_strings; // Release dynamically allocated memory
   }

   std::ostream& Guitar::display(std::ostream& os) const {
       if (this->m_strings == nullptr ) 
       {
           os << "***Empty Guitar***\n";
       }
       else
       {
           os << "Guitar Model: " << this->m_model;
           os << "\nStrings: " << this->m_numStrings << "\n";
           for (int i = 0; i < m_numStrings; i++) {
               os << "#" << i + 1;
               int sz = strlen(this->m_strings[i].material());
               if (sz == 5) {
                   os << "     ";
               }
               else {
                   os << "    ";
               }
               os << this->m_strings[i].material();
               os << " | " << setprecision(1) << this->m_strings[i].gauge() << "\n";

           }
       }
       return os;
   }

   // check if guitar has at least one string
   bool Guitar::strung() const {
       return this->m_numStrings > 0;
   }

   // removes all strings and set to safe state
   void Guitar::deString() {

       this->m_numStrings = 0;
       // Delete the dynamically allocated array of strings
       delete[] this->m_strings;

       // Set the pointer to the array of strings to nullptr
       this->m_strings = nullptr;
   }

   // change string by string object with material and gauge and index position
   bool Guitar::changeString(const GuitarStr& gs, int sn) {
       bool checker = false;

       // Check if the given string number (sn) is within the valid range
       if (sn >=0 && sn < this->m_numStrings) {
           this->m_strings[sn] = gs;
           checker = true;
       }
       return checker;
   }

   // Restring the guitar with the provided array of GuitarStr and the number of strings
   void Guitar::reString(GuitarStr strs[], int ns) {

       // Remove existing strings
       (*this).deString();

       // Allocate a new array for the specified number of strings
       this->m_strings = new GuitarStr[ns];

       // Set the number of strings
       this->m_numStrings = ns;

       // Copy the information from the provided array to the current guitar's string array
       for (int i = 0; i < ns; i++) {
           this->m_strings[i] = strs[i];
       }
   }

   // Check if any string on the guitar has a gauge matching the specified value.
   bool Guitar::matchGauge(double ga) const {
       bool checker = false; // flag

       // Iterate through each string on the guitar
       for (int i = 0; i < this->m_numStrings; i++) {
           if (this->m_strings[i].gauge() == ga) {
               checker = true;
           }
       }
       return checker;
   }

}
