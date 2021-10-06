#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include "Enemy.h"

class Player{
private:
	std::string name;
	int health = 20;
public:
	Player() = default;
	Player(std::string name) : name{ name }, health{ health } {}
	~Player() = default;

	std::string get_name() { return name; }
	void set_name(std::string name) { this->name = name; }

	int get_health() { return health; }
	void set_health(int health) { this->health = health; }

	void attack(Enemy& enemy);

};

#endif