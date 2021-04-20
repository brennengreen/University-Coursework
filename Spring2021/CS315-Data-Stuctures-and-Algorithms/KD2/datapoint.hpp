#ifndef DATAPOINT
#define DATAPOINT

#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <vector>

/* DATAPOINT CLASS
*  - Usage: Used to store a datapoint of varying dimensions
*  and provides basic functionality to work with the datapoint.
*/
class DataPoint {
    public:
        DataPoint() {};

        int& operator[](int index);
        
        void print();
        void add_coord(int coord) { coords.push_back(coord); }
        void print_in_place();

        int size();
    private:
        std::vector<int> coords;

};

/*
* int& DataPoint::operator[](int index)
* Input: index
* Output: 
* Returns: Value at that index.
*/
int& DataPoint::operator[](int index) {
    return coords[index];
}

/*
* void DataPoint::print()
* Input: 
* Output: String representation with trailing newline.
* Returns: 
*/
void DataPoint::print() {
    for (size_t i = 0; i < coords.size(); i++)
        printf("%-4d ", coords[i]);
    printf("\n");
}

/*
* void DataPoint::print_in_place()
* Input: 
* Output: String representation without trailing newline.
* Returns: 
*/
void DataPoint::print_in_place() {
    for (size_t i = 0; i < coords.size(); i++)
        printf("%-4d ", coords[i]);
}

/*
* int DataPoint::size()
* Input: 
* Output: 
* Returns: The number of dimensions in the datapoint.
*/
int DataPoint::size() {
    return (int)coords.size();
}

#endif