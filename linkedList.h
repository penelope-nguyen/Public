
#include <iostream>
#include <string>
using namespace std;

template <class THING>
class linkedList {
private:
	class node {
	public:
		THING data;
		node * next;
		node * prev;

		node(THING x) {
			data = x;
			next = NULL;
			prev = NULL;
		}
	};


public:
	node * root;
	node * tail;
	int listSize;

	linkedList() {
		root = NULL;
		tail = NULL;
		listSize = 0;
	}

	int size() {
		return listSize;
	}

	void insert(THING x) {
		node * newest = new node(x);
		if (root == NULL) 
			root = newest;
		else {
			tail->next = newest;
			newest->prev = tail;
		}
	
		tail = newest;
		
		listSize += 1;
	}

	bool contains(THING x) {
		node * p = root;
		while (p != NULL) {
			if (p->data == x)
				return true;
			p = p->next;
		}
		return false;
	}

	void push_back(THING x) {

		node * newest = new node(x);
		newest->next = root;
		root->prev = newest;
		root = newest; 	
	}

	void display() {
		node * current = root; 
		while (current != NULL) {
			cout << current->data << endl;
			current = current->next;
		}
	}

};