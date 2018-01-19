#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "button.hpp"
#include "grid.hpp"


int main(void) {
    auto game = Game();

	sf::RenderWindow window(sf::VideoMode(512.0f, 512.0f), "EAmpire Tower Defense", sf::Style::Titlebar | sf::Style::Close);


	std::string play = "Play";
	std::string exit = "Exit";
	Button play_button(play, sf::Vector2f{ float((window.getSize().x / 2)), float((window.getSize().y / 2)) }, sf::Vector2f{ 70,50 }, window);
	Button exit_button(exit, sf::Vector2f{ float((window.getSize().x / 2)), float((window.getSize().y / 2))+window.getSize().y*0.15f }, sf::Vector2f{ 70,50 }, window);
	
	Grid grid(10, 10, 30);
	
	while( window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {

			switch(evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:
				if	(play_button.is_pressed()){
					std::cout << "Play button pressed" << std::endl;
					//Change gamestate
				}
				if (exit_button.is_pressed()) {
					window.close();
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
		game.update();
		//std::this_thread::sleep_for(std::chrono::seconds(1));
		sf::sleep(sf::milliseconds(20));
		window.clear();
		exit_button.draw();
		play_button.draw();
		window.display();
	}
    return 0;
}
