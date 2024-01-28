// Student's name: Diego B Soares
// ID number: 145820239
// 01/27/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "Assessment.h"

namespace seneca {

	void freeMem(Assessment*& aptr, int size) {
		int i;
		for (i = 0; i < size; i++) {
			delete aptr[i].m_mark;
			delete[] aptr[i].m_title;
		}
		delete[] aptr;
		aptr = nullptr;
	}
	bool read(int& value, FILE* fptr) {
		if (fptr != nullptr) {
			// if file reads an integer returns 1
			if (fscanf(fptr, "%d", &value) == 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	bool read(double& value, FILE* fptr) {

		if (fptr != nullptr) {
			// if file reads a double returns 1
			if (fscanf(fptr, "%lf", &value) == 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	bool read(char* cstr, FILE* fptr) {
		if (fptr != nullptr) {
			// if file reads an integer returns 1, note coma before start reading
			if (fscanf(fptr, ",%60[^\n]\n", cstr) == 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	bool assignValues(Assessment& assess, FILE* fptr) {
		char tmpTitle[61];
		double tmpDoub = 0.0;

		if (read(tmpDoub, fptr) && read(tmpTitle, fptr)) {
			tmpTitle[60] = '\0';
			// allocate memory dynamically for a double value
			assess.m_mark = new double;
			*assess.m_mark = tmpDoub;

			assess.m_title = new char[strlen(tmpTitle) + 1];
			strcpy(assess.m_title, tmpTitle);
			return true;
		}
		else {
			
			return false;
		}
	}

	bool read(Assessment& assess, FILE* fptr) {

		if (fptr != nullptr) {
			{
				return assignValues(assess, fptr) == true;
			}
		}
		else {
			return false;
		}
	}

	int read(Assessment*& aptr, FILE* fptr) {
		int cnt, totalRead = 0;

		if (fptr != nullptr) {
			if (read(cnt, fptr)) {
				// Allocating dynamically array of Assessments
				aptr = new Assessment[cnt];
					for (int i = 0; i < cnt; i++) {
						if (read(aptr[i], fptr)) {
							totalRead++;
						}
					}
			}
			if (totalRead == cnt) {
				return totalRead;
			}
		}
		freeMem(aptr, totalRead);
		return 0;
	}
}