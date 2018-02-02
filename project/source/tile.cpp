#include "tile.hpp"

Tile::Tile(bool is_navigable) : navigable(is_navigable) {
}

void Tile::set_navigability(bool navigability) {
    navigable = navigability;
}

bool Tile::is_navigable() {
    return navigable;
}

std::string Tile::get_sprite() {
    return sprite;
}

void Tile::set_sprite(std::string new_sprite) {
    sprite = new_sprite;
}