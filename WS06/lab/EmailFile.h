#pragma once
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
// File:	EmailFile.h
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
#ifndef SENECA_EMAILFILE_H
#define SENECA_EMAILFILE_H
#include <iostream>

namespace seneca {

	const int BUFFER_SIZE = 1024; // Maximum possible size for all the fields of the Email record

	class EmailFile;
	class Email
	{
		char* m_email{ nullptr };
		char* m_name{ nullptr };
		char m_year[5]{ '\0' };
		Email() {};
		Email& operator=(const Email&);
		bool load(std::ifstream& in);
		~Email();

		// Prohibit copy constructor for this class: 
		Email(const Email&) = delete;

		// Make the EmailFile class friend of the Email class
		friend class EmailFile;
	};


	class EmailFile
	{
		Email* m_emailLines{ nullptr };
		char* m_filename{};
		int m_noOfEmails{ 0 };
		void setFilename(const char* filename);
		void setEmpty();
		bool setNoOfEmails();
		void loadEmails();
		operator bool() const;
		bool isEmpty() const;
		void copyData(const EmailFile& filename);
		void appendEmails(int totalEmails, const EmailFile& obj);
	public:
		EmailFile(); // default constructor
		EmailFile(const char* filename);
		EmailFile(const EmailFile& filename); // copy constructor
		EmailFile& operator=(const EmailFile& filename);  // copy assignment
		~EmailFile(); // destructor
		void fileCat(const EmailFile& obj, const char* name = nullptr); // merges emails from paramenter into current object
		bool saveToFile(const char*) const; 
		std::ostream& view(std::ostream& ostr) const;
	};

	std::ostream& operator<<(std::ostream& ostr, const EmailFile& text);

}
#endif // !SENECA_EMAILFILE_H
