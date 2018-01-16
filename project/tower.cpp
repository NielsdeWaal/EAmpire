#include "tower.hpp"
#include <iostream>


Tower::Tower(Tile location) :
	location(location)
{
	value = cost;
}


Tower::~Tower()
{
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

void Tower::sell_tower() {
	//currency += (value*0.75)
}