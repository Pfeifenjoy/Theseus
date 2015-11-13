/*
* @author Dominic Steinhauser, Arwed Mett
*/
#ifndef _THESEUS_GAME_OBJECTS_BIZAGI_CD_H
#define _THESEUS_GAME_OBJECTS_BIZAGI_CD_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include "../engine/components/positionable.hpp"
#include "../engine/components/messagereceiver.hpp"
#include "../messages/interact.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class BizagiCD
			: public theseus::engine::components::Positionable
			, public virtual engine::components::Sprite
			, public virtual engine::components::MessageReceiver<theseus::messages::Interact>
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			BizagiCD();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~BizagiCD();

			void updateItem(const theseus::messages::Interact& message);

			void removeMySelf(theseus::engine::Scene& scene);
		};
	}
}

#endif


