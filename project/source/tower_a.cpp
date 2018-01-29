#include "tower_a.hpp"

tower_a::tower_a(int x_location, int y_location) :
	x_location(x_location),
	y_location(y_location)
{
	radius_circle.setRadius(radius);
	radius_circle.setOutlineColor(sf::Color::Red);
	radius_circle.setFillColor(sf::Color::Transparent);
	radius_circle.setOutlineThickness(1);
	radius_circle.setPosition(x_location, y_location);
	value = cost;
}


void tower_a::upgrade() {

}

void tower_a::sell_tower() {

}

void tower_a::draw(sf::RenderWindow & window) {
	window.draw(radius_circle);
}