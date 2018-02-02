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
    image_from_file angry_arni;
    image_from_file boss_fight1;
    image_from_file boss_fight2;
    image_from_file end_game1;
    image_from_file end_game2;
    image_from_file helpscreen;

  public:
    /**
    * @brief cutscene constructor
    *
    * @param[in] window The window that a cutscene should be displayed on
    */
    cutscene(sf::RenderWindow &window);

    /**
    * @brief This function plays a specific set of scenes, the opening sequence
    *
    * This function draws and displays an image, waits for a given amount of
    * time and then clears the screen again, to create the beginning cutscene of
    * our game.
    */
    void play_scene();

    /**
    * @brief This function plays a specific set of scenes, the Angry Arno scene
    *
    * This function draws and displays an image, waits for a given amount of
    * time and then clears the screen again, to create the beginning cutscene of
    * our game.
    */
    void angry_arno();

    /**
    * @brief This function plays a specific set of scenes, the boss fight sequence
    *
    * This function draws and displays an image, waits for a given amount of
    * time and then clears the screen again, to create the beginning cutscene of
    * our game.
    */
    void boss_fight();

    /**
    * @brief This function plays a specific set of scenes, the end game sequence
    *
    * This function draws and displays an image, waits for a given amount of
    * time and then clears the screen again, to create the beginning cutscene of
    * our game.
    */
    void end_game();
    
    /**
    * @brief This function plays a specific set of scenes, the help screen
    *
    * This function draws and displays an image, aand waits for user input to continue
    */
    void help_screen();
};

#endif // CUTSCENE_HPP
