#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button {
private:
	std::string s;
	sf::Vector2f location;
	sf::Font font;
	sf::Text text;
	sf::Vector2f size;

	sf::RectangleShape boundary;

public:

	Button(std::string s, sf::Vector2f location, sf::Vector2f size);

	void draw(sf::RenderWindow& window);

	void setup();

	bool is_mouse_inside(const sf::Vector2i mouse_pos) const;
};

#endif //BUTTON_HPP
