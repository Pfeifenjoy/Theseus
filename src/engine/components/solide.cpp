#include "solide.hpp"
#include "../scene.hpp"
#include <functional>

using namespace std;
using namespace std::placeholders;
using namespace theseus::engine;
using namespace theseus::engine::components;

Solide::Solide()
{
	evRegisterComponents.subscribe(bind(&Solide::onRegisterComponents, this, _1));
	evUpdateComponentRegistrations.subscribe(bind(&Solide::onUpdateRegistration, this, _1));
	evUnregisterComponents.subscribe(bind(&Solide::onUnregisterComponents, this, _1));
}

Solide::~Solide()
{}

void Solide::onRegisterComponents(Scene& scene)
{
	scene.registerSolide(this);
	positionInSync = getPosition();
}

void Solide::onUnregisterComponents(Scene& scene)
{
	scene.unRegisterSolide(this);
}

void Solide::onUpdateRegistration(Scene& scene)
{
	auto position = getPosition();
	if (positionInSync != position)
	{
		scene.reRegisterSolide(positionInSync, this);
		positionInSync = position; 
	}
}


sf::Vector2f Solide::getCollisionAreaTopLeft() const
{
	return collisionAreaTL;
}

void Solide::setCollisionAreaTopLeft(sf::Vector2f value)
{
	collisionAreaTL = value;
}

sf::Vector2f Solide::getCollisionAreaBottomRight() const
{
	return  collisionAreaBR;
}

void Solide::setCollisionAreaBottomRight(sf::Vector2f value)
{
	collisionAreaBR = value;
}

sf::Vector2f Solide::getAbsoluteCollisionAreaTopLeft() const
{
	auto pos = getPosition();
	return sf::Vector2f(
			pos.x + collisionAreaTL.x,
			pos.y + collisionAreaTL.y
			);
}

sf::Vector2f Solide::getAbsoluteCollisionAreaBottomRight() const
{
	auto pos = getPosition();
	return sf::Vector2f(
			pos.x + collisionAreaBR.x,
			pos.y + collisionAreaBR.y
			);

}

