#include "enemy_b.hpp"
#include <math.h>

Enemy_b::Enemy_b () :
		Enemy(sf::Color::Blue, 50, 2, 5)
	{}

Enemy_b::~Enemy_b() {
	std::cout << "enemy_b is deleted" << std::endl;
}