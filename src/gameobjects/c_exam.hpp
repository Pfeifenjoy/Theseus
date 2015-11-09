/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_C_EXAM_H
#define _THESEUS_GAME_OBJECTS_C_EXAM_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>
#include "../engine/components/positionable.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class CExam
			: public theseus::engine::components::Positionable
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
