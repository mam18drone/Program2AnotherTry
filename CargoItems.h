#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using namespace std;

enum Priority { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN };

struct Item {
	int priority;
	double weight;
	int check;
};

struct List {
	vector<Item> items;
};

bool initializeItemList(List& listItems) {
	ifstream inFile;
	inFile.open("Program2Input.txt");
	/*
	if (!inFile) {
		cerr << "Unable to open input file" << endl;
		return false;
	}
	*/
	int priorityFile;
	double weightFile;
	int checkFile;
	Item item;

	//int column1, column2;
	/*
	while (inFile >> priorityFile >> weightFile >> checkFile)
	{
		item.priority = priorityFile;
		item.weight = weightFile;
		item.check = checkFile;
		listItems.items.push_back(item);
	}
	return true;
	*/
}