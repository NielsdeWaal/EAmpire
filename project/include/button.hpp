#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
private:
	std::string& s;
	sf::Vector2f location;
	sf::Font font;
	sf::Text text;
	sf::Vector2f size;
	sf::RenderWindow& window;
	sf::RectangleShape boundary;

public:

	Button(std::string& s, sf::Vector2f location, sf::Vector2f size, sf::RenderWindow& window);

	void draw();

	void setup();

	bool is_pressed();

	sf::Vector2f get_location();

	sf::Vector2f get_size();
};

#endif //BUTTON_HPP
