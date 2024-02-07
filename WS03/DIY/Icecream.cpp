#include "IceCream.h"

namespace seneca {


	IceCream::IceCream() {
		this->extraVanillaWaffer = '\0';
		this->priceByScoop = PRICE_BY_SCOOP;
		this->flavour = 0;
		this->totalScoops = 0;
	}

	IceCream IceCream::getOrder(void) {
		IceCream tmp;
		cout << "Select flavour : " << "----------------" << "1: Chocolate" << "2: Strawberry" << "3: Mango" << "4: Tutti fruit" << "5: Almond crunch" << "----------------";
		tmp.flavour = getFlavour();
		tmp.totalScoops = getTotalScoop();
		tmp.extraVanillaWaffer = checkWaffer();

		return tmp;
	}
	int IceCream::getTotalScoop(void) {
		return this->totalScoops;
	}
	int IceCream::getScoopUser(void) {
		int tmpScoop = 0;
		cout << "Number of Scoops (max " << MAX_SCOOPS << ")";
		do {
			cin >> tmpScoop;
			if (!(isdigit(tmpScoop))) {
				cout << "Invalid entry, retry" << endl;
			}
			else {
				cout << "Invlid value(" << 1 << "<= val <= " << MAX_FLAVOURS << ")" << endl;
			}
		} while (tmpScoop < 1 || tmpScoop > MAX_SCOOPS);
		return tmpScoop;
		
	}
	bool IceCream::getVanillaOpt() {
		return this->extraVanillaWaffer;
	}

	bool IceCream::checkWaffer(void) {
		char tmpChar;
		bool check = false;
		cout << "(Y)es/(N)o > ";
		do {
			cin >> tmpChar;
			if (tmpChar != 'y' && tmpChar != 'n') {
				cout << "Only Y or N are acceptable:";
			}
		} while (tmpChar != 'y' && tmpChar != 'n');
		if (tmpChar == 'y') {
			check = true;
		}
		return check;
	}

	int IceCream::receiveFlavour(void) {
		int iceCreamFlavour = 0;
		do {
			cin >> iceCreamFlavour;
			if (!(isdigit(iceCreamFlavour))) {
				cout << "Invalid entry, retry" << endl;
			}
			else {
				cout << "Invlid value(" << 1 << "<= val <= " << MAX_FLAVOURS << ")" << endl;
			}
		} while (iceCreamFlavour < 1 || iceCreamFlavour > 5);
		return iceCreamFlavour;
	}
	int IceCream::getFlavour(void) {
		return this->flavour;
	}
}