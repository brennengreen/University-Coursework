//--------------------------------------------------------------------------
//								CS215-003 LAB3
//--------------------------------------------------------------------------
// Author: Brennen Green
// Date: 09/17/2019
// Description: A C++ Program that does arithmetic on two integers
//--------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>

void printBox(char box_type, int box_size) {
	// Given a character to represent the box and the length of the box sides
	// use a for loop to print the box to the screen
	for (int i = 0; i < box_size; ++i) {
		for (int j = 0; j < box_size; ++j) {
			std::cout << box_type << " ";
		}
		std::cout << std::endl;
	}

}

int main() {
	// Display the authors personal logo and program title
	std::cout << "---------------------------------" << std::endl;
	std::cout << "-           Box Maker           -" << std::endl;
	std::cout << "-        By: Brennen Green      -" << std::endl;
	std::cout << "---------------------------------" << std::endl;

	std::cout << "Box Characters:" << std::endl;
	std::cout << "S - Star" << std::endl;
	std::cout << "D - Dollar" << std::endl;
	std::cout << "B - Backslash" << std::endl;
	std::cout << std::endl;

	char user_char_selection = ' ';
	while (user_char_selection != 'D' && user_char_selection != 'S' && user_char_selection != 'B') {
		std::cout << "Enter your selection: ";
		std::cin >> user_char_selection;
		user_char_selection = toupper(user_char_selection);
		if (user_char_selection != 'D' && user_char_selection != 'S' && user_char_selection != 'B') {
			std::cout << "Invalid entry. Enter *, $, \\" << std::endl;
		}
	}
	std::cout << std::endl;

	int user_size_selection = 0;
	while (user_size_selection < 3 || user_size_selection > 7) {
		std::cout << "Enter size of box <3-7>: ";
		std::cin >> user_size_selection;
		if (user_size_selection < 3 || user_size_selection > 7) {
			std::cout << "Invalid entry. Enter a number 3-7!" << std::endl;
		}
	}
	std::cout << std::endl;

	char box_character;
	if (user_char_selection == 'S') {
		box_character = '*';
	}
	else if (user_char_selection == 'B') {
		box_character = '\\';
	}
	else if (user_char_selection == 'D') {
		box_character = '$';
	}
	printBox(box_character, user_size_selection);

	std::cout << std::endl;
	std::system("pause");
	return 0;
}