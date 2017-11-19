/*************************************************
* Program: Project 4 - Fantasy Tournament
* Author: Emmet Cooke
* Date: 11/15/2017
* Description: This file runs the Fantasy Tournament.
* The user is asked if they want to run the tournament, 
* and if they do, the required functions are run.
* Otherwise, the game exits.
*************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Menu.hpp"
#include "validateInput.hpp"
#include "FantasyTournament.hpp"

int main()
{
	Menu mainMenu("Welcome to the Fantasy Fighting Game.", 2);
	mainMenu.setOption(0, "Play Game");
	mainMenu.setOption(1, "Exit");

	bool exitChoice = false;
	string validateInput;
	int menuChoice;
	FantasyTournament game;
	mainMenu.printPrompt();

	do
	{
		mainMenu.printOptions();
		getline(cin, validateInput);
		menuChoice = getInt(validateInput);

		switch (menuChoice)
		{
		case 1: // Run the game
			cout << endl;
			game.runTournament();
			exitChoice = true;
			break;
		case 2: // Exit
			exitChoice = true;
			break;
		default:
			cout << "Please enter a valid menu choice." << endl;
		}
	} while (!exitChoice);

	cout << "Thank you for playing Fantasy Tournament!" << endl;
	return 0;
}