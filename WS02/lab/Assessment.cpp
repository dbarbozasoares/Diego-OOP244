#include "Assessment.h"

namespace diego {

	void freeMem(Assessment*& aptr, int size) {
		for (int i = 0; i < size; i++) {
			delete &aptr[i];
		}
		delete[] aptr;
	}
}