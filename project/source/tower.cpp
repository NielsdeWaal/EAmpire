#include "tower.hpp"
#include <iostream>

Tower::Tower(int x_location, int y_location): 
             x_location(x_location), 
             y_location(y_location) 
{}

Tower::Tower() {
}

Tower::Tower() {}

Tower::~Tower()
{

}

float Tower::get_damage() {
    return damage;
}

sf::Vector2i Tower::get_loc() {
    return sf::Vector2i(0, 0);
}

int Tower::get_radius() {
    return radius;
}

float Tower::get_cost() {
    return cost;
}
