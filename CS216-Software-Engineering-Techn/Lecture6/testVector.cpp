/*
 * Course: CS216-00x
 * Project: Demo
 * Purpose: this program demonstrates how to use vector to solve problems
 * 
 * Author: (your name)
 */

#include <iostream>
#include <vector>

using namespace std;

// return a vector object which contains elements being doubled from pass-in parameter
vector<int> double_elements(const vector<int>& in_vector);

int main()
{
    vector<int> myvector;
    cout << "the size of myvector is: " << myvector.size() << endl;
    myvector.push_back(2);
    myvector.push_back(3);
    myvector.push_back(5);
    myvector.push_back(7);
    myvector.push_back(11);
    myvector.push_back(13);
    
    // display elements in the vector
    for  (int i = 0; i < myvector.size(); i++)
        cout << myvector[i] << "\t";
    cout << endl;
    cout << "The new vector contains: " << endl;
    vector<int> yourvector = double_elements(myvector);

    for  (int i = 0; i < yourvector.size(); i++)
        cout << yourvector[i] << "\t";
    cout << endl;

    return 0;
}

vector<int> double_elements(const vector<int>& in_vector)
{
    vector<int> result;
    for (int i=0; i < in_vector.size(); i++)
    {
        result.push_back(in_vector.at(i) * 2);
    }

    return result;
}
