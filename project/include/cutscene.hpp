#ifndef CUTSCENE_HPP
#define CUTSCENE_HPP

#include <SFML/Graphics.hpp>
#include "image.hpp"

class cutscene {
private:
    sf::RenderWindow & window;
    image_from_file scene1;
    image_from_file scene2;
    image_from_file scene3;
    image_from_file scene4;
    image_from_file scene5;
    image_from_file scene6;
    image_from_file scene7;
    image_from_file scene8;
    image_from_file scene9;
    image_from_file scene10;
    image_from_file scene11;
    image_from_file scene12;
    image_from_file scene13;
    image_from_file scene14;
public:
    cutscene(sf::RenderWindow & window);

    void play_scene();
};


#endif //CUTSCENE_HPP
