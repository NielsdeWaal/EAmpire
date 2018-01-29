#ifndef TOWER_HPP
#define TOWER_HPP

#include <SFML/Graphics.hpp>


class Tower
{
private:
	float cost;
	float upgrade_cost;
	float value;

	float damage;
	float fire_rate;
	int radius;

	int current_level;
	int max_level;

	int x_location;
	int y_location;

public:
	Tower(int x_location, int y_location);

	Tower();

	~Tower();

	void build_tower();
	void upgrade();
	void sell_tower();
	
	virtual float get_damage();
	virtual void draw(sf::RenderWindow & window);

	virtual int get_radius();

	virtual sf::Vector2i get_loc();

	//sf::Sprite get_sprite();
};

#endif // TOWER_HPP
