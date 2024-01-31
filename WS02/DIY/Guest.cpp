#define CRT_SECURE_NO_WARNINGS
#include "Guest.h"

namespace seneca {

	void set(Guest& guest, const char* first, const char* last, int age) {
		if ((first != nullptr && strcmp(first, "") != 0) && (last != nullptr && strcmp(last , "") != 0) && age != 0) {
			guest.m_firstName = new char[strlen(first) + 1];
			strcpy_s(guest.m_firstName, strlen(first) + 1, first);
			guest.m_lastName = new char[strlen(last) + 1];
			strcpy_s(guest.m_lastName, strlen(last) + 1, last);
			guest.m_adult = age >= 18;
		}
		else {
			// doing this we can check on print() function if first name or last name is a nullptr
			guest.m_firstName = NULL;
			guest.m_lastName = NULL;
		}
	}

	void print(const Guest& guest) {
		if (guest.m_firstName == NULL || guest.m_lastName == NULL) {
			cout << "Vacated\n";
		}
		else {
			cout << guest.m_firstName << " " << guest.m_lastName << (guest.m_adult ? "(Child)" : "") << "\n";
		} 
	}

	void book(Guest& guest) {

		int tmpAge = 0;
		char tmpName[50];
		char tmpLast[50];
		// receive input for guest data
		cout << "Name: ";
		cin >> tmpName;

		cout << "Lastname: ";
		cin >> tmpLast;

		cout << "Age: ";
		cin >> tmpAge;
		
		// set new Guest with user input Note: Validations on set()
		set(guest, tmpName, tmpLast, tmpAge);
	}

	void vacate(Guest& guest) {
		delete[] guest.m_firstName;
		delete[] guest.m_lastName;
		
		// setting to nullptr so we can make sure while printing
		guest.m_firstName = nullptr;
		guest.m_lastName = nullptr;
	}
}