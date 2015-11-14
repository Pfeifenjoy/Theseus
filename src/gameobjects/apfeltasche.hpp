/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_APFELTASCHE_H
#define _THESEUS_GAME_APFELTASCHE_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>
#include "../engine/components/positionable.hpp"
#include "../engine/components/messagereceiver.hpp"
#include "../messages/interact.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Apfeltasche
			: public theseus::engine::components::Positionable
			, public virtual engine::components::Sprite
			, public virtual engine::components::MessageReceiver<theseus::messages::Interact>
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Apfeltasche();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Apfeltasche();

			void updateItem(const theseus::messages::Interact& message);
		};
	}
}

#endif


