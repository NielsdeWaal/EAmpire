#include "board.hpp"

Board::Board(sf::RenderWindow &window): 
             boardGrid(Grid(grid_x, grid_y, scale,
                     (grid_x_pixel - 100) / 2 - grid_x * 25,
                     grid_y_pixel / 2 - grid_y * 25)),
             window(window),
             menu_button(
                 Button(std::string("Menu"),
                        sf::Vector2f(static_cast<float>(grid_x_pixel - 50), 25),
                        sf::Vector2f(100, 50), window)),
             tower1_button(
                 Button(std::string("Arno"),
                        sf::Vector2f(static_cast<float>(grid_x_pixel - 50), 125),
                        sf::Vector2f(100, 50), window)),
             tower2_button(
                 Button(std::string("Wall"),
                        sf::Vector2f(static_cast<float>(grid_x_pixel - 50), 200),
                        sf::Vector2f(100, 50), window)),
             sell_button(
                 Button(std::string("Sell"),
                        sf::Vector2f(static_cast<float>(grid_x_pixel - 50), 275),
                        sf::Vector2f(100, 50), window))
{
    window.create(sf::VideoMode(grid_x_pixel, grid_y_pixel),
                  "EAmpire Tower Defense",
                  sf::Style::Titlebar | sf::Style::Close);

    setup();

    start = sf::Vector2i(0, 0);
    end = sf::Vector2i(9, 9);

    std::cout << "New board created" << std::endl;
    /*enemy_generator(enemy_queue, 0, 0, 0, 0, 10);
        enemy_generator(enemy_queue, 0, 0, 0, 10, 0);
        enemy_generator(enemy_queue, 0, 0, 10, 0, 0);
        enemy_generator(enemy_queue, 0, 10, 0, 0, 0);
        enemy_generator(enemy_queue, 10, 0, 0, 0, 0);*/
}

void Board::setup() {
    font.loadFromFile("PlayfairDisplay-Black.ttf");

    lives.setCharacterSize(30);
    lives.setFont(font);
    lives.setFillColor(sf::Color(32, 194, 14));
    lives.setPosition(sf::Vector2f(50, 0));

    currency_amount.setCharacterSize(30);
    currency_amount.setFont(font);
    currency_amount.setFillColor(sf::Color(32, 194, 14));
    currency_amount.setPosition(sf::Vector2f(250, 0));

    current_wave.setCharacterSize(30);
    current_wave.setFont(font);
    current_wave.setFillColor(sf::Color(32, 194, 14));
    current_wave.setPosition(sf::Vector2f(400, 0));

    wave_hint.setCharacterSize(30);
    wave_hint.setFont(font);
    wave_hint.setFillColor(sf::Color(32, 194, 14));
    wave_hint.setPosition(
        sf::Vector2f(50, static_cast<float>(grid_y_pixel - 50)));
    wave_hint.setString("Press Space to summon next wave");
}

void Board::clicked(sf::Vector2i position) {
    if (boardGrid.is_clicked(position.x, position.y)) {
        // auto start_position = boardGrid.get_start_values();
        boardGrid.set_tile_navigability(
            (position.x - boardGrid.get_start_values().first) / scale,
            (position.y - boardGrid.get_start_values().second) / scale,
            !(boardGrid.is_navigable(
                (position.x - boardGrid.get_start_values().first) / scale,
                (position.y - boardGrid.get_start_values().second) / scale)));
    }
}

void Board::next_wave() {
    if (game_state->get_round_state() != "fighting") {
        game_state->set_round_state("fighting");
        game_state->set_action_state("free");
        switch (wave) {
        case 0:
            enemy_generator(enemy_queue, 5);
            break;
        case 1:
            enemy_generator(enemy_queue, 7, 2);
            break;
        case 2:
            enemy_generator(enemy_queue, 2, 5);
            break;
        case 3:
            enemy_generator(enemy_queue, 5, 5, 2);
            break;
        case 4:
            enemy_generator(enemy_queue, 5, 0, 0, 1);
            enemy_generator(enemy_queue, 5, 0, 0, 1);
            break;
        case 5:
            enemy_generator(enemy_queue, 0, 0, 0, 0, 1);
            wave++;
            break;
        case 6:
            std::cout << "GAME OVER" << std::endl;
            break;
        }
        wave++;
    }

    // if (game_state->get_round_state() != "fighting") {
    //    game_state->set_round_state("fighting");
    //    game_state->set_action_state("free");
    //    wave++;
    //    std::cout << "Wave " << wave << " incomming!\n";
    //    enemy_generator(enemy_queue, 10+wave, 5+wave*2);
    //}
}

