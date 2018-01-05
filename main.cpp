#include <iostream>
#include "MatchGame.h"
using namespace std;

//main function
int main()
{
	//prints the welcoming message
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "WELCOME TO THE CARD GAME" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	int numberPlayers, maximumRank; //variables representing the number of players and maximum rank of the cards
	
	while (true) //loops until break occurs
	{
		cout << endl << "Enter the number of players" << endl; 
		cin >> numberPlayers; //user inputs number of players
		cout << endl << "Enter the maximum rank of the cards" << endl;
		cin >> maximumRank; //user inputs maximum rank of cards

		//if the number of cards in each player's hand totaled is greater than the total number of cards then error message
		if (numberPlayers * 6 - maximumRank * 4 >= 0 || maximumRank > 10)
			cout << "Invalid, enter again please! " << endl;
		else
			break; //breaks loop if the above if statement is not true
	}

	MatchGame game (numberPlayers, maximumRank); //initializes MatchGame variable game with parameters numberPlayers and maximumRank
	game.play(); //game calls the play function 
	return 0;
}