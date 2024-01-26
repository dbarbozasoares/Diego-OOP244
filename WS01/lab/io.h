#ifndef SENECA_IO_H
#define SENECA_IO_H
#include <iostream>
#include "StMark.h"
namespace seneca {
	// Maximum number of samples in an graph
	const int MAX_NO_OF_S = 20;
	// prints the int value in width of fieldWidth
	void printInt(int value, int fieldWidth);
	// Performs a fool-proof integer entry assuming the user will only enter numeric values.
	// if the user enters non digit values, the function will hang in an endless loop.
	int getInt(int min, int max);
	// moves the cursor backwards
	void goBack(int n);
	// displays the user interface menu
	int menu(int noOfSamples);
	// Prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max);
	// Draws a line and adds a label
	void labelLine(int n, const char* label);
	// Draws a line
	void line(int n);
	// Prints a graph comparing the sample values visually 
	void printGraph(int samples[], int noOfSamples, const char* label);

}
#endif