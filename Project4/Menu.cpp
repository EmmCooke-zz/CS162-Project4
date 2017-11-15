/*************************************************
* Author: Emmet Cooke
* Description: This file contains the definitions for
* the Menu class.
*************************************************/
#include "Menu.hpp"
#include <iostream>

/*************************************************
* Description: Constructor that takes in an int to
* determine the number of options.
*************************************************/
Menu::Menu(int numOptions)
{
	setPrompt("");
	setMenuSize(numOptions);
	options = new string[getMenuSize()];
}

/*************************************************
* Description: Constructor that takes in a prompt
* and the number of options.
*************************************************/
Menu::Menu(string promptIn, int numOptions)
{
	setPrompt(promptIn);
	setMenuSize(numOptions);
	options = new string[getMenuSize()];
}

/*************************************************
* Description: Uses the input int to determine which
* option in the array should be set to the input string.
*************************************************/
void Menu::setOption(int optionNumber, string optionIn) const
{
	if (optionNumber < getMenuSize())
	{
		options[optionNumber] = optionIn;
	}
}

/*************************************************
* Description: Prints the prompt.
*************************************************/
void Menu::printPrompt() const
{
	std::cout << getPrompt() << std::endl;
}

/*************************************************
* Description: Prints the options.
*************************************************/
void Menu::printOptions() const
{
	for (int i = 0; i < getMenuSize(); i++)
	{
		if (options[i] != "")
		{
			std::cout << i + 1 << ". ";
			std::cout << options[i] << std::endl;
		}
		
	}
}
