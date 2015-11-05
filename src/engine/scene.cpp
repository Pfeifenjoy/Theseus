#include "scene.hpp"
#include "components/base.hpp"
#include "components/drawable.hpp"
#include "components/update.hpp"
#include "components/keyboardinput.hpp"
#include "components/solide.hpp"
#include "components/collisiondetector.hpp"
#include "components/camera.hpp"
#include "gameobject.hpp"
#include <algorithm>
#include <vector>

using namespace std;
using namespace theseus::engine;

const float MAX_GAMEOBJECT_W = 200;
const float MAX_GAMEOBJECT_H = 200;

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

	// ...and from the list of game objects that might need to update their registration
	auto position = needsRegistrationUpdate.find(result.get());
	if (position != needsRegistrationUpdate.end())
	{
		needsRegistrationUpdate.erase(position);
	}

	// unregister the components
	result->unregisterComponents(*this);
	
	// return
	// if the caller picks up the returned smart pointer,
	// he becomes its owner.
	// If not, the corresponding memory will be freed automatically.
	return result;
}

void Scene::setCamera(const components::Camera * camera)
{
	activeCamera = camera;
}

void Scene::registerDrawable(int layer, const components::Drawable* drawable)
{
	drawables[layer].insert(drawable->getPosition(), drawable);
}

void Scene::unregisterDrawable(int layer, sf::Vector2f position, const components::Drawable* drawable)
{
	drawables[layer].remove(position, drawable);
}

void Scene::reRegisterDrawable(int layer, sf::Vector2f oldPosition, const components::Drawable* drawable)
{
	drawables[layer].updatePosition(oldPosition, drawable->getPosition(), drawable);
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

void Scene::registerSolide(components::Solide * component)
{
	solide.insert(component->getPosition(), component);
}

void Scene::unRegisterSolide(sf::Vector2f position, components::Solide * component)
{
	solide.remove(position, component);
}

void Scene::reRegisterSolide(sf::Vector2f oldPosition, components::Solide * component)
{
	solide.updatePosition(oldPosition, component->getPosition(), component);
}

void Scene::checkCollisions(components::CollisionDetector* component)
{
	// The collision area is the area of the given component that is checked against
	// collisions with other solide game objects.
	auto collisionArea_tl = component->getAbsoluteCollisionAreaTopLeft();
	auto collisionArea_br = component->getAbsoluteCollisionAreaBottomRight();
	
	// all solide game objects that are near to the collision area are candidates that
	// could possibly collide with the collision area.
	sf::Vector2f checkArea_tl;
	sf::Vector2f checkArea_br;
	checkArea_tl.x = collisionArea_tl.x - MAX_GAMEOBJECT_W;
	checkArea_tl.y = collisionArea_tl.y - MAX_GAMEOBJECT_H;
	checkArea_br.x = collisionArea_br.x + MAX_GAMEOBJECT_W;
	checkArea_br.y = collisionArea_br.y + MAX_GAMEOBJECT_H;
	auto candidates = solide.find(checkArea_tl, checkArea_br);

	// check all candidates for a collision.
	for (auto result : candidates)
	{
		auto otherCollisionArea_tl = result.second->getAbsoluteCollisionAreaTopLeft();
		auto otherCollisionArea_br = result.second->getAbsoluteCollisionAreaBottomRight();
		if (collisionArea_tl.x < otherCollisionArea_br.x 			// the collision-candidate is not completely left to the collision area 
				&& collisionArea_br.x > otherCollisionArea_tl.x 	// the collision-candidate is not completely right to the collision area
				&& collisionArea_br.y > otherCollisionArea_tl.y  	// the collision-candidate is not completely under the collision area
				&& collisionArea_tl.y < otherCollisionArea_br.y 	// the collision-candidate is not completely above the collision area
				&& component != result.second) 				// exclude "self-collisions"
		{
			// collision detected!
			needsRegistrationUpdate.insert(component);
			component->handleCollision(*result.second);
		}
	}
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::View view;
	
	if (activeCamera != nullptr)
	{
		view = activeCamera->view();
		view.move(activeCamera->getPosition());
	}
	else
	{
		view = target.getDefaultView();
	}

	sf::Vector2f drawArea_lt(view.getCenter().x - view.getSize().x / 2 - MAX_GAMEOBJECT_W
			, view.getCenter().y - view.getSize().y / 2 - MAX_GAMEOBJECT_H);

	sf::Vector2f drawArea_rb(view.getCenter().x + view.getSize().x / 2 + MAX_GAMEOBJECT_W
			, view.getCenter().y + view.getSize().y / 2 + MAX_GAMEOBJECT_H);

	target.setView(view);

	// Draw!
	for (int i = 0; i < 5; ++i)
	{
		auto objectsToDraw = drawables[i].find(drawArea_lt, drawArea_rb); 
		if (i == 3)
		{
			// layer 2 has to be sorted first
			vector<const components::Drawable *> layer2;
			for(auto drawable : objectsToDraw)
			{
				layer2.push_back(drawable.second);
			}
			sort(layer2.begin(), layer2.end(), [](const components::Drawable * first, const components::Drawable * second)->bool{
					return first->getPosition().y < second->getPosition().y;
					});
			for (auto drawable : layer2)
			{
				drawable->draw(i, target, states);
			}
			
		}
		else
		{
			for(auto drawable : objectsToDraw)
			{
				drawable.second->draw(i, target, states);
			}
		}
	
	}
}

void Scene::handleUpdateEvent(float timePassed)
{
	// create update events
	for (auto it = update.begin(); it < update.end(); ++it)
	{
		auto needsUpdate = *it;
		needsRegistrationUpdate.insert(needsUpdate);
		needsUpdate->doUpdate(timePassed);
	}

	// do reregistration stuff
	swap(needsRegistrationUpdate, needsRegistrationUpdate_previous);
	while (!needsRegistrationUpdate_previous.empty())
	{
		auto position = needsRegistrationUpdate_previous.begin();
		auto element = *position;	
		needsRegistrationUpdate_previous.erase(position);
		element->refreshComponentRegistrations(*this);
	}
}

void Scene::handleKeyDownEvent(sf::Keyboard::Key key)
{
	for (auto it = keyboardInput.begin(); it < keyboardInput.end(); ++it)
	{
		auto deliverTo = *it;
		needsRegistrationUpdate.insert(deliverTo);
		deliverTo->handleKeyDown(key);	
	}
}

Scene::~Scene(){}
