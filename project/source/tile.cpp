#include <iostream>

#include "tile.hpp"

Tile::Tile(bool is_navigable):
	navigable(is_navigable)
	{}

void Tile::set_navigability(bool navigability) {
	navigable = navigability;
}

bool Tile::is_navigable() {
	return navigable;
}

void Tile::clicked() {
	navigable = !navigable;
}