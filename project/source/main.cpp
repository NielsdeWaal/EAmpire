#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "button.hpp"
#include "grid.hpp"


int main(void) {
    auto game = Game();

	//for (int i = 0; i < 9; i++) {
	//	grid.set_tile_navigability(4, i, false);
	//}

	sf::RenderWindow window(sf::VideoMode(1000, 750), "EAmpire Tower Defense", sf::Style::Titlebar | sf::Style::Close );

	Grid grid(10, 10, 50, window.getSize().x/4, 50);

	bool lastButton = false;
	auto start = sf::Vector2i(0,0);
	auto end   = sf::Vector2i(9,9);

	sf::Texture tile_path;
	sf::Sprite sprite_tile_path;
	tile_path.loadFromFile("textures/tile_path.png");
	sprite_tile_path.setTexture(tile_path);
	std::string play = "Play";
	std::string exit = "Exit";
	Button play_button(play, sf::Vector2f{ float((window.getSize().x / 2)), float((window.getSize().y / 2)) }, sf::Vector2f{ 70,50 }, window);
	Button exit_button(exit, sf::Vector2f{ float((window.getSize().x / 2)), float((window.getSize().y / 2))+window.getSize().y*0.15f }, sf::Vector2f{ 70,50 }, window);

	
	while( window.isOpen()) {

		auto path = grid.find_path(start, end);

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
					//Change gamestate to new board
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
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					grid.clicked(event.mouseButton.x, event.mouseButton.y);
				}

				//if (event.mouseButton.button == sf::Mouse::Right) {
				//	if (lastButton) {
				//		//start.x = (int)event.mouseButton.x / 50;
				//		//start.y = (int)event.mouseButton.y / 50;
				//		lastButton = !lastButton;
				//	}
				//	else {
				//		//end.x = (int)event.mouseButton.x / 50;
				//		//end.y = (int)event.mouseButton.y / 50;
				//		lastButton = !lastButton;
				//	}
				//}

				break;

			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					//Pop up 'Do you want to exit?' screen
					window.close();
				}
				break;
			}

			}
		}
		game.update();
		//std::this_thread::sleep_for(std::chrono::seconds(1));
		//sf::sleep(sf::milliseconds(20));
		window.clear();
		
		grid.draw(window);
		
		for (auto tile : path) {
			sprite_tile_path.setPosition(tile.x * 50 + (window.getSize().x / 4), tile.y * 50 + 50);
			window.draw(sprite_tile_path);
		}
		//exit_button.draw();
		//play_button.draw();
		window.display();
	}
    return 0;
}
