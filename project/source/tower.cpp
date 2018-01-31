#include "tower.hpp"
#include <iostream>


Tower::Tower(int x_location, int y_location) :
	x_location(x_location),
	y_location(y_location)
{
}

Tower::Tower() {}

Tower::~Tower()
{
	//currency += (value*0.75)
}

void Tower::build_tower() {

}

void Tower::upgrade() {
	if (current_level >= max_level) {
		std::cout << "Can't be upgraded anymore." << std::endl;
		return;
	}
	//if (currency < upgrade_cost){
	//		std::cout << "Not enough money to upgrade." << std::endl;
	//		return;
	current_level += 1;
	value = value + upgrade_cost;
	upgrade_cost = (upgrade_cost * 2) + (upgrade_cost / 10);
}


float Tower::get_damage() {
	return damage;
}
void Tower::draw(sf::RenderWindow & window) {


}

sf::Vector2i Tower::get_loc() {
	return sf::Vector2i(0, 0);
}

int Tower::get_radius() {
	return radius;
}