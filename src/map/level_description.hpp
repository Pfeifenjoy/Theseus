/**
 *  @Author: Leon Mutschke, Dominic Steinhauser
 */

#ifndef THESEUS_MAP_LEVEL_DESCRIPTION
#define THESEUS_MAP_LEVEL_DESCRIPTION

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class Level_Description

		{
		private:
			void getRandomGO(); // get randome Gameobject
			void getRooms();
			void getPlayer();
			

		public:
			//---- Constructor --------------------------------------------------------------------------------------

			Level_Description();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~Level_Description();
		};
	}
}

#endif
#pragma once

