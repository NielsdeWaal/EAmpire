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
* This is a subclass of Enemy.
*/

class Enemy_a :public Enemy{
public:
	/**
	* @brief Constructor
	*
	* When this constructor is called, it will make a custom enemy.
	*/
	Enemy_a();
	
	/**
	* @brief Destructor
	*/
	~Enemy_a();

	
	/**
	* @brief Function for drawing the enemy
	*
	* @param[out] Window, the screen on which you have to draw
	*/
	void draw(sf::RenderWindow & window) override;

};
#endif // !ENEMYA_HPP

