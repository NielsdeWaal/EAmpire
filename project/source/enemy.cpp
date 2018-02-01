#include "enemy.hpp"

//PRIVATE
float Enemy::length(sf::Vector2f vector2f) {
	return roundf(float(sqrt(vector2f.x * vector2f.x + vector2f.y * vector2f.y)) * 100) / 100;
}

sf::Vector2f Enemy::normalize(sf::Vector2f distance_nextlocation) {
	sf::Vector2f vector;
	float length_of_vector = length(distance_nextlocation);
	if (length_of_vector != 0) {
		vector.x = (distance_nextlocation.x / length_of_vector);
		vector.y = (distance_nextlocation.y / length_of_vector);
	}
    return vector;
}

void Enemy::corner_check(sf::Vector2f & boundarieA, sf::Vector2f & boundarieB, sf::Vector2f & position) {
	if (boundarieA.x == boundarieB.x) {
		position.x = boundarieA.x;
	}
	else if (boundarieA.y == boundarieB.y) {
		position.y = boundarieA.y;
	}
}
//PUBLIC
Enemy::Enemy(sf::Color color, const int damage, const float speed, float lives) :
	color(color),
	damage(damage),
	speed(speed),
	lives(lives)
{
	circle.setRadius(diameter);
	circle.setFillColor(color);
	circle.setPosition(position);
}

Enemy::~Enemy() {}

void Enemy::attack(int & health_player) {
	health_player -= damage;
}

void Enemy::move_direction(const int & size_grid) {
	sf::Vector2f direction_enemy = normalize(sf::Vector2f(position.x - boundaryB.x, position.y - boundaryB.y));
	position = position - sf::Vector2f(direction_enemy.x * speed, direction_enemy.y * speed);
	if (position.x > size_grid - 1) {
		position.x = (float)size_grid - 1;
	} else if (position.y > size_grid - 1) {
		position.y = (float)size_grid - 1;
	} else if (position.x < 0) {
		position.x = 0;
	} else if (position.y < 0) {
		position.y = 0;
	}
}

void Enemy::next_location(std::vector<sf::Vector2i> path) {
	for (auto it = path.begin(); it != path.end(); ++it) {
		if (it->x == boundaryA.x && it->y == boundaryA.y) {
			if (std::next(it) != path.end()) {
				boundaryB = sf::Vector2f((float)std::next(it)->x, (float)std::next(it)->y);
				if (position == boundaryB) {
					boundaryA = boundaryB;
					move_direction(path.size());
					if (std::next(std::next(it)) != path.end()) {
						boundaryB = sf::Vector2f((float)std::next(std::next(it))->x, (float)std::next(std::next(it))->y);
					}
				} else if (position.x >= boundaryA.x && position.y >= boundaryA.y && position.x <= boundaryB.x && position.y <= boundaryB.y || position.x <= boundaryA.x && position.y <= boundaryA.y && position.x >= boundaryB.x && position.y >= boundaryB.y) {
					move_direction(path.size());
					corner_check(boundaryA, boundaryB, position);
				} else {
					boundaryA = boundaryB;
					if (std::next(std::next(it)) != path.end()) {
						boundaryB = sf::Vector2f(float(std::next(std::next(it))->x), float(std::next(std::next(it))->y));
					}
					move_direction(path.size());
					corner_check(boundaryA, boundaryB, position);
				}
			}
		}
	}
}

bool Enemy::check_end_location(std::vector<sf::Vector2i> path) {
    for (auto it = path.begin(); it != path.end(); ++it) {
        if (it->x == boundaryA.x && it->y == boundaryA.y) {
            if (std::next(it) == path.end()){
                return true;
            }
        }
    }
    return false;
}

void Enemy::draw(sf::RenderWindow & window, const int & tile_size) {
	circle.setPosition((position.x + 1) * tile_size, (position.y + 1) * tile_size);
	window.draw(circle);
}

float Enemy::get_lives() {
    return lives;
}

void Enemy::set_lives(float lives_input) {
	lives = lives_input;
}
sf::Vector2f Enemy::get_location() {
    return position;
}

void Enemy::set_fillcolor(sf::Color color_output) {
	circle.setFillColor(color_output);
}

sf::Color Enemy::get_fillcolor() {
	return color;
}

void Enemy::set_speed(float speed_input) {
	speed = speed_input;
}

int Enemy::get_damage() {
    return damage;
}

void Enemy::take_damage(float damage_tower) {
    lives -= damage_tower;
}