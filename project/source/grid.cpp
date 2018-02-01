#include "grid.hpp"

//void Grid::initialise(int size_x, int size_y) {
//    for (int i = 0; i < (size_x * size_y); ++i) {
//        tiles.push_back(Tile());
//    }
//}

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

bool Grid::fill_mini_grid(std::vector<Grid::Mini_tile> &mini_grid,
                          sf::Vector2i start, sf::Vector2i end) {
    mini_grid[start.y * size_tiles_x + start.x].distance = 1;
    bool next_available = true;
    int current_distance = 1;
    while (next_available) {
        next_available = false;
        for (int y = 0; y < size_tiles_y; y++) {
            for (int x = 0; x < size_tiles_x; x++) {
                if (mini_grid[y * size_tiles_x + x].distance ==
                    current_distance) {
                    if ((x + 1) < size_tiles_x &&
                        mini_grid[y * size_tiles_x + (x + 1)].navigable &&
                        mini_grid[y * size_tiles_x + (x + 1)].distance == 0) {
                        mini_grid[y * size_tiles_x + (x + 1)].distance =
                            (current_distance + 1);
                        next_available = true;
                    }
                    if ((x - 1) >= 0 &&
                        mini_grid[y * size_tiles_x + (x - 1)].navigable &&
                        mini_grid[y * size_tiles_x + (x - 1)].distance == 0) {
                        mini_grid[y * size_tiles_x + (x - 1)].distance =
                            (current_distance + 1);
                        next_available = true;
                    }
                    if ((y + 1) < size_tiles_y &&
                        mini_grid[(y + 1) * size_tiles_x + x].navigable &&
                        mini_grid[(y + 1) * size_tiles_x + x].distance == 0) {
                        mini_grid[(y + 1) * size_tiles_x + x].distance =
                            (current_distance + 1);
                        next_available = true;
                    }
                    if ((y - 1) >= 0 &&
                        mini_grid[(y - 1) * size_tiles_x + x].navigable &&
                        mini_grid[(y - 1) * size_tiles_x + x].distance == 0) {
                        mini_grid[(y - 1) * size_tiles_x + x].distance =
                            (current_distance + 1);
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
    return false;
}

std::vector<sf::Vector2i> Grid::path_from_grid(std::vector<Grid::Mini_tile> &mini_grid,
                                               sf::Vector2i end) {
    std::vector<sf::Vector2i> path;
    auto current = end;

    while (mini_grid[current.y * size_tiles_x + current.x].distance != 1) {
        path.insert(path.begin(), current);
        if ((current.x + 1) < size_tiles_x &&
            mini_grid[current.y * size_tiles_x + (current.x + 1)].distance ==
                mini_grid[current.y * size_tiles_x + current.x].distance - 1) {
            current.x++;
            continue;
        }
        if ((current.x - 1) >= 0 &&
            mini_grid[current.y * size_tiles_x + (current.x - 1)].distance ==
                mini_grid[current.y * size_tiles_x + current.x].distance - 1) {
            current.x--;
            continue;
        }
        if ((current.y + 1) < size_tiles_y &&
            mini_grid[(current.y + 1) * size_tiles_x + current.x].distance ==
                mini_grid[current.y * size_tiles_x + current.x].distance - 1) {
            current.y++;
            continue;
        }
        if ((current.y - 1) >= 0 &&
            mini_grid[(current.y - 1) * size_tiles_x + current.x].distance ==
                mini_grid[current.y * size_tiles_x + current.x].distance - 1) {
            current.y--;
            continue;
        }
    }
    path.insert(path.begin(), current);
    return path;
}

Grid::Grid(): // Default constructor
    tiles(std::vector<Tile>(10 * 10)),
    size_tiles_x(10), size_tiles_y(10), 
    scale(50), 
    start_x(0), 
    start_y(0),
    highlight(sf::RectangleShape(sf::Vector2f(scale, scale)))
    {
        highlight.setFillColor(sf::Color(0, 0, 0, 100));
    }

Grid::Grid(int tiles_x, int tiles_y, int scale = 50, int start_x = 0,
           int start_y = 0): 
    tiles(std::vector<Tile>(tiles_x * tiles_y)), 
    size_tiles_x(tiles_x),
    size_tiles_y(tiles_y), 
    scale(scale), 
    start_x(start_x), 
    start_y(start_y),
    highlight(sf::RectangleShape(sf::Vector2f(scale, scale)))
    {
        highlight.setFillColor(sf::Color(0, 0, 0, 100));
    }

bool Grid::is_clicked(int x, int y) {
    if ((x - start_x) < 0 || (y - start_y) < 0 ||
        (x - start_x) >= (size_tiles_x * scale) ||
        (y - start_y) >= (size_tiles_y * scale)) {
        return 0;
    }
    // std::cout << "Clicked on tile (" << ((x - start_x) / scale) << ", " <<
    // ((y - start_y) / scale) << ")\n";
    return 1;
}

int Grid::get_size_x() {
    return size_tiles_x;
}

int Grid::get_size_y() {
    return size_tiles_y;
}

int Grid::get_start_x() {
    return start_x;
}

int Grid::get_start_y() {
    return start_y;
}

std::vector<sf::Vector2i> Grid::find_path(sf::Vector2i start,
                                          sf::Vector2i end) {
    auto mini_grid = create_mini_grid();
    if (!fill_mini_grid(mini_grid, start, end)) {
        return (std::vector<sf::Vector2i>(0));
    }
    auto path = path_from_grid(mini_grid, end);
    return path;
}

bool Grid::can_place(sf::Vector2i start, sf::Vector2i end,
                     sf::Vector2i location) {
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

void Grid::draw(sf::RenderWindow &window) {
    for (int x = 0; x < size_tiles_x; x++) {
        for (int y = 0; y < size_tiles_y; y++) {
            game_state->draw_sprite(tiles[y * size_tiles_x + x].get_sprite(), 
                sf::Vector2f(static_cast<float>(start_x + (x * scale)),
                static_cast<float>(start_y + (y * scale))), 
                window);
        }
    }
}

void Grid::draw_path(sf::RenderWindow &window, std::vector<sf::Vector2i> path) {
    for (auto tile : path) {
        game_state->draw_sprite("tile_path", 
                                sf::Vector2f(static_cast<float>(start_x + (tile.x * scale)),
                                             static_cast<float>(start_y + (tile.y * scale))), 
                                window);
    }
}

void Grid::draw_selected(sf::RenderWindow &window, sf::Vector2i mouse_location) {
    highlight.setPosition(sf::Vector2f((((mouse_location.x-start_x)/50)*50+start_x), (((mouse_location.y-start_y)/50)*50 + start_y)));
    window.draw(highlight);
}

//void Grid::update(sf::RenderWindow& window, std::vector<sf::Vector2i> path) {
//	for(auto tile : path) {
//
//	}
//}

void Grid::create_maze() {
    for (int x = 0; x < size_tiles_x; x++) {
        for (int y = 0; y < size_tiles_y; y++) {
            if (x % 2 == 0 || y % 2 == 0) {
                tiles[y * size_tiles_x + x].set_navigability(false);
            }
        }
    }
    std::vector<sf::Vector2i> visited;
    std::vector<sf::Vector2i> walls;
    visited.insert(visited.begin(), sf::Vector2i(1, 1));
    walls.insert(walls.begin(), sf::Vector2i(1, 2));
    walls.insert(walls.begin(), sf::Vector2i(2, 1));
    while (!walls.empty()) {
        unsigned seed =
            static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
        std::shuffle(walls.begin(), walls.end(),
                     std::default_random_engine(seed));
        auto current_wall = walls[0];
        walls.erase(walls.begin());
        if (current_wall.x % 2 == 0) { // Wall horizontal between tiles.
            if (!(std::find(visited.begin(), visited.end(),
                            sf::Vector2i(current_wall.x - 1, current_wall.y)) !=
                      visited.end() && // Both tiles allready visited.
                  std::find(visited.begin(), visited.end(),
                            sf::Vector2i(current_wall.x + 1, current_wall.y)) !=
                      visited.end())) {
                tiles[current_wall.y * size_tiles_x + current_wall.x]
                    .set_navigability(true);
                if (std::find(
                        visited.begin(), visited.end(),
                        sf::Vector2i(current_wall.x - 1, current_wall.y)) !=
                    visited.end()) { // Left tile visited, adding walls around
                                     // right tile.
                    visited.insert(
                        visited.begin(),
                        sf::Vector2i(current_wall.x + 1, current_wall.y));
                    if (current_wall.y > 3) { // 1 right, 1 up.
                        walls.insert(walls.begin(),
                                     sf::Vector2i(current_wall.x + 1,
                                                  current_wall.y - 1));
                    }
                    if (current_wall.x < size_tiles_x - 3) { // 2 right.
                        walls.insert(
                            walls.begin(),
                            sf::Vector2i(current_wall.x + 2, current_wall.y));
                    }
                    if (current_wall.y < size_tiles_y - 3) { // 1 right, 1 down.
                        walls.insert(walls.begin(),
                                     sf::Vector2i(current_wall.x + 1,
                                                  current_wall.y + 1));
                    }
                } else { // Right tile visited, adding walls around left tile.
                    visited.insert(
                        visited.begin(),
                        sf::Vector2i(current_wall.x - 1, current_wall.y));
                    if (current_wall.y > 3) { // 1 left, 1 up.
                        walls.insert(walls.begin(),
                                     sf::Vector2i(current_wall.x - 1,
                                                  current_wall.y - 1));
                    }
                    if (current_wall.x > 3) { // 2 left.
                        walls.insert(
                            walls.begin(),
                            sf::Vector2i(current_wall.x - 2, current_wall.y));
                    }
                    if (current_wall.y < size_tiles_y - 3) { // 1 left, 1 down.
                        walls.insert(walls.begin(),
                                     sf::Vector2i(current_wall.x - 1,
                                                  current_wall.y + 1));
                    }
                }
            }
        } else { // Tile vertical between tiles.
            if (!(std::find(visited.begin(), visited.end(),
                            sf::Vector2i(current_wall.x, current_wall.y - 1)) !=
                            visited.end() && // Both tiles allready visited.
                  std::find(visited.begin(), visited.end(),
                            sf::Vector2i(current_wall.x, current_wall.y + 1)) !=
                            visited.end())) {
                tiles[current_wall.y * size_tiles_x + current_wall.x]
                    .set_navigability(true);
                if (std::find(
                        visited.begin(), visited.end(),
                        sf::Vector2i(current_wall.x, current_wall.y - 1)) !=
                    visited.end()) { // Tile above visited, adding walls around
                                     // tile below.
                    visited.insert(
                        visited.begin(),
                        sf::Vector2i(current_wall.x, current_wall.y + 1));
                    if (current_wall.x > 3) { // 1 down, 1 left.
                        walls.insert(walls.begin(),
                                     sf::Vector2i(current_wall.x - 1,
                                                  current_wall.y + 1));
                    }
                    if (current_wall.y < size_tiles_y - 3) { // 2 down.
                        walls.insert(
                            walls.begin(),
                            sf::Vector2i(current_wall.x, current_wall.y + 2));
                    }
                    if (current_wall.x < size_tiles_y - 3) { // 1 down, 1 right.
                        walls.insert(walls.begin(),
                                     sf::Vector2i(current_wall.x + 1,
                                                  current_wall.y + 1));
                    }
                } else { // Tile below visited, adding walls around tile above.
                    visited.insert(
                        visited.begin(),
                        sf::Vector2i(current_wall.x, current_wall.y - 1));
                    if (current_wall.x > 3) { // 1 up, 1 left.
                        walls.insert(walls.begin(),
                                     sf::Vector2i(current_wall.x - 1,
                                                  current_wall.y - 1));
                    }
                    if (current_wall.y > 3) { // 2 up.
                        walls.insert(
                            walls.begin(),
                            sf::Vector2i(current_wall.x, current_wall.y - 2));
                    }
                    if (current_wall.y < size_tiles_y - 3) { // 1 up, 1 right.
                        walls.insert(walls.begin(),
                                     sf::Vector2i(current_wall.x + 1,
                                                  current_wall.y - 1));
                    }
                }
            }
        }
        /*for (auto wall : walls) {
                std::cout << "(" << wall.x << ", " << wall.y << ")\n";
        }
        std::cout << "\n";*/
    }
}

std::pair<int, int> Grid::get_grid_size() {
    return std::make_pair(size_tiles_x, size_tiles_y);
}

std::pair<int, int> Grid::get_start_values() {
	return std::make_pair(start_x, start_y);
}


void Grid::reset_damage() {
	for (auto& tile : tiles) {
		tile.set_damage(0);
	}
}

float Grid::get_damage(int tile_x, int tile_y) {
    return tiles[tile_y * size_tiles_x + tile_x].get_damage();
}

std::string Grid::get_sprite(int tile_x, int tile_y) {
    return tiles[tile_y * size_tiles_x + tile_x].get_sprite();
}

void Grid::set_sprite(int tile_x, int tile_y, std::string new_sprite) {
    return tiles[tile_y * size_tiles_x + tile_x].set_sprite(new_sprite);
}
