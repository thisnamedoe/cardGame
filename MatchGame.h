#pragma once
#include "OrderedList.h"
#include "Queue.h"
#include "Stack.h"
#include "MatchPlayer.h"
#include "MatchCard.h"	
#include <iostream>
#include <time.h>	

class MatchGame //declaration of class MatchGame
{
public: //public members
	MatchGame(int numPlayers, int maxRank); //constructor for MatchGame which has parameters int number of players and int maximum rank of cards
	~MatchGame(); //default constructor for MatchGame
	void play(); //play function of the game
	MatchPlayer *thePlayers; //public member container for number of players
	
private: //private members 
	int players; //number of players
	int rank; //maximum rank of cards
	Stack <MatchCard> up; //type Stack member which represents faceup cards
	Queue <MatchCard> deck;	//type Queue member which represents the deck
};