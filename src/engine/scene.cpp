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
