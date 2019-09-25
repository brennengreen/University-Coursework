//--------------------------------------------------------------------------
//							CS215-003 PROJECT ONE																				
//--------------------------------------------------------------------------
// Author: Brennen Green
// Date: 09/20/2019
// Description:	Simulate a coffee shop experience by running a console
// based machine that tracks coffee sales
//--------------------------------------------------------------------------

#include <string>
#include <iostream>
#include <iomanip>
#include "Windows.h"
#include "Math.h"

using namespace std;

// =====================NECESSARY CONSTANTS===========================
	// The amount of time to wait before brewing
const int BREWING_DELAY_MSECONDS = 2000;
// The maximum and minimum amount of ounces allowed in each cup
const int CUP_MAX_OUNCES = 18;
const int CUP_MIN_OUNCES = 9;
const double TAX_RATE = 0.06; // Sales tax rate is 6%
// Cost of each beverage per ounce
const double COST_COFFEE_PER_OZ = 0.15;
const double COST_LATTE_PER_OZ = 0.25;
const double COST_MOCHA_PER_OZ = 0.30;
// The amount of liquid that can be brewed in one dispense sequence
const int MAX_DISPENSE_AMOUNT = 3;
// Beverage Identifiers
const char COFFEE_IDENTIFIER = 'c';
const char LATTE_IDENTIFIER = 'l';
const char MOCHA_IDENTIFIER = 'm';
// Shutdown code
const char SHUTDOWN_IDENTIFIER = '!';

/*======================================
			  is_valid_request
GIVEN:
	string request | the current request from the user
RETURNS:
	true if request is valid, false if not
=======================================*/
bool is_valid_request(string request) {
	char request_letter = tolower(request[0]);
	if (request_letter == 'c' || request_letter == 'm' || request_letter == 'l' || request_letter == '!')
		return true;
	else
		return false;
}

