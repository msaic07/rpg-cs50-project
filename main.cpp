#include <iostream>
#include <string>

#include "Player.h"
#include "Enemy.h"

int main() {

	//makes sure all attacks are randomized
	srand(static_cast<unsigned>(time(NULL)));

	//creates player and enemy
	Player player;
	Enemy enemy{ "Giant Goblin",  30 };
	std::string player_name;
	std::cout << "What is your name? ";
	std::getline(std::cin, player_name);
	player.set_name(player_name);

	std::cout << "The village is being attacked by a giant goblin " << player_name << "!" << std::endl;	
	std::cout << "\nSTART FIGHT" << std::endl;

	//starts the game
	player.commands(player, enemy);

	//Waits until users enters to quit out of app
	std::cout << "Press any key and then enter to exit..." << std::endl;
	std::cin >> player_name;

	return 0;
}

