#include "drawable.hpp"
#include "../scene.hpp"
#include <iostream>

using namespace theseus::engine;
using namespace theseus::engine::components;

void Drawable::setDrawableOnLayer(int layer, const sf::Drawable* drawable)
{
	if (layers[layer] == nullptr)
		scene().addDrawable(layer, this);
	layers[layer] = drawable;
}

void Drawable::draw(int layer, sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.translate(getPosition());
	target.draw(*layers[layer], states);
}
