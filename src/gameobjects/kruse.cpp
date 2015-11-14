/**
*  @Author: Leon Mutschke
*/


#include "kruse.hpp"
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


Kruse::Kruse()
{
	evOnUpdate.subscribe(bind(&Kruse::onUpdate, this, _1));
	evCollisionDetected.subscribe(bind(&Kruse::onCollision, this, _1));

	// texture
	setTexture(2, TextureManager::instance().getTexture("charset_level_5.png"));

	// autotalk
	this->startAutoSpeech({ { "while(1){ printf(\"C is great!\");}", "Apfeltasche? Lecker...", "Daumengeste?", "Mein Glücksrad ist toll!" } }, 3, 10, 40, true, true);

}

void Kruse::onCollision(const components::Solide&)
{
	changeDirection();
}

void Kruse::changeDirection()
{
	auto direction = nextDirection();
	setDirection(direction);
}

void Kruse::onUpdate(float time)
{
	time_passed += time;

	if (time_passed > 0.2)
	{
		time_passed = 0;
		changeDirection();
	}


}



Kruse::~Kruse()
{}

