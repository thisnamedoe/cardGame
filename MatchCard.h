#pragma once
#include <iostream>
#include "OrderedList.h" //includes orderedlist file


enum Suit { SPADES = 1, HEARTS = 2, CLUBS = 3, DIAMONDS = 4 }; //enum for the suit of the cards

class MatchCard //class declaration for MatchCard
{
public: //public members
	MatchCard(Suit suit = SPADES, int rank = 1); //constructor for MatchCard which sets default suit to SPADES and default rank to 1
	~MatchCard(); //destructor for MatchCard
	
	inline Suit getSuit(void) const { return m_suit; } //inline function that returns the suit of the card
	inline int getRank(void) const { return m_rank; } //inline function that returns the rank of the card

private: //private members
	Suit m_suit; //suit of the card
	int m_rank; //rank of the card
	friend std::ostream& operator<<(std::ostream& os, const MatchCard &c); //function for << operator as a friend so it can access private variables
}; 

inline bool operator==(MatchCard &a, MatchCard &b) //inline function for the operator ==
{

	return (a.getRank() == b.getRank() || a.getSuit() == b.getSuit()); //checks if the cards are equal if the rank OR the suit are the same
}

inline bool operator<(const MatchCard& a, const MatchCard& b)  //inline function for the operator <
{ 
	if (a.getSuit() == b.getSuit()) 
		return (a.getRank() < b.getRank());
	else                           
		return (a.getSuit() < b.getSuit());   //returns true if a < b (first checks rank then checks suit)
}

inline bool operator>(const MatchCard& a, const MatchCard& b) //inline function for the operator >
{
		if (a.getSuit() == b.getSuit()) 
			return (a.getRank()>b.getRank());
		else                            
			return (a.getSuit()>b.getSuit());	//returns true if a > b (first checks rank then checks suit)
}