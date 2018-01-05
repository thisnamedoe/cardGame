#include "MatchCard.h"

//constructor for MatchCard which initializes private members m_suit and m_rank as the parameters of the constructor
MatchCard::MatchCard(Suit suit, int rank) : m_suit(suit), m_rank(rank)
{
}

//default constructor for MatchCard
MatchCard::~MatchCard()
{

}

//function for outputing MatchCards using operator <<
std::ostream& operator<<(std::ostream& os, const MatchCard &c)
{
	//variables initialized to the ones from MatchCard class
	Suit suit = c.getSuit(); 
	int rank = c.getRank();
	//outputs the rank of the card first
	os << rank;

	//switch for the suits of the cards (4 cases)
	switch (suit) {
	case 1:
		os << " of Spades";
		break;
	case 2:
		os << " of Hearts";
		break;
	case 3:
		os << " of Clubs";
		break;
	default:
		os << " of Diamonds";
	}
	return os; //returns the output statement 
}