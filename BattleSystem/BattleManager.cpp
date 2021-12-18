#include <iostream>
#include <stdlib.h>
#include "BattleManager.h"
#include "Player.h"
#include "Monsters.h"

using namespace std;

//displays possible inputs and validates input taken with it
char inputValidator(int size, char options[], const char* actions[]) {
	//loops until valid
	while (true) {
		cout << "\nWhat would you like to do?" << endl;
		char result;
		//iterates through the arrays given to print out the options
		for (int i = 0; i < size; i++) {
			cout << "'" << options[i] << "'" << " : " << actions[i] << endl;
		}

		//takes input
		cin >> result;

		//lowers it
		result = tolower(result);

		//iterates through possible inputs, comparing what player input with them
		for (int i = 0; i < size; i++) {
			//if one of the inputs matches, then returns it.
			if (result == options[i]) {
				return result;
			}
		}
	}
}

//clears console
void clear()
{
	//an efficient way of clearing the console without breaking anything.
	//https://www.delftstack.com/howto/cpp/how-to-clear-console-cpp/
	cout << "\x1B[2J\x1B[H";
}

//displays text-HUD, giving information on the player and enemy stats
void displayMenu(string playerName, string monsterName, int pHP, int pMP, int pATK, int pSPL, int mHP, int mMP) {
	cout << "Player: " << playerName << "\n    HP: " << pHP << "\n    MP: " << pMP << "\n    ATK: " << pATK << "\n    SPL: " << pSPL << endl;
	cout << "Enemy: " << monsterName << "\n    HP: " << mHP << "\n    MP: " << mMP << endl;
}



