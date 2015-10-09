#include "examplescene.hpp"
#include "../gameobjects/ball.hpp"
#include "../engine/game.hpp"

using namespace theseus::scenes;
using namespace theseus::engine;

ExampleScene::ExampleScene(Game& game) : Scene(game)
{
	game.loadTexture("ball.png");		
}

