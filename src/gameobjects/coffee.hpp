/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_COFFEE_H
#define _THESEUS_GAME_OBJECTS_COFFEE_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>
#include "../engine/components/positionable.hpp"
#include "../messages/interact.hpp"
#include "../engine/components/messagereceiver.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Coffee
			: public theseus::engine::components::Positionable
			, public virtual engine::components::Sprite
			, public theseus::engine::components::MessageReceiver<theseus::messages::Interact>
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Coffee();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Coffee();

			void incrementCaffeineLevel(const theseus::messages::Interact& message);
		};
	}
}

#endif

