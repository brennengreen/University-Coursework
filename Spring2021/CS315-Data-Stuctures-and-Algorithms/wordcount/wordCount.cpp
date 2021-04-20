/*   wordCount.cpp                                       */
/*   Author: Brennen Green                               */
/*   CS315 Spring 2021 Assignment 4                      */
/*   Usage: ./wordCount [Expects input data on stream]   */
/*   Extra Credit: Please check read me section!         */
/*   Outputs: Prints word occurrences in alphabetical and*/
/*    numerical order of occurrences                     */
/*   Refer to README for program description and info    */
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "hash_table_quad.h" // Hash Table Class (Quadratic Probing)
#include "hash_table_linear.h" // Hash Table Class (Linear Probing)
#include "key_value_pair.h" // K,V Pair Class

// Prototypes
std::vector<std::string> parse_line(std::string line);
std::string clean_line(std::string line);
template <typename T> 
void merge_sort(T array[], int lowIndex, int highIndex,
        int & motion_tracker, int & comparison_tracker);
void heap_sort(std::string array[], int array_size, int & motion_tracker,
         int & comparison_tracker);
void quick_sort(std::string array[], int low, int high, 
        int & motion_tracker, int & comparison_tracker);

/*
* main()
*/
int main(int argc, char ** argv) {
    int TABLE_SIZE = 200003; // Very large prime table size, could be smaller

    // Build the hash tables 
    HashTableQuad * table_quad = new HashTableQuad(TABLE_SIZE);
    HashTableLinear * table_linear = new HashTableLinear(TABLE_SIZE);

    std::vector<std::string> unique;

    std::string this_line;
    while (std::getline(std::cin, this_line)) {
        std::vector<std::string> words = parse_line(this_line);
        for (size_t i = 0; i < words.size(); i++) {
            // Insert into quadratic probing table
            if (table_quad->find(words[i]) == -1) {
                table_quad->insert(words[i]); // Will only do this once
                unique.push_back(words[i]);
            } else {
                table_quad->increment(words[i]);
            } // Check if word should be incremented or inserted

            // Insert into linear probing table
            if (table_linear->find(words[i]) == -1) {
                table_linear->insert(words[i]);
            } else {
                table_linear->increment(words[i]);
            } // Check if word should be incremented or inserted
        } // Insert or update all words into the tables
    } // Read all lines of input data


    // Sort and output (arrays make our sorting easier)

    // Initialize the arrays we'll need
    std::string merge_sort_copy[unique.size()];
    int merge_comparisons = 0;
    int merge_motions = 0;

    std::string heap_sort_copy[unique.size()];
    int heap_comparisons = 0;
    int heap_motions = 0;

    std::string quick_sort_copy[unique.size()];
    int quick_comparisons = 0;
    int quick_motions = 0;

    Pair numerical_sort_copy[unique.size()];

    for (size_t i = 0; i < unique.size(); i++) {
        merge_sort_copy[i] = unique[i];
        numerical_sort_copy[i] = Pair(unique[i],
            table_quad->find(merge_sort_copy[i]));
        heap_sort_copy[i] = unique[i];
        quick_sort_copy[i] = unique[i];
    } // Build the arrays for sorting

    // Alphabetical Merge Sort (Primary Sorting Method)
    merge_sort<std::string>(merge_sort_copy, 0, unique.size()-1, merge_motions,
        merge_comparisons);

    // Numerical Merge Sort
    int trash = -9999; // Don't need to track the comparisons here
    merge_sort<Pair>(numerical_sort_copy, 0, unique.size()-1, trash, trash);

    // Alphabetical Heap and Quick Sort (Extra Credit)
    quick_sort(quick_sort_copy, 0, unique.size()-1,
                    quick_motions, quick_comparisons);
    heap_sort(heap_sort_copy, unique.size(), heap_motions, heap_comparisons);


    // Print the resultant arrays
    for (size_t i = 0; i < unique.size(); i++) {
        std::cout << merge_sort_copy[i] << " ";
        std::cout << table_quad->find(merge_sort_copy[i]) << std::endl;
    } // Print the alphabetically sorted array
    std::cout << std::endl;
    for (int i = unique.size() - 1; i >= 0; i--) {
        std::cout << numerical_sort_copy[i].get_key() << " ";
        std::cout << numerical_sort_copy[i].get_value() << std::endl;
    } // Print the numerically sorted array

    if (argc > 1) {
        // Print performance statistics (Extra Credit)
        std::cout << std::endl;

        std::cout << "------------PERFORMANCE STATISTICS----------" << std::endl;
        std::cout << "Quadratic and Linear Comparisons: " << std::endl;
        std::cout << "Quadratic Probing: " << table_quad->comparisons << std::endl;
        std::cout << "Linear Probing: "  << table_linear->comparisons << std::endl;
        std::cout << "HeapSort, QuickSort, MergeSort Stats: " << std::endl;
        std::cout << "MergeSort Comparisons: " << merge_comparisons << std::endl;
        std::cout << "MergeSort Data Motions: " << merge_motions << std::endl;
        std::cout << "HeapSort Comparisons: " << heap_comparisons << std::endl;
        std::cout << "HeapSort Data Motions: " << heap_motions << std::endl;
        std::cout << "QuickSort Comparisons: " << quick_comparisons << std::endl;
        std::cout << "QuickSort Data Motions: " << quick_motions << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
    } // Check to see if extra credit flag was passed

    return 0;
} // main


