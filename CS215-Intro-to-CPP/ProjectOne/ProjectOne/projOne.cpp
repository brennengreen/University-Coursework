//--------------------------------------------------------------------------
//							CS215-003 PROJECT ONE																				
//--------------------------------------------------------------------------
// Author: Brennen Green
// Date: 09/12/2019
// Description:	TODO
//--------------------------------------------------------------------------

#include <string>
#include <iostream>
#include <iomanip>
#include "Windows.h"
#include "Math.h"


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
// Beverage Identifiers
const char COFFEE_IDENTIFIER = 'c';
const char LATTE_IDENTIFIER = 'l';
const char MOCHA_IDENTIFIER = 'm';
// Shutdown code
const char SHUTDOWN_IDENTIFIER = '!';

/*======================================
			  is_valid_request
GIVEN:
	std::string request | the current request from the user
RETURNS:
	true if request is valid, false if not
=======================================*/
bool is_valid_request(std::string request) {
	char request_letter = tolower(request[0]);
	if (request_letter == 'c' || request_letter == 'm' || request_letter == 'l' || request_letter == '!')
		return true;
	else
		return false;
}

/*======================================
			  shutdown
RETURNS:
	true if request is valid, false if not
=======================================*/
void shutdown() {
	std::cout << "SHUTDOWN\n";
}

int main() {
	// ========================PROGRAM STARTUP=============================
	// Display the authors personal logo and program title
	std::cout << "---------------------------------" << std::endl;
	std::cout << "-          CAFE DU MONDE        -" << std::endl;
	std::cout << "-        By: Brennen Green      -" << std::endl;
	std::cout << "---------------------------------" << std::endl;

	std::cout << std::endl; // Line for spacing
	
	// Start up the machine and ask the technician for fill levels of each beverage tank
	// Declare necessary variables for each tank
	int coffee_tank_level, latte_tank_level, mocha_tank_level;
	// Display prompt to user
	std::cout << "STARTUP: Enter Tank Levels\n";
	std::cout << "Coffee tank: ";
	std::cin >> coffee_tank_level;
	std::cout << "Latte tank:  ";
	std::cin >> latte_tank_level;
	std::cout << "Mocha tank:  ";
	std::cin >> mocha_tank_level;
	std::cout << std::endl; // Blank line for spacing

	// ======================BEVERAGE SELECTION LOOP======================
	std::string current_request = "";
	while (current_request[0] != SHUTDOWN_IDENTIFIER) {

		std::cout << "PLEASE SELECT YOUR BEVERAGE\n";
		// Check if each tank has at minimum the maximum amount for a sale,
		// if a tank doesn't, then don't outpit that option to user
		if (coffee_tank_level >= 18) {
			std::cout << "C. Coffee   $ 0.15 per oz.\n";
		}
		if (latte_tank_level >= 18) {
			std::cout << "L. Latte    $ 0.25 per oz.\n";
		}
		if (mocha_tank_level >= 18) {
			std::cout << "M. Mocha    $ 0.30 per oz.\n";
		}
		std::cout << "===> ";
		std::cin >> current_request;

		int beverage_tank_level;
		double cost_of_selection_per_oz;
		std::string beverage_selection;
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
			std::cout << "Invalid selection! Try again!\n";
			std::cout << "===> ";
			std::cin >> current_request;

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
			shutdown();
		}
		else { // Complete the remainder of the program
			// Prompt the user for the size of cup to brew
			int brew_amount = 0;
			std::cout << "Number of ounces (9-18): ";
			std::cin >> brew_amount;
			while (brew_amount < 9 || brew_amount > 18) {
				std::cout << "Invailid entry!" << std::endl;
				std::cout << "Number of ounces (9-18): ";
				std::cin >> brew_amount;
			}

			// =============== PAYMENT ==================
			// Compute the total cost of the cup then ask the user how muc hthey will pay with
			double sub_total = brew_amount * cost_of_selection_per_oz;
			double tax_total = round((sub_total * TAX_RATE) * 100) / 100;
			double total_price = sub_total + tax_total;
			double amount_paid;
			std::cout << "Total Price:       $ " << total_price << std::endl;
			std::cout << "Enter amount paid: $ ";
			std::cin >> amount_paid;
			while (amount_paid < total_price) { // Ensure the user paid with enough to afford the cup
				std::cout << "That is not enough! Please try again." << std::endl;
				std::cout << "Enter amount paid: $ ";
				std::cin >> amount_paid;
			}
			// Display the amount of change the user has received
			double change_amount = amount_paid - total_price;
			std::cout << "Your change $ " << change_amount << " falls out of the machine on the floor." << std::endl;
			std::cout << "Thank you! Your " << beverage_selection << " will now be brewed!" << std::endl;
			std::cout << std::endl; // New line for spacing 
			Sleep(BREWING_DELAY_MSECONDS);
			
			// ========== BEGIN BREWEING ===============
			std::cout << "A cup drops out of the machine below the " << beverage_selection << " spigot." << std::endl;
			int amount_brewed = 0;
			while (amount_brewed < brew_amount) {
				if (brew_amount - amount_brewed >= 3)
					amount_brewed = amount_brewed + 3;
				else
					amount_brewed = amount_brewed + (brew_amount - amount_brewed); // Adds the remainder of what's left to brew if less than 3
				std::cout << std::setw(2) << amount_brewed << " ounces dispensed..." << std::endl;
				Sleep(BREWING_DELAY_MSECONDS);
			}
			std::cout << std::endl; // Spacing
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
			std::cout << "Your Latte is ready! Here is your receipt!" << std::endl;
			std::cout << "Beverage:       " << beverage_selection << std::endl;
			std::cout << "Ounces:         " << brew_amount << std::endl;
			std::cout << "Price per Oz: $ " << cost_of_selection_per_oz << std::endl;
			std::cout << "Sub Total:    $ " << sub_total << std::endl;
			std::cout << "Tax:          $ " << tax_total << std::endl;
			std::cout << "Total:        $ " << total_price << std::endl;
			std::cout << "Amount Paid   $ " << amount_paid << std::endl;
			std::cout << "Change:       $ " << change_amount << std::endl;
			std::system("pause");

			// TODO: Precision on output
		}
	}

	std::system("pause");
	return 0;
}

