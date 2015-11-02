/*
* @author Dominic Steinhauser
*/#ifndef _THESEUS_GAME_OBJECTS_MATH_SOLUTION_H
#define _THESEUS_GAME_OBJECTS_MATH_SOLUTION_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>

namespace theseus
{
	namespace gameobjects
	{
		class MathSolution
			: public engine::GameObject
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			MathSolution(sf::Vector2f position);

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~MathSolution();
		};
	}
}

#endif
#pragma once

