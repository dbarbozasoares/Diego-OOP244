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

   Guitar::Guitar(GuitarStr strs[], int ns, const char* mod)
   {
       Guitar temp; // in case parameters are not valid

       if (strs != nullptr && ns > 0 && strcmp(mod, "") != 0)
       {
           // deallocate previous memory if allocated
           if (this->m_strings != nullptr) 
           {
               delete[] this->m_strings;
               this->m_strings = nullptr;
           }

           this->m_strings = new GuitarStr[ns]; // allocate memory dynamically
           this->m_numStrings = ns;

           for (int i = 0; i < ns; i++) 
           {  // copy strings info to our GuitarStr inside Guitar Class
               this->m_strings[i] = strs[i];
           }

           // copy model name if doesn't exceed character limit
           if (strlen(mod) < MAX_MODEL_NAME && strlen(mod) > 0)
           {
               strcpy(this->m_model, mod); // assign new model name
           }
       }
       else
       {
           *this = temp; // set to empty
       }
   }

   Guitar::~Guitar() {}

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
               os << "     ";
               os << this->m_strings[i].material() << " | " << this->m_strings[i].gauge() << "\n";

           }
       }
       return os;
   }

   bool Guitar::strung() const {
       return this->m_numStrings > 0;
   }

   void Guitar::deString() {
       this->m_numStrings = 0;
       delete[] this->m_strings;
       this->m_strings = nullptr;
   }

   bool Guitar::changeString(const GuitarStr& gs, int sn) {
       bool checker = false;
       if (sn >=0 && sn < this->m_numStrings) {
           this->m_strings[sn] = gs;
           checker = true;
       }
       return checker;
   }

   void Guitar::reString(GuitarStr strs[], int ns) {

       (*this).deString();
       this->m_strings = new GuitarStr[ns];
       this->m_numStrings = ns;
       for (int i = 0; i < ns; i++) {
           this->m_strings[i] = strs[i];
       }
   }

   bool Guitar::matchGauge(double ga) const {
       bool checker = false;
       for (int i = 0; i < this->m_numStrings; i++) {
           if (this->m_strings[i].gauge() == ga) {
               checker = true;
           }
       }
       return checker;
   }

}
