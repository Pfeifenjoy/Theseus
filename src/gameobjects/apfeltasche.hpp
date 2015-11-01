#ifndef _THESEUS_GAME_APFELTASCHE_H
#define _THESEUS_GAME_APFELTASCHE_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class Apfeltasche
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Apfeltasche(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Apfeltasche();
		};
	}
}

#endif
#pragma once

