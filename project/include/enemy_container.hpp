#ifndef ENEMY_CONTAINER_HPP
#define ENEMY_CONTAINER_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "enemy.hpp"
#include "enemy_a.hpp"
#include "enemy_b.hpp"
/**
* @file enemy_container.hpp
* @author Dylan van Eck
* @date 18/01/2018
*
* Template class with a STL container vector where pointers will be set.
*
*/

class Enemy_container {
private:
	//the vector container for to set pointers to
	std::map< int, Enemy*> enemy_container;
	int count = 0;

public:

	Enemy_container() {};
	/**
	* @brief Function for drawing the enemy
	*
	* @param[in] pointer		object 
	*/
	void add();

	void remove(int index);

	std::map< int, Enemy*> get_container();

};

#endif // ENEMY_CONTAINER_HPP
