# Word Count
### By: Brennen Green
### CS315-Spring 2021 Assignment 4


## __Program Description__

Given an input .txt file with word data. It will count the number
of occurences of each unique word in the file. 

__Output__: Word occurrences in alphabetical order and order of occurrences.

```
Ah 1
Aidenn 1
Allan 1
And 8
As 1

. . .

the 56
I 32
and 30
```

__Usage__: `./wordCount [Expects input data on stream]`

FOR EXTRA CREDIT: `./wordCount 1 [Expects input data on stream]`

Example Usage: `./wordCount < data.txt`
Example Usage With Extra Credit: `./wordCount 1 < data.txt`


### __Extra Credit Information__
__IMPORTANT__: To get the extra credit to appear, please pass
an extra command line argument to the wordCount program.
e.g. `./wordCount 1 < data.txt` this will tell the program
to output the extra statistics for the extra credit!

As extra credit I implemented several performance metrics
to compare design decisions.

First off, I implemented two different collision resolutions
based off open addressing. The first is quadratic probing
and the second is linear probing. I compare the number of 
comparisons each of these require when building the tables.

Secondly, I implemented the algorithms QuickSort, HeapSort,
 and MergeSort. I compared the number of both comparisons,
 and data motions each algorithm uses to alphabetically sort the words.

## __Compilation__

Compilation made easy via the Makefile.

Just type `make` in the command line. It'll even
run it once for you and pipe output to tmpRun.out .

## __Function and Structure Documentation__

```C++
void heap(std::string array[], int array_size, int index,
      int & motion_tracker, int & comparison_tracker)
Input: An array of data, size of the array,
      sorting index and two tracking variables
Output:
Returns:

void heap_sort(std::string array[], int array_size, int & motion_tracker,
       int & comparison_tracker)
Input: An array of data, size of the array and two tracking variables
Output:
Returns:

void merge(template T array[], int lowIndex, int highIndex,
  int & motion_tracker, int & comparison_tracker)
Input: An array of data, lower bound, upper bound, and two tracking variables
Output:
Returns:

void merge_sort(template T array[], int lowIndex, int highIndex,
      int & motion_tracker, int & comparison_tracker)
Input: An array of data, lower bound, upper bound, and two tracking variables 
Output:
Returns:
Note: For use with string based arrays

int partition(std::string array[], int low, int high,
      int & motion_tracker, int & comparison_tracker)
Input: Array, low value, high value, and two tracking values
Output: 
Returns: The index of the middle element of the partioned array.

void quick_sort(std::string array[], int low, int high, 
      int & motion_tracker, int & comparison_tracker);
Input: Array, low value, high value, and two tracking values
Output: 
Returns:

std::vector<std::string> parse_line(std::string line)
Input: A line of characters
Output: 
Returns: A vector of parsed words

std::string clean_line(std::string line)
Input: A line of characters
Output: 
Returns: A line without punctuation (excluding the underscore)
```

### __HASH TABLE DOCUMENTATION__
__Usage__: Create a hash table using either quad or linear probing.

```C++
int HashTableQuad::hash_function(std::string key_string)
Input: A key string
Output: 
Returns: An integer hash value

int HashTableQuad::check_collision(int hash)
Input: An integer hash value
Output: 
Returns: 1 if there is a collision, 2 otherwise

int HashTableQuad::get_hash(std::string key)
Input: A key string
Output: 
Returns: the correct hash index (with open addressing)

int HashTableQuad::search(std::string key)
Input: A key string
Output: 
Returns: The index if the key is found, -1 if not found

int HashTableQuad::find(std::string key)
Input: A key string
Output: 
Returns: The value of the key if found, -1 if not found

int HashTableQuad::quadratic_probing(int hash)
Input: An integer hash value
Output: 
Returns: The proper hash value after probing

void HashTableQuad::insert(std::string key)
Input: A key string
Output: 
Returns:


void HashTableQuad::increment(std::string key)
Input: A key string
Output: 
Returns:

```

### __(KEY, VALUE) PAIR DOCUMENTATION__
__Usage__: Store a key, value pair (e.g {"A", 65})
