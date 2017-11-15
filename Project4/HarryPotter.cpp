/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This file contains the definitions
* for the functions declared in the HarryPotter class.
*************************************************/
#include <iostream>
using std::cout;
using std::endl;

#include "HarryPotter.hpp"

/*************************************************
* Description: Default Constructor.
*************************************************/
HarryPotter::HarryPotter()
{
	name = "Harry Potter";

	// Attack Die
	setNumAttackDie(2);
	setDieSides(6);

	// Defense Die
	setNumDefenseDie(2);

	// Armor
	setArmor(0);

	// Strength
	setStrength(10);
}

/*************************************************
* Description: Destructor.
*************************************************/
HarryPotter::~HarryPotter()
{
}

/*************************************************
* Description: Harry's reduceStrength function.
* If Harry dies, he returns with double the strength.
*************************************************/
void HarryPotter::reduceStrength(int damageIn)
{
	if (damageIn > 0)
	{
		damageIn -= getArmor();
		setStrength(getStrength() - damageIn);
		// Harry's special ability
		if (getStrength() < 1)
		{
			if (hogwarts)
			{
				cout << "Harry has died, but his time is not up!";
				cout << " He revives at twice the strength!" << endl;
				setStrength(20);
				hogwarts = false;
			}
		}
	}
}

/*************************************************
* Description: Returns the classes name.
*************************************************/
string HarryPotter::getName()
{
	return name;
}
