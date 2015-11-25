/*
* @author Philipp Pütz
*/
#ifndef _THESEUS_GAME_OBJECTS_CAFFEINELEVEL_H
#define _THESEUS_GAME_OBJECTS_CAFFEINELEVEL_H

#include "../engine/gameobject.hpp"
#include "../engine/components/text.hpp"
#include "../engine/components/messagereceiver.hpp"
#include "../messages/updatecaffeinelevel.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class CaffeineLevel
			: public engine::GameObject
			, public virtual engine::components::Text
			, public virtual engine::components::MessageReceiver<theseus::messages::UpdateCaffeineLevel>

		{
		public:
			//---- Constructor --------------------------------------------------------------------------------------
			CaffeineLevel(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~CaffeineLevel();

			// Sets the caffeine level and updates the HUD
			void setCaffeineLevel(const theseus::messages::UpdateCaffeineLevel& message);
		};
	}
}

#endif

