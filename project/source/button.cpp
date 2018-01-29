#include "button.hpp"

Button::Button(const std::string s, sf::Vector2f location, sf::Vector2f size,
               sf::RenderWindow &window): 
               s(s), 
               location(location), 
               size(size), 
               window(window) 
{
    setup();
}

void Button::setup() {
    if (!font.loadFromFile("PlayfairDisplay-Black.ttf")) {
        // handle error
        std::cout << "File not loaded" << std::endl;
    }
    font.loadFromFile("PlayfairDisplay-Black.ttf");

    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setString(s);
    text.setOrigin(size.x / 2, size.y / 2);
    text.setPosition(location.x + 2, location.y + 2);

    boundary.setPosition(location);
    boundary.setOrigin(size.x / 2, size.y / 2);
    boundary.setSize(size);
    boundary.setFillColor(sf::Color::Green);
}

void Button::draw() {
    window.draw(boundary);
    window.draw(text);
}

sf::Vector2f Button::get_location() {
    return location;
}

sf::Vector2f Button::get_size() {
    return size;
}

bool Button::is_pressed() {
    if (boundary.getGlobalBounds().contains(
            sf::Vector2f{float(sf::Mouse::getPosition(window).x),
                         float(sf::Mouse::getPosition(window).y)})) {
        while (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            boundary.setFillColor(sf::Color(0, 255, 200));
            this->draw();
            window.display();
        }
        boundary.setFillColor(sf::Color::Green);
        return true;
    }
    return false;
}
