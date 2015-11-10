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
			// sf::Vector2f( (!) whole screen width (i will center me by myself), 'normal' y position)
			CaffeineLevel(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~CaffeineLevel();

			void setCaffeineLevel(const theseus::messages::UpdateCaffeineLevel& message);
		};
	}
}

#endif

