#ifndef TOWER_HPP
#define TOWER_HPP

#include "tile.hpp"

class Tower
{
private:
	float cost;
	float upgrade_cost;
	float value;

	float damage;
	float fire_rate;
	float radius;

	int current_level = 1;
	int max_level;

	Tile location;
public:
	Tower(Tile location);

	~Tower();

	void build_tower();
	void upgrade();
	void sell_tower();
};

#endif // !TOWER_HPP

