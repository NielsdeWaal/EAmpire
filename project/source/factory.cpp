#include "factory.hpp"

factory::factory(std::string filename, sf::RenderWindow& window):
	s(s),
	window(window)
{
	if (input.is_open()) {
		input.close();
	}
	input.open(filename);
}

button_ptr factory::read_line() {
	std::string name;
	sf::Vector2f location;
	sf::Vector2f size;

	input >> name;
	input >> location;
	input >> size;

	return button_ptr(new Button(name, location, size, window));
}

button_vector factory::buttons_from_file() {
	file_line_counter = 1;
	button_vector buttons;
	for (;;) {
		try {
			buttons.push_back(read_line());
		}
		catch (const std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		file_line_counter++;
	}

	return buttons;
}

std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs) {
	char c;

	input >> c;

	input >> c;

	return input;
}