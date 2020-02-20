/*
 * course: CS216-00x
 * Project: Lab Assignment 4 (as part of Project 1)
 * Purpose:this program repeatedly allows the user
 *         to practice three basic math operations: + - and *
 *         until the user chooses to quit the program
 *         it generates two single digit integers named num1 and num2 as two operands
 *         it then asks the user to enter the answer to three questions:
 *         (1)num1 + num2; (2)num1 - num2; (3)num1 * num2; 
 *         note that for question (2): if num1 < num2, swap two to make sure the answer is a positive number
 *         it should allow the user to try again if the user input is not a valid integer
 *         if the answer is correct, a message of congratulations should be printed;
 *         if the answer is not correct, a message should be printed showing the correct answer.
 *Author: (Brennen Green)
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>   // for the transform() function
#include <string>
#include "MathOperations.h"

using namespace std;

void collectAnswer(const MathOperations& question);
string toUpper(const string &original);

int main()
{
    int num1;          // The first operand for the operations
    int num2;          // The second operand for the operations
    string choice;     // The user's choice: either answer the question or quit

    // Seed the random number generator.
    srand(time(0));

    cout << "Do you want to practice three basic math operations?" << endl;
    cout << "Press Enter to continue or press  N(o) to quit...";
    getline(cin, choice);
    // covert the string stored in choice into all uppercase
    // by calling toUpper() function 
    choice = toUpper(choice);
    cout << endl;
    while (choice != "N" && choice!= "NO")
    {  
        MathOperations question;
        // Generate two single digit number at the range of [1,9] as the two operands
        num1 = 1 + rand() % 9;
        num2 = 1 + rand() % 9;

        // check if num1 < num2
        // if it is, swap two operands to make sure that the subtraction always gets positive result or zero
        if (num1 < num2)
        {
            int temp = num2;
            num2 = num1;
            num1 = temp;
        }
        question.setOperands(num1, num2);

        // With the same operands: num1 and num2
        // (1)Produce an addition question
        // (2)Produce a substraction question
        // (3)Produce a multiplication question
        question.Addition();
        question.print();
        collectAnswer(question);

        question.Subtraction();
        question.print();
        collectAnswer(question);
        
        question.Multiplication();
        question.print();
        collectAnswer(question);
         
        cout << "Do you want to practice three basic math operations?" << endl;
        cout << "Press Enter to continue or press  N(o) to quit...";
        getline(cin, choice);
        // covert the string stored in choice into all uppercase
        // by calling toUpper() function 
        choice = toUpper(choice);
    }

    cout << "Thank you for practicing Basic Math Operations." << endl;
    return 0;
}

/* pass an object using const call by reference
 * (no copy is made for efficiency and no side-effect, safe to the argument)
 */
void collectAnswer(const MathOperations& question)
{
    int studentAnswer; // The student's answer
    cout << "Please type your answer: " << endl;
    cin  >> studentAnswer;
    
    // your code starts here...
    // if user-input is not a valid integer, allow the user to try again and again...
    // until a valid user input has been captured
    	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid value! Re-Enter Answer: ";	
		cin >> studentAnswer;
	}	      
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the current line before using getline
    // your code ends here.

    // get valid integer input, then check if it is correct
    if (question.checkAnswer(studentAnswer))
        cout << "Congratulations! " << question.getAnswer() << " is the right answer." << endl;
    else
        cout << "Sorry, the correct answer is " << question.getAnswer() << "." << endl;
}

/*
 * Returns the string which transforms each character of the parameter into upper case
 * @param original: the original string
 *  const call by reference (no copy is made for efficiency, safe to the argument)
 * @return a new string which transforms each character of the parameter into upper case
 *  (algorithm header file is needed for the definition of transform function)
 */
string toUpper(const string &original)
{
    string result = original;
    transform(original.begin(), original.end(), result.begin(), ::toupper);
    return result;
}

