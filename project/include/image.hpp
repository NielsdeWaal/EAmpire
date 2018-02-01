#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class image_from_file {
private:
    sf::Vector2f position;
    sf::Sprite image;
    std::string image_name;
    sf::Texture texture;

public:
    image_from_file(sf::Vector2f position, std::string image_name);

    void draw(sf::RenderWindow&window);
};

#endif //IMAGE_HPP

