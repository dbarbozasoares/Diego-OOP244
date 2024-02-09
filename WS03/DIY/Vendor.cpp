// Student's name: Diego B Soares
// ID number: 145820239
// 02/08/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "Vendor.h"

namespace seneca {

	///////////////////// INPUT OUTPUT ///////////////////////

	// print an icecream on screen
	void Vendor::printIceCream(void) {
		cout << "Seneca Icecream shop" << endl;
		cout.width(11);
		cout << "@" << endl;
		cout.width(13);
		cout << "(' .)" << endl;
		cout.width(14);
		cout << "(*.`. )" << endl;
		cout.width(13);
		cout << "\\###/" << endl;
		cout.width(12);
		cout << "\\#/" << endl;
		cout.width(11);
		cout << "V" << endl;
	}

	// display all orders
	void Vendor::displayOrders(void) {
		double total = 0;
		cout << "\n";
		cout << "********** Order Summary **********" << endl;
		for (int i = 0; i < this->totalOrders; i++) {
			if (i == (totalOrders - 1)) {
				cout << "\nOrder No: " << i + 1 << ":" << endl;
			}
			else {
				cout << "Order No: " << i + 1 << ":" << endl;
			}
			cout << "Order details:" << "                Price" << endl;
			cout << "-----------------------------------\n";
			this->iceCream[i].printOrder(); // prints each object
			total += this->iceCream[i].getTotalOrder();
		}
		displayBottom(total);

	}

	// display total with tax
	void Vendor::displayBottom(double total) {
		cout << "-----------------------------------" << endl;
		cout << "Price:";
		cout.width(29);
		cout << total << endl;

		cout << "Tax:";
		cout.width(31);
		cout << (total * FEDERAL_TAX) << endl;

		cout << "Total Price ($):";
		cout.width(19);
		cout << total + (total * FEDERAL_TAX) << endl;


	}

	// receive orders for each icecream
	void Vendor::takeOrders(void) {
		printIceCream();
		cout << "How many Icecreams?" << endl << "> ";
		cin >> this->totalOrders;
		while (this->totalOrders < 1) {
			cout << "You have to choose at least one icecream!" << endl;
			cin >> this->totalOrders;
			cout << "Quantity: " << endl;
		}

		// free mem
		delete[] this->iceCream;

		// set a dynamic size for quantity of icecream
		this->iceCream = new IceCream[this->totalOrders];

		for (int i = 0; i < this->totalOrders; i++) {
			cout << "Order number " << i + 1 << ":\n";
			this->iceCream[i].receiveOrder();
		}
	}

	/////////////////////// UTILITES ///////////////////////////

	// set all members variables to nullptr or 0;
	void Vendor::setEmpty(void) {
		this->iceCream = nullptr;
		this->totalOrders = 0;
	}

	// free mem
	void Vendor::clearData() {
		if (this->iceCream != nullptr) {
			delete[] this->iceCream;
			this->iceCream = nullptr;
		}
	}

	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////

}
