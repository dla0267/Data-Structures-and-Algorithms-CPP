/*
 * Wordcount.cpp
 *
 *  Created on: Apr 9, 2018
 *      Author: Yuun
 */

#include "BST.h"

#include <string>

#include <iostream>

#include <fstream>

using namespace std;

void print_count(const string& key, int& value) {
	cout << value << "\t" << key << endl;
}

int main() {

	BST<string, int> count;
	string word;

	while (cin >> word) {++count[word];}

	for (auto it = count.begin(); it != count.end(); ++it)
	{
		print_count((*it).first, (*it).second);
	}

	count.dump();

	return 0;
}


