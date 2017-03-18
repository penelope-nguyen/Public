#include <iostream> 
using namespace std; 

template<class THING> class minHeap {
private:
	class node {
	public: 
		THING data;
		node * left;
		node * right;
		int height;

		node(THING new_data) {
			data = new_data; 
			height = 0;
			left = NULL;
			right = NULL;
		}
	};

	node * root;

	void insert(node * p, THING x) {
		
		if (p == NULL)
			p = new node(x);
		
		else {

			if (childrenBalanced(p))
				insert(p->left, THING x);

			else
				insert(p->right, THING x);
				
		}
	}
	
	void subtreeHeight(node *p, int & l_height, int & r_height) {

		l_height = -1; 
		r_height = -1; 
		if (p->left != NULL)
			l_height = p->left->data;
		if (p->left != NULL)
			right = p->right->height;
	}

	bool childrenBalanced(node * p) {
		int l_height, int r_height;

		subtreeHeight(p, l_height, r_height);
		if (l_height == r_height)
			return true;
		else
			return false;

	}

	void display(node * p) {
		if (p == NULL)
			return; 

		else 
	}
public:
	
	// some display functions 
	display() {
		displayBF(root);
	}

	minHeap() {
		root = NULL;
	}

	void insert(THING x) {

		insert(root, x);
	}

	THING extractMin() {

	}

	bool empty() {
		if (root == NULL)
			return true;
		else
			return false;
	}
};
