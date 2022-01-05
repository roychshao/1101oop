/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     QueueTest.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Dec 11, 1998: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
}

#include <iostream>
#include <fstream>
#include "AnsiPrint.h"
#include "Queue.h"

using namespace std;

/**
 * Print my id 
 */

void
PrintMyID(const char *studId) {

  char *str= new char[strlen(studId)+5];
  sprintf(str,"ID: %s",studId);
  AnsiPrint(str,yellow,red,true,true);
  cout << endl ;
  delete [] str;

}

/**
 * PrintUsage
 */

void
PrintUsage(const char *progName) {

    assert(progName);
    cout << "Usage: " << progName << " [passes [display [seed]]]" << endl;

}

int
main(int argc, char **argv) {

  istream *is1=&cin,*is2=&cin;

  if (argc>3) {
    PrintUsage(argv[0]);
    exit(-1);
  } else if (argc>2) {
    is2 = new ifstream(argv[2]);
    if (is2==NULL) {
      cerr << "Can't open file " << argv[2] << endl;
      exit(1);
    }
  } 
  if (argc>1) {
    is1 = new ifstream(argv[1]);
    if (is1==NULL) {
      cerr << "Can't open file " << argv[1] << endl;
      exit(2);
    }
  }
  
  // In the whole program , class Except is not used
  // I used my own wawy instead.
  
  int intd; // int data
  char chard; // char data
  int dataCounter = 0;
  Queue<int> iQ; // int queue
  Queue<char> cQ; // char queue
  while(*is1 >> intd)
  {
	// enqueue int data
  	iQ.Enqueue(intd);
	dataCounter++;
  }
  AnsiPrint("Integer Queue:", blue, black, false);
  cout << endl;
  while(dataCounter != 0)
  {
	// dequeue int data
    iQ.Dequeue();
    dataCounter--;
  }
  dataCounter = 0;
  while(*is2 >> chard)
  {
	// enqueue char data
  	cQ.Enqueue(chard);
	dataCounter++;
  }
  AnsiPrint("Character Queue:", blue, black, false);
  cout << endl;
  while(dataCounter != 0)
  {
	// dequeue char data
    cQ.Dequeue();
	dataCounter--;
  }
  cQ.Dequeue();	// try catch checking
  PrintMyID("109703041");
  return 0;  
}
