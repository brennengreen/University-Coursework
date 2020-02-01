#include "course.h";
#include <iostream>
#include <iomanip>

using namespace std;

//-------------------------------------------------------------------
//                               constructor
//-------------------------------------------------------------------
// Initializes all values in the course to empty values
course::course() 
{
	id = "";
	department = "";
	number = "";
	creditHours = 0;
	title = "";
}

//-------------------------------------------------------------------
//                               setHours
//-------------------------------------------------------------------
// Set the hours a course is worth based on given values
void course::setHours(int hours)
{
	if (hours <= 0) { // defaults to 0 if given value is below 0
		creditHours = 0;
	}
	else {
		creditHours = hours;
	}
}

//-------------------------------------------------------------------
//                               setId
//-------------------------------------------------------------------
// Set the course id
void course::setId(string newId)
{
	id = newId;
}

//-------------------------------------------------------------------
//                               setNumber
//-------------------------------------------------------------------
// Set the course number
void course::setNumber(string num)
{
	number = num;
}

//-------------------------------------------------------------------
//                               setDepartment
//-------------------------------------------------------------------
// Set the department the course is within
void course::setDepartment(string newDeptartment)
{
	department = newDeptartment;
}

//-------------------------------------------------------------------
//                               setTitle
//-------------------------------------------------------------------
// Set the title of the course
void course::setTitle(string newTitle)
{
	title = newTitle;
}

//-------------------------------------------------------------------
//                               getId
//-------------------------------------------------------------------
// Set the id of the course
string course::getId()
{
	return id;
}

//-------------------------------------------------------------------
//                               getDepartment
//-------------------------------------------------------------------
// Return the department the course is within
string course::getDeptarment()
{
	return department;
}

//-------------------------------------------------------------------
//                               getNumber
//-------------------------------------------------------------------
// Return the course number
string course::getNumber()
{
	return number;
}

//-------------------------------------------------------------------
//                               getHours
//-------------------------------------------------------------------
// Return the amount of hours the course is worth
int course::getHours()
{
	return creditHours;
}

//-------------------------------------------------------------------
//                               getTitle
//-------------------------------------------------------------------
// Return the title of the course
string course::getTitle()
{
	return title;
}

//-------------------------------------------------------------------
//                               print
//-------------------------------------------------------------------
// Print the information from the course to the user
void course::print()
{
	cout << setw(5) << left << id << " " << setw(4) << department << " " << setw(4) << number << " " << setw(3) << right \
		<< creditHours << " " << setw(20) << left << title << endl;
}
