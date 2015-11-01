#ifndef _THESEUS_GAME_OBJECTS_COFFEE_H
#define _THESEUS_GAME_OBJECTS_COFFEE_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class Coffee
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:
			

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Coffee(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Coffee();
		};
	}
}

#endif
#pragma once
