#include <iostream>
#include <chrono>
#include <thread>

#include "game.hpp"

int main(void) {
    auto game = Game();

	Grid grid(19, 19, 50, 0, 0);
	
	sf::RenderWindow window(sf::VideoMode(950, 950), "EAmpire Tower Defense");

	bool lastButton = false;
	auto start = sf::Vector2i(1,1);
	auto end   = sf::Vector2i(17,17);

	auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	int loop = 0;

    while(window.isOpen()) {
		grid.create_maze();
		auto path = grid.find_path(start, end);

		//std::this_thread::sleep_for(std::chrono::milliseconds(200));
		sf::Event event;
		while (window.pollEvent(event)) {

			switch(event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					grid.clicked(event.mouseButton.x, event.mouseButton.y);
					break;
				}
				if (event.mouseButton.button == sf::Mouse::Right) {
					if (lastButton) {
						start.x = (int)(event.mouseButton.x)/50;
						start.y = (int)(event.mouseButton.y)/50;
						lastButton = !lastButton;
					}
					else {
						end.x = (int)(event.mouseButton.x)/50;
						end.y = (int)(event.mouseButton.y)/50;
						lastButton = !lastButton;
					}
					break;
				}
				
			}
		}

		window.clear();
		grid.draw(window);
		grid.draw_path(window, path);
		window.display();

        game.update();

		loop++;
		if ((std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) - time) > 1) {
			time++;
			std::cout << loop << "'s loops per second\n";
			loop = 0;
		}

		//std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
