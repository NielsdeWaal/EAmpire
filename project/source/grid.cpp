#include <iostream>
#include <queue>
#include <set>

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
	if (x < 0 || y < 0 || x >= (size_tiles_x * scale) || y >= (size_tiles_y * scale)) {
		return;
	}
	std::cout << "Clicked on tile (" << (x / scale) << ", " << (y / scale) << ")\n";
	//tiles[(y / scale) * size_tiles_x + (x / scale)].clicked;
}

bool Grid::find_path(sf::Vector2i start, sf::Vector2i end) {
	struct Mini_tile {
		int distance = 0;
		bool navigable = true;
	};

	std::vector<Mini_tile> temp(size_tiles_x * size_tiles_y);
	for (int y = 0; y < size_tiles_y; y++) {
		for (int x = 0; x < size_tiles_x; x++) {
			if (!tiles[y * size_tiles_x + x].is_navigable()) {
				temp[y * size_tiles_x + x].navigable = false;
			}
			if (!temp[y * size_tiles_x + x].navigable) {
				std::cout << "X";
			}
			else {
				std::cout << temp[y * size_tiles_x + x].distance;
			}
		}
		std::cout << "\n";
	}
	temp[start.y * size_tiles_x + start.x].distance = 1;
	bool next_available = true;
	int current_distance = 1;
	while (next_available) {
		next_available = false;
		for (int y = 0; y < size_tiles_y; y++) {
			for (int x = 0; x < size_tiles_x; x++) {
				

				if (!temp[y * size_tiles_x + x].navigable) {
					std::cout << "X";
				}
				else {
					std::cout << temp[y * size_tiles_x + x].distance;
				}

				if (temp[y * size_tiles_x + x].distance == current_distance) {
					if ((x + 1) < size_tiles_x && temp[y * size_tiles_x + (x + 1)].navigable && temp[y * size_tiles_x + (x + 1)].distance == 0) {
						temp[y * size_tiles_x + (x + 1)].distance = (current_distance + 1);
						next_available = true;
					}
					if ((x - 1) >= 0 && temp[y * size_tiles_x + (x - 1)].navigable && temp[y * size_tiles_x + (x - 1)].distance == 0) {
						temp[y * size_tiles_x + (x - 1)].distance = (current_distance + 1);
						next_available = true;
					}
					if ((y + 1) < size_tiles_y && temp[(y + 1) * size_tiles_x + x].navigable && temp[(y + 1) * size_tiles_x + x].distance == 0) {
						temp[(y + 1) * size_tiles_x + x].distance = (current_distance + 1);
						next_available = true;
					}
					if ((y - 1) >= 0 && temp[(y - 1) * size_tiles_x + x].navigable && temp[(y - 1) * size_tiles_x + x].distance == 0) {
						temp[(y - 1) * size_tiles_x + x].distance = (current_distance + 1);
						next_available = true;
					}
				}
				if (temp[y * size_tiles_x + x].distance != 0 && x == end.x && y == end.y) {
					std::cout << "Found";
					next_available = false;
					break;
				}
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		current_distance++;
	}
	std::cout << current_distance;

	return false;
}

void Grid::set_tile(int tile_x, int tile_y, Tile tile) {
	tiles[tile_y * size_tiles_x + tile_x] = tile;
}

void Grid::set_tile_navigability(int tile_x, int tile_y, bool navigability) {
	tiles[tile_y * size_tiles_x + tile_x].set_navigability(navigability);
}

bool Grid::is_navigable(int tile_x, int tile_y) {
	return tiles[tile_y * size_tiles_x + tile_x].is_navigable();
}

void Grid::update() {
	for(auto tile : tiles) {
		//tile.update();
	}
}
