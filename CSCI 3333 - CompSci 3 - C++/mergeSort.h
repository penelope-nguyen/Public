#include <iostream>
using namespace std;

template <class T>
class linkedList
{
private:
	class node
	{
	public:
		T data;
		node * next;
		node * prev;

		node(T x)
		{
			data = x;
			next = NULL;
			prev = NULL;
		}
	};

	node * head;
	node * tail;

	int numItems;

	void split(node * head1, node * tail2, node * & tail1, node * & head2, int num_nodes) {

		// t2 being the original tail 

		node * traverse = head1;

		int mid = num_nodes / 2 - 1;

		for (int num = 0; num < mid; num++) {
			traverse = traverse->next;
		}

		tail1 = traverse;
		head2 = traverse->next;

		head2->prev = NULL;
		tail1->next = NULL;

		
	}

	void merge(node * & head1, node * tail1, node * head2, node * & tail2) {

		node * trv = head1;

		trv = head2;
		node * trv_1 = head1;
		node * trv_2 = head2;

		node * new_head;
		node * new_tail;

		if (trv_1->data < trv_2->data) {
			new_head = trv_1;
			trv_1 = trv_1->next;
		}
		else {
			new_head = trv_2;
			trv_2 = trv_2->next;
		}
		new_tail = new_head;

		
		while (trv_1 != NULL && trv_2 != NULL) {
	
			if (trv_1->data < trv_2->data) {
				new_tail->next = trv_1;
				trv_1 = trv_1->next;
			}
			else {	

				new_tail->next = trv_2;
				trv_2 = trv_2->next;
			}

			new_tail = new_tail->next;
		}

		if (trv_1 == NULL) {
			new_tail->next = trv_2;
		}

		if (trv_2 == NULL) {
			new_tail->next = trv_1;
		}

		while (new_tail->next != NULL) {
			new_tail = new_tail-> next;
		}
		head1 = new_head;
		tail2 = new_tail;

		trv = new_head;
	}

	//merge sort the list from node h to t
	void mergeSort(node * &h, node * &t, int num_nodes)
	{


		if (h != NULL && h != t) //2 or more items, otherwise base case of nothing
		{

			//step 1: split list into 2
			//point t1 and h2 to nodes such that: 
			//the left half of the list is from node h to t1, right half from node h2 to t
			node * t1;
			node * h2;
			split(h, t, t1, h2, num_nodes);

			//step 2: sort 2 halves
			
			int split_num_nodes = num_nodes / 2;
			mergeSort(h, t1, split_num_nodes);
			
			mergeSort(h2, t, split_num_nodes);

			//step 3: merge sorted halves back together
			//into a single sorted list

			merge(h, t1, h2, t);
		
		}
	}



public:
	linkedList()
	{
		head = NULL;
		tail = NULL;
		numItems = 0;
	}

	//frees all dynamically allocated memory (the nodes in the list)
	~linkedList()
	{
		while (!empty())
		{
			pop_front();
		}
	}


	int size()
	{
		return numItems;
	}

	//add item x to back of list
	void push_back(T x)
	{
		numItems++;
		if (head == NULL)
		{
			head = new node(x);
			tail = head;
		}
		else
		{
			tail->next = new node(x);
			tail->next->prev = tail;
			tail = tail->next;
		}
	}

	//remove and return the first item in the list
	T pop_front()
	{
		numItems--;
		T output = head->data;
		if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = NULL;
		}
		return output;
	}

	void display()
	{

		node * c = head;
		while (c != NULL)
		{
			cout << c->data << ",";
			c = c->next;
		}
		cout << endl;
	}

	bool empty()
	{
		return (numItems == 0);
	}

	void mergeSort()
	{
		mergeSort(head, tail, numItems);
	}

};
