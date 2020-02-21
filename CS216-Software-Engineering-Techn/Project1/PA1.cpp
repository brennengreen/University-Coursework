#include <iostream>
#include <iomanip>
#include "MathOperations.h"
#include "MathReport.h"

using namespace std;

MathOperations generateAddition();
MathOperations generateSubtraction();
MathOperations generateMultiplication();


int main() {
	int in = 0;
	MathReport report = MathReport();
	while (in != 4) 
	{	
		cout << "Please choose an option  " << endl;
		cout << "=========================" << endl;
		cout << "1. Addition Problem      " << endl;
		cout << "2. Subtraction problem   " << endl;
		cout << "3. Multiplication Problem" << endl;
		cout << "4. Quit Program          " << endl;
		cin >> in;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid Input! Try again: ";
			cin >> in;
		}	
		
		MathOperations op;
		switch (in) 
		{
			case 1:
			{
				// run addition method
				op = generateAddition();
				break;
			}
			case 2:
				// run subtraction method
				op = generateSubtraction();
				break;
			case 3:
				// run multiplication method
				op = generateMultiplication();
				break;
			case 4:
				break;
			default:
				cout << "Invalid Option! Valid Option (1-4)\n";
		}
		
		if (in < 4 & in > 0)
		{
			op.print();
			int answer;
			cin >> answer;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid Input! Try again: ";
				cin >> answer;
			}
			if (op.checkAnswer(answer))
			{
				cout << "Correct!" << endl;
			}
			else
			{
				cout << "Better luck next time!" << endl;
				cout << "Correct answer: " << op.getAnswer() << endl;	
			}
			cout << endl;
			report.insert(op, answer);
		}	
	}
	
	cout << endl;
	report.generateReport();
	return 0;
}

MathOperations generateMultiplication() {
	int numOne = rand() % 100 + 1;
	int scalar = rand() % 9 + 1;
	MathOperations op = MathOperations();
	op.setOperands(numOne, scalar);
	op.Multiplication();
	return op;
}

MathOperations generateSubtraction() {
	int numOne = rand() % 500 + 1;
	int numTwo = rand() % 500 + 1;
	
	MathOperations op = MathOperations();
	if (numOne > numTwo)
	{
		op.setOperands(numOne, numTwo);
	}
	else
	{
		op.setOperands(numTwo, numOne);
	}
	op.Subtraction();
	return op;
}

MathOperations generateAddition() {
	int numOne = rand() % 500 + 1;
	int numTwo = rand() % 500 + 1;
	MathOperations op = MathOperations();
	op.setOperands(numOne, numTwo);
	op.Addition();
	return op;
}
