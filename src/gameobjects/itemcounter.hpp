/*
* @author Philipp Pütz
*/
#ifndef _THESEUS_GAME_OBJECTS_ITEMCOUNTER_H
#define _THESEUS_GAME_OBJECTS_ITEMCOUNTER_H

#include "../engine/gameobject.hpp"
#include "../engine/components/text.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class ItemCounter
			: public engine::GameObject
			, public virtual engine::components::Text
			, public virtual engine::components::Sprite

		{
		private:
			int numberOfItemsToCollect;
			int numberOfItems;


		public:
			//---- Constructor --------------------------------------------------------------------------------------
			// Creates a new ItemCounter
			ItemCounter(sf::Vector2f position, int numberofItemsToCollect);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~ItemCounter();

			// Returns the actual number of items
			int getNumberOfItems();

			// Returns the number of items which should collected
			int getNumberOfItemsToCollect();

			// Adds 1 item to the collected item counter
			void incrementCounter();

		};
	}
}

#endif

