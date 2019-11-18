#include "catalog.h"
#include "course.h"
#include <fstream>
#include <string>


catalog::catalog() {
	for (int i = 0; i < MAX_COURSES; i++)
	{
		courses[i] = course();
	}
	numCourses = 0;
}

int catalog::getNumCourses()
{
	return numCourses;
}

course catalog::getCourse(int index)
{
	if (index > numCourses || index < 0)
	{
		course emptyCourse;
		return emptyCourse;
	}
	else
	{
		return courses[index];
	}
}

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

void catalog::print()
{
	cout << "=============== COURSE CATALOG ===============" << endl;
	cout << "ID    DEPT NUMB HRS TITLE                     " << endl;
	cout << "----- ---- ---- --- --------------------------" << endl;
	for (int i = 0; i < numCourses; i++)
	{
		courses[i].print();
	}
	cout << "=========== # COURSES LISTED: " << numCourses << " ===========" << endl;
	system("pause");
}

void catalog::read()
{
	ifstream fin(IN_CATALOG_FILE);
	int endFound = 0; // 1 If end has been found
	int i = 0;
	if (fin.is_open())
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
		fin.close();
	}
}
