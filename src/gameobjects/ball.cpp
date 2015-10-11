#include "ball.hpp"
#include "../engine/scene.hpp"
#include "../engine/game.hpp"
#include <SFML/Graphics.hpp>

using namespace theseus::gameobjects;
using namespace theseus::engine;

Ball::Ball(Scene& scene) : GameObject(scene)
{
	setTexture(3, game().getTexture("ball.png"));
	setPosition(sf::Vector2f(100,100));
}

Ball::~Ball(){}
