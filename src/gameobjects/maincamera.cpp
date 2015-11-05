#include "maincamera.hpp"
#include <SFML/System.hpp>

using namespace theseus::gameobjects;

MainCamera::~MainCamera()
{}

MainCamera::MainCamera()
{
	setSpeed(sf::Vector2f(30, 30));
}
