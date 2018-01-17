#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "button.hpp"




int main(void) {
   // auto game = Game();

	sf::RenderWindow window(sf::VideoMode(512.0f, 512.0f), "EAmpire Tower Defense", sf::Style::Default);

	std::string play = "Play";

	Button play_button(play, sf::Vector2f{ float((window.getSize().x / 2)), float((window.getSize().y / 2)) }, sf::Vector2f{ 50,50 });

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
			case sf::Event::MouseButtonPressed:
				switch (evnt.key.code) {
				case sf::Mouse::Left:
					std::cout << (sf::Mouse::getPosition(window)).x << "\t" << (sf::Mouse::getPosition(window)).y << std::endl;
					break;
				}
				break;
			case sf::Event::LostFocus:
				std::cout << "MOUSE HAS LEFT THE BUILDING" << std::endl;
				//pause game
				break;
			case sf::Event::GainedFocus:
				std::cout << "MOUSE HAS ENTERED THE BUILDING" << std::endl;
				//continue game
				break;
			}
		}
		window.clear();
		play_button.draw(window);
		window.display();
	}

    return 0;
}
