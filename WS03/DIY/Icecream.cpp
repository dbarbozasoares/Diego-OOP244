#include "IceCream.h"

namespace seneca {


	IceCream::IceCream() {
		this->extraVanillaWaffer = '\0';
		this->priceByScoop = PRICE_BY_SCOOP;
		this->flavour = 0;
		this->totalScoops = 0;
		this->flavourName[0] = " ";
		this->flavourName[1] = "Chocolate";
		this->flavourName[2] = "Strawberry";
		this->flavourName[3] = "Mango";
		this->flavourName[4] = "Tutti fruit";
		this->flavourName[5] = "Almond crunch";
	}

	const char* IceCream::getFlavourName(int n) {
		return this->flavourName[n];
	}

	void IceCream::getOrder(void) {
		IceCream tmp;
		cout << "Select flavour : \n" << "----------------\n" << "1: Chocolate\n" << "2: Strawberry\n" << "3: Mango\n" << "4: Tutti fruit\n" << "5: Almond crunch\n" << "----------------\n";
		this->flavour = receiveFlavour();
		this->totalScoops = getScoopUser();
		this->extraVanillaWaffer = checkWaffer();
	}

	int IceCream::getTotalScoop(void) {
		return this->totalScoops;
	}

	int IceCream::getScoopUser(void) {
		int tmpScoop = 0;
		cout << "Number of Scoops (max " << MAX_SCOOPS << ")\n";
		do {
			cin >> tmpScoop;
			if (cin.fail()) {
				cout << "Invalid entry, retry" << endl;
			}
			else if(tmpScoop < 1 || tmpScoop > MAX_SCOOPS){
				cout << "Invlid value(" << 1 << "<= val <= " << MAX_FLAVOURS << ")" << endl;
			}
		} while (tmpScoop < 1 || tmpScoop > MAX_SCOOPS);
		return tmpScoop;
		
	}

	bool IceCream::getVanillaOpt() {
		return this->extraVanillaWaffer;
	}

	bool IceCream::checkWaffer(void) {
		char tmpChar[20];
		char checkerChar[] = "yn";
		bool checkWaffer = false, charChecker = false; // validations helpers

		cout << "Vanilla wafer cone?\n";
		cout << "(Y)es/(N)o > ";
		do {
			cin >> tmpChar;
			*tmpChar = tolower(*tmpChar);
			
			// check if input is one of string checker and length equals 1 that means 1 char
			if (strchr(checkerChar, *tmpChar) && strlen(tmpChar) == 1) {
				charChecker = true;
			}
			else {
				cout << "Only Y or N are acceptable:\n";
				charChecker = false;
			}
		} while (charChecker == false );

		// if char receives y, waffer returns true
		if (*tmpChar == 'y') {
			checkWaffer = true;
		}
		return checkWaffer;
	}

	int IceCream::receiveFlavour(void) {
		int iceCreamFlavour = 0;
		do {
			cin >> iceCreamFlavour;
			if (isalpha(iceCreamFlavour)) {
				cout << "Invalid entry, retry" << endl;
			}
			else if(iceCreamFlavour < 1 || iceCreamFlavour > MAX_FLAVOURS){
				cout << "Invlid value(" << 1 << "<= val <= " << MAX_FLAVOURS << ")" << endl;
			}
		} while (iceCreamFlavour < 1 || iceCreamFlavour > 5);
		return iceCreamFlavour;
	}

	int IceCream::getFlavour(void) {
		return this->flavour;
	}
}