#pragma once
#include "candidate.h"
#include <string>

using namespace std;

const int MAX_CANDIDATES = 5;

class office
{
public:
	office();
	// Mutators
	void setOfficeName(string n);
	void addCandidate(int ballotNum, string party, string name); // 1, "SLR", "Corey"
	// Accessors
	string getOfficeName();
	int getNumCandidates();
	candidate getCandidate(int idx);
	// ETC
	void doVote();
	void print();
	void printReport();

private:
	string officeName;
	candidate candidates[MAX_CANDIDATES];
	int numCandidates;

};