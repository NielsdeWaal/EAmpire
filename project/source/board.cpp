#include "board.hpp"

Board::Board(sf::RenderWindow &window):
    boardGrid(Grid(grid_x, grid_y, scale, (grid_x_pixel - 100) / 2 - grid_x * 25, grid_y_pixel / 2 - grid_y * 25)),
    window(window),
    menu_button(Button(std::string("Menu"), 
				sf::Vector2f(static_cast<float>(grid_x_pixel - 50), 25), 
				sf::Vector2f(100, 50), window)),
	tower1_button(Button(std::string("Tower1"),
				sf::Vector2f(static_cast<float>(grid_x_pixel - 50), 100), 
				sf::Vector2f(100, 50), window)),
	sell_button(Button(std::string("Sell"), 
				sf::Vector2f(static_cast<float>(grid_x_pixel - 50), 175), 
				sf::Vector2f(100, 50), window))
{
    window.create(sf::VideoMode(grid_x_pixel, grid_y_pixel), "EAmpire Tower Defense", sf::Style::Titlebar | sf::Style::Close);

    setup();

    currency_amount.setFont(font);
    currency_amount.setPosition(sf::Vector2f(250, 0));

    start = sf::Vector2i(0, 0);
    end = sf::Vector2i(9, 9);

    std::cout << "New board created" << std::endl;
}

void Board::setup() {
    font.loadFromFile("PlayfairDisplay-Black.ttf");

    lives.setCharacterSize(30);
    lives.setFont(font);
    lives.setFillColor(sf::Color::White);
    //lives.setString("Lives??");
    lives.setPosition(sf::Vector2f(50, 0));

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
    window.clear(sf::Color(100, 100, 100)); // Clear screen with a grey background.

    boardGrid.draw(window);
    boardGrid.draw_path(window, path);

    tower1_button.draw();
    // tower2_button.draw();
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

    if (game_state->get_round_state() == "building") {
        game_state->draw_sprite("hammer", static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)), window);
        window.setMouseCursorVisible(false);
    } else if (game_state->get_round_state() == "selling") {
        game_state->draw_sprite("sell", static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)), window);
        window.setMouseCursorVisible(false);
    } else {
        window.setMouseCursorVisible(true);
    }

    window.display();
}

void Board::update() {
    path = boardGrid.find_path(start, end);

    for (auto &action: actions) {
        action();
    }

    //for (auto& enemy : enemies ) {
    //  enemy.take_damage(boardGrid.get_damage(enemy.get_location().x - boardGrid.get_start_x()) / 50,enemy.get_location().y - boardGrid.get_start_y()) / 50)):
    //}

	boardGrid.calculate_damage(towers);
    lives.setString(("Lives: " + std::to_string(game_state->get_lives())).c_str());
    currency_amount.setString(("Moneh: " + std::to_string(game_state->get_curreny())).c_str());
}
