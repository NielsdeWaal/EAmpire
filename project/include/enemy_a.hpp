#ifndef ENEMY_A_HPP
#define ENEMY_A_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

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

};
#endif // ENEMY_A_HPP
