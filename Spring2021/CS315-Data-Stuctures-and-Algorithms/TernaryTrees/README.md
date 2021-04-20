# TREES
### By: Brennen Green
### CS315-Spring 2021 Assignment 2


## Program Description

The program receives as input from the command line 1 value,
n, the number of lines to read as input to populate the tree

The program then constructs a tree with these n values and
prints out the appropriate in order representation

Usage: ./ternary [num lines] (expects random number generator piped to stream)

Example Usage: ./randGen.pl 49 10000 | ./ternary 1000

Number of trains = 100

## Compilation

Compilation made easy via the Makefile.

Just type make in the command line. It'll even
run it once for you and pipe output to output.txt

## Extra Credit Information

Made a ternary search routine in the function search_for(), added
a small section onto the end of the output of the program that picks
a random number from the RNG and searches for it in the tree

## Function and Structure Documentation

int main(int argc, char ** argv)
Input: a stream of arguments from command line
Description: Main control flow of the program
Output:
Returns: 0 if successful, error otherwise

Node * init_tree()
Input: 
Description: Used to initialize an empty ternary tree
Output: 
Returns: An empty ternary tree

void insert_value(Node * tree, int value)
Input: a tree root and a value to insert
Description: Insets a given value at the appropriate place in tree
Output: 
Returns: 

int is_tree_empty(Node * tree)
Input: the root of a tree
Description: Checks if a given tree is currently empty
Output: 
Returns: 1 if empty, 0 otherwise

void inorder_traversal(Node * root)
Input: the root of a tree
Description: Traverses a tree in order and prints the representation
Output: The in order representation of the tree
Returns: 

int get_next_num()
Input: 
Description: Gets the next number from random number generator
Output: 
Returns: int representation of next random number

int search_for(Node * tree, int value)
Input: the root of a tree, search value
Description: search for a value in the tree
Output: 
Returns: 1 if found, 0 otherwise
