#include "menu.h"
#include <string>
#include <iostream>

using namespace std;

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

void menu::setTitle(string newTitle)
{
	title = newTitle;
}

void menu::setErrorMsg(string newError)
{
	error = newError;
}

void menu::addOption(char identifier, string desc)
{
	if (numOptions < MAX_OPTIONS)
	{
		menuOptions[numOptions] = identifier;
		optionDescs[numOptions] = desc;
		numOptions++;
	}
}

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
		cout << "Enter option: ";
		cin >> userChoice;
		userChoice = toupper(userChoice);
		isValidOption = validOption(userChoice);
	}
	return userChoice;
}

bool menu::validOption(char userChoice)
{
	for (int i = 0; i < numOptions; i++)
	{
		if (menuOptions[i] == userChoice)
			return true;
	}
	return false;
}
