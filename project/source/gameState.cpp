#include "gameState.hpp"

GameState *GameState::instance = 0;

GameState *GameState::get_state() {
    if (instance == 0) {
        instance = new GameState();
    }

    return instance;
}

int GameState::get_lives() {
    return lives;
}

void GameState::set_lives(int amount) {
    lives = amount;
}

GameState::GameState() {}
