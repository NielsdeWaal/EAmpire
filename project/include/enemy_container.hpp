#ifndef ENEMY_CONTAINER_HPP
#define ENEMY_CONTAINER_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "enemy.hpp"

/**
* @file enemy_container.hpp
* @author Dylan van Eck
* @date 18/01/2018
*
*
*/
template <typename T>
class Enemy_container {
private:
	std::vector<T> screen_objects;

public:

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
