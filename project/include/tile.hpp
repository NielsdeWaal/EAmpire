#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>

class Tile {
  private:
    int id;
    int lives;

  public:
    int getID();
};

#endif // TILE_HPP
