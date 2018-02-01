#ifndef TOWER_A_HPP
#define TOWER_A_HPP

#include "gameState.hpp"
#include "tower.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

/**
* @file tower_a.hpp
* @author Nick Goris
* @date 16/1/18
*
* @brief Derived, specific tower class
*/
class tower_a : public Tower {
  private:
    GameState *game_state = GameState::get_state();
    float cost = 100.0;
    float upgrade_cost = 50.0;
    float value;

    float damage = 15.0;
    int radius = 1;

    int current_level = 1;
    int max_level = 5;

    int x_location;
    int y_location;

public:
    /**
    * @brief Tower_a constructor
    *
    * @param[in] x_location Location of the tower in the grid, x coordinate
    * @param[in] y_location Location of the tower in the grid, y coordinate
    */
	tower_a(int x_location, int y_location);

    /**
    * @brief Tower_a destructor
    */
	~tower_a();

	//void upgrade();

    /**
    * @brief Function to return damage of a tower
    *
    * @return a float value containing the damage of the tower
    */
	float get_damage();

    /**
    * @brief Function to return radius of a tower
    *
    * @return an integer containing the radius of the tower
    */
	int get_radius();

    /**
    * @brief Function to return the cost of a tower
    *
    * @return a float containing the cost of a tower
    */
    float get_cost();

    /**
    * @brief Function to return location of a tower
    *
    * @return an sf::Vector2i with the location of the tower on the grid
    */
	sf::Vector2i get_loc();

};

#endif // TOWER_A_HPP
