#ifndef BOARD_HPP
#define BOARD_HPP

#include "grid.hpp"

class Board {
  private:
    Grid boardGrid;

  public:
    Board() {}

    void update();
};

#endif // BOARD_HPP
