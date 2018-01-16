#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <iostream>

#include "tile.hpp"

class Grid {
  private:
    std::vector<Tile> tiles;

    int size_x;
    int size_y;

  public:
    Grid(int size_x, int size_y) : 
        size_x(size_x), 
        size_y(size_y) 
    {
        initialise(size_x, size_y);
        std::cout << "Grid initialised" << std::endl;
    }

    void update();

    void initialise(int x, int y);
};

#endif // GRID_HPP
