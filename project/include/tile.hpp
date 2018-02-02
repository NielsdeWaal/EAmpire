#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Tile {
  private:
    int lives;
    bool navigable = true;
    std::string sprite = "tile_normal";

  public:
    Tile() {
    }

    /**
    * @brief Constructor for tile.
    *
    * @param[in] is_navigable Whether the tile should allready be navigable or not.
    **/
    Tile(bool is_navigable);

    /**
    * @brief Set the navigability of the tile
    *
    * @param[in] navigability Whether the tile should be navigable or not.
    **/
    void set_navigability(bool navigability);

    /**
    * @brief Return the navigability of the tile.
    *
    * @return Bool whether the tile is navigable.
    **/
    bool is_navigable();

    /**
    * @brief Get the name of the sprite of the tile.
    *
    * @return A string of the name of the sprite of the tile.
    **/
    std::string get_sprite();

    /**
    * @brief Set the name of the sprite of the tile.
    *
    * @param[in] Name of the sprite.
    **/
    void set_sprite(std::string new_sprite);
};

#endif // TILE_HPP
