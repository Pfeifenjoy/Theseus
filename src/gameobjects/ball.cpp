#include "ball.hpp"
#include "../engine/scene.hpp"
#include "../engine/game.hpp"

using namespace theseus::gameobjects;
using namespace theseus::engine;

Ball::Ball(Scene& scene) : GameObject(scene)
{
	setTexture(game().getTexture("ball.png"));
}

Ball::~Ball(){}
