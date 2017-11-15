/*************************************************
* Program: 
* Author: Emmet Cooke
* Date: 11/15/2017
* Description: 
*************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Menu.hpp"
#include "validateInput.hpp"
#include "FantasyGame.hpp"

int main()
{
	Menu mainMenu("Welcome to the Fantasy Fighting Game.", 2);
	mainMenu.setOption(0, "Play Game");
	mainMenu.setOption(1, "Exit");

	bool exitChoice = false;
	string validateInput;
	int menuChoice;
	FantasyGame game;
	mainMenu.printPrompt();

	do
	{
		mainMenu.printOptions();
		getline(cin, validateInput);
		menuChoice = getInt(validateInput);

		switch (menuChoice)
		{
		case 1: // Run the game
			cout << endl << endl;
			game.runGame();
			exitChoice = true;
			break;
		case 2: // Exit
			exitChoice = true;
			break;
		default:
			cout << "Please enter a valid menu choice." << endl;
		}
	} while (!exitChoice);

	cout << "Thank you for playing Fantasy Fighter!" << endl;
	return 0;
}