/**
* @author Philipp Pütz
*/
#include "text.hpp"

using namespace theseus::engine::components;

sf::Font& Text::font()
{
	static bool loaded = false;
	static sf::Font actual_font;
	if (!loaded)
	{
		if (!actual_font.loadFromFile("./resources/fonts/arial.ttf"))
		{
			throw std::invalid_argument("Couldn't load font.");
		}
		loaded = true;
	}
	return actual_font;
}

void Text::setText(int layer, std::string text)
{
	unsetText(layer);
	texts[layer].setFont(font());
	texts[layer].setString(text);
	addDrawable(layer, &texts[layer]);
}

void Text::unsetText(int layer)
{
	removeDrawable(layer, &texts[layer]);
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
