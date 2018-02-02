#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "board.hpp"
#include "cutscene.hpp"
#include "gameState.hpp"

class Game {
  private:
    std::vector<Board *> boards;
    // Board* boards;

    GameState *game_state = GameState::get_state();

    sf::RenderWindow window;

    Button quit_button;
    Button start_button;
    cutscene scenes;

    action actions[2] = {action(sf::Keyboard::Escape, [&] { window.close(); }),
                         action(sf::Mouse::Left, [&] {
                             if (quit_button.is_pressed()) {
                                 window.close();
                             }
                             if (start_button.is_pressed()) {
                                 game_state->set_game_state("scene");
                                 initialize();
                             }
                         })};

  public:
    /**
    * @brief Constructor for the game.
    */
    Game();

    /**
    * @brief Get the reference to the window the game uses.
    *
    * @return Reference to the window the game uses.
    */
    sf::RenderWindow &get_window();

    /**
    * @brief Handles a click on the game.
    *
    * @param[in] position Position that has been clicked.
    */
    void clicked(sf::Vector2i position);

    /**
    * @brief Draws the game.
    */
    void draw();

    /**
    * @brief Updates the game.
    */
    void update();

    /**
    * @brief Initializes the game.
    */
    void initialize();
};

#endif // GAME_HPP
