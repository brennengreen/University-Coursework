/*
* QUEUE CLASS
* Handles operations to maintain a queue to for breadth first search.
*/

#ifndef PERSON_QUEUE_H
#define PERSON_QUEUE_H

#include <vector>

class Queue {
    public:
        Queue() {}
        void enqueue(int p);
        int dequeue();
        bool is_empty() {
            return (persons.size() == 0);
        }
    private:
        std::vector<int> persons;
};

/*
* Queue::enqueue(int p)
* Input: An integer to add to the queue (represents a person).
*/
void Queue::enqueue(int p) {
    persons.push_back(p);
} // enqueue

/*
* Queue::dequeue()
* Returns: An integer from the front of the queue.
*/
int Queue::dequeue() {
    int first_person = persons[0];
    persons.erase(persons.begin());
    return first_person;
} /// dequeue

#endif