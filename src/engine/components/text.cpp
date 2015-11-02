#include "text.hpp"

using namespace theseus::engine::components;

void Text::setText(int layer, std::string text)
{	
	if (!font.loadFromFile("./resources/fonts/arial.ttf"))
	{
		throw std::invalid_argument("Couldn't load font.");
	}
	else{
		texts[layer].setFont(font);
		texts[layer].setString(text);
		activateLayer(layer, &texts[layer]);
	}

}

void Text::setColor(int layer, sf::Color color)
{
	texts[layer].setColor(color);
}


sf::Text& Text::text(int layer)
{
	return texts[layer];
}

Text::~Text()
{}
