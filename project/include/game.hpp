#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "board.hpp"
#include "gameState.hpp"

class Game {
  private:
    std::vector<Board> boards;

    GameState *game_state = GameState::get_state();

  public:
    Game() {
        std::cout << "Game started" << std::endl;
        initialize();
    }

    void update();

    void initialize();
};

#endif // GAME_HPP
