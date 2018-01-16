#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "board.hpp"

class Game {
  private:
    std::vector<Board> boards;

  public:
    Game() {}

    void update();
};

#endif // GAME_HPP
