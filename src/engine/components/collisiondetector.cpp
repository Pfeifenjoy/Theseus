#include "collisiondetector.hpp"
#include "../scene.hpp"
#include <functional>

using namespace std;
using namespace std::placeholders;
using namespace theseus::engine;
using namespace theseus::engine::components;

CollisionDetector::CollisionDetector()
{
	evUpdateComponentRegistrations.subscribe(bind(&CollisionDetector::onUpdateRegistration, this, _1));
	evRegisterComponents.subscribe(bind(&CollisionDetector::onUpdateRegistration, this, _1));
	evPositionChanged.subscribe(bind(&CollisionDetector::onPositionChanged, this, _1, _2));	
	reCheckCollision = true;
}

CollisionDetector::~CollisionDetector()
{}

void CollisionDetector::onUpdateRegistration(Scene& scene)
{
	if (reCheckCollision)
	{
		scene.checkCollisions(this);
		reCheckCollision = false;
	}
}

void CollisionDetector::onPositionChanged(sf::Vector2f, sf::Vector2f)
{
	reCheckCollision = true;	
}

void CollisionDetector::handleCollision(const Solide& other)
{
	evCollisionDetected(other);
}
