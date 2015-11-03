/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_BIZAGI_CD_H
#define _THESEUS_GAME_OBJECTS_BIZAGI_CD_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class BizagiCD
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			BizagiCD(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~BizagiCD();
		};
	}
}

#endif
#pragma once

