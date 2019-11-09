#include "menu.h"
#include <string>

using namespace std;

menu::menu() {
	title = string();
	error = string();
	for (int i = 0; i < MAX_OPTIONS; i++)
	{
		optionDescs[i] = string();
		menuOptions[i] = char();
	}
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
	return 0;
}

bool menu::validOption()
{
	return false;
}
