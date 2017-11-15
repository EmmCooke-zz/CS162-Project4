/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This is the header file for the
* Barbarian class. 
*************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"
class Barbarian :
	public Character
{
public:
	// Default Constructor
	Barbarian();
	// Destructor
	~Barbarian();

	// Pure virtual function from Character
	virtual string getName();
};

#endif