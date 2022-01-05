
/***************************************************************************
   NAME
     BJackPlayer.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct. 5, 1998: Created.
***************************************************************************/

/* $Log: BJackPlayer.cc,v $
 * */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
}

using namespace std;
#include <iostream>
#include "AnsiPrint.h"
#include "CardPat.h"
#include "BJackPlayer.h"
#include "Card.h"

// default constructor: simply initialize the number of cards to 0

BJackPlayer::BJackPlayer(const char *player_name) {
	DrawCards = new Card[10];
	playerName = new char[strlen(player_name)+1];
	strcpy(playerName, player_name);
	Points = 0;
}

int
BJackPlayer::getPoints(){
	return Points;
}

// start the black jack game with a new card
void
BJackPlayer::start(void) {
	int randNum = rand() % 52;
	Card acard;
	acard.setID(randNum);
	int score = acard.getPip();
	Points += (score >= 10) ? 10 : score;	/*max point is 10*/
	DrawCards[0] = acard;
}

// add a new card to the current hand.
// need to protect the array from overflowing
void 
BJackPlayer::addCard(Card acard, int idx) {
	int score = acard.getPip();
	if(score >= 10)	/*max point is 10*/
		Points += 10;
	else
		Points += score;
	DrawCards[idx] = acard;
}

// get the total points of the curirent hand in a black jack game
// cards with face vaules above 10 are treated as 10
// Ace's can be treated as 1 or 11 points

void
BJackPlayer::totalPoints(BJackPlayer bjplayer) {
	cout << "Total points: " << Points << endl;
}

// set the status of the first card

/*void
BJackPlayer::openFirstCard() {

}*/

// print the current hand to the screen graphically

void 
BJackPlayer::showCards(bool showFirst,BJackPlayer bjplayer, int ncards) {
	bool printwords = false;	/*print "player" or not*/
	char suit;
	char space[11];
	char words[7] = "player";
	memset(space, ' ', sizeof(space));
	space[11] = '\0';
	int counter = 0;
	while (counter < ncards)
	{
		if((ncards - counter) >= 5)	/*if there remains more than 5 cards*/
		{
			for(int height = 0; height < 11; ++height)	
			{
				if(height < 6 && !printwords)
				{
					if(height == 5)
						printwords = true;
					cout << words[height] << " ";
				}
				else
					cout << "  ";
				for(int i = 0; i < 5; ++i)
				{
					Card tmp = bjplayer.DrawCards[counter+i];
					int tmppip = tmp.getPip() - 1;
					int tmpsuit = tmp.getSuit();
					if(tmpsuit == 3)
						suit = 'C';
					else if(tmpsuit == 2)
						suit = 'D';
					else if(tmpsuit == 1)
						suit = 'H';
					else if(tmpsuit == 0)
						suit = 'S';
					//	change the 'x' to suit
					for(int j = 0; j < 11; ++j)
						if(card[tmppip][height][j] == 'x')
							card[tmppip][height][j] = suit;
					//	ANSIPRINT
					if(suit == 'D' || suit == 'H')
					{
						if(counter == 0 && i == 0 && !showFirst)
							AnsiPrint(space, red, white, false, false);
						else
							AnsiPrint(card[tmppip][height],red, white, false, false);
					}
					else
					{
						if(counter == 0 && i == 0 && !showFirst)
							AnsiPrint(space, black, white, false, false);
						else
							AnsiPrint(card[tmppip][height],black, white, false, false);
					}
					cout << " ";
					//	recover the change of 'x'
					for(int j = 0;j < 11; ++j)
						if(card[tmppip][height][j] > 65)
							card[tmppip][height][j] = 'x';
				}
				cout << endl;
			}
			cout << endl;
			counter += 5;
		}
		else 	//	remains less than 5 cards
		{
			for(int height = 0; height < 11; ++height)
			{
				if(height < 6 && !printwords)
				{
					if(height == 5)
						printwords = true;
					cout << words[height] << "  ";
				}
				else
					cout << "  ";
				for(int i = 0; i < (ncards - counter); ++i)
				{
					Card tmp = bjplayer.DrawCards[counter+i];
					int tmppip = tmp.getPip() - 1;
					int tmpsuit = tmp.getSuit();
					if(tmpsuit == 3)
						suit = 'C';
					else if(tmpsuit == 2)
						suit = 'D';
					else if(tmpsuit == 1)
						suit = 'H';
					else if(tmpsuit == 0)
						suit = 'S';
					//	change the 'x' to suit
					for(int j = 0; j < 11; ++j)
						if(card[tmppip][height][j] == 'x')
							card[tmppip][height][j] = suit;
						//	ANSIPRINT
					if(suit == 'D' || suit == 'H')
					{
						if(counter == 0 && i == 0 && !showFirst)
							AnsiPrint(space, red, white, false, false);
						else
							AnsiPrint(card[tmppip][height],red, white, false, false);
					}
					else
					{
						if(counter == 0 && i == 0 && !showFirst)
							AnsiPrint(space, black, white, false, false);
						else
							AnsiPrint(card[tmppip][height],black, white, false, false);
					}
					cout << " ";

					//	recover the change of 'x'
					for(int j = 0;j < 11; ++j)
						if(card[tmppip][height][j] > 65)
							card[tmppip][height][j] = 'x';
				}
				cout << endl;
			}
			cout << endl;
			counter += (ncards - counter);
		}
	}
}

