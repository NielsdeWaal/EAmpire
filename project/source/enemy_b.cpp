#include "enemy_b.hpp"
#include <math.h>

Enemy_b::Enemy_b () :
		Enemy(sf::Vector2f(400,400), sf::Color::Blue, 50, 2, 5)
	{}

Enemy_b::~Enemy_b() {
	std::cout << "enemy_a is deleted" << std::endl;
}

void Enemy_b::draw(sf::RenderWindow & window) {
	circle.setPosition(position);
	window.draw(circle);
}





//void Enemy_a::draw_string(sf::Vector2f position) {
//	text.setFillColor(sf::Color::White);
//}