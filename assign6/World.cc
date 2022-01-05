#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include "World.h"
using namespace std;

World::World(int numpasses, int seed) {
	roundNum = numpasses;
	srand((unsigned)seed);
	//	first let the whole map point to null
	for(int i = 0; i < 20; ++i)
	{
		for(int j = 0; j < 35; ++j)
		{
			map[i][j] = NULL;
		}
	}
	int counter = 15;
	int randnum;
	while(counter)	/* if counter > 10 , generate a goat , else generate a grass */
	{
		randnum = rand() % 700;
		if(map[randnum/35][randnum%35] == NULL)
		{
			if(counter > 10)
				map[randnum/35][randnum%35] = new Goat(randnum%35, randnum/35);
			else
				map[randnum/35][randnum%35] = new Grass(randnum%35, randnum/35);
			counter--;
		}
	}
}

void
World::mainLoop(int displayInterval) {
	
	// do passes
	for(int i = 1; i <= roundNum; ++i)
	{
		if(i % displayInterval == 0)
		{
			display();
		}
		//scan the map
		for(int y = 0; y < mapheight; ++y)
		{
			for(int x = 0; x < mapwidth; ++x)
			{
				if(map[y][x] == NULL)
					continue;
				else if(map[y][x]->getType() == grass && !map[y][x]->getPass())
				{
					// if map[y][x] is a grass and haven't act
					// grass operation
					if(map[y][x]->getAge() >= 3 && map[y][x]->getAge() <= 5)
					{
						map[y][x]->reproduce(map);
					}
					map[y][x]->ageIncrement();
					map[y][x]->setPass();
				}
				else if(map[y][x]->getType() == goat && !map[y][x]->getPass())
				{
					// if map[y][x] is a goat and haven't act
					// goat operation
					if(map[y][x]->getAge() >= 50 && map[y][x]->getAge() <= 55)
					{
						map[y][x]->setPass();
						map[y][x]->ageIncrement();
						map[y][x]->foodDecrement();
						map[y][x]->reproduce(map);
					}
					else
					{
						map[y][x]->setPass();
						map[y][x]->ageIncrement();
						map[y][x]->foodDecrement();
						map[y][x]->MoveAndEatGrass(map);
					}
				}
			}
		}
		// reset and clear the map
		for(int y = 0; y < mapheight; ++y)
		{
			for(int x = 0; x < mapwidth; ++x)
			{
				if(map[y][x] == NULL)
					continue;
				if(map[y][x]->die())	/* clear the dead body */
					map[y][x] = NULL;
				else
					map[y][x]->notPass();	/* reset all creature to "haven't move" */
			}
		}
	}
}

void
World::display() {	/* display the current map */
	int goatcount = 0, grasscount = 0;
	char printArray[21] = "0 1 2 3 4 5 6 7 8 9 ";
	cout << "  " << printArray << printArray << printArray << "0 1 2 3 4" << endl;
	for(int i = 0; i < 20; ++i)
	{
		cout << i % 10;
		for(int j = 0; j < 35; ++j)
		{
			cout << ' ';
			if(map[i][j] == NULL)
				cout << ' ';
			else if(map[i][j]->getType() == grass)
			{
				grasscount++;
				cout << 'I';
			}
			else if(map[i][j]->getType() == goat)
			{
				goatcount++;
				cout << 'X';
			}
		}
		cout << endl;
	}
	for(int i = 0; i < 9; ++i)
		cout << "--------";
	cout << endl;
}