int main() {
	// Variables to maintain machine stats
	int coffee_tank_level, latte_tank_level, mocha_tank_level; // The amount currently in each tank
	int init_coffee_tank_level, init_latte_tank_level, init_mocha_tank_level; // The amount put in the tank at the beginning
	

	// ========================PROGRAM STARTUP=============================
	// Display the authors personal logo and program title
	cout << "---------------------------------" << endl;
	cout << "-          CAFE DU MONDE        -" << endl;
	cout << "-        By: Brennen Green      -" << endl;
	cout << "---------------------------------" << endl;

	cout << endl; // Line for spacing
	
	// Start up the machine and ask the technician for fill levels of each beverage tank
	// Display prompt to user
	cout << "STARTUP: Enter Tank Levels\n";
	cout << "Coffee tank: ";
	cin >> init_coffee_tank_level;
	cout << "Latte tank:  ";
	cin >> init_latte_tank_level;
	cout << "Mocha tank:  ";
	cin >> init_mocha_tank_level;
	cout << endl; // Blank line for spacing

	coffee_tank_level = init_coffee_tank_level; 
	latte_tank_level = init_latte_tank_level;
	mocha_tank_level = init_mocha_tank_level;

	// ======================BEVERAGE SELECTION LOOP======================
	string current_request = "";
	while (current_request[0] != SHUTDOWN_IDENTIFIER) {

		cout << "PLEASE SELECT YOUR BEVERAGE\n";
		// Check if each tank has at minimum the maximum amount for a sale,
		// if a tank doesn't, then don't outpit that option to user
		if (coffee_tank_level >= CUP_MAX_OUNCES) {
			cout << "C. Coffee   $ 0.15 per oz.\n";
		}
		if (latte_tank_level >= CUP_MAX_OUNCES) {
			cout << "L. Latte    $ 0.25 per oz.\n";
		}
		if (mocha_tank_level >= CUP_MAX_OUNCES) {
			cout << "M. Mocha    $ 0.30 per oz.\n";
		}
		cout << "===> ";
		cin >> current_request;

		int beverage_tank_level;
		double cost_of_selection_per_oz;
		string beverage_selection;
		// Determine which tank to check the levels of, set the beverage type, and set the price
		switch (tolower(current_request[0])) {
			case COFFEE_IDENTIFIER:
				beverage_tank_level = coffee_tank_level;
				cost_of_selection_per_oz = COST_COFFEE_PER_OZ;
				beverage_selection = "Coffee";
				break;
			case LATTE_IDENTIFIER:
				beverage_tank_level = latte_tank_level;
				cost_of_selection_per_oz = COST_LATTE_PER_OZ;
				beverage_selection = "Latte";
				break;
			case MOCHA_IDENTIFIER:
				cost_of_selection_per_oz = COST_MOCHA_PER_OZ;
				beverage_tank_level = mocha_tank_level ;
				beverage_selection = "Mocha";
				break;
			case SHUTDOWN_IDENTIFIER:
				beverage_tank_level = 999999; // The machine will shut down and this selection has no tank
				break;
			default:
				break;
		}
		
		// If the user did not input a valid request, keep looping until they do
		while (!is_valid_request(current_request) || beverage_tank_level < 18)
		{
			cout << "Invalid selection! Try again!\n";
			cout << "===> ";
			cin >> current_request;

			// Determine which tank to check the levels of, set the beverage type, and set the price
			switch (tolower(current_request[0])) {
				case COFFEE_IDENTIFIER:
					beverage_tank_level = coffee_tank_level;
					cost_of_selection_per_oz = COST_COFFEE_PER_OZ;
					beverage_selection = "Coffee";
					break;
				case LATTE_IDENTIFIER:
					beverage_tank_level = latte_tank_level;
					cost_of_selection_per_oz = COST_LATTE_PER_OZ;
					beverage_selection = "Latte";
					break;
				case MOCHA_IDENTIFIER:
					cost_of_selection_per_oz = COST_MOCHA_PER_OZ;
					beverage_tank_level = mocha_tank_level;
					beverage_selection = "Mocha";
					break;
				case SHUTDOWN_IDENTIFIER:
					beverage_tank_level = 999999; // The machine will shut down and this selection has no tank
					break;
				default:
					break;
			}
		}

		// If the user entered the shutdown command, display shut down message
		//================== MACHINE PROCESSING / BREWING =================================
		if (current_request[0] == SHUTDOWN_IDENTIFIER) {
			// ====================== BEGIN SHUTDOWN SEQUENCE =============================

			// Compute the totals for each individual beverage
			int coffee_sold_oz = init_coffee_tank_level - coffee_tank_level;
			double coffee_total = coffee_sold_oz * COST_COFFEE_PER_OZ;
			int latte_sold_oz = init_latte_tank_level - latte_tank_level;
			double latte_total = latte_sold_oz * COST_LATTE_PER_OZ;
			int mocha_sold_oz = init_mocha_tank_level - mocha_tank_level;
			double mocha_total = mocha_sold_oz * COST_MOCHA_PER_OZ;
			// Compute the totals for the entire machine
			int ounces_sold = coffee_sold_oz + latte_sold_oz + mocha_sold_oz;
			double total_sale = coffee_total + latte_total + mocha_total;
			
			//=====================FINAL OUTPUT==========================================
			// Output all totals to user
			cout << "SHUTDOWN: Totals Sold:" << endl;
			cout << "BEVERAGE  OUNCES  TOTAL SOLD  LEFT IN TANK" << endl;
			cout << "--------  ------  ----------  ------------" << endl;
			// Display coffee totals
			cout << left << setw(8) << "Coffee" << "  " << right << setw(6) << coffee_sold_oz << "  " <<
				left << "$" << right << setw(8) << fixed << setprecision(2) << coffee_total << "  " << setw(5) << " " << setw(2) << coffee_tank_level << endl;
			// Display latte totals																								   
			cout << left << setw(8) << "Latte" << "  " << right << setw(6) << latte_sold_oz << "  " <<							   
				left << "$" << right << setw(8) << fixed << setprecision(2) << latte_total << "  " << setw(5) << " " << setw(2) << latte_tank_level << endl;
			// Display mocha totals																								   
			cout << left << setw(8) << "Mocha" << "  " << right << setw(6) << mocha_sold_oz << "  " <<							   
				left << "$" << right << setw(8) << fixed << setprecision(2) << mocha_total << "  " << setw(5) << " " << setw(2) << mocha_tank_level << endl;
			// TOTAL Values
			cout << left << setw(8) << "TOTAL" << "  " << right << setw(6) << ounces_sold << "  " <<
				left << "$" << right << setw(8) << fixed << setprecision(2) << total_sale << endl;
		}
		else { // Complete the remainder of the program
			// Prompt the user for the size of cup to brew
			int brew_amount = 0;
			cout << "Number of ounces (9-18): ";
			cin >> brew_amount;
			while (brew_amount < CUP_MIN_OUNCES || brew_amount > CUP_MAX_OUNCES) {
				cout << "Invailid entry!" << endl;
				cout << "Number of ounces (9-18): ";
				cin >> brew_amount;
			}

			// =============== PAYMENT ==================
			// Compute the total cost of the cup then ask the user how muc hthey will pay with
			double sub_total = brew_amount * cost_of_selection_per_oz;
			double tax_total = round((sub_total * TAX_RATE) * 100) / 100;
			double total_price = sub_total + tax_total;
			double amount_paid;
			cout << "Total Price:       $ " << total_price << endl;
			cout << "Enter amount paid: $ ";
			cin >> amount_paid;
			while (amount_paid < total_price) { // Ensure the user paid with enough to afford the cup
				cout << "That is not enough! Please try again." << endl;
				cout << "Enter amount paid: $ ";
				cin >> amount_paid;
			}
			// Display the amount of change the user has received
			double change_amount = amount_paid - total_price;
			cout << "Your change $ " << change_amount << " falls out of the machine on the floor." << endl;
			cout << "Thank you! Your " << beverage_selection << " will now be brewed!" << endl;
			cout << endl; // New line for spacing 
			Sleep(BREWING_DELAY_MSECONDS);
			
			// ========== BEGIN BREWEING ===============
			cout << "A cup drops out of the machine below the " << beverage_selection << " spigot." << endl;
			int amount_brewed = 0;
			while (amount_brewed < brew_amount) {
				if (brew_amount - amount_brewed >= MAX_DISPENSE_AMOUNT)
					amount_brewed = amount_brewed + MAX_DISPENSE_AMOUNT;
				else
					amount_brewed = amount_brewed + (brew_amount - amount_brewed); // Adds the remainder of what's left to brew if less than 3
				cout << setw(2) << amount_brewed << " ounces dispensed..." << endl;
				Sleep(BREWING_DELAY_MSECONDS);
			}
			cout << endl; // Spacing
			// Remove the amount brewed from the correct tank
			switch (tolower(current_request[0])) {
				case 'c':
					coffee_tank_level = coffee_tank_level - amount_brewed;
					break;
				case 'l':
					latte_tank_level = latte_tank_level - amount_brewed;
					break;
				case 'm':
					mocha_tank_level = mocha_tank_level - amount_brewed;
					break;
				default:
					break;
			}
			// =============== DISPLAY RECEIPT =================
			cout << "Your Latte is ready! Here is your receipt!" << endl;
			cout << "Beverage:       " << beverage_selection << endl;
			cout << "Ounces:         " << brew_amount << endl;
			cout << "Price per Oz: $ " << setprecision(2) << fixed << cost_of_selection_per_oz << endl;
			cout << "Sub Total:    $ " << setprecision(2) << fixed << sub_total << endl;
			cout << "Tax:          $ " << setprecision(2) << fixed << tax_total << endl;
			cout << "Total:        $ " << setprecision(2) << fixed << total_price << endl;
			cout << "Amount Paid   $ " << setprecision(2) << fixed << amount_paid << endl;
			cout << "Change:       $ " << setprecision(2) << fixed << change_amount << endl;
			system("pause");
		}
	} // Exits loop if user signaled shutdown

	system("pause");
	return 0;
}

