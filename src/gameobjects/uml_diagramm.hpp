/*
* @author Dominic Steinhauser
*/
#ifndef _THESEUS_GAME_OBJECTS_UML_DIAGRAMM_H
#define _THESEUS_GAME_OBJECTS_UML_DIAGRAMM_H

#include "../engine/gameobject.hpp"
#include "../engine/components/sprite.hpp"
#include <SFML/System.hpp>
#include "../engine/components/positionable.hpp"

namespace theseus
{
	namespace gameobjects
	{
		class UMLDiagramm
			: public theseus::engine::components::Positionable
			, public virtual engine::components::Sprite
		{
		private:


		public:
			//---- Constructor --------------------------------------------------------------------------------------

			UMLDiagramm();

			//---- Destructor ---------------------------------------------------------------------------------------

			virtual ~UMLDiagramm();
		};
	}
}

#endif
#pragma once
