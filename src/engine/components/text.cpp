/**
* @author Philipp Pütz
*/
#include "text.hpp"

using namespace theseus::engine::components;

void Text::setText(int layer, std::string text)
{
	if (!font.loadFromFile("./resources/fonts/arial.ttf"))
	{
		throw std::invalid_argument("Couldn't load font.");
	}
	else
	{
		texts[layer].setFont(font);
		texts[layer].setString(text);
		activateLayer(layer, &texts[layer]);
	}

}

void Text::setColor(int layer, sf::Color color)
{
	texts[layer].setColor(color);
}

void Text::setStyle(int layer, sf::Text::Style style)
{
	texts[layer].setStyle(style);
}


void Text::setCharSize(int layer, int textSize)
{
	texts[layer].setCharacterSize(textSize);
}

int  Text::getTextWidth(int layer)
{
	return texts[layer].getLocalBounds().width;
}


sf::Text& Text::text(int layer)
{
	return texts[layer];
}

Text::~Text()
{}
