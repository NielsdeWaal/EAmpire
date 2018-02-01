#ifndef TOWER_HPP
#define TOWER_HPP

#include "gameState.hpp"
#include <SFML/Graphics.hpp>

class Tower {
  private:
    float cost;
    float upgrade_cost;
    float value;

    float damage;
    float fire_rate;
    int radius;

    int current_level;
    int max_level;

    int x_location;
    int y_location;
    GameState *game_state = GameState::get_state();

  public:
    Tower(int x_location, int y_location);

    Tower();

    virtual ~Tower();

    void build_tower();
    void upgrade();

    virtual float get_damage();
    virtual void draw(sf::RenderWindow &window);

    virtual int get_radius();

    virtual sf::Vector2i get_loc();

    virtual float get_cost();

    // sf::Sprite get_sprite();
};

#endif // TOWER_HPP
