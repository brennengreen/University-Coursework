
//--------------------------------------------------------------------------
//							CS215-003 PROJECT TWO																				
//--------------------------------------------------------------------------
// Author: Brennen Green
// Date: 10/07/2019
// Description:	An amazon-like sales point system that tracks inventory
// Assistance: I received help from no one.
//--------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// CONSTANTS //
const int MAX_ORDER_ITEMS = 5; // Maximum number of items per order
const int MAX_NUM_ORDERS = 5; //  Maximum possible number of orders for one day
const int READ_ERROR = -1; // Signifies that an error has occured opening the file
const int MAX_INV_ITEMS = 10; // Maximum number of items in the stores inventory
const int NUM_OPTIONS = 4; // Number of options in the main menu
const string VALID_OPTIONS = "IOLX"; // All possible character options on main menu 
const char INV_CHAR = 'I'; // Character option that will list inventory
const char ORDER_CHAR = 'O'; // Character option to create a new order
const char LIST_CHAR = 'L'; // Character option to list all orders
const char EXIT_CHAR = 'X'; // Character option to exit program
const int END_ORDER_IDENTIFIER = -1; // Character option to quit ordering items
const string OUT_FILE_NAME = "orders.txt"; // File to output orders to
const string IN_FILE_NAME = "inventory.txt"; // File to read inventory from


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
	f.open(IN_FILE_NAME);
	if (f.fail()) {
		cout << "readFile: error opening inventory.txt\n";
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
		if (cin.peek() == '\n') cin.ignore();
		getline(cin, userOption);
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
// Given: An partial inventory array (could be a basket or inventory), and the size of
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
	cout << "Total              $" << setw(6) << right << thisOrder.totalPrice << endl;
	cout << endl;
}

//----------------------------------------------------------------------------
//                                  startOrder
//----------------------------------------------------------------------------
// Modifies: partial array of Orders(baskets), lastOrderNumber
// Initializes the basket for the next available order and gathers the 
// users name for the order
//----------------------------------------------------------------------------
void startOrder(order orders[], int& numOrders, int& lastOrderNum) {
	order newOrder;
	newOrder.orderNumber = ++lastOrderNum;
	newOrder.numItems = 0;
	newOrder.totalPrice = 0;
	cout << "Order Number:        " << newOrder.orderNumber << endl;
	cout << "Enter customer name: ";
	getline(cin, newOrder.custName);
	orders[numOrders] = newOrder;
	numOrders++;
}

//----------------------------------------------------------------------------
//                                  orderItem
//----------------------------------------------------------------------------
// Given: A partial inventory array
// Modifies: A single basket
// Returns: true or false
// Handles ordering a single item in a basket
//----------------------------------------------------------------------------
bool orderItem(item inventory[], int numItems, order orders[], int numOrders) {
	order& thisOrder = orders[numOrders-1];

	int userResponse = -999;
	while (userResponse < -1 || userResponse >= numItems) {
		cout << endl;
		cout << "Enter an item number (-1 to " << numItems-1 << "): ";
		cin >> userResponse;
		if (userResponse < -1 || userResponse >= numItems) {
			cout << "Invailid entry. Enter number -1 to " << numItems << endl;
		}
	}
	if (userResponse == END_ORDER_IDENTIFIER) {
		return true;
	}
	if (thisOrder.numItems >= MAX_ORDER_ITEMS) {
		cout << "Sorry, the max number of items per order is " << MAX_ORDER_ITEMS << endl;
		return true;
	}
	item chosenItem = inventory[userResponse];
	item newItem;
	newItem.description = chosenItem.description;
	newItem.prodCode = chosenItem.prodCode;
	newItem.price = chosenItem.price;

	thisOrder.items[thisOrder.numItems] = newItem;
	thisOrder.numItems++;
	thisOrder.totalPrice = thisOrder.totalPrice + newItem.price;

	cout << newItem.description << " added to your basket. " << "Current total is $" << thisOrder.totalPrice << endl;

	return false;
} // orderItem()

