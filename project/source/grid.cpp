#include <iostream>

#include "grid.hpp"

std::vector<Grid::Mini_tile> Grid::create_mini_grid() {
	std::vector<Mini_tile> mini_grid(size_tiles_x * size_tiles_y);
	for (int y = 0; y < size_tiles_y; y++) {
		for (int x = 0; x < size_tiles_x; x++) {
			if (!tiles[y * size_tiles_x + x].is_navigable()) {
				mini_grid[y * size_tiles_x + x].navigable = false;
			}
		}
	}
	return mini_grid;
}

bool Grid::fill_mini_grid(std::vector<Grid::Mini_tile>& mini_grid, sf::Vector2i start, sf::Vector2i end) {
	mini_grid[start.y * size_tiles_x + start.x].distance = 1;
	bool next_available = true;
	int current_distance = 1;
	while (next_available) {
		next_available = false;
		for (int y = 0; y < size_tiles_y; y++) {
			for (int x = 0; x < size_tiles_x; x++) {


				if (!mini_grid[y * size_tiles_x + x].navigable) {          // Debug
					std::cout << "X";                                      //
				}                                                          //
				else {                                                     //
					std::cout << mini_grid[y * size_tiles_x + x].distance; //
				}

				if (mini_grid[y * size_tiles_x + x].distance == current_distance) {
					if ((x + 1) < size_tiles_x && mini_grid[y * size_tiles_x + (x + 1)].navigable && mini_grid[y * size_tiles_x + (x + 1)].distance == 0) {
						mini_grid[y * size_tiles_x + (x + 1)].distance = (current_distance + 1);
						next_available = true;
					}
					if ((x - 1) >= 0 && mini_grid[y * size_tiles_x + (x - 1)].navigable && mini_grid[y * size_tiles_x + (x - 1)].distance == 0) {
						mini_grid[y * size_tiles_x + (x - 1)].distance = (current_distance + 1);
						next_available = true;
					}
					if ((y + 1) < size_tiles_y && mini_grid[(y + 1) * size_tiles_x + x].navigable && mini_grid[(y + 1) * size_tiles_x + x].distance == 0) {
						mini_grid[(y + 1) * size_tiles_x + x].distance = (current_distance + 1);
						next_available = true;
					}
					if ((y - 1) >= 0 && mini_grid[(y - 1) * size_tiles_x + x].navigable && mini_grid[(y - 1) * size_tiles_x + x].distance == 0) {
						mini_grid[(y - 1) * size_tiles_x + x].distance = (current_distance + 1);
						next_available = true;
					}
				}
			}
			std::cout << "\n"; // Debug
		}
		if (mini_grid[end.y * size_tiles_x + end.x].distance != 0) {
			return true;
		}
		std::cout << "\n"; // Debug
		current_distance++;
	}
	std::cout << "No route"; // Debug
	return false;
}

std::vector<sf::Vector2i> Grid::path_from_grid(std::vector<Grid::Mini_tile>& mini_grid, sf::Vector2i end) {
	std::vector<sf::Vector2i> path;
	auto current = end;
	
	while (mini_grid[current.y * size_tiles_x + current.x].distance != 1) {
		path.insert(path.begin(), current);
		if ((current.x + 1) < size_tiles_x && mini_grid[current.y * size_tiles_x + (current.x + 1)].distance == mini_grid[current.y * size_tiles_x + current.x].distance - 1) {
			current.x++;
			continue;
		}
		if ((current.x - 1) >= 0 && mini_grid[current.y * size_tiles_x + (current.x - 1)].distance == mini_grid[current.y * size_tiles_x + current.x].distance - 1) {
			current.x--;
			continue;
		}
		if ((current.y + 1) < size_tiles_y && mini_grid[(current.y + 1) * size_tiles_x + current.x].distance == mini_grid[current.y * size_tiles_x + current.x].distance - 1) {
			current.y++;
			continue;
		}
		if ((current.y - 1) >= 0 && mini_grid[(current.y - 1) * size_tiles_x + current.x].distance == mini_grid[current.y * size_tiles_x + current.x].distance - 1) {
			current.y--;
			continue;
		}
	}
	path.insert(path.begin(), current);
	return path;
}

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

std::vector<sf::Vector2i> Grid::find_path(sf::Vector2i start, sf::Vector2i end) {
	auto mini_grid = create_mini_grid();
	if (!fill_mini_grid(mini_grid, start, end)) {
		return (std::vector<sf::Vector2i>(0));
	}
	auto path = path_from_grid(mini_grid, end);
	for(auto coordinate : path) {
		std::cout << "(" << coordinate.x << ", " << coordinate.y << ")\n";
	}
	return path;
}

bool Grid::can_place(sf::Vector2i start, sf::Vector2i end, sf::Vector2i location) {
	auto mini_grid = create_mini_grid();
	mini_grid[location.y * size_tiles_x + location.x].navigable = false;
	return fill_mini_grid(mini_grid, start, end);
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
