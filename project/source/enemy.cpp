#include "enemy.hpp"

//PRIVATE
float Enemy::length(sf::Vector2f vector2f) {
	return roundf(float(sqrt(vector2f.x * vector2f.x + vector2f.y * vector2f.y)) * 10) / 10;
}

sf::Vector2f Enemy::normalize(sf::Vector2f vector2f) {
	sf::Vector2f vector;
	float length_of_vector = length(vector2f);
	if (length_of_vector != 0) {
		vector.x = (vector2f.x / length_of_vector);
		vector.y = (vector2f.y / length_of_vector);
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
Enemy::Enemy(sf::Color color, const int damage, const float speed, int lives) :
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

void Enemy::take_damage(float damage_tower) {
   // if (lives <= 0) {
   //     std::cout << "death";
   // } else {
        lives -= static_cast<int>(damage_tower);
        //std::cout << "lives down";
    //}
}

void Enemy::move_direction() {
	sf::Vector2f direction_enemy = normalize(sf::Vector2f(position.x - boundarieB.x, position.y - boundarieB.y));
	position = position - sf::Vector2f(direction_enemy.x * speed, direction_enemy.y * speed);
	if (position.x > 9) {
		position.x = 9;
	} else if (position.y > 9) {
		position.y = 9;
	} else if (position.x < 0) {
		position.x = 0;
	} else if (position.y < 0) {
		position.y = 0;
	}
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

void Enemy::next_location(std::vector<sf::Vector2i> path) {
	for (auto it = path.begin(); it != path.end(); ++it) {
		if (it->x == boundarieA.x && it->y == boundarieA.y) {
			if (std::next(it) != path.end()) {
				boundarieB = sf::Vector2f((float)std::next(it)->x, (float)std::next(it)->y);
				if (position == boundarieB) {
					boundarieA = boundarieB;
					move_direction();
					if (std::next(std::next(it)) != path.end()) {
						boundarieB = sf::Vector2f((float)std::next(std::next(it))->x, (float)std::next(std::next(it))->y);
					}
				} else if (position.x >= boundarieA.x && position.y >= boundarieA.y && position.x <= boundarieB.x && position.y <= boundarieB.y || position.x <= boundarieA.x && position.y <= boundarieA.y && position.x >= boundarieB.x && position.y >= boundarieB.y) {
					move_direction();
					corner_check(boundarieA, boundarieB, position);
				}
				else {
					boundarieA = boundarieB;
					if (std::next(std::next(it)) != path.end()) {
						boundarieB = sf::Vector2f(float(std::next(std::next(it))->x), float(std::next(std::next(it))->y));
					}
					move_direction();
					corner_check(boundarieA, boundarieB, position);
				}
			}
		}
	}
}

bool Enemy::check_end_location(std::vector<sf::Vector2i> path) {
    for (auto it = path.begin(); it != path.end(); ++it) {
        if (it->x == boundarieA.x && it->y == boundarieA.y) {
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
    return static_cast<float>(lives);
}

sf::Vector2f Enemy::get_location() {
    return position;
}