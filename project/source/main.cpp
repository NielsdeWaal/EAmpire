#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "button.hpp"




int main(void) {
   // auto game = Game();

	sf::RenderWindow window(sf::VideoMode(512.0f, 512.0f), "EAmpire Tower Defense", sf::Style::Default);


	std::string play = "Play";
	Button play_button(play, sf::Vector2f{ float((window.getSize().x / 2)), float((window.getSize().y / 2)) }, sf::Vector2f{ 70,50 }, window);
	
	std::cout << "Start button is at: " << play_button.get_location().x << '\t' << play_button.get_location().y << std::endl;
	std::cout << "End button is at: " << play_button.get_location().x + play_button.get_size().x << '\t' << play_button.get_location().y + play_button.get_size().y << std::endl;

	sf::Text testtekst;
	sf::Font fontje;
	fontje.loadFromFile("PlayfairDisplay-Black.ttf");
	testtekst.setFont(fontje);
	testtekst.setFillColor(sf::Color::Green);
	testtekst.setString("TESTTEST");
	testtekst.setPosition(sf::Vector2f(20, 20));

	
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
				if	(play_button.is_pressed()){
					std::cout << "Play button pressed" << std::endl;
					//Change gamestate
				}
				else {
					std::cout << "Mouse x " << sf::Mouse::getPosition(window).x << "\tButton x" << play_button.get_location().x << ">>" << play_button.get_location().x + play_button.get_size().x << std::endl;
					std::cout << "Mouse y " << sf::Mouse::getPosition(window).y << "\tButton y" << play_button.get_location().y << ">>" << play_button.get_location().y + play_button.get_size().y << std::endl;
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
		play_button.draw();
		window.display();
	}

    return 0;
}
