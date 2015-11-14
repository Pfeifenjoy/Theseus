/**
*  @Author: Leon Mutschke
*/


#include "glaser.hpp"
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


Glaser::Glaser()
{
	evOnUpdate.subscribe(bind(&Glaser::onUpdate, this, _1));
	evCollisionDetected.subscribe(bind(&Glaser::onCollision, this, _1));

	// texture
	setTexture(2, TextureManager::instance().getTexture("charset_level_2.png"));

	// autotalk
	this->startAutoSpeech({ { "0110100001101001", "Schon wieder keine Kreide.", "AND oder NAND?", "XOR, NOR oder OR?" } }, 3, 10, 40, true, true);
}

void Glaser::onCollision(const components::Solide&)
{
	changeDirection();
}

void Glaser::changeDirection()
{
	auto direction = nextDirection();
	setDirection(direction);
}

void Glaser::onUpdate(float time)
{
	time_passed += time;

	if (time_passed > 0.2)
	{
		time_passed = 0;
		changeDirection();
	}


}



Glaser::~Glaser()
{}

