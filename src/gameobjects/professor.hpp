#ifndef _THESEUS_GAME_OBJECTS_PROFESSOR_H
#define _THESEUS_GAME_OBJECTS_PROFESSOR_H

#include "character.hpp"
#include "../engine/components/update.hpp"
#include "../engine/components/messagereceiver.hpp"
#include "../engine/components/messagesender.hpp"
#include "../engine/components/seeker.hpp"
#include "../messages/attrack.hpp"
#include "../messages/exmatriculation.hpp"
#include <SFML/System.hpp>

namespace theseus
{
namespace gameobjects
{

	class Professor
		: public Character
		, public virtual engine::components::MessageReceiver<messages::Attrack>
		, public virtual engine::components::MessageSender<messages::Exmatriculation>
		, public virtual engine::components::Update
		, public virtual engine::components::Seeker
	{
		private:
			enum class Mode
			{
				custom, 	// The derived class has full controll over the prof.
				idle, 		// Prof walks randomly around
				rage 		// Prof follows a student
			};

			// the mode
			Mode mode = Mode::idle;

			// rage mode (autofollow)
			sf::Vector2f destination; 	// The place to go...
			int destination_priority = 0; 	// the priority of the current destination (the player usually has a higher priority than other students)
			float rageSpeedFactor = 1.5; 	// the factor that the professor is fater, when he has a good target (is in rage mode).
			float timeToCalmDown; 		// time that is left until the prof falls back to IDLE mode.
			float changeDirectionTimeout = 0;

			// exmatriculation
			float exmatriculation_radius = 100; 	// where the exmatriculation message is sent to
			float exmatriculation_speed = 1; 	// how fast the professor exmatriculates his poor students

			// events
			void onUpdate(float timePassed);
			void onAttrack(const messages::Attrack& attraction);

		public:

			/**
			 * Constructor
			 */
			Professor();

			/**
			 * Destructor
			 */
			virtual ~Professor();

	};
}
}

#endif
