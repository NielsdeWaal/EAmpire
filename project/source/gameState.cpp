#include "gameState.hpp"

GameState *GameState::instance = 0;

GameState *GameState::get_state() {
    if (instance == 0) {
        instance = new GameState();
    }

    return instance;
}

int GameState::get_lives() {
    return lives;
}

void GameState::set_lives(int amount) {
    lives = amount;
}

int GameState::get_curreny() {
    return curreny_amount;
}

void GameState::set_curreny(int amount) {
    curreny_amount = amount;
}

void GameState::add_currency(int amount) {
    curreny_amount += amount;
}


GameState::GameState()
{}

void GameState::load_sprites(std::map<std::string, std::string> files) {
	for (std::map<std::string, std::string>::iterator it = files.begin(); it != files.end(); ++it) {
		textures.insert(std::pair<std::string, sf::Texture>(it->first, sf::Texture()));
		textures.find(it->first)->second.loadFromFile(it->second);
		sprites.insert(std::pair<std::string, sf::Sprite>(it->first, sf::Sprite()));
		sprites.find(it->first)->second.setTexture(textures.find(it->first)->second);
	}
}

void GameState::draw_sprite(std::string name, sf::Vector2f position, sf::RenderWindow &window) {
	sprites.find(name)->second.setPosition(position);
	window.draw(sprites.find(name)->second);
}

void GameState::set_action_state(std::string state) {
    action_state = state;
}

std::string GameState::get_action_state() {
    return action_state;
}

void GameState::set_round_state(std::string state) {
    round_state = state;
    std::cout << "Round state set to:" << state << std::endl;
}

std::string GameState::get_round_state() {
    return round_state;
}

void GameState::set_game_state(std::string state) {
    game_state = state;
}

std::string GameState::get_game_state() {
    return game_state;
}