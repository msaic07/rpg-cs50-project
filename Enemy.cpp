#include "Enemy.h"
#include "Player.h"

#include <iostream>
#include <time.h>

//the static variable
int Enemy::damage = 0;

void Enemy::attack(Player& player) {
	if (player.get_health() > 0) {
		player.take_damage(player);
	}
}

//enemy heals for 15 hp
void Enemy::heal(Enemy& enemy) {
	if (enemy.get_health() > 0) {
		enemy.set_health(health += 15);
	}
}

void Enemy::take_damage(Enemy& enemy) {
	if (enemy.get_health() > 0) {
		
		//damages the enemy for numbers between 0 - 6, inclusive
		damage = rand() % 6;
		enemy.set_health(health = health - damage);
	}
}

//debugging
std::ostream& operator<<(std::ostream& os, const Enemy& e){
	os << e.get_name() << "'s health: " << e.get_health() << std::endl;
	return os;
}
