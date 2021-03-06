#pragma once
#include "schedule.h"

//----------------------------------------------------------------------
//                         schedList class
//----------------------------------------------------------------------
// This class helps keep track of a list of schedules of all known
// students
//----------------------------------------------------------------------

const int MAX_SCHEDULES = 50;
const string IN_FILE_NAME = "schedList.txt";
const string OUT_FILE_NAME = "schedList_1.txt";
class schedList {
public:
	schedList();

	schedule getSchedule(int idx);
	schedule getSchedule(string id);

	void addSchedule(schedule searchSchedule);
	void print();
	void read();
	void write();
private:
	schedule schedules[MAX_SCHEDULES];
	int numSchedules;
};