#include <iostream>
#include <string>
#include "Player.h"
#include "Enemy.h"

int main() {

	Player player;
	Enemy enemy{ "Giant Goblin",  30 };
	std::string player_name;
	std::cout << "What is your name? ";
	std::getline(std::cin, player_name);
	player.set_name(player_name);

	std::cout << "The village is being attacked by a giant goblin " << player_name << "!" << std::endl;	

	player.commands(player, enemy);
	
	//tests
	//std::cout << enemy;
	//player.attack(enemy);
	//std::cout << enemy;

	//std::cout << player;
	//enemy.attack(player);
	//std::cout << player;

	//player.heal(player);
	//std::cout << player;
	//player.heal(player);
	//std::cout << player;

	//enemy.heal(enemy);
	//std::cout << enemy;
	//enemy.heal(enemy);
	//std::cout << enemy;

	return 0;
}

