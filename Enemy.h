#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <string>
#include "Player.h"

class Enemy{
private:
	std::string name;
	int health = 20;
public:
	Enemy() = default;
	Enemy(std::string name, int health) : name{ name }, health{ health } {}
	~Enemy() = default;

	std::string get_name() { return name; }
	void set_name(std::string name) { this->name = name; }

	int get_health() { return health; }
	void set_health(int health) { this->health = health; }

	//void attack(Player& player);

	void take_damage() { health = health - 1; }

};

#endif