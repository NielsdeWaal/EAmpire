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
protected:
	//The damage that the enemy can do to the lives of the player
	int damage;
	//The lives of the enemy
	int lives;
	//The speed with which the enemy can move
	sf::Vector2f speed, position;
	//The color of the enemy's shape
	sf::Color color;
	//The text that represents the lives of the enemy when you hovering over it with your mouse
	sf::Text text;
public:

	/**
	* @brief Constructor
	*
	* @param[in] start_position		The position where the enemy will start.
	* @param[in] color				The default color of the enemy.
	* @param[in] damage				The damage the enemy will do to the players lives.
	* @param[in] speed				The speed with which the enemy moves.
	* @param[in] lives				The lives of the enemy.
	*/
	Enemy(sf::Vector2f start_position, sf::Color color, const int damage, const sf::Vector2f speed, int lives):
		position(start_position),
		color(color),
		damage(damage),
		speed(speed),
		lives(lives)
	{}

	~Enemy(void){
		std::cout << "Enemy is being deleted" << std::endl;
	}

	/**
	* @brief Function that reduces the lives of the player
	*
	* @param[in, out] The lives of the player who must be reduced
	*/
	virtual void attack(int & lives_player) = 0;

	/**
	* @brief Function that reduces the lives of the enemy
	*
	* Reduces the lives of the enemy with the attack number of the towers.
	* when the lives are at 0, the destructor will be invoked.
	*
	* @param[in] The damage of the tower who reduced the lives of the enemy
	*/
	virtual void take_damage(const int damage_tower) = 0;

	/**
	* @brief Function for moving the enemy in different directions
	*
	* @param[in] The direction where the enemy has to move to. Left,Right,Up,Down = sf::Vector2f(-1,0), sf::Vector2f(1,0), sf::Vector2f(0,-1), sf::Vector2f(0,1)
	*/
	virtual void move_direction(sf::Vector2f direction) = 0;
	
	/**
	* @brief Function for drawing the enemy
	*
	* @param[out] Window, the screen on which you have to draw
	*/
	virtual void draw(sf::RenderWindow & window) = 0;

	/**
	* @brief Function for coloring the shape of the enemy when hovering over it with your mouse.
	*
	* @param[in] The color that must take the shape of the enemy
	*/
	virtual void set_fill_color(sf::Color color) = 0;

	/**
	* @brief Function for drawing the info of the enemy when hovering over it with your mouse.
	*
	* @param[out] Window, the screen on which you have to draw.
	* @param[in]  Position of the enemy to center the text of the shape of the object
	*/
	virtual void draw_string(sf::RenderWindow & window, sf::Vector2f object) = 0;

	//There will be another function for knowing wich way the enemy have to go

};

#endif // ENEMY_HPP
