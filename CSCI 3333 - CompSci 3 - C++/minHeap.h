#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

template<class THING> class minHeap {
private:

	vector <THING> heap;

	void bubbleUp(int child) {
		int parent;

		if (child % 2 == 0)
			parent = (child - 2)/2;
		else
			parent = (child - 1)/2;

		if (parent >= 0) {
			if (heap[parent] > heap[child]) {
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
		if (heap[left] < heap[smallest])
			smallest = left;

		if (right <= size) {
			if (heap[right] < heap[smallest])
				smallest = right;
		}

		if (smallest != index) {
			swap(heap[smallest], heap[index]);
			bubbleDown(smallest);
		}
	}

public:

	minHeap() {
		
	}

	void insert(THING x) {
		heap.push_back(x);
		bubbleUp(heap.size() - 1);
	}

	THING extractMin() {
		int size = heap.size() - 1;
		THING minValue = heap[0];
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
			cout << i << ": " << heap[i] << endl; 
		}
		cout << endl;
	}
};