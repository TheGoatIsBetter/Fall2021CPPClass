#pragma once
#include <string>
#include "Creatures.h"

using namespace std;


//class declaration of Player, defined in Player.cpp
//purpose of header file is to allow these to be used in other files that just need to include this
//header file
//Player class is also a child inheriting from parent Creatures class
class Player : public Creatures {
public:
	int atk;
	int spl;
	
	Player(string, int, int, int, int);
	int GetATK();
	int GetSPL();
};

