/**
 *   Author: Leon Mutschke
 */

#ifndef _THESEUS_GAME_FLOOR_H
#define _THESEUS_GAME_FLOOR_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class Floor
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Floor(sf::Vector2f position, sf::Vector2f size);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Floor();
		};
	}
}

#endif
#pragma once

