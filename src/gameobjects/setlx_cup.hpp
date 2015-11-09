/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_SETLX_CUP_H
#define _THESEUS_GAME_OBJECTS_SETLX_CUP_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>
#include "../engine/components/positionable.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class SetlxCup
			: public theseus::engine::components::Positionable
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			SetlxCup();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~SetlxCup();
		};
	}
}

#endif
#pragma once

