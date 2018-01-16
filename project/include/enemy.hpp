#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>

class Enemy {
	int damage;
	sf::Vector2f speed;
	int health;
	sf::Vector2f position;
	sf::Color color;
	//std::string shape;
	sf::RectangleShape shape;
public:
	Enemy(sf::Vector2f position, sf::Color color, const int damage, const sf::Vector2f speed, int health):
		position(position),
		shape(shape),
		color(color),
		damage(damage),
		speed(speed),
		health(health)
	{
		/*const struct { const char * name; } shapes[]{
			{ "circle"		, sf::CircleShape },
			{ "rectangle"	, sf::RectangleShape }
		};*/

		shape.setPosition(position);
		shape.setFillColor(color);
	}

	virtual void attack(int & health_player) {
		health_player -= damage;
	}

	virtual void take_damage(const int damage_player) {
		health -= damage_player;
	}
	
	virtual sf::Vector2f move_forward() {
		position += speed;
		return position;
	}

	virtual sf::Vector2f move_direction(sf::Vector2f direction) {
		sf::Vector2f buffer_position = move_forward();
		position = sf::Vector2f(buffer_position.x * direction.x, buffer_position.y * direction.y);
		return position;
	}

	virtual void draw(sf::RenderWindow & window) {
		shape.setPosition(position);
		window.draw(shape);
	}
};

#endif // ENEMY_HPP
