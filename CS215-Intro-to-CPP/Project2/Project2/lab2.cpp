
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
const int NUM_OPTIONS = 4;
const string VALID_OPTIONS = "IOLX";
const char INV_CHAR = 'I';
const char ORDER_CHAR = 'O';
const char LIST_CHAR = 'L';
const char EXIT_CHAR = 'X';


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

bool isValidOption(char option, string validOptions) {
	for (int i = 0; i < NUM_OPTIONS; ++i) {
		if (option == validOptions[i]) {
			return true;
		}
	}
	return false;
}

//----------------------------------------------------------------------------
//                                  getMainOption
//----------------------------------------------------------------------------
// Returns: the main menu option (a char: ’I’, ’O’, ’L’, or ’X’)
//----------------------------------------------------------------------------
char getMainOption() {
	string userOption;
	char optionChar = '!'; // sentinel value
	
	cout << "---------------------------------" << endl;
	cout << "-          AMAZON.COM           -" << endl;
	cout << "-        By: Brennen Green      -" << endl;
	cout << "---------------------------------" << endl;
	cout << "I - List our Inventory" << endl;
	cout << "O - Make an order" << endl;
	cout << "L - List all Orders made" << endl;
	cout << "X - Exit" << endl;

	while (!isValidOption(optionChar, VALID_OPTIONS)) {
		cout << "Enter an option: ";
		cin >> userOption;
		optionChar = toupper(userOption[0]);
		if (!isValidOption(optionChar, VALID_OPTIONS)) {
			cout << "Invalid option, enter I, O, L or X!\n";
		}
	}
	
	return toupper(userOption[0]);
}

void displayList(item inventory[]) {
	// Display inventory
}

void displayInventory(item inventory[]) {
	cout << "+-------------------------------------------------------------------+" << endl;
	cout << "|                             PRODUCTS                              |" << endl;
	cout << "+-------------------------------------------------------------------+" << endl;
	cout << " #   PRODUCT CODE   PRICE   PRODUCT DESCRIPTION                      " << endl;
	cout << "---  ------------  -------  -----------------------------------------" << endl;
	displayList(inventory);
}

void displayOrder(order order[]) {

}

void startOrder() {

}

bool orderItem() {
	return true;
}

void makeOrder(item inventory[]) {

}

void listOrders(order orders[]) {

}

void writeOrders(order orders[]) {

}

int main() {
	item inventory[MAX_INV_ITEMS];
	order orders[MAX_ORDER_ITEMS];
	int lastOrderNum = 0;
	int numInvItems = 0;

	readInventory(inventory, numInvItems, numInvItems);
	char userChoice = getMainOption();

	switch (userChoice) {
		case INV_CHAR:
			displayInventory(inventory);
			break;
		case ORDER_CHAR:
			break;
		case LIST_CHAR:
			break;
		case EXIT_CHAR:
			break;
		default:
			break;
	}

	system("pause");
	return 0;
}