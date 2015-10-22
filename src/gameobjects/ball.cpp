#include "ball.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>

using namespace theseus::gameobjects;
using namespace theseus::engine;

Ball::Ball()
{
	setTexture(3, TextureManager::instance().getTexture("ball.png"));
	setPosition(sf::Vector2f(100,100));
	setSpeed(sf::Vector2f(5,3));
}

Ball::~Ball(){}
