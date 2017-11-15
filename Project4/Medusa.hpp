/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This is the header file for the
* Medusa class. 
*************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"
class Medusa :
	public Character
{
public:
	// Default Constructor
	Medusa();
	// Destructor
	~Medusa();

	// Pure virtual function from Character
	virtual string getName();

	// Virtual function overriden from Character
	virtual int attack();
};

#endif