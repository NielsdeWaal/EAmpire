#ifndef TOWER_HPP
#define TOWER_HPP


class Tower
{
private:
	float cost;
	float upgrade_cost;
	float value;

	float damage;
	float fire_rate;
	float radius;

	int current_level;
	int max_level;

public:
	Tower();

	~Tower();

	void build_tower();
	void upgrade();
	void sell_tower();
	void draw_tower();
};

#endif // !TOWER_HPP

