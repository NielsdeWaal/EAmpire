#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Tile {
  private:
    int id;
    int lives;

  public:
    Tile() 
    {
        std::cout << "Tile made" << std::endl;
    }

    int getID();
};

#endif // TILE_HPP
