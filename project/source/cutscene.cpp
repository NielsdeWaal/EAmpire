#include "cutscene.hpp"

float sleep = 5.0;

cutscene::cutscene(sf::RenderWindow &window): 
                   window(window), 
                   scene1(sf::Vector2f(0, 66.5f), "textures/scene1.png"),
                   scene2(sf::Vector2f(50.0f, 0.0f), "textures/scene2.png"),
                   scene3(sf::Vector2f(0, 19.0f), "textures/scene3.png"),
                   scene4(sf::Vector2f(0, 66.5f), "textures/scene4.png"),
                   scene5(sf::Vector2f(0, 32.0f), "textures/scene5.png"),
                   scene6(sf::Vector2f(0, 56.5f), "textures/scene6.png"),
                   scene7(sf::Vector2f(0, 66.5f), "textures/scene7.png"),
                   scene8(sf::Vector2f(0, 68.5f), "textures/scene8.png"),
                   scene9(sf::Vector2f(0, 68.0f), "textures/scene9.png"),
                   scene10(sf::Vector2f(0, 66.5f), "textures/scene10.png"),
                   scene11(sf::Vector2f(0, 42.5f), "textures/scene11.png"),
                   scene12(sf::Vector2f(0, 42.5f), "textures/scene12.png"),
                   scene13(sf::Vector2f(0, 42.5f), "textures/scene13.png"),
                   scene14(sf::Vector2f(0, 42.5f), "textures/scene14.png"),
                   angry_arni(sf::Vector2f(75.0f,0), "textures/AngryArnoScene.png"),
                   boss_fight1(sf::Vector2f(0,0), "textures/ArnoBossFight.png"),
                   boss_fight2(sf::Vector2f(0, 0), "textures/ArnoBossFight2.png"),
                   end_game1(sf::Vector2f(0, 0), "textures/AfterGameScene1.png"),
                   end_game2(sf::Vector2f(0, 0), "textures/AfterGameScene2.png"),
                   helpscreen(sf::Vector2f(0, 40.5f), "textures/HelpScreen.png")
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
    sf::sleep(sf::seconds(8));
    window.clear();

    scene4.draw(window);
    window.display();
    sf::sleep(sf::seconds(sleep));
    window.clear();

    scene5.draw(window);
    window.display();
    sf::sleep(sf::seconds(1));
    window.clear();

    scene6.draw(window);
    window.display();
    sf::sleep(sf::seconds(2));
    window.clear();

    scene7.draw(window);
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    scene8.draw(window);
    window.display();
    sf::sleep(sf::seconds(10));
    window.clear();

    scene9.draw(window);
    window.display();
    sf::sleep(sf::seconds(sleep));
    window.clear();

    scene10.draw(window);
    window.display();
    sf::sleep(sf::seconds(10));
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
    sf::sleep(sf::seconds(1));
    window.clear();

    scene14.draw(window);
    window.display();
    sf::sleep(sf::seconds(sleep));
    window.clear();
}

void cutscene::angry_arno() {
    angry_arni.draw(window);
    window.display();
    sf::sleep(sf::seconds(5));
    window.clear();
}

void cutscene::boss_fight() {
    boss_fight1.draw(window);
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();

    boss_fight2.draw(window);
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();
}

void cutscene::end_game() {
    end_game1.draw(window);
    window.display();
    sf::sleep(sf::seconds(sleep));
    window.clear();

    end_game2.draw(window);
    window.display();
    sf::sleep(sf::seconds(3));
    window.clear();
}

void cutscene::help_screen() {
    helpscreen.draw(window);
    window.display();
    for (;;) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            window.clear();
            return;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
    }
}