#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

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

	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Sprite> sprites;

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

	void load_sprites(std::map<std::string, std::string> files);

	void draw_sprite(std::string name, sf::Vector2f position, sf::RenderWindow &window);
};

#endif // GAME_STATE_HPP
