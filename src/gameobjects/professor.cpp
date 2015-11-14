#include "professor.hpp"
#include <functional>

using namespace std;
using namespace std::placeholders;
using namespace theseus::gameobjects;
using namespace theseus::messages;
using namespace theseus::engine;
using namespace theseus::engine::components;

Professor::Professor()
{
	// register for events
	evOnUpdate.subscribe(bind(&Professor::onUpdate, this, _1));
	MessageReceiver<Attrack>::evOnMessageReceived.subscribe(bind(&Professor::onAttrack, this, _1));
}

void Professor::onAttrack(const Attrack& attraction)
{
	if (mode != Mode::custom && destination_priority <= attraction.priority)
	{
		destination_priority = attraction.priority;
		destination = attraction.position;
		timeToCalmDown = 2.;
		mode = Mode::rage;
	}
}

void Professor::onUpdate(float timePassed)
{
	if (mode == Mode::rage)
	{
		// test if the rage mode has timed out
		timeToCalmDown -= timePassed;
		if (timeToCalmDown < 0)
		{
			mode = Mode::idle;
			destination_priority = 0;
		}

		// send the exmatriculation message
		Exmatriculation exmatriculation;
		exmatriculation.setProfessorSended();
		exmatriculation.setExmatriculationAmount(timePassed * exmatriculation_speed);
		sendMessage(exmatriculation, exmatriculation_radius, exmatriculation_radius);

		// retarget the movement
		auto direction = nextDirection(destination, 15);	
		setDirection(direction);
		setSpeedMultiplier(rageSpeedFactor);
	}
	else if (mode == Mode::idle)
	{
		// TODO: idle around
		setSpeedMultiplier(1);
		setDirection(sf::Vector2i(0, 0));
	}
}

Professor::~Professor()
{}
