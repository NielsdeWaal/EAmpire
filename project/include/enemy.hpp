#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "gameState.hpp"

/**
* @file enemy.hpp
* @author Dylan van Eck
* @date 18/01/2018
*
* @brief Abstract superclass for creating a enemy
*
* This is a superclass for enemies.
* It contains the variables and functions that come in handy for every enemy.
*/

class Enemy {
  private:
    GameState *game_state = GameState::get_state();
    // The damage that the enemy can do to the lives of the player. And the
    // speed with which the enemy can move
    const int damage;
    // The speed with which the enemy is running. The range is from 0 to 1. (for
    // example: 0.2)
    float speed;
    // The lives of the enemy
    float lives;
    const float original_lives;

	/**
	* @brief Private function to calculate the length of a sf::vector2f in 2D
	*
	* @param[in]	vector				The vector that have to be calculated
	* @return		float				The length of the vector
	*/
	float length(sf::Vector2f distance);

    /**
    * @brief Private function to normalize a sf::vector2f in 2D
    *
    * It uses the length function
    *
    * @param[in]	vector				The vector that have to be
    * calculated
    * @return		sf::Vector2i		The normalized vector
    */
    sf::Vector2f normalize(sf::Vector2f distance_nextlocation);

	/**
	* @brief Private function for checking when ther is a corner within the grid
	*
	* @param[in]	boundarieA			the first boundary
	* @param[in]	boundarieB			the second boundary
	* @param[in]	position			position of the enemy
	*/
	void corner_check(sf::Vector2f & boundaryA, sf::Vector2f & boundaryB, sf::Vector2f & position);

	//The speed with which the enemy can move
	sf::Vector2f position = sf::Vector2f(0.0,0.0);
	//The name of the enemy
	std::string name;
	//The start boundary that have to be located: default first tile(most left at top)
	sf::Vector2f boundaryA = sf::Vector2f(0, 0);
	//The end boundary that have to be located 
	sf::Vector2f boundaryB;
public:

	/**
	* @brief Constructor
	*
	* If this constructor is called, it will make a circle shaped enemy with custom characteristics.
	* That are determines by the parameters. It will also automatic set the radius, color and position.
	*
	* @param[in]	name				The name of the enemy
	* @param[in]	damage				The damage the enemy will do to the players lives.
	* @param[in]	speed				The speed with which the enemy moves.
	* @param[in]	lives				The lives of the enemy.
	*/
	Enemy( std::string name, const int damage, const float speed, float lives);

    /**
    * @brief Destructor
    */
    ~Enemy();

    /**
    * @brief Function that reduces the lives of the player
    *
    * @param[in]	lives_player	The lives of the player who must be
    * reduced
    */
    void attack(int &lives_player);

	/**
	* @brief Virtual Function that reduces the lives of the enemy
	*
	* @param[in]	damage_tower		The damage of the tower who reduced the lives of the enemy
	*/
	virtual void take_damage(float damage_tower);

	/**
	* @brief Function for moving the enemy to a specific location
	*
	* The direction to move your enemy into is simply the difference between the location and the enemy position. 
	* However, you want the enemies to move with constant speed, so we normalize the result.  
	* This will give you the direction as a vector of length 1. multiply this direction by the speed constant of that enemy's type. 
	* The result is a vector with it's length depending on the speed factor instead of the distance to the player.
	*
	* @param[in]	size_grid			The size of the grid that is used when position of enemy is outside the grid
	*/
	void move_direction(const int & size_grid);
	

	/**
	* @brief Function for looking at the next location on the path
	*
	* If first, the function passes through the tile of the path.
	* When a tile matches the boundaryA and the next tile is not the end of the path.
	*
	* if true, boundaryB is referenced to the location of the next tile. 
	* If the position of the enemy is boundaryB, boundaryA becomes boundaryB. 
	* If the next tile is not the last tile. BoundaryB becomes the next location in the path.
	*
	* If the position of the enemy is within the boundaries. the enemy moves in the direction of boundaryB.
	*
	* otherwise boundaryA becomes boundaryB. If the next tile is not the last tile. 
	* BoundaryB becomes the next location in the path. and then the enemy moves in the direction of boundaryB and executes a corner check
	*
	* @param[in]	path				The path for looking at the next pathtile
	*/

	void next_location(std::vector<sf::Vector2i> path);


	/**
	* @brief Function for looking at the next location on the path
	*
	* @param[in]	path				The path for looking at the next pathtile
	*
	* @return		bool				When the end destination is reached, true will be returned.
	*/
    bool check_end_location(std::vector<sf::Vector2i> path);


	/**
	* @brief Function for drawing the enemy
	*
	* @param[out]	window				The screen on which you have to draw
	*/
	void draw(sf::RenderWindow & window, const int & tile_size);


    /**
    * @brief Getter for lives
    *
    * @return       float               Lives of the enemy
    */
    float get_lives();

    /**
    * @brief Setter for lives
    *
    * @param        float               Input float to set lives
    */
	void set_lives(float lives);
    
    /**
    * @brief Getter for location
    *
    * @return       sf::Vector2f        Location of the enemy
    */
    sf::Vector2f get_location();

    /**
    * @brief Setter for the name of the enemy
    *
    * @param[in]    std::string           Name to set the enemy
    */
	void set_name(std::string new_name);

    /**
    * @brief Getter for color
    *
    * @return       std::string           Name of the enemy
    */
	std::string get_name();

    /**
    * @brief Setter for speed
    *
    * @param       float                Speed_input to set the speed of the enemy
    */
	void set_speed(float speed_input);

    /**
    * @brief Getter for damage
    *
    * @return       int                 Damage of the enemy
    */
    int get_damage();
};

#endif // ENEMY_HPP
