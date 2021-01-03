/* 
 * File:   MagicString.h
 * Purpose: provide the declaration of the MagicString class
 *          to demonstrate some basic string manipulations
 * Author: Pike
 *
 */

#ifndef MAGICSTRING_H
#define	MAGICSTRING_H

#include <string>

using namespace std;

class MagicString
{
    public:
        // constructor: initialize str with ini_str passing as a parameter
        MagicString(string ini_str);

        // return the current value of the private data member: str
        string getString() const;

        // set the value of str to be the passed in parameter input_str
        void setString(string input_str);

        // return a reversed string. 
	// Note that str has not been changed
        string reverse() const;

        // return true if str is a palindrome
        // otherwise return false
        // A palindrome is defined as a sequence of characters which reads the same backward as forward
        bool isPalindrome() const;

        // return a palindrome which contains str then followed by
        //                     the reverse of str
        // for example, if str is "abc", it returns "abccba";
        //              if str is "ab", it returns "abba", and so on.
        // return value is guaranteed to be a palindrome with even number of characters
        // Note that str has not been changed
        string evenPalindrome() const;

        // displays str, followed by a new line marker, 
        //               to the standard output
        void print() const;

    private:
        string str;
};

#endif	/* MAGICSTRING_H */

