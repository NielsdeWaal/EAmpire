#include "tower_a.hpp"

tower_a::tower_a(int x_location, int y_location) :
	x_location(x_location),
	y_location(y_location)
{
	//radius_circle.setRadius(radius);
	//radius_circle.setOutlineColor(sf::Color::Red);
	//radius_circle.setFillColor(sf::Color::Transparent);
	//radius_circle.setOutlineThickness(1);
	//radius_circle.setPosition(x_location, y_location);
	value = cost;
}

tower_a::~tower_a() {
	std::cout << "TOWER SOLD" << std::endl;
	//currency += (value*0.75)
}


void tower_a::upgrade() {

}


float tower_a::get_damage() {
	return damage;
}

void tower_a::draw(sf::RenderWindow & window) {
	//window.draw(radius_circle);
}

sf::Vector2i tower_a::get_loc() {
	return sf::Vector2i(x_location, y_location);
}

int tower_a::get_radius() {
	return radius;
}