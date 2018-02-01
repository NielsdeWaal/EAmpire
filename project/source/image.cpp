#include "image.hpp"

image_from_file::image_from_file(sf::Vector2f position, std::string image_name): 
                                 position(position), 
                                 image_name(image_name) 
{
    if (!texture.loadFromFile(image_name)) {
        std::cout << "Image doet het niet :(" << std::endl;
    }
    image.setTexture(texture);
}

void image_from_file::draw(sf::RenderWindow &window) {
    image.setPosition(position);
    window.draw(image);
}
