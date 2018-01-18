#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "enemy_a.hpp"
#include "enemy.hpp"
#include "action.hpp"


int main(void) {
	std::cout << "Starting application 01-02 static ball\n";
	sf::RenderWindow window{ sf::VideoMode{ 640, 640 }, "SFML window" };
	Enemy_a a1{ sf::Vector2f{0,0}, sf::Color::Red, 8 , sf::Vector2f{4,4}, 300, 50.0 };

	//Tryout: has to be deleted or implemented somewhere else
	//Direction = Left,Right,Up,Down
	sf::Vector2f directions[4] = { sf::Vector2f(-1,0), sf::Vector2f(1,0), sf::Vector2f(0,-1), sf::Vector2f(0,1) };
	sf::Vector2i cursorPos;

	action actions[] = {
		action(sf::Keyboard::Left,	[&a1,&directions]() {	a1.move_direction(directions[0]);	}),
		action(sf::Keyboard::Right,	[&a1,&directions]() {	a1.move_direction(directions[1]);	}),
		action(sf::Keyboard::Up,	[&a1,&directions]() {	a1.move_direction(directions[2]);	}),
		action(sf::Keyboard::Down,	[&a1,&directions]() {	a1.move_direction(directions[3]);	}),
		action(sf::Keyboard::A,		[&a1]				{	a1.take_damage(50);					}),
		action([&cursorPos, &a1, &window]() {
		if (cursorPos.y <= a1.getCircle().getGlobalBounds().top + a1.getCircle().getGlobalBounds().height - a1.getCircle().getRadius() && cursorPos.y >= a1.getCircle().getGlobalBounds().top - a1.getCircle().getRadius()&&
			cursorPos.x <= a1.getCircle().getGlobalBounds().left + a1.getCircle().getGlobalBounds().width && cursorPos.x >= a1.getCircle().getGlobalBounds().left) {
			a1.set_fill_color(sf::Color::Blue);
			//a1.draw_string(window, sf::Vector2f(a1.getCircle().getGlobalBounds().top + a1.getCircle().getGlobalBounds().height - a1.getCircle().getRadius(), a1.getCircle().getGlobalBounds().left + a1.getCircle().getGlobalBounds().width - a1.getCircle().getRadius()));
		} else {
			a1.set_fill_color(sf::Color::Red);
		}; }) };


	while (window.isOpen()) {
		for (auto & action : actions) {
			action();
		}
		cursorPos = sf::Mouse::getPosition(window);
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		};

		window.clear();
		a1.draw(window);
		window.display();

		//std::cout << a1.getCircle().getGlobalBounds().top + a1.getCircle().getGlobalBounds().height << std::endl;

		sf::sleep(sf::milliseconds(20));
	}
	std::cout << "Terminating application\n";
	return 0;
}
