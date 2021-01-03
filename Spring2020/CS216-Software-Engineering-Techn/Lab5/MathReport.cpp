/* course: CS216-001
 * Project: Lab5 (as part of Project 1)
 * Purpose: Provide the implementation of member functions for  the class named MathReport
 * Author: Brennen Green
 */

#include <iostream>
#include <iomanip>
#include "MathReport.h"

using namespace std;

// default constructor
MathReport::MathReport()
{
	numCorrectAnswers = 0;
	numWrongAnswers = 0;
}

// add a Question object into the vector of mathQuestions
// and the response to check with the correct answer: 
//    if response is correct, increase numCorrectAnswers
//    otherwise, increase numWrongAnswers
void MathReport::insert(MathOperations newQuestion, int response)
{
	// If the answer is correct insert it at the front, if wrong push to back
	// This will allow us to know the first numCorrectAnswer indices have a 
	// question that was answered correctly
	if (newQuestion.checkAnswer(response))
	{	
		mathQuestions.insert(mathQuestions.begin(), newQuestion);
		numCorrectAnswers++;
	}
	else 
	{
		mathQuestions.push_back(newQuestion);
		numWrongAnswers++;
	}
}

// return the value of numCorrectAnswers
int MathReport::getNumOfCorrectAnswers() const
{
	return numCorrectAnswers;
}

// return the value of numWrongAnswers
int MathReport::getNumOfWrongAnswers() const
{
	return numWrongAnswers;
}

// generate a brief report:
//   the total number of math problems has been solved;
//   the list of math problems solved with correct answers
//   the total number of correctly answered questions
//   the total number of questions with wrong answers
//   if numCorrectAnswers > numWrongAnswers, display message of "Great job!"
//   otherwise display message of "You will do better next time..."
void MathReport::generateReport()
{
	cout << "REPORT:\n";
	cout << "==============================\n";

	cout << "Number of questions answered: " << mathQuestions.size() << endl;

	cout << "==============================\n";
	// The vector is intetively set up with the correct answers at the start
	for (int i = 0; i < mathQuestions.size(); i++)
	{	
		cout << "Question " << i + 1 << endl;
		mathQuestions[i].print();
		cout << mathQuestions[i].getAnswer();	
		cout << endl;
		cout << endl;
	}
	cout << "==============================\n";
	cout << "Number of correct answers:    " << numCorrectAnswers << endl;
	cout << "Number of wrong answers:      " << numWrongAnswers << endl;

	if (numCorrectAnswers > numWrongAnswers) 
		cout << "Great job!\n";
	else
		cout << "You will do better next time...\n";
}
