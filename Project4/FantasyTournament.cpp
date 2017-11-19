/*************************************************
* Author: Emmet Cooke
* Date: 11/17/2017
* Description: This file contains the definitions
* for the functions declared in the FantasyTournament
* class.
*************************************************/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "validateInput.hpp"
#include "FantasyTournament.hpp"
#include "Menu.hpp"

// All of the character classes
#include "Character.hpp"
#include "Vampire.hpp"		
#include "Barbarian.hpp"	
#include "BlueMen.hpp"		
#include "Medusa.hpp"
#include "HarryPotter.hpp"

/*************************************************
* Description: Default Constructor.
*************************************************/
FantasyTournament::FantasyTournament()
{
}

/*************************************************
* Description: Destructor. If there are nodes in
* the three different queues, this clears them.
*************************************************/
FantasyTournament::~FantasyTournament()
{
	CharacterList * removeThis = nullptr;
	// Delete Player 1
	if (player1 != nullptr)
	{
		while (player1 != nullptr)
		{
			removeThis = player1;
			player1 = player1->next;
			delete removeThis;
		}
	}

	// Delete Player 2
	if (player2 != nullptr)
	{
		while (player2 != nullptr)
		{
			removeThis = player2;
			player2 = player2->next;
			delete removeThis;
		}
	}

	// Delete Losers
	if (losers != nullptr)
	{
		while (losers != nullptr)
		{
			removeThis = losers;
			losers = losers->next;
			delete removeThis;
		}
	}
}

/*************************************************
* Description: This function broadly runs the
* tournament. It first gets the heroes from the
* user, then causes them to fight, and then it
* determines who won and outputs a statement for that.
*************************************************/
void FantasyTournament::runTournament()
{
	// Prints the menu for the user and allows them
	// to set the number of heroes, which class they are,
	// and those heroes names
	printMenu();

	// The heroes within each queue fight
	// The returned value determines which
	// player won
	int tournamentWinner = fightTournament();

	// Draw
	if (tournamentWinner == 0)
	{
		cout << "Draw!" << endl;
	}// Player 1 won
	if (tournamentWinner == 1)
	{
		cout << "Player 1 wins!" << endl;
	}// Player 2 won
	if (tournamentWinner == 2)
	{
		cout << "Player 2 wins!" << endl;
	}

	// Ask the user if they want to see the losers queue
	string validateInput;
	do
	{
		cout << "Would you like to see the losers (y/n)? ";
		getline(cin, validateInput);
		if (validateInput.length() > 1
			|| (tolower(validateInput[0]) != 'y'
				&& tolower(validateInput[0]) != 'n'))
		{
			cout << "Please enter either 'y' or 'n'." << endl;
		}
	} while (validateInput.length() > 1
		|| (tolower(validateInput[0]) != 'y'
			&& tolower(validateInput[0]) != 'n'));

	// They wish to view the losers
	if (validateInput == "y")
	{
		CharacterList * losersList = losers;
		int position = 1;
		while (losersList != nullptr)
		{
			cout << position++ << ": " << losersList->fighter->getName();
			cout << endl;
			losersList = losersList->next;
		}
	}
}

/*************************************************
* Description: This function runs the main fights
* of the tournament. It pits the characters from
* each queue against each other until one or both
* of the queues are empty. At that point, it returns
* a value that relates to which player lost.
*************************************************/
int FantasyTournament::fightTournament()
{
	int fightWinner,
		round = 1;
	// While either player has fighters
	while (player1 != nullptr && player2 != nullptr)
	{
		// This function determines which character wins
		// It's from the FantasyGame class
		fightWinner = fight(player1->fighter, player2->fighter);

		cout << "Round " << round << endl;
		cout << "Team A: " << player1->fighter->getName();
		cout << " vs " << "Team B: " << player2->fighter->getName();
		cout << endl;

		// This function sorts out where the fighters go
		// It places the losers onto the losers queue
		// and moves the winner to the bottom of their
		// respective players queue
		fightResults(fightWinner);
		
		// Determine the winner
		// Player 2 wins
		if (player1 == nullptr)
		{	// Both lost all heroes
			if (player2 == nullptr)
			{
				return 0;
			}
			return 2;
		} // Player 1 wins
		if (player2 == nullptr)
		{	// Both lost all heroes
			if (player1 == nullptr)
			{
				return 0;
			}
			return 1;
		}
		round++;
	}
}

