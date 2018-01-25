#include "enemy_a.hpp"

Enemy_a::Enemy_a () :
		Enemy(sf::Vector2i(50,50), sf::Color::Red, 50, 1, 5)
	{}


Enemy_a::~Enemy_a() {
    std::cout << "enemy_a is deleted" << std::endl;
}


void Enemy_a::draw(sf::RenderWindow & window) {
	circle.setPosition(Vector2f_from_Vector2i(position));
	window.draw(circle);
}
