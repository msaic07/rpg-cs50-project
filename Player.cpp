#include "Player.h"
#include "Enemy.h"
#include <iostream>

Player::Player(){
	health = max_health;
	error = false;
	game_over = false;
	incorrect_command = false;
}

void Player::attack(Enemy& enemy){
	if (enemy.get_health() > 0) {
		enemy.take_damage(enemy);
	}
}

void Player::heal(Player& player){
	if (player.get_health() > 0 && player.get_health() < max_health) {
		player.set_health(health += 1);
		error = false;
	}
	else {
		std::cout << "You already have full health!";
		error = true;
	}
}

void Player::commands(Player& player, Enemy& enemy){
	int command{};

	while (!error && !game_over || !error && !game_over && incorrect_command) {
		switch (command) {
		case 1:
			Player::attack(enemy);
			break;
		case 2:
			Player::heal(player);
			break;
		default:
			incorrect_command = true;
			std::cout << "Incorrect command, try again" << std::endl;
			break;
		}
        std::cout "Choose your command: ";
		std::cin >> command;
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
