#ifndef VENDOR_H
#define VENDOR_H
#include "IceCream.h"

namespace seneca {
	class Vendor {
		IceCream* iceCream;
		int totalOrders;

	public:
		void setEmpty(void);
		void takeOrders(void);
		void displayOrders(void);
		void clearData(void);
		void printIceCream(void);
	};
}

#endif