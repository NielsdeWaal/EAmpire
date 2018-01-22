#ifndef ENEMY_CONTAINER_HPP
#define ENEMY_CONTAINER_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

/**
* @file enemy_container.hpp
* @author Dylan van Eck
* @date 18/01/2018
*
* Template class with a STL container vector where pointers will be set.
*
*/

template <typename T>
class Enemy_container {
private:
	//the vector container for to set pointers to
	std::vector<T> screen_objects;

public:
	/**
	* @brief Function for drawing the enemy
	*
	* @param[in] pointer		object 
	*/
	void add(const T & pointer) {
		screen_objects.push_back(pointer);
	}

	void remove(const T & pointer) {
		screen_objects.erase(std::remove(screen_objects.begin(), screen_objects.end(), pointer), screen_objects.end());
		delete pointer;
	}

	std::vector<Enemy*> get_container() {
		return screen_objects;
	}

};

#endif // ENEMY_CONTAINER_HPP
