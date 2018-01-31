#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>

/**
 * @file gameState.hpp
 * @author Niels de Waal
 * @date 16/1/18
 *
 * @brief Global class for keeping track of the game
 *
 * This is a singleton class that can keep track of a mutlitude of variables.
 * These variables include things like lives and the amount of currency held.
 */
class GameState {
  private:
    static GameState *instance;

    GameState();

    // TODO Is a hardcoded value, needs to be scalable to difficulty level.
    int lives = 100; ///< Current amount of lives.

    int curreny_amount = 0;

    bool new_round = true;

    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Sprite> sprites;

    std::string round_state;
    std::string game_state = "start_menu";

  public:
    /**
     * @brief function which returns a pointer to the GameState class.
     *
     * This function makes sure that there is only one instance of GameState.
     * This way this class can easily be used all over the code without having
     * to
     * wory about multiple instances.
     *
     * @return Pointer to GameState
     */
    static GameState *get_state();

    /**
     * @brief function that returns the current amount of lives.
     *
     * @return amount of lives left.
     */
    int get_lives();
    /**
     * @brief function which is able to change the current amount of lives.
     *
     * @param[in] the amount that lives needs to be set to.
     */
    void set_lives(int amount);
    /**
    * @brief function that returns the current amount of curreny.
    *
    * @return amount of curreny.
    */
    int get_curreny();
    /**
    * @brief function which is able to change the current amount of curreny.
    *
    * @param[in] the amount that curreny_amount needs to be set to.
    */
    void set_curreny(int amount);
    /**
    * @brief function that loads sprites from a map.
    *
    * This function loads the sprites from a map with filenames
    * and converts them to sprites for easy use.
    *
    * @param[in] files The map with files. First value should be the name, the
    * second the path.
    */
    void load_sprites(std::map<std::string, std::string> files);
    /**
    * @brief function that can draw a sprite.
    *
    * @param[in] name Name of the sprite to be drawn.
    * @param[in] position Position to draw the sprite at.
    * @param[in] window Window to draw the sprite on.
    */
    void draw_sprite(std::string name, sf::Vector2f position,
                     sf::RenderWindow &window);

    void set_new_round(bool result);

    bool get_round_status();

    void set_round_state(std::string state);

    std::string get_round_state();

    void set_game_state(std::string state);

    std::string get_game_state();
};

#endif // GAME_STATE_HPP
