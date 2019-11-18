#include "list.h"
#include <iostream>
#include <string>

using namespace std;

list::list()
{
	head = NULL;
}

void list::print()
{
	node * p = head;
	while (p != NULL)
	{
		cout << p->key << ", ";
		p = p->next;
	}
}

node * list::search(int key)
{
	node * p = head;
	while (p != NULL)
	{
		if (p->key == key)
		{
			return p;
		}
		p = p->next;
	}
	return NULL; // Nothing was found
}

void list::insert(int newKey)
{
	node * newNode = new node;
	newNode->key = newKey;
	newNode->next = NULL;
}
