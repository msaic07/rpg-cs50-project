#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

class Enemy;
class Player{
	friend std::ostream& operator<<(std::ostream& os, const Player& p);
private:
	std::string name;
	int health = 20;
	bool is_attacked;
public:
	Player() = default;
	Player(std::string name, int health) : name{ name }, health{ health } {}
	~Player() = default;

	std::string get_name() const{ return name; }
	void set_name(std::string name) { this->name = name; }

	int get_health() const{ return health; }
	void set_health(int health) { this->health = health; }

	//Player commands
	void attack(Enemy& enemy);
	void heal(Player& player);
	void defend(Player& player);

	void take_damage(Player& player);

};

#endif