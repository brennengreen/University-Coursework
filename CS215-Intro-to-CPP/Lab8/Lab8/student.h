#pragma once
#include <string>
using namespace std;

const int MAX_SCORES = 10;

class student {
public:
	student();
	// Accessors
	void setName(string newName);
	void addScore(int score);
	// Mutators
	string getName();
	double getAvg();
	int getNumScores();
	// ETC
	void print();
private:
	string name;
	int numScores;
	int scores[MAX_SCORES];
};