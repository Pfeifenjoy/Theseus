/*
* @author Philipp Pütz
*/
#ifndef _THESEUS_GAME_OBJECTS_HEALTHBAR_H
#define _THESEUS_GAME_OBJECTS_HEALTHBAR_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include "../engine/components/messagereceiver.hpp"
#include "../messages/updatelifepoints.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class HealthBar
			: public engine::GameObject
			, public virtual engine::components::Sprite
			, public virtual engine::components::MessageReceiver<theseus::messages::UpdateLifePoints>
		{
		private:
			int healthPoints;

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			HealthBar(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~HealthBar();

			void HealthBar::setHealthPoints(const theseus::messages::UpdateLifePoints& message);
		};
	}
}

#endif

