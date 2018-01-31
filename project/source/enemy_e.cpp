#include "enemy_e.hpp"

Enemy_e::Enemy_e () :
		Enemy( sf::Color::Black, 1, 0.05f, 500)
	{}


Enemy_e::~Enemy_e() {}

void Enemy_e::take_damage(float damage_tower) {
	float lives_a = get_lives();
	lives_a	-= damage_tower;
	set_lives(lives_a);
}