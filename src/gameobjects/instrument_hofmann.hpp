/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_INSTRUMENT_H
#define _THESEUS_GAME_OBJECTS_INSTRUMENT_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class Instrument
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------
			
			Instrument(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Instrument();
		};
	}
}

#endif
#pragma once
