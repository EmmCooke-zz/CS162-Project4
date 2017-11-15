/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This is the header file for the
*FantasyGame class.
*************************************************/
#include <memory>
using std::shared_ptr;
#include "Character.hpp"


class FantasyGame
{
private:
	Character * fighter1 = nullptr;
	Character * fighter2 = nullptr;
public:
	// Default Constructor
	FantasyGame();
	// Destructor
	~FantasyGame();

	// Getters
	Character * getFighter1() const { return fighter1; }
	Character * getFighter2() const { return fighter2; }

	// Setters
	void setFighter1(int fighterIn);
	void setFighter2(int fighterIn);

	// Run the game function
	void runGame();
	int printHeroes(int heroNum);
	void printStats(Character * attacker, int attackRoll,
					Character * defender, int defendRoll);
};

