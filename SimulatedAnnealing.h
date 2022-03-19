#pragma once

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include "CargoItems.h"

using namespace std;

double function(double currWeight)
{
	//return x = pow(x, 4) + (4 / 3) * pow(x, 3) - 4 * pow(x, 2) + 5;
	return currWeight = ;

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

int simulatedAnnealing(double maxWeight, double initialT, double minimumT, double alpha, List& itemList) {

	double currWeight = 0; // setting of initial weight
	//double L = function(currWeight);
	double val = function(currWeight);

	while (maxWeight > currWeight)
	{
		for (double currT = initialT; currT > minimumT; currT *= alpha) // cooling schedule
		{
			for (int i = 0; i < 200; i++) // 
			{
				//double xNew = currWeight + ((rand() / (double)RAND_MAX) * 2 - 1);
				//double LNew = function(xNew);
				double newWeight = currWeight + itemList.cargo[grabItemIndex(itemList)].weight;
				double valNew = function(newWeight);

				if (valNew < val || (rand() / (double)RAND_MAX) <= pow(3, -(valNew - val) / currT))
				{
					val = valNew;
					currWeight = newWeight;
				}
			}
		}
	}

	cout << "Final state = " << currWeight << "\t, total of F(x) = " << function(currWeight) << "\n\n";

	return currWeight;
}



double grabItemIndex(List& itemList)
{
	Item indexItem;
	srand(time(0));
	size_t randomIndex = rand() % itemList.cargo.size();
	indexItem = itemList.cargo[randomIndex];
	if (indexItem.check = 1)
		return grabItemIndex(itemList);
	else
	{
		itemList.cargo[randomIndex].check = 1;

	}
	return indexItem.weight;
}