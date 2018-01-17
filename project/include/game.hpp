#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "board.hpp"

class Game {
  private:
    std::vector<Board> boards;

  public:
    Game() {
        std::cout << "Game started" << std::endl;
        initialize();
    }

    void update();

    void initialize();
};

#endif // GAME_HPP
