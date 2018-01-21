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
		}
		if (mini_grid[end.y * size_tiles_x + end.x].distance != 0) {
			return true;
		}
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

Grid::Grid(): //Default constructor
	tiles(std::vector<Tile>(10 * 10)),
	size_tiles_x(10),
	size_tiles_y(10),
	scale(50),
	start_x(0),
	start_y(0)
	{
		tile_normal.loadFromFile("textures/tile_normal.png");
		tile_blocked.loadFromFile("textures/tile_blocked.png");
		sprite_tile_normal.setTexture(tile_normal);
		sprite_tile_blocked.setTexture(tile_blocked);
	}

Grid::Grid(int tiles_x, int tiles_y, int scale = 50, int start_x = 0, int start_y = 0):
	tiles(std::vector<Tile>(tiles_x * tiles_y)),
	size_tiles_x(tiles_x),
	size_tiles_y(tiles_y),
	scale(scale),
	start_x(start_x),
	start_y(start_y)
	{
		tile_normal.loadFromFile("textures/tile_normal.png");
		tile_blocked.loadFromFile("textures/tile_blocked.png");
		sprite_tile_normal.setTexture(tile_normal);
		sprite_tile_blocked.setTexture(tile_blocked);
	}

bool Grid::is_clicked(int x, int y) {
	if ((x - start_x) < 0 || (y - start_y) < 0 || (x - start_x) >= (size_tiles_x * scale) || (y - start_y) >= (size_tiles_y * scale)) {
		return 0;
	}
	std::cout << "Clicked on tile (" << ((x - start_x) / scale) << ", " << ((y - start_y) / scale) << ")\n";
	return 1;
}

void Grid::set_navigability(int x, int y) {
	tiles[((y - start_y) / scale) * size_tiles_x + ((x - start_x) / scale)].clicked();
}

std::vector<sf::Vector2i> Grid::find_path(sf::Vector2i start, sf::Vector2i end) {
	auto mini_grid = create_mini_grid();
	if (!fill_mini_grid(mini_grid, start, end)) {
		return (std::vector<sf::Vector2i>(0));
	}
	auto path = path_from_grid(mini_grid, end);
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

void Grid::draw(sf::RenderWindow& window) {
	for (int x = 0; x < size_tiles_x; x++) {
		for (int y = 0; y < size_tiles_y; y++) {
			if (tiles[y * size_tiles_x + x].is_navigable()) {
				sprite_tile_normal.setPosition(sf::Vector2f(start_x + (x * scale), start_y + (y * scale)));
				window.draw(sprite_tile_normal);
			}
			else {
				sprite_tile_blocked.setPosition(sf::Vector2f(start_x + (x * scale), start_y + (y * scale)));
				window.draw(sprite_tile_blocked);
			}
		}
	}
}

void Grid::update() {
	for(auto tile : tiles) {
		//tile.update();
	}
}
