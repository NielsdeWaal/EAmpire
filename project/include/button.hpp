#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

/**
* @file button.hpp
* @author Nick Goris
* @date 18/1/18
*
* @brief Class to create and handle a multitude of buttons
*
* With this class you can create a button, displaying a certain
* text, on a specific location. It can check whether or not the
* button is pressed.
*/
class Button {
  private:
    std::string s;
    sf::Vector2f location;
    sf::Font font;
    sf::Text text;
    sf::Vector2f size;
    sf::RenderWindow &window;
    sf::RectangleShape boundary;

  public:
    /**
    * @brief Constructor
    *
    * If this constructor is called, it will create a button according
    * to the following parameters
    *
    * @param[in] s		    The text displayed on the button
    * @param[in] location	The top left coordinate of the button
    * @param[in] size		The bottom right coordinate of the button
    * @param[in] window		The window the button is displayed on
    **/
    Button(std::string s, sf::Vector2f location, sf::Vector2f size,
           sf::RenderWindow &window);

    /**
    * @brief Draw the button and it's text
    *
    * This function draws the button on the screen (to the buffer)
    **/
    void draw();

    /**
    * @brief This sets all paramters for the button and it's text
    *
    **/
    void setup();

    /**
    * @brief Returns whether or not the mouse was inside the bounding box of the
    * button
    * when an action specified in the Ganeloop occurs
    *
    * @return bool that describes whether or not the above was true
    **/
    bool is_pressed();

    /**
    * @brief Returns top left coordinate of the button
    *
    * @return sf::Vector2f containing the top left coordinate of the button
    **/
    sf::Vector2f get_location();

    /**
    * @brief Returns bottom right coordinate of the button
    *
    * @return sf::Vector2f containing the bottom right coordinate of the button
    **/
    sf::Vector2f get_size();
};

#endif // BUTTON_HPP
