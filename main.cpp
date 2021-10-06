#include <iostream>
#include <string>
#include "Player.h"
#include "Enemy.h"

int main() {

	Player player;
	Enemy enemy;
	std::string player_name;
	std::cout << "What is your name? ";
	std::getline(std::cin, player_name);
	player.set_name(player_name);

	std::cout << "The village is being attacked " << player_name << "!" << std::endl;

	//tests
	std::cout << enemy.get_health() << std::endl;
	player.attack(enemy);
	std::cout << enemy.get_health() << std::endl;

	/*std::cout << player_name << "'s" << " health: " << player.get_health() << std::endl;
	enemy.attack(player);
	std::cout << player_name << "'s" << " health: " << player.get_health() << std::endl;*/

	return 0;
}