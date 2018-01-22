#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

#include "grid.hpp"
#include "gameState.hpp"

class Board {
  private:
    Grid boardGrid;
    GameState *game_state = GameState::get_state();

  public:
    Board() 
    { 
        std::cout << "New board created" << std::endl;
    }

    void update();
};

#endif // BOARD_HPP
