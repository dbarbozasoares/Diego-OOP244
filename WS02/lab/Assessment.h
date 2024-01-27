#ifndef ASSESSMENT_H
#define ASSESMENT_H
#include <stdio.h>
#include <string.h>
namespace seneca {
	const int maxCharName = 60;
	struct Assessment {
		double* m_mark;
		char* m_title;
	};

	bool read(int& value, FILE* fptr);
	bool read(double& value, FILE* fptr);
	bool read(char* cstr, FILE* fptr);
	bool read(Assessment& assess, FILE* fptr);
	int read(Assessment*& aptr, FILE* fptr);
	void freeMem(Assessment*& aptr, int size);
}
#endif
