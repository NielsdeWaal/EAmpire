#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

/**
* @file image.hpp
* @author Nick Goris, with help from the Teenage Mutant Ninja Unicorns
* @date 31/1/18
*
* @brief Class to handle images loaded from a file (now mostly used for
* cutscenes)
*
* This class can load and draw images loaded from a file.
*/
class image_from_file {
  private:
    sf::Vector2f position;
    sf::Sprite image;
    std::string image_name;
    sf::Texture texture;

  public:
    /**
    * @brief image_from_file constructor
    *
    * @param[in] position The position that a image should be displayed on
    * @param[in] image_name The name of the image file
    */
    image_from_file(sf::Vector2f position, std::string image_name);

    /**
    * @brief function that draws a image_from_file
    *
    * This function sets the position of the image, and draws it using the
    * window.draw() method from SFML
    *
    * @param[in] window A reference to the game window.
    */
    void draw(sf::RenderWindow &window);
};

#endif // IMAGE_HPP
