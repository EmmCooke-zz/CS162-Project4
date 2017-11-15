/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This is the header file for the
* BlueMen class. 
*************************************************/
#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include "Character.hpp"
class BlueMen :
	public Character
{
private:
	int cummulativeDamage = 0;
public:
	// Default Constructor
	BlueMen();
	// Destructor
	~BlueMen();

	// Pure virtual function from Character
	virtual string getName();

	// Virtual function overriden from Character
	virtual void reduceStrength(int damageIn);
};

#endif