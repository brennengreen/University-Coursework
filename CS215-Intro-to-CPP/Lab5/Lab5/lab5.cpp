//--------------------------------------------------------------------------
//								CS215-003 LAB5
//--------------------------------------------------------------------------
// Author: Brennen Green
// Date: 10/8/2019
// Description:A program that takes in a file given at runtime and generates
// a grade report based on that file
//--------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// CONSTANSTS
const int MAX_FRIENDS = 5;
const string INPUT_FILE = "indata.txt";

struct AFriend {
	string name;
	string phone;
	string email;
};

void display_friends(AFriend friends[], int num_friends) {
	cout << "-------------------- FRIEND LIST --------------------" << endl;
	cout << "Num" << " " << "Name           " << " " << "Phone       " << " " << "Email               " << endl;
	cout << "--- --------------- ------------ --------------------" << endl;
	for (int i = 0; i < num_friends; ++i) {
		AFriend& curr_frnd = friends[i];
		cout << setw(3) << right << i + 1 << " " << setw(15) << left << curr_frnd.name << " " << setw(12) << curr_frnd.phone << " " << setw(20) << left << curr_frnd.email << endl;
	}
	cout << endl;
	cout << "-----------------------------------------------------" << endl;

}

AFriend add() {
	AFriend new_friend;
	cout << "Name: ";
	cin >> new_friend.name;
	cout << "Email: ";
	cin >> new_friend.email;
	cout << "Phone: ";
	cin >> new_friend.phone;
	return new_friend;
}

void edit(AFriend friends[], int num_friends) {

}

int main() {
	AFriend friends[MAX_FRIENDS];
	int num_friends = 0;

	ifstream f_in(INPUT_FILE);
	int num_lines;
	f_in >> num_lines;
	if (f_in.fail()) {
		cout << "ERROR: UNABLE TO OPEN FILE!" << endl;
		std::system("pause");
		return 1;
	} // File has failed

	// File has been opened
	for (int i = 0; i < num_lines; ++i) {
		AFriend& current = friends[i];
		f_in >> current.name;
		f_in >> current.phone;
		f_in >> current.email;
		num_friends++;
	}
	string user_option = "";
	while (user_option[0] != 'x') {
		display_friends(friends, num_friends);
		cout << "Options: A=Add, E=Edit, X=Exit" << endl;
		while (user_option[0] != 'x' && user_option[0] != 'a' && user_option[0] != 'e') {
			cout << "Enter A, E, or X: ";
			cin >> user_option;
			user_option = tolower(user_option[0]);
			if (user_option[0] != 'x' && user_option[0] != 'a' && user_option[0] != 'e') {
				cout << "Invalid option! Try again." << endl;
			}
		}

		switch (user_option[0]) {
			case 'x':
				cout << "Thanks for using Friender!" << endl;
				std::system("pause");
				return 0;
			case 'a':
				num_friends++;
				friends[num_friends] = add();
				break;
			case 'e':
				edit(friends, num_friends);
				break;
			default:
				break;
		}
	}

	

	std::system("pause");
	return 0;
}
