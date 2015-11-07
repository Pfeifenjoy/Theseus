/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_COFFEE_H
#define _THESEUS_GAME_OBJECTS_COFFEE_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>
#include "../map/positionable.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Coffee
			: public theseus::map::Positionable
			, public virtual engine::components::Sprite
		{
		private:
			

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Coffee();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Coffee();
		};
	}
}

#endif
#pragma once
