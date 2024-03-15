/*/////////////////////////////////////////////////////////////////////////
                          Workshop - 6
Full Name  : Diego Barboza Soares
Student ID#: 145820239
Email      : dbarboza-soares@myseneca.ca
Section    : NII
Date       : 14th March 2024

Authenticity Declaration:

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
/***********************************************************************
// OOP244 Workshop # 6
//
// File: EmailFile.cpp
// Version 1.0
// Date:
// Author: Sina Talebi Moghaddam
// Description
// This file must be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <cstring>
#include "EmailFile.h"

using namespace std;
namespace seneca
{
    // ****************  EMAIL ************************
    // ////////////////////////////////////////////////
    Email& Email::operator=(const Email& rhs) {

        if (this != &rhs && rhs.m_email && rhs.m_name) {
            delete[] m_email;
            m_email = nullptr;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
            strcpy(m_year, rhs.m_year);
        }

        return *this;
    }

    bool Email::load(std::ifstream& in) {

        char buffer[BUFFER_SIZE];
        bool result = false;

        if (in.getline(buffer, BUFFER_SIZE, ',')) {
            delete[] m_email;
            m_email = new char[strlen(buffer) + 1];
            strcpy(m_email, buffer);

            if (in.getline(buffer, BUFFER_SIZE, ',')) {
                delete[] m_name;
                m_name = new char[strlen(buffer) + 1];
                strcpy(m_name, buffer);

                if (in.getline(buffer, BUFFER_SIZE, '\n')) {
                    strcpy(m_year, buffer);
                    result = true;
                }
            }
        }

        return result;
    }

    Email::~Email() {
        delete[] m_name;
        delete[] m_email;
    }

    void EmailFile::setFilename(const char* filename)
    {
        delete[] m_filename;
        m_filename = nullptr;
        if (filename)
        {
            m_filename = new char[strlen(filename) + 1];
            m_filename[0] = '\0';
            strcpy(m_filename, filename);
        }
    }

    void EmailFile::setEmpty()
    {
        delete[] m_emailLines;
        delete[] m_filename;
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;
    }


    // ////////////////////////////////////////////////////
    // ////////////////////////////////////////////////////
    // *********** EMAILFILE *****************************

    EmailFile::EmailFile() {
        m_filename = nullptr;
        m_noOfEmails = 0;
        m_emailLines = nullptr;
    }

    EmailFile::EmailFile(const char* filename) {
        // Initialize members to safe state
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;

        if (filename != nullptr) {
            // set all member data 
            setFilename(filename);
            setNoOfEmails();
            loadEmails();
        }
        else {
            setEmpty();
        }
    }

    EmailFile::EmailFile(const EmailFile& filename) {
        *this = filename;
    }

    EmailFile& EmailFile::operator=(const EmailFile& filename)
    {
        if (this != &filename) {
            this->copyData(filename);
        }
        return *this;
    }


    EmailFile::~EmailFile()
    {
        if (m_emailLines != nullptr) {
            delete[] m_emailLines;
            m_emailLines = nullptr;
        }
        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }
    }

    void EmailFile::copyData(const EmailFile& filename) {
        setEmpty();
        delete[] this->m_emailLines;
        delete[] this->m_filename;

        this->m_filename = new char[strlen(filename.m_filename) + 1];
        strcpy(this->m_filename, filename.m_filename);

        this->m_noOfEmails = filename.m_noOfEmails;

        this->m_emailLines = new Email[this->m_noOfEmails];
        for (int i = 0; i < this->m_noOfEmails; i++) {
            this->m_emailLines[i] = filename.m_emailLines[i];
        }
    }

    void EmailFile::loadEmails()
    {
        if (!isEmpty()) {
            // OPEN FILE
            ifstream readFile;
            readFile.open(m_filename);

            if (readFile.is_open()) {

                setNoOfEmails(); // sets total of emails
                delete[] m_emailLines; // delete previous data
                m_emailLines = new Email[m_noOfEmails]; // set new size based on new total of emails
                for (int i = 0; i < m_noOfEmails; i++) {
                    if (m_emailLines[i].Email::load(readFile) == false) {
                        //if it can not read a valid email, stop looping and update right amount of lines
                        m_noOfEmails = i;
                        i = m_noOfEmails;
                    }
                }
                readFile.close();
            }
        }
        else {
            *this = EmailFile();
        }
    }

    void EmailFile::fileCat(const EmailFile& obj, const char* name) {
        if (!obj.isEmpty() && !this->isEmpty() && obj.m_noOfEmails > 0) {
            int totalEmails = this->m_noOfEmails + obj.m_noOfEmails;

            appendEmails(totalEmails, obj);

            if (name != nullptr) {
                delete[] m_filename;
                m_filename = new char[strlen(name) + 1];
                strcpy(m_filename, name);
            }

            saveToFile(m_filename);
        }
        return;
    }

    void EmailFile::appendEmails(int totalEmails, const EmailFile& obj) {
        Email* temp = new Email[totalEmails];
        for (int i = 0; i < this->m_noOfEmails; i++) {
            temp[i] = this->m_emailLines[i];
        }
        for (int j = 0; j < obj.m_noOfEmails; j++) {
            temp[this->m_noOfEmails + j] = obj.m_emailLines[j];
        }
        delete[] m_emailLines;

        m_emailLines = temp;
        m_noOfEmails = totalEmails;

    }

    bool EmailFile::saveToFile(const char* filename) const
    {
        bool checker = false;
        ofstream writeFile;
        writeFile.open(filename);

        if (writeFile) {
            for (int i = 0; i < m_noOfEmails; i++) {
                writeFile << m_emailLines[i].m_email << "," << m_emailLines[i].m_name << "," << m_emailLines[i].m_year << endl;
            }
            checker = true;
        }
        else {
            cout << "Error: Could not open file: " << filename << endl;
        }
        // close file
        writeFile.close();
        return checker;
    }

    bool EmailFile::setNoOfEmails() {

        bool isValid = false;
        ifstream file(m_filename);

        if (!file.is_open()) {
            cout << "Failed to open file: " << m_filename << endl;
        }
        else
        {
            m_noOfEmails = 0;
            while (file) {
                m_noOfEmails += (file.get() == '\n');
            }
            file.close();

            if (m_noOfEmails == 0)
            {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else {
                m_noOfEmails++;
                isValid = true;
            }
        }
        return isValid;
    }

    bool EmailFile::isEmpty() const // student
    {
        return (m_emailLines == nullptr && m_filename == nullptr && m_noOfEmails == 0);
    }

    EmailFile::operator bool() const
    {
        return isEmpty();
    }

    std::ostream& EmailFile::view(std::ostream& ostr) const
    {
        if (m_filename) {
            ostr << m_filename << endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails; i++) {
                ostr.width(35);
                ostr.setf(ios::left);
                ostr << m_emailLines[i].m_email;
                ostr.width(25);
                ostr << m_emailLines[i].m_name;
                ostr << "Year = " << m_emailLines[i].m_year << endl;
            }
        }

        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const EmailFile& text)
    {
        return text.view(ostr);
    }

}