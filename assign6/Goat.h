#ifndef _GOAT_H
#define _GOAT_H

#include <iostream>
#include "Creature.h"
using namespace std;

class Goat: public Creature {

public:
	Goat(int, int);
	~Goat() {};
	bool die() {
	   if(getAge() == getLifelimit() || foodpoint == 0)
	   	return true;
	   else
		return false;
	};
	void MoveAndEatGrass(Creature* [20][35]);	
	void reproduce(Creature* [20][35]);
	void foodDecrement() { foodpoint--; };

private:
	int foodpoint;
	RandomNum r;	// a random number generator
};

#endif // _GOAT_H
