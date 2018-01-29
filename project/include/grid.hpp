#ifndef GRID_HPP
#define GRID_HPP

#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

#include "gameState.hpp"
#include "enemy.hpp"
#include "enemy_a.hpp"
#include "enemy_b.hpp"
#include "enemy_container.hpp"
#include "enemy_generator.hpp"
#include "tile.hpp"
#include "gameState.hpp"
#include "typedefs.hpp"

/**
* @file grid.hpp
* @author Jasper Smienk
* @date 18/1/18
*
* @brief Class to handle all kind of things related to the grid as a whole.
*
* With this class you can manage the tiles in each grid.
* there are also different functions related to path-finding.
*/
class Grid {
  private:
    std::vector<Tile> tiles;

    int size_tiles_x;
    int size_tiles_y;
    int scale;
    int start_x;
    int start_y;
	std::vector<std::pair<int, std::shared_ptr<Enemy>>> enemies;
	GameState *game_state = GameState::get_state();

    /**
    * @brief Struct to help with path-finding.
    *
    * This struct is used in path-finding to make it simpler/more efficient.
    * This way, all the relevant information that is needed is easily available.
    **/
    struct Mini_tile {
        int distance = 0;
        bool navigable = true;
    };

    /**
    * @brief Function that creates a simpler version of the grid.
    *
    * @return Vector of Mini_tiles the same size of the 'real' grid.
    **/
    std::vector<Mini_tile> create_mini_grid();

    /**
    * @brief Fill a mini grid in with the correct distance.
    *
    * This function fills a mini grid in with the distance from itself to the
    *start.
    * If it can't find a path to a tile, it stays at 0.
    * If it found a path to the end tile, it stops.
    *
    * @param[in] mini_grid The grid to fill in.
    * @param[in] start     The start coordinate to begin from.
    * @param[in] end       The end coordinate.
    *
    * @return Boolean whether it has found a path from the start to the end.
    **/
    bool fill_mini_grid(std::vector<Mini_tile> &mini_grid, sf::Vector2i start,
                        sf::Vector2i end);

    /**
    * @brief Makes the path.
    *
    * This function creates a path from the start till the end,
    * and saves the sf::Vector2i of each location in a std::Vector.
    *
    * @param[in] mini_grid The grid to make a path in.
    * @param[in] end       The end point (Start isn't needed because that is the
    *only 1)
    *
    * @return std::vector with all locations of the path.
    **/
    std::vector<sf::Vector2i> path_from_grid(std::vector<Mini_tile> &mini_grid,
                                             sf::Vector2i end);

  public:
    /**
    * @brief Default constructor.
    *
    * If this constructor is called, it will make a standard grid of 10 by 10.
    **/
    Grid();

    /**
    * @brief Constructor.
    *
    * If this constructor is called, it will make a custom grid.
    *
    * @param[in] tiles_x The amount of tiles on the x axis.
    * @param[in] tiles_y The amount of tiles on the y axis.
    * @param[in] scale   Used to know how big the grid is in pixels.
    * @param[in] start_x The x coordinate of the upper left origin.
    * @param[in] start_y The y coordinate of the upper left origin.
    **/
    Grid(int tiles_x, int tiles_y, int scale, int start_x, int start_y);

    /**
    * @brief Checks whether a click has occured in the grid
    *
    * @param[in] x The relative x coordinate in the grid.
    * @param[in] y The relative y coordinate in the grid.
    **/
    bool is_clicked(int x, int y);

    /**
    * @brief Returns the amount of tiles on the x axis.
    *
    * @return Amount of tiles on the x axis.
    **/
    int get_size_x();

    /**
    * @brief Returns the amount of tiles on the y axis.
    *
    * @return Amount of tiles on the y axis.
    **/
    int get_size_y();

    /**
    * @brief Returns the x coordinate of the start position.
    *
    * @return X coordinate of the start position.
    **/
    int get_start_x();

    /**
    * @brief Returns the y coordinate of the start position.
    *
    * @return Y coordinate of the start position.
    **/
    int get_start_y();

    /**
    * @brief Changes the specific tile that has been clicked to non-navigatable
    *
    * The right tile is calculated by deviding the coordinate by the scale.
    * It then communicates to the correct tile that it has been clicked on.
    *
    * @param[in] x The relative x coordinate in the grid.
    * @param[in] y The relative y coordinate in the grid.
    **/
    void set_built(int x, int y);

    /**
    * @brief Changes the specific tile that has been clicked to navigatable
    *
    * The right tile is calculated by deviding the coordinate by the scale.
    * It then communicates to the correct tile that it has been clicked on.
    *
    * @param[in] x The relative x coordinate in the grid.
    * @param[in] y The relative y coordinate in the grid.
    **/
    void set_free(int x, int y);

    /**
    * @brief Finds a path in the grid.
    *
    * This function calculates the fastest path from one point in the grid to
    *another.
    *
    * @param[in] start Where to start from.
    * @param[in] end   Where to go to.
    *
    * @return std::vector with all locations of the path.
    **/
    std::vector<sf::Vector2i> find_path(sf::Vector2i start, sf::Vector2i end);

    /**
    * @brief See if there is a path available if you block a tile.
    *
    * This function blocks the tile at the given location,
    * and then tries to find a path from the start to the end.
    *
    * @param[in] start    Where to start from.
    * @param[in] end      Where to go to.
    * @param[in] location Which tile to block.
    *
    * @return Whether there still is a path available.
    **/
    bool can_place(sf::Vector2i start, sf::Vector2i end, sf::Vector2i location);

    /**
    * @brief Sets a tile to a new tile.
    *
    * @param[in] tile_x X location of tile to change.
    * @param[in] tile_y Y location of tile to change.
    * @param[in] tile   Tile.
    **/
    void set_tile(int tile_x, int tile_y, Tile tile);

    /**
    * @brief Sets whether you can navigate through a tile.
    *
    * @param[in] tile_x       X location of tile to change.
    * @param[in] tile_y       Y location of tile to change.
    * @param[in] navigability Whether you can navigate it or not.
    **/
    void set_tile_navigability(int tile_x, int tile_y, bool navigability);

    /**
    * @brief Checks whether you can navigate through a tile.
    *
    * @param[in] tile_x X location of tile to check.
    * @param[in] tile_y Y location of tile to check.
    *
    * @return Whether it is navigable or not.
    **/
    bool is_navigable(int tile_x, int tile_y);

    /**
    * @brief Draws the grid on the relative coordinates
    *
    * @param[in] window The window to draw on.
    **/
    void draw(sf::RenderWindow &window);

    /**
    * @brief Draws a path on the grid on the relative coordinates
    *
    * @param[in] window The window to draw on.
    * @param[in] path Path to be drawn.
    **/
    void draw_path(sf::RenderWindow &window, std::vector<sf::Vector2i> path);

    /**
    * @brief Function to turn the grind into a random maze.
    *
    * This function is mostly just for demo purposes.
    **/
    void create_maze();

    /**
    * @brief Updates all the tiles in the grid.
    *
    * NOTE: Doesn't yet work.
    **/
    void update();

    /**
     * @brief Returns size of grid
     *
     * @return std::pair with size values
     */
    std::pair<int, int> get_grid_size();

    /**
     * @brief Returns start
     *
     * @return std::pair with start values
     */
    std::pair<int, int> get_start_values();

	void reset_damage();

	void calculate_damage(std::vector<tower_ptr> tower_vector);


};

#endif // GRID_HPP
