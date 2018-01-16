#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <iostream>

#include "tile.hpp"
#include "gameState.hpp"

class Grid {
  private:
    std::vector<Tile> tiles;
    GameState* game_state = GameState::get_state();

  public:
    Grid() {}

    void update();
};

#endif // GRID_HPP
