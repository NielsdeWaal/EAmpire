#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "gameState.hpp"
#include "button.hpp"
#include "grid.hpp"

class Board {
private:
    GameState *game_state = GameState::get_state();
    int grid_x = 10, grid_y = 10, scale = 50;
    int grid_x_pixel = (grid_x < 10 ? 700 : grid_x * scale + 200);
    int grid_y_pixel = (grid_y < 10 ? 600 : grid_y * scale + 100);
    Grid boardGrid;
    sf::Vector2i start, end;

    sf::RenderWindow &window;

    sf::Font font;
    sf::Text lives;
    sf::Text currency_amount;

    Enemy_container container = Enemy_container();

    std::vector<sf::Vector2i> path;

    Button menu_button;

public:
    Board(sf::RenderWindow &window);

    void clicked(sf::Vector2i position);

    void draw();

    void update();

    void setup();
};

#endif // BOARD_HPP
