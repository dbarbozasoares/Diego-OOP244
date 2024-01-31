#define _CRT_SECURE_NO_WARNINGS
#include "Room.h"

namespace seneca {

	void vacate(Room& room) {

		vacate(*room.m_guests);
		delete[] room.m_roomNumber;
		
	}

	void set(Room& room, int numberOfGuests, const char* roomNumber) {
		if (room.m_guests != nullptr || numberOfGuests != 0 || strcmp(roomNumber, "") != 0) {
			room.m_guests = new Guest[numberOfGuests];
			room.m_noOfGuests = numberOfGuests;
			strcpy(room.m_roomNumber, roomNumber);
		}
		else {
			
		}
	}
	void book(Room& room) {
		
		char tmpRoom[MAX_ROOM_GUEST];
		int tst;
		// receive roomNumber and number of guest so after we can allocate memory with these data
		cout << "Room number: ";
		cin >> tmpRoom;
		cout << "Number of guests: ";
		cin >> tst;
		// allocate dynamically memory for Guest's array
		set(room, tst, tmpRoom);

		// assign data for each guest
		for (int i = 0; i < room.m_noOfGuests; i++) {
			// we can use overloading from guest to add guest info
			book(room.m_guests[i]);
		}
	}
	void print(const Room& room) {
		char tmpRoom[MAX_ROOM_GUEST];

		// get information from user input
		cout << "Room Number: ";
		cin >> tmpRoom;
		

		if (strcmp(tmpRoom, room.m_roomNumber) == 0 && room.m_noOfGuests != 0) {
			// print all guests booked on this room, if empty prints "Vacated"
			for (int i = 0; i < room.m_noOfGuests; i++) {
				cout << "    ";
				if (&room.m_guests[i].m_firstName != nullptr && &room.m_guests[i].m_lastName != nullptr) {
					print(room.m_guests[i]);
				}
				else {
					cout << "Vacated\n";
				}
			}
		}
	}
}