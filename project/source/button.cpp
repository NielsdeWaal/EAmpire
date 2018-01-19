#include "button.hpp"

/// \brief		Button constructor
/// \details	This constructor is called when creating a clickable button screen object. Window needs to be passed as an argument, because 
///				it is used in the function that checks whether or not the mouse is over the button.
/// \param		std::string s : std::string s - Contains the text displayed on the button
///	
Button::Button(std::string& s, sf::Vector2f location, sf::Vector2f size, sf::RenderWindow& window):
	s(s),
	location(location),
	size(size),
	window(window)
{
	setup();
}

/// \brief Button setup function
/// \details This function initializes the button. It is called in the constructor.
///
void Button::setup() {
	if (!font.loadFromFile("PlayfairDisplay-Black.ttf")) {
		//handle error
		std::cout << "File not loaded" << std::endl;
	}
	font.loadFromFile("PlayfairDisplay-Black.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setString(s);
	text.setPosition(location.x+2,location.y+2);

	boundary.setPosition(location);
	boundary.setSize(size);
	boundary.setFillColor(sf::Color::Green);
}

/// \brief		Draw function
/// \details	This function draws the button objects to the buffer, window.display() then displays them
///
void Button::draw() {
	window.draw(boundary);
	window.draw(text);
}

/// \brief		Get location function for button
/// \ details	This function returns the coordinates of the top left corner of the button
/// \return		The top left corner coordinate of the button in the form of a Vector2F
sf::Vector2f Button::get_location() {
	return location;
}

/// \brief		Get size function for button
/// \ details	This function returns the coordinates of the bottom right corner of the button
/// \return		The bottom right corner coordinate of the button in the form of a Vector2F
sf::Vector2f Button::get_size() {
	return size;
}


/// \brief		Function to check if button is pressed
/// \brief		This function checks if the mouse is in the bounding box of the button when it's clicked
///				It changes the colour of the button as a form of click-feedback
/// \return		This function returns TRUE if the button was in the bounding box, FALSE if it wasn't
bool Button::is_pressed() {
	if (boundary.getGlobalBounds().contains(sf::Vector2f{ float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y) })) {
		while (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			boundary.setFillColor(sf::Color (0,255,200));
			this->draw();
			window.display();
		}
		boundary.setFillColor(sf::Color::Green);
		return true;
	}
	return false;
}