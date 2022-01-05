#ifndef _GRASS_H
#define _GRASS_H

#include <iostream>
#include "Creature.h"
using namespace std;

class Grass: public Creature {

public:
	Grass(int, int);
	~Grass() {};
	void reproduce(Creature* [20][35]);
	bool die() {
		return getAge() == getLifelimit() ? true : false;
	};

private:
	RandomNum r;	// a random number generator
};

#endif // _GRASS_H
