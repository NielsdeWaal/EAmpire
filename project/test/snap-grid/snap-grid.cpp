#include "grid.hpp"
#include "gtest/gtest.h"

#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>

namespace {

/*TEST(GridTest, defaultConstructor) {
    Grid default_grid;
    Grid fake_default_grid(10, 10, 50, 0, 0);
    EXPECT_EQ(default_grid, fake_default_grid);
}*/

TEST(GridTest, defaultConstructorStartValues) {
    Grid default_grid;
    auto returned_start_values = default_grid.get_start_values();
    std::pair<int, int> default_grid_start(0, 0);
    EXPECT_EQ(default_grid_start, returned_start_values);
}

TEST(GridTest, defaultConstructorSize) {
    Grid default_grid;
    auto returned_grid_size = default_grid.get_grid_size();
    std::pair<int, int> default_grid_size(10, 10);
    EXPECT_EQ(default_grid_size, returned_grid_size);
}

TEST(GridTest, setup) {
    try {
        sf::RenderWindow window(sf::VideoMode(1000, 750), "Testing");
        Grid grid(10, 10, 50, window.getSize().x / 4, 50);

        auto start = sf::Vector2i(0, 0);
        auto end = sf::Vector2i(9, 9);

        auto path = grid.find_path(start, end);
    } catch (...) {
        FAIL() << "Failed to initialize non-default grid";
    }
}

TEST(GridTest, defaultPath) {
    sf::RenderWindow window(sf::VideoMode(1000, 750), "Testing");
    Grid grid(10, 10, 50, window.getSize().x / 4, 50);

    auto start = sf::Vector2i(0, 0);
    auto end = sf::Vector2i(9, 9);

    auto constructed_path = grid.find_path(start, end);

    auto default_path = std::vector<sf::Vector2i>(0);

    EXPECT_EQ(default_path, constructed_path);
}
}
