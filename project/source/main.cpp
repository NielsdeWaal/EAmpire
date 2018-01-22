#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "enemy_a.hpp"
#include "enemy.hpp"
#include "action.hpp"
#include "enemy_container.hpp"

int main(void) {
	std::cout << "Starting application 01-02 static ball\n";
	sf::RenderWindow window{ sf::VideoMode{ 640, 640 }, "SFML window" };
	//std::vector<Enemy*> screen_objects;
	Enemy_container<Enemy*> screen_objects;
	Enemy* a1 = new Enemy_a(sf::Vector2f( 150,150 ), sf::Color::Red, 8 , 1, 300, 50.0 );
	screen_objects.add(a1);
	//Enemy_a a2{ sf::Vector2f{ 150,150 }, sf::Color::Red, 8 , 1, 300, 50.0 };
	sf::Vector2f locations(0, 0);

	//Tryout: has to be deleted or implemented somewhere else
	//Direction = Left,Right,Up,Down
	sf::Vector2f directions[4] = { sf::Vector2f(200,200), sf::Vector2f(1,0), sf::Vector2f(0,-1), sf::Vector2f(0,1) };
	sf::Vector2i cursorPos;

	//action actions[] = {
	//	action([&cursorPos, /*&a1*/, &window]() {
	//	if (cursorPos.y <= a1.get_circle().getGlobalBounds().top + a1.get_circle().getGlobalBounds().height && cursorPos.y >= a1.get_circle().getGlobalBounds().top - a1.get_circle().getRadius()&&
	//		cursorPos.x <= a1.get_circle().getGlobalBounds().left + a1.get_circle().getGlobalBounds().width && cursorPos.x >= a1.get_circle().getGlobalBounds().left) {
	//		a1.set_fill_color(sf::Color::Blue);
	//	} else {
	//		a1.set_fill_color(sf::Color::Red);
	//	}; }) };


	while (window.isOpen()) {
		/*for (auto & action : actions) {
			action();
		}*/
		cursorPos = sf::Mouse::getPosition(window);
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		};
		window.clear();
		bool first_state = false;
		/*if (!first_state) {
			bool firstlocation = a1.move_direction(locations);
			if (firstlocation) {
				locations = sf::Vector2f(300, 300);
			}
		}
		else if(first_state) {
			std::cout << "start second" << std::endl;
			bool secondlocation = a1.move_direction(sf::Vector2f(300, 300));
		}*/
		for (auto p : screen_objects.get_container()){
				p->draw(window);
				bool location = p->move_direction(sf::Vector2f(300, 300));
				if (location) {
					screen_objects.remove(a1);
				}
		}
		window.display();

		sf::sleep(sf::milliseconds(20));
	}
	std::cout << "Terminating application\n";
	return 0;
}
