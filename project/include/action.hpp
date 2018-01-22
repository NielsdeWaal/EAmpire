#ifndef ACTION_HPP
#define ACTION_HPP

#include <SFML/Graphics.hpp>
#include <functional>


/**
* @file button.hpp
* @author Nick Goris, Wouter van Ooijen
* @date 21/1/18
*
* @brief Action class to abstract event handling from the main game loop
*
* With this class you can save specific events and their corresponding actions (as lambdas)
*/
class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;

public:
	/**
	* @brief Standard constructor for the action calss
	*
	* @param[in] condition	A function pointer to a bool function
	* @param[in] work		A function pointer to a void function (usually lambda) - this function will be executed when the above function returns true
	**/
	action(std::function< bool() > condition, std::function< void() > work);

	/**
	* @brief Constructor for action class for specifically SFML Keyboard events
	*
	* @param[in] key		An SFML Keyboard key event
	* @param[in] work		A function pointer to a void function (usually lambda) - this function will be executed when the above key is pressed			
	**/
	action(sf::Keyboard::Key key, std::function< void() > work);

	/**
	* @brief Constructor for action class for specifically SFML Mouse events
	*
	* @param[in] key		An SFML Mouse button event
	* @param[in] work		A function pointer to a void function (usually lambda) - this function will be executed when the above button is clicked
	**/
	action(sf::Mouse::Button button, std::function<void()> work);



	/**
	* @brief Overloaded operator() to make it possible to execute functions passed as a parameter in the constructor
	**/
	void operator()();
};

#endif //ACTION_HPP
