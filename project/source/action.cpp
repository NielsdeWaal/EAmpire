#include "action.hpp"

action::action(std::function< bool() > condition, std::function< void() > work) :
	condition(condition),
	work(work)
{}

action::action(sf::Keyboard::Key key, std::function< void() > work) :
	condition(
		[key]()->bool { return sf::Keyboard::isKeyPressed(key); }
	),
	work(work)
{}

action::action(sf::Mouse::Button button, std::function< void() > work) :
	condition(
		[button]()->bool { return sf::Mouse::isButtonPressed(button); }
	),
	work(work)
{}

void action::operator()() {
	if (condition()) {
		work();
	}
}
