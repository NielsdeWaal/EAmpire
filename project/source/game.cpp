#include "game.hpp"

void Game::update() {
    for(auto board : boards) {
        board.update();
    }
}
