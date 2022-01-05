#ifndef _CREATURE_H
#define _CREATURE_H

#include <iostream>
#include "RandomNum.h"
using namespace std;

const int nocreature = 0;
const int grass = 1;
const int goat = 2;

class Creature {

public:
	/* constructor and destructor */
	Creature() {
		age = -1, lifelimit = -1, type = nocreature;
		X = -1, Y = -1, passed = false;
	}
	Creature(int, int);	// (x, y)
	virtual ~Creature() {};
	void setInfo(int, int, int);
	//(this function will be called in the grass's and goat's constructor)
	
	int getType() { return type; };
	/*
	 * return 0 : no creatrue
	 * return 1 : grass
	 * return 2 : goat
	 */
	virtual bool die() {
		cout << "virtual invalid in die()" << '\n';
		return false;
	}
	virtual void MoveAndEatGrass(Creature* [20][35]);
	int getAge() { return age; };
	int getLifelimit() { return lifelimit; };
	void setX(int x) { X = x; };
	void setY(int y) { Y = y; };	
	int getX() { return X; };
	int getY() { return Y; };
	virtual void reproduce(Creature* [20][35]) {
		cout << "virtual invalid in reproduce()" << '\n';
	}
	virtual void foodDecrement();
	void ageIncrement() { age++; };
	void notPass() { passed = false; };	// a mark to record if a creature have act.
	void setPass() { passed = true; };
	bool getPass() { return passed; };

private:
	int age;
	int lifelimit;
	int type;
	int X;
	int Y;
	bool passed;
};

#endif // _CREATURE_H
