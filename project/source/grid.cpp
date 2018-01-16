#include "grid.hpp"

void Grid::update() {}

void Grid::initialise(int size_x, int size_y) {
    for (int i = 0; i < (size_x * size_y); ++i) {
        tiles.push_back(Tile());
    }
}
