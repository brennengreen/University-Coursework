
//--------------------------------------------------------------------------
//							CS215-003 PROJECT TWO																				
//--------------------------------------------------------------------------
// Author: Brennen Green
// Date: 10/07/2019
// Description:	Simulate a coffee shop experience by running a console
// based machine that tracks coffee sales
// Assistance: I received help from no one.
//--------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// CONSTANTS //
const int MAX_ORDER_ITEMS = 5;
const int READ_ERROR = -1;
const int MAX_INV_ITEMS = 10;


struct item {
	string prodCode; // product code: length 12, no spaces
	string description; // product description: max length 28, has spaces
	double price; // price of the product, max 999.99
};

struct order {
	long orderNumber; // unique order number for this order
	string custName;
	double totalPrice;
	item items[MAX_ORDER_ITEMS];
	int numItems;
};

//----------------------------------------------------------------------------
//                                  readInventory
//----------------------------------------------------------------------------
// Modifies: inventory list (sets numberOfItems to -1 on READ ERROR)
//           lastOrderNum
// Reads inventory data from a file into an array of inventory items
//----------------------------------------------------------------------------
void readInventory(item inv[], int & numberOfInvItems, int & lastOrderNum) {
	ifstream f;

	// open the inventory file
	f.open("inventory.txt");
	if (f.fail()) {
		cout << "readFile:: error opening inventory.txt\n";
		numberOfInvItems = READ_ERROR;
		return;
	}

	// read number of items from first line
	f >> numberOfInvItems >> lastOrderNum;

	// for each item, read the data for the item
	for (int i = 0; i < numberOfInvItems; i++) {
		f >> inv[i].prodCode >> inv[i].price;
		f.ignore(); // finished reading integer, getline() on string is next
		getline(f, inv[i].description);
	}
	f.close();
} // readInventory()

bool isValidOption(char option, string, string validOptions) {

}

string getMainOptions() {
	return "IOLX";
}

void displayList(item inventory[]) {
	// Display inventory
}

void displayInventory(item inventory[]) {
	// Display inventory
}

void displayOrder(order order[]) {

}

void startOrder() {

}

bool orderItem() {

}

void makeOrder(item inventory[]) {

}

void listOrders(order orders[]) {

}

void writeOrders(order orders[]) {

}

int main() {
	cout 


	return 0;
}