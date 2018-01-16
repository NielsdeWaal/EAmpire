#include "game.hpp"

void Game::update() {
    for(auto board : boards) {
        board.update();
    }
}

void Game::initialize() {
    boards.push_back(Board());
}
