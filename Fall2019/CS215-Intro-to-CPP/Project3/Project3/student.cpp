#include "student.h"
#include <iostream>
#include <iomanip>

using namespace std;

//-------------------------------------------------------------------
//                               constructor
//-------------------------------------------------------------------
// initializes the objects (data members) used by the class
student::student() 
{
	id = "";
	firstName = "";
	lastName = "";
	totalCreditHours = 0;
}

//-------------------------------------------------------------------
//                               print
//-------------------------------------------------------------------
// Stringified representation of the student
void student::print()
{
	cout << setw(5) << left << id << " " << setw(3) << right << totalCreditHours << " " \
		<< setw(15) << left << lastName << " " << setw(15) << left << firstName << endl;
}

//-------------------------------------------------------------------
//                               getId
//-------------------------------------------------------------------
// returns the students id
string student::getId()
{
	return id;
}

//-------------------------------------------------------------------
//                               getFirstName
//-------------------------------------------------------------------
// Returns the students first name
string student::getFirstName()
{
	return firstName;
}

//-------------------------------------------------------------------
//                               getLastName
//-------------------------------------------------------------------
// Returns the students last name
string student::getLastName()
{
	return lastName;
}

//-------------------------------------------------------------------
//                               getCreditHours
//-------------------------------------------------------------------
// Returns the students number of credit hours
int student::getCreditHours()
{
	return totalCreditHours;
}

//-------------------------------------------------------------------
//                               setId
//-------------------------------------------------------------------
// Sets the new student id for the student
void student::setId(string newId)
{	
	id = newId;
}

//-------------------------------------------------------------------
//                               setFirstName
//-------------------------------------------------------------------
// Sets the students first name 
void student::setFirstName(string name)
{
	firstName = name;
}

//-------------------------------------------------------------------
//                               setLastName
//-------------------------------------------------------------------
// Sets the students last name
void student::setLastName(string name)
{
	lastName = name;
}

//-------------------------------------------------------------------
//                               setCreditHours
//-------------------------------------------------------------------
// Sets the students number of credit hours
void student::setCreditHours(int hours)
{
	totalCreditHours = hours;
}
