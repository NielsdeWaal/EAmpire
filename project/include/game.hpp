#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "board.hpp"
#include "gameState.hpp"

class Game {
private:
    std::vector<Board*> boards;
    //Board* boards;

    GameState *game_state = GameState::get_state();

    sf::RenderWindow window;

    Button quit_button;
    Button start_button;

    action actions[1] = {
        action(sf::Mouse::Left, [&] {
        if (quit_button.is_pressed()) {
            window.close();
        }
        if (start_button.is_pressed()) {
            game_state->set_game_state("ingame");
            initialize();
        }
    })};

public:
    Game();

    sf::RenderWindow& get_window();

    void clicked(sf::Vector2i position);

    void draw();

    void update();

    void initialize();
};

#endif // GAME_HPP
