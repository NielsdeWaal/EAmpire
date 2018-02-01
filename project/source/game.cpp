#include "game.hpp"

Game::Game(): 
      quit_button(Button(std::string("Quit"), sf::Vector2f(950, 25),
                         sf::Vector2f(100, 50), window)),
      start_button(Button(std::string("Start"), sf::Vector2f(500, 250),
                          sf::Vector2f(100, 50), window)),
      scenes(window)
{
    window.create(sf::VideoMode(1000, 750), "EAmpire Tower Defense",
                  sf::Style::Titlebar | sf::Style::Close);
    std::cout << "Game started" << std::endl;
}

sf::RenderWindow &Game::get_window() {
    return window;
}

void Game::clicked(sf::Vector2i position) {
    for (auto &board : boards) {
        board->clicked(position);
    }
    // boards->clicked(position);
}

void Game::draw() {
    if (game_state->get_game_state() == "start_menu") {
        window.clear();
        game_state->draw_sprite("start_menu", sf::Vector2f(0, 0), window);
        start_button.draw();
        quit_button.draw();
        window.display();
    }
    if (game_state->get_game_state() == "scene") {
        window.clear();
        scenes.play_scene();
        game_state->set_game_state("ingame");
        window.clear();
    }
    if (game_state->get_game_state() == "ingame") {
        for (auto &board : boards) {
            board->draw();
        }
    }
}

void Game::update() {
    if (game_state->get_game_state() == "start_menu") {
        for (auto &action : actions) {
            action();
        }
    } else if (game_state->get_game_state() == "ingame") {
        for (auto &board : boards) {
            board->update();
        }
    }
}

void Game::initialize() {
    // boards.push_back(Board(window));
    // boards = new Board(window);
    boards.emplace_back(new Board(window));
}
