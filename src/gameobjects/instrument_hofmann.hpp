/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_INSTRUMENT_H
#define _THESEUS_GAME_OBJECTS_INSTRUMENT_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>
#include "../engine/components/positionable.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class Instrument
			: public theseus::engine::components::Positionable
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Instrument();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Instrument();
		};
	}
}

#endif
#pragma once
