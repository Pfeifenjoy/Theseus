/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_THROWING_CUP_H
#define _THESEUS_GAME_OBJECTS_THROWING_CUP_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>
#include "../engine/components/positionable.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class ThrowingCup
			: public theseus::engine::components::Positionable
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			ThrowingCup();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~ThrowingCup();
		};
	}
}

#endif
#pragma once

