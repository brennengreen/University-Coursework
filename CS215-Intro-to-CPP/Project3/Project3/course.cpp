#include "course.h";
#include <iostream>
#include <iomanip>

using namespace std;

course::course() 
{
	id = "";
	department = "";
	number = "";
	creditHours = 0;
	title = "";
}

void course::setHours(int hours)
{
	if (hours <= 0) {
		creditHours = 0;
	}
	else {
		creditHours = hours;
	}
}

void course::setId(string newId)
{
	id = newId;
}

void course::setNumber(string num)
{
	number = num;
}

void course::setDepartment(string newDeptartment)
{
	department = newDeptartment;
}

void course::setTitle(string newTitle)
{
	title = newTitle;
}

string course::getId()
{
	return id;
}

string course::getDeptarment()
{
	return department;
}

string course::getNumber()
{
	return number;
}

int course::getHours()
{
	return creditHours;
}

string course::getTitle()
{
	return title;
}

void course::print()
{
	cout << setw(5) << left << id << " " << setw(4) << department << " " << setw(4) << number << " " << setw(3) << right \
		<< creditHours << " " << setw(20) << left << title << endl;
}
