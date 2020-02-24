/* course: CS216-002
 * Project: Lab 4 (as part of Project 1)
 * Purpose: to define the class named MathOperations
 * Author: Brennen Green
 */
#include <iostream>
#include <iomanip>
#include "MathOperations.h"

// default constructor    
MathOperations::MathOperations()
{
}

// set the private data members: operand1 and operand2
// to op1 and op2 respectively
void MathOperations::setOperands(int op1, int op2)
{
	operand1=op1;
	operand2=op2;
}


// read the current value of the private data member: current operator
char MathOperations::getOperator() const
{
	return theoperator;
}

// return the value of the data member: answer
int MathOperations::getAnswer() const
{
	return answer;
}

// set theoperator to '+'
// apply the addition operation to operand1 and operand2
// set the answer equal to operand1 + operand2
void MathOperations::Addition()
{
	theoperator = '+';
	answer = operand1 + operand2;
}

// set theoperator to '-'
// apply the subtraction operation to operand1 and operand2
// set the answer equal to operand1 - operand2
void MathOperations::Subtraction()
{
	theoperator = '-';
	answer = operand1 - operand2;
}

// set theoperator to '*'
// apply the multiplication operation to operand1 and operand2
// set the answer equal to operand1 * operand2
void MathOperations::Multiplication()
{
	theoperator = '*';
	answer = operand1 * operand2;
}

// if answer == response, it returns true
// otherwise it returns false
bool MathOperations::checkAnswer(int response) const
{
	if (answer == response)
		return true;

	return false;
}

//display the question in the format described in the problem statement
// for example:
//    135
//  +  78
//  _____
//
void MathOperations::print() const
{

	cout << setw(5) << right << operand1 << endl;
	cout << theoperator << setw(4) << right << operand2 << endl;
	cout << "_____" << endl;
}
