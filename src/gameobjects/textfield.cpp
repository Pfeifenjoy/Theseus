/**
 * @author Philipp Pütz
 */
#include "textfield.hpp"
#include <SFML/Graphics.hpp>

using namespace theseus::gameobjects;
using namespace theseus::engine;

Textfield::Textfield(std::string text, sf::Color textcolor)
{
	setText(4, text);
	setColor(4, textcolor);

}

int Textfield::getTextWidth()
{
	return Text::getTextWidth(4);
}

void Textfield::setCharSize(int size)
{
	Text::setCharSize(4, size);
}


Textfield::~Textfield() {}
