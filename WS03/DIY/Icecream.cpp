// Student's name: Diego B Soares
// ID number: 145820239
// 02/08/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "Icecream.h"
#include "Vendor.h"

namespace seneca {

	//////////////////// CONSTRUCTORS ////////////////////////////////

	// default constructor
	IceCream::IceCream() {
		this->extraVanillaWaffer = '\0';
		this->priceByScoop = PRICE_BY_SCOOP;
		this->totalOrder = 0;
		this->flavour = 0;
		this->totalScoops = 0;
		this->flavourName[0] = " ";
		this->flavourName[1] = "Chocolate";
		this->flavourName[2] = "Strawberry";
		this->flavourName[3] = "Mango";
		this->flavourName[4] = "Tutti fruit";
		this->flavourName[5] = "Almond crunch";
	}

	//////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////
	//////////////////// GET FUNCTIONS ///////////////////////////////
	
	// return total $ for the order
	double IceCream::getTotalOrder() {
		return this->totalOrder;
	}

	// return how many scoop user chose
	int IceCream::getTotalScoop(void) {
		return this->totalScoops;
	}

	// return if user opted for extra wafle
	bool IceCream::getVanillaOpt() {
		return this->extraVanillaWaffer;
	}

	// returns flavour name by index as parameter
	const char* IceCream::getFlavourName(int index) {
		return this->flavourName[index];
	}

	// return flavour number so we can print after flavour name calling by index
	int IceCream::getFlavour(void) {
		return this->flavour;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////// INPUT OUTPUT ////////////////////////////////////

	// call option functions  waffle, scoops and flavour
	void IceCream::receiveOrder(void) {
		IceCream tmp;
		cout << "Select flavour:\n" << "----------------\n" << "1: Chocolate\n" << "2: Strawberry\n" << "3: Mango\n" << "4: Tutti fruit\n" << "5: Almond crunch\n" << "----------------\n" << "> ";
		this->flavour = receiveFlavour();
		this->totalScoops = receiveScoopUser();
		this->extraVanillaWaffer = receiveWafferOpt();
	}

	// ask user how many scoops
	int IceCream::receiveScoopUser(void) {
		int tmpScoop = 0;
		cout << "Number of Scoops (max " << MAX_SCOOPS << ")\n" << "> ";
		do {
			cin >> tmpScoop;
			if (cin.fail()) {
				cout << "Invalid entry, retry" << endl << "> ";
				cin.clear();
				while (cin.get() != '\n') {}
			}
			else if (tmpScoop < 1 || tmpScoop > MAX_SCOOPS) {
				cout << "Invlid value(" << 1 << "<=val<=" << MAX_SCOOPS << ")" << endl << "> ";
			}
		} while (tmpScoop < 1 || tmpScoop > MAX_SCOOPS || isalpha(tmpScoop));
		return tmpScoop;

	}

	// ask user what flavour by number
	int IceCream::receiveFlavour(void) {
		int iceCreamFlavour = 0;
		do {
			cin >> iceCreamFlavour;
			if (cin.fail()) {
				cout << "Invalid entry, retry" << endl << "> ";
				cin.clear();
				while (cin.get() != '\n') {}
			}
			else if (iceCreamFlavour < 1 || iceCreamFlavour > MAX_FLAVOURS) {
				cout << "Invlid value(" << 1 << "<=val<=" << MAX_FLAVOURS << ")" << endl << "> ";
			}
		} while (iceCreamFlavour < 1 || iceCreamFlavour > 5);
		return iceCreamFlavour;
	}

	// print order for 1 icecream
	void IceCream::printOrder(void) {
		double scoop = 0, chocolate = 0, total = 0, vanilla = 0;
		total = calculateTotal(&scoop, &chocolate, &vanilla);
		cout << "Number of scoops, " << this->getTotalScoop() << " total:";
		cout.width(9);
		cout << fixed << setprecision(2) << scoop << endl;

		if (this->getFlavour() == 1) {
			cout << this->getFlavourName(this->getFlavour()) << " flavour:";
			cout.width(17);
			cout << chocolate << endl;
		}
		else {
			cout << this->getFlavourName(this->getFlavour()) << " flavour\n";
		}

		cout << "Vanilla Wafer:";
		cout.width(21);
		cout << vanilla << endl;

		cout << "Price:";
		cout.width(29);
		cout << total;
		cout << "\n";
	}

	// ask user if want vanilla wafer
	bool IceCream::receiveWafferOpt(void) {
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
				cout << "Only Y or N are acceptable:\n" << "> ";
				charChecker = false;
			}
		} while (charChecker == false);

		// if char receives y, waffer returns true
		if (*tmpChar == 'y') {
			checkWaffer = true;
		}
		return checkWaffer;
	}

	//////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	////////////////////// UTILITIES ///////////////////////////////
	
	// calcualte total for each icecream and assign local variables so we can print it out based on icecream option
	int IceCream::calculateTotal(double* scoop, double* chocolate, double* vanilla) {
		*scoop = this->getTotalScoop() * PRICE_BY_SCOOP;
		*chocolate = this->getFlavour() == 1 ? PRICE_EXTRA_SCOOP_CHOCOLATE * (this->getTotalScoop()) : 0;
		*vanilla = this->getVanillaOpt() == true ? PRICE_VANILLA_WAFFER_EXTRA : 0;
		this->totalOrder = *chocolate + *scoop + *vanilla;

		return *chocolate + *scoop + *vanilla;
	}

	///////////////////////////////////////////////////////////////


	

	
	

	

	

	

	

	

	

	
}