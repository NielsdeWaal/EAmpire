#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

class Enemy {
protected:
	int damage;
	int health;
	sf::Vector2f speed, position;
	sf::Color color;
	sf::Text health;
public:
	Enemy(sf::Vector2f start_position, sf::Color color, const int damage, const sf::Vector2f speed, int health):
		position(start_position),
		color(color),
		damage(damage),
		speed(speed),
		health(health)
	{}

	~Enemy(void){
		std::cout << "Enemy is being deleted" << std::endl;
	}
	virtual void attack(int & health_player) = 0;

	virtual void take_damage(const int damage_player) = 0;

	virtual void move_direction(sf::Vector2f direction) = 0;

	virtual void draw(sf::RenderWindow & window) = 0;

	virtual void setFillColor(sf::Color color) = 0;

	//There will be another function for knowing wich way the enemy have to go

};

#endif // ENEMY_HPP
