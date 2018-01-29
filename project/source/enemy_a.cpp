#include "enemy_a.hpp"

Enemy_a::Enemy_a () :
		Enemy( sf::Color::Yellow, 50, 1.0, 5)
	{}


Enemy_a::~Enemy_a() {
    std::cout << "enemy_a is deleted" << std::endl;
}
