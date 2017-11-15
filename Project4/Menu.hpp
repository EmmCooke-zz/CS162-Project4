/*************************************************
* Author: Emmet Cooke
* Description: This is the header file for the Menu class.
*************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using std::string;

class Menu
{
private:
	string prompt;
	int menuSize;
	string* options;

public:
	// Default Constructor
	Menu(int numOptions);

	// Constructor that takes prompt
	Menu(string promptIn, int numOptions);

	// Destructor
	~Menu() { delete[] options; }

	// Getters
	string getPrompt() const { return prompt; }
	string* getOptions() const { return options; }
	int getMenuSize() const { return menuSize; }

	// Setters
	void setPrompt(string promptIn) { prompt = promptIn; }
	void setMenuSize(int sizeIn) { menuSize = sizeIn; }
	void setOption(int optionNumber, string optionIn) const;
	

	// Prints the prompt
	void printPrompt() const;
	// Prints the menu
	void printOptions() const;
};

#endif
