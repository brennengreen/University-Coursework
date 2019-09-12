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

	// ==============================BEVERAGE SELECTION======================


	std::system("pause");
	return 0;
}