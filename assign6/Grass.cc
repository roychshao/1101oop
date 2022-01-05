#include <bits/stdc++.h>
#include "Grass.h"

using namespace std;

Grass::Grass(int x, int y) : Creature(x, y) {
	setInfo(0, 6, grass);
}

void
Grass::reproduce(Creature* map[20][35]) {
	int x[4] = {1,0,-1,0}, X = getX();
	int y[4] = {0,-1,0,1}, Y = getY();
	int rn = r.getRandomNum(0,3);
	if(X+x[rn] >= 35 || X+x[rn] < 0 || Y+y[rn] >= 20 || Y+y[rn] < 0)
		return;
	//	if the destination is null, then reproduce
	if(map[Y+y[rn]][X+x[rn]] == NULL)
		map[Y+y[rn]][X+x[rn]] = new Grass(X+x[rn], Y+y[rn]);
}

