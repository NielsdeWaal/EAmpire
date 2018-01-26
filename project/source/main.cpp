#include <SFML/Graphics.hpp>
#include <chrono>
#include <cstring>
#include <iostream>
#include <thread>

#include "action.hpp"
#include "enemy.hpp"
#include "enemy_a.hpp"
#include "enemy_container.hpp"
#include "button.hpp"
#include "game.hpp"
#include "grid.hpp"

int main(void) {
    Game game;
	GameState *game_state = GameState::get_state();

	std::map<std::string, std::string> sprites {
		{"tile_normal", "textures/tile_normal.png"},
		{"tile_blocked", "textures/tile_blocked.png"},
		{"tile_path", "textures/tile_path.png"},
		{"hammer", "textures/hammer.png"},
		{"sell", "textures/sell.png"}
	};

	game_state->load_sprites(sprites);
 
    auto& window = game.get_window();

    /*
    // Button play_button(play, sf::Vector2f{ float((window.getSize().x / 2)),
    // float((window.getSize().y / 2)) }, sf::Vector2f{ 70,50 }, window);
    Button tower1_button(tower1, sf::Vector2f(grid_x_pixel - 50, 125),
                         sf::Vector2f(100, 50), window);
    Button tower2_button(tower2, sf::Vector2f(grid_x_pixel - 50, 200),
                           sf::Vector2f(100, 50), window);
    Button tower3_button(tower3, sf::Vector2f(grid_x_pixel - 50, 275),
                         sf::Vector2f(100, 50), window);
    Button tower4_button(tower4, sf::Vector2f(grid_x_pixel - 50, 350),
                         sf::Vector2f(100, 50), window);
    Button tower5_button(tower5, sf::Vector2f(grid_x_pixel - 50, 425),
                         sf::Vector2f(100, 50), window);
    Button sell_button(sell, sf::Vector2f(grid_x_pixel - 50, 525),
                       sf::Vector2f(100, 50), window);*/
                       

    action actions[] = {
        action(sf::Keyboard::Escape, [&window] { window.close(); }),
        action(sf::Mouse::Left, [&window, &game] { game.clicked(sf::Mouse::getPosition(window)); })
    };
        //action(sf::Keyboard::Num1, [&state] { state = "building"; }),
        //action(sf::Keyboard::Num2,		[&container] {container.add(); }),
        //action(sf::Keyboard::Delete, [&state] { state = "selling"; }),
        //action(sf::Mouse::Right, [&state] { state = "free"; }),
        /*action(sf::Mouse::Left, [&state, &window, &menu_button, &tower1_button,
                                 &sell_button, &grid] {
            if (menu_button.is_pressed()) {
                window.close();
            }
            if (tower1_button.is_pressed()) {
                state = "building";
            }
            if (sell_button.is_pressed()) {
                state = "selling";
            }
            if (grid.is_clicked(sf::Mouse::getPosition(window).x,
                                sf::Mouse::getPosition(window).y) &&
                (!std::strcmp(state, "building"))) {

                grid.set_built(sf::Mouse::getPosition(window).x,
                               sf::Mouse::getPosition(window).y);
                state = "free";
            }
            if (grid.is_clicked(sf::Mouse::getPosition(window).x,
                                sf::Mouse::getPosition(window).y) &&

                (!std::strcmp(state, "selling"))) {

                grid.set_free(sf::Mouse::getPosition(window).x,
                              sf::Mouse::getPosition(window).y);
                state = "free";
            }

        })*/

	window.setFramerateLimit(25);
    while (window.isOpen()) {

        for (auto &action : actions) {
            action();
        }

        sf::Event evnt;
        while (window.pollEvent(evnt)) {

            switch (evnt.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::LostFocus:
                std::cout << "MOUSE HAS LEFT THE BUILDING" << std::endl;
                // pause game
                break;

            case sf::Event::GainedFocus:
                std::cout << "MOUSE HAS ENTERED THE BUILDING" << std::endl;
                // continue game
                break;
            }
        }

        game.update();
        game.draw();
    }
    return 0;
}
