/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This file contains the definitions
* for the functions declared in the Barbarian class.
*************************************************/
#include "Barbarian.hpp"

/*************************************************
* Description: Default Constructor. 
*************************************************/
Barbarian::Barbarian()
{
	name = "Barbarian";

	// Attack Die
	setNumAttackDie(2);
	setDieSides(6);

	// Defense Die
	setNumDefenseDie(2);

	// Armor
	setArmor(0);

	// Strength
	setStrength(12);
}

/*************************************************
* Description: Destructor.
*************************************************/
Barbarian::~Barbarian()
{
}

/*************************************************
* Description: Returns the classes name.
*************************************************/
string Barbarian::getName()
{
	return name;
}
