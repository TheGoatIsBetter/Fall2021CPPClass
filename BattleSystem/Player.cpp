#include <string>
#include "Player.h"

using namespace std;

//constructor for player classes
Player::Player(string playName, int health, int mana, int attack, int magicAttack) {
	name = playName;
	hp = health;
	mp = mana;
	atk = attack;
	spl = magicAttack;
}

//getter for getting player attack
int Player::GetATK() {
	return Player::atk;
}

//getter for getting player spell attack
int Player::GetSPL() {
	return Player::spl;
}
