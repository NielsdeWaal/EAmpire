#ifndef ENEMY_A_HPP
#define ENEMY_A_HPP

#include <SFML/Graphics.hpp>
#include <math.h>

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

class Enemy_a :public Enemy{ //#1
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


    /**
    * @brief Getter for getting the Circleshape of the enemy.
    *
    * This is useful for other class to get the globalbounds of the circle
    */
    sf::CircleShape get_circle();

    // is not finished
    // void draw_string(sf::Vector2f position) override;
};
#endif // ENEMY_A_HPP
