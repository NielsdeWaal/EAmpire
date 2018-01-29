#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Tile {
  private:
	int id;
	int lives;
	float damage = 0.0;
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

	float get_damage();

	void update_damage(float new_damage);

	void set_damage(float new_damage);
};

#endif // TILE_HPP
