#include "student.h"
#include <iostream>
#include <string>

using namespace std;

student::student() 
{
	name = "";
	numScores = 0;
	for (int i = 0; i < MAX_SCORES; i++) {
		scores[i] = 0;
	}
	cout << "Constructed!\n";
}

//===========================================================================
//								student::setName()
//===========================================================================
void student::setName(string newName)
{
	name = newName;
}

//===========================================================================
//								student::addScore()
//===========================================================================
void student::addScore(int score)
{
	if (numScores == 10)
	{
		cout << "MAX SCORES exceeded!\n";
	}
	else
	{
		scores[numScores] += score;
		numScores += 1;
	}
}

//===========================================================================
//								student::getName()
//===========================================================================
string student::getName()
{
	return name;
}

//===========================================================================
//								student::getAvg()
//===========================================================================
double student::getAvg()
{
	if (numScores == 0)
	{
		return 0.0;
	} 
	else {
		double totalScore = 0.0;
		for (int i = 0; i < numScores; i++)
		{
			totalScore += scores[i];
		}
		return (totalScore / double(numScores));
	}
}

//===========================================================================
//								student::getNumScores()
//===========================================================================
int student::getNumScores()
{
	return numScores;
}

//===========================================================================
//								student::print()
//===========================================================================
void student::print()
{
	cout << "Name=" << name << " Avg=" << getAvg() << " #scores=" << numScores \
		<< " scores=";
	for (int i = 0; i < numScores; i++) {
		cout << scores[i] << " ";
	}
	cout << endl;
}
