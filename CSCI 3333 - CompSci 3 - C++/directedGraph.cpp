#include <iostream>
#include <string>
#include "directedGraph.h"
#include <fstream>
#include <sstream>
using namespace std;

string * read_file_into_array(string fname, int &h, int &w) {
	
	string row;
	int ctr = 0;

	ifstream file;
	file.open(fname);

	while (file >> row) {
		h += 1;
	}

	w = row.length();
	file.close();

	file.open(fname);
	string * maze_array = new string[h*w];

	while (file >> row) {

		for (int i = 0; i < w; i++) {
			maze_array[ctr] = row[i];
			ctr += 1;
		}

	}

	return maze_array;
}

int main() {

	directedGraph graph;
	
	//part 1:  implement "addVertex", "addDirectedEdge", and "addEdge"
	graph.addVertex("a");
	graph.addVertex("b");
	graph.addVertex("c");
	graph.addVertex("d");
	graph.addVertex("e");
	graph.addVertex("f");
	
	graph.addEdge("a", "b");
	graph.addEdge("a", "c");
	graph.addEdge("b", "d");
	graph.addEdge("c", "d");
	graph.addEdge("c", "e");
	graph.addEdge("e", "d");
	graph.addEdge("e", "f");
	graph.addDirectedEdge("f", "a");
	
	//test that your add methods correctly build the graph:
	//should display:
	//a: b c
	//b: a d
	//c: a d e
	//d: b c 
	//e: c d f
	//f: e a
	

	graph.testDisplay();
	
	//Part 2: Implement breadth first search.

	//Implement a test method that:
	//1: runs breadth first search with respect to given vertex
	//2: displays each vertex and its predecessor

	//list each vertex in the graph and display which vertex is its predecessor
	//on a shortest path starting from vertex "c".

	graph.testBreadthFirstSearch("c");
	

	//list each vertex in the graph and display which vertex is its predecessor
	//on a shortest path starting from vertex "a".
	graph.testBreadthFirstSearch("a");

	//etc.
	graph.testBreadthFirstSearch("f");
	graph.testBreadthFirstSearch("d");

	
	//part 2: Use breadth first search to compute shortest paths
	cout << "Shortest path from a to f: " << graph.shortestPath("a", "f") << endl;

	int width = 0;
	int height = 0;

	int total; 
	int start_pos;
	int end_pos;

	string start;
	string end;
	directedGraph graphMaze;
	string * maze;
	
	maze = read_file_into_array("maze.txt", height, width);
	total = width * height;

	/*

	for (int i = 0; i < total; i++) {
		cout << i << maze[i] << " ";
		if (i % width == (width - 1))
			cout << endl;
	}
	*/

	// creating vertices from maze as well as determining start/end
	// o's are vertices, x's are walls 
	for (int i = 0; i < total; i++) {
		if (maze[i] != "x") {
			if (maze[i] == "d") {
				end_pos = i;
				end = to_string(i);
			}
			if (maze[i] == "s") {
				start_pos = i;
				start = to_string(i);
			}
			string vertex = to_string(i);
			graphMaze.addVertex(vertex);
		}
	}

	// creating edges 
	for (int j = 0; j < total; j++) {
		if (maze[j] != "x") {
			// if moves are possible, add edges 
			string current = to_string(j);
			string left = to_string(j - 1);
			string right = to_string(j + 1);
			string up = to_string(j - width);
			string down = to_string(j + width);
			// right move 
			if (j >= width)
				graphMaze.addDirectedEdge(current, up);
			if (j % width != 0)
				graphMaze.addDirectedEdge(current, left);
			if (j % width != width - 1)
				graphMaze.addDirectedEdge(current, right);
			
			if (j <= total - width)
				graphMaze.addDirectedEdge(current, down);
		}
	}

	// graphMaze.testDisplay();

	graphMaze.testBreadthFirstSearch(start);
	string shortest(graphMaze.shortestPath(start, end));

    string buf; 
    stringstream ss(shortest); 

    vector<string> paths; 

    while (ss >> buf) { 
		paths.push_back(buf);
	}

	while (!paths.empty()) {
		int path = stoi(paths.back());
		if (path != start_pos && path != end_pos)
			maze[path] = "*";
		paths.pop_back();
	}

	// for printing out purposes 
	for (int i = 0; i < total; i++) {
		cout << maze[i];
		if (i % width == (width - 1))
			cout << endl;
	}

	cout << endl;
	return 0;
}