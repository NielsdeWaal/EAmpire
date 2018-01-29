#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

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
        action(sf::Keyboard::Escape,    [&] {window.close();}),
        action(sf::Keyboard::Num1,      [&] {game_state->set_round_state("building"); }),
        action(sf::Keyboard::Delete,    [&] {game_state->set_round_state("selling"); }),
        action(sf::Mouse::Right,        [&] {game_state->set_round_state("free"); }),
        action(sf::Mouse::Left,			[&] {
                    if (menu_button.is_pressed()) {
                        window.close();
                    }
					if (tower1_button.is_pressed()) {
						game_state->set_round_state("building");
					}
					if (sell_button.is_pressed()) {
						game_state->set_round_state("selling");
					}
					if ((boardGrid.is_clicked(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) && (game_state->get_round_state() == "building")) {
						boardGrid.set_built(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
						towers.push_back(tower_ptr(new tower_a((sf::Mouse::getPosition(window).x - boardGrid.get_start_x()) / 50, (sf::Mouse::getPosition(window).y - boardGrid.get_start_y()) / 50)));
						game_state->set_round_state("free");
					}
					if (boardGrid.is_clicked(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && (game_state->get_round_state() == "selling")) {
						boardGrid.set_free(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
						int i = 0;
						for (auto& tower : towers) {
							if (tower->get_loc() == sf::Vector2i((sf::Mouse::getPosition(window).x - boardGrid.get_start_x()) / 50, (sf::Mouse::getPosition(window).y - boardGrid.get_start_y()) / 50)) {
								towers.erase(towers.begin()+i);
							}
							i++;
						}
						game_state->set_round_state("free");
					}
		})
	};

public:
    Board(sf::RenderWindow &window);

    void clicked(sf::Vector2i position);

    void draw();

    void update();

    void setup();
};

#endif // BOARD_HPP
