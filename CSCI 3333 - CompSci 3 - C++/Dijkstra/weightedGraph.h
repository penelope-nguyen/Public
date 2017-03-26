#include <iostream>
#include <string>
#include <list> //the stl's doubly linked list
#include <string>
#include <algorithm>
#include "queue.h"
using namespace std;

class weightedGraph
{
private:
	class vertex;
	class edge;
	class AVLTree;

	class edge {
		vertex * start;
		vertex * end;
		int weight;

		edge(vertex * s, vertex * e, int w) {
			start = s;
			end = e;
			weight = w;
		}

	};

	class vertex
	{
	public:
		int data;
		AVLTree * adjList;
		vertex * parent;
		bool visited;
		int weight;

		vertex(int x)
		{
			data = x;
			adjList = new AVLTree();
		}

	};

	class AVLTree
	{
	private:
		class node
		{
		public:
			vertex * vertex_node;
			int edge_weight;
			int height;
			node * left;
			node * right;

			node(vertex * v, int e)
			{
				vertex_node = v;
				edge_weight = e;
				height = 0;
				left = NULL;
				right = NULL;
			}
		};

		node * root = NULL;

		//insert x into tree rooted at p
		void insert(vertex * v, int e, node * &p)
		{

			if (p == NULL)
			{
				p = new node(v, e);
			}
			else
			{
				if (v->data < p->vertex_node->data)
				{
					//put in left subtree
					insert(v, e, p->left);
				}
				else
				{
					//put in right subtree
					insert(v, e, p->right);
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
				cout << p->vertex_node->data << "|" << p->edge_weight << " ";
				display(p->right);
			}
		}

		vertex * pop(node * p) {

			node * toDelete = root;

			
		}
	public:
AVLTree()
{
	root = NULL;
}

void insert(vertex *v, int e)
{
	insert(v, e, root);
}

void display()
{
	display(root);
}

int getHeight() {
	return root->height;
}

vertex * pop() {
	pop(root);
}

	};

	vertex ** vertexList;
	int max_size;

public:

	weightedGraph(int n) {
		vertexList = new vertex *[n];
		for (int i = 0; i < n; i++) {
			vertexList[i] = NULL;
		}
		max_size = n;
	}

	~weightedGraph()
	{
		//free all the (dynamically allocated) vertices.
	}

	//add a new vertex with data value x to the graph
	void addVertex(string x)
	{
		int index = stoi(x);
		if (vertexList[index] == NULL)
			vertexList[index] = new vertex(index);
	}

	void findDirectedEdge(string x) {

	}

	void display() {

		for (int i = 0; i < max_size; i++) {

			if (vertexList[i] != NULL) {
				cout << vertexList[i]->data << ": ";
				vertexList[i]->adjList->display();
				cout << endl;
			}
		}
		cout << endl;
	}

	vertex * findVertex(string v) {

		int index = stoi(v);

		if (vertexList[index] != NULL)
			return vertexList[index];

	}

	void addDirectedEdge(string x, string y, string e_weight) // int u 
	{
		vertex * x_vertex = findVertex(x);

		vertex * y_vertex = findVertex(y);

		if (x_vertex != NULL && y_vertex != NULL) {
			x_vertex->adjList->insert(y_vertex, stoi(e_weight));
		}

	}

	//add a basic edge (going both directions) connect x and y
	void addEdge(string x, string y, string e)
	{
		addDirectedEdge(x, y, e);
		addDirectedEdge(y, x, e);
	}

	void breadthFirstSearch(string x) {

		vertex * start = vertexList[stoi(x)];

		queue<int> Q;
		Q.push(start->data);
		start->visited = true;

		while (!Q.empty()) {
			for ()
		}

	}

	string shortestPath(string start, string end) {
		

	}

};