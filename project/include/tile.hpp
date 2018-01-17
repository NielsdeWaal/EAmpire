#ifndef TILE_HPP
#define TILE_HPP

class Tile {
  private:
    bool navigable;

  public:
    Tile() {};

    Tile(bool is_navigable);

	void set_navigability(bool navigability);

	bool is_navigable();
};

#endif // TILE_HPP
