/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_CHALK_H
#define _THESEUS_GAME_OBJECTS_CHALK_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class Chalk
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Chalk(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Chalk();
		};
	}
}

#endif
#pragma once
#pragma once
