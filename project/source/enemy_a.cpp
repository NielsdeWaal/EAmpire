#include "enemy_a.hpp"

Enemy_a::Enemy_a (sf::Vector2f start_position, sf::Color color, const int damage, const sf::Vector2f speed, int health, const float diameter) :
		Enemy(start_position, color, damage, speed, health),
		diameter(diameter)
	{
		circle.setRadius(diameter);
		circle.setFillColor(color);
	}

void Enemy_a::attack(int & health_player) {
	health_player -= damage;
}

void Enemy_a::take_damage(const int damage_tower) {
	if (health <= 0) {
		delete this;
	}
	health -= damage_tower;
}

void Enemy_a::move_direction(sf::Vector2f direction) {
	position += sf::Vector2f(speed.x * direction.x, speed.y * direction.y);
}

void Enemy_a::draw(sf::RenderWindow & window) {
	circle.setPosition(position);
	window.draw(circle);
}

