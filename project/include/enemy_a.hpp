#ifndef ENEMYA_HPP
#define ENEMYA_HPP

#include <SFML/Graphics.hpp>
#include "enemy.hpp"

class Enemy_a : Enemy{
private:
	float diameter;
	sf::CircleShape circle;
	sf::Text text;

public:
	Enemy_a(sf::Vector2f start_position, const sf::Color color, const int damage, const sf::Vector2f speed, int health, const float diameter);
	~Enemy_a() {
		std::cout << "enemy_a is deleted" << std::endl;
	}
	void attack(int & health_player) override;
	void take_damage(const int damage_player) override;
	void move_direction(sf::Vector2f direction) override;
	void draw(sf::RenderWindow & window) override;
	void setFillColor(sf::Color color);
	sf::CircleShape getCircle();
	void draw_string(sf::RenderWindow & window, sf::Vector2f object);

};
#endif // !ENEMYA_HPP

