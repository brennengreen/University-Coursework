
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
	string prod_code; // product code: length 12, no spaces
	string description; // product description: max length 28, has spaces
	double price; // price of the product, max 999.99
};

struct order {
	long orderNumber; // unique order number for this order
	string cust_name;
	double total_price;
	item items[MAX_ORDER_ITEMS];
	int num_items;
};

//----------------------------------------------------------------------------
//                                  readInventory
//----------------------------------------------------------------------------
// Modifies: inventory list (sets numberOfItems to -1 on READ ERROR)
//           lastOrderNum
// Reads inventory data from a file into an array of inventory items
//----------------------------------------------------------------------------
void read_inventory(item inv[], int & numberOfInvItems, int & lastOrderNum) {
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
		f >> inv[i].prod_code >> inv[i].price;
		f.ignore(); // finished reading integer, getline() on string is next
		getline(f, inv[i].description);
	}
	f.close();
} // readInventory()

bool is_valid_option(char option, string, string valid_options) {

}

string get_main_options() {
	return "IOLX";
}

void display_list(item inventor[]) {
	// Display inventory
}

void display_inventory(item inventory[]) {
	// Display inventory
}

void display_order(order order[]) {

}

void start_order() {

}

bool order_item() {

}

void make_order(item inventory[]) {

}

void list_orders(order orders[]) {

}

void write_orders(order orders[]) {

}

int main() {



	return 0;
}