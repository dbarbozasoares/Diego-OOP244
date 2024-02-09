// Student's name: Diego B Soares
// ID number: 145820239
// 02/08/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef ICECREAM_H
#define ICECREAM_H
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// ICE CREAM VALUES IF OWNER CHANGE ITS VALUE
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
		const char* flavourName[MAX_FLAVOURS+1]; // stores flavours by name
		double totalOrder;

	public:
		// default constructor
		IceCream();

		// call option functions  waffle, scoops and flavour
		void receiveOrder(void);

		// ask user what flavour by number
		int receiveFlavour(void);

		// return flavour number so we can print after flavour name calling by index
		int getFlavour(void); 

		// returns flavour name by index as parameter
		const char* getFlavourName(int); 

		// ask user if want vanilla wafer
		bool receiveWafferOpt(void);

		// return if user opted for extra wafle
		bool getVanillaOpt(void);

		// ask user how many scoops
		int receiveScoopUser(void);

		// return how many scoop user chose
		int getTotalScoop(void);

		// print order for 1 icecream
		void printOrder(void);

		// calcualte total for each icecream and assign local variables so we can print it out based on icecream option
		int calculateTotal(double*, double*, double*);

		// return total $ for the order
		double getTotalOrder();
	};
}
#endif