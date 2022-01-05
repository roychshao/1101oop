#include <bits/stdc++.h>
#include <iostream>
#include "Goat.h"

using namespace std;

Goat::Goat(int x, int y) : Creature(x,y) {
	foodpoint = 20;
	setInfo(0, 70, goat);
}


void
Goat::MoveAndEatGrass(Creature* map[20][35]) {
	int x[4] = {1,0,-1,0}, X = getX();
	int y[4] = {0,-1,0,1}, Y = getY();
	int rn = r.getRandomNum(0,3);
	int newX = X+x[rn], newY = Y+y[rn];
	if(newX >= 35 || newX < 0 || newY >= 20 || newY < 0)
		return;
	//	if the destination is null, move, else eat grass
	if(map[newY][newX] == NULL)
	{
		// copy current place to the destination
		// use pointer operation to move
		map[newY][newX] = this;
		this->setX(newX);
		this->setY(newY);
		map[Y][X] = NULL;
	}
	else if(map[newY][newX]->getType() == grass)
	{
		// copy current place to the destination
		map[newY][newX] = NULL;
		map[newY][newX] = this;
		this->setX(newX);
		this->setY(newY);
		foodpoint += 5;
		map[Y][X] = NULL;
	}
}

void
Goat::reproduce(Creature* map[20][35]) {
	int x[4] = {1,0,-1,0}, X = getX();
	int y[4] = {0,-1,0,1}, Y = getY();
	int rn = r.getRandomNum(0,3);
	if(X+x[rn] >= 35 || X+x[rn] < 0 || Y+y[rn] >= 20 || Y+y[rn] < 0)
		return;
	// if the destination is null, then reproduce
	if(map[Y+y[rn]][X+x[rn]] == NULL)
		map[Y+y[rn]][X+x[rn]] = new Goat(X+x[rn], Y+y[rn]);
}
