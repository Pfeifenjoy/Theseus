/**
*  @Author: Tobias Dorra, Leon Mutschke, Dominic Steinhauser
*/


#ifndef _THESEUS_GAME_OBJECTS_PLAYER_H
#define _THESEUS_GAME_OBJECTS_PLAYER_H

#include "../engine/gameobject.hpp"
#include "../engine/components/update.hpp"
#include "../engine/components/animation.hpp"
#include "../engine/components/speed.hpp"
#include "../engine/components/camera.hpp"
#include <SFML/System.hpp>
#include "character.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Player
			: public Character
			, public virtual engine::components::Update
			, public virtual engine::components::Animation
			, public virtual engine::components::Speed
			, public virtual engine::components::Camera
		{
		private:
			// events
			void onUpdate(float passedTime);

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Player();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Player();
		};
	}
}

#endif
