/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This file contains the definitions
* for the functions declared in the Character class.
*************************************************/
#include "Character.hpp"

/*************************************************
* Description: Default Constructor.
*************************************************/
Character::Character()
{
}

/*************************************************
* Description: Destructor.
*************************************************/
Character::~Character()
{
}

/*************************************************
* Description: Default Character attack function. 
* The attackRoll variable is incremented until the 
* corrent number of rolls has taken place. This value
* is then returned.
*************************************************/
int Character::attack()
{
	int attackRoll = 0;
	for (int i = 0; i < getNumAttackDie(); i++)
	{
		attackRoll += rand() % getDieSides() + 1;
	}
	return attackRoll;
}

/*************************************************
* Description: Returns the classes name.
*************************************************/
void Character::reduceStrength(int damageIn)
{
	if (damageIn > 0)
	{
		damageIn -= getArmor();
		setStrength(getStrength() - damageIn);
	}
}

/*************************************************
* Description: Default defend function. Returns
* true if the defender survives and false if they
* die.
*************************************************/
int Character::defend()
{
	int defendRoll = 0; 
	for (int i = 0; i < getNumDefenseDie(); i++)
	{
		defendRoll += rand() % 6 + 1;
	}
	return defendRoll;
}

/*************************************************
* Description: Returns the classes name.
*************************************************/
bool Character::alive()
{
	if (getStrength() < 1)
	{
		return false;
	}
	return true;
}
