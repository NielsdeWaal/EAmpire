#include <iostream>
#include <chrono>
#include <thread>

#include "game.hpp"

int main(void) {
    auto game = Game();

    while(true) {
        game.update();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
