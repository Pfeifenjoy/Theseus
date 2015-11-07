/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_FRUCTIV_H
#define _THESEUS_GAME_OBJECTS_FRUCTIV_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>
#include "../map/positionable.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Fructiv
			: public theseus::map::Positionable
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Fructiv();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Fructiv();
		};
	}
}

#endif
#pragma once

