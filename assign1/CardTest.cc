/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     CardTest.cc
   PURPOSE
     Testing card displaying
   NOTES

   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 7, 1999: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>
}

#include <iostream>
#include "AnsiPrint.h"
#include "Cards.h"

using namespace std;

/**
 * Print my id 
 */
void
PrintMyID(const char *studId) {

  char *str= new char[sizeof(studId)+5];
  // we put string in a buffer first 
  sprintf(str,"ID: %s",studId);
  // print the buffer out with color
  AnsiPrint(str,yellow,red, true, true);
  cout << endl << endl;
  delete [] str;

}

/**
 * PrintUsage
 */
void
PrintUsage(const char *progName) {

  assert(progName);
  cout << "Usage: " << progName << " NCards [Seed]" << endl;

}

/**
 * Main Function Call
 */
int
main(int argc, char **argv) {

  int ncards=0;  // number of cards to draw 
  if (argc==3) {
    long seed=atoi(argv[2]); // the third argument is the seed
	//cout << seed << endl;
    srand(seed);
    ncards=atoi(argv[1]); // the second argument is the number of cards
  } else if (argc==2) {
    ncards=atoi(argv[1]);
  } else {
    PrintUsage(argv[0]);
    exit(-1);
  }

  // You are asked to fill in a few missing statements here
  
    if(ncards > 52)
	{
		cout << "Sorry, number of cards can not exceed 52." << endl;
		return 0;
	}
	int record[60];
	int used[60];
	int num, idx = 0;
	char suit;
	memset(record, 0, sizeof(record));
	memset(used, 0, sizeof(used));

	//	Random
	for(int i = 0; i < ncards; ++i)
	{
		num = rand() % 52;
		while(used[num])
		{
			//cout << "draw" << endl;
			num = rand() % 52;
		}
		record[idx++] = num;
		used[num] = 1;
	}
	/*for(int i = 0; i < 52; ++i)
		cout << used[i];
	cout << endl;*/

	//	Print
	idx = 0;
	while (ncards)
	{
		if (ncards >= 5)
		{
			for(int height = 0; height < 11; ++height)
			{
				for(int i = 1; i <= 5; ++i)
				{
					int tmp = record[ncards-i];
					//cout << tmp;
					//	CHANGE SUIT
					if(tmp % 4 == 1)
						suit = 'C';
					else if(tmp % 4 == 2)
						suit = 'D';
					else if(tmp % 4 == 3)
						suit = 'H';
					else if(tmp % 4 == 0)
						suit = 'S';
					for(int j = 0; j < 11; ++j)
						if(card[tmp/4][height][j] > 65 &&
						   card[tmp/4][height][j] != 'J' &&
						   card[tmp/4][height][j] != 'Q' &&
						   card[tmp/4][height][j] != 'K')
							card[tmp/4][height][j] = suit;
					
					//	ANSIPRINT
					if(suit == 'D' || suit == 'H')
						AnsiPrint(card[tmp/4][height], red, white, false, false);
						//cout << card[record[ncards-i]/4][height];
					else
						AnsiPrint(card[tmp/4][height], black, white, false, false);
						//cout << card[record[ncards-i]/4][height];	
					cout << " ";
				}
				cout << endl;
			}
			ncards -= 5;
		}
		else
		{
			for(int height = 0; height < 11; ++height)
			{
				for(int i = 1; i <= ncards; ++i)
				{
					int tmp = record[ncards-i];
					//cout << tmp;
					//	CHANGE SUIT
					if(tmp % 4 == 1)
						suit = 'C';
					else if(tmp % 4 == 2)
						suit = 'D';
					else if(tmp % 4 == 3)
						suit = 'H';
					else if(tmp % 4 == 0)
						suit = 'S';
					for(int j = 0; j < 11; ++j)
						if(card[tmp/4][height][j] > 65 &&
						   card[tmp/4][height][j] != 'J' &&
						   card[tmp/4][height][j] != 'Q' &&
						   card[tmp/4][height][j] != 'K')
							card[tmp/4][height][j] = suit;
					
					//	ANSIPRINT
					if(suit == 'D' || suit == 'H')
						AnsiPrint(card[tmp/4][height], red, white, false, false);
						//cout << card[record[ncards-i]/4][height];
					else
						AnsiPrint(card[tmp/4][height], black, white, false, false);
						//cout << card[record[ncards-i]/4][height];
					cout << " ";
				}
				if (height != 10)
					cout << endl;
			}
			cout << endl;
			break;
		}
	}
	// Print my id at the end of the program
	PrintMyID("109703041");
	return 0;
}
