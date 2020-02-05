/* 
 * File:   MagicString.cpp
 * Purpose: provide the definition of the MagicString class
 *          using a loop to reverse a sequence; 
 *          using a recursion to decide if a string is a panlindrome;
 *          using a recursion to generate a panlindrome with even number of characters
 * Author: (your name)
 *
 */

#include <iostream>
#include "MagicString.h"

// initialize str with ini_str passing as a parameter
MagicString::MagicString(string ini_str)
{
	str = ini_str;
}

// return the current value of the private data member: str
string MagicString::getString() const
{
	return str;
}

// set the value of str to be the passed in parameter input_str
void MagicString::setString(string input_str)
{
	str = input_str;
}

// return a reversed string. Note that str has not been changed
string MagicString::reverse() const
{
	// Option 1: Use Loop
	string rev_str;
	for (int i=str.length()-1;i>=0;i--)
	{
		rev_str = rev_str + str[i];
	}
	return rev_str;
}

// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
bool MagicString::isPalindrome() const
{
}

// return a palindrome which contains str then followed by
//                     the reverse of str
// for example, if str is "abc", it returns "abccba";
//              if str is "ab", it returns "abba", and so on.
// return value is guaranteed to be a palindrome with even number of characters
// Note that str has not been changed
string MagicString::evenPalindrome() const
{
}

// displays str followed by a new line marker
//              to the standard output
void MagicString::print() const
{
}

