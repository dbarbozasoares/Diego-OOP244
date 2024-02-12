// Student's name: Diego B Soares
// ID number: 145820239
// 02/09/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/***********************************************************************
// OOP244 Workshop #4 p1
//
// File	Fridge.cpp
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
#include <cstring>
#include <iostream>
#include "Fridge.h"
using namespace std;

namespace seneca {

    // returns food name
    const char* Food::name() const {
        return m_name;
    } 

    // returns weight
    int Food::weight() const {
        return m_weight;
    } 

    ////////////////////////////////////////////////////////////
    ////////////////////  CONSTRUCTORS /////////////////////////
    Fridge::Fridge() {
        this->m_numFoods = 0;
        this->m_model = nullptr;
    }

    // default Food constructor
    Food::Food() {} 

    // constructor with no name, default name: Ice Age
    Food::Food(const char* nm, int wei) {
        strncpy(m_name, nm, NAME_LEN);
        m_weight = wei;
    }

    // constructor with all parameters
    Fridge::Fridge(Food farr[], int nf, const char* mod)
    {
        Fridge tempFridge;
        *this = tempFridge;
        if (nf > 0 && (mod != nullptr && strlen(mod) > 0) && strcmp(mod, "") != 0) {
            this->m_numFoods = nf; // set number of foods in this fridge
            // allocate memory for model
            this->m_model = new char[strlen(mod) + 1];
            // assign model name for current object
            strcpy(this->m_model, mod);
            // if number of food passed to fridge is over fridge limit, set number of food to fridge limit
            if (nf > FRIDGE_CAP) {
                nf = FRIDGE_CAP;
            }
            // fridge receives each food from array
            for (int i = 0; i < nf; i++) {
                this->m_foods[i] = farr[i]; // assign one food to new fridge array
            }
        }
    }

    ///////////////////  DESTRUCTOR  ///////////////////////////

    Fridge::~Fridge() {
        delete[] this->m_model;
        this->m_model = nullptr;
    }

    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    /////////////// MODIFIERS //////////////////////////////
    // add food if fridge not empty
    bool Fridge::addFood(const Food& f) {
        bool foodAdd = false;
        if (this->m_numFoods < FRIDGE_CAP) {
            this->m_foods[this->m_numFoods] = f;
            this->m_numFoods++;
            foodAdd = true;
        }
        return foodAdd;
    }

    // change model name
    void Fridge::changeModel(const char* m) {
        if (this->m_model != nullptr) {
            delete[] this->m_model; // deallocate previous fridge model memory if not null
        }
        this->m_model = new char[strlen(m) + 1];
        strcpy(this->m_model, m);
    }

    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    /////////////// QUERIES ////////////////////////////////

    // returns true if fridge is full
    bool Fridge::fullFridge() const {
        bool isFull = false;
        if (this->m_numFoods == FRIDGE_CAP) {
            isFull = true;
        }
        return isFull;
    }

    // find food by name and return true if find
    bool Fridge::findFood(const char* f) const {
        bool wasFound = false;
        for (int i = 0; i < this->m_numFoods; i++) {
            if (strcmp(this->m_foods[i].name(), f) == 0) { // strcmp returns 0 if true
                wasFound = true;
            }
        }
        return wasFound;
    }

    // display all fridge information if model not null
    std::ostream& Fridge::display(std::ostream& os) const {
        if (this->m_model != nullptr) { // if model equals null, just return os
            os << "Fridge model: " << this->m_model << std::endl;
            os << "Food count: " << this->m_numFoods << " Capacity: " << FRIDGE_CAP << std::endl;
            os << "List of Foods" << std::endl;
            for (int i = 0; i < this->m_numFoods; i++) {
                os.width(NAME_LEN);
                os << this->m_foods[i].name()  << " | " << this->m_foods[i].weight() << std::endl;
            }
        }
        return os;
        
    }
}
