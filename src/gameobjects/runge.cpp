/**
*  @Author: Leon Mutschke
*/


#include "runge.hpp"
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
using namespace theseus::messages;
 
Runge::Runge()
{
	evOnUpdate.subscribe(bind(&Runge::onUpdate, this, _1));
	evCollisionDetected.subscribe(bind(&Runge::onCollision, this, _1));

	// texture
	setTexture(2, TextureManager::instance().getTexture("charset_level_1.png"));

}

void Runge::onCollision(const components::Solide&)
{
	changeDirection();
}


void Runge::changeDirection()
{
	auto direction = nextDirection();
	setDirection(direction);
}

void Runge::onUpdate(float time)
{
	time_passed += time;

	if (time_passed > 1)
	{
		time_passed = 0;
		changeDirection();
	}
	
	// send exmatriculation message
	Exmatriculation exmatriculation;
	exmatriculation.setProfessorSended();
	MessageSender<Exmatriculation>::sendMessage(exmatriculation, 85, 85);

}


Runge::~Runge()
{}

