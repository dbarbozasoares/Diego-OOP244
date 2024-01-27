#ifndef ASSESSMENT_H
#define ASSESMENT_H

namespace diego {

	struct Assessment {
		double* m_mark;
		char* m_title;
	};

	void freeMem(Assessment*& aptr, int size);
}
#endif
