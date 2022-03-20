#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "SimulatedAnnealing.h"

using std::string;
using std::vector;
using namespace std;

struct Item {
	double priority;
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
		item.priority = priorityFile;
		item.weight = weightFile;
		item.check = 0;
		//cout << item.priority << "\t" << item.weight << "\t" << item.check << endl;
		listItems.cargo.push_back(item);
	}
}

void csvlogger(List& inCargo)
{
	auto now = chrono::system_clock::now();
	auto UTC = chrono::duration_cast<chrono::seconds>(now.time_since_epoch()).count();
	ofstream loggerfile("SimulatedAnneal_Log_" + to_string(UTC) + ".csv");
	loggerfile << "Item Num" << "," << "Utility" << "," << "Weight" << "\n";
	for (int i = 0; i < inCargo.cargo.size(); i++)
	{
		loggerfile << i + 1 << "," << inCargo.cargo[i].priority << "," << inCargo.cargo[i].weight << "\n";
	}
	loggerfile.close();
}

void txtlogger(List& inCargo, double currWeight, double currUtility)
{
	auto now = chrono::system_clock::now();
	auto UTC = chrono::duration_cast<chrono::seconds>(now.time_since_epoch()).count();
	ofstream txtfile("PokerSummary_" + to_string(UTC) + ".txt");

	txtfile << "For the simulated annealing configuration the following results appear: \n";
	txtfile << "\t - The total number of items in cargo is: " << inCargo.cargo.size() << "\n";
	txtfile << "\t - The total weight of cargo is: " << weightCalc(inCargo) << "\n";
	txtfile << "\t - The total utility of cargo is: " << utilityCalc(inCargo) << "\n";
	txtfile.close();
}