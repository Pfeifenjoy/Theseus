#include "scene.hpp"
#include "game.hpp"

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

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// draw everything
}

Scene::~Scene(){}
