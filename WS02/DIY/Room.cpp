#include "Room.h"

namespace seneca {

	void vacate(Room& room) {
		delete &room.m_noOfGuests;
		delete[] room.m_roomNumber;
		delete &room.m_guests->m_adult;
		delete[] room.m_guests->m_firstName;
		delete[] room.m_guests->m_lastName;
		delete &room;
	}

	void set(Room& room, int numberOfGuests, const char* roomNumber) {
		if (room.m_guests != NULL || numberOfGuests <= 0 || strcmp(roomNumber, " ")) {
			room.m_guests = new Guest[numberOfGuests];
			strcpy(room.m_roomNumber, roomNumber);
		}
	}
	void book(Room& room) {
		// receive roomNumber and number of guest so after we can allocate memory with these data
		cin >> room.m_roomNumber;
		cin >> room.m_noOfGuests;
		// allocate dynamically memory for Guest's array
		set(room, room.m_noOfGuests, room.m_roomNumber);

		// assign data for each guest
		for (int i = 0; i < room.m_noOfGuests; i++) {

			// we can use overloading from guest to add guest info
			book(room.m_guests[i]);
		}
	}
	void print(const Room& room) {

	}
}