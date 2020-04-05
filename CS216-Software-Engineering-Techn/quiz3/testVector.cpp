/*
 * course: CS216-00x
 * Project: Demonstration of using GDB
 * Purpose: Provide some operations on vectors 
 *          Help students deeply understand the code      
 * Author: (your name)
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dothis_option1(vector<int>& v);

vector<int> dothis_option2(const vector<int>& v);

int dothat(const vector<int>& v); 

int main()
{
    const int SIZE = 14;
    int myArray[SIZE] = {2, 2, 2, 2, 3, 3, 5, 5, 7, 11, 11, 11, 13, 13};
    int yourArray[SIZE] = {2, 2, 2, 2, 3, 3, 5, 5, 7, 13, 13, 13, 13, 13};
    
    cout << "The original myvector: " << endl;
    vector<int> myVector, yourVector;
    for (int i = 0; i < SIZE; i++)
    {
        myVector.push_back(myArray[i]);
        cout << " " << myVector[i];

        yourVector.push_back(yourArray[i]);
    }
    cout << endl;

    // check what the function, dothat(), returns
    int myReturn = dothat(myVector);
    cout << "The return value from calling dothat function on myVector is: " << myReturn << endl;

    int yourReturn = dothat(myVector);

    // check what this function, dothis_option1() does
    // pass in myVector as the argument
    // note it is call by reference
    dothis_option1(myVector);
    cout << "After calling dothis on myVector: " << endl;
    for (int i = 0; i < myVector.size(); i++)
        cout << " " << myVector[i];
    cout << endl;

    // check what this function, dothis_option2() does
    // passing in yourVector as the argument
    dothis_option2(yourVector);

    return 0;
}

void dothis_option1(vector<int>& v)
{
	int current = v[0];
    vector<int> result;
    result.push_back(current);
    for (int i=1; i < v.size(); i++)
    {

        if (v[i] != current)
        {
            current = v[i];
            result.push_back(current);
        }
    }
}

vector<int> dothis_option2(const vector<int>& v)
{
    stack<int> stk;
    stk.push(v[0]);

    for (int i=1; i < v.size(); i++)
    {
        if (v[i] != stk.top())
            stk.push(v[i]);
    }

    vector<int> result(stk.size());

    for (int i = stk.size()-1; i>=0; i--)
    {
        result.at(i) = stk.top();
        stk.pop();
    }
    return result;    
}

int dothat(const vector<int>& v)
{
    int maxlength = 0;
    int curr_length = 0;
    for (int i=0; i < v.size(); i++)
    {
        if (v[i]== v[i+1])
        {
            curr_length++;
        }
        else
        {
            if (maxlength < curr_length)
                maxlength = curr_length;
            curr_length = 0;
        }
    }

    if (maxlength == 0)
        return 1;
    else
        return maxlength;
}
