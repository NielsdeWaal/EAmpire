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

	Enemy_container<Enemy*> screen_objects;
	Enemy* a1 = new Enemy_a(sf::Vector2f( 150,150 ), sf::Color::Red, 8 , 5, 300, 50.0 );
	screen_objects.add(a1);


	sf::Vector2f directions[4] = { sf::Vector2f(200,200), sf::Vector2f(1,0), sf::Vector2f(0,-1), sf::Vector2f(0,1) };
	sf::Vector2i cursorPos;
	

	//This is for Action class
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
		for (auto p : screen_objects.get_container()){
				p->draw(window);
				bool first_state = p->move_direction(sf::Vector2f(300, 300));
				if (first_state) {
					screen_objects.remove(a1);
				}
		}
		window.display();

		sf::sleep(sf::milliseconds(20));
	}
	std::cout << "Terminating application\n";
	return 0;
}
