#pragma once

#include <string>

using namespace std;

//class declaration of Creatures, defined in Creatures.cpp
//purpose of header file is to allow these to be used in other files that just need to include this
//header file
class Creatures {
public:
	string name;
	int hp;
	int mp;

	string GetName();
	void SetHP(int);
	int GetHP();
	void SetMP(int);
	int GetMP();

	Creatures();
};