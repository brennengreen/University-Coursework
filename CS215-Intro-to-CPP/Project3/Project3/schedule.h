#pragma once
#include <string>
using namespace std;

const int MAX_COURSES = 10;

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
	string courseIDs[MAX_COURSES];
	int numCourses;
};