#include <iostream>
#include <algorithm>
using namespace std;
class AVLTree
{
private:
	class node
	{
	public:
		double data;
		int height;
		node * left;
		node * right;

		node(double x)
		{
			data = x;
			height = 0;
			left = NULL;
			right = NULL;
		}
	};

	node * root;

	//insert x into tree rooted at p
	void insert(double x, node * &p)
	{
		if (p == NULL)
		{
			p = new node(x);
		}
		else
		{
			if (x < p->data)
			{
				//put in left subtree
				insert(x, p->left);
			}
			else
			{
				//put in right subtree
				insert(x, p->right);
			}

			updateNodeHeight(p);

			if (isUnbalanced(p)) {
				rotate(p);
			}
		}
	}

	
	void subtreeHeight(node *p, int &left, int &right) {
		// returns height of left and right subtrees (children)
		// most useful method 10/10 

		left = -1; 
		right = -1;

		if (p->left != NULL)
			left = p->left->height;

		if (p->right != NULL)
			right = p->right->height;
	}


	void updateNodeHeight(node *& p) {

		int left_child, right_child;
		subtreeHeight(p, left_child, right_child);

		p->height = 1 + max(left_child, right_child);

	}

	bool isUnbalanced(node * p) {

		int left_child, right_child;

		subtreeHeight(p, left_child, right_child);

		if (abs(left_child - right_child) > 1)
			return true;
		else
			return false;

	}

	void rotate(node * & p) {

		int l_child_height, r_child_height;
		int l_Gchild_height, r_Gchild_height;
		node * childNode; 

		subtreeHeight(p, l_child_height, r_child_height);


		// CASE 1: LEFT ROTATION - LEFT CHILD AND GRANDCHILD HEIGHT ARE GREATER THAN THEIR COUNTERPARTS 
		// CASE 2: LEFT RIGHT ROTATION - LEFT CHILD HEIGHT > RIGHT CHILD HEIGHT, 
		//         BUT LEFT GRANDCHILD HEIGHT < RIGHT GRANDCHILD HEIGHT 

		if (l_child_height> r_child_height) {

			childNode = p->left; 
			subtreeHeight(childNode, l_Gchild_height, r_Gchild_height);
			if (l_Gchild_height > r_Gchild_height)
				leftRotation(p);
			else
				leftRight(p);
		}

		// CASE 3: RIGHT ROTATION - RIGHT CHILD AND GRANDCHILD HEIGHT ARE GREATER THAN THEIR COUNTERPARTS 
		// CASE 2: RIGHT ROTATION - RIGHT CHILD HEIGHT > LEFT CHILD HEIGHT, 
		//         BUT RIGHT GRANDCHILD HEIGHT < LEFT GRANDCHILD HEIGHT 		
		else
		{
			childNode = p->right; 
			subtreeHeight(childNode, l_Gchild_height, r_Gchild_height);

			if (l_Gchild_height < r_Gchild_height)
				rightRotation(p);
			else
				rightLeft(p);

		}

		updateNodeHeight(p->left);
		updateNodeHeight(p->right);

		updateNodeHeight(p);

	}
	
	void leftRotation(node *&p) {

		node * new_r_child = p;
		node * new_parent = p->left;
		
		new_r_child->left = new_parent->right;
		new_parent->right = new_r_child;
		
		if (root == p)
			root = new_parent;

		p = new_parent;
		
	}
	void rightRotation(node *&p) {

		
		node * new_l_child = p;
		node * new_parent = p->right;
		new_l_child->right = new_parent->left;
		new_parent->left = new_l_child;

		if (root == p)
			root = new_parent;

		p = new_parent;
	}
	void leftRight(node *&p) {

		node * new_r_child = p;
		node * new_l_child = p->left;
		node * new_parent = p->left->right;

		new_l_child->right = NULL;
		new_r_child->left = new_parent->right;
		new_parent->right = new_r_child;
		new_parent->left = new_l_child;

		if (p == root)
			root = new_parent;
		p = new_parent;

	}
	void rightLeft(node *&p) {

		node * new_l_child = p;
		node * new_r_child = p->right;
		node * new_parent = p->right->left;

		new_r_child->left = new_parent->left;
		new_l_child->right = NULL;
		new_parent->left = new_l_child;
		new_parent->right = new_r_child;

		if (p == root)
			root = new_parent;
		p = new_parent;
	}

	void display(node * p)
	{
		if (p == NULL)
		{
		}
		else
		{
			display(p->left);
			cout << p->data << endl;
			display(p->right);
		}
	}

public:
	AVLTree()
	{
		root = NULL;
	}

	void insert(double x)
	{
		insert(x, root);
	}

	void display()
	{
		display(root);
	}

	int getHeight() {
		return root->height;
	}
	};