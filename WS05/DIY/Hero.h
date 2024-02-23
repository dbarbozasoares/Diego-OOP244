// Student's name: Diego B Soares
// ID number: 145820239
// 02/22/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef HERO_H
#define HERO_H
#define MAX_NAME_LEN 20
#include "Power.h"
#include <iostream>
#include <string.h>
namespace seneca {
	class Hero {
		char hero_name[MAX_NAME_LEN + 1];
		Power* heroPowers;
		int totalHeroPowers;
		int powerHeroLevel; // sum of rarity of all powers multiplied by the total count of powers

	public:
		//default constructor, set to a safe empty state
		Hero(void);

		//overloaded constructor, while assigning new values, update hero power level as well based on heroPowers rarity and totalHeroPowers
		Hero(const char* heroName, Power* heroPowers, int totalHeroPowers);

		//destructor
		~Hero();

		//overload output so we can print hero's information
		std::ostream& display(std::ostream& os = std::cout) const;

		//@param New power object to be added into hero's powers array
		//@brief Allocate a new space of memory and insert newPower into array, call updatePowerLevel() to updated hero's power level
		void operator+=(Power& newPower);

		//@param Power to be subtracted from hero's powerLevel
		//@brief Subtract the parameter's value from hero's power level
		void operator-=(int powerAmount);

		//@param Value to be updated on hero power level
		//@return New power level updated
		//@brief Goes trough current power array, sum all power rarity, add newRarity into this sum and multiplies by totalHeroPowers
		int updatePowerLevel(int newRarity);

		//@return Return hero's powerLevel
		int getPowerLevel() const;

		// assign new power into hero super powers ( call operator overload += )
		friend void operator>>(Power& power, Hero& hero);

		// assign new power into hero super powers ( call operator overload += )
		friend void operator<<(Hero& hero, Power& power);

	};
	// compares if hero 1 power level is less than hero 2 power level
	bool operator<(Hero& hero1, Hero& hero2);

	// compare if hero 1 power level is greater than hero 2 power level
	bool operator>(Hero& hero1, Hero& hero2);
}
#endif