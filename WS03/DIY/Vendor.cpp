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
		this->iceCream = new IceCream[totalOrders];
		
		for (int i = 0; i < totalOrders; i++) {
			cout << "Order number " << i+1 << ":";
			this->iceCream[i].getFlavour();
		}
	}
	void Vendor::displayOrders(void) {
		double scoop = 0, chocolate = 0, total = 0, vanilla = 0;
		total = calculateTotal((*this), scoop, chocolate, vanilla);
		cout << "\n";
		cout << "********** Order Summary **********";
		for (int i = 0; i < this->totalOrders; i++) {
			cout << "Order number " << i + 1 << ":";
			cout << "Order details:" << "               Price" << endl;
			cout << "-----------------------------------";

			cout << "Number of scoops, " << this->iceCream[i].getTotalScoop() << " total:";
			cout.width(4);
			cout << scoop << endl;

			cout << "Chocolate flavour:";
			cout.width(13);
			cout << chocolate << endl;

			cout << "Vanilla Wafer:";
			cout.width(17);
			cout << vanilla << endl;

			cout << "Price:";	
			cout.width(24);
			cout << total;
			cout << "\n\n";

		}
	}
	int Vendor::calculateTotal(Vendor v, double scoop, double chocolate, double vanilla) {
		scoop = v.iceCream->getTotalScoop() * PRICE_BY_SCOOP;
		chocolate = v.iceCream->getFlavour() == 1 ? PRICE_EXTRA_SCOOP_CHOCOLATE * (v.iceCream->getTotalScoop()) : 0;
		vanilla = v.iceCream->getVanillaOpt() == true ? PRICE_VANILLA_WAFFER_EXTRA : 0;

		return chocolate + scoop;
	}
	void Vendor::clearData() {
		if (this->iceCream != nullptr) {
			delete[] this->iceCream;
			this->iceCream = nullptr;
		}
	}

}
