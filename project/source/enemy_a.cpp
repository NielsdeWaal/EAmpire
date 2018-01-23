#include "enemy_a.hpp"
#include <math.h>

Enemy_a::Enemy_a () :
		Enemy(sf::Vector2f(200,200), sf::Color::Red, 50, 3, 5)
	{}

Enemy_a::~Enemy_a() {
	std::cout << "enemy_a is deleted" << std::endl;
}

void Enemy_a::draw(sf::RenderWindow & window) {
	circle.setPosition(position);
	window.draw(circle);
}





//void Enemy_a::draw_string(sf::Vector2f position) {
//	text.setFillColor(sf::Color::White);
//}