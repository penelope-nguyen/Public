
#include "chainingTable.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {

	chainingTable ct;


	ifstream file;
	file.open("dictionary.txt");
	string word;
	while (file >> word) {
		ct.insert(word);
	}

	// ct.printTable();
	cout << endl << ct.averageSearchCost() << endl;
	ofstream outfile;
	outfile.open("not_words.txt");
	ifstream poe;
	poe.open("raven.txt");
	while (poe >> word) {
		string new_word;
		int length = word.length();

		for (int i = 0; i < length; i++) {
			int ascii = word.at(i);

			if (ascii >= 97 && ascii <= 122)
				new_word += char(ascii);
			else if (ascii >= 65 && ascii <= 90)
				new_word += char(ascii);
			else {
				if (i < length - 1)
					cout << new_word << " ";
					
				new_word = "";
				continue;
			}

		}
		cout << new_word << " ";
		
	}
	outfile.close();
	file.close();
	return 0;

}