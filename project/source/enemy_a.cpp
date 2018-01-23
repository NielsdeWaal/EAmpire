#include "enemy_a.hpp"

Enemy_a::Enemy_a (sf::Vector2f start_position, sf::Color color, const int damage, const sf::Vector2f speed, int lives, const float diameter) :
		Enemy(start_position, color, damage, speed, lives),
		diameter(diameter)
	{
		circle.setRadius(diameter);
		circle.setFillColor(color);
	}

Enemy_a::~Enemy_a() {
	std::cout << "enemy_a is deleted" << std::endl;
}

void Enemy_a::attack(int & health_player) {
	health_player -= damage;
}

void Enemy_a::take_damage(const int damage_tower) {
	if (lives <= 0) {
		std::cout << "death";
	}
	else {
		lives -= damage_tower;
		std::cout << "lives down";
	}
}

void Enemy_a::move_direction(sf::Vector2f direction) {
	position += sf::Vector2f(speed.x * direction.x, speed.y * direction.y);
}

void Enemy_a::draw(sf::RenderWindow & window) {
	circle.setPosition(position);
	window.draw(circle);
}

sf::CircleShape Enemy_a::getCircle() {
	return circle;
}

void Enemy_a::set_fill_color(sf::Color color) {
	circle.setFillColor(color);
}

void Enemy_a::draw_string(sf::RenderWindow & window, sf::Vector2f object) {
	sf::Font font;
	sf::Text text1;
	if (!font.loadFromFile("include/arial.ttf")) {
		std::cout << "not loaded";
	}
	text1.setFont(font);
	text1.setString("RANDOMTEXT");
	text1.setCharacterSize(24);
	//text1.setColor(sf::Color::Red);
	text1.setOrigin(text1.getGlobalBounds().left + text1.getGlobalBounds().width / 2.0f,
		text1.getGlobalBounds().top + text1.getGlobalBounds().height / 2.0f);
	text1.setPosition(object);
	text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
	//std::cout << text.getPosition().x << " : " << text.getPosition().y << std::endl;
	window.draw(text);
}