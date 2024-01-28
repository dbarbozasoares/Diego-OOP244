// Student's name: Diego B Soares
// ID number: 145820239
// 01/27/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_ASSESSMENT_H
#define SENECA_ASSESSMENT_H
#include <stdio.h>
#include <string.h>

namespace seneca {
	struct Assessment {
		double* m_mark;
		char* m_title;
	};
	// Reads one integer from the fptr file into the value reference 
	bool read(int& value, FILE* fptr);

	//Skips a comma and then reads a cstring no longer than 60 characters from the fptr file into the address
	bool read(char* cstr, FILE* fptr);

	// read a double value from the fptr file into the value reference
	bool read(double& value, FILE* fptr);

	// read a double value for the mark and a string for the title into a temporary local double variable and a 60-character lone cString
	bool read(Assessment& assess, FILE* fptr);

	// read function receives a reference of an Assessment pointer (to hold a dynamic array) and a file pointer from which it will read the assessment records into a newly allocated dynamic array.
	int read(Assessment*& aptr, FILE* fptr);

	// This function will receive a reference of a dynamic Assessment array and its size. The function then will delete the dynamic Assessment array as follows:
	void freeMem(Assessment*& aptr, int size);

	// assign values from file into assesment array
	bool assignValues(Assessment& assess, FILE* fptr);
}
#endif
