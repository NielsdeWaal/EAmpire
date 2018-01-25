#include "enemy_container.hpp"

void Enemy_container::add() {
	Enemy *enemy = new Enemy_b();
	enemy_container[count] = enemy;
	count++;;
}

void Enemy_container::remove(int index) {
	delete enemy_container.find(index)->second;
	enemy_container.erase(index);
}

std::map< int, Enemy*> Enemy_container::get_container() {
	return enemy_container;
}