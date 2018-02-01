#include "enemy_d.hpp"

Enemy_d::Enemy_d():
         Enemy(sf::Color::Magenta, 1, 0.6f, 20)
{}

Enemy_d::~Enemy_d() {
}

void Enemy_d::take_damage(float damage_tower) {
    float lives_a = get_lives();
    lives_a -= damage_tower;
    set_lives(lives_a);
}
