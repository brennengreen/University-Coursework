# KD Trees
### By: Brennen Green
### CS315-Spring 2021 Assignment 3


## __Program Description__

Given a specified number of dimensions, k, and n values. Build a k-d tree with
n data points of k dimensions. After building the tree, probe the tree with
p different data points and print out the corresponding bucket

__Output__: The expected output will include the results of a probe 
and the nearest neighbor of the probing datapoint. 

```
inputs: k = 3 n = 64 p = 1
probe 6292 3336 1613 reaches bucket: 8 elements
7445 3427 1110 
8168 2136 887  
9331 1389 5444 
6872 2847 2604 
9438 2088 2017 
7356 3869 3919 
9054 3749 85   
8236 4587 4984 
Nearest Neighbor: 6872 2847 2604
```

__Usage__: `./kd [num dims] [num values] [num probes] (expects random number 
generator piped to stream)`

Example Usage: `./randGen.pl 49 10000 | ./kd 3 64 2`

__EVEN ELEMENT MEDIAN SELECTION METHOD__: Lower of the two middle values.

### __Extra Credit Information__

Implemented nearest neighbor (inside bucket) using Euclidean Distance.
The nearest neighbor of each probe is listed after its bucket is printed.

## __Compilation__

Compilation made easy via the Makefile.

Just type `make` in the command line. It'll even
run it once for you and pipe output to tmpRun.out .

## __Function and Structure Documentation__
`int main (int argc, char ** argv)`
```
Input: Number of arguments, Argument Variables
Output: The results of p probes.
Returns: Error code (0 if successful)
```
`void probe(Node * tree, DataPoint probe_dp)`
```
Input: A Tree, A Probe
Output: The points in the bucket the probe would be in.
Returns: 
```
`void split(Node * tree, std::vector<DataPoint> array, size_t b)`
```
Input: A tree, array of points, and a threshold
Output: 
Returns: N/A, But manipulates the input tree.
```
`DataPoint nearest_neighbor(DataPoint probe, std::vector<DataPoint> bucket)`
```
Input: Probe, Bucket of Neighbors
Output: 
Returns: The datapoint in the bucket which is its nearest neighbor.
```
`int distance(DataPoint point1, DataPoint point2)`
```
Input: Point1, Point2
Output: 
Returns: Euclidean Distance between the two points.
```
`Node * allocate_node()`
```
Input:
Output: 
Returns: A newly allocated node.
```
`int find_discriminate_dim(std::vector<DataPoint> array)`
```
Input: An array of points
Output: 
Returns: The dimension index with largest range.
```
`int get_next_num()`
```
Input: 
Output: 
Returns: Integer representation of next random number.
```
`int select_median(int array[], int size, int target)`
```
Input: array, size of array, target index
Output: 
Returns: The median of that array.
```
`int partition(int array[], int low, int high)`
```
Input: array, low value, high value
Output: 
Returns: The index of the target element of the partioned array.
```
### __DATA POINT DOCUMENTATION__
__Usage__: Used to store a datapoint of varying dimensions
and provides basic functionality to work with the datapoint

`int& DataPoint::operator[](int index)`
```
Input: index
Output: 
Returns: Value at that index.
```
`void DataPoint::print()`
```
Input: 
Output: String representation with trailing newline.
Returns: 
```
`void DataPoint::print_in_place()`
```
Input: 
Output: String representation without trailing newline.
Returns: 
```
`int DataPoint::size()`
```
Input: 
Output: 
Returns: The number of dimensions in the datapoint.
```