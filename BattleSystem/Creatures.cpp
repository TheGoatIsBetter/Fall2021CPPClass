#include <string>
#include "Creatures.h"

using namespace std;

//creature constructor for creature child classes to inherit from
//do not use this on it's own
Creatures::Creatures() {
	name = "";
	hp = 100;
	mp = 50;
}

//getter for getting a creature name
string Creatures::GetName() {
	return Creatures::name;
}

//setter for setting a creature's health
void Creatures::SetHP(int newHP) {
	Creatures::hp = newHP;
}

//getter for getting a creature's health
int Creatures::GetHP() {
	return Creatures::hp;
}

//setter for setting a creature's mana
void Creatures::SetMP(int newMP) {
	Creatures::mp = newMP;
}

//getter for getting a creature's mana
int Creatures::GetMP() {
	return Creatures::mp;
}