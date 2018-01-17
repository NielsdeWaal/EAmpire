#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.hpp"

int main(void) {
   // auto game = Game();

	sf::RenderWindow window(sf::VideoMode(512, 512), "EAmpire Tower Defense", sf::Style::Default);

	while( window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {

			switch(evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				std::cout << "Window Resized" << std::endl;
				break;
			}
		}
		window.clear();
		window.display();
	}

    return 0;
}
