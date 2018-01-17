#include "button.hpp"

Button::Button(std::string s, sf::Vector2f location, sf::Vector2f size) {
	setup();
}

void Button::setup() {
	if (!font.loadFromFile("PlayfairDisplay-Black.ttf")) {
		//handle error
	}

	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setString(s);
	text.setPosition(location);

	boundary.setPosition(location);
	boundary.setSize(size);
}

void Button::draw(sf::RenderWindow &window) {
	window.draw(text);
}



bool Button::is_mouse_inside(const sf::Vector2i mouse_pos) const
{
	//return true if mouse is inside rectangle (bounding box)
	return 0;
}