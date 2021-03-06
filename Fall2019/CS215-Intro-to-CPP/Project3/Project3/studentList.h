#pragma once
#include "student.h"
#include <string>

//----------------------------------------------------------------------
//                         studentList class
//----------------------------------------------------------------------
// This class allows the program to keep a continuous list of students
// who are currently registered
//----------------------------------------------------------------------

using namespace std;

const string IN_STU_LIST = "stuList.txt";
const int MAX_STUDENTS = 50;
class studentList {
public:
	studentList();
	void print();
	student search(string id); // Searches with student id
	student search(int idx); // Searches with index
	void read(); // Reads input file for student data

private:
	student stuArray[MAX_STUDENTS];
	int numStudents;
};