#ifndef CUTSCENE_HPP
#define CUTSCENE_HPP

#include "image.hpp"
#include <SFML/Graphics.hpp>

/**
* @file cutscene.hpp
* @author Nick Goris, with help from the Teenage Mutant Ninja Unicorns
* @date 31/1/18
*
* @brief Class to play scenes (images from file)
*
* This class can bundle scenes to actually play them as a cutscene
*/
class cutscene {
  private:
    sf::RenderWindow &window;
    image_from_file scene1;
    image_from_file scene2;
    image_from_file scene3;
    image_from_file scene4;
    image_from_file scene5;
    image_from_file scene6;
    image_from_file scene7;
    image_from_file scene8;
    image_from_file scene9;
    image_from_file scene10;
    image_from_file scene11;
    image_from_file scene12;
    image_from_file scene13;
    image_from_file scene14;

  public:
    /**
    * @brief cutscene constructor
    *
    * @param[in] window The window that a cutscene should be displayed on
    */
    cutscene(sf::RenderWindow &window);

    /**
    * @brief This function plays a specific set of scenes
    *
    * This function draws and displays an image, waits for a given amount of
    * time and then clears the screen again, to create the beginning cutscene of
    * our game.
    */
    void play_scene();
};

#endif // CUTSCENE_HPP
