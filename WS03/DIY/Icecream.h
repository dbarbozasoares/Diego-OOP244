#ifndef ICECREAM_H
#define ICECREAM_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// ICE CREAM VALUES IF HAS TO CHANGE
#define PRICE_BY_SCOOP 5
#define PRICE_VANILLA_WAFFER_EXTRA 5
#define PRICE_EXTRA_SCOOP_CHOCOLATE 1
#define MAX_FLAVOURS 5
#define MAX_SCOOPS 3

namespace seneca {
	class IceCream {
		double priceByScoop;
		bool extraVanillaWaffer; // y or n
		int totalScoops;
		int flavour; // select by number, not by name
		const char* flavourName[MAX_FLAVOURS+1];

	public:
		
		// default constructor
		IceCream();
		const char* getFlavourName(int n);
		void getOrder(void);
		int receiveFlavour(void);
		int getFlavour(void);
		bool checkWaffer(void);
		int getScoopUser(void);
		int getTotalScoop(void);
		bool getVanillaOpt(void);
		void printOrder(void);
		int calculateTotal(double*, double*, double*);
	};

	
}
#endif