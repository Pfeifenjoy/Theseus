#include "drawable.hpp"
#include "../scene.hpp"
#include <functional>

using namespace theseus::engine;
using namespace theseus::engine::components;

Drawable::Drawable()
{
	baseInitialized.setCallback(std::function<void(Drawable*)>(&Drawable::onBaseInitialized), this);
	evBaseInitialized.subscribe(baseInitialized);
}

void Drawable::onBaseInitialized()
{
	for(int i = 0; i < 5; ++i)
	{
		if (layers[i] != nullptr)
			scene().addDrawable(i, this);
	}
}

void Drawable::setDrawableOnLayer(int layer, const sf::Drawable* drawable)
{
	if (layers[layer] == nullptr && isInitialized())
		scene().addDrawable(layer, this);
	layers[layer] = drawable;
}

void Drawable::draw(int layer, sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.translate(getPosition());
	target.draw(*layers[layer], states);
}
