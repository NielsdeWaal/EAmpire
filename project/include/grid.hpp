#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <SFML/Graphics.hpp>

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

	bool find_path(sf::Vector2i start, sf::Vector2i end);

	void set_tile(int x, int y, Tile tile);

	void set_tile_navigability(int tile_x, int tile_y, bool navigability);

	bool is_navigable(int tile_x, int tile_y);

    void update();
};

#endif // GRID_HPP
