#ifndef HASH_TABLE_QUAD_H
#define HASH_TABLE_QUAD_H

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

#include "key_value_pair.h" // Custom (Key, Value) class

/*
* Hash Table Implementation
*/
class HashTableQuad { 
    public:
        HashTableQuad(int table_size) { 
            TABLE_SIZE = table_size;
            table = std::vector<Pair>(table_size, Pair());
            comparisons = 0;
        };
        int comparisons; // Fine to be public

        void insert(std::string key);
        void increment(std::string key);
        int find(std::string key);

    private:
        int TABLE_SIZE;
        std::vector<Pair> table; // Table of Key, Value pairs

        int search(std::string key);
        int quadratic_probing(int hash);
        int hash_function(std::string key_string);
        int check_collision(int hash);
        int get_hash(std::string key);


}; // HashTableQuad

/*
* int HashTableQuad::hash_function(std::string key_string)
* Input: A key string
* Output: 
* Returns: An integer hash value
*/
int HashTableQuad::hash_function(std::string key_string) {
    int hash_val = 0; // Ascii based hash
    for (char ch : key_string) {
        hash_val += ch;
    } // Hash function implementation based off Weiss textbook

    return (hash_val % TABLE_SIZE);
} // hash_function

/*
* int HashTableQuad::check_collision(int hash)
* Input: An integer hash value
* Output: 
* Returns: 1 if there is a collision, 2 otherwise
*/
int HashTableQuad::check_collision(int hash) {
    if (table[hash].is_empty()) {
        return 0;
    }
    return 1;
} // check_collision

/*
* int HashTableQuad::get_hash(std::string key)
* Input: A key string
* Output: 
* Returns: The correct hash index (with open addressing)
*/
int HashTableQuad::get_hash(std::string key) {
    int table_index = hash_function(key);
    if (check_collision(table_index)) {
        table_index = quadratic_probing(table_index);
    }
    return table_index;
} // get_hash

/*
* int HashTableQuad::search(std::string key)
* Input: A key string
* Output: 
* Returns: The index if the key is found, -1 if not found
*/
int HashTableQuad::search(std::string key) {
    int table_index = hash_function(key);
    int i = 1;
    while (table_index <= TABLE_SIZE) {
        comparisons++; // Add Comparison
        if (table[table_index].is_empty()) {
            return -1;
        } else if (table[table_index].get_key() == key) {
            return table_index; // Should go here but nothing is there.
        } else {
            table_index += i*i;
            i++;
        }
    }
    return -1;
} // search

/*
* int HashTableQuad::find(std::string key)
* Input: A key string
* Output: 
* Returns: The value of the key if found, -1 if not found
*/
int HashTableQuad::find(std::string key) {
    int hash_val = search(key);
    if (hash_val > -1) {
        return table[hash_val].get_value();
    } else {
        return -1; // Not Found
    }
} // find

/*
* int HashTableQuad::quadratic_probing(int hash)
* Input: An integer hash value
* Output: 
* Returns: The proper hash value after probing
*/
int HashTableQuad::quadratic_probing(int hash) {
    int hash_val = hash;
    int i = 1;
    while (check_collision(hash_val)) {
        hash_val = hash_val + (i*i); // Helps with primary clustering
        i++;
    }
    return hash_val;
} // quadratic_probing

/*
* void HashTableQuad::insert(std::string key)
* Input: A key string
* Output: 
* Returns:
*/
void HashTableQuad::insert(std::string key) {
    // When inserting, we know element doesn't already exist
    int table_index = get_hash(key);
    Pair datum;
    datum.set_key(key);
    datum.set_value(1);
    table[table_index] = datum;
} // insert

/*
* void HashTableQuad::increment(std::string key)
* Input: A key string
* Output: 
* Returns:
*/
void HashTableQuad::increment(std::string key) {
    int table_index = search(key);
    table[table_index].set_value(table[table_index].get_value() + 1);
} // increment

#endif