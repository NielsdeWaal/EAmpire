#include "enemy_c.hpp"

Enemy_c::Enemy_c () :
    Enemy(sf::Color::Yellow, 2, 0.18f, 150)
    {}

Enemy_c::~Enemy_c() {}

void Enemy_c::take_damage(float damage_tower) {
	float lives_b = get_lives();
	lives_b -= damage_tower;
	if (get_fillcolor() != sf::Color::Blue) {
		if (lives_b <= 100) {
			set_fillcolor(sf::Color::Blue);
			set_speed(0.14f);
		}
	}
	if (get_fillcolor() != sf::Color::Red) {
		if (lives_b <= 50) {
			set_fillcolor(sf::Color::Red);
			set_speed(0.1f);
		}
	}
	set_lives(lives_b);
}