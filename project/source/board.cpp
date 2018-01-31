#include "board.hpp"

Board::Board(sf::RenderWindow &window):
    boardGrid(Grid(grid_x, grid_y, scale, (grid_x_pixel - 100) / 2 - grid_x * 25, grid_y_pixel / 2 - grid_y * 25)),
    window(window),
    menu_button(Button(std::string("Menu"), 
				sf::Vector2f(static_cast<float>(grid_x_pixel - 50), 25), 
				sf::Vector2f(100, 50), window)),
	tower1_button(Button(std::string("Arno"),
				sf::Vector2f(static_cast<float>(grid_x_pixel - 50), 125), 
				sf::Vector2f(100, 50), window)),
    tower2_button(Button(std::string("Wall"),
                sf::Vector2f(static_cast<float>(grid_x_pixel - 50), 200), 
                sf::Vector2f(100, 50), window)),
	sell_button(Button(std::string("Sell"), 
				sf::Vector2f(static_cast<float>(grid_x_pixel - 50), 275), 
				sf::Vector2f(100, 50), window))
{
    window.create(sf::VideoMode(grid_x_pixel, grid_y_pixel), "EAmpire Tower Defense", sf::Style::Titlebar | sf::Style::Close);

    setup();

    start = sf::Vector2i(0, 0);
    end = sf::Vector2i(9, 9);

    std::cout << "New board created" << std::endl;
    enemy_generator(enemy_queue, 0, 0, 0, 0, 10);
	enemy_generator(enemy_queue, 0, 0, 0, 10, 0);
	enemy_generator(enemy_queue, 0, 0, 10, 0, 0);
	enemy_generator(enemy_queue, 0, 10, 0, 0, 0);
	enemy_generator(enemy_queue, 10, 0, 0, 0, 0);

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

}

void Board::clicked(sf::Vector2i position) {
    if (boardGrid.is_clicked(position.x, position.y)) {
        //auto start_position = boardGrid.get_start_values();
        boardGrid.set_tile_navigability((position.x - boardGrid.get_start_values().first) / scale, 
                                        (position.y - boardGrid.get_start_values().second) / scale, 
                                        !(boardGrid.is_navigable((position.x - boardGrid.get_start_values().first) / scale, 
                                        (position.y - boardGrid.get_start_values().second) / scale)));
    }
}

void Board::draw() {
    window.clear(sf::Color(0, 0, 0)); // Clear screen with a black background.

    boardGrid.draw(window);
    boardGrid.draw_path(window, path);

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

    if (game_state->get_round_state() == "building1" || game_state->get_round_state() == "building2") {
        game_state->draw_sprite("hammer", static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)), window);
        window.setMouseCursorVisible(false);
    } else if (game_state->get_round_state() == "selling") {
        game_state->draw_sprite("sell", static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)), window);
        window.setMouseCursorVisible(false);
    } else {
        window.setMouseCursorVisible(true);
    }

    for (auto&enemy : enemies) {
        enemy.second->draw(window, 50);
    }

    window.display();
}

void Board::update() {
    path = boardGrid.find_path(start, end);
    int enemy_index = 0;
    int temp_size = enemies.size();

    for (auto &action: actions) {
        action();
    }
    
    if (queue_clock.getElapsedTime() >= sf::milliseconds(500)) {
        if (enemy_queue.size()>0) {
            enemies.push_back(enemy_queue.back());
            enemy_queue.pop_back();
        }
        queue_clock.restart();
    }

    for (auto& enemy : enemies) {
        enemy.second->take_damage(boardGrid.get_damage(enemy.second->get_location().x, (enemy.second->get_location().y)));
    }

    for (auto&enemy : enemies) {
        if (enemy.second->check_end_location(path)) {
            enemy.second->take_damage(enemy.second->get_lives());
            game_state->set_lives(game_state->get_lives()-1);
        }
    }
    
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [&](auto& enemy) {return (enemy.second->get_lives() <= 0); }), enemies.end());

    for (auto&enemy : enemies) {
        enemy.second->next_location(path);
    }

	boardGrid.calculate_damage(towers);
    lives.setString(("Lives: " + std::to_string(game_state->get_lives())).c_str());
    currency_amount.setString(("Moneh: " + std::to_string(game_state->get_curreny())).c_str());
}
