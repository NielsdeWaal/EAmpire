#ifndef ENEMYA_HPP
#define ENEMYA_HPP

#include <SFML/Graphics.hpp>
#include "enemy.hpp"

/**
* @file enemy_a.hpp
* @author Dylan van Eck
* @date 18/01/2018
*
* @brief subclass of Enemy
*
* This is a subclass of Enemy. The Enemy is a circle shape with adaptable diameter and adaptable color.
*/

class Enemy_a : Enemy{
private:
	//The diameteer of the circle
	float diameter;
	//The circle shape of the enemy
	sf::CircleShape circle;
	
	//Is not finished
	//sf::Text text;

public:
	/**
	* @brief Constructor
	*
	* When this constructor is called, it will make a custom circle shaped enemy.
	* It will set the radius and the color for the circle automaticly.
	*
	* @param[in] start_position		The position where the enemy will start.
	* @param[in] color				The default color of the enemy.
	* @param[in] damage				The damage the enemy will do to the players lives.
	* @param[in] speed				The speed with which the enemy moves.
	* @param[in] lives				The lives of the enemy.
	* @param[in] diameter			The diameter for the circle shape.
	*/
	Enemy_a(sf::Vector2f start_position, const sf::Color color, const int damage, const sf::Vector2f speed, int lives, const float diameter);
	
	/**
	* @brief Destructor
	*/
	~Enemy_a();

	/**
	* @brief Function that reduces the lives of the player
	*
	* @param[in, out] The lives of the player who must be reduced
	*/
	void attack(int & health_player) override;

	/**
	* @brief Function that reduces the lives of the enemy
	*
	* Reduces the lives of the enemy with the attack number of the towers.
	* when the lives are at 0, the destructor will be invoked.
	*
	* @param[in] The damage of the tower who reduced the lives of the enemy
	*/
	void take_damage(const int damage_player) override;

	/**
	* @brief Function for moving the enemy in different directions
	*
	* @param[in] The direction where the enemy has to move to. Left,Right,Up,Down = sf::Vector2f(-1,0), sf::Vector2f(1,0), sf::Vector2f(0,-1), sf::Vector2f(0,1)
	*/
	void move_direction(sf::Vector2f direction) override;
	
	/**
	* @brief Function for drawing the enemy
	*
	* @param[out] Window, the screen on which you have to draw
	*/
	void draw(sf::RenderWindow & window) override;
	
	/**
	* @brief Function for coloring the shape of the enemy when hovering over it with your mouse.
	*
	* @param[in] The color that must take the shape of the enemy
	*/
	void set_fill_color(sf::Color color) override;
	
	/**
	* @brief Getter for getting the Circleshape of the enemy.
	*
	* This is useful for other class to get the globalbounds of the circle
	*/
	sf::CircleShape getCircle();

	//is not finished
	void draw_string(sf::RenderWindow & window, sf::Vector2f object) override;

};
#endif // !ENEMYA_HPP

