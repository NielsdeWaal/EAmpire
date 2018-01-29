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

void Tile::set_built() {
	navigable = false;
}

void Tile::set_free() {
	navigable = true;
}

float Tile::get_damage() {
	return damage;
}

void Tile::update_damage(float new_damage) {
	damage += new_damage;
}

void Tile::set_damage(float new_damage) {
	damage = new_damage;
}