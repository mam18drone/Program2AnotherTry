#pragma once

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

double function(double currWeight)
{
	//return x = pow(x, 4) + (4 / 3) * pow(x, 3) - 4 * pow(x, 2) + 5;
	return currWeight = ;

}

double grabItemIndex(List& itemList)
{
	Item indexItem;
	srand(time(0));
	size_t randomIndex = rand() % itemList.items.size();
	indexItem = itemList.items[randomIndex];
	if (indexItem.check = 1)
		return grabItemIndex(itemList);
	else
	{
		itemList.items[randomIndex].check = 1;

	}
	return indexItem.weight;
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
				double newWeight = currWeight + itemList.items[grabItemIndex(itemList)].weight;
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
