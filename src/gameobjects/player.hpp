/**
*  @Author: Tobias Dorra, Leon Mutschke, Dominic Steinhauser, Philipp Pütz
*/


#ifndef _THESEUS_GAME_OBJECTS_PLAYER_H
#define _THESEUS_GAME_OBJECTS_PLAYER_H

#include "../engine/gameobject.hpp"
#include "../engine/components/update.hpp"
#include "../engine/components/animation.hpp"
#include "../engine/components/speed.hpp"
#include "../engine/components/camera.hpp"
#include "../engine/components/messagesender.hpp"
#include "../messages/updatelifepoints.hpp"
#include "../messages/interact.hpp"
#include "../messages/updatecaffeinelevel.hpp"
#include "../messages/updateitemcounter.hpp"
#include "../map/map.hpp"
#include "../engine/components/messagereceiver.hpp"
#include "../messages/exmatriculation.hpp"
#include <SFML/System.hpp>
#include "character.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Player
			: public Character
			, public virtual engine::components::Update
			, public virtual engine::components::Animation
			, public virtual engine::components::Speed
			, public virtual engine::components::Camera
			, public virtual engine::components::MessageSender<theseus::messages::UpdateLifePoints>
			, public virtual engine::components::MessageSender<theseus::messages::UpdateCaffeineLevel>
			, public virtual engine::components::MessageSender<theseus::messages::Interact>
			, public virtual engine::components::MessageSender<theseus::messages::UpdateItemCounter>
			, public virtual engine::components::MessageReceiver<theseus::messages::Exmatriculation>

		{
		private:
			// events
			void onUpdate(float passedTime);

			// player attributs
			int lifePoints;
			float caffeineLevel;
			float maxCaffeineLevel;
			int inventoryItem;
			int maxInventoryItems;

			float exmatriculationTime;
			bool exmatricualtionProcessActive;

			void updateItemCounter();
			void updateCaffeineLevel();
			void updateLifePoints();
			theseus::map::Map* map;


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Player(int startCaffeineLevel, int maxCaffeineLevel, int lifePoints, int itemsToCollect);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Player();


			// Methods
			void decrementLifePoints();

			int getLifePoints();

			// Increments the caffeinelevel by a certain value
			void incrementCaffeineLevel(int value);

			// Increment inventory item value by 1
			void incrementInventoryItemValue();

			void setMap(theseus::map::Map*);

			void exmatriculated(const theseus::messages::Exmatriculation& message);

			void endScene(theseus::engine::Scene& scene);

		};
	}
}

#endif
