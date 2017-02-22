
#include <iostream>
#include <string>
using namespace std; 

class linkedList {
private: 
	class node {
	public:
		string data;
		node * next;
		
		node(string x) {
			data = x;
			next = NULL;
		}
	};

	
public: 
	node * root;
	node * tail;
	int listSize;

	linkedList() {
		root = NULL;
		listSize = 0;
	}

	int size() {
		return listSize;
	}

	void insert(string x) {
		node * newest = new node(x);
		if (root == NULL)
			root = newest;
		else 
			tail->next = newest;
		
		tail = newest;
		listSize += 1;
	}

	bool contains(string x) {
		node * p = root;
		while (p != NULL) {
			if (p->data == x)
				return true;
			p = p->next;
		}
		return false;
	}
};