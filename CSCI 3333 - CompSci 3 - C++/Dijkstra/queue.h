
#include <iostream> 
using namespace std; 
template <class THING> 
class queue {
	
private: 
	class node {
	public:

		THING data;
		node * next;

		node(THING x) {
			data = x;
			next = NULL;
		}
	};


	node * root;
	node * tail;
	int size;

public:
	queue() {
		root = NULL;
		size = 0;
	}

	void push(THING x) {

		node * newest = new node(x);
		if (root == NULL) {
			root = newest;
			tail = newest;
		}

		else {
			tail->next = newest;
			tail = tail->next;
		}

		size += 1;
	}

	void display() {
		node * traverse = root;
		while (traverse != NULL) {
			cout << traverse->data << " ";
			traverse = traverse->next;
		}
	}

	bool empty() {

		if (size == 0)
			return true;

		else 
			return false;
	}

	node * pop() {
		

		if (root == tail) {
			root = NULL;
			tail = NULL;
			return NULL;
		}

		else {
			node * old_root = root;

			root = root->next;
			size -= 1;
			return old_root;
		}

	}
};