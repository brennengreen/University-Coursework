/* 
 * File: smartReverse.cpp
 * Purpose: provide the implementation of the smartReverse class
 *
 * Author: Brennen Green
 *
 */

#include <stack>
#include "smartReverse.h"

// default constructor
smartReverse::smartReverse()
{
    // you do not really need to do anything
    // since string class provides default constructor 
    // to initialize the object to empty string
}

// constructor: initialize str with ini_str passing as a parameter
smartReverse::smartReverse(string ini_str)
{
	str = ini_str;
}

// return the current value of the private data member: str
string smartReverse::getString() const
{
	return str;
}

// set the value of str to be the passed in parameter input_str
void smartReverse::setString(string input_str)
{
	str = input_str;
}

// return a reversed string from str
// using a loop to implement
// Note that str has not been changed
string smartReverse::rev() const
{
	string str_copy = str;
	int mid = str_copy.length() / 2;
	for (int i = 0; i < mid; i++)
	{
		char buf = str_copy[i];
		str_copy[i] = str_copy[(str_copy.length()-1)-i];
		str_copy[(str_copy.length()-1)-i] = buf;
	}
	
	return str_copy;
}

string smartReverse::rev_recursive() const
{
	if (str.length() <= 1)
		return str;
	char first_char = str[0];
	smartReverse remainder(str.substr(1));
	return remainder.rev_recursive() + first_char;
}

// return a reversed string
//from str
// using a stack to implement
// Note that str has not been changed
string smartReverse::rev_stack() const
{
	stack<char> st;
	string new_string = str;
	for (int i = 0; i < str.length(); i++)
	{
		st.push(str[i]);
	}

	for (int i =0;i < str.length(); i++)
	{
		new_string[i] = st.top();
		st.pop();
	}
	return new_string;
}


