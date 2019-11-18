#include "schedule.h"
#include <iostream>
#include <iomanip>
using namespace std;

schedule::schedule() {
	studentId = "";
	numCourses = 0;
	for (int i = 0; i < MAX_STU_COURSES; i++)
	{
		courseIDs[i] = "";
	}
}

string schedule::getStudentId()
{
	return studentId;
}

int schedule::getNumCourses()
{
	return numCourses;
}

string schedule::getCourseID(int index)
{
	if (index > numCourses || index < 0)
	{
		return "";
	}
	else
	{
		return courseIDs[index];
	}
}

void schedule::setStudentId(string newId)
{
	studentId = newId;
}

int schedule::addCourse(string courseID)
{
	if (numCourses == MAX_STU_COURSES)
	{
		return -1; // Array is full
	}
	else
	{
		courseIDs[numCourses] = courseID;
		numCourses++;
		return 0;
	}
}

int schedule::dropCourse(string courseID)
{
	for (int i = 0; i < numCourses; i++)
	{
		if (courseIDs[i] == courseID)
		{
			for (int j = i; j < numCourses - 1; j++) // Loop from the found course index to the end of the array and shift all values to the left 1
			{
				courseIDs[j] = courseIDs[j + 1]; // Current course = the index of the course after it
			}
			courseIDs[numCourses] = "";
			numCourses--;
			return 0;
		}
	}
	return -1; // Not Found
}

void schedule::print()
{
	cout << left << setw(5) << studentId << " " << right << setw(2) << numCourses << " ";
	for (int i = 0; i < numCourses; i++) 
	{
		cout << courseIDs[i] << " ";
	}
	cout << endl;
}