/*
* void heap(std::string array[], int array_size, int index,
        int & motion_tracker, int & comparison_tracker)
* Input: An array of data, size of the array,
        sorting index and two tracking variables
* Output:
* Returns:
*/
void heap(std::string array[], int array_size, int index,
                int & motion_tracker, int & comparison_tracker) {
    int larger = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Check which is the larger side
    if (left < array_size && array[left] > array[larger]) {
        larger = left;
    }
    comparison_tracker++;
    if (right < array_size && array[right] > array[larger]) {
        larger = right;
    }
    comparison_tracker++;

    if (larger != index) {
        std::string temp = array[index];
        array[index] = array[larger];
        array[larger] = temp;
        motion_tracker++;
        heap(array, array_size, larger, motion_tracker, comparison_tracker);
    } // Place larger on "top"
} // heap

/*
* void heap_sort(std::string array[], int array_size, int & motion_tracker,
         int & comparison_tracker)
* Input: An array of data, size of the array, and two tracking variables
* Output:
* Returns:
*/
void heap_sort(std::string array[], int array_size, int & motion_tracker,
         int & comparison_tracker) {
    for (int i = array_size/ 2 - 1; i >= 0; i--) {
        heap(array, array_size, i, motion_tracker, comparison_tracker);
    }

    for (int i = array_size - 1; i > 0; i--) {
        std::string temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        motion_tracker++;

        heap(array, i, 0, motion_tracker, comparison_tracker);
    }
} // heap_sort


/*
* merge(template T array[], int lowIndex, int highIndex,
    int & motion_tracker, int & comparison_tracker)
* Input: An array of data, lower bound, upper bound, and two tracking variables
* Output:
* Returns:
*/
template <typename T> // Multi Use
void merge(T array[], int lowIndex, int highIndex,
    int & motion_tracker, int & comparison_tracker) {
    int mid = (lowIndex+highIndex)/2;

    // Temporary values for copying array
    int temp1 = mid - lowIndex + 1;
    int temp2 = highIndex - mid;

    T left[temp1], right[temp2];

    for (int i = 0; i < temp1; i++) {
        left[i] = array[lowIndex + i];
        motion_tracker++;
    } // Copy relevant parts of array to the left
    for (int j = 0; j < temp2; j++) {
        right[j] = array[mid + 1 + j];
        motion_tracker++;
    } // Copy relevant parts of array to the right

    // Merge
    int i = 0;
    int j = 0;
    int comb = lowIndex;

    while (i < temp1 && j < temp2) {
        if (left[i] <= right[j]) {
            array[comb] = left[i];
            i++;
            motion_tracker++;
            comparison_tracker++;
        } else {
            array[comb] = right[j];
            j++;
            motion_tracker++;
            comparison_tracker++;
        }
        comb++;
    } // Merging

    // Copy remainders
    while (i < temp1) {
        array[comb] = left[i];
        motion_tracker++;
        i++;
        comb++;
    } // Copy left remaining

    while (j < temp2) {
        array[comb] = right[j];
        motion_tracker++;
        j++;
        comb++;
    } // Copy right remaining

} // merge

