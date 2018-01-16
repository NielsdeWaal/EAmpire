#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

#include "tile.hpp"

class Grid {
  private:
    std::vector<Tile> tiles;
	int size_tiles_x;
	int size_tiles_y;
	int scale;

  public:
    Grid();

	Grid(int tiles_x, int tiles_y, int tile_scale);

	void clicked(int x, int y);

	void set_tile(int x, int y, int value);

    void update();
};

#endif // GRID_HPP
