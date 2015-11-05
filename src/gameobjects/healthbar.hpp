/*
* @author Philipp Pütz
*/
#ifndef _THESEUS_GAME_OBJECTS_HEALTHBAR_H
#define _THESEUS_GAME_OBJECTS_HEALTHBAR_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class HealthBar
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:
			int healthPoints;

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			HealthBar(sf::Vector2f position, int healthPoints);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~HealthBar();


			int getHealthPoints();

			void decrementHealthPoints();

			void incrementHealthPoints();

			void setHealthPoints(int healthPoints);
		};
	}
}

#endif

