#include "gameobject.hpp"
#include "scene.hpp"
#include "game.hpp"

using namespace theseus::engine;

GameObject::GameObject(Scene& scene)
{
	myscene = &scene;
}

GameObject::~GameObject(){}
