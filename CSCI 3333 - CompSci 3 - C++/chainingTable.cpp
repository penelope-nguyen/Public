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
		string new_word = "";
		int length = word.length();
		
		for (int i = 0; i < length; i++) {
			char letter = word.at(i);
			int ascii = word.at(i);

			if (ascii > 64 && ascii < 91)
				new_word += letter;
			else if (ascii > 96 && ascii < 123)
				new_word += letter;
			else {
				if (new_word.length() != 0) {
					if (!ct.contains(new_word))
						outfile << new_word << endl;
				}
				new_word = "";
				continue;
			}

		}
		if (new_word.length() != 0) {
			if (!ct.contains(new_word))
				outfile << new_word << endl;
		}
	}
	outfile.close();
	file.close();
	return 0;

}
