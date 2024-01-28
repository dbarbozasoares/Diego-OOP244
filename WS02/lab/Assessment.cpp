#define _CRT_SECURE_NO_WARNINGS
#include "Assessment.h"

namespace seneca {

	void freeMem(Assessment*& aptr, int size) {
		for (int i = 0; i < size; i++) {
			delete[i] aptr;
		}
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
			// if file reads an integer returns 1
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
	bool read(Assessment& assess, FILE* fptr) {
		char tmpTitle[maxCharName + 1] = { '\0' };
		double tmpDoub = 0.0;
		double* tmpPtr = nullptr;

		if (fptr != nullptr) {
			if (read(tmpDoub, fptr) && read(tmpTitle, fptr)) {
				assess.m_title = new char[strlen(tmpTitle) + 1];
				strcpy(assess.m_title, tmpTitle);
				// allocate memory dynamically for a double value
				assess.m_mark = new double;
				*assess.m_mark = tmpDoub;
				return true;
			}
		}
		else {
			return false;
		}
	}
	int read(Assessment*& aptr, FILE* fptr) {
		int cnt, totalRead = 0;
		
		if (fptr != nullptr) {
			read(cnt, fptr);
			// Allocating dynamically array of Assessments
			aptr = new Assessment[cnt];
			for (int i = 0; i < cnt; i++) {
				if (read(aptr[i], fptr)) {
					totalRead++;
				}
			}
			if (totalRead == cnt) {
				return totalRead;
			}
			else {
				delete[] aptr;
				aptr = nullptr;
				return 0;
			}
		}
	}
}