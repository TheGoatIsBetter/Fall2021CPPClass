#pragma once
#include <string>

using namespace std;

//function declarations defined in BattleManager.cpp
//purpose of header file is to allow these to be used in other files that just need to include this
//header file
char inputValidator(int size, char options[], const char* actions[]);
void clear();
void displayMenu(string, string, int, int, int, int, int, int);