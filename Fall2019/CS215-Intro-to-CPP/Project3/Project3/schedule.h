#pragma once
#include <string>

//----------------------------------------------------------------------
//                         schedule class
//----------------------------------------------------------------------
// This class allows each student to have an indivdually discrete schedule
// and will be used by the schedule list class
//----------------------------------------------------------------------

using namespace std;

const int MAX_STU_COURSES = 10;

class schedule {
public:
	schedule();
	// Accessors
	string getStudentId();
	int getNumCourses();
	string getCourseID(int index);

	// Mutators
	void setStudentId(string newId);
	int addCourse(string courseID);
	int dropCourse(string courseID); // 1=Error 0=Success
	
	// ETC
	void print();
private:
	string studentId;
	string courseIDs[MAX_STU_COURSES];
	int numCourses;
};