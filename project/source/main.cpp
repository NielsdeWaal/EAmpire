#include <iostream>
#include <chrono>
#include <thread>

#include "game.hpp"

int main(void) {
    auto game = Game();

	Grid grid(10, 10, 50, 100, 50);

	for (int i = 0; i < 9; i++) {
		grid.set_tile_navigability(4, i, false);
	}

	sf::RenderWindow window(sf::VideoMode(1000, 750), "EAmpire Tower Defense");

    while(true) {

		window.clear();
		grid.draw(window);
		window.display();

        game.update();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
