/**
*  @Author: Leon Mutschke
*/


#include "huebl.hpp"
#include "../engine/texturemanager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <cmath>
#include <stdlib.h> // includes rand()

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::engine;


Huebl::Huebl()
{
	evOnUpdate.subscribe(bind(&Huebl::onUpdate, this, _1));
	evCollisionDetected.subscribe(bind(&Huebl::onCollision, this, _1));

	// texture
	setTexture(2, TextureManager::instance().getTexture("charset_level_3.png"));

}

void Huebl::onCollision(const components::Solide&)
{
	changeDirection();
}

void Huebl::changeDirection()
{
	auto direction = nextDirection();
	setDirection(direction);
}

void Huebl::onUpdate(float time)
{
	time_passed += time;

	if (time_passed > 0.2)
	{
		time_passed = 0;
		changeDirection();
	}


}



Huebl::~Huebl()
{}

