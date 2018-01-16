#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

#include "grid.hpp"

class Board {
  private:
    Grid boardGrid = Grid(10, 10);

  public:
    Board() 
    {
        std::cout << "New board created" << std::endl;
    }

    void update();
};

#endif // BOARD_HPP
