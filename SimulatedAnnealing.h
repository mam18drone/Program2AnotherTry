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

/* Calculate the weight of items in Cargo*/
double weightCalc(List list)
{
	double weight = 0;
	for (int i = 0; i < list.cargo.size(); i++)
	{
		if (list.cargo[i].check == 1)
			weight = weight + list.cargo[i].weight;
	}
	return weight;
}

/*Compare weight in Cargo*/
int weightCompare(List temp1, List temp2)
{
	double w1 = weightCalc(temp1);
	double w2 = weightCalc(temp2);
	if (w1 > w2)
		return 1;
	else
		return 2;
}

/* Caculate Utility of the Cargo*/
double utilityCalc(List list, double maxWeight)
{
	double utility = 0;
	double newWeight;
	for (int i = 0; i < list.cargo.size(); i++)
	{
		if(list.cargo[i].check == 1)
			utility = utility + list.cargo[i].utility;
	}
	newWeight = weightCalc(list);
	if (newWeight > maxWeight)
	{
		utility = utility + ((newWeight - maxWeight) * (-20));
	}
	return utility;
}

/*Compare two Cargo load Utililties */
double utilityCompare(List temp1, List temp2, double maxWeight)
{
	double u1 = utilityCalc(temp1, maxWeight);
	double u2 = utilityCalc(temp2, maxWeight);
	if (u1 > u2)
		return 1;
	else
		return 2;
}

/* Flips bit for if item is in or out of Cargo*/
int flipBit(List& listItems, int index)
{
	/* Puts item in */
	if (listItems.cargo[index].check == 0) // out
		return listItems.cargo[index].check = 1; // in
		
	/* Takes item out */
	else 
		return listItems.cargo[index].check = 0; // out
}

/* Cost Check Bench Mark */
double benchMark(double targetUtility, double actualUtility)
{
	double distanceUtility = targetUtility - actualUtility;
	return distanceUtility;
}

/* Simualted Annealing Function*/
void simulatedAnnealing(List& listItems, double minTemp, double maxTemp, double maxWeight, double geoDec, int maxAttempts, double targetUtility)
{
	int index;
	int attempt;
	int acceptedChanges;
	double weightProposed;
	double utilityProposed;
	double weightPrevious;
	double utilityPrevious;
	double e = 2.71828;
	/* start of simulated annealing */
	for (double currT = maxTemp; currT > minTemp; currT *= geoDec)
	{
		acceptedChanges = 0;
		/* cycle of attempts to make changes in cargo */
		for (int i = 0; i < maxAttempts; i++)
		{
			weightPrevious = weightCalc(listItems);
			utilityPrevious = utilityCalc(listItems,maxWeight);
			index = randIndex(listItems);
			flipBit(listItems, index);
			weightProposed = weightCalc(listItems);
			utilityProposed = utilityCalc(listItems, maxWeight);
			if (benchMark(targetUtility, utilityProposed) < benchMark(targetUtility, utilityPrevious) || double(rand()) <= pow(e, -(utilityProposed - utilityPrevious) / currT))
			{
				/* Change was made */
				acceptedChanges++;
			}
			else
			{
				/* Change was not made */
				flipBit(listItems, index);
			}
				
		}
		cout << weightCalc(listItems) << "\t" << utilityCalc(listItems, maxWeight) << endl;
		/* if no changes made in full cycle, break from loop */
		if (acceptedChanges == 0)
			break;
	}
}

/* csv logger of items used for final configuration*/
void csvlogger(List listItems)
{
	auto now = chrono::system_clock::now();
	auto UTC = chrono::duration_cast<chrono::seconds>(now.time_since_epoch()).count();
	ofstream loggerfile("SimulatedAnneal_Log_" + to_string(UTC) + ".csv");
	loggerfile << "Item Num" << "," << "Utility" << "," << "Weight" << "\n";
	for (int i = 0; i < listItems.cargo.size(); i++)
	{
		if (listItems.cargo[i].check == 1)
			loggerfile << i + 1 << "," << listItems.cargo[i].utility << "," << listItems.cargo[i].weight << "\n";
	}
	loggerfile.close();
}

/* text logger of overall performance of final configuration */
void txtlogger(List listItems, double maxWeight)
{
	auto now = chrono::system_clock::now();
	auto UTC = chrono::duration_cast<chrono::seconds>(now.time_since_epoch()).count();
	ofstream txtfile("SimulatedAnneal_Summary_" + to_string(UTC) + ".txt");

	txtfile << "For the simulated annealing configuration the following results appear: \n";
	for (int i = 0; i < listItems.cargo.size(); i++)
	{
		if (listItems.cargo[i].check == 1)
			txtfile << "\t - The total number of items in cargo is: " << listItems.cargo.size() << "\n";
	}
	txtfile << "\t - The total weight of cargo is: " << weightCalc(listItems) << "\n";
	txtfile << "\t - The total utility of cargo is: " << utilityCalc(listItems, maxWeight) << "\n";
	txtfile.close();
}