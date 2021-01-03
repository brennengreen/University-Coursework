/* 
 * File:   functions.h
 * Course: CS216-00x
 * Project: Lab 10
 * Purpose: provide the function declarations for three functions 
 *          multiplication() 
 *          sort3()
 *          median_and_mean()
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

using namespace std;

// Pre: pass in the two parameters: min, max
// Post: return a random number in the range of [min, max]
int rand_in_range(int min, int max);

// A recursive function
// Pre: Assigned(a)&&Assigned(b)
// Post: using recursive way to return (a*b)
int multiplication(int a, int b);

// pre: pass in three parameters: parm1, parm2, parm3
// Post: sort three parameters in ascending order
//       so that parm1 <= parm2 <= parm3
void sort3(int &parm1,int &parm2, int &parm3); 

// Pre: pass in three parameters: parm1, parm2, parm3
// Post: return the median and mean of three parameters
//       the return pointer points at the median, and the next location stores the mean
int* median_and_mean(int parm1, int parm2, int parm3);

#endif	/* FUNCTIONS_H */

