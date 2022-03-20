#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using std::string;
using std::vector;
using namespace std;

struct Item {
	double utility;
	double weight;
	int check;
};

struct List {
	vector<Item> cargo;
};

void initializeItemList(List& listItems) {
	ifstream inFile;
	inFile.open("Program2Input.txt");
	
	if (!inFile) {
		cerr << "Unable to open input file" << endl;
	}
	
	double priorityFile;
	double weightFile;
	while (inFile >> priorityFile >> weightFile)
	{
		Item item;
		item.utility = priorityFile;
		item.weight = weightFile;
		item.check = 0;
		//cout << item.priority << "\t" << item.weight << "\t" << item.check << endl;
		listItems.cargo.push_back(item);
	}
}
