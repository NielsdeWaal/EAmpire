#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

#include "tile.hpp"

class Grid {
  private:
    std::vector<Tile> tiles;

  public:
    Grid() {}

    void update();
};

#endif // GRID_HPP
