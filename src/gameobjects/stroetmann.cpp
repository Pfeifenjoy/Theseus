/**
*  @Author: Leon Mutschke
*/


#include "stroetmann.hpp"
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


Stroetmann::Stroetmann()
{
	evOnUpdate.subscribe(bind(&Stroetmann::onUpdate, this, _1));
	evCollisionDetected.subscribe(bind(&Stroetmann::onCollision, this, _1));
	// texture
	setTexture(2, TextureManager::instance().getTexture("charset_level_6.png"));

}

void Stroetmann::onCollision(const components::Solide&)
{
	changeDirection();
}

void Stroetmann::changeDirection()
{
//	auto direction = nextDirection();
//	setDirection(direction);
}

void Stroetmann::onUpdate(float time)
{
	time_passed += time;

	if (time_passed > 0.2)
	{
		time_passed = 0;
		changeDirection();
	}


}



Stroetmann::~Stroetmann()
{}

