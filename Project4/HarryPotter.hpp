/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This is the header file for the
* Barbarian class. 
*************************************************/
#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include "Character.hpp"
class HarryPotter :
	public Character
{
private:
	bool hogwarts = true;
public:
	// Default Constructor
	HarryPotter();
	// Destructor
	~HarryPotter();

	// Pure virtual function from Character
	virtual string getName();

	// Virtual function overriden from Character
	virtual void reduceStrength(int damageIn);
};

#endif