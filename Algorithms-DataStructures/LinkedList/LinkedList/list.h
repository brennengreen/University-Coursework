#pragma once
#include "node.h";

class list {
public:
	list();
	void print();
	node * search(int key);
	void insert(int newKey);
private:
	node * head;
};