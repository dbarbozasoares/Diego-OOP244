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
      const char* name()const;
      int weight()const;
      Food();
      Food(const char* nm, int wei);
   };

   class Fridge {
       Food m_foods[FRIDGE_CAP];
       int m_numFoods;
       char* m_model;

   public:
       Fridge();
       Fridge(Food farr[], int nf, const char* mod = "Ice Age");
       ~Fridge();
       bool addFood(const Food& f);
       void changeModel(const char* m);
       bool findFood(const char* f) const;
       bool fullFridge() const;
       std::ostream& display(std::ostream& os = std::cout) const;
   };

}

#endif
