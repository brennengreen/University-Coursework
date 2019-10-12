
//--------------------------------------------------------------------------
//							CS215-003 PROJECT TWO																				
//--------------------------------------------------------------------------
// Author: Brennen Green
// Date: 10/07/2019
// Description:	An amazon-like sales point system tht tracks inventory
// Assistance: I received help from no one.
//--------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
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
const int END_ORDER_IDENTIFIER = -1;


struct item {
	string prodCode; // product code: length 12, no spaces
	string description; // product description: max length 28, has spaces
	double price; // price of the product, max 999.99
};

struct order {
	long orderNumber; // unique order number for this order
	string custName; // The identifier for the customer who made the order
	double totalPrice; // The total price of the order
	item items[MAX_ORDER_ITEMS]; // An array of the items in the order
	int numItems; // the number of items in the order
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

//----------------------------------------------------------------------------
//                                  isValidOption
//----------------------------------------------------------------------------
// Given: An option char, a string of valid options
// Returns: true or false
// Validates input based on a set of valid characters
//----------------------------------------------------------------------------
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
// Outputs a main menu to the user and passes the valid character chosen
// along to the program
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
} // getMainOption()

//----------------------------------------------------------------------------
//                                  displayList
//----------------------------------------------------------------------------
// Given: An inventory (could be a basket or inventory), and the size of
// the array given
// Outputs the items in an inventory to the user 
//----------------------------------------------------------------------------
void displayList(item inventory[], int sizeInventory) {
	// Display inventory
	for (int i = 0; i < sizeInventory; ++i) {
		item currItem = inventory[i];
		cout << right << setw(3) << i << "  " << setw(12) << currItem.prodCode << "  $" << right << setw(6) << fixed << setprecision(2) << currItem.price << "  " << left << currItem.description << endl;
	}
}

//----------------------------------------------------------------------------
//                                  displayInventory
//----------------------------------------------------------------------------
// Returns:An inventory (could be a basket or inventory), and the size of
// the array given
// Displays the products header menu then invokes displayList w/ an inventory
//----------------------------------------------------------------------------
void displayInventory(item inventory[], int inventorySize) {
	cout << "+-------------------------------------------------------------------+" << endl;
	cout << "|                             PRODUCTS                              |" << endl;
	cout << "+-------------------------------------------------------------------+" << endl;
	cout << " #   PRODUCT CODE   PRICE   PRODUCT DESCRIPTION                      " << endl;
	cout << "---  ------------  -------  -----------------------------------------" << endl;
	displayList(inventory, inventorySize);
	cout << "Number of items in inventory: " << inventorySize << endl;
}
//----------------------------------------------------------------------------
//                                  displayOrder
//----------------------------------------------------------------------------
// Given: A single order
// Displays the order header and important information and invokes displayList
// with the basket from the given order
//----------------------------------------------------------------------------
void displayOrder(order thisOrder) {
	cout << "ORDER: " << thisOrder.orderNumber << "   " << thisOrder.custName << endl;
	displayList(thisOrder.items, thisOrder.numItems);
	cout << "Total              $" << setw(6) << right << thisOrder.totalPrice;
}

//----------------------------------------------------------------------------
//                                  startOrder
//----------------------------------------------------------------------------
// Modifies: Orders(baskets), lastOrderNumber
// TODO
//----------------------------------------------------------------------------
void startOrder() {



}

//----------------------------------------------------------------------------
//                                  orderItem
//----------------------------------------------------------------------------
// Given: A partial inventory array
// Modifies: A single basket
// Returns: true or false
// Handles ordering a single item in a basket
//----------------------------------------------------------------------------
bool orderItem(item inventory) {
	return true;
}

//----------------------------------------------------------------------------
//                                  makeOrder
//----------------------------------------------------------------------------
// Given: Inventory partial array
// Modifies: Orders Partial Array, lastOrderNumber
// TODO
//----------------------------------------------------------------------------
void makeOrder(item inventory[], int& lastOrderNum) {

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

	readInventory(inventory, numInvItems, lastOrderNum);
	char userChoice = getMainOption();

	switch (userChoice) {
		case INV_CHAR:
			displayInventory(inventory, numInvItems);
			break;
		case ORDER_CHAR:
			makeOrder(inventory, lastOrderNum);
			break;
		case LIST_CHAR:
			break;
		case EXIT_CHAR:
			writeOrders(orders);
			break;
		default:
			break;
	}

	system("pause");
	return 0;
}