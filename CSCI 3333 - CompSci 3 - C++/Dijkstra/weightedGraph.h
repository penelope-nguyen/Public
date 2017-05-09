#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;


class weightedGraph
{
private:
	class vertex;
	class edge;

	vector<vertex*> vertexList;
	int max_size;

	class edge {
	public:
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
		vector<edge*>adjList;
		vertex * parent;
		bool visited;
		int weight;
		int index;

		vertex(int x)
		{
			data = x;
		}

	};


	class minHeap {
		vector <vertex*> heap;
	private:
		void bubbleUp(int child) {
			int parent;

			if (child % 2 == 0)
				parent = (child - 2) / 2;
			else
				parent = (child - 1) / 2;

			if (parent >= 0) {
				if (heap[parent]->weight > heap[child]->weight) {
					swap(heap[parent]->index, heap[child]->index);
					swap(heap[parent], heap[child]);
					bubbleUp(parent);
				}
				else
					return;
			}
		}

		void bubbleDown(int index) {
			int size = heap.size() - 1;
			int left = (2 * index) + 1;
			int right = (2 * index) + 2;
			int smallest = index;

			if (left > size) {
				return;
			}
			if (heap[left]->weight < heap[smallest]->weight)
				smallest = left;

			if (right <= size) {
				if (heap[right]->weight < heap[smallest]->weight)
					smallest = right;
			}

			if (smallest != index) {
				swap(heap[smallest]->index, heap[index]->index);
				swap(heap[smallest], heap[index]);
				bubbleDown(smallest);
			}
		}
	public:

		minHeap() {

		}

		void insert(vertex * x) {
			if (x->index == -1) {
				x->index = heap.size() - 1;
				heap.push_back(x);
			}
			bubbleUp(x->index);
		}

		vertex * extractMin() {
			int size = heap.size() - 1;
			vertex * minValue = heap[0];
			swap(minValue->index, heap[size]->index);
			swap(heap[0], heap[size]);
			heap.pop_back();
			bubbleDown(0);
			return minValue;
		}

		bool empty() {
			if (heap.size() < 1)
				return true;
			else
				return false;
		}

		void display() {

			for (int i = 0; i < heap.size(); i++) {
				cout << heap[i]->data << ": " << heap[i]->weight << endl;
			}
			cout << endl;
		}
	};
	public:

	weightedGraph(int n) {
			max_size = n;
			vertexList = vector<vertex*>(max_size);
		}

	~weightedGraph()
		{
		for (int i = 0; i < max_size; i++) {
			delete vertexList[i];
			vertexList[i] = NULL;
			}
		}

		void addVertex(string x)
		{

			int index = stoi(x);
			if (vertexList[index] == NULL)
				vertexList[index] = new vertex(index);
		}
		
		void display() {

			for (int i = 0; i < max_size; i++) {
				if (vertexList[i] != NULL) {
					cout << vertexList[i]->data << ": ";
					int adjListSize = vertexList[i]->adjList.size();
					for (int j = 0; j < adjListSize; j++) {
						cout << vertexList[i]->adjList[j]->end->data << "|" << vertexList[i]->adjList[j]->weight << " " ;
					}
					cout << endl;
				}
			}

		}

		vertex * findVertex(string v) {

			int index = stoi(v);

			return vertexList[index];

		}

		void addDirectedEdge(string x, string y, string e_weight) // int u 
		{
			vertex * x_vertex = findVertex(x);
			vertex * y_vertex = findVertex(y);

			int edge_weight = stoi(e_weight);
			if (x_vertex != NULL && y_vertex != NULL) {

				edge * new_edge = new edge(x_vertex, y_vertex, edge_weight);
				x_vertex->adjList.push_back(new_edge);
			}
		}

		void addEdge(string x, string y, string e)
		{
			addDirectedEdge(x, y, e);
			addDirectedEdge(y, x, e);
		}

		void Dijkstra(string x, string y) {
			vertex * source = findVertex(x);
			minHeap heap;
			for (int i = 0; i < max_size; i++) {
				vertexList[i]->visited = false;
				vertexList[i]->parent = NULL;
				vertexList[i]->weight = std::numeric_limits<int>::max(); // set weight to infinity 
				vertexList[i]->index = -1;
			}

			source->weight = 0;
			heap.insert(source);

			while (!heap.empty()) {
				vertex * current = heap.extractMin();
				current->visited = true;
				int size = current->adjList.size();
				for (int i = 0; i < size; i++) {

					vertex * neighbor = current->adjList[i]->end;

					if (!neighbor->visited) {
						int edgeWeight = current->weight + current->adjList[i]->weight;

						if (edgeWeight < neighbor->weight) {
							neighbor->weight = edgeWeight;
							neighbor->parent = current;
							heap.insert(neighbor);
						} // bracket edgeWeight < neighbor
					} // bracket !neighbor
				} // bracket for loop 
			} // while !heap.empty

			
			vertex * current = findVertex(y);
			int cost = current->weight;
			string path = "";
			cout << "Computing shortest path from " << source->data << " to " << current->data << ": " << endl;
			while (current->parent != NULL) {
				path = "to " + to_string(current->data) + " " + path;
				current = current->parent;
			}

			if (current == source) 
				path = to_string(current->data) + " " + path;
			else {
				path = "No path was found.";
				cost = -1;
			}
			cout << path << endl;
			cout << "Cost is: " << cost << endl;
		}
	
};