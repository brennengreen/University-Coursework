#pragma once
#include <string>

using namespace std;

const int MAX_OPTIONS = 10;

class menu {
public:
	menu();

	// Mutators
	void setTitle(string newTitle);
	void setErrorMsg(string newError);
	void addOption(char identifier, string desc);

	// Accessors

	// Menu Controls
	char doMenu();
	bool validOption(char userChoice);
private:
	char menuOptions[MAX_OPTIONS];
	int numOptions;
	string optionDescs[MAX_OPTIONS]; // Parallel to menu options
	string title;
	string error;

};