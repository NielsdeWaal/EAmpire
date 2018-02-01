#ifndef ENEMY_B_HPP
#define ENEMY_B_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

#include "enemy.hpp"

/**
* @file enemy_b.hpp
* @author Dylan van Eck
* @date 18/01/2018
*
* @brief subclass of Enemy
*
* This is a subclass of Enemy. The Enemy is a circle shape with adaptable
* diameter and adaptable color.
*/

class Enemy_b : public Enemy {
  public:
    /**
    * @brief Constructor
    *
    * When this constructor is called, it will make a custom enemy.
    */
    Enemy_b();

    /**
    * @brief Destructor
    */
    ~Enemy_b();

    void take_damage(float damage_tower) override;
};
#endif // ENEMY_B_HPP
