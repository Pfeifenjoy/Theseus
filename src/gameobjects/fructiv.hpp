/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_FRUCTIV_H
#define _THESEUS_GAME_OBJECTS_FRUCTIV_H

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
		class Fructiv
			: public theseus::engine::components::Positionable
			, public virtual engine::components::Sprite
			, public virtual engine::components::MessageReceiver<theseus::messages::Interact>
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Fructiv();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Fructiv();

			void updateItem(const theseus::messages::Interact& message);
		};
	}
}

#endif


