/**
*  @Author: Tobias Dorra, Leon Mutschke, Dominic Steinhauser, Philipp Pütz
*/


#ifndef _THESEUS_GAME_OBJECTS_PLAYER_H
#define _THESEUS_GAME_OBJECTS_PLAYER_H

#include "../engine/gameobject.hpp"
#include "../engine/components/update.hpp"
#include "../engine/components/animation.hpp"
#include "../engine/components/speed.hpp"
#include "../engine/components/camera.hpp"
#include "../engine/components/messagesender.hpp"
#include "../messages/updatelifepoints.hpp"
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
			, public virtual engine::components::MessageSender<theseus::messages::UpdateLifePoints>
		{
		private:
			// events
			void onUpdate(float passedTime);

			// player attributs
			int lifePoints;
			float caffeineLevel;
			float maxCaffeineLevel;

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Player(int startCaffeineLevel, int maxCaffeineLevel, int lifePoints);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Player();


			// Methods
			void decrementLifePoints();

			int getLifePoints();

			
		};
	}
}

#endif
