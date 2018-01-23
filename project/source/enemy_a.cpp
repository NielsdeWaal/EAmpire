#include "enemy_a.hpp"
#include <math.h>

Enemy_a::Enemy_a () :
		Enemy(sf::Vector2i(200,200), sf::Color::Red, 50, 3, 5)
	{}

Enemy_a::~Enemy_a() {
	std::cout << "enemy_a is deleted" << std::endl;
}

void Enemy_a::draw(sf::RenderWindow & window) {
	circle.setPosition(Vector2f_from_Vector2i(position));
	window.draw(circle);
}





//void Enemy_a::draw_string(sf::Vector2f position) {
//	text.setFillColor(sf::Color::White);
//}