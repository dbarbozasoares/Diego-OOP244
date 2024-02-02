// Student's name: Diego B Soares
// ID number: 145820239
// 02/01/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Workshop 3 part 2

#define _CRT_SECURE_NO_WARNINGS
#include "Guest.h"

namespace seneca {

	void set(Guest& guest, const char* first, const char* last, int age) {

		//make sure first and last names are ready to receive new values
		guest.m_firstName = nullptr;
		guest.m_lastName = nullptr;

		if ((first != nullptr && strcmp(first, "") != 0) && (last != nullptr && strcmp(last, "") != 0) && (age != 0)) {
			delete[] guest.m_firstName;
			guest.m_firstName = new char[strlen(first) + 1];
			strcpy(guest.m_firstName, first);
			delete[] guest.m_lastName;
			guest.m_lastName = new char[strlen(last) + 1];
			strcpy(guest.m_lastName, last);
			guest.m_adult = age >= 18;
		}
	}

	void print(const Guest& guest) {
		if (guest.m_firstName == nullptr || guest.m_lastName == nullptr) {
			cout << "Vacated!\n";
		}
		else{
			cout << guest.m_firstName << " " << guest.m_lastName << (guest.m_adult ? "" : "(Child)") << "\n";
		} 
	}

	void book(Guest& guest) {

		// vacates previous guest. Note:  vacate checks if guest is already empty
		vacate(guest);

		int tmpAge;
		char tmpF[MAX_NAME];
		char tmpL[MAX_NAME];

		// receive input for guest data
		cout << "Name: ";
		cin >> tmpF;
		cout << "Lastname: ";
		cin >> tmpL;
		cout << "Age: ";
		cin >> tmpAge;
		
		// set new Guest with user input Note: Validations on set()
		set(guest, tmpF, tmpL, tmpAge);

	}

	void vacate(Guest& guest) {
		
		if (guest.m_firstName != nullptr) {
			delete[] guest.m_firstName;
			guest.m_firstName = nullptr;// setting to nullptr so we can make sure while printing
		}
		if (guest.m_lastName != nullptr) {
			delete[] guest.m_lastName;
			guest.m_lastName = nullptr;// setting to nullptr so we can make sure while printing
		}
	}
}