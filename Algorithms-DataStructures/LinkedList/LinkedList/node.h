#pragma once
#include <string>

using namespace std;

class node {
public:
	friend class list;
	node();
private:
	int key;
	node * next;

};