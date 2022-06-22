#include "Player.h"
#include "Enemy.h"

#include <iostream>
#include <time.h>

Player::Player(){
	health = max_health;
	isPlayersTurn = true;
	game_over = false;
}

void Player::attack(Enemy& enemy){
	//uses function from enemy class to damage enemy
	if (enemy.get_health() > 0) {
		enemy.take_damage(enemy);
	}
}

void Player::heal(Player& player){
	//Sees if potions are 0 and if player has full health, otherwise heal
	if (player.get_health() > 0 && player.get_health() < max_health && potions > 0) {
		player.set_health(health += 6);
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
	bool enemyUsedPotion = false;
	bool usedMegaPotion = false;

	//game loop
	do{
		//displays this for every turn
		std::cout << "===============================================" << std::endl;
		std::cout << player.get_name() << ": " << player.get_health() << std::endl;
		std::cout << enemy.get_name() << ": " << enemy.get_health() << std::endl;
		std::cout << "Potions: " << potions << "\n\n";
		std::cout << "Choose your command:\nAttack: 1\nHeal: 2\nMega Potion: 3 (You only get one!)\n";
		std::cin >> command;
		std::cout << std::endl;

		//command options
		if (command == 1) {

			player.attack(enemy);
			isPlayersTurn = false;

			//Since damage is randomized, there will be different outputs for the amount of damage the player does
			if (Enemy::damage >= 2 && Enemy::damage <= 4) {
				std::cout << player.get_name() << " attacked for " << Enemy::damage << " hp!" << std::endl;
			}
			else if (Enemy::damage == 5) {
				std::cout << "Critical hit! " << player.get_name() << " attacked for 5 hp!" << std::endl;
			}
			else if (Enemy::damage == 1) {
				std::cout << "Weak hit! " << player.get_name() << " attacked for 1 hp!" << std::endl;
			}
			else {
				std::cout << player.get_name() << " missed!" << std::endl;
			}

		}
		//heals player
		else if (command == 2) {

			player.heal(player);

		}
		//Checks players health and if the mega potion was already used, otherwise heal player for 10 hp
		else if (command == 3 && !usedMegaPotion && health < (max_health - 10)) {

			player.set_health(health += 10);
			std::cout << player.get_name() << " used a mega potion and got 10 hp!" << std::endl;
			usedMegaPotion = true;
			isPlayersTurn = false;

		}
		else if (command == 3 && !usedMegaPotion && health >= (max_health - 10)) {

			player.set_health(max_health);
			std::cout << player.get_name() << " used a mega potion and got back to full health!" << std::endl;
			usedMegaPotion = true;
			isPlayersTurn = false;

		}
		else if (command == 3 && usedMegaPotion && health <= max_health) {

			std::cout << "Sorry, you already used your mega potion!" << std::endl;
			isPlayersTurn = true;

		}
		else if (command == 3 && health >= max_health) {

			std::cout << "You already have full health!" << std::endl;
			isPlayersTurn = true;

		}
		//Outputs this if any other command was used
		else {

			std::cout << "Please enter a valid command!" << std::endl;
			isPlayersTurn = true;

		}

		//Enemy's attack
		if (!isPlayersTurn) {
			//checks if enemy's health is less than 5 and if the heal wasn't already used, if so heal enemy for 15 hp
			if (enemy.get_health() < 5 && enemy.get_health() > 0 && !enemyUsedPotion) {
				enemy.heal(enemy);
				enemyUsedPotion = true;
				std::cout << enemy.get_name() << " healed for 15 hp!" << std::endl;
			}
			//attack player
			else {
				enemy.attack(player);
				//damage is also randomized for enemy so different there are different outputs
				if (damage <= 4 && damage >= 2) {
					std::cout << enemy.get_name() << " attacked for " << damage <<  " hp!" << std::endl;
				}
				else if (damage == 5) {
					std::cout << "Critical hit! " << enemy.get_name() << " attacked for 6 hp!" << std::endl;
				}
				else{
					std::cout << "Weak hit! " << enemy.get_name() << " attacked for 1 hp!" << std::endl;
				}
			}

		}

		//displays this if player wins
		if (enemy.get_health() <= 0 && health > 0) {
			game_over = true;
			std::cout << "  _     _      ___     __ __              __     __    __     ____     __    __  " << std::endl;
			std::cout << " | |   | |    /   \\   | | | |            | \\    / |   |  |   |     \\  |  |  |  |     " << std::endl;
			std::cout << " | |   | |   | __  |  | | | |            |  \\/\\/  |   |  |   |  |\\  \\ |  |  |  |     " << std::endl;
			std::cout << "  \\ \\ / /    |     |  | |_| |            |        |   |  |   |  | \\  \\|  |  |__|                 " << std::endl;
			std::cout << "   |  |      \\    /   |     |            |   /\\   |   |  |   |  |  \\     |   __             " << std::endl;
			std::cout << "   |__|       \\__/     \\___/             |__/  \\__|   |__|   |__|   \\____|  |__|                  " << std::endl;
		}

		//displays this if player loses
		if (health <= 0) {
			game_over = true;
			std::cout << std::endl;
			std::cout << "You lost!" << std::endl;
		}

	} while (!game_over);
}

void Player::take_damage(Player& player){
	if (player.get_health() > 0) {

		//the amount of damage the player takes is randomized between 1 - 4, inclusive
		damage = rand() % 4 + 1;
		player.set_health(health = health - damage);
	}
}

//debugging
std::ostream& operator<<(std::ostream& os, const Player& p){
	os << p.get_name() << "'s health: " << p.get_health() << std::endl;
	return os;
}
