#pragma once
#include <string>

//----------------------------------------------------------------------
//                         course class
//----------------------------------------------------------------------
// This class implements the course class which allows the programmer
// to create objects to represent classes easily
//----------------------------------------------------------------------

using namespace std;

class course {
public:
	course();

	// MUTATORS
	void setHours(int hours);
	void setId(string newId);
	void setNumber(string num);
	void setDepartment(string newDeptartment);
	void setTitle(string newTitle);

	// ACCESSORS
	string getId();
	string getDeptarment();
	string getNumber();
	int getHours();
	string getTitle();

	// ETC
	void print();
private:
	string id;
	string department;
	string number;
	int creditHours;
	string title;
};