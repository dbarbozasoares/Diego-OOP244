/***********************************************************************
OOP244 Workshop # p2: 
Version 1.0
Date	   winter 2024
Author	Fardad Soleimanloo
Description
  tests the file module of workshop 1 part 2(DIY)
Revision History
-----------------------------------------------------------
Name            Date            Reason
***********************************************************************/
#ifndef SENECA_STMARK_H
#define SENECA_STMARK_H
namespace seneca {
    const int max_cat_range = 10;
   /// <summary>
   /// Record of a mark received by a student.
   /// </summary>
   struct StMark {
      char name[21];
      char surname[31];
      int mark;
   };
   bool printReport(const char* filename);
   // bubble sorting by marks in descending order
   void sortArray(struct StMark* studentsArr);
   // Display all student data in descending order
   void displayStdData(struct StMark* stdArray, int);
   // Fill up students array
   void fillStdArray(struct StMark* stdArray, int size);
   // stores range number 0-10: array[10] and so on...
   void marksRange(struct StMark* studentsArr, int* numByRange, int totalStudents);
   // Prints a graph comparing the sample values visually 
   void printGraph(int samples[], int noOfSamples, const char* label);

}
#endif // !SENECA_STMARK_H


