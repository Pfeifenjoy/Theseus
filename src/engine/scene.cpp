#include "scene.hpp"
#include "game.hpp"
#include "components/drawable.hpp"
#include "gameobject.hpp"

using namespace theseus::engine;

Scene::Scene(Game& game)
{
	mygame = &game;
}

Game& Scene::game()
{
	return *mygame;
}

const Game& Scene::game() const
{
	return *mygame;
}

void Scene::addDrawable(int layer, const components::Drawable* drawable)
{
	drawables[layer].push_back(drawable);
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Sort layer 2 using insertion sort
	/*
	auto& layer2 = drawables[2];
	int size = layer2.size();
	for(int i = 0; i < size; ++i)
	{
		int j = i - 1;
		while(j >= 0 && layer2[j]->getPosition().y > layer2[j+1]->getPosition().y)
		{
			auto tmp = layer2[j];
			layer2[j] = layer2[j+1];
			layer2[j+1] = tmp;
			--j;
		}
	}
	*/

	// Draw!
	for (int i = 0; i < 5; ++i)
	{
		auto& layer = drawables[i];
		for(auto drawable : layer)
		{
			drawable->draw(i, target, states);
		}
	
	}
}

Scene::~Scene(){}