void Board::calculate_damage(std::vector<tower_ptr> tower_vector,
                             enemy_vector enemies) {
    if (enemies.size() == 0) {
        return;
    }
    for (auto &tower : tower_vector) {
        float shortest_distance = std::numeric_limits<float>::max();
        std::pair<int, std::shared_ptr<Enemy>> shortest_enemy = enemies.front();

        for (auto &enemy : enemies) {
            float delta_x =
                abs(tower->get_loc().x - enemy.second->get_location().x);
            float delta_y =
                abs(tower->get_loc().y - enemy.second->get_location().y);
            float distance = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
            if (distance < shortest_distance) {
                shortest_distance = distance;
                shortest_enemy = enemy;
            }
        }
        shortest_distance -= 1;
        if (shortest_distance < tower->get_radius() && tower->get_damage() > 0) {
            shortest_enemy.second->take_damage(tower->get_damage());
            std::pair<sf::Vertex, sf::Vertex> line(
                sf::Vertex(sf::Vector2f(static_cast<float>(tower->get_loc().x*50+75), static_cast<float>(tower->get_loc().y*50+75))),
                sf::Vertex(sf::Vector2f(shortest_enemy.second->get_location().x*50+75, shortest_enemy.second->get_location().y*50+75)));
            projectiles.emplace(projectiles.begin(), line);
        }
    }
}

void Board::draw_projectiles() {
    for (auto projectile : projectiles) {
        sf::Vertex line[] =
        {
            projectile.first,
            projectile.second
        };
        line[1].color = sf::Color(255,255,255, 0);
        window.draw(line, 2, sf::Lines);
    }
}

void Board::clear_projectiles() {
    projectiles.clear();
}

void Board::draw() {
    window.clear(sf::Color(0, 0, 0)); // Clear screen with a black background.

    boardGrid.draw(window);
    boardGrid.draw_path(window, path);
    boardGrid.draw_selected(window, sf::Mouse::getPosition(window));

    tower1_button.draw();
    tower2_button.draw();
    // tower3_button.draw();
    // tower4_button.draw();
    // tower5_button.draw();
    sell_button.draw();
    menu_button.draw();
    // play_button.draw();

    window.draw(lives);
    window.draw(currency_amount);
    window.draw(current_wave);
    if (game_state->get_round_state() == "building") {
        window.draw(wave_hint);
    }

    if (game_state->get_action_state() == "building1" ||
        game_state->get_action_state() == "building2") {
        game_state->draw_sprite(
            "hammer", static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)),
            window);
        window.setMouseCursorVisible(false);
    } else if (game_state->get_action_state() == "selling") {
        game_state->draw_sprite(
            "sell", static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)),
            window);
        window.setMouseCursorVisible(false);
    } else {
        window.setMouseCursorVisible(true);
    }

    for (auto &enemy : enemies) {
        enemy.second->draw(window, 50);
    }

    draw_projectiles();

    window.display();
}

void Board::update() {
    path = boardGrid.find_path(start, end);
    int enemy_index = 0;
    int temp_size = enemies.size();

    for (auto &action : actions) {
        action();
    }

    if (queue_clock.getElapsedTime() >= sf::milliseconds(500)) {
        if (enemy_queue.size() > 0) {
            enemies.push_back(enemy_queue.back());
            enemy_queue.pop_back();
        }
        queue_clock.restart();
    }

    if (tower_clock.getElapsedTime() >= sf::milliseconds(500)) {
        clear_projectiles();
        calculate_damage(towers, enemies);
        tower_clock.restart();
    }

    // TODO Maybe combine these 4 enemy loops into 1?
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
                                 [&](auto &enemy) {
                                     return (enemy.second->get_lives() <= 0);
                                 }),
                  enemies.end());
    for (auto &enemy : enemies) {
        if (enemy.second->check_end_location(path)) {
            enemy.second->take_damage(enemy.second->get_lives());
            game_state->set_lives(game_state->get_lives() -
                                  enemy.second->get_damage());
        }
    }
    for (auto &enemy : enemies) {
        enemy.second->next_location(path);
    }

    if (game_state->get_round_state() == "fighting" && enemies.size() == 0 &&
        enemy_queue.size() == 0) {
        game_state->add_currency(150);
        game_state->set_round_state("building");
    }

    lives.setString(
        ("Lives: " + std::to_string(game_state->get_lives())).c_str());
    currency_amount.setString(
        ("$: " + std::to_string(game_state->get_curreny())).c_str());
    current_wave.setString(("Wave: " + std::to_string(wave)).c_str());
}
