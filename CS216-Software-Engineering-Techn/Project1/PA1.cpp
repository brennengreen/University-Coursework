#include <iostream>
#include <iomanip>
#include "MathOperations.h"
#include "MathReport.h"

using namespace std;

MathOperations generateAddition();

int main() {
	int in = 0;
	while (in != 4) 
	{	
		cout << "Please choose an option  " << endl;
		cout << "=========================" << endl;
		cout << "1. Addition Problem      " << endl;
		cout << "2. Subtraction problem   " << endl;
		cout << "3. Multiplication Problem" << endl;
		cout << "4. Quit Program          " << endl;
		cin >> in;
		// TODO: Write cin.fail() method
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid Input! Try again: ";
			cin >> in;
		}	
		
		// TODO: Put all into conditional loop if in < 4
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
				break;
			case 3:
				// run multiplication method
				break;
			case 4:
				break;
			default:
				cout << "Invalid Input";
		}
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
	}	


	return 1;
}

MathOperations generateAddition() {
	int numOne = rand() % 500 + 1;
	int numTwo = rand() % 500 + 1;
	MathOperations op = MathOperations();
	op.setOperands(numOne, numTwo);
	op.Addition();
	return op;
}
