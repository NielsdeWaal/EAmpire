#include "tower_a.hpp"

tower_a::tower_a(){
	sf::Texture tower_a_texture;
	sf::Sprite sprite_tower_a;
	tower_a_texture.loadFromFile("textures/TinyArno.png");
	sprite_tower_a.setTexture(tower_a_texture);

	value = cost;
}
