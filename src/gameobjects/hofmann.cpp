/**
*  @Author: Leon Mutschke
*/


#include "hofmann.hpp"
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


Hofmann::Hofmann()
{
	evOnUpdate.subscribe(bind(&Hofmann::onUpdate, this, _1));
	evCollisionDetected.subscribe(bind(&Hofmann::onCollision, this, _1));

	// texture
	setTexture(2, TextureManager::instance().getTexture("charset_level_4.png"));

	// autotalk
	this->startAutoSpeech({ { "Keiner kommt in den Rosengarten!", "Boah, ist hier ne Luft.", "<b> hi </b>", "Ich bin hier der Boss!" } }, 3, 10, 40, true, true);
}

void Hofmann::onCollision(const components::Solide&)
{
	changeDirection();
}

void Hofmann::changeDirection()
{
	auto direction = nextDirection();
	setDirection(direction);
}

void Hofmann::onUpdate(float time)
{
	time_passed += time;

	if (time_passed > 0.2)
	{
		time_passed = 0;
		changeDirection();
	}


}



Hofmann::~Hofmann()
{}

