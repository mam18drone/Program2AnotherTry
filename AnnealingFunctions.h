#pragma once
#include <iostream>
#include <ctime>
#include "CargoItems.h"
#include <random>
#include <cstdlib>

using namespace std;

double functionRand(double x, double weight)
{

	x = pow(x, 4) + (4 / 3) * pow(x, 3) - 4 * pow(x, 2) + 5;
	return x;
}

int randIndex(List& listItems)
{
	int randomIndex = rand() % listItems.cargo.size();
	return randomIndex;
}

bool indexCheck(List& listItems,int& index)
{
	index = randIndex(listItems);
	Item indexItem = listItems.cargo[index];
	if (indexItem.check == 0)
	{
		listItems.cargo[index].check == 1;
		return true;
	}
	else
		return false;
}

bool probabilityStep(double deltE, double currT)
{
	double prob = exp(-deltE / currT);
	if (prob > 0.50)
		return true;
	else
		return false;
}

double randChange(List& listItems)
{
	
	return 0;
}

void cargoRandom(List& listItems, List& inCargo, int count, double& currWeight, double& currUtility)
{
	int index;
	int i = 0;
	while (i < count)
	{
		if (indexCheck(listItems,index))
		{
			currWeight = currWeight + listItems.cargo[index].weight;
			currUtility = currUtility + listItems.cargo[index].priority;
			inCargo.cargo.push_back(listItems.cargo[index]);
			i++;
		}
	}
}

/*
void shuffle(List& listItems)
{
	List copy;
	while (!listItems.cargo.empty())
	{
		srand(time(0));
		size_t randomIndex = rand() % listItems.cargo.size();
		copy.cargo.push_back(listItems.cargo[randomIndex]);
		listItems.cargo.erase(listItems.cargo.begin() + randomIndex);
	}
	listItems = copy;
}
*/