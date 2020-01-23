#include "menu.h"
#include <string>
#include <iostream>

using namespace std;

//-------------------------------------------------------------------
//                               constructor
//-------------------------------------------------------------------
// initializes the objects (data members) used by the class
menu::menu() {
	title = string();
	error = string();
	for (int i = 0; i < MAX_OPTIONS; i++)
	{
		optionDescs[i] = string();
		menuOptions[i] = char();
	}
	numOptions = 0;
}

//-------------------------------------------------------------------
//                               setTitle
//-------------------------------------------------------------------
// Set the title of the course
void menu::setTitle(string newTitle)
{
	title = newTitle;
}

//-------------------------------------------------------------------
//                               setErrorMsg
//-------------------------------------------------------------------
// Sets the error message given when invalid input is entered
void menu::setErrorMsg(string newError)
{
	error = newError;
}

//-------------------------------------------------------------------
//                               addOptions
//-------------------------------------------------------------------
// Adds an option to the given list if it is not at capacity
void menu::addOption(char identifier, string desc)
{
	if (numOptions < MAX_OPTIONS)
	{
		menuOptions[numOptions] = identifier;
		optionDescs[numOptions] = desc;
		numOptions++;
	}
}

//-------------------------------------------------------------------
//                               doMenu
//-------------------------------------------------------------------
// Controls flow of the menu from displaying options to user input
char menu::doMenu()
{
	cout << title << endl;
	for (int i = 0; i < numOptions; i++)
	{
		cout << menuOptions[i] << "-" << optionDescs[i] << endl;
	}
	char userChoice = char();
	bool isValidOption = false;
	while (!isValidOption)
	{
		string buffer;
		cout << "Enter option: ";
		getline(cin, buffer);
		userChoice = toupper(buffer[0]);
		isValidOption = validOption(userChoice);
	}
	return userChoice;
}

//-------------------------------------------------------------------
//                               validOption
//-------------------------------------------------------------------
// Validates user input
bool menu::validOption(char userChoice)
{
	for (int i = 0; i < numOptions; i++)
	{
		if (menuOptions[i] == userChoice)
			return true;
	}
	return false;
}
