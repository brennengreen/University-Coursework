# TRAINS
### By: Brennen Green
### CS315-Spring 2021 Assignment 1


## Program Description

The program receives as input from the command line 3 values,
n the number of trains, c the number of cars each train starts with,
and t the number of iterations for our simulation.

The program will then run t simulations. Each time rolling
an n-sided die to decide which train will be the "donor". 
The program will then flip a 2-sided die to decide whether
the donor will have a car taken from the front or the back. 
Then once again rolls an n-sided die to decide which 
train will receive the car at its front.

The simulation will continue until any one train is empty 
or t steps has been reached.

The program will output running statistics at every step
as well as a end-of-simulation report which includes
the train with the max value.

Usage: ./trains [num trains] [num cars] [num iterations]

Example Usage: ./trains 5 6 1000

Number of trains = 5
Number of cars per train at start = 6
Number of iterations = 1000



## Compilation

Compilation made easy via the Makefile.

Just type make in the command line. It'll even
run it once for you and pipe output to output.txt

## Extra Credit Information

For extra credit I did several things. 

First I created a handy visualization of a train. The print_train()
function not only handles printing the value of a train but also a
car-by-car description of the train.

Second, I did running statistics that can be reviewed in the output.
You can see what the value of the trains are, how they are constructed,
and the average value of all the trains at that iteration.



## Function and Structure Documentation


### Train
Train: Used to represent the (start of) trains
Node * front: pointer to the first car in the train
Node * rear: pointer to the last car in the train (can )
int cars: The number of cars in a train
(side note) value: the total value of a car which is the sum of p*s
    (position of each car * size) 

### Node
Node: Used to represent an individual car of a train
Node * next: pointer to the next train (nullptr if last train)
Node * next: pointer to previous train (nullptr if first train)
int size: And integer which stores the size of a train (fixed value)
(side note) value: the value of a car is its position (index) * size

### main()
int main(int argc, char ** argv)
Input: a stream of arguments from command
Output: Simulation results
Returns: 0 if successful, error otherwise

### simulate()
void simulate(int iterations, Train ** train_heads, int num_trains)
Input: number of iterations, the train array, and number of trains
Output: Running simulation statistics
Returns: Nothing

### print_stats()
void print_stats(Train ** trains, int num_trains)
Input: the train array, and number of trains
Output: Final max statistics
Returns: Nothing

### make_car()
Node * make_car(int size, Node * next, Node * previous)
Input: size of car, next car, previous car
Output: No output
Returns Pointer to location car was allocated at

### make_train()
Train * make_train(int num_cars)
Input: number of cars in the train
Output: No output
Returns Pointer to location train was allocated at

### find_max()
Train * find_max(Train ** trains, int num_trains)
Input: train array, number of trains (for indexing)
Output: No output
Returns pointer to max_train location

### flip_n()
int flip_n(int n, int random_num)
Input: n sides of the die, random number from stream
Output: No output
Returns result of die roll

### is_train_empty()
int is_train_empty(Train * train_head)
Input: train to check
Output: No output
Returns 1 if empty, 0 otherwise

### pop_from_front()
int pop_from_front(Train * train_head)
Input: train to pop
Output: No output
Returns size of car popped

### pop_from_rear()
int pop_from_rear(Train * train_head)
Input: train to pop
Output: No output
Returns size of car popped

### transfer_car()
void transfer_car(Train * donor, Train * receiver, int front_or_rear)
Input: donor train, receiver train, 1 for rear, 0 for front
Output: No output
Returns Nothing

### update_train_value()
void update_train_value(Train * train_head)
Input: train to update
Output: No output
Returns Nothing

### insert_node_at_front()
void insert_node_at_front(Train * train_head, int size)
Input: train to update, number of cars
Output: No output
Returns Nothing

### print_train()
void print_train(Train * train_head)
Input: train to print
Output: No output
Returns Nothing