#include "enemy_b.hpp"
#include <math.h>

Enemy_b::Enemy_b () :
		Enemy(sf::Vector2i(400,400), sf::Color::Blue, 50, 2, 5)
	{}

Enemy_b::~Enemy_b() {
	std::cout << "enemy_a is deleted" << std::endl;
}

void Enemy_b::draw(sf::RenderWindow & window) {
	circle.setPosition(Vector2f_from_Vector2i(position));
	window.draw(circle);
}