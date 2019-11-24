#pragma once
#include <string>

//----------------------------------------------------------------------
//                         student class
//----------------------------------------------------------------------
// This class implements the student object type which allows the
// program to keep track of many different students in a concise way
//----------------------------------------------------------------------

using namespace std;

class student {
public:
	student();
	void print();
	// Getters
	string getId();
	string getFirstName();
	string getLastName();
	int getCreditHours();
	// Setters
	void setId(string newId);
	void setFirstName(string name);
	void setLastName(string name);
	void setCreditHours(int hours);

private:
	string id;
	string firstName;
	string lastName;
	int totalCreditHours;
};