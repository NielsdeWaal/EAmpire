#include <SFML/Graphics.hpp>
#include <chrono>
#include <cstring>
#include <iostream>
#include <thread>

#include "game.hpp"
#include "gameState.hpp"

int main(void) {
    Game game;
    GameState *game_state = GameState::get_state();

    sf::Clock clock;

    std::map<std::string, std::string> sprites{
        {"tile_normal", "textures/tile_normal.png"},
        {"tile_blocked", "textures/tile_blocked.png"},
        {"tile_path", "textures/tile_path.png"},
        {"hammer", "textures/hammer.png"},
        {"sell", "textures/sell.png"},
        {"start_menu", "textures/start_menu.png"},
        {"arno", "textures/TinyArno.png"},
        {"firewall", "textures/firewall.png"},
        {"death_screen", "textures/death.png"}
    };

    game_state->load_sprites(sprites);

    auto &window = game.get_window();

    // auto state = "free";

    while (window.isOpen()) {

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
            default:
                break;
            }
        }
        if (clock.getElapsedTime() >= sf::milliseconds(1000/game_state->get_updates_per_sec())) {
            game.update();
            clock.restart();
        }

        game.draw();
    }
    return 0;
}
