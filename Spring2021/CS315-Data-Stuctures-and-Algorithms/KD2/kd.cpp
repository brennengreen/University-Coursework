/*   kd.c                                                */
/*   Author: Brennen Green                               */
/*   CS315 Spring 2021 Assignment 3                      */
/*   Usage: ./kd num_dims data_points probes             */
/*   Outputs: Probe Results                              */
/*   Refer to README for Program Description!            */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "datapoint.hpp" // Custom Data Point Class


/*
* Node Struct
*/
typedef struct Node {
    int dim; // Discriminate Dimension
    int value; // Discriminate Value
    struct Node * left;
    struct Node * right;
    std::vector<DataPoint> values; // Points in the bucket
} Node; // Node for K-D Tree


/*
* Prototypes
*/

int get_next_num();
int select_median(int array[], int size, int target);
int partition(int array[], int low, int high);
int find_discriminate_dim(std::vector<DataPoint> array);
int distance(DataPoint point1, DataPoint point2);

void split(Node * tree, std::vector<DataPoint> array, size_t b);
void probe(Node * tree, DataPoint probe_dp);
void traverse(Node * tree);

DataPoint nearest_neighbor(DataPoint probe, std::vector<DataPoint> bucket);
Node * allocate_node();

/*
* int main (int argc, char ** argv)
* Input: Number of arguments, Argument Variables
* Output: The results of p probes.
* Returns: Error code (0 if successful)
*/
int main (int argc, char ** argv) { 
    /* PARSE PARAMETERS */
    int k = strtol(argv[1], NULL, 10);
    int n = strtol(argv[2], NULL, 10);
    int p = strtol(argv[3], NULL, 10);
    if (k == 0 || k < 0 || n == 0 || n < 0 || p == 0 || p < 0 ) { 
        // Validate value of all parameters (nonnegative integer greater than 0)
        printf("Input Error: All input values must be greater than 0." 
                    "Values given: %d %d %d\n", k, n, p);
        return 1; // Input error
    } // Parse the value k,n,p from command line

    /* READ DATA BASED ON PARAMETERS */
    std::vector<DataPoint> offline_store;

    for (int i = 0; i < n; i++) {
        DataPoint this_dp;
        for (int current_dim = 0; current_dim < k; current_dim++) {
            int new_value = get_next_num();
            this_dp.add_coord(new_value);
        } // Fill the datapoint
        offline_store.push_back(this_dp);
    } // Create offline array of nodes to be inserted later

    size_t b = 10; // The threshold for each bucket
    Node * tree = allocate_node();
    split(tree, offline_store, b);

    for (int i = 0; i < p; i++) {
        DataPoint this_probe;
        for (int current_dim = 0; current_dim < k; current_dim++) {
            int new_value = get_next_num();
            this_probe.add_coord(new_value);
        } // Fill the datapoint
        probe(tree, this_probe);
    } // Probe the tree p times

    return 0;
} // main()

void traverse(Node * tree) {
    if (tree->value == -1 && tree->dim == -1) {
         for (size_t i = 0; i < tree->values.size(); i++)
            tree->values[i].print();
        return;
    } else {
        printf("( %d %d )\n", tree->dim, tree->value);
        printf("----\n");
        traverse(tree->left);
        printf("----\n");
        printf("====\n");
        traverse(tree->right);
        printf("====\n");
    }

}

/*
* void probe(Node * tree, DataPoint probe_dp)
* Input: A Tree, A Probe
* Output: The points in the bucket the probe would be in.
* Returns: 
*/
void probe(Node * tree, DataPoint probe_dp) {
    if(tree->dim == -1 && tree->value == -1) {
        printf("probe ");
        probe_dp.print_in_place();
        printf("reaches bucket: %d elements\n", (int)tree->values.size());
        for (size_t i = 0; i < tree->values.size(); i++)
            tree->values[i].print(); // Print all datapoints.

        printf("Nearest Neighbor: ");
        nearest_neighbor(probe_dp, tree->values).print(); // EXTRA CREDIT
        return;
    } // Found our bucket.

    if (probe_dp[tree->dim] <= tree->value) {
        return probe(tree->left, probe_dp);
    } else {
        return probe(tree->right, probe_dp);
    } // Find which direction to probe next.
} // probe()

