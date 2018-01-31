#include "enemy_a.hpp"

Enemy_a::Enemy_a () :
		Enemy( sf::Color::Red, 1, 0.1f, 50)
	{}


Enemy_a::~Enemy_a() {}

void Enemy_a::take_damage(float damage_tower) {
	float lives_a = get_lives();
	lives_a	-= damage_tower;
	set_lives(lives_a);
}