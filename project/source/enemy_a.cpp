#include "enemy_a.hpp"
#include <math.h>

Enemy_a::Enemy_a (sf::Vector2f start_position, sf::Color color, const int damage, const int speed, int lives, const float diameter) :
		Enemy(start_position, color, damage, speed, lives),
		diameter(diameter)
	{
		circle.setRadius(diameter);
		circle.setFillColor(color);
	}

Enemy_a::~Enemy_a() {
	std::cout << "enemy_a is deleted" << std::endl;
}

void Enemy_a::draw(sf::RenderWindow & window) {
	circle.setPosition(position);
	window.draw(circle);
}

sf::CircleShape Enemy_a::get_circle() {
	return circle;
}

void Enemy_a::set_fill_color(sf::Color color) {
	circle.setFillColor(color);
}



//void Enemy_a::draw_string(sf::Vector2f position) {
//	text.setFillColor(sf::Color::White);
//}