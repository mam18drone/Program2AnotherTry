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

/*
void weightChoice(double currWeight, double currUtility)
{

}

void comparison()
{
	// if new method better return true
	// if new method worse return false
}

double keyFunction(double deltE, double currT)
{
	double probability = exp(-deltE / currT);
	return probability;
}

bool changeCheck()
{
	randChange(); // make a random change
	comparison();
	keyFunction(); // key function check change
	
}


void simulatedAnnealingNew(List& listItems, List& inCargo, double& currWeight, double& currUtility, double minTemp, double maxTemp, double maxWeight, double geoDec, int maxAttempts, double targetUtility)
{
	int index;
	int attempt = 0;
	int acceptedChanges;

	for (double currT = maxTemp; currT > minTemp; currT *= geoDec)
	{
		index = randIndex(listItems);
		if (indexCheck(listItems, index))
		{

		}

		



		acceptedChanges = 0;
		while (attempt < maxAttempts)
		{
			if (changeCheck())
				acceptedChanges++;
			attempt++;
		}
		if (acceptedChanges == 0)
			break;
	}
}
*/
