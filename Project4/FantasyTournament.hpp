/*************************************************
* Author: Emmet Cooke
* Date: 11/17/2017
* Description: This is the header file for the
*FantasyTournament class.
*************************************************/
#ifndef FANTASY_TOURNAMENT_HPP
#define FANTASY_TOURNAMENT_HPP

#include "FantasyGame.hpp"
class FantasyTournament :
	public FantasyGame
{
private:
	struct CharacterList
	{
		Character * fighter;
		CharacterList * next;
		CharacterList(Character * fighterIn, CharacterList * nextIn = nullptr)
		{
			fighter = fighterIn;
			next = nextIn;
		}
		CharacterList(Character * fighterIn, string nameIn = "", CharacterList * nextIn = nullptr)
		{
			fighter = fighterIn;
			fighter->setName(nameIn);
			next = nextIn;
		}
	};

	CharacterList * player1 = nullptr;
	CharacterList * player2 = nullptr;
	CharacterList * losers = nullptr;
public:
	// Default Constructor
	FantasyTournament();
	// Destructor
	~FantasyTournament();
	
	// Function to run the tournament
	void runTournament();
	// Runs the fights
	int fightTournament();

	// uses the winner to change the queues
	void fightResults(int winner);

	// Sets the heroes as determined by the player
	void setHeroes(CharacterList * &player, int numFighters);
	// sets the fighter for a node
	Character * setFighter(int fighterIn);

	// Moves the head to the back of the queue
	void moveToBack(CharacterList * &player);
	// Moves the head to the losers queue
	void moveToLosers(CharacterList * &player);

	// Prints the game menu and sets the heroes
	void printMenu();
};

#endif