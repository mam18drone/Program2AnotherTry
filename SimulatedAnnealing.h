#pragma once

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "CargoItems.h"
#include "AnnealingFunctions.h"
#include <math.h>

using namespace std;


void weightChoice(double currWeight, double currUtility)
{

}

double weightCalc(List list)
{
	double weight = 0;
	for (int i = 0; i < list.cargo.size(); i++)
	{
		weight = weight + list.cargo[i].weight;
	}
	return weight;
}

int weightCompare(List temp, List listItems)
{
	double w1 = weightCalc(temp);
	double w2 = weightCalc(listItems);
	if (w1 > w2)
		return 1;
	else
		return 2;
}

double utilityCalc(List list)
{
	double utility;
	for (int i = 0; i < list.cargo.size(); i++)
	{
		utility = utility + list.cargo[i].priority;
	}
	return utility;
}



void comparison(List& listItems)
{
	randIndex(listItems);
	

}

double keyFunction(double deltE, double currT)
{
	double probability = exp(-deltE / currT);
	return probability;
}

bool insertCheck(List& listItems, List& inCargo, double currWeight, double currUtility, double maxWeight, int index)
{
	if (indexCheck(listItems, index))
	{
		if (currWeight < maxWeight)
		{
			currWeight = currWeight + listItems.cargo[index].weight;
			currUtility = currUtility + listItems.cargo[index].priority;
			if (currWeight < maxWeight)
			{
				inCargo.cargo.push_back(listItems.cargo[index]);
				listItems.cargo[index].check == 1;
				return true;
			}
			// insert else statement for weighting?
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

void simulatedAnnealing(List& listItems, List& inCargo, double& currWeight, double& currUtility, double minTemp, double maxTemp, double maxWeight, double geoDec, int maxAttempts, double targetUtility)
{
	int index;
	int attempt;
	int acceptedChanges;

	for (double currT = maxTemp; currT > minTemp; currT *= geoDec)
	{
		attempt = 0;
		acceptedChanges = 0;
		while (attempt < maxAttempts)
		{
			index = randIndex(listItems);
			if (insertCheck(listItems, inCargo, currWeight, currUtility, maxWeight, index))
				acceptedChanges++;
			else
				if (comparison())
					acceptedChanges++;
			attempt++;
		}
	}
	cout << currWeight << "\t" << currUtility << endl;
}