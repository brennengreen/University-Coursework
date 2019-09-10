//--------------------------------------------------------------------------
//								CS215-003 LAB2																				
//--------------------------------------------------------------------------
// Author: Brennen Green
// Date: 09/10/2019
// Description: Given four inputs (first name, last name, payrate, hours
// worked) output a pretty-printed paystub telling them the taxes they paid
// and the gross/net-pay they're earning
//--------------------------------------------------------------------------


#include <iostream>
#include <iomanip>
#include <string>

int main() {
	// Constant values that will be used later on
	// Tax percentages as doubles for calculating pay
	const double ss_tax_rate = 0.03;
	const double state_tax_rate = 0.06;
	const double fed_tax_rate = 0.07;

	// Display the authors personal logo and program title
	std::cout << "---------------------------------" << std::endl;
	std::cout << "-        Payroll Calculator     -" << std::endl;
	std::cout << "-        By: Brennen Green      -" << std::endl;
	std::cout << "---------------------------------" << std::endl;

	// Gather input from their user
	// first_name, last_name (strings
	// pay_rate, hours_worked (double)
	std::string first_name;
	std::string last_name;
	std::cout << "Enter first name:    ";
	std::cin >> first_name;
	std::cout << "Enter last name:     ";
	std::cin >> last_name;

	double hours_worked;
	double pay_rate; // Could convert pay rate to pennies and use integer, but redundant given the nature of our calculations
	std::cout << "Enter hours worked:  ";
	std::cin >> hours_worked;
	std::cout << "Enter pay rate:      ";
	std::cin >> pay_rate;

	// Compute the values needed for the program
	// Begin by using the tax rates to calculate taxes paid
	// taxes are rounded up using round() in accordance with tax laws
	double gross_pay = hours_worked * pay_rate;
	double total_taxes;
	double ss_tax = gross_pay * ss_tax_rate;
	double state_tax = gross_pay * state_tax_rate;
	double fed_tax = gross_pay * fed_tax_rate;
	total_taxes = ss_tax + state_tax + fed_tax;
	double net_pay = gross_pay - total_taxes;

	// Output the programs results to the user in proper format
	std::cout << std::endl;
	std::cout << "Name:      " << last_name << ", " << first_name << std::endl;
	std::cout << "Gross Pay  $" << std::fixed << std::setprecision(2) << std::setw(9) << gross_pay << std::endl;
	std::cout << "State Tax  $" << std::fixed << std::setprecision(2) << std::setw(9) << state_tax << std::endl;
	std::cout << "Fed Tax    $" << std::fixed << std::setprecision(2) << std::setw(9) << fed_tax << std::endl;
	std::cout << "SS Tax     $" << std::fixed << std::setprecision(2) << std::setw(9) << ss_tax << std::endl;
	std::cout << "Net Pay    $" << std::fixed << std::setprecision(2) << std::setw(9) << net_pay << std::endl;
	std::cout << std::endl;


	// Pause the program to review results
	std::system("pause");
	return 0;
}