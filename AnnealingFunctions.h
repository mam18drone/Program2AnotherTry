#pragma once
#include <iostream>
#include <ctime>
#include "CargoItems.h"

using namespace std;

double functionRand(double x, double weight)
{

	x = pow(x, 4) + (4 / 3) * pow(x, 3) - 4 * pow(x, 2) + 5;
	return x;
}

int randIndex(List& listItems)
{
	srand(time(0));
	int randomIndex = rand() % listItems.cargo.size();
	return randomIndex;
}

bool indexCheck(List& listItems, int index)
{
	Item indexItem = listItems.cargo[index];
	if (indexItem.check == 0)
	{
		listItems.cargo[index].check == 1;
		return true;
	}
	else
		return false;
}

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

bool probabilityStep(double deltE, double currT)
{
	double prob = exp(-deltE / currT);
	if (prob > 0.50)
		return true;
	else
		return false;
}