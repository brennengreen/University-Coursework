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

bool is_valid_request(std::string request) {
	/*======================================
	PARAMS: 
		std::string request | the current request from the user
	RETURNS:
		true if request is valid, false if not
	=======================================*/
	char request_letter = tolower(request[0]);
	if (request_letter == 'c' || request_letter == 'm' || request_letter == 'l' || request_letter == '!')
		return true;
	else
		return false;
}

void shutdown() {
	std::cout << "SHUTDOWN\n";
}

int main() {
	// =====================NECESSARY CONSTANTS===========================
	// The maximum and minimum amount of ounces allowed in each cup
	const int CUP_MAX_OUNCES = 18;
	const int CUP_MIN_OUNCES = 9;
	const double TAX_RATE = 0.06; // Sales tax rate is 6%
	// Cost of each beverage per ounce
	const double COST_COFFEE_PER_OZ = 0.15;
	const double COST_LATTEE_PER_OZ = 0.25;
	const double COST_MOCHA_PER_OZ = 0.30;


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
	while (current_request[0] != '!') {

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
		// Determine which tank to check the levels of
		switch (tolower(current_request[0])) {
			case 'c':
				beverage_tank_level = coffee_tank_level;
				break;
			case 'l':
				beverage_tank_level = latte_tank_level;
				break;
			case 'm':
				beverage_tank_level = mocha_tank_level ;
				break;
			case '!':
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

			switch (tolower(current_request[0])) {
				case 'c':
					beverage_tank_level = coffee_tank_level;
					break;
				case 'l':
					beverage_tank_level = latte_tank_level;
					break;
				case 'm':
					beverage_tank_level = mocha_tank_level;
					break;
				case '!':
					beverage_tank_level = 999999; // The machine will shut down and this selection has no tank
					break;
				default:
					break;
			}
		}

		// If the user entered the shutdown command, display shut down message
		if (current_request[0] == '!') {
			shutdown();
		}
		else { // Complete the remainder of the program
			int brew_amount = 0;
			std::cout << "Number of ounces (9-18): ";
			std::cin >> brew_amount;
			while (brew_amount < 9 || brew_amount > 18) {
				std::cout << "Invailid entry!" << std::endl;
				std::cout << "Number of ounces (9-18): ";
				std::cin >> brew_amount;
			}


		}
	}

	std::system("pause");
	return 0;
}

