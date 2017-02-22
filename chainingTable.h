#include "linkedList.h"

class chainingTable
{
private:
	//hash table conists of a table of lists
	linkedList * table;

	//size of table
	int capacity;

	//number of items in hash table
	int numItems;

	int hash(string x) {
		// turn first letter into lowercase 
		// then transform into hash index
		int length = x.length();
		int hashvalue = tolower(x.at(0)) - 97;;
		for (int pos = 1; pos < 10; pos++) {
			if (pos >= length)
				break;
			int sec_value = tolower(x.at(pos)) - 97;
			if (sec_value > 10)
				hashvalue += 26;
		}
		return hashvalue;
	}
public:
	
	chainingTable() {
		capacity = 26 * 10; 
		table = new linkedList[capacity];
		numItems = 0;
	}
	//use this to measure how good your
	//hash function is.
	double averageSearchCost()
	{
		double sumSquares = 0;
		for (int i = 0; i<capacity; i++)
		{
			sumSquares += (table[i].size()*table[i].size());
		}
		return sumSquares / numItems;
	}

	void insert(string x)
	{ 
		int index = hash(x);

		table[index].insert(x);
		numItems += 1;
	}

	bool contains(string x)
	{
		int index = hash(x);
		
		return table[index].contains(x);

		}

	int getnumItems() {
		return numItems;
	}

	void printTable() {
		for (int i = 0; i < capacity; i++)
			cout << i << ": " << table[i].size() << endl;
	}
};
