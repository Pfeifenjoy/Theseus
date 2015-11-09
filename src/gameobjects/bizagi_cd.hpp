/*
* @author Dominic Steinhauser, Arwed Mett
*/
#ifndef _THESEUS_GAME_OBJECTS_BIZAGI_CD_H
#define _THESEUS_GAME_OBJECTS_BIZAGI_CD_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include "../engine/components/positionable.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class BizagiCD
			: public theseus::engine::components::Positionable
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			BizagiCD();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~BizagiCD();
		};
	}
}

#endif


