#ifndef ENEMYB_HPP
#define ENEMYB_HPP

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

class Enemy_b :public Enemy{
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
	Enemy_b();
	
	/**
	* @brief Destructor
	*/
	~Enemy_b();

	
	/**
	* @brief Function for drawing the enemy
	*
	* @param[out] Window, the screen on which you have to draw
	*/
	void draw(sf::RenderWindow & window) override;

	//is not finished
	//void draw_string(sf::Vector2f position) override;

};
#endif // !ENEMYA_HPP

