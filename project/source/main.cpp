#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "button.hpp"
#include "grid.hpp"
#include "action.hpp"
#include "enemy_a.hpp"
#include "enemy.hpp"
#include "enemy_container.hpp"


int main(void) {
    auto game = Game();
	sf::RenderWindow window(sf::VideoMode(1000, 750), "EAmpire Tower Defense", sf::Style::Titlebar | sf::Style::Close );
	Enemy_container container = Enemy_container();
	container.add();
	container.add();

	while (window.isOpen()) {
		window.clear();

		for (const auto & enemy : container.get_container()) {
			enemy.second->draw(window);
			//std::cout << enemy.first << "\n";
		}
		container.get_container()[2]->move_direction(sf::Vector2f(20, 20));
		container.get_container()[0]->move_direction(sf::Vector2f(700, 700));
		container.get_container()[1]->move_direction(sf::Vector2f(400, 300));
		bool location = container.get_container()[3]->move_direction(sf::Vector2f(200, 300));
		window.display();
		if (location == true) {
			container.remove(3);
			while (true) {
				window.clear();
				for (const auto & enemy : container.get_container()) {
					enemy.second->draw(window);
					//std::cout << enemy.first << "\n";
				}
				container.get_container()[2]->move_direction(sf::Vector2f(20, 400));
				container.get_container()[0]->move_direction(sf::Vector2f(700, 700));
				container.get_container()[1]->move_direction(sf::Vector2f(400, 300));
				window.display();

				sf::sleep(sf::milliseconds(20));

				sf::Event event;
				if (window.pollEvent(event)) {
					if (event.type == sf::Event::Closed) {
						window.close();
					}
				}
			}
		}

		sf::sleep(sf::milliseconds(20));

		sf::Event event;
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	
	}
    return 0;
}
