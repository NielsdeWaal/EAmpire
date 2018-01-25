#ifndef ENEMY_CONTAINER_HPP
#define ENEMY_CONTAINER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "enemy.hpp"
#include "enemy_a.hpp"
#include "enemy_b.hpp"

/**
* @file enemy_container.hpp
* @author Dylan van Eck
* @date 24/01/2018
* 
* @brief  Class for organizing a STL container map
* 
* Class with a STL container map where int index will be set at first 
* and pointers of type enemy will be set at second. 
* With the methods needed to remove and add pointers
*
*/
class Enemy_container {
private:

	//The STD container where everything will be saved
	std::map< int, Enemy*> enemy_container;
	
	//The number to indentify a Enemy pointer
	int count = 0;

public:
	/**
	* @brief Default constructor
	*
	* If this constructor is called, it will make the map with the count at zero.
	*/
	Enemy_container() {};

	/**
	* @brief Function for adding a Enemy to the container
	* 
	* It is for now a default Enemy_a what will be added to the container.
	*/
	void add();

	/**
	* @brief Function for deleting a Enemy from the container by index
	*
	* The pointer will be erased from the std::map, thereafter the Enemy will be destructed.
	*
	* @parameter	index			To locate which enemy pointer has to be removed
	*/
	void remove(int index);

	/**
	* @brief Function to return the map by using a for auto loop
	*
	* @return	std::map< int, Enemy*>	The enemy_container
	*/
	std::map< int, Enemy*> get_container();


    std::vector<Enemy *> get_container() {
        return screen_objects;
    }
};
#endif // ENEMY_CONTAINER_HPP