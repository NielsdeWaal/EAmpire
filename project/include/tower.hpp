#ifndef TOWER_HPP
#define TOWER_HPP

#include "gameState.hpp"
#include <SFML/Graphics.hpp>


/**
* @file tower.hpp
* @author Nick Goris
* @date 16/1/18
*
* @brief Super class to derive towers from
*/
class Tower
{
private:
	float cost;
	float upgrade_cost;
	float value;

    float damage;
    int radius;

    int current_level;
    int max_level;

    int x_location;
    int y_location;
    GameState *game_state = GameState::get_state();

public:
    /**
    * @brief Tower constructor
    *
    * @param[in] x_location Location of the tower in the grid, x coordinate
    * @param[in] y_location Location of the tower in the grid, y coordinate
    */
	Tower(int x_location, int y_location);

    /**
    * @brief Empty tower constructor
    */
	Tower();

    /**
    * @brief Virtual tower destructor
    */
	virtual ~Tower();

	//void upgrade();

    /**
    * @brief Virtual function to return damage of a tower
    */
	virtual float get_damage();

    /**
    * @brief Virtual function to return radius of a tower
    *
    * @return an integer containing the radius of the tower
    */
	virtual int get_radius();

    /**
    * @brief Virtual function to return location of a tower
    *
    * @return an sf::Vector2i with the location of the tower on the grid
    */
	virtual sf::Vector2i get_loc();

    /**
    * @brief Virtual function to return the cost of a tower
    *
    * @return a float containing the cost of a tower
    */
    virtual float get_cost();
};

#endif // TOWER_HPP
