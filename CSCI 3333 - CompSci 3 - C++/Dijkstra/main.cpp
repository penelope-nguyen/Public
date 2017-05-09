#include <iostream>	
#include "weightedGraph.h"
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
	string fname = "NYC.txt";
	string source, destination, edge;
	string line;
	int num_vertices;

	ifstream stream(fname);

	getline(stream, line);
	num_vertices = stoi(line);

	// read in number of edges, but isn't really used. 
	getline(stream, line);

	weightedGraph graph(num_vertices);
		// read in file  
	
	clock_t startTime = clock();

	cout << "building map..." << endl;
	while (stream >> source >> destination >> edge) {

		graph.addVertex(source);
		graph.addVertex(destination);
		graph.addDirectedEdge(source, destination, edge);
	
	}

	clock_t endTime = clock();

	cout << "building map took: " << (endTime - startTime) / (double)CLOCKS_PER_SEC << "seconds" << endl << endl;

	startTime = clock();
	graph.Dijkstra("42155", "234370");
	endTime = clock();
	cout << "This took: " << (endTime - startTime) / (double)CLOCKS_PER_SEC << "seconds" << endl << endl;
	
	startTime = clock();
	graph.Dijkstra("34967", "983");
	endTime = clock();
	cout << "This took: " << (endTime - startTime) / (double)CLOCKS_PER_SEC << "seconds" << endl << endl;


	startTime = clock();
	graph.Dijkstra("90210", "211111");
	endTime = clock();
	cout << "This took: " << (endTime - startTime) / (double)CLOCKS_PER_SEC << "seconds" << endl << endl;

	return 0;
}