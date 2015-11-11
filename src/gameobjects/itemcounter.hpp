/*
* @author Philipp P�tz
*/
#ifndef _THESEUS_GAME_OBJECTS_ITEMCOUNTER_H
#define _THESEUS_GAME_OBJECTS_ITEMCOUNTER_H

#include "../engine/gameobject.hpp"
#include "../engine/components/text.hpp"
#include "../engine/components/sprite.hpp"
#include "../engine/components/messagereceiver.hpp"
#include "../messages/updateitemcounter.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class ItemCounter
			: public engine::GameObject
			, public virtual engine::components::Text
			, public virtual engine::components::Sprite
			, public virtual engine::components::MessageReceiver<theseus::messages::UpdateItemCounter>

		{
		private:
			int numberOfItemsToCollect;
			int numberOfItems;


		public:
			//---- Constructor --------------------------------------------------------------------------------------
			// Creates a new ItemCounter
			ItemCounter(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			 ~ItemCounter();

			 void updateText(const theseus::messages::UpdateItemCounter& message);

		};
	}
}

#endif

