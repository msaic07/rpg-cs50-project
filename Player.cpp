#include "Player.h"
#include "Enemy.h"
#include <iostream>

void Player::attack(Enemy& enemy){
	if (enemy.get_health() > 0) {
		enemy.take_damage(enemy);
		is_attacked = true;
	}
	else {
		is_attacked = false;
	}
}

void Player::heal(Player& player){
	if (player.get_health() > 0) {
		player.set_health(health += 1);
	}
}

void Player::defend(Player& player){
	if (is_attacked == true) {
		player.set_health(health -= 1);
	}
}

void Player::take_damage(Player& player){
	if (player.get_health() > 0) {
		player.set_health(health = health - 2);
	}
}

std::ostream& operator<<(std::ostream& os, const Player& p){
	os << p.get_name() << "'s health: " << p.get_health() << std::endl;
	return os;
}
