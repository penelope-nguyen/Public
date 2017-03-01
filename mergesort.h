#include <iostream>
using namespace std;

class linkedList {
private:
	class node {
	public:
		int data;
		node * next;
		node * previous;

		node() {
			next = NULL;
			previous = NULL;
		}
	};

	node *head;
	node *tail;

	static int findMid(linkedList aList) {

		if (aList.head == NULL)
			return 0;

		int count = 1;
		node * someNode = aList.head;

		while (someNode->next != NULL) {
			count++;
			someNode = someNode->next;
		}

		return count / 2;
	}



public:

	linkedList() {
		head = NULL;
		tail = NULL;
	}

	void display() {

		if (head == NULL) {
			cout << endl;
			return;
		}

		node * current = head;
		while (current != tail) {
			cout << current->data << " ";
			current = current->next;
		}

		cout << current->data << " ";

	}

	void push_back(int someData) {

		node * newNode = new node;
		newNode->data = someData;

		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}

		else {
			tail->next = newNode;
			newNode->previous = tail;
			tail = tail->next;
		}

	}

	static void split(linkedList & listA, linkedList & listB) {

		// find middle node: 

		node * midNode = listA.head;

		for (int i = 1; i < findMid(listA); i++) {
			midNode = midNode->next;
		}

		// middle node is now tail of listA, the node after middle is the head of B 
		// tail of A is tail of B

		listB.head = midNode->next;
		listB.head->previous = NULL;
		listB.tail = listA.tail;


		listA.tail = midNode;
		listA.tail->next = NULL;
	}


	void transfer(linkedList & someList) {

		node * newNode = someList.head;

		push_back(newNode->data);

		if (someList.head->next != NULL) {
			someList.head = newNode->next;
			someList.head->previous = NULL;
			delete newNode;
		}

		else {
			delete newNode;
			someList.head = NULL;
			someList.tail = NULL;
		}

	}

	static void merge(linkedList & listOne, linkedList & listTwo, linkedList & listMerged) {

		node * transferNode;

		while ((listOne.head != NULL) && (listTwo.head != NULL)) {
			if (listOne.head->data < listTwo.head->data)
				listMerged.transfer(listOne);
			else
				listMerged.transfer(listTwo);
		}

		if (listOne.head != NULL)
			listMerged.transfer(listOne);

		if (listTwo.head != NULL)
			listMerged.transfer(listTwo);

	}

	void static mergeSort(linkedList & someList) {
		
		linkedList otherList;
		linkedList mergedList;

		if (someList.head->next == NULL)
			return;

		else {
			split(someList, otherList);
			mergeSort(someList);
			mergeSort(otherList);
			merge(someList, otherList, mergedList);
			someList = mergedList;
		}

	}

};
