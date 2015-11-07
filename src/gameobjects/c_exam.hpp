/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_C_EXAM_H
#define _THESEUS_GAME_OBJECTS_C_EXAM_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>
#include "../map/positionable.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class CExam
			: public theseus::map::Positionable
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			CExam();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~CExam();
		};
	}
}

#endif
#pragma once
