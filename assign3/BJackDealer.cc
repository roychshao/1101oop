/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
  NAME
  BJackDealer.cc
  PURPOSE

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
#include <string.h>
}

using namespace std;
#include <assert.h>
#include <iostream>
#include "AnsiPrint.h"
#include "Card.h"
#include "CardPat.h"
#include "BJackPlayer.h"
#include "BJackDealer.h"

// constructor 
// nDeck is the number of standard decks that the dealer will deal with
BJackDealer::BJackDealer(int nSet) {	/* initialize the card status */
	dealer = new BJackPlayer("dealer");
	decknum = nSet;
	cardnum = nSet * kMaxNCards;
	for(int i = 0; i < kMaxNCards; ++i)
		cardstatus[i] = nSet;	
}

BJackDealer::~BJackDealer() {	/* free the dealer */
	delete dealer;
}

// distribute a card to the player
int
BJackDealer::giveCard() {
	int randnum = rand() % 52;
	while(!cardstatus[randnum])	/* if the card have all drawed out , redraw a card */
		randnum = rand() % 52;
	cardstatus[randnum]--;
	cardnum--;
	return randnum;
}

// give the dealer one card unconditionally
void 
BJackDealer::addCard() {
	int randnum = rand() % 52;
	while(!cardstatus[randnum])	/* if the card have all drawed out , redraw a card */
		randnum = rand() % 52;
	cardstatus[randnum]--;
	cardnum--;
	Card newcard(randnum);
	dealer->addCard(newcard);
}

// give the dealer as many cards as necessary to exceed the player 
// of the given total points
// A special case happen when both of them have 21 points.
// It is a tie game and therefore the dealer does not get more cards.

void
BJackDealer::addCards(int oppTotal) {
	int totalscore = dealer->totalPoints();	/* get the dealer points */
	while(totalscore <= oppTotal || totalscore < 17) {	/* not untill the end condition is reached , addcard */
		if (oppTotal > 21 && totalscore >= 17) break;
		this->addCard();
		totalscore = dealer->totalPoints();
	}
}

// Determine who has win the game.
// The total points that the dealer has should be greater than 
// the player at the point this function is called.

result
BJackDealer::judge(int oppTotal) const {
												/* return the game result */
	int totalscore = dealer->totalPoints();
	if (oppTotal > 21 && totalscore > 21)
		return tie;
	else if (oppTotal > 21 && totalscore <= 21)
		return win;
	else if (oppTotal <= 21 && totalscore > 21)
		return lose;
	else if (oppTotal > totalscore)
		return lose;
	else if (oppTotal == totalscore)
		return tie;
	else if (oppTotal < totalscore)
		return win;
	return tie;
}

// start a new game
// before starting a new game, check if there are enough cards left for 
// the next game.

void
BJackDealer::start(void) {		/* check if it is need to be shuffled */
	if (cardnum < 17 * decknum)
		shuffle();
}

// shuffle the deck of cards
void 
BJackDealer::shuffle(void) {	/* do shuffle */
	int randnum = rand();
	srand(randnum);
	for(int i = 0; i < cardnum; ++i)
		cardstatus[i] = decknum;
}

// reset the seed before shuffling
void
BJackDealer::shuffle(long seed) {

}

void
BJackDealer::openFirstCard() {	/* open the dealer's first card */
	dealer->openFirstCard();
}

void
BJackDealer::clearCards() {		/* clear the dealer's hand card */
	dealer->closeFirstCard();
	dealer->clearCards();
}

// show the dealer's hand to the screen
void 
BJackDealer::showCards(void) const {

	dealer->showCards();

}

