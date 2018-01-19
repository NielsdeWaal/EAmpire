#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>

class Tile {
  private:
    bool navigable;
    int id;
    int lives;

  public:
    Tile() {};

    Tile(bool is_navigable);

	void set_navigability(bool navigability);

	bool is_navigable();
    
	int getID();
};

#endif // TILE_HPP
