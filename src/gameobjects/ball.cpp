#include "ball.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;

const int SPEED = 150;

Ball::Ball()
{
	evOnUpdate.subscribe(bind(&Ball::onUpdate, this, _1));
	setTexture(3, TextureManager::instance().getTexture("ball.png"));
	setPosition(sf::Vector2f(100,100));
}

Ball::~Ball(){}

void Ball::onUpdate(float)
{
	sf::Vector2f direction(0,0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		direction.x -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		direction.x += 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		direction.y -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		direction.y += 1;
	float vectorLength = sqrt(pow(direction.x, 2.) + pow(direction.y, 2.));
	sf::Vector2f speed(0,0);
	if (vectorLength > 0.5)
	{
		speed.x = direction.x * SPEED / vectorLength;
		speed.y = direction.y * SPEED / vectorLength; 
	}
	setSpeed(speed);
}
