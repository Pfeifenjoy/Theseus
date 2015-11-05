/*
* @author Philipp Pütz
*/
#ifndef _THESEUS_GAME_OBJECTS_TIMER_H
#define _THESEUS_GAME_OBJECTS_TIMER_H

#include "../engine/gameobject.hpp"
#include "../engine/components/update.hpp"
#include "../engine/components/text.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class Timer
			: public engine::GameObject
			, public virtual engine::components::Text
			, public virtual engine::components::Update

		{
		private:
			float startTime;
			float actualTime;
			float lastDisplayedTime;

		public:
			//---- Constructor --------------------------------------------------------------------------------------
			// Creates a new timer; Timer(position, startTime in secs)
			Timer(sf::Vector2f position, int startTime);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Timer();

			// Returns the actual timer countdown in secs
			float getActualTime();

			// Method which is called from the update component -> decrements the timer
			void onUpdate(float timePassed);

		};
	}
}

#endif

