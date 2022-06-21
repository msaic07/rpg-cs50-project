#include "Player.h"
#include "Enemy.h"
#include <iostream>

Player::Player(){
	health = max_health;
	isPlayersTurn = true;
	game_over = false;
}

void Player::attack(Enemy& enemy){
	if (enemy.get_health() > 0) {
		enemy.take_damage(enemy);
	}
}

void Player::heal(Player& player){
	if (player.get_health() > 0 && player.get_health() < max_health && potions > 0) {
		player.set_health(health += 5);
		std::cout << "You healed for 3 hp!" << std::endl;
		isPlayersTurn = false;
		--potions;
	}
	else if(potions <= 0) {
		std::cout << "You don't have any potions!" << std::endl;
		isPlayersTurn = true;
	}
	else{
		std::cout << "You already have full health!" << std::endl;
		isPlayersTurn = true;
	}
}

void Player::commands(Player& player, Enemy& enemy) {
	int command{};

	do{
		std::cout << "===============================================" << std::endl;
		std::cout << player.get_name() << ": " << player.get_health() << std::endl;
		std::cout << enemy.get_name() << ": " << enemy.get_health() << std::endl;
		std::cout << "Choose your command:\nAttack: 1\nHeal: 2\n";
		std::cin >> command;
		if (command == 1) {
			player.attack(enemy);
			isPlayersTurn = false;
			std::cout << player.get_name() << " attacked for 2 hp!" << std::endl;
		}
		else if (command == 2) {
			player.heal(player);
		}
		else {
			std::cout << "Please enter a valid command!" << std::endl;
		}

		if (!isPlayersTurn) {
			enemy.attack(player);
			std::cout << enemy.get_name() << " attacked for 3 hp!" << std::endl;
		}
	} while (!game_over);
}

void Player::take_damage(Player& player){
	if (player.get_health() > 0) {
		player.set_health(health = health - 4);
	}
}

std::ostream& operator<<(std::ostream& os, const Player& p){
	os << p.get_name() << "'s health: " << p.get_health() << std::endl;
	return os;
}
