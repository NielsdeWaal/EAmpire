#ifndef factory_hpp
#define factory_hpp

#include <fstream>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "button.hpp"

std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs);

typedef std::shared_ptr<Button> button_ptr;
typedef std::vector<button_ptr> button_vector;

class factory {
private:
	int file_line_counter = 1;
	std::ifstream input;
	sf::Vector2f location;
	sf::Vector2f size;
	std::string& s;
	sf::RenderWindow& window;

public:
	factory(std::string filename);

	button_ptr read_line();

	button_vector buttons_from_file();
};




#endif //factory_hpp
