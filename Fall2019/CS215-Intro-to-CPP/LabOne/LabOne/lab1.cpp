//--------------------------------------------------------------------------
//								CS215-003 LAB1
//--------------------------------------------------------------------------
// Author: Brennen Green
// Date: 09/04/2019
// Description: A C++ Program that does arithmetic on two integers
//--------------------------------------------------------------------------
#include <iostream>


int main() {
	// Display the authors personal logo and program title
	std::cout << "---------------------------------" << std::endl;
	std::cout << "-         Arithmetic Fun        -" << std::endl;
	std::cout << "-        By: Brennen Green      -" << std::endl;
	std::cout << "---------------------------------" << std::endl;

	int number_one; // The first number of the pair to perform arithmetic on
	int number_two; // The second number of the pair to perform arithmetic on

	// Receive input from 
	std::cout << "Please input integer one: ";
	std::cin >> number_one;


	std::cout << "Please input integer two: ";
	std::cin >> number_two;

	// Separate the output from the input using a newline
	std::cout << std::endl;

	// Perform arithmetic on the two numbers to find:
	// sum, difference, product, integer quotiet, and floating point quotient
	// of the numbers
	float f_quotient = (float)number_one / (float)number_two; // Uses type casting to convert integer division to floating point division
	int int_quotient = number_one / number_two;
	int sum = number_one + number_two;
	int difference = number_one - number_two;
	int product = number_one * number_two;

	// Display the output of the calculations
	std::cout << "Floating-Point Quotient:  " << f_quotient << std::endl;
	std::cout << "Integer Quotient:         " << int_quotient << std::endl;
	std::cout << "Sum:                      " << sum << std::endl;
	std::cout << "Difference:               " << difference << std::endl;
	std::cout << "Product:                  " << product << std::endl;

	// Pause the execution so user can review output
	std::system("pause");

	return 0;
}
