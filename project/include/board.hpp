#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <algorithm>

#include "action.hpp"
#include "gameState.hpp"
#include "button.hpp"
#include "grid.hpp"
#include "tower.hpp"
#include "tower_a.hpp"

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
	tower_vector towers;

    std::vector<sf::Vector2i> path;

    Button menu_button;
	Button tower1_button;
	Button sell_button;

        action actions[5] = {
            action(sf::Keyboard::Escape, [&] { window.close(); }),
            action(sf::Keyboard::Num1,
                   [&] {
                       if (game_state->get_round_state() != "building") {
                           game_state->set_round_state("building");
                       }
                   }),
            action(sf::Keyboard::Delete,
                   [&] {
                       if (game_state->get_round_state() != "selling") {
                           game_state->set_round_state("selling");
                       }
                   }),
            action(sf::Mouse::Right,
                   [&] {
                       if (game_state->get_round_state() != "free") {
                           game_state->set_round_state("free");
                       }
                   }),
            action(sf::Mouse::Left, [&] {
                int mouse_x = sf::Mouse::getPosition(window).x;
                int mouse_y = sf::Mouse::getPosition(window).y;
                if (menu_button.is_pressed()) {
                    window.close();
                }
                if (tower1_button.is_pressed()) {
                    if (game_state->get_round_state() != "building") {
                        game_state->set_round_state("building");
                    }
                }
                if (sell_button.is_pressed()) {
                    if (game_state->get_round_state() != "selling") {
                        game_state->set_round_state("selling");
                    }
                }
                if ((boardGrid.is_clicked(mouse_x, mouse_y)) &&
                    (game_state->get_round_state() == "building")) {
                    if (boardGrid.is_navigable(
                            (mouse_x - boardGrid.get_start_x()) / 50,
                            (mouse_y - boardGrid.get_start_y()) / 50)) {
                        if (boardGrid.can_place(start, end, sf::Vector2i(
                            (mouse_x - boardGrid.get_start_x()) / 50,
                            (mouse_y - boardGrid.get_start_y()) / 50))) {
                            boardGrid.set_built(mouse_x, mouse_y);
                            towers.push_back(tower_ptr(new tower_a(
                                (mouse_x - boardGrid.get_start_x()) / 50,
                                (mouse_y - boardGrid.get_start_y()) / 50)));
                            game_state->set_round_state("free");
                        }
                        else {
                            //TODO Add some vidual indication that you can't build where the user is clicking.
                        }
                        
                    }
                }
                if (boardGrid.is_clicked(mouse_x, mouse_y) &&
                    (game_state->get_round_state() == "selling")) {
                    boardGrid.set_free(mouse_x, mouse_y);
                    towers.erase(
                        std::remove_if(
                            towers.begin(), towers.end(),
                            [&](tower_ptr tower_pointer) {
                                return (
                                    tower_pointer->get_loc() ==
                                    sf::Vector2i(
                                        (mouse_x - boardGrid.get_start_x()) /
                                            50,
                                        (mouse_y - boardGrid.get_start_y()) /
                                            50));
                            }),
                        towers.end());
                    game_state->set_round_state("free");
                }
            })};

      public:
        explicit Board(sf::RenderWindow &window);

        void clicked(sf::Vector2i position);

        void draw();

        void update();

        void setup();
};

#endif // BOARD_HPP
