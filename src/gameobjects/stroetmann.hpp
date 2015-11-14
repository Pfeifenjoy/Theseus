/**
*  @Author: Leon Mutschke
*/


#ifndef _THESEUS_GAME_OBJECTS_STROETMANN_H
#define _THESEUS_GAME_OBJECTS_STROETMANN_H

#include "../engine/gameobject.hpp"
#include "../engine/components/update.hpp"
#include "../engine/components/animation.hpp"
#include "../engine/components/speed.hpp"
#include <SFML/System.hpp>
#include "character.hpp"
#include "../engine/components/seaker.hpp"
#include "../engine/components/positionable.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Stroetmann
			: public Character
			, public virtual engine::components::Update
			, public virtual engine::components::Animation
			, public virtual engine::components::Speed
			, public virtual engine::components::Seaker
		{
		private:
			// events
			void onUpdate(float passedTime);
			float time_passed = 0;
			void onCollision(const theseus::engine::components::Solide&);
			void changeDirection();

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Stroetmann();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Stroetmann();
		};
	}
}

#endif
