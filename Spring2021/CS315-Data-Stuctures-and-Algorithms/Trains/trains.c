/*   trains.c                                           */
/*   Brennen Green                                      */
/*   CS315 Spring 2021 Assignment 1                     */
/*   Usage: ./trains num_trains num_cars num_iterations */
/*   Outputs statistics of every iteration and report   */
/*   Refer to README for Program Description!           */

#include <stdio.h>
#include <stdlib.h>

/* 
* Train: Used to represent the (start of) trains
* Node * front: pointer to the first car in the train
* Node * rear: pointer to the last car in the train (can )
* int cars: The number of cars in a train
* (side note) value: the total value of a car which is the sum of p*s
*     (position of each car * size) 
*/
typedef struct Train {
    struct Node * dummy;
    int cars;
    int value;
} Train;

/* 
* Node: Used to represent an individual car of a train
* Node * next: pointer to the next train (nullptr if last train)
* Node * next: pointer to previous train (nullptr if first train)
* int size: And integer which stores the size of a train (fixed value)
* (side note) value: the value of a car is its position (index) * size
*/
typedef struct Node {
    struct Node * next;
    struct Node * previous;
    int size;
} Node;

/*
* Prototypes: Check declaration or README for information
*/

Node * make_car(int size, Node * next, Node * previous);

Train * make_train(int num_cars);
Train * find_max(Train ** trains, int num_trains);

int flip_n(int n, int random_num);
int is_train_empty(Train * train_head);
int pop_from_front(Train * train_head);
int pop_from_rear(Train * train_head);

void simulate(int iterations, Train ** train_heads, int num_trains);
void transfer_car(Train * donor, Train * receiver, int front_or_rear);
void update_train_value(Train * train_head);
void insert_node_at_front(Train * train_head, int size);
void print_train(Train * train_head);
void print_stats(Train ** trains, int num_trains);

/*
* int main(int argc, char ** argv)
* Input: a stream of arguments from command line
* Output: Simulation results
* Returns: 0 if successful, error otherwise
*/
int main(int argc, char *argv[]) {
    /* strtol: A stdlib function which converts a c-string to integer. 
    *  Ignoring the middle parameter thanks to our specifications.
    *  parameter is the base srtol(char * str, char **endptr, int base)
    */
    int n = strtol(argv[1], NULL, 10); 
    int c = strtol(argv[2], NULL, 10); 
    int t = strtol(argv[3], NULL, 10); 
    if (n == 0 || n < 0 || c == 0 || c < 0 || t == 0 || t < 0) { 
        // Validate value of all parameters (nonnegative integer great than 0)
        printf("Input Error: All input values must be greater than 0." 
                    "Values given: %d %d %d\n", n, c, t);
        return 1; // input error
    } // parse the value n, c, and t from command line

    Train * train_heads[n]; // store the n trains in a n-size array
    // initiate array with n trains
    for (int current_train = 0; current_train < n; current_train++) {
        Train * new_train = make_train(current_train);
        for (int current_car = 0; current_car < c; current_car++) {
            insert_node_at_front(new_train, c - current_car); // insert car 
        }
        update_train_value(new_train);
        train_heads[current_train] = new_train;
        print_train(train_heads[current_train]);
    } // set up all the trains properly
    
    printf("\n===================== STARTING SIMULATION =====================\n");
    simulate(t, train_heads, n);

    printf("\n===================== SIMULATION RESULTS =====================\n");
    print_stats(train_heads, n);

    return 0; // successful execution
} // main

/*
* void simulate(int iterations, Train ** train_heads, int num_trains)
* Input: number of iterations, the train array, and number of trains
* Output: Running simulation statistics
* Returns: Nothing
*/
void simulate(int iterations, Train ** train_heads, int num_trains) {
        // Run through t steps of the simulation
    int empty_flag = 0;
    for (int iteration = 0; iteration < iterations; iteration++) {
        if (empty_flag) break; // Some train is empty, end simulation

        // Parse Randomness
        char * line = NULL;
        size_t len = 0;

        getline(&line, &len, stdin);
        int donor_train_num = flip_n(num_trains, strtol(line, NULL, 10));

        getline(&line, &len, stdin);
        int front_or_rear = flip_n(2, strtol(line, NULL, 10)); // 1 front 2 back

        getline(&line, &len, stdin);
        int accepting_train_num = flip_n(num_trains, strtol(line, NULL, 10));

        free(line); // free memory used to store line just to be safe

        // Handle Transfer //
        Train * donor_train = train_heads[donor_train_num];
        Train * receiver_train = train_heads[accepting_train_num];
        transfer_car(donor_train, receiver_train, front_or_rear);
        //

        // Print Statistics //
        printf("========================================================\n");
        printf("ITERATION %d: Train %d donated from the %s to train %d\n",
                iteration+1, donor_train_num+1, front_or_rear ? "rear" : "front",
                accepting_train_num+1); // +1 for human readability
        
        int running_value = 0;
        for (int current_train = 0; current_train < num_trains; current_train++) {
            empty_flag = (is_train_empty(train_heads[current_train]) && empty_flag == 0) ? 1 : empty_flag;
            update_train_value(train_heads[current_train]);
            print_train(train_heads[current_train]);
            running_value += train_heads[current_train]->value;
        } // Update values and print statistics
        printf("AVERAGE TRAIN VALUE: %d\n", running_value / num_trains);
        printf("========================================================\n");
    } // run the simulation
} // simulate

