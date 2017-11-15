/*************************************************
* Author: Emmet Cooke
* Date: 11/3/2017
* Description: This is the header file for the
* Character class.
*************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
using std::string;

#include <cstdlib> // for rand()

class Character
{
protected:
	string name;

private:
	
	// attack
	int numAttackDie;
	int dieSides;

	// defense
	int numDefenseDie;

	int armor;
	int strength;
public:
	// Default Constructor
	Character();
	// Destructor
	~Character();

	// Getters
	int getNumAttackDie() const { return numAttackDie; }
	int getDieSides() const { return dieSides; }
	int getNumDefenseDie() const { return numDefenseDie; }
	int getArmor() const { return armor; }
	int getStrength() const { return strength; }

	// Setters
	void setNumAttackDie(int numAttackDieIn) { numAttackDie = numAttackDieIn; }
	void setDieSides(int dieSidesIn) { dieSides = dieSidesIn; }
	void setNumDefenseDie(int numDefenseDieIn) { numDefenseDie = numDefenseDieIn; }
	void setArmor(int armorIn) { armor = armorIn; }
	void setStrength(int strengthIn) { strength = strengthIn; }

	bool alive();

	// Virual functions to be overriden
	virtual void reduceStrength(int damageIn);
	virtual int attack();
	virtual int defend();
	virtual string getName() = 0;
};

#endif