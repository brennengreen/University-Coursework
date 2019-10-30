#include "student.h"
#include <iostream>
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

void student::setName(string newName)
{
	name = newName;
}

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

string student::getName()
{
	return name;
}

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

int student::getNumScores()
{
	return numScores;
}

void student::print()
{
	cout << "Name=" << name << " Avg=" << getAvg() << " #scores=" << numScores \
		<< " scores=";
	for (int i = 0; i < numScores; i++) {
		cout << scores[i] << " ";
	}
	cout << endl;
}
