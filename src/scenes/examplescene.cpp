#include "examplescene.hpp"
#include "../gameobjects/ball.hpp"
#include "../engine/game.hpp"

using namespace theseus::scenes;
using namespace theseus::gameobjects;
using namespace theseus::engine;
using namespace std;

ExampleScene::ExampleScene(Game& game) : Scene(game)
{
	// Load textures needed in this scene
	game.loadTexture("ball.png");

	// Add game objects
	ball = unique_ptr<Ball>(new Ball(*this));

}

ExampleScene::~ExampleScene(){}
