#ifndef _THESEUS_GAME_OBJECTS_FRUCTIV_H
#define _THESEUS_GAME_OBJECTS_FRUCTIV_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class Fructiv
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Fructiv(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Fructiv();
		};
	}
}

#endif
#pragma once

