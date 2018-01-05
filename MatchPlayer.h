#pragma once
#include "MatchCard.h"
#include <iostream>
#include <string>
#include "OrderedList.h"

using namespace std;

class MatchPlayer //declaration for MatchPlayer class
{ 
public: //public members
	 
	MatchPlayer(); //default constructor for MatchPlayer
	~MatchPlayer(); //default destructor for Matchplayer
	friend ostream& operator<<(ostream& os, const MatchPlayer &c); //friend function for operator <<
	int cardMatch(MatchCard card); //checks for matching cards and returns the position of the card as an integer
	int addCard(MatchCard card); //adds a card into the hand and returns the position of where the card was inserted as an integer
	MatchCard getCard(unsigned pos); //function which returns the card at a position in the hand
	MatchCard removeCard(unsigned pos); //function which returns the card that was removed from a position in the hand
	int getLength(); //function which returns the size of the hand

private:		// private members
	OrderedList<MatchCard> hand; //OrderedList of type MatchCard which represents the player's hand
};	