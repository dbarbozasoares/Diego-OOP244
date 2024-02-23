#define _CRT_SECURE_NO_WARNINGS
#include "Hero.h"

namespace seneca {

	// default constructor
	Hero::Hero(void) {
		this->heroPowers = nullptr;
		this->totalHeroPowers = 0;
		this->powerHeroLevel = 0;
		this->hero_name[0] = '\0';
	}

	// overload constructor
	Hero::Hero(const char* heroName, Power* heroPowers, int totalHeroPowers) {
		*this = Hero(); // set current object to a safe empty state before assign members data
		strcpy(this->hero_name, heroName);
		this->totalHeroPowers = totalHeroPowers;
		// allocate memory dynamically
		this->heroPowers = new Power[totalHeroPowers];
		// set each power for the Hero from powers array parameter
		for (int i = 0; i < totalHeroPowers; i++) {
			this->heroPowers[i] = heroPowers[i];
			this->powerHeroLevel += this->heroPowers[i].checkRarity(); // sum of rarity of all powers multiplied by the total count of powers
		}
		this->powerHeroLevel *= totalHeroPowers;
	}

	// destructor
	Hero::~Hero() {

		delete[] this->heroPowers;
		this->heroPowers = nullptr;
		
	}

	// display hero's information (name, list of super powers and power level)
	std::ostream& Hero::display(std::ostream& os) const {
		os << "Name: " << this->hero_name << std::endl;
		os << "List of available powers: " << std::endl;
		for (int i = 0; i < this->totalHeroPowers; i++) {
			os << "  Name: " << this->heroPowers[i].checkName() << ", Rarity: " << this->heroPowers[i].checkRarity() << std::endl;
		}
		os << "Power Level: " << this->powerHeroLevel;
		return os;
	}

	// add new super power into current's hero powers array
	void Hero::operator+=(Power& newPower)
	{
		this->totalHeroPowers++; // increase +1 in total hero powers
		Power* tmpArr = new Power[this->totalHeroPowers]; // create a temporary array with new heroPowers size
			for (int i = 0; i < this->totalHeroPowers - 1; i++) { // copy each member from hero powers to temporary array ( -1 because the last index is the new power we're adding)
				tmpArr[i] = heroPowers[i];
			}
		tmpArr[totalHeroPowers - 1] = newPower; // assign new power to last temporary array position
		delete[] this->heroPowers; // deallocate old memory
		this->heroPowers= tmpArr; // points heroPowers array to the same block of memory as tempArr with new size
		this->powerHeroLevel = updatePowerLevel(newPower.checkRarity()); // update hero power level based on new power rarity
		
	}

	// reduce hero's power level by paramenter's value
	void Hero::operator-=(int powerAmount) {
		this->powerHeroLevel -= powerAmount;
	}

	//////////////////////////////////////////////////////////////
	/////////////////// MEMBER HELPER FUNCTIONS //////////////////

	// return power level of current's hero
	int Hero::getPowerLevel() const {
		return this->powerHeroLevel;
	}

	// update current's hero power level based on new power rarity
	int Hero::updatePowerLevel(int newRarity) {
		int newPower = newRarity;
		for (int i = 0; i < this->totalHeroPowers - 1; i++) { // since we are adding a new power, we dont have to check the last position since its gonna be the current one
			newPower += this->heroPowers[i].checkRarity();
		}
		newPower *= this->totalHeroPowers;
		return newPower;
	}
	
	//////////////////////////////////////////////////////////////
	////////////////// HELPER FUNCTIONS //////////////////////////
	
	// compares if hero 1 power level is less than hero 2 power level
	bool operator<(Hero& hero1, Hero& hero2) {
		return hero1.getPowerLevel() < hero2.getPowerLevel();
	}

	// compare if hero 1 power level is greater than hero 2 power level
	bool operator>(Hero& hero1, Hero& hero2) {
		return !(hero1 < hero2);
	}

	// assign new power into hero super powers ( call operator overload += )
	void operator>>(Power& power, Hero& hero) {
		hero += power;
	}

	// assign new power into hero super powers ( call operator overload += )
	void operator<<(Hero& hero, Power& power) {
		hero += power;
	}
	
}