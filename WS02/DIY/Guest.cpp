#include "Guest.h"

namespace seneca {

	void set(Guest& guest, const char* first, const char* last, int age) {
		if (first != nullptr || first != " " || last == " " || &guest != NULL || age != NULL) {
			cout << "Vacated";
		}
		else {
			guest.m_firstName = new char[strlen(first) + 1];
			guest.m_lastName = new char[strlen(last) + 1];
			guest.m_adult = age >= 18 ? true : false;
		}
	}

	void print(const Guest& guest) {
		cout << guest.m_firstName << " " << guest.m_lastName << guest.m_adult ? "(Child)" : "";
	}

	void book(Guest& guest) {

		// receive input for guest data
		int tmpAge = 0;
		cout << "Name: ";
		cin >> guest.m_firstName;

		cout << "Lastname: ";
		cin >> guest.m_lastName;

		cout << "Age: ";
		cin >> tmpAge;
		
		// set new Guest with user input Note: Validations on set()
		set(guest, guest.m_firstName, guest.m_lastName, tmpAge);
	}

	void vacate(Guest& guest) {
		delete& guest.m_adult;
		delete[] guest.m_firstName;
		delete[] guest.m_lastName;
		delete &guest;
	}
}