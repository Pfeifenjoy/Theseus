#include "button.hpp"
#include <SFML/Graphics.hpp>

using namespace theseus::gameobjects;
using namespace theseus::engine;

Button::Button(std::string text, sf::Vector2f position, sf::Color textcolor)
{
	setPosition(position);
	setText(4, text);
	setColor(4, textcolor);

}

Button::~Button() {}
