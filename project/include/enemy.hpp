#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

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
	const int damage, speed;
	//The lives of the enemy
	int lives;

	/**
	* @brief Private function to calculate the length of a sf::vector2f in 2D
	*
	* @param[in]	vector				The vector that have to be calculated
	* @return		float				The length of the vector
	*/
	float length(sf::Vector2f vector2);

	/**
	* @brief Private function to normalize a sf::vector2f in 2D
	* 
	* It uses the length function
	*
	* @param[in]	vector				The vector that have to be calculated
	* @return		sf::Vector2f		The normalized vector
	*/
	sf::Vector2f normalize(sf::Vector2f vector2f);

protected:
	//The speed with which the enemy can move
	sf::Vector2f position;
	//The color of the enemy's shape
	sf::Color color;

	//NOT FINISHED: because it is a feature
	//The text that represents the lives of the enemy when you hovering over it with your mouse
	//sf::Text text;
public:

	/**
	* @brief Constructor
	*
	* @param[in]	start_position		The position where the enemy will start.
	* @param[in]	color				The default color of the enemy.
	* @param[in]	damage				The damage the enemy will do to the players lives.
	* @param[in]	speed				The speed with which the enemy moves.
	* @param[in]	lives				The lives of the enemy.
	*/
	Enemy(sf::Vector2f start_position, sf::Color color, const int damage, const int speed, int lives):
		position(start_position),
		color(color),
		damage(damage),
		speed(speed),
		lives(lives)
	{}

	/**
	* @brief Destructor
	*/
	~Enemy(void){
		std::cout << "Enemy is being deleted" << std::endl;
	}

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
	* The result is a vector with it's length depending on the speed factor instead of the distance to the player. use the result to move your enemy.
	*
	* @param[in]	location			The location where the enemy has to move to.
	* @return		bool				when the enemy arrives at the location, true is returned. Otherwise it returns false
	*/
	bool move_direction(sf::Vector2f location);
	
	/**
	* @brief Virtual function for drawing the enemy
	*
	* @param[out]	window				The screen on which you have to draw
	*/
	virtual void draw(sf::RenderWindow & window) = 0;

	/**
	* @brief Virtual function for coloring the shape of the enemy when hovering over it with your mouse.
	*
	* @param[in]	color				The color that must take the shape of the enemy
	*/
	virtual void set_fill_color(sf::Color color) = 0;



	//NOT FINISHED: because it is a feature
	/**
	* @brief Function for drawing the info of the enemy when hovering over it with your mouse.
	*
	* @param[out] Window, the screen on which you have to draw.
	* @param[in]  Position of the enemy to center the text of the shape of the object
	*/
	//virtual void draw_string( sf::Vector2f position) = 0;

	//There will be another function for knowing wich way the enemy have to go

};

#endif // ENEMY_HPP
