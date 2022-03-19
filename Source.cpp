#include <iostream>
#include "SimulatedAnnealing.h"
#include "SimulatedAnnealingRandom.h"
#include <fstream>
#include "CargoItems.h"

using namespace std;



int main()
{
	double maxWeight = 500; // 500 lbs of weight ist he upper limit to not crossover
	double maxTemp = 1000;
	double minTemp = 1;
	double geoDec = 0.95;
	List listItems;

	initializeItemList(listItems); // Initialize all items from text file
	List master = listItems;
	int iterations = 100;
	double output;
	output = simulatedAnnealingRand(maxWeight, maxTemp, minTemp, geoDec, listItems);
	
	/*
	for (int i = 0; i < iterations; i++)
	{
		output = simulatedAnnealingRand(maxWeight, maxTemp, minTemp, geoDec, listItems);
	}
	*/

	return 0;
}