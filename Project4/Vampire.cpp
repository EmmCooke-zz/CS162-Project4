/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This file contains the definitions
* for the functions declared in the Vampire class.
*************************************************/
#include <iostream>
using std::cout;
using std::endl;

#include "Vampire.hpp"

/*************************************************
* Description: Default Constructor.
*************************************************/
Vampire::Vampire()
{
	name = "Vampire";

	// Attack Die
	setNumAttackDie(1);
	setDieSides(12);

	// Defense Die
	setNumDefenseDie(1);

	// Armor
	setArmor(1);

	// Strength
	setStrength(18);
}

/*************************************************
* Description: Destructor.
*************************************************/
Vampire::~Vampire()
{
}

/*************************************************
* Description: Vampire's reduceStrength function. Vampire's
* special ability charm is built into the function.
* There is a 50% chance that no damage is done
* to the Vampire.
* Returns true if the defender survives and false
* if they die.
*************************************************/
void Vampire::reduceStrength(int damageIn)
{
	if (damageIn > 0)
	{
		// 50% chance for the Vampire not to take damage
		if (rand() % 2 == 0)
		{
			damageIn -= getArmor();
			setStrength(getStrength() - damageIn);
		}
		else
		{
			cout << "Vampire uses Charm! He takes no damage!" << endl;
		}
	}
}


/*************************************************
* Description: Returns the classes name.
*************************************************/
string Vampire::getName()
{
	return name;
}