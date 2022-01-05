#ifndef _WORLD_H
#define _WORLD_H

#include <iostream>
#include "Creature.h"
#include "Goat.h"
#include "Grass.h"
using namespace std;

const int mapwidth = 35;
const int mapheight = 20;

class World {

public:
	World(int, int);	// (numPasses,seed)
	void mainLoop(int);	// (displayInterval)
	void display();		// display the current map
private:
	
	Creature* map[20][35];	// 35*20 array
	int roundNum;	// total round
};

#endif // _WORLD_H
