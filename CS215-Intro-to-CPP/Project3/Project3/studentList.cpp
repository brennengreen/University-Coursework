#include "studentList.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

studentList::studentList() {
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		stuArray[i] = student();
	}
	numStudents = 0;
}

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

student studentList::search(int idx)
{
	if (idx > numStudents || idx < 0)
	{
		return student();
	}
}

void studentList::read()
{
	ifstream fin(IN_FILE_NAME);
	if (!fin.fail)
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

	fin.close();
}
