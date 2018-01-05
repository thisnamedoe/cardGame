#include "MatchPlayer.h"

//default constructor for MatchPlayer, initalizes player's hand to 40 (this does not matter as only 6 cards will be added to the player's hand)
MatchPlayer::MatchPlayer(): hand (OrderedList<MatchCard> (40))
{
}

//default deconstructor for MatchPlayer
MatchPlayer::~MatchPlayer()
{
}

//function for checking if any card in the player's hand matches another card
int MatchPlayer::cardMatch(MatchCard card)
{	
	for (int k = 1; k <= hand.getLength(); k++)
	{
		if (hand.retrieve(k) == card)
			return k; //if a card matches, then return the position of the card that was matched
	}
	return 0; //return 0 if no card matched

}

//function for adding a card into the player's hand
int MatchPlayer::addCard(MatchCard card)
{
	return hand.insert(card); //returns the position of where the card was added (function insert from OrderedList is called)
}

//retrieves the card at position pos in the player's hand
MatchCard MatchPlayer::getCard(unsigned pos)
{
	return hand.retrieve(pos); //returns the card at the position (function retrieve from OrderedList is called)
}

//removes a card from the player's hand at position pos
MatchCard MatchPlayer::removeCard(unsigned pos)
{
	return hand.remove(pos); //returns the card that was removed from the player's hand (function remove from OrderedList is called)
}

//function that obtains the length of the player's hand
int MatchPlayer::getLength()
{
	return hand.getLength(); //returns the size of the player's hand (getLength from OrderedList is called)
}

//function which outputs the player's entire hand 
ostream& operator<<(ostream& os, const MatchPlayer &c) 
{ 
	for (int i = 1; i <= c.hand.getLength(); i++)
		os << c.hand.retrieve(i) << "    ";
	return os;
}
