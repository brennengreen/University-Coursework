#include "schedList.h"
#include "schedule.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

schedList::schedList() {
	numSchedules = 0;
	for (int i = 0; i < MAX_SCHEDULES; i++)
	{
		schedules[i] = schedule();
	}
}

schedule schedList::getSchedule(int idx)
{
	if (idx > numSchedules || idx < 0)
	{
		return schedule();
	}
	else
	{
		return schedules[idx];
	}
}

schedule schedList::getSchedule(string id)
{
	for (int i = 0; i < numSchedules; i++)
	{
		if (schedules[i].getStudentId() == id)
		{
			return schedules[i];
		}
	}
	return schedule(); // No schedule with said id was found to exist
}

void schedList::addSchedule(schedule searchSchedule)
{
	string searchId = searchSchedule.getStudentId();
	for (int i = 0; i < numSchedules; i++)
	{
		schedule& currentSched = schedules[i];
		if (currentSched.getStudentId() == searchId)
		{
			currentSched = searchSchedule;
		}
	}
	// No schedule with same student id has been found

	if (numSchedules < MAX_SCHEDULES)
	{
		schedules[numSchedules] = searchSchedule;
	}
	else
	{
		cout << "Error: Schedules array is full." << endl;
	}
}

void schedList::print()
{
	cout << "============================= ALL SCHEDULES <" << numSchedules << "> ============================\n";
	cout << "STUID #C COURSE IDS" << endl;
	cout << "----- -- -------------------------------------------------------------------\n";
	for (int i = 0; i < numSchedules; i++)
	{
		schedules[i].print();
	}

	system("pause");
}

void schedList::read()
{
	ifstream fin(IN_FILE_NAME);
	if (fin.is_open())
	{
		fin >> numSchedules;
		for (int i = 0; i < numSchedules; i++)
		{
			schedule& currSched = schedules[i];
			string studentId;
			int numCourses;
			fin >> studentId >> numCourses;
			currSched.setStudentId(studentId);
			for (int j = 0; j < numCourses; j++)
			{
				string currCourseId;
				fin >> currCourseId;
				currSched.addCourse(currCourseId);
			}
		}
		fin.close();
	}
}

void schedList::write()
{
	ofstream fout(OUT_FILE_NAME);
	if (fout.is_open())
	{
		fout << numSchedules << endl;
		for (int i = 0; i < numSchedules; i++)
		{
			schedule currSchedule = schedules[i];
			fout << currSchedule.getStudentId() << " " << currSchedule.getNumCourses() << " ";
			for (int j = 0; j < currSchedule.getNumCourses(); j++)
			{
				fout << currSchedule.getCourseID(j) << " ";
			}
			fout << endl;
		}
		fout.close();
	}
}
