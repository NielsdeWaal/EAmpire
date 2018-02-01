#include "enemy_c.hpp"

Enemy_c::Enemy_c():
         Enemy("enemy_c", 2, 0.18f, 150)
{}

Enemy_c::~Enemy_c() {
}

void Enemy_c::take_damage(float damage_tower) {
    float lives_b = get_lives();
    lives_b -= damage_tower;
    if (get_name() != "enemy_b") {
        if (lives_b <= 100) {
            set_name("enemy_b");
            set_speed(0.14f);
        }
    }
    if (get_name() != "enemy_a") {
        if (lives_b <= 50) {
            set_name("enemy_a");
            set_speed(0.1f);
        }
    }
    set_lives(lives_b);
}
