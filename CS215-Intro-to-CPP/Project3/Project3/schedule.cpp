#include "schedule.h"
#include <iostream>
#include <iomanip>
using namespace std;

schedule::schedule() {
	studentId = "";
	numCourses = 0;
	for (int i = 0; i < MAX_COURSES; i++)
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
	if (index > numCourses)
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
	if (numCourses == MAX_COURSES)
	{
		return -1; // Array is full
	}
	else
	{
		courseIDs[numCourses] = courseID;
		numCourses++;
	}
}

int schedule::dropCourse(string courseID)
{
	for (int i = 0; i < numCourses; i++)
	{
		if (courseIDs[i] == courseID)
		{
			courseIDs[i] = "";
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
