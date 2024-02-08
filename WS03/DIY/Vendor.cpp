#include "Vendor.h"

namespace seneca {

	void Vendor::setEmpty(void) {
		this->iceCream = nullptr;
		this->totalOrders = 0;
	}
	void Vendor::printIceCream(void) {
		cout << "Seneca Icrecream shop" << endl;
		cout.width(7);
		cout << "@" << endl;
		cout.width(9);
		cout << "(' .)" << endl;
		cout.width(10);
		cout << "(*.`. )" << endl;
		cout.width(9);
		cout << "\\###/" << endl;
		cout.width(8);
		cout << "\\#/" << endl;
		cout.width(7);
		cout << "V" << endl;
	}
	void Vendor::takeOrders(void) {
		printIceCream();
		cout << "How many Icecreams?" << endl;
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
			cout << "Order number " << i+1 << ":\n";
			this->iceCream[i].getOrder();
		}
	}
	void Vendor::displayOrders(void) {
		cout << "\n";
		cout << "********** Order Summary **********" << endl;
		for (int i = 0; i < this->totalOrders; i++) {
			cout << "Order no: " << i + 1 << ":" << endl;
			cout << "Order details:" << "               Price" << endl;
			cout << "-----------------------------------" << endl;
			this->iceCream[i].printOrder(); // prints each object
		}
	}
	void Vendor::clearData() {
		if (this->iceCream != nullptr) {
			delete[] this->iceCream;
			this->iceCream = nullptr;
		}
	}

}
