/**
*  @Author: Leon Mutschke
*/
#ifndef _THESEUS_GAME_OBJECTS_RUNGE_H
#define _THESEUS_GAME_OBJECTS_RUNGE_H

#include "../engine/gameobject.hpp"
#include "../engine/components/update.hpp"
#include "../engine/components/animation.hpp"
#include "../engine/components/speed.hpp"
#include "../engine/components/messagesender.hpp"
#include "../messages/exmatriculation.hpp"
#include <SFML/System.hpp>
#include "character.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Runge
			: public Character
			, public virtual engine::components::Update
			, public virtual engine::components::Animation
			, public virtual engine::components::Speed
			, public virtual engine::components::MessageSender<theseus::messages::Exmatriculation>
		{
		private:
			// events
			void onUpdate(float passedTime);
			float time_passed = 0;
			void onCollision(const theseus::engine::components::Solide&);
			void changeDirection();

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Runge();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Runge();
		};
	}
}

#endif
