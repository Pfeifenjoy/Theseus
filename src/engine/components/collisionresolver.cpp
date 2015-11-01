#include "collisionresolver.hpp"
#include <functional>

using namespace std;
using namespace std::placeholders;
using namespace theseus::engine;
using namespace theseus::engine::components;

CollisionResolver::CollisionResolver()
{
	evCollisionDetected.subscribe(bind(&CollisionResolver::onCollisionDetected, this, _1));
}

CollisionResolver::~CollisionResolver()
{}

void CollisionResolver::onCollisionDetected(const Solide& other)
{
	// my own collision area
	auto tl = getAbsoluteCollisionAreaTopLeft();
	auto br = getAbsoluteCollisionAreaBottomRight();

	// the collision area of the other guy.
	auto o_tl = other.getAbsoluteCollisionAreaTopLeft();
	auto o_br = other.getAbsoluteCollisionAreaBottomRight();

	// calculate the distance that we would need to 
	// move in each direction in order to resolve the collision.
	float moveUp = br.y - o_tl.y;
	float moveDown = o_br.y - tl.y;
	float moveLeft = br.x - o_tl.x;
	float moveRight = o_br.x - tl.x;

	// resolve the collision by moving into the direction where
	// the smallest movement is required.
	if (moveUp < moveDown && moveUp < moveLeft && moveUp < moveRight)
	{
		setPositionRelative(sf::Vector2f(0, 0 - moveUp));
	}
	else if (moveDown < moveLeft && moveDown < moveRight)
	{
		setPositionRelative(sf::Vector2f(0, moveDown));
	}
	else if (moveLeft < moveRight)
	{
		setPositionRelative(sf::Vector2f(0 - moveLeft, 0));
	}
	else
	{
		setPositionRelative(sf::Vector2f(moveRight, 0));
	}
}
