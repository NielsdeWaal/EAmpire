#include "tower_b.hpp"

tower_b::tower_b(int x_location, int y_location): 
                 x_location(x_location), 
                 y_location(y_location) 
{
    // radius_circle.setRadius(radius);
    // radius_circle.setOutlineColor(sf::Color::Red);
    // radius_circle.setFillColor(sf::Color::Transparent);
    // radius_circle.setOutlineThickness(1);
    // radius_circle.setPosition(x_location, y_location);
    value = cost;
    game_state->set_curreny(game_state->get_curreny() - cost);
}

tower_b::~tower_b() {
    game_state->add_currency(value - 5);
}

void tower_b::upgrade() {
}

float tower_b::get_damage() {
    return damage;
}

void tower_b::draw(sf::RenderWindow &window) {
    // window.draw(radius_circle);
}

sf::Vector2i tower_b::get_loc() {
    return sf::Vector2i(x_location, y_location);
}

int tower_b::get_radius() {
    return radius;
}
