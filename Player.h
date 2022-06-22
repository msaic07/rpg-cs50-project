#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Enemy;
class Player{
	friend std::ostream& operator<<(std::ostream& os, const Player& p);
private:
	std::string name;
	int health;
	int max_health = 40;
	int potions = 2;
	int damage{};
	bool isPlayersTurn;
	bool game_over;
public:
	Player();
	Player(std::string name, int health) : name{ name }, health{ health } {}
	~Player() = default;

	std::string get_name() const{ return name; }
	void set_name(std::string name) { this->name = name; }

	int get_health() const{ return health; }
	void set_health(int health) { this->health = health; }

	//Player commands
	void attack(Enemy& enemy);
	void heal(Player& player);
	void commands(Player& player, Enemy& enemy);

	void take_damage(Player& player);

};

#endif