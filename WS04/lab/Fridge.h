// Student's name: Diego B Soares
// ID number: 145820239
// 02/09/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
// OOP244 Workshop #4 p2
//
// File	Fridge.h
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H

#define FRIDGE_CAP 3
#include <cstring>
#include <iostream>

namespace seneca{

   const int NAME_LEN = 20;

   class Food {
      char m_name[NAME_LEN]{};
      int m_weight{};
   public:
      const char* name()const; // returns food name
      int weight()const; // returns food weight
      Food(); // default constructor
      Food(const char* nm, int wei); // constructor with all parameters
   };

   class Fridge {
       Food m_foods[FRIDGE_CAP];
       int m_numFoods;
       char* m_model;

   public:
       Fridge(); // default constructor
       Fridge(Food farr[], int nf, const char* mod = "Ice Age"); // if doesnt receive thirs parameter mod, assign to Ice Age
       ~Fridge();
       bool addFood(const Food& f); // add food in fridge 
       void changeModel(const char* m); // change model name and return true if find it
       bool findFood(const char* f) const; // find a food by name trough fridge food array
       bool fullFridge() const; // returns true if fridge is full
       std::ostream& display(std::ostream& os = std::cout) const; // display all information about fridge if not null
   };

}

#endif
