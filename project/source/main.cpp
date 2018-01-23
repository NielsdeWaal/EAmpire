#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "button.hpp"
#include "grid.hpp"
#include "action.hpp"
#include "factory.hpp"


int main(void) {
    auto game = Game();
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
	std::string tower1 = "Tower#1";
	std::string sell = "Sell";

	//factory button_factory("files/buttons.txt", window);
	//button_vector button = button_factory.buttons_from_file();

	
	//Button play_button(play, sf::Vector2f{ float((window.getSize().x / 2)), float((window.getSize().y / 2)) }, sf::Vector2f{ 70,50 }, window);
	Button exit_button(	exit, 
						sf::Vector2f{ (float((window.getSize().x / 2 )+ 212)), (float((window.getSize().y / 2)+100))+window.getSize().y*0.15f }, 
						sf::Vector2f{ 70,50 }, 
						window);
	Button basic_tower(	tower1, 
						sf::Vector2f{ (float((window.getSize().x / 2) + 325)), (float((window.getSize().y-window.getSize().y)+77)) },
						sf::Vector2f{ 130,50 },
						window);
	Button sell_button(	sell,
						sf::Vector2f{ (float((window.getSize().x / 2) + 325)), (float((window.getSize().y-window.getSize().y)+137)) },
						sf::Vector2f{ 130,50 },
						window);

	auto state = "free";

	action actions[] = {
		action(sf::Keyboard::Escape,	[&window]	{window.close(); }),
		action(sf::Keyboard::Num1,		[&state]	{state = "building"; }),
		action(sf::Keyboard::Delete,	[&state]	{state = "selling"; }),
		action(sf::Mouse::Right,		[&state]	{state = "free"; }),
		action(sf::Mouse::Left,			[&state, &window,&exit_button,&basic_tower,&sell_button,&grid]
													{	if (exit_button.is_pressed()) { window.close(); 
														}
														if (basic_tower.is_pressed()) { state = "building"; 
														}
														if (sell_button.is_pressed()) { state = "selling"; 
														}
														if (grid.is_clicked(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && (!strcmp(state,"building"))) {
															grid.set_built(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y); 
															state = "free"; 
														}
														if (grid.is_clicked(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && (!strcmp(state, "selling"))) {
															grid.set_free(sf::Mouse::getPosition(window).x,   sf::Mouse::getPosition(window).y); 
															state = "free";
														}

													})
	};

	while (window.isOpen()) {

		auto path = grid.find_path(start, end);
		sf::Event evnt;

		for (auto &action : actions) {
			action();
		}

		while (window.pollEvent(evnt)) {

			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
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

			window.clear();

			grid.draw(window);

			for (auto tile : path) {
				sprite_tile_path.setPosition(tile.x * 50 + (window.getSize().x / 4), tile.y * 50 + 50);
				window.draw(sprite_tile_path);
			}

			exit_button.draw();
			basic_tower.draw();
			sell_button.draw();
			//play_button.draw();
			
			window.display();
			game.update();

		}
	}
    return 0;
}
