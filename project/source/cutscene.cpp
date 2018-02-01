#include "cutscene.hpp"

float sleep = 6.0;

cutscene::cutscene(sf::RenderWindow &window): 
                   window(window), 
                   scene1(sf::Vector2f(0, 0), "textures/scene1.png"),
                   scene2(sf::Vector2f(0, 0), "textures/scene2.png"),
                   scene3(sf::Vector2f(0, 0), "textures/scene3.png"),
                   scene4(sf::Vector2f(0, 0), "textures/scene4.png"),
                   scene5(sf::Vector2f(0, 0), "textures/scene5.png"),
                   scene6(sf::Vector2f(0, 0), "textures/scene6.png"),
                   scene7(sf::Vector2f(0, 0), "textures/scene7.png"),
                   scene8(sf::Vector2f(0, 0), "textures/scene8.png"),
                   scene9(sf::Vector2f(0, 0), "textures/scene9.png"),
                   scene10(sf::Vector2f(0, 0), "textures/scene10.png"),
                   scene11(sf::Vector2f(0, 0), "textures/scene11.png"),
                   scene12(sf::Vector2f(0, 0), "textures/scene12.png"),
                   scene13(sf::Vector2f(0, 0), "textures/scene13.png"),
                   scene14(sf::Vector2f(0, 0), "textures/scene14.png") 
{}

void cutscene::play_scene() {
    scene1.draw(window);
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene2.draw(window);
    window.display();
    sf::sleep(sf::seconds(sleep));
    window.clear();

    scene3.draw(window);
    window.display();
    sf::sleep(sf::seconds(10));
    window.clear();

    scene4.draw(window);
    window.display();
    sf::sleep(sf::seconds(sleep));
    window.clear();

    scene5.draw(window);
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene6.draw(window);
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene7.draw(window);
    window.display();
    sf::sleep(sf::seconds(sleep));
    window.clear();

    scene8.draw(window);
    window.display();
    sf::sleep(sf::seconds(15));
    window.clear();

    scene9.draw(window);
    window.display();
    sf::sleep(sf::seconds(sleep));
    window.clear();

    scene10.draw(window);
    window.display();
    sf::sleep(sf::seconds(15));
    window.clear();

    scene11.draw(window);
    window.display();
    sf::sleep(sf::seconds(sleep));
    window.clear();

    scene12.draw(window);
    window.display();
    sf::sleep(sf::seconds(sleep));
    window.clear();

    scene13.draw(window);
    window.display();
    sf::sleep(sf::seconds(2));
    window.clear();

    scene14.draw(window);
    window.display();
    sf::sleep(sf::seconds(sleep));
    window.clear();
}
