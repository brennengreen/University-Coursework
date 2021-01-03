/* 
 * File:   functions.cpp
 * Course: CS216-00x
 * Project: Lab 10
 * Purpose: provide the function implementations declared in functions.h file
 */

#include <iostream> 
#include <cstdlib>
#include <ctime>
#include "functions.h"

using namespace std;

// Pre: pass in the two parameters: min, max
// Post: return a random number in the range of [min, max]
int rand_in_range(int min, int max)
{
    int random_number = (rand() % ((max - min) +1)) + min;
    return random_number;
}

// A recursive function
// Pre: Assigned(a)&&Assigned(b)
// Post: using recursive way to return (a*b)
int multiplication(int a, int b)
{
    static int fcount = 0; // use a static variable to count the function calling
    fcount++;   // increase fcount by one while calling the function
    cout << endl;
    cout << "Calling the recursive function " << fcount  << " times." << endl;
    int result;
    if (b == 0)     // base case
        result=0;
    else if (b > 0) // first general case
        result= a + multiplication(a, b-1);         
    else 	    //  second general case
        result = multiplication(-a, -b) ;  
    return  result;
}

// pre: pass in three parameters: parm1, parm2, parm3
// Post: sort three parameters in ascending order
//       so that parm1 <= parm2 <= parm3
void sort3(int &parm1,int &parm2, int &parm3) 
{
    if (parm1 > parm2)
    {
        int k = parm1;
        parm1 = parm2;
        parm2 = k;
    }
    if (parm2 > parm3)
    {
        int k = parm2;
        parm2 = parm3;
        parm3 = k;
    }
    if (parm1 > parm2)
    {
        int k = parm1;
        parm1 = parm2;
        parm2 = k;
    }    
} 

// Pre: pass in three parameters: parm1, parm2, parm3
// Post: return the median and mean of three parameters
//       the return pointer points at the median, and the next location stores the mean
int* median_and_mean(int parm1, int parm2, int parm3)
{
    sort3(parm1, parm2, parm3);
    int * result = new int[2];
    result[0] = parm2;
    result[1] = (parm1 + parm2 + parm3) / 3;
    return result;
} 