/*
* void split(Node * tree, std::vector<DataPoint> array, size_t b)
* Input: A tree, array of points, and a threshold
* Output: 
* Returns: N/A But manipulates the input tree.
*/
void split(Node * tree, std::vector<DataPoint> array, size_t b) {
    if (array.size() <= b) {
        tree->values = array;
        return;
    } // Check if array is below threshold.

    tree->dim = find_discriminate_dim(array);
    int dim_array[array.size()];
    for (size_t i = 0; i < array.size(); i++) {
        DataPoint this_dp = array[i];
        dim_array[i] = this_dp[tree->dim];
    } // Pile in values from discriminate dimension

    int target = (int)(array.size() / 2); // median
    if (array.size() % 2 == 0) {
        tree->value = select_median(dim_array, array.size(), target - 1);
    } else {
        tree->value = select_median(dim_array, array.size(), target);
    }


    std::vector <DataPoint> array_left;
    std::vector <DataPoint> array_right;
    for (size_t i = 0; i < array.size(); i++) {
        DataPoint this_dp = array[i];
        if (this_dp[tree->dim] <= tree->value) {
            array_left.push_back(this_dp);
        } else {
            array_right.push_back(this_dp);
        } 
    } // Split the array given a discriminate value.

    tree->left = allocate_node();
    tree->right = allocate_node();

    split(tree->left, array_left, b);
    split(tree->right, array_right, b);
} // Split()

/*
* DataPoint nearest_neighbor(DataPoint probe, std::vector<DataPoint> bucket)
* Input: Probe, Bucket of Neighbors
* Output: 
* Returns: The datapoint in the bucket which is its nearest neighbor.
*/
DataPoint nearest_neighbor(DataPoint probe, std::vector<DataPoint> bucket) {
    int min_dist = 999999999; // sentinel value
    DataPoint curr_nearest;
    for (size_t i = 0; i < bucket.size(); i++) {
        int dist = distance(probe, bucket[i]);
        if (dist < min_dist) {
            min_dist = dist;
            curr_nearest = bucket[i];
        }
    } // Calculate all distances   
    return curr_nearest;
} // nearest_neighbor()

/*
* int distance(DataPoint point1, DataPoint point2)
* Input: Point1, Point2
* Output: 
* Returns: Euclidean Distance between the two points.
*/
int distance(DataPoint point1, DataPoint point2) {
    int running_tot = 0;
    for (int i = 0; i < point1.size(); i++) {
        int dist_to_axis = (point2[i] - point1[i]);
        running_tot += std::pow(dist_to_axis, 2);
    } // Dimensional distances
    return running_tot;
} // distance()

/*
* Node * allocate_node()
* Input:
* Output: 
* Returns: A newly allocated node.
*/
Node * allocate_node() {
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->dim = -1;
    new_node->value = -1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
} // allocate_node()

/*
* int find_discriminate_dim(std::vector<DataPoint> array)
* Input: An array of points
* Output: 
* Returns: The diminesion index with largest range.
*/
int find_discriminate_dim(std::vector<DataPoint> array) {
    int max_range = 0;
    int discriminate_dimension = -1;
    for (int dim = 0; dim < array[0].size(); dim++) {
        int max_of_dim = -999999;
        int min_of_dim = 999999;
        for (size_t i = 0; i < array.size(); i++) {
            DataPoint this_dp = array[i];
            if (this_dp[dim] < min_of_dim) {
                min_of_dim = this_dp[dim];
            } else if (this_dp[dim] > max_of_dim) {
                max_of_dim = this_dp[dim];
            } // Check if min or max
        } // Calculate ranges
        int range = max_of_dim - min_of_dim;
        if (range > max_range) {
            max_range = range;
            discriminate_dimension = dim;
        } // Check if max range
    } // Check all dimensions
    return discriminate_dimension;
} // find_discriminate_dim()

/*
* int get_next_num()
* Input: 
* Output: 
* Returns: Integer representation of next random number.
*/
int get_next_num() {
    char * line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);
    return strtol(line, NULL, 10);
} // get_next_num

/*
* int select_median(int array[], int size, int target)
* Input: array, size of array, target element
* Output: 
* Returns: The median of that array.
*/
int select_median(int array[], int size, int target) {
    int low = 0;
    int high = size-1;
    while (low < high) {
        int mid = partition(array, low, high);
        if (mid == target) {
            return array[target];
        } else if (mid < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    } // Recurse until selected
    return array[target];
} // QuickSelect (Using Partitioning)

/*
* int partition(int array[], int low, int high)
* Input: array, low value, high value
* Output: 
* Returns: The index of the middle element of the partioned array.
*/
int partition(int array[], int low, int high) {
    int pivot = array[low];
    int divide = low;
    for (int comb = low+1; comb <= high; comb++) {
        if (array[comb] < pivot) {
            divide++;
            // Swap divide and comb
            int temp = array[divide];
            array[divide] = array[comb];
            array[comb] = temp;
        }
    } // Iterate over and perform algorithm
    // Swap divide and low
    int temp = array[divide];
    array[divide] = array[low];
    array[low] = temp;
    return divide;
} // Partition (Lomuto's Method)