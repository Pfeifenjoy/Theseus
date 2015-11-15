/**
*  @Author: Tobias Dorra, Leon Mutschke, Dominic Steinhauser, Philipp Pütz
*/


#ifndef _THESEUS_GAME_OBJECTS_PLAYER_H
#define _THESEUS_GAME_OBJECTS_PLAYER_H

#include "../engine/gameobject.hpp"
#include "../engine/components/camera.hpp"
#include "../engine/components/messagesender.hpp"
#include "../engine/components/keyboardinput.hpp"
#include "../messages/updatelifepoints.hpp"
#include "../messages/interact.hpp"
#include "../messages/updatecaffeinelevel.hpp"
#include "../messages/updateitemcounter.hpp"
#include "../messages/attrack.hpp"
#include "../map/map.hpp"
#include "../gameobjects/student.hpp"
#include <SFML/System.hpp>
#include "character.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Player
			: public Student
			, public virtual engine::components::Camera
			, public virtual engine::components::KeyboardInput
			, public virtual engine::components::MessageSender<theseus::messages::UpdateLifePoints>
			, public virtual engine::components::MessageSender<theseus::messages::UpdateCaffeineLevel>
			, public virtual engine::components::MessageSender<theseus::messages::Interact>
			, public virtual engine::components::MessageSender<theseus::messages::UpdateItemCounter>
		{
		private:
			// events
			void onUpdate(float passedTime);

			// Player attributs
			int lifePoints;
			float caffeineLevel;
			float maxCaffeineLevel;
			int inventoryItem;
			int maxInventoryItems;

			void updateItemCounter();
			void updateCaffeineLevel();
			void updateLifePoints();
			
			void endScene(theseus::engine::Scene& scene);
			void keyPressed(sf::Keyboard::Key key);
			theseus::map::Map* map;
			
			bool genderMale = true;

			void exmatriculationDone();
			bool exmatriculationTick(const theseus::messages::Exmatriculation&);

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

			void setMale(bool male);

		};
	}
}

#endif
