#include "student.h"
#include <iostream>
#include <iomanip>

using namespace std;

student::student() 
{
	id = "";
	firstName = "";
	lastName = "";
	totalCreditHours = 0;
}

void student::print()
{
	cout << setw(5) << left << id << " " << setw(3) << right << totalCreditHours << " " \
		<< setw(15) << left << lastName << " " << setw(15) << left << firstName << endl;
}

string student::getId()
{
	return id;
}

string student::getFirstName()
{
	return firstName;
}

string student::getLastName()
{
	return lastName;
}

int student::getCreditHours()
{
	return totalCreditHours;
}

void student::setId(string newId)
{	
	id = newId;
}

void student::setFirstName(string name)
{
	firstName = name;
}

void student::setLastName(string name)
{
	lastName = name;
}

void student::setCreditHours(int hours)
{
	totalCreditHours = hours;
}
