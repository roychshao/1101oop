/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJackGame.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 12, 1998: Created.
***************************************************************************/

/* $Log:$ */

#include <iostream>
#include "AnsiPrint.h"
#include "Card.h"
#include "BJackGame.h"
#include "BJackPlayer.h"
#include "BJackDealer.h"

using namespace std;

// only constructor
// Must be given a valid (initialized) game player and dealer
// Menu is constructed internally to provide basic text interface
// We must use an initialization list here.
BJackGame::BJackGame(BJackPlayer &bjp, BJackDealer &bjd) : menu(sizeof(menuItems)/sizeof(char *),menuItems), bjplayer(bjp), bjdealer(bjd){
	/* initialize */
	playerCredit = initCredit;
	dealerCredit = initCredit;
	bjplayer.clearCards();
	bjdealer.clearCards();
	init = false;
}

// one run of the game
// take and process a user action
// show current hands for both players at the end of a run.
bool
BJackGame::oneRun() {
	menu.print();
	int option = menu.getAnswer();
	/* according to the option to do the corresponding action */
	while(true)
	{
		if (option == 1)
		{
			moreCard();
			return true;
		}
		else if (option == 2)
		{
			enough();
			return true;
		}
		else if (option == 3)
		{
			restart();
			return true;
		}
		else if (option == 4)
			return false;
		else
			option = menu.getAnswer();
	}
	return false;
}

// give the player one more card
// check if we can do that first
void 
BJackGame::moreCard() {
	if (!init)
	{
		cout << "Game over" << endl;
		return;
	}
	int playerscore = bjplayer.totalPoints();
	if (playerscore > 21)	/* player can not add card when his points over 21 */
		cout << "You are over 21 already" << endl;
	else
		bjplayer.addCard(bjdealer.giveCard());
	bjplayer.showCards();
	bjdealer.showCards();
}

// give the dealer enough cards to try to win the player
// determine who win the game at the end
void 
BJackGame::enough() {
	if (!init)
	{
		cout << "Game over" << endl;
		return;
	}
	int playerscore = bjplayer.totalPoints();
	bjdealer.openFirstCard();
	bjdealer.addCards(playerscore);
	int result = bjdealer.judge(playerscore);
	/* print the result imformation to screen */
	if (result == lose)
	{
		playerCredit += betCredit, dealerCredit -= betCredit;
		cout << "You win. Good job.(You have " << playerCredit << " points, I have " << dealerCredit << " points.)" << endl;
	}
	else if (result == tie)
		cout << "It's a Tie.(You have " << playerCredit << " points, I have " << dealerCredit << " points.)" << endl;
	else
	{
		playerCredit -= betCredit, dealerCredit += betCredit;
		cout << "I win. Try again.(You have " << playerCredit << " points, I have " << dealerCredit << " points.)" << endl;
	}
	bjplayer.showCards();
	bjdealer.showCards();
	init = false;
}

// restart the game by giving each player two new cards
// need to check if any one broke (bankrupt).
void 
BJackGame::restart() {
	if (!playerCredit)
	{
		cout << "Sorry. Game over. No loan here." << endl;
		return;
	}
	if (!dealerCredit)
	{
		cout << "You win. Good job." << endl;
		return;
	}
	if (init)
	{
		cout << "Game is not over yet. Choose 'enough' to end a game" << endl;
		return;
	}
	bjplayer.clearCards();
	bjdealer.clearCards();
	bjdealer.start();
	bjplayer.start();
	init = true;
	for(int i = 0; i < 2; ++i)
	{
		/* each player draw two cards first */
		Card newcard(bjdealer.giveCard());
		bjplayer.addCard(newcard);
		bjdealer.addCard();
	}
	bjplayer.openFirstCard();
	bjplayer.showCards();
	bjdealer.showCards();
}

