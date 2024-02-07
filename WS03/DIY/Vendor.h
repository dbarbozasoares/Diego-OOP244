#ifndef VENDOR_H
#define VENDOR_H
#include "Icecream.h"

namespace seneca {
	class Vendor {
		IceCream* iceCream;
		int totalOrders;

	public:
		void setEmpty(void);
		void takeOrders(void);
		void displayOrders();
		void clearData();
		void printIceCream(void);
		int calculateTotal(Vendor, double, double, double);
	};
}

#endif