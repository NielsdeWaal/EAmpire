#include "enemy.hpp"

//PRIVATE
float Enemy::length(sf::Vector2f vector2f) {
	return sqrt(vector2f.x * vector2f.x + vector2f.y * vector2f.y);
}

sf::Vector2f Enemy::normalize(sf::Vector2f vector2f) {
	sf::Vector2f vector;
	float length_of_vector = length(vector2f);

	if (length_of_vector != 0) {
		vector.x = vector2f.x / length_of_vector;
		vector.y = vector2f.y / length_of_vector;
	}

	return vector;
}


//PUBLIC
Enemy::Enemy(sf::Vector2f start_position, sf::Color color, const int damage, const int speed, int lives) :
	position(start_position),
	color(color),
	damage(damage),
	speed(speed),
	lives(lives)
{
	circle.setRadius(diameter);
	circle.setFillColor(color);
	circle.setPosition(position);
}

Enemy::~Enemy() {
	std::cout << "Enemy is being deleted" << std::endl;
}

void Enemy::attack(int & health_player) {
	health_player -= damage;
}

void Enemy::take_damage(const int damage_tower) {
	if (lives <= 0) {
		std::cout << "death";
	}
	else {
		lives -= damage_tower;
		std::cout << "lives down";
	}
}

bool Enemy::move_direction(sf::Vector2f direction) {
	sf::Vector2f direction_enemy = normalize(position - direction);
	float ratio = 3.0;
	if (position.x <= direction.x + ratio && position.x >= direction.x - ratio && position.y <= direction.y + ratio && position.y >= direction.y - ratio) {
		//std::cout << "done";
		return true;
	}
	position = position - sf::Vector2f(direction_enemy.x * speed, direction_enemy.y * speed);
	return false;
}

sf::CircleShape Enemy::get_circle() {
	return circle;
}

void Enemy::set_fill_color(sf::Color color) {
	circle.setFillColor(color);
}
