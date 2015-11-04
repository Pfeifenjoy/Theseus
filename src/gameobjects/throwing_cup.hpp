/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_THROWING_CUP_H
#define _THESEUS_GAME_OBJECTS_THROWING_CUP_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class ThrowingCup
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			ThrowingCup(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~ThrowingCup();
		};
	}
}

#endif
#pragma once

