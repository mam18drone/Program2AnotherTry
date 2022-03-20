#include <iostream>
#include "SimulatedAnnealing.h"
#include "SimulatedAnnealingRandom.h"
#include <fstream>
#include "CargoItems.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	double maxWeight = 500; // 500 lbs of weight ist he upper limit to not crossover
	double maxTemp = 1000;
	double minTemp = 1;
	double geoDec = 0.95;
	int maxAttempts = 40000;
	double targetUtility = 1000;
	List listItems;

	initializeItemList(listItems); // Initialize all items from text file
	List inCargo;

	double numItems = listItems.cargo.size();
	double initialCount = 0.05 * numItems;
	int counter = int(initialCount);
	
	double currWeight = 0;
	double currUtility = 0;
	cargoRandom(listItems, inCargo, counter, currWeight, currUtility);
	simulatedAnnealing(listItems, inCargo, currWeight, currUtility, minTemp, maxTemp, maxWeight, geoDec, maxAttempts, targetUtility);
	
	return 0;
}