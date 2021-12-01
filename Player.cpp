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
	if (player.get_health() > 0 && player.get_health() < max_health && potions > 0) {
		player.set_health(health += 3);
		--potions;
	}
	else if(potions <= 0) {
		std::cout << "You don't have any potions!" << std::endl;
	}
	else{
		std::cout << "You already have full health!" << std::endl;
	}
}

void Player::commands(Player& player, Enemy& enemy) {
	int command{};


	while (!error && !game_over || !error && !game_over && incorrect_command) {
		std::cout << "===============================================" << std::endl;
		switch (command) {
		case 1:
			player.attack(enemy);
			std::cout << player.get_name() << " attacked for 3 hp!" << std::endl;
			break;
		case 2:
			player.heal(player);
			std::cout << "You healed for 3 hp!" << std::endl;
			break;
		default:
			incorrect_command = true;
			std::cout << "Incorrect command, try again" << std::endl;
			break;
		}
		std::cout << player.get_name() << ": " << player.get_health() << std::endl;
		std::cout << enemy.get_name() << ": " << enemy.get_health() << std::endl;
		std::cout << "Choose your command: ";
		std::cin >> command;

		enemy.attack(player);
		std::cout << enemy.get_name() << " attacked for 2 hp!" << std::endl;
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
