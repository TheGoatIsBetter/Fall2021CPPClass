//TODO: Refactor the attacks and abilities in main to be similar to how the Monsters class method Struggle is done.

//include some libraries
#include <stdlib.h>
#include <iostream>

//include header files for use in here
#include "Monsters.h"
#include "Player.h"
#include "BattleManager.h"
#include "BattleSystem.h"

using namespace std;


int main() {

	cout << "This program is a bare-bones RPG battle system.  \nYou fight a goblin.  \nHe fights you." <<
		"\nYou may win.  \nYou may lose.  \nThat's all there is to it." << endl;

	//char array and pointer const char array that work with inputValidator to validate input for a continue
	char cont[1] = { 'c' };
	const char* continueGame[1] = { "Continue" };
	inputValidator(1, cont, continueGame);
	
	//clears the console
	clear();
	
	
	//enter name
	string name;
	string& nameRef = name;
	cout << "Please enter your name." << endl;
	cin >> name;

	//instantiate player and enemy goblin
	//, also done using references for player name because I couldn't refactor everything else to use them in time...
	//reference changes along with the actual variable, as it's only a reference to that variable
	Player P1(nameRef, 100, 50, 5, 10); //Name, health, mana, attack, magic attack
	Goblin Gob("Goblin", 100, 50, 5); //Name, health, mana, attack


	//main game loop
	while (true) {
		int enemyDMGTaken = 0; //keeps track of total damage enemy takes in turn, takes into account unimplemented between turns for magics such as poison
		
		//player input.  Loops to allow going between menus
		bool redo = false;
		do {
			redo = false;
			clear(); //clears console

			//displays the things listed nicely for the player to see
			displayMenu(P1.GetName(), Gob.GetName(), P1.GetHP(), P1.GetMP(), P1.GetATK(), P1.GetSPL(), Gob.GetHP(), Gob.GetMP());
			
			//2 versions of the next input validator.  This is to get rid of the Magic option from the menu when you run out of mana.
			// it works just like the continue from the beginning otherwise
			//I didn't have time to figure out how to get rid of it from the lists, so there's 2 that can be switched between...
			char mainOpts[2] = { 'a', 'm' };
			//using pointers to create an array of indexes of const char
			const char* mainActs[2] = { "Attack: 1*ATK DMG", "Magic" };
			//switch case for whichever menu option was selected
			switch (inputValidator(2, mainOpts, mainActs)) {
			case 'a': //basic attack
			{
				//clears the screen
				clear();
				//sets the enemy's health down by the player attack, and then adds the player attack to the
				//total damage the enemy has taken over the turn
				int newEnemyHP = Gob.GetHP() - P1.GetATK();
				Gob.SetHP(newEnemyHP);
				enemyDMGTaken += P1.GetATK();
				cout << P1.GetName() << " attacked " << Gob.GetName() << " and did " << P1.GetATK() << " damage." << endl;
				break;
			}
			case 'm':
			{
				clear();
				//make sure the player has MP, as if they don't they fail the spell immediately
				if (P1.GetMP() >= 5) {
					//redisplays player and enemy variables, as there is a new menu here
					displayMenu(P1.GetName(), Gob.GetName(), P1.GetHP(), P1.GetMP(), P1.GetATK(), P1.GetSPL(), Gob.GetHP(), Gob.GetMP());
					//yet another use of the input validator with some arrays and a switch
					char magicOpts[2] = { 'b', 'm' };
					const char* magicActs[2] = { "Back", "Magic Attack: Between 1 and SPL+1 DMG (5MP)" };
					switch (inputValidator(2, magicOpts, magicActs)) {
					case 'b':
						//sets redo to true, setting up the do while to repeat and go back to the first menu
						redo = true;
						break;
					case 'm':
						clear();
						//works the same as basic attack, but it does a random amount of damage using
						//the player's spell strength as the amount it can be up to minus 1, and adds 1 to make it
						// between that and 1, then also subtracts from the player's mana as well
						srand(time(NULL));
						//damage minimum of one, maximum of spell strength + 1
						int dmg = rand() % P1.GetSPL() + 1;
						enemyDMGTaken += dmg;
						P1.SetMP(P1.GetMP() - 5);
						Gob.SetHP(Gob.GetHP() - dmg);
						cout << P1.GetName() << " did a magic attack on " << Gob.GetName() << " and did " << dmg << " damage." << endl;
						break;
					}
				}
				//if you have no MP, then you fail to cast spells
				else {
					cout << P1.GetName() << " tried to cast a spell... but failed..." << endl;
				}
			}
			}
		} while (redo == true);


		//Put calculations for between-turn stuff for the enemy here.  i.e. poison damage.
		

		//Player turn results
		cout << P1.GetName() << " did a total of " << enemyDMGTaken << "DMG to " << Gob.GetName() << " this turn." << endl;
		
		inputValidator(1, cont, continueGame);
		

		//enemy attack section.  Everything below here needs full refactor to include multiple monsters
		clear();
		//player equivalent to enemyDMGTaken described above
		int playerDMGTaken = 0;
		//Goblins use MP for their attack, but otherwise, are the same as the player's basic attack
		if (Gob.GetMP() > 0) {
			playerDMGTaken += Gob.GetATK();
			Gob.SetMP(Gob.GetMP() - 5);
			P1.SetHP(P1.GetHP() - Gob.GetATK());
			cout << Gob.GetName() << " attacked " << P1.GetName() << " and did " << Gob.GetATK() << " damage." << endl;
		}
		else {
		//when the goblin runs out of MP to attack with, they start struggling just like all monsters would.
		//struggle is a calculation of rand() % attack / 2 + health / 10.
			int gobDMG = Gob.struggle(Gob.GetATK(), Gob.GetHP());
			playerDMGTaken += gobDMG;
			P1.SetHP(P1.GetHP() - gobDMG);
			cout << P1.GetName() << " struggled against " << P1.GetName() << " and did " << gobDMG << " damage." << endl;
		}


		//Put calculations for between-turn stuff for the player here.  i.e. poison damage.


		//then, the goblin's total damage over the turn towards the player is shown here.  The player is asked to continue again.
		cout << Gob.GetName() << " did a total of " << playerDMGTaken << "DMG to " << P1.GetName() << " this turn." << endl;
		inputValidator(1, cont, continueGame);


		//death check
		if (Gob.GetHP() <= 0 && P1.GetHP() <= 0) { //first check to see if tie
			cout << "You guys both died... you tie." << endl;
			//pause the console (portability way)
			cin.get();
			break;
		}
		else if (Gob.GetHP() <= 0) { //then check to see if gob died and player win
			cout << "You killed your opponent! You win!" << endl;
			//pause the console (portability way)
			cin.get();
			break;
		}
		else if (P1.GetHP() <= 0) { //then check to see if player dies and gob win
			cout << "You were killed by your opponent... you lose." << endl;
			//pause the console (portability way)
			cin.get();
			break;
		}

		
	}
	return 0;
}