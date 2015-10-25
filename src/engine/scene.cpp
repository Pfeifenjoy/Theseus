#include "scene.hpp"
#include "components/drawable.hpp"
#include "components/update.hpp"
#include "components/keyboardinput.hpp"
#include "gameobject.hpp"

using namespace std;
using namespace theseus::engine;

void Scene::addGameObject(std::unique_ptr<GameObject> gameObject)
{
	gameObject->registerComponents(*this);
	gameObjects.push_back(move(gameObject));
}

void Scene::registerDrawable(int layer, const components::Drawable* drawable)
{
	drawables[layer].push_back(drawable);
}

void Scene::registerUpdate(components::Update * updateComponent)
{
	update.push_back(updateComponent);
}

void Scene::registerKeyboardInput(components::KeyboardInput * keyboardComponent)
{
	keyboardInput.push_back(keyboardComponent);
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

void Scene::handleUpdateEvent(float timePassed)
{
	for (auto needsUpdate : update)
	{
		needsUpdate->doUpdate(timePassed);
	}
}

void Scene::handleKeyDownEvent(sf::Keyboard::Key key)
{
	for (auto deliverTo : keyboardInput)
	{
		deliverTo->handleKeyDown(key);	
	}
}

Scene::~Scene(){}
