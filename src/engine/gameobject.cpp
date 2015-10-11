#include "gameobject.hpp"
#include "scene.hpp"
#include "game.hpp"

using namespace theseus::engine;

GameObject::GameObject(Scene& scene)
{
	myscene = &scene;
}

Scene& GameObject::scene()
{
	return *myscene;
}

const Scene& GameObject::scene() const
{
	return *myscene;
}

Game& GameObject::game()
{
	return myscene->game();
}

const Game& GameObject::game() const
{
	return myscene->game();
}

GameObject::~GameObject(){}
