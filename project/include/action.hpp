#ifndef _ACTION_HPP
#define _ACTION_HPP
#include <SFML/Graphics.hpp>
#include <functional>
class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;

public:
	action(std::function<bool()> condition, std::function< void()> work);
	action(sf::Keyboard::Key key, std::function< void()> work);
	action(sf::Mouse::Button button, std::function<void()> work);
	action(std::function< void() > work);
	
	void operator()();
};
#endif // !_ACTION_HPP
