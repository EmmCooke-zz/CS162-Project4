/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This file contains the definitions
* for the functions declared in the BlueMan class.
*************************************************/
#include <iostream>
using std::cout;
using std::endl;


#include "BlueMen.hpp"

/*************************************************
* Description: Default Constructor.
*************************************************/
BlueMen::BlueMen()
{
	name = "Blue Men";

	// Attack Die
	setNumAttackDie(2);
	setDieSides(10);

	// Defense Die
	setNumDefenseDie(3);

	// Armor
	setArmor(3);

	// Strength
	setStrength(12);
}

/*************************************************
* Description: Destructor.
*************************************************/
BlueMen::~BlueMen()
{
}

/*************************************************
* Description: Reduces the strength of the class.
* If the BlueMan's strength drops by four, they 
* lose a die.
*************************************************/
void BlueMen::reduceStrength(int damageIn)
{
	if (damageIn > 0)
	{
		damageIn -= getArmor();
		cummulativeDamage += damageIn;
		setStrength(getStrength() - damageIn);
		if (cummulativeDamage >= 4)
		{
			cout << "A Blue Man has died!" << endl;
		}
		// BlueMen's special ability is Mob
		// If their strength is reduced by 4, they lose a die
		setNumDefenseDie(getStrength() / 4);
	}
}

/*************************************************
* Description: Returns the classes name.
*************************************************/
string BlueMen::getName()
{
	return name;
}