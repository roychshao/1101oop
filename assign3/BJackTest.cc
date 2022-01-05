/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     CardGame.cc
   PURPOSE
     Homework assignment for simulating card game
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 12, 1998: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
}

using namespace std;
#include <iostream>
#include "AnsiPrint.h"
#include "Card.h"
#include "ConsoleMenu.h"
#include "BJackPlayer.h"
#include "BJackDealer.h"
#include "BJackGame.h"

/**
 * Print my id 
 */

void
PrintMyID(const char *studId) {

  char *str= new char[sizeof(studId)+5];
  sprintf(str,"ID: %s",studId);
  AnsiPrint(str,yellow,red,true,true);
  cout << endl << endl;
  delete [] str;

}


/**
 * PrintUsage
 */

void
PrintUsage(const char *progName) {

  assert(progName);
  cout << "Usage: " << progName << " [Seed] [nDecks]" << endl;

}

/**
 * Main Function Call
 */

int
main(int argc, char **argv) {

  int ndecks=2;  // number of cards to draw
  
  if (argc==3) {
    long seed=atoi(argv[1]); // the first argument is the seed
    srand(seed);
    ndecks=atoi(argv[2]); // the second argument is the number of decks
  } else if (argc==2) {
    if (argv[1][1]=='h') {
      PrintUsage(argv[0]);
      exit(-1);
    } else {
      long seed=atoi(argv[1]); // the first argument is the seed
      srand(seed);
    }
  } else if (argc>3) {
    PrintUsage(argv[0]);
    exit(-1);
  }

  // create an instance of player and dealer
  BJackPlayer bjplayer("Player");
  BJackDealer bjdealer(ndecks);

  // create an instance of the bj game with the given player an dealer
  BJackGame bjgame(bjplayer,bjdealer);

  // play the game until the user quit
  while(bjgame.oneRun());

  PrintMyID("109703041");
  return 0;

}
