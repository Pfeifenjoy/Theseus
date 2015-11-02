/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_TABLE_H
#define _THESEUS_GAME_OBJECTS_TABLE_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class Table
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Table(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Table();
		};
	}
}

#endif
#pragma once

#pragma once
