#include "enemy_b.hpp"

Enemy_b::Enemy_b () :
    Enemy(sf::Color::Blue, 2, 0.14f, 100)
    {}

Enemy_b::~Enemy_b() {}

void Enemy_b::take_damage(float damage_tower) {
	float lives_b = get_lives();
	lives_b -= damage_tower;
	if (get_fillcolor() != sf::Color::Red) {
		if (lives_b <= 50) {
			set_fillcolor(sf::Color::Red);
			set_speed(0.1f);
		}
	}
	set_lives(lives_b);
}