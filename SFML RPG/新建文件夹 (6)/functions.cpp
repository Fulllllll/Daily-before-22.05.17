#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//global variables
extern ofstream aut;

extern int numSublevels;
extern int currentSublevel;
extern int numGates;
extern int numTreasures;
extern int numTeki;
extern int totalTeki;

//pools
extern string modifiers[21];
extern string places[7];
extern string easyEnemies[128];
extern string hardEnemies[128];
extern string treasures[256];
extern string layouts[256];
extern string unitFiles[256];

int getSeed() {
	//srand (time(NULL));
	bool func_run = 1;
	int seed;
	while(func_run) {
		cout << "Seed: (input 0 for random)" << endl;
		if (!(cin >> seed)) {
      		cout << "Please enter a number without a period." << endl;
      		cin.clear();
      		cin.ignore(10000,'\n');
    	} else {
    		func_run = 0;
    	}

	}
	if(seed == 0) {
		cout << "Generating Seed..." << endl;
		seed = time(NULL);
		cout << seed << endl;
		
	}
	srand(seed);
	return 0;
}

string getName() {
	cout << "Generating Name..." << endl;

	
	int v1 = rand() % 21;
	int v2 = rand() % 7;
	
	string name = "./caves/" + modifiers[v1] + " " + places[v2] + ".txt";
	return name;
}


int writeCaveInfo() {
	cout << "Generating CaveInfo..." << endl;
	aut << "# CaveInfo" << endl;
	aut << "{" << endl;
	aut << "	{c000} 4 " << numSublevels << " 	# SublevelCount"<< endl;
	aut << "	{_eof}" << endl;
	aut << "}" << endl;
	aut << numSublevels << " ";
	return 0;
}

int writeFloorInfo() {
	//workaround/limitation for now
	totalTeki = numTeki;
	cout << "Generating FloorInfo..." << endl;
	aut << "# FloorInfo " << endl;
	aut << "{" << endl;
	aut << "	{f000} 4 " << (currentSublevel - 1) << " # CurrentSublevelIndex" << endl;
	aut << "	{f001} 4 " << (currentSublevel - 1) << " # CurrentSublevelIndex" << endl;
	aut << "	{f002} 4 " << totalTeki << " # EntityTotal" << endl;//this is total number of teki spawned on floor
	aut << "	{f003} 4 " << numTreasures << " # TreasureTotal" << endl;
	aut << "	{f004} 4 " << numGates << " # GateTotal" << endl;
	aut << "	{f005} 4 " << (rand() % 1) + 1 << " # RoomTotal" << endl;
	aut << "	{f006} 4 " << 0.12 << " # CorridorRatio" << endl;
	aut << "	{f007} 4 " << (currentSublevel == numSublevels) << " # Geyser" << endl;
	aut << "	{f008} -1 " << unitFiles[rand() % 11] << " # UnitFile" << endl;
	aut << "	{f009} -1 " << "normal_light_lv0.ini" << " # LightFile" << endl;
	aut << "	{f00A} -1 " << "none" << " # Skybox" << endl;
	aut << "	{f010} 4 " << 0 << " # CloggedHole" << endl;
	aut << "	{f011} 4 " << 0 << " # Unknown" << endl;
	aut << "	{f012} 4 " << 0 << " # MusicType" << endl;
	aut << "	{f013} 4 " << 0 << " # SolidPlane" << endl;
	aut << "	{f014} 4 " << 50 << " # DeadEndTotal" << endl;
	aut << "	{f015} 4 " << 1 << " # Version" << endl;
	aut << "	{f016} 4 " << 0.000000 << " # WaterwraithTimer" << endl;
	aut << "	{f017} 4 " << 0 << " # Seesaw" << endl;
	aut << "	{_eof}" << endl;
	
	
	return 0;
}

int writeTekiInfo() {
	cout << "Generating TekiInfo..." << endl;

	aut << "# TekiInfo" << endl;
	aut << "{" << endl;
	aut << "	" << numTeki << " # num" << endl;
	for (int i = 0; i < numTeki; i++) {
		if (rand() > 0.8) {
			aut << "	" << hardEnemies[rand() % 7] << " " << 10 << " # weight" << endl; 	
			aut << "	" << rand() % 2 << " # type" << endl; 
		} else { 
			//int numEnemies = rand() % 3 + 1; //removed for now, it makes calculating totalTeki hard as heck
			int numEnemies = 1;
			aut << "	" << easyEnemies[rand() % 9] << " " << numEnemies * 10 << " # weight" << endl; 	
			aut << "	" << rand() % 2 << " # type" << endl; 
		}
	}
	aut << "}" << endl;
	return 0;
}

int writeItemInfo() {
	cout << "Generating ItemInfo..." << endl;
	

	aut << "# ItemInfo" << endl;
	aut << "{" << endl;
	aut << "	" << numTreasures << " # num" << endl;
	for (int i = 0; i < numTreasures; i++) {

		aut << "	" << treasures[rand() % 85] << " 10 # weight" << endl; 	
	}
	aut << "}" << endl;
	return 0;
}

int writeGateInfo() {
	cout << "Generating GateInfo..." << endl;
	aut << "# GateInfo" << endl;
	aut << "{" << endl;
	aut << "	" << numGates << " # num" << endl;
	for (int i = 0; i < numGates; i++) {
		aut << "	gate " << 3000 << " # life" << endl;
		aut << "	1 # weight" << endl; 	
	}
	aut << "}" << endl;
	return 0;
}

int writeCapInfo() {
	cout << "Generating CapInfo..." << endl;
	aut << "# CapInfo" << endl;
	aut << "{" << endl;
	aut << "	0 # num" << endl;
	aut << "}" << endl;
	return 0;
}
