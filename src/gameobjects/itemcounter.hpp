/*
* @author Philipp Pütz
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
			// Creates a new ItemCounter(position, name of the picture (*.png))
			ItemCounter(sf::Vector2f position, std::string itemPictureName);

			//---- Destructor ---------------------------------------------------------------------------------------

			 ~ItemCounter();

			 // Updates the item counter
			 void updateMyText(const theseus::messages::UpdateItemCounter& message);

		};
	}
}

#endif

