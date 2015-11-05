/**
 *   Author: Leon Mutschke, Philipp Pütz
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
		enum FloorType {CORRIDOR, ROOM};
		class Floor
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Floor(sf::Vector2f position, sf::Vector2f size, FloorType);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Floor();
		};
	}
}

#endif
#pragma once

