#define _CRT_SECURE_NO_WARNINGS
#include "file.h"
namespace seneca {
    FILE* datafile = nullptr;
    bool openFile(FILE* fname)
    {
        if (datafile != nullptr) closeFile();
        datafile = fname;
        return datafile != nullptr;
    }

    void closeFile() {
        if (datafile) {
            fclose(datafile);
            datafile = nullptr;
        }
    }

}