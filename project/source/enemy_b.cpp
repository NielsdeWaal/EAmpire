#include "enemy_b.hpp"
#include <math.h>

Enemy_b::Enemy_b () :
		Enemy(sf::Vector2i(50,50), sf::Color::Blue, 50, 2, 5)
	{}

Enemy_b::~Enemy_b() {
	std::cout << "enemy_a is deleted" << std::endl;
}