#include "game.hpp"

Game::Game()
{
    window.create(sf::VideoMode(1000, 1000), "EAmpire Tower Defense", sf::Style::Titlebar | sf::Style::Close);
    std::cout << "Game started" << std::endl;
    initialize();
}

sf::RenderWindow& Game::get_window() {
    return window;
}

void Game::clicked(sf::Vector2i position) {
    for (auto& board : boards) {
        board->clicked(position);
    }
    //boards->clicked(position);
}

void Game::draw() {
    for (auto& board : boards) {
        board->draw();
    }
    //boards->draw();
}

void Game::update() {
    for (auto& board : boards) {
        board->update();
    }
    //boards->update();
}

void Game::initialize() {
    //boards.push_back(Board(window));
    //boards = new Board(window);
    boards.emplace_back(new Board(window));
}
