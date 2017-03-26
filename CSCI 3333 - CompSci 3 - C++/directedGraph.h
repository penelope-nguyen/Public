
#include <iostream>
#include <string>
#include <list> //the stl's doubly linked list
#include <queue>
using namespace std;

class directedGraph
{
private:
	class vertex
	{
	public:
		string data;
		list<vertex*> adjList;
		vertex * parent;
		bool visited;
		vertex(string x)
		{
			data = x;
		}
	};

	list<vertex*> vertexList; //should really use.. hash table, or AVL-tree

public:

	~directedGraph()
	{
		//free all the (dynamically allocated) vertices.
	}

	//add a new vertex with data value x to the graph
	void addVertex(string x)
	{

		vertexList.push_back(new vertex(x));

	}

	//add a directed edge going from x to y
	void addDirectedEdge(string x, string y)
	{
		//first, find the vertices holding x and y
		//Second, add an edge going from x's vertex to y's vertex


		vertex * y_node = NULL;
		vertex * x_node = NULL;

		for (list<vertex*>::iterator itr = vertexList.begin(); itr != vertexList.end(); itr++)
		{
			vertex * v = (*itr);
			if (v->data == x) {
				x_node = v;
			}
			if (v->data == y)
				y_node = v;
		}

		if (x_node != NULL && y_node != NULL) {
			x_node->adjList.push_back(y_node);
		}
	}

	//add a basic edge (going both directions) connect x and y
	void addEdge(string x, string y)
	{
		addDirectedEdge(x, y);
		addDirectedEdge(y, x);
	}

	//after implementing your "addVertex", "addDirectedEdge", and "addEdge" methods,
	//test that each added vertex is present, and it has the correct neighbors:
	void testDisplay()
	{
		for (list<vertex*>::iterator itr = vertexList.begin(); itr != vertexList.end(); itr++)
		{
			vertex * v = (*itr);
			cout << v->data << ": ";
			for (list<vertex*>::iterator jtr = v->adjList.begin(); jtr != v->adjList.end(); jtr++)
			{
				vertex * u = (*jtr);
				cout << u->data << ", ";
			}
			cout << endl;
		}

		cout << endl;
	}

	void testBreadthFirstSearch(string x) {

		queue<vertex*> Q;

		for (list<vertex*>::iterator itr = vertexList.begin(); itr != vertexList.end(); itr++)
		{
			vertex * v = (*itr);
			v->parent = NULL;
			v->visited = false;
			if (v->data == x) {
				Q.push(v);
				v->visited = true;
			}
		}

		while (!Q.empty()) {
			vertex * current = Q.front();
			Q.pop();
			for (list<vertex*>::iterator jtr = current->adjList.begin(); jtr != current->adjList.end(); jtr++) {
				vertex * v = (*jtr);
				if (!(v->visited)) {
					Q.push(v);
					v->visited = true;
					v->parent = current;
				}
			}
		}

		for (list<vertex*>::iterator itr = vertexList.begin(); itr != vertexList.end(); itr++)
		{
			vertex * v = (*itr);
			cout << v->data << ": ";
			if (v->parent != NULL)
				cout << v->parent->data;
			cout << endl;
		}

		cout << endl;
	}

	string shortestPath(string start, string end) {
		testBreadthFirstSearch(start);
		
		vertex * current;
		string path = "";
		// finds the last node / node containing end 
		for (list<vertex*>::iterator itr = vertexList.begin(); itr != vertexList.end(); itr++)
		{
			vertex * v = (*itr);
			if (v->data == end) {
				current = v;
			}
		}

		// assuming there is a path from start to end
		// otherwise idk lol 
		while (current->parent != NULL) {
			path = current->data + " " + path;
			current = current->parent;
		}

		path = current->data + " " + path;

		if (current->data != start)
			path = "";
		
		return path;

	}

};