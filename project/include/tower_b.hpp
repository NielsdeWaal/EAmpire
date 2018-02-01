#ifndef TOWER_B_HPP
#define TOWER_B_HPP

#include "gameState.hpp"
#include "tower.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class tower_b : public Tower {
  private:
    GameState *game_state = GameState::get_state();
    float cost = 10.0;
    float upgrade_cost = 50.0;
    float value;

    float damage = 0.0;
    int radius = 1;

    int current_level = 1;
    int max_level = 1;

    int x_location;
    int y_location;

public:
    /**
    * @brief Tower_b constructor
    *
    * @param[in] x_location Location of the tower in the grid, x coordinate
    * @param[in] y_location Location of the tower in the grid, y coordinate
    */
	tower_b(int x_location, int y_location);

    /**
    * @brief Tower_b destructor
    */
	~tower_b();

	//void upgrade();

    /**
    * @brief Function to return damage of a tower
    *
    * @return get_damage a float value containing the damage of the tower
    */
	float get_damage();

    /**
    * @brief Function to return radius of a tower
    *
    * @return an integer containing the radius of the tower
    */
	int get_radius();

    /**
    * @brief Function to return location of a tower
    *
    * @return an sf::Vector2i with the location of the tower on the grid
    */
	sf::Vector2i get_loc();

    /**
    * @brief Function to return the cost of a tower
    *
    * @return a float containing the cost of a tower
    */
    float get_cost();

};

#endif // TOWER_B_HPP
