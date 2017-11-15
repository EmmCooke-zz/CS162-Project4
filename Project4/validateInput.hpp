/*************************************************
* Author: Emmet Cooke
* Date: 10/18/2017
* Description: This is the header file for the 
* validateInput functions.
*************************************************/
#ifndef VALIDATE_INPUT_HPP
#define VALIDATE_INPUT_HPP

#include <string>
using std::string;

bool checkStringToInt(string);

int getInt(string);
double getDouble(string);

void getNum(int &num);
#endif