//----------------------------------------------------------------------------
//                                  makeOrder
//----------------------------------------------------------------------------
// Given: Inventory partial array
// Controls the main processing flow of the make order functionallity of the 
// program, gets information from the user then appends a new order to the
// orders array
//----------------------------------------------------------------------------
void makeOrder(item inventory[], order orders[], int& numOrders, int numItems, int& lastOrderNum) {
	if (numOrders == MAX_NUM_ORDERS) {
		cout << "Sorry, we can't take more orders today." << endl;
	}
	else {
		order& thisOrder = orders[numOrders];
		startOrder(orders, numOrders, lastOrderNum);
		displayInventory(inventory, numItems);
		bool identifier = false;
		while (!identifier) {
			identifier = orderItem(inventory, numItems, orders, numOrders);
		}
		cout << "Thank you for your order!" << endl;
		displayOrder(thisOrder);
	}
	system("pause");
}
//----------------------------------------------------------------------------
//                                  listOrders
//----------------------------------------------------------------------------
// Given: Inventory partial array
// Prints the orders logo and invokes displayOrder for every order in the
// partial array
//----------------------------------------------------------------------------
void listOrders(order orders[], int numOrders) {
	cout << "+--------------------------------------------------------------+\n";
	cout << "-                            ORDERS                            -\n";
	cout << "+--------------------------------------------------------------+\n";
	for (int i = 0; i < numOrders; ++i) {
		displayOrder(orders[i]);
	}
	cout << "Total Number of Orders = " << numOrders << endl;
	cout << endl;
}
//----------------------------------------------------------------------------
//                                  writeOrders
//----------------------------------------------------------------------------
// Given: Inventory partial array
// Opens the orders.txt file for writing, ensures the file opened properly,
// then writes the current orders to the file
//----------------------------------------------------------------------------
void writeOrders(order orders[], int numOrders) {
	ofstream fout(OUT_FILE_NAME);
	if (fout.fail()) {
		cout << "Failed to open file " << OUT_FILE_NAME << endl;
		return;
	}
	fout << numOrders << endl;
	order currOrder;
	for (int i = 0; i < numOrders; ++i) {
		currOrder = orders[i];
		fout << currOrder.orderNumber << " " << currOrder.numItems << " " << currOrder.totalPrice << " " << currOrder.custName << endl;
		item currItem;
		for (int j = 0; j < currOrder.numItems; ++j) {
			currItem = currOrder.items[j];
			fout << currItem.prodCode << " " << currItem.price << " " << currItem.description << endl;
		}
	}
}


//----------------------------------------------------------------------------
//                                  main
//----------------------------------------------------------------------------
// Returns: 0
// Main is used to declare the inventory and orders partial array and as well
// used to control the main processing flow of the program invoke several
// important function calls
//----------------------------------------------------------------------------
int main() {
	// Declaring partial array for the current inventory items and orders
	item inventory[MAX_INV_ITEMS];
	order orders[MAX_NUM_ORDERS];
	int numInvItems = 0;
	int numOrders = 0;
	int lastOrderNum = 0; // The order number of the very last order
	int isExiting = 0; // 1 to signal program to exit

	// Read the inventory from input file
	readInventory(inventory, numInvItems, lastOrderNum);
	char userChoice; // User main menu option
	// While the user has not selected to quit the program, keep prompting the menu
	while (isExiting != 1) {
		userChoice = getMainOption();
		cout << endl;
		switch (userChoice) {
			case INV_CHAR:
				displayInventory(inventory, numInvItems);
				break;
			case ORDER_CHAR:
				makeOrder(inventory, orders, numOrders, numInvItems, lastOrderNum);
				break;
			case LIST_CHAR:
				listOrders(orders, numOrders);
				break;
			case EXIT_CHAR:
				writeOrders(orders, numOrders);
				isExiting = 1;
				break;
			default:
				break;
		}
	} // isExiting != 1

	system("pause");
	return 0;
}