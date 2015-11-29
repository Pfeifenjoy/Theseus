/**
 * Autor: Tobias Dorra
 */
#include "speed.hpp"
#include <functional>

using namespace std;
using namespace std::placeholders;
using namespace theseus::engine::components;

void Speed::onUpdate(float timePassed)
{
	sf::Vector2f position = getPosition();
	position += speed * timePassed;
	setPosition(position);
}

Speed::Speed()
{
	evOnUpdate.subscribe(bind(&Speed::onUpdate, this, _1));
}

Speed::~Speed()
{}

void Speed::setSpeed(sf::Vector2f value)
{
	speed = value;
}

sf::Vector2f Speed::getSpeed() const
{
	return speed;
}
