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
    enemy_generator(enemy_queue, 10, 20);
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
    window.clear(sf::Color(0, 0, 0)); // Clear screen with a grey background.

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
    //std::cout << "Komen we hier?" << std::endl;

    window.draw(lives);
    window.draw(currency_amount);
    

    //      for (const auto & enemy : container.get_container()) {
    //	enemy.second->draw(window);
    //	if (!enemy.second->next_location(path, grid)) {
    //		container.remove(enemy.first);
    //		//std::cout << "end of path" << std::endl;
    //	}
    //}

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
        //enemy.second->next_location(path);
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
    
    for (auto&enemy : enemies) {
        enemy.second->next_location(path);
    }

    if (queue_clock.getElapsedTime() >= sf::milliseconds(500)) {
        if (enemy_queue.size()>0) {
            enemies.emplace_back(enemy_queue.end());
            enemy_queue.pop_back();
        }
        queue_clock.restart();
    }

    //for (auto it = enemies.begin(), end = enemies.end(); it != end; ++it)
    //{
    //    for (auto it2 = enemies.begin(); it2 != (it + 1); ++it2)
    //    {
    //        it2->second->next_location(path);
    //        
    //    }
    //    //std::cout << "\n";
    //}

    //for (auto& enemy : enemies ) {
    //    //enemy_index -= (temp_size - enemies.size());
    //    //temp_size = enemies.size();

    //    if (enemy.second->check_end_location(path)) {
    //        enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy));
    //    }
    //    else{
    //        std::cout << enemy.second->get_location().x << ',' << enemy.second->get_location().y << std::endl;
    //        enemy.second->take_damage(boardGrid.get_damage(enemy.second->get_location().x ,(enemy.second->get_location().y )));
    //        enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [&](auto enemy) {return ((enemy.second->get_lives() <= 0)); }), enemies.end());
    //    }
    //}

	boardGrid.calculate_damage(towers);
    lives.setString(("Lives: " + std::to_string(game_state->get_lives())).c_str());
    currency_amount.setString(("Moneh: " + std::to_string(game_state->get_curreny())).c_str());
}