/*
* void print_stats(Train ** trains, int num_trains)
* Input: the train array, and number of trains
* Output: Final max value statistics
* Returns: Nothing
*/
void print_stats(Train ** trains, int num_trains) {
    Train * max_train = find_max(trains, num_trains);
    printf("Max Train: ");
    print_train(max_train);

} // print_stats

/*
* Node * make_car(int size, Node * next, Node * previous)
* Input: size of car, next car, previous car
* Output: No output
* Returns Pointer to location car was allocated at
*/
Node * make_car(int size, Node * next, Node * previous) {
    Node * answer = (Node * ) malloc(sizeof(Node));
    answer->size = size;
    answer->next = next;
    answer->previous = previous;
    return answer;
} // make_car

/*
* Train * make_train(int num_cars)
* Input: number of cars in the train
* Output: No output
* Returns Pointer to location train was allocated at
*/
Train * make_train(int num_cars) {
    Train * answer = (Train *) malloc(sizeof(Train));
    Node * answer_dummy = make_car(-1, NULL, NULL);
    answer_dummy->next = answer_dummy;
    answer_dummy->previous = answer_dummy;
    answer->dummy = answer_dummy;
    answer->cars = num_cars;
    return answer;
} // make_train

/*
* Train * find_max(Train ** trains, int num_trains)
* Input: train array, number of trains (for indexing)
* Output: No output
* Returns pointer to max_train location
*/
Train * find_max(Train ** trains, int num_trains) {
    int max_value = -111; // sentinel value
    Train * max_train = NULL;
    for (int i = 0; i < num_trains; i++) {
        if (trains[i]->value > max_value) {
            max_value = trains[i]->value;
            max_train = trains[i];
        } // figures if train is greater max_value
    } // iterates over trains
    return max_train;
} // find_max

/*
* int flip_n(int n, int random_num)
* Input: n sides of the die, random number from stream
* Output: No output
* Returns result of die roll
*/
int flip_n(int n, int random_num) {
    int result = (random_num % n) + 1; // random num in [1, n]
    return (result - 1); // [0, n-1]
} // flip n sided die

/*
* int is_train_empty(Train * train_head)
* Input: train to check
* Output: No output
* Returns 1 if empty, 0 otherwise
*/
int is_train_empty(Train * train_head) {
    return (train_head->dummy->next == train_head->dummy); // 1 if empty
} // is_train_empty

/*
* int pop_from_front(Train * train_head)
* Input: train to pop
* Output: No output
* Returns size of car popped
*/
int pop_from_front(Train * train_head) {
    int size = train_head->dummy->next->size;
    train_head->dummy->next = train_head->dummy->next->next;
    train_head->dummy->next->previous = train_head->dummy;
    return size;
} // pop_from_front

/*
* int pop_from_rear(Train * train_head)
* Input: train to pop
* Output: No output
* Returns size of car popped
*/
int pop_from_rear(Train * train_head) {
    int size = train_head->dummy->previous->size;
    train_head->dummy->previous->previous->next = train_head->dummy;
    train_head->dummy->previous = train_head->dummy->previous->previous;
    return size;
} // pop_from_rear

/*
* void transfer_car(Train * donor, Train * receiver, int front_or_rear)
* Input: donor train, receiver train, 1 for rear, 0 for front
* Output: No output
* Returns Nothing
*/
void transfer_car(Train * donor, Train * receiver, int front_or_rear) {
    int donation_size;
    if (front_or_rear) {
        donation_size = pop_from_rear(donor); // 1 = rear
    } else {
        donation_size = pop_from_front(donor); // 0 = front
    }
    insert_node_at_front(receiver, donation_size);
} // transfer_car

/*
* void update_train_value(Train * train_head)
* Input: train to update
* Output: No output
* Returns Nothing
*/
void update_train_value(Train * train_head) {
    if (is_train_empty(train_head)) {
        train_head->value = 0;
    } else {
        train_head->value = 0;
        int position = 1;
        Node * current = train_head->dummy->next;
        while (current->next != train_head->dummy->next) {
            train_head->value += (position * current->size);
            current = current->next;
            position++;
        } // traverse the train
    } // value is 0 if empty
} // update_train_value

/*
* void insert_node_at_front(Train * train_head, int size)
* Input: train to update, number of cars
* Output: No output
* Returns Nothing
*/
void insert_node_at_front(Train * train_head, int size) {
    Node *answer = make_car(size, train_head->dummy->next, train_head->dummy);
    if (is_train_empty(train_head)) {
        // Train is empty
        train_head->dummy->next = answer;
        train_head->dummy->previous = answer;
        answer->next = train_head->dummy;
    } else {
        answer->next->previous = answer;
        train_head->dummy->next = answer;
    }
    
} // insert_node_at_front

/*
* void print_train(Train * train_head)
* Input: train to print
* Output: No output
* Returns Nothing
*/
void print_train(Train * train_head) {
    Node * current = train_head->dummy->next; // dont care about list head
    while (current->next != NULL && current->next->size != -1) {
        printf("|| %d ||->", current->size);
        current = current->next;
    } // traverse over train
    printf("|| %d || Value: %d\n", current->size, train_head->value);
} // print_list