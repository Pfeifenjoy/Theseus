#include "drawable.hpp"
#include "../scene.hpp"
#include <functional>

using namespace std;
using namespace std::placeholders;
using namespace theseus::engine;
using namespace theseus::engine::components;

Drawable::Drawable()
{
	evRegisterComponents.subscribe(bind(&Drawable::onRegisterComponents, this, _1));
	evUnregisterComponents.subscribe(bind(&Drawable::onUnregisterComponents, this, _1));
	evUpdateComponentRegistrations.subscribe(bind(&Drawable::onUpdateRegistration, this, _1));
}

void Drawable::onRegisterComponents(Scene& scene)
{
	for(int i = 0; i < 5; ++i)
	{
		if (layers[i] != nullptr)
			scene.registerDrawable(i, this);
	}
	positionInSync = getPosition();
}

void Drawable::onUpdateRegistration(Scene& scene)
{
	if (positionInSync != getPosition())
	{
		auto oldPosition = positionInSync;
		positionInSync  = getPosition();
		for(int i = 0; i < 5; ++i)
		{
			if (layers[i] != nullptr)
				scene.reRegisterDrawable(i, oldPosition, this);
		}
	}
}

void Drawable::onUnregisterComponents(Scene& scene)
{
	for(int i = 0; i < 5; ++i)
	{
		if (layers[i] != nullptr)
			scene.unregisterDrawable(i, positionInSync, this);
	}
}

void Drawable::activateLayer(int layer, const sf::Drawable* drawable)
{
	layers[layer] = drawable;
}

void Drawable::draw(int layer, sf::RenderTarget& target, sf::RenderStates states) const
{
	if (layers[layer] != nullptr)
	{
		states.transform.translate(getPosition());
		target.draw(*layers[layer], states);
	}
}

Drawable::~Drawable()
{}
