#pragma once
#include <stdio.h>
namespace seneca {
	/// <returns>ture if file is opened successfuly or false if not</returns>
	bool openFile(const char* fname);
	void closeFile();
}