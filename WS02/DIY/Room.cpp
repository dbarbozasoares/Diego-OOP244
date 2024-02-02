// Student's name: Diego B Soares
// ID number: 145820239
// 02/01/2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Workshop 3 part 2

#define _CRT_SECURE_NO_WARNINGS
#include "Room.h"

namespace seneca {

	
	void vacate(Room& room) {
		for (int i = 0; i < room.m_noOfGuests; i++) { // make sure vacates each guest from current room
			vacate(room.m_guests[i]);
		}
		delete[] room.m_guests;
		room.m_guests = nullptr;
		room.m_noOfGuests = 0;
	}

	void set(Room& room, int numberOfGuests, const char* roomNumber) {

		if ((numberOfGuests != 0) && (strcmp(roomNumber, "") != 0)) {
			room.m_noOfGuests = numberOfGuests;
			room.m_guests = new Guest[numberOfGuests];  // Allocate dynamic memory for guest's array
			strcpy(room.m_roomNumber, roomNumber);

			// make sure first and last name are nullptr so we can use to check if empty while printing guest data
			for (int i = 0; i < numberOfGuests; i++) {
				room.m_guests[i].m_firstName = nullptr;
				room.m_guests[i].m_lastName = nullptr;
			}
		}
		else {
			delete[] room.m_guests;  // Deallocate memory if conditions are not met
			room.m_guests = nullptr;
		}
	}
	void book(Room& room) {

		char tmpRoom[MAX_ROOM_GUEST]; // use macro size so if we increase quantity, change just in one place "Room.h"
		int numGuest = 0;

		// receive roomNumber and number of guest so after we can allocate memory with these data
		cout << "Room number: ";
		cin >> tmpRoom;
		cout << "Number of guests: ";
		cin >> numGuest;

		set(room, numGuest, tmpRoom); // allocate dynamically memory for Guest's array

		// vacate each position from guest's array to receive new guests
		for (int i = 0; i < room.m_noOfGuests; i++) {
			vacate(room.m_guests[i]);
		}
		// assign data for each guest
		for (int i = 0; i < numGuest; i++) {
			cout << i + 1 << ":" << endl;
			// we can use overloading from guest to add guest info
			book(room.m_guests[i]);
		}
	
	}
	void print(const Room& room) {
		
		if (room.m_noOfGuests != 0) {
			cout << "Room Number: " << room.m_roomNumber << endl;
			for (int i = 0; i < room.m_noOfGuests; i++) {
				cout << "    ";
					print(room.m_guests[i]); // print function checks if guest is a nullptr
			}
		}
		else {
			cout << "Empty Room!\n";
		}
	}
}