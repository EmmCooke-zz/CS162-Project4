/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This file contains the definitions
* for the functions declared in the Medusa class.
*************************************************/
#include <iostream>
using std::cout;
using std::endl;

#include "Medusa.hpp"


/*************************************************
* Description: Default Constructor.
*************************************************/
Medusa::Medusa()
{
	name = "Medusa";

	// Attack Die
	setNumAttackDie(2);
	setDieSides(6);

	// Defense Die
	setNumDefenseDie(1);

	// Armor
	setArmor(3);

	// Strength
	setStrength(8);
}

/*************************************************
* Description: Destructor.
*************************************************/
Medusa::~Medusa()
{
}

/*************************************************
* Description: Medusa's attack function. The
* attackRoll variable is incremented until the 
* corrent number of rolls has taken place. This value
* is then returned.
*************************************************/
int Medusa::attack()
{
	int attackRoll = 0;
	for (int i = 0; i < getNumAttackDie(); i++)
	{
		attackRoll += rand() % getDieSides() + 1;
		// Medusa's special ability Glare
		// 50 damage is enough to overpower anyone
		if (attackRoll == 12)
		{
			cout << "Medusa uses Glare! It's super effective!" << endl;
			return 50;
		}
	}
	return attackRoll;
}

/*************************************************
* Description: Returns the classes name.
*************************************************/
string Medusa::getName()
{
	return name;
}