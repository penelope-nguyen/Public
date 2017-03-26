#include <iostream>	
#include "weightedGraph.h"
#include "queue.h"
#include <fstream>

#include <ctime>
using namespace std;

int main()
{
	string temp_string;
	int num_vertices;
	int num_edges; 
	string fname = "NYC_test.txt";
	string word;
	string source;
	string destination;
	string edge;

	ifstream stream(fname);

	getline(stream, temp_string);

	num_vertices = stoi(temp_string);
	getline(stream, temp_string);
	num_edges = stoi(temp_string);

	weightedGraph graph(num_vertices);
		// read in file  
	
	clock_t startTime = clock();

	while (stream) {
		stream >> source;
		stream >> destination;
		stream >> edge;

		graph.addVertex(source);
		graph.addVertex(destination);
		graph.addDirectedEdge(source, destination, edge);
	}
	clock_t endTime = clock();

	cout << "building map took: " << (endTime - startTime) / (double)CLOCKS_PER_SEC << "seconds" << endl;
	
	return 0;
}