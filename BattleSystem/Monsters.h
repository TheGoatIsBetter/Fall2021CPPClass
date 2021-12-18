#pragma once
#include <string>
#include "Creatures.h"

using namespace std;

//class declaration of Monsters, defined in Monsters.cpp
//purpose of header file is to allow these to be used in other files that just need to include this
//header file
//Monsters class is also a child inheriting from parent Creatures class
class Monsters : public Creatures{
public:
	int struggle(int, int);
};

//class declaration of Goblin, defined in Monsters.cpp
//Goblin class is also a child inheriting from parent Monsters class
class Goblin : public Monsters {
public:
	int atk;

	Goblin(string, int, int, int);
	int GetATK();
};