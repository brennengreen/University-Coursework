#include "studentList.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//-------------------------------------------------------------------
//                               constructor
//-------------------------------------------------------------------
// initializes the objects (data members) used by the class
studentList::studentList() {
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		stuArray[i] = student();
	}
	numStudents = 0;
}

//-------------------------------------------------------------------
//                               print
//-------------------------------------------------------------------
// Stringified representation of the student list
void studentList::print()
{
	cout << "================ STUDENT LIST <" << numStudents << "> ================" << endl;
	cout << "IDNUM HRS LAST            FIRST          " << endl;
	cout << "----- --- --------------- ---------------" << endl;
	for (int i = 0; i < numStudents; i++)
	{
		stuArray[i].print();
	}
	system("pause");
}

//-------------------------------------------------------------------
//                               search(id)
//-------------------------------------------------------------------
// Given an id searches the student array for a match or returns
// an empty student object if none is found
student studentList::search(string id)
{
	for (int i = 0; i < numStudents; i++)
	{
		student& currStudent = stuArray[i];
		if (currStudent.getId() == id)
		{
			return currStudent;
		}
	}
	return student();
}

//-------------------------------------------------------------------
//                               search(idx)
//-------------------------------------------------------------------
// Given an integer which is an index to an array, returns the student
// at that index or an empty student if index is out of bounds
student studentList::search(int idx)
{
	if (idx > numStudents || idx < 0)
	{
		return student();
	}
	else
	{
		return stuArray[idx];
	}
}

//-------------------------------------------------------------------
//                               read
//-------------------------------------------------------------------
// With a specified input file, reads the data in a specific format
// to populate the list of students
void studentList::read()
{
	ifstream fin(IN_STU_LIST);
	if (fin.is_open())
	{
		fin >> numStudents;
		for (int i = 0; i < numStudents; i++)
		{
			student& currStudent = stuArray[i];
			string newId, firstName, lastName;
			int totalCredits;
			fin >> newId >> firstName >> lastName >> totalCredits;
			currStudent.setId(newId);
			currStudent.setCreditHours(totalCredits);
			currStudent.setFirstName(firstName);
			currStudent.setLastName(lastName);
		}

	}

	fin.close(); // Close for safety
} // read()
