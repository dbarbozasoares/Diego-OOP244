
#include "StMark.h"
#include "file.h"
#include "graph.h"
#include "io.h"
/// Tries to open the students' mark data file. 
/// If successful it will print a report based on the 
/// date in the file.
/// </summary>
/// <param name="filename">, holds the data file name</param>
/// <returns>True if the date files is opened succesfully, 
/// otherwise returns false</returns>
bool seneca::printReport(const char* filename) {

	StMark stArr[MAX_NO_RECS] = { 0 };
	int numbersRange[max_cat_range] = { 0 };
	int totalStudents = 0;
	char label[] = { "Students' mark distribution" };

	if (openFile(filename)) {
		// gets total of students read from file
		totalStudents = readMarks(stArr);

		// fill up students array
		fillStdArray(stArr, totalStudents);

		// sort students array in descending order
		sortArray(stArr, totalStudents);

		// get total for each range 0-10 11-20 21-30
		marksRange(stArr, numbersRange, totalStudents);

		// prints students mark range graph
		printGraph(numbersRange, max_cat_range, label);

		// display students data grade + full name
		displayStdData(stArr, totalStudents);

		
		closeFile();
		return true;
	}
	else {
		return false;
	}
}

	// sort students array by student marks in descending order
	void seneca::sortArray(struct StMark* studentsArr, int size) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				struct StMark tmp;
				if (studentsArr[j].mark < studentsArr[j+1].mark) {
					tmp = studentsArr[j];
					studentsArr[j] = studentsArr[j+1];
					studentsArr[j+1] = tmp;
				}
			}
		}
	}

	// fill array type StdMark
	void seneca::fillStdArray(struct StMark* stdArray, int size) {
		for (int i = 0; i < size; i++) {
			readMark(&stdArray[i]);
		}
	}

	// stores range number 0-10: array[10] and so on...
	void seneca::marksRange(struct StMark* studentsArr, int* numByRange, int totalStudents) {
		for (int i = 0; i < totalStudents; i++) {
			if (studentsArr[i].mark <= 100 && studentsArr[i].mark > 90) {
				numByRange[0] += 1;
			}
			else if (studentsArr[i].mark < 91 && studentsArr[i].mark > 80) {
				numByRange[1] += 1;
			}
			else if (studentsArr[i].mark < 81 && studentsArr[i].mark > 70) {
				numByRange[2] += 1;
			}
			else if (studentsArr[i].mark < 71 && studentsArr[i].mark > 60) {
				numByRange[3] += 1;
			}
			else if (studentsArr[i].mark < 61 && studentsArr[i].mark > 50) {
				numByRange[4] += 1;
			}
			else if (studentsArr[i].mark < 51 && studentsArr[i].mark > 40) {
				numByRange[5] += 1;
			}
			else if (studentsArr[i].mark < 41 && studentsArr[i].mark > 30) {
				numByRange[6] += 1;
			}
			else if (studentsArr[i].mark < 31 && studentsArr[i].mark > 20) {
				numByRange[7] += 1;
			}
			else if (studentsArr[i].mark < 21 && studentsArr[i].mark > 10) {
				numByRange[8] += 1;
			}
			else if (studentsArr[i].mark < 11 && studentsArr[i].mark >= 0) {
				numByRange[9] += 1;
			}
		}
	}