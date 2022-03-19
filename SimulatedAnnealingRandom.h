#pragma once

#include <iostream>
//#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "CargoItems.h"
#include "AnnealingFunctions.h"
#include <math.h>

using namespace std;

double simulatedAnnealingRand(double maxWeight, double initialT, double minimumT, double alpha, List& listItems) {
	double currWeight = 0; // setting of initial weight
	double currUtility = 0; // setting of initial utility
	double val = functionRand(currWeight, 10);
	int index; // initialize index for random assignment
	double newWeight; // initialize the additive weight to cargo
	double newUtility; // initialize the additive utiliity
	int attempt = 0;
	int attemptLimit;
	
	for (double currT = initialT; currT > minimumT; currT *= alpha) // cooling schedule
	{
		shuffle(listItems);
		index = randIndex(listItems);
		if (indexCheck(listItems, index))
		{
			double newWeight = currWeight + listItems.cargo[index].weight;
			double valNew;
			if (valNew < val || (rand() / (double)RAND_MAX) <= pow(3, -(valNew - val) / currT))
			{

			}
			//cout << listItems.cargo[index].weight << endl;
			currWeight = currWeight + listItems.cargo[index].weight;
			currUtility = currUtility + listItems.cargo[index].priority;
		}
		attempt++;
		if (attempt > 40000)
			break;
	}
	cout << attempt << endl;
	

	/*
	while (maxWeight > currWeight)
	{
		for (double currT = initialT; currT > minimumT; currT *= alpha) // cooling schedule
		{
			for (int i = 0; i < attempts; i++) //
			{
				index = randIndex(listItems);
				if (indexCheck(listItems, index))
				{
					newWeight = currWeight + listItems.cargo[index].weight;
					newUtility = currUtility + listItems.cargo[index].priority;
					double valNew = functionRand(newWeight);
				}
				currWeight = newWeight;
				currUtility = newUtility;
				newUtility = 0;
				newWeight = 0;
			}
		}
	}
	*/
	cout << "Final Weight = " << currWeight << "\t, Total Utility = " << currUtility << "\n\n";
	
	return currWeight;
}


