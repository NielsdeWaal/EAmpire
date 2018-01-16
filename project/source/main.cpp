#include <iostream>

#include "game.hpp"

int main(void) {
    auto game = Game();

    while(true) {
        game.update();
    }

    return 0;
}
