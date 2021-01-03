/* 
 * File:   Gradebook.cpp
 * Course: CS216-00x
 * Project: Lab Exam
 * Purpose: provide the implementation of the member functions of the class named Gradebook
 *
 * Author: (your name)
 *
 */
#include <iostream>
#include <iomanip>
#include "Gradebook.h"

// default constructor
Gradebook::Gradebook()
{
    // do nothing
    // vector class from STL provide default constructor
}

// return the size of the current vector: scores, 
// which represents current gradebook
int Gradebook::getSize() const
{
	return scores.size();
}

// insert a FinalGrade object, newFG, 
// into the end of the current gradebook
void Gradebook::insert(FinalGrade newFG)
{
	scores.push_back(newFG);
}

// return a FinalGrade object, 
// which holds the maximum score in the current gradebook
FinalGrade Gradebook::getMax() const
{
	FinalGrade max_score = FinalGrade(0);
	for (int i = 0; i < scores.size(); i++)
	{
		if ( scores[i].getScore() > max_score.getScore() )
			max_score = scores[i];
	}
	return max_score;

}

// return a FinalGrade object,
// which holds the minimum score in the current gradebook
FinalGrade Gradebook::getMin() const
{
	FinalGrade min_score = FinalGrade(100);
	for (int i = 0; i < scores.size(); i++)
	{
		if ( scores[i].getScore() < min_score.getScore() )
			min_score = scores[i];
	}
	return min_score;
}

// return the average score among all scores in the current gradebook
double Gradebook::getAverage() const
{
	double total = 0;
	double average;
	for (int i = 0; i < scores.size(); i++)
	{
		total += scores[i].getScore();
	}
	average = total / (double)scores.size();
}

// display the FinalGrade objects in the current gradebook
// display one object at each line
// For example:
// Score: 98.50    Letter Grade: A
void Gradebook::print() const
{

	for (int i = 0; i < scores.size(); i++)
	{
		cout << "Score: " << setw(4) << scores[i].getScore() << "    Letter Grade: " << scores[i].decideLetterGrade() << endl;
	}

}

