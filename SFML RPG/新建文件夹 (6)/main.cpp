// Pikmin 2 cave randomizer
// creates a .txt file 

#include <iostream>
#include <fstream> //file writing
#include <stdlib.h> //random

using namespace std;

//global variables
ofstream aut;

int numSublevels;
int currentSublevel;
int numGates;
int numTreasures;
int numTeki;
int totalTeki;

#include "functions.h"



int main () {
	
	getSeed();	
	string name = getName();
	//const char *path="./caves/file.txt";
	//path = "./caves/" + name;
	cout << name << endl;
	aut.open(name);
	if (!aut.is_open()) {
		return 0;
	}

	//Populate global variables from config

	int minSublevels = 2;
	int maxSublevels  = 15;  //these stats are straight out of pikmin 2
	//int avgSublevels = 7.5;

	numSublevels = rand() % (maxSublevels - minSublevels) + minSublevels;
	if(numSublevels > 8) { //bring the average down.
		if ((((double) rand() / (RAND_MAX))  > 0.4)) {
			numSublevels -= 1;
		}
	}  

	numSublevels = 5;

	int minGates = 0;
	int maxGates = 2;
	numGates = rand() % (maxGates - minGates) + minGates;

	int minTreasures = 0;
	int maxTreasures = 2;
	numTreasures = rand() % (maxTreasures - minTreasures) + minTreasures;

	int minTeki = 2;
	int maxTeki = 15;
	numTeki = rand() % (maxTeki - minTeki) + minTeki; //NUMBER OF TYPES OF TEKI

	writeCaveInfo();

	for (currentSublevel = 1; currentSublevel <= numSublevels; currentSublevel++) {
		//refresh global variables that vary by floor
		numGates = rand() % (maxGates - minGates) + minGates;
		numTreasures = rand() % (maxTreasures - minTreasures) + minTreasures;
		numTeki = rand() % (maxTeki - minTeki) + minTeki;
		writeFloorInfo();
		writeTekiInfo();
		writeItemInfo();
		writeGateInfo();
		writeCapInfo();
	}

	aut.close();
	return 0;
}