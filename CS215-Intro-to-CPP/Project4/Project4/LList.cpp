#include <iostream>
#include "LList.h"

//----------------------------------------------------
//				constructor & destructor
//----------------------------------------------------
// FINISH THESE!
LList::LList() {

	cout << "LList: constructed!\n";
}

LList::~LList() {

	cout << "LList: destructed!\n";
}

//----------------------------------------------------
//				         search
//----------------------------------------------------
// Given: key to search for
// Returns: pointer to a node in the list found to have
//          the given search key, or NULL for not found
//----------------------------------------------------
node * LList::search(int srchKey) {

} // search()

//----------------------------------------------------
//				   findNode
//----------------------------------------------------
// Given: a key to search for
// Searches for a node with the given key, and if 
// found, invokes the print() method in the found node.
// Otherwise, prints "not found"
//----------------------------------------------------
void LList::findNode(int srchkey) {

} // findNode()

//----------------------------------------------------
//				    getb4
//----------------------------------------------------
// Given: a pointer to a node in the list
// Returns: a pointer to the node in the list BEFORE
//               the one pointed to by r, OR
//          NULL when r is the head or not found in
//               the list
//----------------------------------------------------
node * LList::getb4(node * r) {

} // getb4()

//----------------------------------------------------
//				       insert
//----------------------------------------------------
// Given: key and data for a new node
// Allocates/populates a new node
// When a node with the same key already exists:
//     the current/old node is replaced by the new one
//     and the old one is placed on the new one's 
//     duplicate list (it's NEXT should be set to NULL,
//     since it is no longer "in the list")
// Otherwise, the new node is prepended to the head
//     of the list.
//----------------------------------------------------
void LList::insert(int k, string d) {

} // insert()

//----------------------------------------------------
//				       remove
//----------------------------------------------------
// Given: a pointer to a node in the list to be removed
//        BUT NOT DELETED/DESTROYED
// Returns: TRUE - when the node was successfully removed
//          FALSE - when the given node is NULL or the node
//                  is not actually in the list.
// Simply removes the node from the linked list.
// (including setting the NEXT pointer in the node to NULL)
//----------------------------------------------------
bool LList::remove(node * r) {

} // remove()

//----------------------------------------------------
//				       drop
//----------------------------------------------------
// Given: key of a node to drop
// Returns: TRUE when a node was found and deleted
//          FALSE when a node with the given key not found,
//                or the remove() fails.
// Searches for a node in the list with the given key:
// When found, removes and deletes the node
//----------------------------------------------------
bool LList::drop(int k) {

} // drop()

//----------------------------------------------------
//				        max
//----------------------------------------------------
// Returns: a pointer to the node with the highest key
//          or NULL when there list is empty.
node * LList::max() {

} // max()

//----------------------------------------------------
//				       sort
//----------------------------------------------------
// Sorts the list in ascending order by key values
void LList::sort() {

} // sort()

//----------------------------------------------------
//				    print
//----------------------------------------------------
// prints each node in the list, or EMPTY when there
// are no nodes to print
//----------------------------------------------------
void LList::print() {
	if (head == NULL)
		cout << "EMPTY\n\n";
	else {
		node * p;
		p = head;
		while (p != NULL) {
			p->print();
			p = p->next;
		}
		cout << endl;
	}
} // print()