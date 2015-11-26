/**
*  @Author: Tobias Dorra, Leon Mutschke, Dominic Steinhauser, Philipp Pütz
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
	// Sets basic behaviour value
	exmatriculatedBool = false; // NPC starts immatriculated
	exmatriculate = false;      // NPC havn't the option to exmatriculate (default)

	// Subscribe for update and collision events
	evOnUpdate.subscribe(bind(&NPC::onUpdate, this, _1));
	evCollisionDetected.subscribe(bind(&NPC::onCollision, this, _1));

	// Sets the texture
	setTexture(2, TextureManager::instance().getTexture("player2.png"));

	// Subscribe for Exmatriculation message
	MessageReceiver<Exmatriculation>::evOnMessageReceived.subscribe(std::bind(&NPC::exmatriculation, this, _1));

	// autotalk
	this->startAutoSpeech({ { "Hallo!", "Wie geht's?", "Exmatrikulier mich nicht!", "Was ist mit den Professoren los?" } }, 3, 10, 40, true, true);
}

void NPC::onCollision(const components::Solide&)
{
	changeDirection();
}

void NPC::exmatriculationDone() {
	setExmatriculationable(false);
	exmatriculatedBool = true;

	// change texture if an npc gets exmatriculated
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
	case 0: direction = sf::Vector2i(0, 0); break; // NPC is not moving
	case 1: direction = sf::Vector2i(-1, 0); break; // NPC is moving left
	case 2: direction = sf::Vector2i(1, 0); break; // NPC is moving right
	case 3: direction = sf::Vector2i(0, -1); break; // NPC is moving up
	case 4: direction = sf::Vector2i(0, 1); break; // NPC is moving down
	case 5: direction = sf::Vector2i(-1, -1); break; // NPC is moving left up
	case 6: direction = sf::Vector2i(1, -1); break; // NPC is moving right up
	case 7: direction = sf::Vector2i(-1, 1); break; // NPC is moving left down
	case 8: direction = sf::Vector2i(1, 1); break; // NPC is moving right down
	}
	setDirection(direction);
}

void NPC::onUpdate(float timePassed)
{
	// Change every sec the moving direction
	time_passed += timePassed;

	if (time_passed > 1)
	{
		time_passed = 0;
		changeDirection();
	}

	// If the NPC should exmatriculate and he's exmatriculated -> Send exmatriculation message to other npc's
	if (exmatriculatedBool && exmatriculate) {
		// send the exmatriculation message
		Exmatriculation exmatriculation;

		// master branch
		//exmatriculation.setExmatriculationAmount(timePassed * exmatriculation_speed);
		//exmatriculation.setOrigin(this->getPosition());
		//	sendMessage(exmatriculation, exmatriculation_radius, exmatriculation_radius);
		//}	

		// develop
		MessageSender<Exmatriculation>::sendMessage(exmatriculation, exmatriculation_radius, exmatriculation_radius);
	}

	// attrack professors
	Attrack attraction;
	attraction.position = getPosition() + 0.5f * this->getCollisionAreaTopLeft() + 0.5f * this->getCollisionAreaBottomRight();
	attraction.priority = 1;
	MessageSender<Attrack>::sendMessage(attraction, 150, 150);

}

NPC::~NPC()
{}

