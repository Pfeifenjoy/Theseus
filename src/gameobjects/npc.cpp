/**
*  @Author: Tobias Dorra, Leon Mutschke, Dominic Steinhauser, Philipp P�tz
*/


#include "npc.hpp"
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

NPC::NPC()
{
	exmatriculatedBool = false;
	exmatriculate = false;

	evOnUpdate.subscribe(bind(&NPC::onUpdate, this, _1));
	evCollisionDetected.subscribe(bind(&NPC::onCollision, this, _1));

	// texture
	setTexture(2, TextureManager::instance().getTexture("player2.png"));

	MessageReceiver<Exmatriculation>::evOnMessageReceived.subscribe(std::bind(&NPC::exmatriculated, this, _1));
}

void NPC::onCollision(const components::Solide&)
{
	changeDirection();
}

void NPC::exmatriculated(const theseus::messages::Exmatriculation& message) {
	exmatriculatedBool = true;
	setTexture(2, TextureManager::instance().getTexture("player2_infected.png"));
}

void NPC::setExmatriculate() {
	this->exmatriculate = true;
}

void NPC::changeDirection()
{
	sf::Vector2i direction(0, 0);
	int number = rand() % 9;

	switch (number)
	{
		case 0: direction = sf::Vector2i( 0, 0); break; // NPC is not moving
		case 1: direction = sf::Vector2i(-1, 0); break; // NPC is moving left
		case 2: direction = sf::Vector2i( 1, 0); break; // NPC is moving right
		case 3: direction = sf::Vector2i(0, -1); break; // NPC is moving up
		case 4: direction = sf::Vector2i( 0, 1); break; // NPC is moving down
		case 5: direction = sf::Vector2i(-1,-1); break; // NPC is moving left up
		case 6: direction = sf::Vector2i(1, -1); break; // NPC is moving right up
		case 7: direction = sf::Vector2i(-1, 1); break; // NPC is moving left down
		case 8: direction = sf::Vector2i( 1, 1); break; // NPC is moving right down
	}
	setDirection(direction);
}

void NPC::onUpdate(float time)
{
	time_passed += time;

	if (time_passed > 1)
	{
		time_passed = 0;
		changeDirection();
	}

	if (exmatriculatedBool && exmatriculate) {
		Exmatriculation exmatriculation;
		MessageSender<Exmatriculation>::sendMessage(exmatriculation, 80, 80);
	}


}



NPC::~NPC()
{}

