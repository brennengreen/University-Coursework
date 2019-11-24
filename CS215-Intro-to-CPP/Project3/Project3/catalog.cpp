#include "catalog.h"
#include "course.h"
#include <fstream>
#include <string>

//-------------------------------------------------------------------
//                               constructor
// Initializes all values with an empty placeholder
//-------------------------------------------------------------------
// initializes the objects (data members) used by the class

catalog::catalog() {
	for (int i = 0; i < MAX_COURSES; i++)
	{
		courses[i] = course();
	}
	numCourses = 0;
}

//-------------------------------------------------------------------
//                               getNumCourses
//-------------------------------------------------------------------
// Returns the number of courses currently in the catalog
int catalog::getNumCourses()
{
	return numCourses;
}

//-------------------------------------------------------------------
//                               getCourse
//-------------------------------------------------------------------
// Returns the course at a specific index in the catalog
course catalog::getCourse(int index)
{
	if (index > numCourses || index < 0) // Esnures index is within range of the array
	{
		// Out of index will return empty course
		course emptyCourse;
		return emptyCourse;
	}
	else
	{
		// If in range, returns course at index
		return courses[index];
	}
}

//-------------------------------------------------------------------
//                               search
// Given a student id searches the array until a match is found
// or returns the CRS_NOT_FOUND code if it is never found
//-------------------------------------------------------------------
int catalog::search(string id)
{
	for (int i = 0; i < numCourses; i++)
	{

		if (courses[i].getId() == id)
		{
			return i;
		}
	}
	return CRS_NOT_FOUND;
}

//-------------------------------------------------------------------
//                               print
//-------------------------------------------------------------------
// Prints the course catalog
void catalog::print()
{
	cout << "=============== COURSE CATALOG ===============" << endl;
	cout << "ID    DEPT NUMB HRS TITLE                     " << endl;
	cout << "----- ---- ---- --- --------------------------" << endl;
	for (int i = 0; i < numCourses; i++)
	{
		courses[i].print(); // Calls the course.print() method
	}
	cout << "=========== # COURSES LISTED: " << numCourses << " ===========" << endl;
	system("pause");
}

//-------------------------------------------------------------------
//                               read
// Reads and input file given a very specific format and populates
// the course catalog with its content
//-------------------------------------------------------------------
void catalog::read()
{
	ifstream fin(IN_CATALOG_FILE);
	int endFound = 0; // 1 If end has been found
	int i = 0;
	if (fin.is_open()) // checks if file actually opened
	{
		while (endFound == 0)
		{
			string id, dept, num, title;
			int hours;
			fin >> id >> dept >> num >> hours;
			getline(fin, title);
			if (id == "XXXXX")
			{
				endFound = 1;
			}
			else if (hours >= 1) // Ensure course is valid
			{
				courses[i].setId(id);
				courses[i].setDepartment(dept);
				courses[i].setNumber(num);
				courses[i].setHours(hours);
				courses[i].setTitle(title);
				numCourses++;
				i++;
			}
		}
		fin.close(); // close file for safety
	}
} // read()
