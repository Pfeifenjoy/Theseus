#include "speed.hpp"
#include <functional>

using namespace std;
using namespace theseus::engine::components;

void Speed::onUpdate(float timePassed)
{
	sf::Vector2f position = getPosition();
	position += speed * timePassed;
	setPosition(position);
}

Speed::Speed()
{
	update.setCallback(function<void(Speed*, float)>(&Speed::onUpdate), this);
	evOnUpdate.subscribe(update);
}

void Speed::setSpeed(sf::Vector2f value)
{
	speed = value;
}

sf::Vector2f Speed::getSpeed() const
{
	return speed;
}
