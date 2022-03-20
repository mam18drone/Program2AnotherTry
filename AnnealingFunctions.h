#pragma once
#include <iostream>
#include <ctime>
#include "CargoItems.h"
#include <random>
#include <cstdlib>

using namespace std;

/* select a random index for other functions */
int randIndex(List& listItems)
{
	int randomIndex = rand() % listItems.cargo.size();
	return randomIndex;
}
/* Check if index has been used */
bool indexCheck(List& listItems,int& index)
{
	index = randIndex(listItems); // grab random index
	Item indexItem = listItems.cargo[index];
	if (indexItem.check == 0)
	{
		listItems.cargo[index].check == 1;
		return true;
	}
	else
		return false;
}

/* Implement cargo at random to initial list */
void cargoRandom(List& listItems, int count)//, double currWeight, double currUtility)
{
	int index;
	int i = 0;
	while (i < count)
	{
		if (indexCheck(listItems,index)) // Check if index has been used
		{
			listItems.cargo[index].check = 1; // Mark index as used 
			i++;
		}
	}
}