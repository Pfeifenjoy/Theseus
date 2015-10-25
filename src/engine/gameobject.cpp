#include "gameobject.hpp"

using namespace theseus::engine;

GameObject::~GameObject(){}

void GameObject::registerComponents(Scene& scene)
{
	evRegisterComponents(scene);
}

void GameObject::unregisterComponents(Scene& scene)
{
	evUnregisterComponents(scene);
}
