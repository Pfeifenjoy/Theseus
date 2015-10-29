#include "scene.hpp"
#include "components/drawable.hpp"
#include "components/update.hpp"
#include "components/keyboardinput.hpp"
#include "gameobject.hpp"
#include <algorithm>

using namespace std;
using namespace theseus::engine;

void Scene::addGameObject(std::unique_ptr<GameObject> gameObject)
{
	gameObject->registerComponents(*this);
	gameObjects.push_back(move(gameObject));
}

unique_ptr<GameObject> Scene::removeGameObject(GameObject* gameObject)
{
	// find the game object in the list of all game objects.
	auto found = gameObjects.end();
	for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		if (it->get() == gameObject)
		{
			found = it;
			break;
		}
	}

	// stop at this point if the requested game object was not found.
	if (found == gameObjects.end())
		return nullptr;
	
	// remove the game object from the list of all game objects
	unique_ptr<GameObject> result = move(*found);
	gameObjects.erase(found);
	
	// unregister the components
	result->unregisterComponents(*this);
	
	// return
	// if the caller picks up the returned smart pointer,
	// he becomes its owner.
	// If not, the corresponding memory will be freed automatically.
	return result;
}

void Scene::registerDrawable(int layer, const components::Drawable* drawable)
{
	drawables[layer].push_back(drawable);
}

void Scene::unregisterDrawable(const components::Drawable* drawable)
{
	for (int i = 0; i < 5; ++i)
	{
		auto& layer = drawables[i];
		layer.erase(remove(layer.begin(), layer.end(), drawable), layer.end());
		// https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
	}
}

void Scene::registerUpdate(components::Update * updateComponent)
{
	update.push_back(updateComponent);
}
		
void Scene::unregisterUpdate(components::Update * component)
{
	update.erase(remove(update.begin(), update.end(), component), update.end());
}

void Scene::registerKeyboardInput(components::KeyboardInput * keyboardComponent)
{
	keyboardInput.push_back(keyboardComponent);
}

void Scene::unregisterKeyboardInput(components::KeyboardInput * component)
{
	keyboardInput.erase(remove(keyboardInput.begin(), keyboardInput.end(), component), keyboardInput.end());
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
