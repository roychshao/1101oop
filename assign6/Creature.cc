#include <bits/stdc++.h>
#include <iostream>
#include "Creature.h"
using namespace std;

Creature::Creature(int x, int y) {
	X = x, Y = y;
	age = 0;
	lifelimit = 0;
	type = nocreature;
	passed = false;
}

void
Creature::MoveAndEatGrass(Creature* map[20][35]) {
	cout << "virtual in MoveAndEatGrass() invalid." << endl;
}

void
Creature::setInfo(int a, int l, int t) {
	age = a;
	lifelimit = l;
	type = t;
}

void
Creature::foodDecrement() {
	cout << "virtual invalid in foodDecrement()" << '\n';
}
