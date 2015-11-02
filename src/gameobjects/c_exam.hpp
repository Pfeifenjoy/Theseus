/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_C_EXAM_H
#define _THESEUS_GAME_OBJECTS_C_EXAM_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class CExam
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			CExam(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~CExam();
		};
	}
}

#endif
#pragma once
