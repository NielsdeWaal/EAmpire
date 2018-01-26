#include "enemy.hpp"

//PRIVATE
float Enemy::length(sf::Vector2i vector2f) {
	return float(sqrt(vector2f.x * vector2f.x + vector2f.y * vector2f.y));
}

sf::Vector2f Enemy::normalize(sf::Vector2i vector2i) {
	sf::Vector2f vector;
	float length_of_vector = length(vector2i);

	if (length_of_vector != 0) {
		vector.x = vector2i.x / length_of_vector;
		vector.y = vector2i.y / length_of_vector;
	}


    return vector;
}



//PUBLIC
Enemy::Enemy(sf::Color color, const int damage, const int speed, int lives) :
	color(color),
	damage(damage),
	speed(speed),
	lives(lives)
{
	circle.setRadius(diameter);
	circle.setFillColor(color);
	circle.setPosition(Vector2f_from_Vector2i(position));
}

Enemy::~Enemy() {
	std::cout << "Enemy is being deleted" << std::endl;
}

void Enemy::attack(int & health_player) {
	health_player -= damage;
}

void Enemy::take_damage(const int damage_tower) {
    if (lives <= 0) {
        std::cout << "death";
    } else {
        lives -= damage_tower;
        std::cout << "lives down";
    }
}

void Enemy::move_direction() {
	sf::Vector2f direction_enemy = normalize(position - nextlocation);
	std::cout << direction_enemy.x << " : " << direction_enemy.y << std::endl;
	position = position - sf::Vector2i(direction_enemy.x * speed, direction_enemy.y * speed);
}

sf::CircleShape Enemy::get_circle() {
	return circle;
}

void Enemy::set_fill_color(sf::Color color) {
	circle.setFillColor(color);
}

sf::Vector2f Enemy::Vector2f_from_Vector2i(sf::Vector2i rhs) {
	return sf::Vector2f(
		static_cast< float >(rhs.x),
		static_cast< float >(rhs.y)
	);
};

bool Enemy::next_location(std::vector<sf::Vector2i> path) {
	for (auto it = path.begin(); it != path.end(); ++it) {
		//std::cout << it->x << " : " << it->y << std::endl;
		//std::cout << position.x << " : " << position.y << std::endl;
		if (position == sf::Vector2i(it->x, it->y)){
			//std::cout << "kip " << std::endl;
			if (std::next(it) != path.end()) {
				nextlocation = sf::Vector2i(std::next(it)->x,  std::next(it)->y);
				position = nextlocation;
				std::cout << nextlocation.x << " : " << nextlocation.y << std::endl;
				return true;
				//std::cout << std::next(it)->x << " : " << std::next(it)->y << std::endl;
				//std::cout << position.x << " : " << position.y << std::endl;
			}
			else {
				return false;
			}
		}
	}

}

void Enemy::draw(sf::RenderWindow & window, const int & tile_size) {
	sf::Vector2i location = sf::Vector2i((position.x + 1) * tile_size, (position.y + 1) * tile_size);
	std::cout << location.x << " : " << location.y << std::endl;
	circle.setPosition(Vector2f_from_Vector2i(sf::Vector2i((position.x + 1) * tile_size, (position.y + 1) * tile_size)));
	window.draw(circle);
}