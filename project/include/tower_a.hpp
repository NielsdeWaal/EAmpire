#ifndef TOWER_A_HPP
#define TOWER_A_HPP

#include <SFML/Graphics.hpp>
#include "tower.hpp"
#include <iostream>

class tower_a : public Tower {
private:
	float cost = 100.0;
	float upgrade_cost = 50.0;
	float value;

	float damage = 15.0;
	//float fire_rate = 1.0;
	int radius = 1;

	int current_level = 1;
	int max_level = 5;

	int x_location;
	int y_location;

	//sf::CircleShape radius_circle;

public:
	tower_a(int x_location, int y_location);

	~tower_a();

	void upgrade();

	float get_damage();
	void draw(sf::RenderWindow & window);

	int get_radius();

	sf::Vector2i get_loc();

	//sf::Texture get_texture();
	//sf::Sprite get_sprite();

};


#endif //TOWER_A_HPP