/*************************************************
* Description: This function determines where the
* heroes are moved after they have fought. If they
* won, they are moved to the bottom of their queue.
* If they lost, they are moved to the bottom of the
* loser queue. If a draw, both are moved to the
* loser queue.
*************************************************/
void FantasyTournament::fightResults(int winner)
{
	// There was a draw
	if (winner == 0)
	{
		cout << "Draw! Both died!" << endl;
		moveToLosers(player1);
		moveToLosers(player2);
	} // Player 2 won
	if (winner == 1)
	{
		cout << player2->fighter->getName() << " wins!" << endl;
		moveToBack(player2);
		moveToLosers(player1);
	} // Player 1 won
	if (winner == 2)
	{
		cout << player1->fighter->getName() << " wins!" << endl;
		moveToBack(player1);
		moveToLosers(player2);
	}
}

/*************************************************
* Description: This function moves the head of the
* input queue to the back of the queue. During this, 
* it rolls a d10 to determine exactly how much
* of its max health is regenerated.
*************************************************/
void FantasyTournament::moveToBack(CharacterList * &player)
{
	// Track the head node
	CharacterList * head = player;
	// Move to the back of the queue
	while (player->next != nullptr)
	{
		player = player->next;
	}

	// Recovers health for the hero
	int recoverHealth = ((rand() % 10 + 1) / 100) * head->fighter->getStrength();
	head->fighter->setStrength(head->fighter->getStrength() + recoverHealth);

	// End of the queue
	player->next = head;
	// Second node
	player = head->next;
	// Now head node is at the end
	head->next = nullptr;
	
}

/*************************************************
* Description: This function moves the head of the
* input queue to the back of the losers queue.
*************************************************/
void FantasyTournament::moveToLosers(CharacterList * &player)
{
	// Tracks the head node
	CharacterList * head = player;
	
	// Moves the players head to the next one
	player = head->next;
	// head node no longer points to the next player node
	head->next = nullptr;

	// If there are no nodes in the loser queue
	if (losers == nullptr)
	{
		losers = head;
	} // Adds the head node to the back of the loser queue
	else
	{	// loser head node to reassign losers to
		CharacterList * losersHead = losers;
		// Goes to the back
		while (losers->next != nullptr)
		{
			losers = losers->next;
		}
		// Sets the head to the end of the queue
		losers->next = head;
		// sets losers back to the head
		losers = losersHead;
	}
	
	
}

/*************************************************
* Description: This function asks the users how
* many heroes they would like for each player
* and what type of hero they should be.
*************************************************/
void FantasyTournament::printMenu()
{
	string validateInput;
	int fighters;

	cout << "Welcome to the Fantasy Tournament!" << endl << endl;
	// Gets the number of fighters
	do
	{
		cout << "How many fighters would you like for either team? ";
		getline(cin, validateInput);
		fighters = getInt(validateInput);
		if (fighters < 0)
		{
			cout << "Please enter a positive int." << endl;
		}
	} while (fighters < 0);

	// If they have chosen to have fighters
	if (fighters > 0)
	{	// Sets player 1s heroes
		cout << "Please choose player 1's heroes." << endl;
		setHeroes(player1, fighters);
		// Sets player 2s heroes
		cout << "Please choose player 2's heroes." << endl;
		setHeroes(player2, fighters);
	}
}

/*************************************************
* Description: This function takes in the players
* queue and the number of heroes they should have.
* It then asks the user for the hero they would like
* and adds that to the players queue.
*************************************************/
void FantasyTournament::setHeroes(CharacterList * &player, int numFighters)
{	// The number of desired heroes
	int * heroArray = new int[numFighters];
	// Their names
	string * nameArray = new string[numFighters];

	// Loops until the number of desired heroes have been added to the arrays
	for (int i = 0; i < numFighters; i++)
	{
		heroArray[i] = printHeroes();
		cout << "What is that hero's name? ";
		getline(cin, nameArray[i]);
	}

	// Goes backwards through the queue creating the heroes nodes
	for (int i = numFighters - 1; i >= 0; i--)
	{
		if (i == numFighters - 1)
		{
			player = new CharacterList(setFighter(heroArray[i]), nameArray[i]);
		}
		else
		{
			player = new CharacterList(setFighter(heroArray[i]), nameArray[i], player);
		}
	}
}

/*************************************************
* Description: This function returns a new class
* of the desired hero type.
*************************************************/
Character * FantasyTournament::setFighter(int heroPick)
{
	switch (heroPick)
	{
	case 1: return new Vampire;
	case 2: return new Barbarian;
	case 3: return new BlueMen;
	case 4: return new Medusa;
	case 5: return new HarryPotter;
	}
}
