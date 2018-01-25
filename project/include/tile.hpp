#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>

class Tile {
  private:
    int id;
    int lives;
    bool navigable = true;

  public:
    Tile() {
    }

    Tile(bool is_navigable);

    void set_navigability(bool navigability);

    bool is_navigable();

    int getID();

    void clicked();

    void set_built();

    void set_free();
};

#endif // TILE_HPP
