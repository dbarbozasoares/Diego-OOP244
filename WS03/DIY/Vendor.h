// Student's name: Diego B Soares
// ID number: 145820239
// 02/08/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef VENDOR_H
#define VENDOR_H
#include "Icecream.h"
#define FEDERAL_TAX 0.13

namespace seneca {
	class Vendor {
		IceCream* iceCream; // icecream array
		int totalOrders;

	public:
		void setEmpty(void); // set all members variables to nullptr or 0;
		void takeOrders(void); // receive orders for each icecream
		void displayOrders(void); // display all orders
		void clearData(void); // free mem
		void printIceCream(void); // print an icecream on screen
		void displayBottom(double total); // display total with tax
	};
}

#endif