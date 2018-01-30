#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

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
	//The damage that the enemy can do to the lives of the player. And the speed with which the enemy can move
	const int damage;
	//The speed with which the enemy is running. The range is from 0 to 1. (for example: 0.2)
	const float speed;
	//The lives of the enemy
	float lives;

	/**
	* @brief Private function to calculate the length of a sf::vector2f in 2D
	*
	* @param[in]	vector				The vector that have to be calculated
	* @return		float				The length of the vector
	*/
	float length(sf::Vector2f vector2f);

	/**
	* @brief Private function to normalize a sf::vector2f in 2D
	* 
	* It uses the length function
	*
	* @param[in]	vector				The vector that have to be calculated
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
	void corner_check(sf::Vector2f & boundarieA, sf::Vector2f & boundarieB, sf::Vector2f & position);

protected:
	//The speed with which the enemy can move
	sf::Vector2f position = sf::Vector2f(0.0,0.0);
	//The color of the enemy's shape
	sf::Color color;
	//The diameteer of the circle
	float diameter = 24;
	//The circle shape of the enemy
	sf::CircleShape circle;
	//The start boundary that have to be located: default first tile(most left at top)
	sf::Vector2f boundaryA = sf::Vector2f(0, 0);
	//The end boundary that have to be locatred 
	sf::Vector2f boundaryB;
public:

	/**
	* @brief Constructor
	*
	* If this constructor is called, it will make a circle shaped enemy with custom characteristics.
	* That are determines by the parameters. It will also automatic set the radius, color and position.
	*
	* @param[in]	color				The default color of the enemy.
	* @param[in]	damage				The damage the enemy will do to the players lives.
	* @param[in]	speed				The speed with which the enemy moves.
	* @param[in]	lives				The lives of the enemy.
	*/
	Enemy( sf::Color color, const float damage, const float speed, int lives);

	/**
	* @brief Destructor
	*/
	~Enemy();

	/**
	* @brief Function that reduces the lives of the player
	*
	* @param[in]	lives_player		The lives of the player who must be reduced
	*/
	void attack(int & lives_player);

	/**
	* @brief Function that reduces the lives of the enemy
	*
	* Reduces the lives of the enemy with the attack number of the towers.
	* when the lives are at 0, the destructor will be invoked.
	*
	* @param[in]	damage_tower		The damage of the tower who reduced the lives of the enemy
	*/
	void take_damage(const int damage_tower);

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
	* @brief Function for transforming a vector2f to 2i.
	*
	* @param[in]	rhs					The vector2i what have to be transformed
	*/
	sf::Vector2f Vector2f_from_Vector2i(sf::Vector2i rhs);

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
	* untrue, true will be returned
	*
	* @param[in]	path				The path for looking at the next pathtile
	*
	* @return		bool				When the end destination is reached, true will be returned.
	*/

	bool next_location(std::vector<sf::Vector2i> path);


	/**
	* @brief Virtual function for drawing the enemy
	*
	* @param[out]	window				The screen on which you have to draw
	*/
	void draw(sf::RenderWindow & window, const int & tile_size);
};

#endif // ENEMY_HPP
