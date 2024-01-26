#ifndef SENECA_GRAPH_H
#define SENECA_GRAPH_H
#include <iostream>

namespace seneca {
	const int GRAPH_WIDTH = 65;
	// Fills the samples array with the statistic samples
	void getSamples(int samples[], int noOfSamples);
	// Finds the largest sample in the samples array, if it is larger than 70,
	// therwise it will return 70. 
	int findMax(int samples[], int noOfSamples);
	// erturns number of digits in an integer
	int intDigits(int value);
}
#endif