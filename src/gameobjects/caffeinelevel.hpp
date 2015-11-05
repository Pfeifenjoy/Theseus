/*
* @author Philipp Pütz
*/
#ifndef _THESEUS_GAME_OBJECTS_CAFFEINELEVEL_H
#define _THESEUS_GAME_OBJECTS_CAFFEINELEVEL_H

#include "../engine/gameobject.hpp"
#include "../engine/components/text.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class CaffeineLevel
			: public engine::GameObject
			, public virtual engine::components::Text

		{
		private:
			float startLevel;
			float actualLevel;
			float maximumLevel;

		public:
			//---- Constructor --------------------------------------------------------------------------------------
			CaffeineLevel(sf::Vector2f position, float startLevel, float maximumLevel);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~CaffeineLevel();

			// Returns the actual caffeine level
			float getActualLevel();

			// Returns the maximum caffeine level
			float getMaximumLevel();

			// Decrements the caffeine level by a certan amough of points
			void decrementCaffeineLevel(float points);

			// Increments the caffeine level by a certan amough of points
			void incrementCaffeineLevel(float points);

		};
	}
}

#endif

