#ifndef KEY_VALUE_PAIR_H
#define KEY_VALUE_PAIR_H

#include <stdio.h>
#include <string>

/*
* (Key, Value) Pair Implementation
*/
class Pair {
    public:
        Pair() {
            this->key = std::string();
            this->value = -1;
            this->empty = 1;
        } // Empty Constructor
        Pair(std::string key, int value) {
            this->key = key;
            this->value = value;
            this->empty = 0;
        } // Non Empty Constructor


        // Overload Relational Operators
        bool operator==(Pair obj) {
            return (this->value == obj.get_value());
        }
        bool operator!=(Pair obj) {
            return (this->value != obj.get_value());
        }
        bool operator>=(Pair obj) {
            return (this->value >= obj.get_value());
        }
        bool operator<=(Pair obj) {
            return (this->value <= obj.get_value());
        }
        bool operator<(Pair obj) {
            return (this->value < obj.get_value());
        }
        bool operator>(Pair obj) {
            return (this->value > obj.get_value());
        }

        // Getters
        std::string get_key() { return key; }
        int get_value() { return value; } 

        int is_empty() { return empty; }

        // Setters
        void set_key(std::string k) { 
            key = k; 
            if (empty) 
                empty = !empty;
        } // Set the key value
        void set_value(int v) { value = v; } // Set the value

        void print() {
            std::cout << "{ Key: " << key << ", Value: " << value << " }";
        } // Print the Node
    private:
        std::string key;
        int value;
        int empty;
};



#endif