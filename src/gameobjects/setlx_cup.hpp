#ifndef _THESEUS_GAME_OBJECTS_SETLX_CUP_H
#define _THESEUS_GAME_OBJECTS_SETLX_CUP_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class SetlxCup
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			SetlxCup(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~SetlxCup();
		};
	}
}

#endif
#pragma once

