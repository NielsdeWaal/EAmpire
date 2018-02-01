#ifndef TOWER_B_HPP
#define TOWER_B_HPP

#include "gameState.hpp"
#include "tower.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class tower_b : public Tower {
  private:
    GameState *game_state = GameState::get_state();
    float cost = 10.0;
    float upgrade_cost = 50.0;
    float value;

    float damage = 0.0;
    int radius = 1;

    int current_level = 1;
    int max_level = 1;

    int x_location;
    int y_location;

  public:
    tower_b(int x_location, int y_location);

    ~tower_b();

    void upgrade();

    float get_damage();
    void draw(sf::RenderWindow &window);

    int get_radius();

    sf::Vector2i get_loc();
};

#endif // TOWER_B_HPP
