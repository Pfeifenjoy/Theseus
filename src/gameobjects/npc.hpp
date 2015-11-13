/**
*  @Author: Tobias Dorra, Leon Mutschke, Dominic Steinhauser
*/


#ifndef _THESEUS_GAME_OBJECTS_NPC_H
#define _THESEUS_GAME_OBJECTS_NPC_H

#include "../engine/gameobject.hpp"
#include "../engine/components/update.hpp"
#include "../engine/components/animation.hpp"
#include "../engine/components/speed.hpp"
#include "../engine/components/messagereceiver.hpp"
#include "../messages/exmatriculation.hpp"
#include <SFML/System.hpp>
#include "character.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class NPC
			: public Character
			, public virtual engine::components::Update
			, public virtual engine::components::Animation
			, public virtual engine::components::Speed
			, public virtual engine::components::MessageReceiver<theseus::messages::Exmatriculation>
		{
		private:
			// events
			void onUpdate(float passedTime);
			float time_passed = 0;
			void onCollision(const theseus::engine::components::Solide&);
			void changeDirection();

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			NPC();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~NPC();

			void exmatriculated(const theseus::messages::Exmatriculation& message);
		};
	}
}

#endif
