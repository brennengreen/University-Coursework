/*   ternary.c                                           */
/*   Brennen Green                                       */
/*   CS315 Spring 2021 Assignment 2                      */
/*   Usage: ./ternary num_lines                          */
/*   Outputs: The representation of a ternary tree with  */
/*                    num_lines values inserted in order */
/*   Refer to README for Program Description!            */

#include <stdio.h>
#include <stdlib.h>

#define NULL 0

/*
* Ternary Tree Node
*/
typedef struct Node {
    struct Node * left;
    struct Node * middle;
    struct Node * right;
    int a;
    int b;
} Node;

/*
* Prototypes: Check declaration or README for information
*/
Node * init_tree();

int get_next_num();
int is_tree_empty(Node * tree);
int search_for(Node * tree, int value);

void inorder_traversal (Node * root);
void insert_value(Node * tree, int value);

/*
* int main(int argc, char ** argv)
* Input: a stream of arguments from command line
* Output: 
* Returns: 0 if successful, error otherwise
*/
int main(int argc, char *argv[]) {
    // parse input
    int n = strtol(argv[1], NULL, 10);
    if (n == 0 || n < 0) { 
        // Validate value of all parameters (nonnegative integer great than 0)
        printf("Input Error: All input values must be greater than 0." 
                    "Values given: %d\n", n);
        return 1; // input error
    } // parse the value n from command line


    Node * tree = init_tree();
    for (int i = 0; i < n; i++) {
       int new_node = get_next_num();
       insert_value(tree, new_node); // place new node
    } // parse n lines of integers

    inorder_traversal(tree);

    // EXTRA CREDIT:
    printf("\n-- -- -- EXTRA CREDIT -- -- --\n");
    int search_num = get_next_num();
    printf("Searching for %d in tree\n", search_num);
    int found = search_for(tree, search_num);
    if (found) printf("Found!\n");
    else printf("Not Found!\n");

    printf("-- -- -- END OUTPUT -- -- --\n");

    return 0;
} // main


/*
* Node * init_tree()
* Input: 
* Output: 
* Returns: An empty ternary tree
*/
Node * init_tree() {
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->a = NULL;
    new_node->b = NULL;
    new_node->left = NULL;
    new_node->middle = NULL;
    new_node->right = NULL;
    return new_node;
} // init_tree


/*
* int is_tree_empty(Node * tree)
* Input: the root of a tree
* Output: 
* Returns: 1 if empty, 0 otherwise
*/
int is_tree_empty(Node * tree) {
    if (tree->a == NULL) return 1;
    else return 0;
} // is_tree_empty


/*
* int search_for(Node * tree, int value)
* Input: the root of a tree, search value
* Output: 
* Returns: 1 if found, 0 otherwise
*/
int search_for(Node * tree, int value) {
    if (is_tree_empty(tree)) {
        return 0;
    } // If tree is empty, value cant be there
    
    if (value == tree->a || value == tree->b) {
        return 1; 
    } // Check if its in current node

    if (value <= tree->a) {
        if (tree->left == NULL) {
            return 0;
        } // cant be found if doesnt exist
        return search_for(tree->left, value);
    } else if (value > tree->b) {
        if (tree->right == NULL) {
            return 0;
        } // cant be found if doesnt exist
        return search_for(tree->right, value);
    } else {
        if (tree->middle == NULL) {
            return 0;
        } // cant be found if doesnt exist
        return search_for(tree->middle, value);
    } // find where a should be and recurse that child
} // search_for


/*
* int get_next_num()
* Input: 
* Output: 
* Returns: int representation of next random number
*/
int get_next_num() {
    char * line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);
    return strtol(line, NULL, 10);
} // get_next_num

/*
* void inorder_traversal(Node * root)
* Input: the root of a tree
* Output: The in order representation of the tree
* Returns: 
*/
void inorder_traversal (Node * tree) {
    if (tree->left != NULL) {
        printf("(");
        inorder_traversal(tree->left);
        printf(")");
    } // recurse left tree

    if (tree->a != NULL) {
        printf(" %d ", tree->a);
    } // print a value

    if (tree->middle != NULL) {
        printf("(");
        inorder_traversal(tree->middle);
        printf(")");
    } // recurse middle tree

    if (tree->b != NULL) {
        printf(" %d ", tree->b);
    } // print b value

    if (tree->right != NULL) {
        printf("(");
        inorder_traversal(tree->right);
        printf(")");
    } // recurse right tree
} // inorder_traversal

/*
* void insert_value(Node * tree, int value)
* Input: a tree root and a value to insert
* Output: 
* Returns: 
*/
void insert_value(Node * tree, int value) {
    if (is_tree_empty(tree)) {
        tree->a = value;
        return;
    } // If tree is empty, insert value at front

    if (tree->b == NULL) {
        if (tree->a <= value){
            tree->b = value;
        } else {
            int temp = tree->a;
            tree->a = value;
            tree->b = temp;
        }
        return;
    } // Place a,b in correct order

    if (value <= tree->a) {
        if (tree->left == NULL) {
            tree->left = init_tree();
        } // check if empty
        return insert_value(tree->left, value);
    } else if (value > tree->b) {
        if (tree->right == NULL) {
            tree->right = init_tree();
        } // check if empty
        return insert_value(tree->right, value);
    } else {
        if (tree->middle == NULL) {
            tree->middle = init_tree();
        } // check if empty
        return insert_value(tree->middle, value);
    } // place p in correct place if a,b are populated
} // insert_value
