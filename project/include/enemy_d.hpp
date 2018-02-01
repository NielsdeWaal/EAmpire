#ifndef ENEMY_D_HPP
#define ENEMY_D_HPP

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

class Enemy_d : public Enemy {
  public:
    /**
    * @brief Constructor
    *
    * When this constructor is called, it will make a custom enemy.
    */
    Enemy_d();

    /**
    * @brief Destructor
    */
    ~Enemy_d();

    void take_damage(float damage_tower) override;
};
#endif // ENEMY_D_HPP
