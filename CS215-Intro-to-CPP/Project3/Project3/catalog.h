#pragma once
#include "course.h"
#include <iostream>

using namespace std;

const int MAX_COURSES = 50;
const string OUT_FILE_NAME = "catalog.txt";

class catalog {
public:
	catalog();

	// Accessors
	int getNumCourses();
	course getCourse(int index);

	// ETC
	int search(string id); // Search for a specific id and return the index where it exists
	void print();
	void read();
private:
	course courses[MAX_COURSES];
	int numCourses;
};