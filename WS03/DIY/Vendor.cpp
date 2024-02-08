#include"Vendor.h"

namespace seneca {

	void Vendor::setEmpty(void) {
		this->iceCream = nullptr;
		this->totalOrders = 0;
	}
	void Vendor::printIceCream(void) {
		cout << "Seneca Icrecream shop" << endl;
		cout.width(10);
		cout << "@" << endl;
		cout.width(9);
		cout << "(' .)" << endl;
		cout.width(8);
		cout << "(' .)" << endl;
		cout << "(*.`. )" << endl;
		cout.width(9);
		cout << "\###/" << endl;
		cout.width(8);
		cout << "\#/" << endl;
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
		double scoop = 0, chocolate = 0, total = 0, vanilla = 0;
		total = calculateTotal((*this), &scoop, &chocolate, &vanilla);
		cout << "\n";
		cout << "********** Order Summary **********" << endl;
		for (int i = 0; i < this->totalOrders; i++) {
			cout << "Order number " << i + 1 << ":" << endl;
			cout << "Order details:" << "               Price" << endl;
			cout << "-----------------------------------" << endl;
			cout.precision(2);
			cout << "Number of scoops, " << this->iceCream[i].getTotalScoop() << " total:";
			cout.width(9);
			cout << scoop << endl;

			cout << this->iceCream[i].getFlavourName(this->iceCream[i].getFlavour()) << " flavour:";
			cout.width(17);
			if (this->iceCream[i].getFlavour() == 1) {
				cout << chocolate << endl;
			}
			else {
				cout << "\n";
			}

			cout << "Vanilla Wafer:";
			cout.width(21);
			cout << vanilla << endl;

			cout << "Price:";	
			cout.width(29);
			cout << total;
			cout << "\n\n";

		}
	}
	int Vendor::calculateTotal(Vendor v, double *scoop, double *chocolate, double *vanilla) {
		*scoop = v.iceCream->getTotalScoop() * PRICE_BY_SCOOP;
		*chocolate = v.iceCream->getFlavour() == 1 ? PRICE_EXTRA_SCOOP_CHOCOLATE * (v.iceCream->getTotalScoop()) : 0;
		*vanilla = v.iceCream->getVanillaOpt() == true ? PRICE_VANILLA_WAFFER_EXTRA : 0;

		return *chocolate + *scoop + *vanilla;
	}
	void Vendor::clearData() {
		if (this->iceCream != nullptr) {
			delete[] this->iceCream;
			this->iceCream = nullptr;
		}
	}

}
