#include "drawable.hpp"
#include "../scene.hpp"
#include <functional>
#include <algorithm>

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
		registeredLayers[i] = !layers[i].empty();
		if (registeredLayers[i])
		{
			scene.registerDrawable(i, this);
		}
	}
	positionInSync = getPosition();
}

void Drawable::onUpdateRegistration(Scene& scene)
{
	// Update registered positions
	if (positionInSync != getPosition())
	{
		auto oldPosition = positionInSync;
		positionInSync  = getPosition();
		for(int i = 0; i < 5; ++i)
		{
			if (registeredLayers[i])
				scene.reRegisterDrawable(i, oldPosition, this);
		}
	}

	// update which layers are registered for drawing 
	for (int i = 0; i < 5; ++i)
	{
		if (registeredLayers[i] && layers[i].empty())
		{
			registeredLayers[i] = false;
			scene.unregisterDrawable(i, positionInSync, this);
		}
		else if (!registeredLayers[i] && !layers[i].empty())
		{
			registeredLayers[i] = true;
			scene.registerDrawable(i, this);
		}
	}
}

void Drawable::onUnregisterComponents(Scene& scene)
{
	for(int i = 0; i < 5; ++i)
	{
		if (registeredLayers[i])
			scene.unregisterDrawable(i, positionInSync, this);
	}
}

void Drawable::addDrawable(int layer, const sf::Drawable* drawable)
{
	layers[layer].push_back(drawable);	
}

void Drawable::removeDrawable(int layer, const sf::Drawable* drawable)
{
	auto& l = layers[layer];
	l.erase(remove(l.begin(), l.end(), drawable), l.end());
	// https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
}

void Drawable::draw(int layer, sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.translate(getPosition());
	for (auto drawable : layers[layer])
	{
		target.draw(*drawable, states);
	}
}

Drawable::~Drawable()
{}
