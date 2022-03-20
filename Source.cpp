#include <iostream>
#include "SimulatedAnnealing.h"
#include <fstream>
#include "CargoItems.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0)); // seed time for random indexes
	double maxWeight = 500; // 500 lbs of weight ist he upper limit to not crossover
	double maxTemp = 10000; // maximum temperature for simulated annealing
	double minTemp = 1; // minimum temperature for simulated annealing
	double geoDec = 0.99; // geometric decrementation of temperature
	int maxAttempts = 40000; // max attempts per temperature iteration cycle
	double targetUtility = 1000; // target utility score to minimize distance to
	List listItems;

	initializeItemList(listItems); // Initialize all items from text file

	double numItems = listItems.cargo.size();
	double initialCount = 0.05 * numItems; // create an initial count for 1/20th of the items to be stored
	int counter = int(initialCount);
	
	cargoRandom(listItems, counter);//, currWeight, currUtility);
	simulatedAnnealing(listItems, minTemp, maxTemp, maxWeight, geoDec, maxAttempts, targetUtility); // run the simulated annealing function
	csvlogger(listItems); // create a csv log of items selected final
	txtlogger(listItems, maxWeight); // create a text file summary
	
	return 0;
}