#include "MatchGame.h"
#include "time.h"

//constructor for MatchGame which takes in parameters for number of players and maximum rank of cards
	MatchGame::MatchGame(int numPlayers, int maxRank) : players(numPlayers), rank(maxRank) //initalizes players to numPlayers and rank to maxRank
	{
		OrderedList<MatchCard> allcards(maxRank * 4); //temporary holder as an orderedlist for the deck of cards 
		thePlayers = new MatchPlayer[players]; //sets container thePlayers to contain the number of players
		Suit suit; //enum from MatchCard
		
		//inserts all of the cards into the deck with MatchCard parameters (suit, k)
		for (int c = 1; c <= 4; c++)
		{
			if (c == 1)
				suit = SPADES;
			else if (c == 2)
				suit = HEARTS;
			else if (c == 3)
				suit = CLUBS;
			else
				suit = DIAMONDS;
			for (int k = 1; k <= maxRank; k++)
			{
				allcards.insert(MatchCard(suit, k));
			}
		}


		int x; //random variable
		MatchCard value; //temporary holder of the value of the selected random card

		
		srand(time(NULL)); //randomizes the rand() function

		//randomizes and creates the queue for the deck
		for (int z = maxRank * 4; z >= 1; z--)
		{
			x = rand() % z; 
			value = allcards.remove(x + 1); //removes the card from the deck that was selected and sets value equal to it
			cout << value << endl; //outputs the deck 
			deck.enqueue(value); //enqueues the deck with random cards from allcards until allcards is empty
		}

		//adds cards to each player's hand from the deck
				for (int c = 0; c < numPlayers; c++)
				{
					for (int q = 1; q <= 6; q++)
					{
					thePlayers[c].addCard(deck.dequeue()); //adds 6 cards to each player's hand to begin the game and also removes a card from the deck
					}
				}

				up.push(deck.dequeue()); //faceup pile now has a card and a card  from the deck is removed

	}

	//default deconstructor for MatchGame
	MatchGame::~MatchGame()
	{
		delete[] thePlayers; //deletes the container for thePlayers
	}
	
	//play function for the game
	void MatchGame::play()
	{
		int playerTurn = 0; //playerTurn is initialized to 0
		cout << endl << "LET THE GAME BEGIN!" << endl;
		int checkCardMatch = 0; //checks the position of the card that has matched with the faceup pile in the player's hand


		//code for the game 
		while (true) //infinite loop until break occurs 
		{ 

			playerTurn++; //playerturn is incremented 

			if (playerTurn == players + 1) //if playerturn surpasses the number of players it gets reset to the first player
			{
				playerTurn = 1;
			}
			cout << endl << "THE CARD ON TOP OF THE PILE IS: " << up.peek() << endl; //outputs the card on top of the face up pile from the stack 
			cout << "It is Player " << playerTurn << " 's turn! " << endl;
			cout << "Here is your hand: " << endl << thePlayers[playerTurn - 1] << endl; //outputs playerhand

			checkCardMatch = thePlayers[playerTurn - 1].cardMatch(up.peek()); //obtains where the card in the player's hand the card was matched at

			//checks to see if card was matched and what happens if it is
			if (checkCardMatch == 0) //if cards in the player's hand do not match the card  on top of the face up pile
			{
				cout << "Player " << playerTurn << " did not find a match. They drew a card. " << endl;
				cout << "You have drawn " << deck.peek() << " from the deck. " << endl; //looks at the card on top of the deck
				thePlayers[playerTurn - 1].addCard(deck.dequeue()); //adds a card to the player's hand and removes one from the deck
				cout << "Here is your hand: " << endl << thePlayers[playerTurn - 1] << endl; //outputs hand after card was added
			}
			else //a card in the player's hand was matched with the one on top of the face up pile
			{
				cout << "Player " << playerTurn << " found a match! " << endl;
				//the card in the player's hand that was matched is added to the top of the face up pile and the card is removed from the player's hand
				cout << "Player " << playerTurn <<  " played " << thePlayers[playerTurn-1].getCard(checkCardMatch) << " and it has been added to the pile!" << endl;
				up.push(thePlayers[playerTurn - 1].getCard(checkCardMatch));
				thePlayers[playerTurn - 1].removeCard(checkCardMatch);
			}

			//outputs a message if only one card remains in the player's hand
			if (thePlayers[playerTurn - 1].getLength() == 1)
				cout << "Player " << playerTurn << " yells Last-card!" << endl;
			//outputs a message if no cards are remaining in the player's hand and ends the infinite loop
			if (thePlayers[playerTurn - 1].getLength() == 0)
			{
				cout << "Player " << playerTurn << " has DESTROYED their opponents. NOT EVEN CLOSE BAYBEE" << endl;
				break; //ends infinite loop
			}

			//if the deck is empty
			if (deck.isEmpty())
			{
				MatchCard temp = up.peek(); //temporary variable that stores the card at the top of the face up pile
				for (int i = up.size(); i >= 1; i--)
				{
					deck.enqueue(up.pop()); //adds to the deck cards from the faceup pile while removing cards from the faceup pile
				}
				up.push(temp); //face up card is now the temporary variable that stored it
				cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "THE DECK HAS BEEN REPOPULATED" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			}

			system("pause"); //asks for user input and outputs a message telling the user to press to continue
		}
		delete[] thePlayers; //deletes the players

	}