/*
* void merge_sort(template T array[], int lowIndex, int highIndex,
        int & motion_tracker, int & comparison_tracker)
* Input: An array of data, lower bound, upper bound, and two tracking variables
* Output:
* Returns:
*/
template <typename T> // Multi Use
void merge_sort(T array[], int lowIndex, int highIndex,
        int & motion_tracker, int & comparison_tracker) {
    if (highIndex - lowIndex < 1) return;
    int mid = (lowIndex + highIndex)/2;
    merge_sort<T>(array,lowIndex,mid,motion_tracker,comparison_tracker);
    merge_sort<T>(array,mid+1,highIndex,motion_tracker,comparison_tracker);
    merge<T>(array,lowIndex,highIndex,motion_tracker,comparison_tracker);
} // merge_sort

/*
* int partition(std::string array[], int low, int high,
        int & motion_tracker, int & comparison_tracker)
* Input: Array, low value, high value, and two tracking values
* Output: 
* Returns: The index of the middle element of the partioned array.
*/
int partition(std::string array[], int low, int high,
        int & motion_tracker, int & comparison_tracker) {
    std::string pivot = array[low];
    int divide = low;
    for (int comb = low+1; comb <= high; comb++) {
        if (array[comb] < pivot) {
            comparison_tracker++;
            divide++;
            // Swap divide and comb
            std::string temp = array[divide];
            array[divide] = array[comb];
            array[comb] = temp;
            motion_tracker++;
        }
    } // Iterate over and perform algorithm
    // Swap divide and low
    std::string temp = array[divide];
    array[divide] = array[low];
    array[low] = temp;
    motion_tracker++;
    return divide;
} // partition (Lomuto's Method)

/*
* void quick_sort(std::string array[], int low, int high, 
        int & motion_tracker, int & comparison_tracker);
* Input: Array, low value, high value, and two tracking values
* Output: 
* Returns:
*/
void quick_sort(std::string array[], int low, int high, 
        int & motion_tracker, int & comparison_tracker) {
    if (high - low <= 0) return;
    int mid = partition(array, low, high, motion_tracker, comparison_tracker);
    quick_sort(array, low, mid-1, motion_tracker, comparison_tracker);
    quick_sort(array, mid+1, high, motion_tracker, comparison_tracker);
} // quick_sort


/*
* std::vector<std::string> parse_line(std::string line)
* Input: A line of characters
* Output: 
* Returns: A vector of parsed words
*/
std::vector<std::string> parse_line(std::string line) {
    line = clean_line(line); // "clean" the line first
    std::vector<std::string> words;
    std::stringstream ss; // Stream for line

    ss << line;

    std::string this_word;
    while (ss >> this_word) {
        words.push_back(this_word);
    } // Iterate over stream

    return words;
} // parse_line

/*
* std::string clean_line(std::string line)
* Input: A line of characters
* Output: 
* Returns: A line without punctuation (excluding the underscore)
*/
std::string clean_line(std::string line) {
    for (size_t i = 0; i < line.size(); i++) {
        if (!std::isalpha(line[i]) && line[i] != '_' && line[i] != ' ' ) {
            line[i] = ' '; // Replace punctuation with space
        } // Check if character is not A-Z or a-Z and is not a _.
          //    We also want to ignore spaces
    } // Iterate over the line
    return line;
} // clean_line