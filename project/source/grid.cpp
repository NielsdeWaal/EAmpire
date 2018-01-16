#include "grid.hpp"

Grid::Grid() { //Default constructor
	tiles = std::vector<Tile>(10 * 10);
	size_tiles_x = 10;
	size_tiles_y = 10;
	scale = 50;
}

Grid::Grid(int tiles_x, int tiles_y, int tile_scale = 50) {
	tiles = std::vector<Tile>(tiles_x * tiles_y);
	size_tiles_x = tiles_x;
	size_tiles_y = tiles_y;
	scale = tile_scale;
}

void Grid::clicked(int x, int y) {
	if (x < 0 || y < 0 || x > (size_tiles_x * scale) || y > (size_tiles_y * scale)) {
		return;
	}
	//tiles[(y / scale) * size_tiles_x + (x / scale)].clicked;
}

void Grid::set_tile(int tile_x, int tile_y, int value) {
	//tiles[tile_y * size_tiles_x + tile_x].set(value);
}

void Grid::update() {
	for(auto tile : tiles) {
		//tile.update();
	}
}
