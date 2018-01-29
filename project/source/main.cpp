#include <iostream>
#include <chrono>
#include <cstring>
#include <thread>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "button.hpp"
#include "grid.hpp"
#include "action.hpp"
#include "tower.hpp"
#include "tower_a.hpp"


int main(void) {
	auto game = Game();
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "EAmpire Tower Defense", sf::Style::Titlebar | sf::Style::Close);

	auto grid_x = 10, grid_y = 10, scale = 50;
	auto grid_x_pixel = (grid_x < 10 ? 700 : grid_x * scale + 200);
	auto grid_y_pixel = (grid_y < 10 ? 600 : grid_y * scale + 100);

	Grid grid(grid_x, grid_y, scale, (grid_x_pixel - 100) / 2 - grid_x * 25, grid_y_pixel / 2 - grid_y * 25);

	window.create(sf::VideoMode(grid_x_pixel, grid_y_pixel), "EAmpire Tower Defense", sf::Style::Titlebar | sf::Style::Close);

	auto start = sf::Vector2i(0, 0);
	auto end = sf::Vector2i(9, 9);

	typedef std::shared_ptr<Tower> tower_ptr;
	typedef std::vector<tower_ptr> tower_vector;

	tower_vector towers;

	//sf::Texture tower_a_texture;
	//sf::Sprite sprite_tower_a;
	//tower_a_texture.loadFromFile("textures/TinyArno.png");
	//sprite_tower_a.setTexture(tower_a_texture);

	sf::Texture build_texture;
	sf::Sprite sprite_hammer;
	build_texture.loadFromFile("textures/hammer.png");
	sprite_hammer.setTexture(build_texture);

	sf::Texture sell_texture;
	sf::Sprite sprite_sell;
	sell_texture.loadFromFile("textures/sell.png");
	sprite_sell.setTexture(sell_texture);

	//std::string play = "Play";
	std::string exit = "Exit";
	std::string tower1 = "Tower#1";
	//std::string tower2 = "Tower#2";
	//std::string tower3 = "Tower#3";
	//std::string tower4 = "Tower#4";
	//std::string tower5 = "Tower#5";
	std::string sell = "Sell";
	std::string menu = "Menu";

	//tower_a tower_1(20,30);

	//Button play_button(play, sf::Vector2f{ float((window.getSize().x / 2)), float((window.getSize().y / 2)) }, sf::Vector2f{ 70,50 }, window);
	Button tower1_button(tower1,
		sf::Vector2f(grid_x_pixel - 50, 125),
		sf::Vector2f(100, 50),
		window);
	/*Button tower2_button(tower2,
	sf::Vector2f(grid_x_pixel - 50, 200),
	sf::Vector2f(100, 50),
	window);
	Button tower3_button(tower3,
	sf::Vector2f(grid_x_pixel - 50, 275),
	sf::Vector2f(100, 50),
	window);
	Button tower4_button(tower4,
	sf::Vector2f(grid_x_pixel - 50, 350),
	sf::Vector2f(100, 50),
	window);
	Button tower5_button(tower5,
	sf::Vector2f(grid_x_pixel - 50, 425),
	sf::Vector2f(100, 50),
	window);*/
	Button sell_button(sell,
		sf::Vector2f(grid_x_pixel - 50, 525),
		sf::Vector2f(100, 50),
		window);
	Button menu_button(menu,
		sf::Vector2f(grid_x_pixel - 50, 25),
		sf::Vector2f(100, 50),
		window);

	auto state = "free";

	action actions[] = {
		action(sf::Keyboard::Escape,	[&window] {window.close(); }),
		action(sf::Keyboard::Num1,		[&state] {state = "building"; }),
		action(sf::Keyboard::Delete,	[&state] {state = "selling"; }),
		action(sf::Mouse::Right,		[&state] {state = "free"; }),
		action(sf::Mouse::Left,			[&state, &window,&menu_button,&tower1_button,&sell_button,&grid,&towers]
	{	if (menu_button.is_pressed()) {
		window.close();
	}
	if (tower1_button.is_pressed()) {
		state = "building";
	}
	if (sell_button.is_pressed()) {
		state = "selling";
	}
	if ((grid.is_clicked(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
		&& (!strcmp(state,"building"))) {
		grid.set_built(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
		towers.push_back(tower_ptr(new tower_a(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)));
		state = "free";
		/*if (grid.is_navigable(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		grid.set_built(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
		towers.push_back(tower_ptr(new tower_a(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)));
		state = "free";
		}*/
	}
	if (grid.is_clicked(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && (!strcmp(state, "selling"))) {
		grid.set_free(sf::Mouse::getPosition(window).x,   sf::Mouse::getPosition(window).y);
		state = "free";
	}

	})
	};

	while (window.isOpen()) {
		for (auto &action : actions) {
			action();
		}

		auto path = grid.find_path(start, end);

		sf::Event evnt;
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
		}


		window.clear(sf::Color(100, 100, 100));
		grid.draw(window);
		grid.draw_path(window, path);

		tower1_button.draw();
		//tower2_button.draw();
		//tower3_button.draw();
		//tower4_button.draw();
		//tower5_button.draw();
		sell_button.draw();
		menu_button.draw();
		//play_button.draw();



		if (!strcmp(state, "building")) {
			sprite_hammer.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
			window.draw(sprite_hammer);
			window.setMouseCursorVisible(false);
		}
		else if (!strcmp(state, "selling")) {
			sprite_sell.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
			window.draw(sprite_sell);
			window.setMouseCursorVisible(false);
		}
		else {
			window.setMouseCursorVisible(true);
		}
		//tower_1.draw(window);

		for (auto &tower : towers) {
			tower->draw(window);
		}

		window.display();
		game.update();

	}
	return 0;
}
