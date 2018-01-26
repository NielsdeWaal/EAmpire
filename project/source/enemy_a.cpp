#include "enemy_a.hpp"

Enemy_a::Enemy_a () :
		Enemy(sf::Vector2i(50,50), sf::Color::Yellow, 50, 1, 5)
	{}


Enemy_a::~Enemy_a() {
    std::cout << "enemy_a is deleted" << std::endl;
}
