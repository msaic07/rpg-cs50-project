#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <string>

class Player;
class Enemy{
	friend std::ostream& operator<<(std::ostream& os, const Enemy& e);
private:
	std::string name;
	int health = 20;
	bool usedPotion = false;
public:
	Enemy() = default;
	Enemy(std::string name, int health) : name{ name }, health{ health } {}
	~Enemy() = default;

	std::string get_name() const{ return name; }
	void set_name(std::string name) { this->name = name; }

	int get_health() const{ return health; }
	void set_health(int health) { this->health = health; }

	//Enemy commands
	void attack(Player& player);
	void heal(Enemy& enemy);

	void take_damage(Enemy& enemy);

	static int damage;

};

#endif