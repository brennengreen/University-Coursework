/*
 * Course: CS216-00x
 * Project: Lab 10
 * Purpose: to demonstrate the following:
 *         1. call stack while calling a recursive function
 *         2. call by value v.s. call by reference
 *         3. variable scope and variable allocation
 * 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.h"

using namespace std;

// declare global variable (constant only)
// set up the integer range of [MIN, MAX]
const int MIN = -9;
const int MAX = 9;

int main()
{
    int num1, num2, num3;

    // generate three random numbers in the range of [MIN, MAX]
    srand(time(0));

    num1 = rand_in_range(MIN, MAX);
    num2 = rand_in_range(MIN, MAX);
    num3 = rand_in_range(MIN, MAX);

    // display num1, num2 and num3 generated from random number generator
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    cout << "num3: " << num3 << endl;

    // calling multiplication() function
    cout << num1 << " * " << num2 << " = " << multiplication(num1, num2) << endl;
    cout << num2 << " * " << num1 << " = " << multiplication(num2, num1) << endl;    

    // calling sort3() function
    sort3(num1, num2, num3);
    cout << "After calling sort3() function..." << endl;
    cout << "num1: " << num1 << endl; 
    cout << "num2: " << num2 << endl; 
    cout << "num3: " << num3 << endl;

    // calling median_and_mean() function
    int* ptr = NULL;
    ptr = median_and_mean(num1, num2, num3);
    cout << "The median among three numbers is: "<< ptr[0] << endl;
    cout << "The mean among three numbers is: "<< ptr[1] << endl;
    delete [] ptr;
    ptr = NULL;

    return 0; 
}

