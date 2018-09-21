/*
 * driver.cpp
 *
 *  Created on: Apr 15, 2018
 *      Author: Yuun
 */




#include "tree.h"
#include <iostream>
#include <fstream>

#include <string>

void print_count(const string& key, int& value) {
	cout << value << "\t" << key << endl;
}

int main() {
	Tree<string, int> count;
	string word;

	while (cin >> word) {
		++count[word];
	}

	count.dump();

	for (auto it = count.begin(); it != count.end(); ++it)
	{
		print_count((*it).first, (*it).second);
	}
	return 0;
}
