#include <iostream>
#include "LList.h"

//----------------------------------------------------
//				constructor & destructor
//----------------------------------------------------
LList::LList() {
	head = NULL;
	cout << "LList: constructed!\n";
}

LList::~LList() {
	if (head != NULL) // If head is not null, a list exists
	{
		node * p = head;
		while (p->next != NULL)
		{
			node * curr = p;
			p = p->next;
			delete curr;
			curr = NULL;
		}
	}
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
	node * p = head;
	if (head == NULL)
		return NULL;
	if (p->key == srchKey)
	{
		return p;
	}
	while (p->next != NULL)
	{
		if (p->key == srchKey)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
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
	node * foundNode = search(srchkey);
	if (foundNode != NULL)
	{
		foundNode->print();
	}
	else
	{
		cout << "Not Found" << endl;
	}
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
	node * p = head;
	node * prev;
	if (r == p)
	{
		return NULL;
	}
	p = p->next;
	prev = head;
	while (p->next != NULL)
	{
		if (p == r)
		{
			return prev;
		}
		p = p->next;
		prev = prev->next;
	}
	return NULL;
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
	node * newNode = new node;
	newNode->key = k;
	newNode->data = d;

	node * dupNode = search(k);
	if (dupNode != NULL) // Found a duplicate
	{
		node * nodeB4 = getb4(dupNode);
		if (nodeB4 != NULL)
		{
			nodeB4->next = newNode;
		}
		newNode->next = dupNode->next;
		dupNode->next = NULL;
		newNode->dup = dupNode;

		if (dupNode == head)
		{
			head = newNode;
		}
	}
	else
	{
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}

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
	node * nodeB4 = getb4(r);
	if (r == NULL || (nodeB4 == NULL && r != head))
	{
		return false;
	}

	if (r == head) // The head needs to be handled a bit different since nothing is before it
	{
		head = r->next;
	}
	else
	{
		nodeB4->next = r->next;
	}
	r->next = NULL;
	return true;
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
	node * p = head;
	while (p->next != NULL)
	{
		if (p->key == k)
		{
			if (remove(p) == true)
			{
				delete p;
				p = NULL;
				return true;
			}
			else // Failed to remove the node from list
			{
				return false;
			}
		}
	}
	return false;
} // drop()

//----------------------------------------------------
//				        max
//----------------------------------------------------
// Returns: a pointer to the node with the highest key
//          or NULL when there list is empty.
node * LList::max() {
	node * p = head;
	if (p == NULL)
		return NULL;
	int max = -999999999999;
	node * maxNode = new node();
	while (p->next != NULL)
	{
		if (p->key > max)
		{
			max = p->key;
			maxNode = p;
		}
		p = p->next;
	}
	return maxNode;
} // max()

//----------------------------------------------------
//				       sort
//----------------------------------------------------
// Sorts the list in ascending order by key values
void LList::sort() {
	LList * buf = new LList(); // Temporary list acting as a buffer
	while (head != NULL)
	{
		node * maxNode = max();
		remove(maxNode);
		buf->insert(maxNode->key, maxNode->data);

	}
	head = buf->head;
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