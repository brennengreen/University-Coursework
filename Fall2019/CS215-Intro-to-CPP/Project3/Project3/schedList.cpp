#include "schedList.h"
#include "schedule.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//-------------------------------------------------------------------
//                               constructor
//-------------------------------------------------------------------
// initializes the objects (data members) used by the class
schedList::schedList() {
	numSchedules = 0;
	for (int i = 0; i < MAX_SCHEDULES; i++)
	{
		schedules[i] = schedule();
	}
}

//-------------------------------------------------------------------
//                               getSchedule
//-------------------------------------------------------------------
// Given an index into the schedules array returns the schedule at
// said index or an empty schedule if the index is out of bounds

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

//-------------------------------------------------------------------
//                               getSchedule
//-------------------------------------------------------------------
// Given a student id the method searches the schedules array until
// it fines the matching schedule or returns an empty schedule if one
// is not found
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

//-------------------------------------------------------------------
//                               addSchedule
//-------------------------------------------------------------------
// Given a schedule to add, searches the array to see if the schedule
// already exists, if it does copies over new schedule, if it doesn't
// the method ensures the array isn't full then adds the schedule to the
// end of the array
void schedList::addSchedule(schedule searchSchedule)
{
	string searchId = searchSchedule.getStudentId();
	for (int i = 0; i < numSchedules; i++)
	{
		schedule& currentSched = schedules[i];
		if (currentSched.getStudentId() == searchId)
		{
			currentSched = searchSchedule;
			return;
		}
	}
	// No schedule with same student id has been found

	if (numSchedules < MAX_SCHEDULES)
	{
		schedules[numSchedules] = searchSchedule;
		numSchedules++;
	}
	else
	{
		cout << "Error: Schedules array is full." << endl;
	}
} // addSchedule

//-------------------------------------------------------------------
//                               print
//-------------------------------------------------------------------
// prints the list of schedules currently created
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

//-------------------------------------------------------------------
//                               read
//-------------------------------------------------------------------
// Opens a specified input file to get all current lists of student
// schedules
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
} // read()

//-------------------------------------------------------------------
//                               write
//-------------------------------------------------------------------
// Given a specified output file, writes all schedules to the output
// file at the end of program execution
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
