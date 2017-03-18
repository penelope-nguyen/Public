
#include <iostream>
#include <string>
#include <list> //the stl's doubly linked list
using namespace std;

class directedGraph
{
private:
	class vertex
	{
	public:
		string data;
		list<vertex*> adjList;

		vertex(string x)
		{
			data=x;
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
		vertex * newest = new vertex(x);
		vertexList.push_back(newest);
	}

	//add a directed edge going from x to y
	void addDirectedEdge(string x, string y)
	{
		//first, find the vertices holding x and y
		//Second, add an edge going from x's vertex to y's vertex

		vertex * parent = findVertex(x);
		if (parent != NULL) {
			parent->adjList.push_back(new vertex(y));
		}
	}


	//add a basic edge (going both directions) connect x and y
	void addEdge(string x, string y)
	{
		addDirectedEdge(x,y);
		addDirectedEdge(y,x);
	}

	//after implementing your "addVertex", "addDirectedEdge", and "addEdge" methods,
	//test that each added vertex is present, and it has the correct neighbors:
	void testDisplay()
	{
		for(list<vertex*>::iterator itr = vertexList.begin(); itr!= vertexList.end(); itr++)
		{
			vertex * v = (*itr);
			cout << v->data << ": ";
			for(list<vertex*>::iterator jtr=v->adjList.begin(); jtr!=v->adjList.end(); jtr++)
			{
				vertex * u = (*jtr);
				cout << u->data << ", ";
			}
			cout << endl;
		}
	}

	// helper function 
	vertex * findVertex(string x) { 

		for (list<vertex*>::iterator itr = vertexList.begin(); itr != vertexList.end(); itr++) {
			vertex * v = (*itr);
			if (v->data == x) {
				return v;
			}
		}

		return NULL;
	}

	void testBreadthFirstSearch(string x) {
		for (list<vertex*>::iterator itr = vertexList.begin(); itr != vertexList.end(); itr++) {
			vertex * v = (*itr);
		}
	}
};