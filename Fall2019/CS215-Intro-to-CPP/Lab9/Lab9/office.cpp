#include "office.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*==========================================================================
							STANDARD CONSTRUCTOR
					Initializes everything with empty values
============================================================================*/
office::office()
{
	officeName = "";
	numCandidates = 0;
	for (int i = 0; i < MAX_CANDIDATES; i++)
	{
		candidates[i] = candidate();
	}
}

void office::setOfficeName(string n)
{
	officeName = n;
}

void office::addCandidate(int ballotNum, string party, string name)
{
	if (numCandidates == MAX_CANDIDATES)
	{
		cout << "office::addCandidate: max candidates exceeded" << endl;
	}
	else
	{
		candidate& currCandidate = candidates[numCandidates];
		currCandidate.setBallotNum(ballotNum);
		currCandidate.setParty(party);
		currCandidate.setName(name);
		numCandidates++; // Increments to next empty candidate;
	}
}

string office::getOfficeName()
{
	return officeName;
}

int office::getNumCandidates()
{
	return numCandidates;
}

candidate office::getCandidate(int idx)
{
	if (idx >= numCandidates || idx < 0)
	{
		return candidate();
	}
	else
	{
		return candidates[idx];
	}
}

void office::doVote()
{
	int ballotNum = -1;
	while (ballotNum <= 0 || ballotNum > numCandidates)
	{
		cout << "Enter ballot number for candidate: ";
		cin >> ballotNum;
		if (ballotNum <= 0 || ballotNum > numCandidates)
		{
			cout << "Invalid ballot number! Enter a number between 1 and " << numCandidates << endl;
		}
	}
	candidate& chosenCandidate = candidates[ballotNum - 1];
	chosenCandidate.addVote();
	cout << "You voted for " << chosenCandidate.getName() << ". Thank you!" << endl;
}

void office::print()
{
	cout << "Election for " << officeName << endl;
	for (int i = 0; i < numCandidates; i++)
	{
		candidates[i].print();
	}
}

void office::printReport()
{
	cout << "Report of Election for " << officeName << endl;
	for (int i = 0; i < numCandidates; i++)
	{
		candidate& currCandidate = candidates[i];
		cout << setw(2) << right << currCandidate.getBallotNum() << " ";
		cout << setw(3) << left << currCandidate.getParty() << " ";
		cout << setw(15) << left << currCandidate.getName() << " ";
		cout << setw(4) << right << currCandidate.getVotes();
		cout << endl;
	}
}
