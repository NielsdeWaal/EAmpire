#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button : public sf::Drawable {
private:
	sf::Vector2f position;
	sf::Vector2f size;

	unsigned int state;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


public:
	Button();

	Button(std::string s, sf::Vector2f position);

	~Button();

	sf::Vector2f get_position();
	sf::Vector2f get_size();
	
	unsigned int get_state();

	void set_position(sf::Vector2f position);

	void update(sf::Events& e, sf::RenderWindow& window);


};

#endif //BUTTON_HPP