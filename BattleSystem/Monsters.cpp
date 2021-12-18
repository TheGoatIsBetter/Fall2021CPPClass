#include <string>
#include <iostream>
#include "Monsters.h"

using namespace std;

//Monster struggle ability
int Monsters::struggle(int attack, int health) {
	//takes a random number between 0 and half of attack + health / 10
	srand(time(NULL));
	int dmg = rand() % (attack / 2) + (health / 10);
	return (dmg);
}

//constructor for goblin classes
Goblin::Goblin(string monsterName, int health, int mana, int attack) {
	name = monsterName;
	hp = health;
	mp = mana;
	atk = attack;
}

//getter for getting sgoblin attack
int Goblin::GetATK() {
	return Goblin::atk;
}

