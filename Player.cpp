#include "Player.h"

void Player::attack(Enemy& enemy){
	if (enemy.get_health() > 0) {
		enemy.take_damage();
	}
}
