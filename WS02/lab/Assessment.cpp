#define _CRT_SECURE_NO_WARNINGS
#include "Assessment.h"

namespace seneca {

	void freeMem(Assessment*& aptr, int size) {
		for (int i = 0; i < size; i++) {
			delete aptr[i].m_mark;
			delete[]aptr->m_title;
		}
		delete[] aptr;
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
			// if file reads an integer returns 1
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
			if (fscanf(fptr, "%60[^\n]\n", cstr) == 1) {
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
		char tmpTitle[maxCharName + 1];
		double tmpDoub = 0.0;

		if (fptr != nullptr) {
			if (read(tmpDoub, fptr)) {
				if (read(tmpTitle, fptr)) {
					assess.m_mark = new double(tmpDoub);
					assess.m_title = new char[strlen(tmpTitle) + 1];
				}
			}
		}
		else {
			return false;
		}
	}
	int read(Assessment*& aptr, FILE* fptr) {
		int totalAsmt = 0;
		if (fscanf(fptr, "%d", &totalAsmt) != 1) {
			return 0;
		}
		else {

		}
	}
}